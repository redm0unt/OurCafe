/**
 * @file EMailSender.cpp
 * @brief Файл с реализацией методов класса EMailSender для отправки электронных писем.
 */

#include "EMailSender.h"

/**
 * @brief Конструктор класса EMailSender.
 * 
 * @param host Хост SMTP-сервера.
 * @param login Логин для авторизации.
 * @param password Пароль для авторизации.
 * @param timeout Таймаут ожидания.
 * @param parent Родительский объект.
 */
EMailSender::EMailSender(const QString &host, const QString &login, const QString &password, int timeout, QObject *parent)
    : QObject(parent), mSmtpHost(host), mLogin(login), mPassword(password), mTimeout(timeout)
{
    pSocket = new QTcpSocket(this);
    connect(pSocket, SIGNAL(connected()), SIGNAL(signalConnected()));
    connect(pSocket, SIGNAL(disconnected()), SIGNAL(signalDisconnected()));
}

/**
 * @brief Функция отправки сообщения.
 * 
 * @param message Сообщение для отправки.
 * @param from Адрес отправителя.
 * @param to Адрес получателя.
 * @return Результат отправки сообщения.
 */
bool EMailSender::sendMessage(const Message &message, const QString &from, const QString &to)
{
    QString m_sMessage;
    m_sMessage = mailTimestamp() + "\n";
    m_sMessage.append("User-Agent: Clever Alloy 1.0.0 (WinXP)\n");
    m_sMessage.append("X-Accept-Language: en-us, en\n");
    m_sMessage.append("MIME-Version: 1.0\n");
    m_sMessage.append("To: " + to + "\n");
    m_sMessage.append("From: " + from + " <" + from + ">\n");
    m_sMessage.append("Subject: " + message.subject + "\n");
    m_sMessage.append("Content-Type: text/html; charset=UTF-8;\n");
    m_sMessage.append("Content-transfer-encoding: 7BIT\n\n\n\n");
    m_sMessage=message.body;
    m_sMessage.replace(QString::fromLatin1("\n"), QString::fromLatin1("\r\n"));
    m_sMessage.replace(QString::fromLatin1("\r\n.\r\n"),QString::fromLatin1("\r\n..\r\n"));

    pSocket->connectToHost(mSmtpHost, CONNECT_PORT);
    pSocket->waitForConnected();
    pSocketStream = new QTextStream(pSocket);

    QString recv = readLine();
    int code = responseCode(recv);
    emit signalLog(QString("### Connection status: %1").arg(QString::number(code)));
    if (code != 220) {
        pSocket->disconnectFromHost();
        return false;
    }

    recv = checkedExchangeMessage("ehlo localhost");
    if (recv.isEmpty()) {
        return false;
    }

    recv = checkedExchangeMessage("AUTH LOGIN");
    if (recv.isEmpty()) {
        return false;
    }

    recv = checkedExchangeMessage(mLogin.toUtf8().toBase64());
    if (recv.isEmpty()) {
        return false;
    }

    recv = checkedExchangeMessage(mPassword.toUtf8().toBase64());
    if (recv.isEmpty() || !recv.contains("ok", Qt::CaseInsensitive)) {
        return false;
    }

    recv = checkedExchangeMessage("MAIL FROM: " + from);
    if (recv.isEmpty()) {
        return false;
    }

    recv = checkedExchangeMessage("RCPT TO: " + to);
    if (recv.isEmpty()) {
        return false;
    }

    recv = checkedExchangeMessage("DATA");
    if (recv.contains("not", Qt::CaseInsensitive)) {
        return false;
    }

    recv = checkedExchangeMessage(m_sMessage + "\r\n.");
    if (recv.size() && recv.contains("ok", Qt::CaseInsensitive)) {
        pSocket->disconnectFromHost();
        return true;
    }

    return false;
}

/**
 * @brief Функция формирования временной метки для письма.
 * 
 * @return Временная метка в формате строки.
 */
QString EMailSender::mailTimestamp() const
{
    const QDateTime dt = QDateTime::currentDateTime();
    const QString day_en = dt.toString("ddd");
    const QString month_en = dt.toString("MMM");
    const QString last = dt.toString("yyyy hh:mm:ss");
    return QString( "Date: %1, %2 %3 %4 +0200" ).arg(day_en, QString::number(dt.date().day()), month_en, last);
}

/**
 * @brief Функция чтения строки из сокета.
 * 
 * @return Прочитанная строка.
 */
QString EMailSender::readLine()
{
    QString sIncommingData;
    if (pSocket->waitForReadyRead(mTimeout))
    {
        while (!pSocketStream->atEnd())
        {
            const QString sOpera = pSocketStream->readLine();
            sIncommingData = sOpera + "\n" + sIncommingData;
            emit signalLog("### Recv: " + sIncommingData);
        }
    }
    return sIncommingData;
}

/**
 * @brief Функция обмена сообщениями с сервером SMTP.
 * 
 * @param sendData Строка для отправки на сервер.
 * @return Полученный ответ от сервера.
 */
QString EMailSender::exchangeMessages(const QString &sendData)
{
    emit signalLog("### Send " + sendData);
    *pSocketStream << sendData << "\r\n";
    pSocketStream->flush();
    return readLine();
}

/**
 * @brief Функция отправки сообщения на сервер SMTP и чтения ответа.
 * 
 * @param message Строка для отправки на сервер.
 * @return Полученный ответ от сервера.
 */
QString EMailSender::checkedExchangeMessage(const QString &message)
{
    QString response = exchangeMessages(message);
    if (response.isEmpty()) {
        pSocket->disconnectFromHost();
    }
    return response;
}

/**
 * @brief Функция получения кода ответа от сервера SMTP.
 * 
 * @param message Строка ответа от сервера.
 * @return Код ответа.
 */
int EMailSender::responseCode(const QString &message)
{
    return message.left(3).toInt();
}
