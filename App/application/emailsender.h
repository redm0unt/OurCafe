#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include "message.h"

#include <QTcpSocket>
#include <QDateTime>

/**
 * @brief Класс для отправки электронной почты.
 */
class EMailSender : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор.
     * @param host SMTP-хост.
     * @param login Логин для аутентификации.
     * @param password Пароль для аутентификации.
     * @param timeout Таймаут ожидания ответа от сервера (по умолчанию 3000 мс).
     * @param parent Родительский объект.
     */
    EMailSender(const QString &host, const QString &login, const QString &password, int timeout = 3000, QObject *parent = 0);

    /**
     * @brief Отправить сообщение.
     * @param message Сообщение.
     * @param from Адрес отправителя.
     * @param to Адрес получателя.
     * @return Успешность отправки.
     */
    bool sendMessage(const Message &message, const QString &from, const QString &to);

signals:
    void signalConnected(); ///< Сигнал о подключении к серверу.
    void signalDisconnected(); ///< Сигнал о отключении от сервера.
    void signalLog(const QString &log); ///< Сигнал о логе.
    void signalSendResult(bool isOk); ///< Сигнал о результате отправки.

protected:
    /**
     * @brief Получить текущее время в формате электронной почты.
     * @return Время в формате электронной почты.
     */
    QString mailTimestamp() const;

    /**
     * @brief Прочитать строку из сокета.
     * @return Прочитанная строка.
     */
    QString readLine();

    /**
     * @brief Обменять сообщения с сервером.
     * @param sendData Отправляемые данные.
     * @return Полученные данные.
     */
    QString exchangeMessages(const QString &sendData);

    /**
     * @brief Обменять сообщения с сервером с проверкой.
     * @param message Отправляемое сообщение.
     * @return Полученный ответ от сервера.
     */
    QString checkedExchangeMessage(const QString &message);

    /**
     * @brief Получить код ответа от сервера.
     * @param message Сообщение от сервера.
     * @return Код ответа.
     */
    int responseCode(const QString &message);

    QString mSmtpHost; ///< SMTP-хост.
    QString mLogin; ///< Логин для аутентификации.
    QString mPassword; ///< Пароль для аутентификации.

    QTcpSocket *pSocket; ///< Сокет для соединения с SMTP-сервером.
    QTextStream *pSocketStream; ///< Поток для обмена данными по сокету.
    int mTimeout; ///< Таймаут ожидания ответа от сервера.

    static const int CONNECT_PORT = 25; ///< Порт подключения к SMTP серверу.
};

#endif // EMAILSENDER_H
