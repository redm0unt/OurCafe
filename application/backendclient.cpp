#include "backendclient.h"


BackendClient::BackendClient(QObject* parent) : QObject(parent)
{
    TcpSocket = new QTcpSocket(this);
    TcpSocket->connectToHost("127.0.0.1", 33333);
    // connect(TcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead));
}
BackendClient* BackendClient::getInstance()
{
    if (!instance)
    {
        instance = new BackendClient();
        destroyer.initialize(instance);
    }
    return instance;
}
void BackendClient::send_message_to_server(QString query)
{
    TcpSocket->write(query.toUtf8());
}

void BackendClient::slotServerRead()
{
    QString message = "";
    while (TcpSocket->bytesAvailable()>0)
    {
        QByteArray array = TcpSocket->readAll();
        message.append(array);
    }
    qDebug() << message;
    emit message_from_server(message);
}
BackendClient* BackendClient::instance;
BackendClientDestroyer BackendClient::destroyer;
