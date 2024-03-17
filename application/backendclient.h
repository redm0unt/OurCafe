#ifndef BACKENDCLIENT_H
#define BACKENDCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>


class BackendClient;

class BackendClientDestroyer
{
    private:
        BackendClient* instance;
    public:
        ~BackendClientDestroyer() { delete instance; }
        void initialize(BackendClient* p) { instance = p; }
};

class BackendClient : public QObject
{
    Q_OBJECT
    private:
        static BackendClient* instance;
        static BackendClientDestroyer destroyer;
        QTcpSocket* TcpSocket;
    protected:
        explicit BackendClient (QObject* parent = nullptr);
        BackendClient( BackendClient& ) = delete;
        BackendClient & operator = (BackendClient &) = delete;
        ~BackendClient() { TcpSocket->close(); }
        friend class BackendClientDestroyer;
    public:
        static BackendClient* getInstance();
        void send_message_to_server ( QString query );

        signals:
            void message_from_server( QString message );

    private slots:
        void slotServerRead();
};


#endif // BACKENDCLIENT_H
