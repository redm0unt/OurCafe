#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include "message.h"

#include <QTcpSocket>
#include <QDateTime>

class EMailSender : public QObject
{
    Q_OBJECT
public:
    EMailSender(const QString &host, const QString &login, const QString &password, int timeout = 3000, QObject *parent = 0);
    bool sendMessage(const Message &message, const QString &from, const QString &to);

signals:
    void signalConnected();
    void signalDisconnected();
    void signalLog(const QString &log);
    void signalSendResult(bool isOk);

protected:
    QString mailTimestamp() const;
    QString readLine();
    QString exchangeMessages(const QString &sendData);
    QString checkedExchangeMessage(const QString &message);
    int responseCode(const QString &message);

    QString mSmtpHost;
    QString mLogin;
    QString mPassword;

    QTcpSocket *pSocket;
    QTextStream *pSocketStream;
    int mTimeout;

    static const int CONNECT_PORT = 25;
};

#endif // EMAILSENDER_H
