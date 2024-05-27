#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>


class TCPServer;

class ServerDestroyer {
private:
    TCPServer *server;
public:
    ~ServerDestroyer() { delete server; }
    void initialize(TCPServer *Server) { server = Server; }
};


class TCPServer : public QObject
{
Q_OBJECT
private:
    static TCPServer *server;
    static ServerDestroyer destroyer;

    QTcpServer *TcpServer;
    QList<QTcpSocket *> clients;
    int server_status;
protected:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();
    TCPServer( TCPServer& ) = delete;
    TCPServer& operator = (TCPServer&) = delete;
    friend class ServerDestroyer;
public:
    static TCPServer *getserver();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    void stopServer();
};


#endif // TCPSERVER_H
