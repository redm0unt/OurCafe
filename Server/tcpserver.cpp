#include <QCoreApplication>
#include <QString>
#include <QDebug>

#include "tcpserver.h"


TCPServer *TCPServer::getserver() {
    if (!server)
    {
        server = new TCPServer();
        destroyer.initialize(server);
    }
    return server;
}

TCPServer::TCPServer(QObject *parent) : QObject(parent){
    TcpServer = new QTcpServer(this);

    connect(TcpServer, &QTcpServer::newConnection, this, &TCPServer::slotNewConnection);

    if (!TcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started\r\n";
    }
    else {
        server_status=1;
        qDebug() << "server is started\r\n";
    }
}

void TCPServer::stopServer() {
    qDebug() << "\nclosing server";
    if (clients.size()) {
        for (QTcpSocket *client : clients) {
            client->write("you was disconnected from server");
            client->close();
        }
    }
    TcpServer->close();
    qDebug() << "successfully closed";
    server_status=0;
}
TCPServer::~TCPServer()
{
    stopServer();
}
void TCPServer::slotNewConnection(){
    if(server_status == 1){
        QTcpSocket *client = TcpServer->nextPendingConnection();
        clients.append(client);
        qDebug() << "\nnew client at" << client->peerAddress().toString() << client->peerPort();

        client->write("successfully connected to server!");

        connect(client, &QTcpSocket::readyRead, this, &TCPServer::slotServerRead);
        connect(client, &QTcpSocket::disconnected, this, &TCPServer::slotClientDisconnected);
    }
}
void TCPServer::slotServerRead(){
    QTcpSocket *client = (QTcpSocket *)sender();

    QString reply = "";
    while (client->bytesAvailable() > 0) {
        QByteArray data = client->readAll();
        qDebug() << data << "\n";

        if (data=="\x01") {
            client->write(reply.toUtf8());
            reply = "";
        }
        else {
            reply.append(data);
        }
    }
    client->write(reply.toUtf8());
}
void TCPServer::slotClientDisconnected(){
    QTcpSocket *client = (QTcpSocket *)sender();

    clients.removeOne(client);
    client->deleteLater();

    qDebug() << "client" << client->peerAddress().toString() << client->peerPort() << "disconnected";
}


// ———————————————————————————————————————
// CLASS MEMBERS DECLARATION

// Singleton pattern
TCPServer *TCPServer::server;
ServerDestroyer TCPServer::destroyer;
