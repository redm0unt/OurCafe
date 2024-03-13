#include <QCoreApplication>
#include <QString>
#include <QDebug>

#include "tcpserver.h"


TCPServer::~TCPServer()
{
    TcpServer->close();
    server_status=0;
}
TCPServer::TCPServer(QObject *parent) : QObject(parent){
    TcpServer = new QTcpServer(this);

    connect(TcpServer, &QTcpServer::newConnection,
            this, &TCPServer::slotNewConnection);

    if(!TcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}
void TCPServer::slotNewConnection(){
    if(server_status==1){
        TcpSocket = TcpServer->nextPendingConnection();
        TcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(TcpSocket, &QTcpSocket::readyRead,this,&TCPServer::slotServerRead);
        connect(TcpSocket,&QTcpSocket::disconnected,this,&TCPServer::slotClientDisconnected);
    }
}
void TCPServer::slotServerRead(){
    QString res = "";
    while(TcpSocket->bytesAvailable()>0)
    {
        QByteArray array = TcpSocket->readAll();
        qDebug() <<array<< "\n";
        if(array=="\x01")
        {
            TcpSocket->write(res.toUtf8());
            res = "";
        }
        else
            res.append(array);
    }
    TcpSocket->write(res.toUtf8());
}
void TCPServer::slotClientDisconnected(){
    TcpSocket->close();
}







// #include "mytcpserver.h"
// #include <QDebug>
// #include <QCoreApplication>
// #include<QString>

// MyTcpServer::~MyTcpServer()
// {

//     mTcpServer->close();
//     //server_status=0;
// }

// MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
//     mTcpServer = new QTcpServer(this);

//     connect(mTcpServer, &QTcpServer::newConnection,
//             this, &MyTcpServer::slotNewConnection);

//     if(!mTcpServer->listen(QHostAddress::Any, 33333)){
//         qDebug() << "server is not started";
//     } else {
//         //server_status=1;
//         qDebug() << "server is started";
//     }
// }

// void MyTcpServer::slotNewConnection(){
//     //   if(server_status==1){
//     mTcpSocket = mTcpServer->nextPendingConnection();
//     mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
//     connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
//     connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
//     // }
// }

// void MyTcpServer::slotServerRead(){
//     QString res = "";
//     while(mTcpSocket->bytesAvailable()>0)
//     {
//         QByteArray array =mTcpSocket->readAll();
//         qDebug()<<array<<"\n";
//         if(array=="\x01")
//         {
//             mTcpSocket->write(res.toUtf8());
//             res = "";
//         }
//         else
//             res.append(array);
//     }
//     mTcpSocket->write(res.toUtf8());

// }

// void MyTcpServer::slotClientDisconnected(){
//     mTcpSocket->close();
// }
