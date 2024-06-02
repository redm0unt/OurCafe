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
        server_status = false;
        qDebug() << "error: server is not started";
    }
    else {
        server_status = true;
        qDebug() << "server is started";
    }


    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("OURCAFEDB.db");

    if (!Database.open()) {
        database_status = false;
        qDebug() << "error: could not open database.";
    }
    else {
        database_status = true;
        qDebug() << "database opened";
        qDebug() << "count of table:" << Database.tables().size();
    }
}

void TCPServer::stopServer() {
    qDebug() << "\nclosing database";
    Database.close();
    database_status = false;

    qDebug() << "\nclosing server";
    if (clients.size()) {
        for (QTcpSocket *client : clients) {
            client->write("you was disconnected from server");
            client->close();
        }
    }
    TcpServer->close();
    qDebug() << "successfully closed";
    server_status = false;
}
TCPServer::~TCPServer()
{
    stopServer();
}
void TCPServer::slotNewConnection(){
    if(server_status){
        QTcpSocket *client = TcpServer->nextPendingConnection();
        clients.append(client);
        qDebug() << "\nnew client at" << client->peerAddress().toString() << client->peerPort() << "\n";

        client->write("successfully connected to server!");
        client->write("\n");

        connect(client, &QTcpSocket::readyRead, this, &TCPServer::slotServerRead);
        connect(client, &QTcpSocket::disconnected, this, &TCPServer::slotClientDisconnected);
    }
}

// Handlers for messages from clients
void TCPServer::slotServerRead(){
    QTcpSocket *client = (QTcpSocket *)sender();


    while (client->bytesAvailable() > 0) {
        QByteArray data = client->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject incomingMessage = doc.object();

        QString type;
        if (incomingMessage.contains("type")) {
            type = incomingMessage["type"].toString();
        }


        // Authorization handler
        if (type == "authorization") {
            QString login = incomingMessage["login"].toString();
            QString incoming_hashed_pass = incomingMessage["hashed_pass"].toString();

            qDebug() << ("authorization (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "): login '" + login + "'");

            QSqlQuery query;
            query.prepare("SELECT user_pass_hash FROM users WHERE user_login = :login");
            query.bindValue(":login", login);

            if (!query.exec()) {
                qDebug() << "error: could not execute query.";
                qDebug() << query.lastError();
            }

            bool auth_status = false;
            if (query.next()) {
                // —————————————————————————————————————————————————————————
                // Need to be done: sending 'true' back to client if success
                // —————————————————————————————————————————————————————————

                QByteArray blob_hash = query.value("user_pass_hash").toByteArray();
                QString hashed_pass_from_server = blob_hash.toHex();

                if (hashed_pass_from_server == incoming_hashed_pass) {

                    auth_status = true;
                    qDebug() << "login attempt satisfied";
                }
                else {
                    auth_status = false;
                    qDebug() << "login attempt rejected";
                }                
            }
            QJsonObject outgoingMessage;
            outgoingMessage["auth_status"] = auth_status;

            QJsonDocument out_doc(outgoingMessage);
            QString out_strJson(out_doc.toJson(QJsonDocument::Compact));

            client->write(out_strJson.toUtf8());

            // // Hashed placeholder password "1111"
            // //QString hashed_pass_from_server = QString("1011110111010100011101010001001001110010111101000010101101000110000010000000011010110100010000100011000111000100001111100000010110001011000111011011011000100000110100110111111010010100111101101000010101100010101111011110110011001010010001100111110010010000");
        }


        // Registration handler
        else if (type == "registration") {
            QString name = incomingMessage["name"].toString();
            QString login = incomingMessage["login"].toString();
            QString email = incomingMessage["email"].toString();
            QString hashed_pass = incomingMessage["hashed_pass"].toString();

            qDebug() << "new user registration" << login;

            QSqlQuery query;
            query.prepare("INSERT INTO users (user_name, user_login, user_email, user_pass_hash) VALUES (:name, :login, :email, :hashed_pass)");
            query.bindValue(":name", name);
            query.bindValue(":login", login);
            query.bindValue(":email", email);
            query.bindValue(":hashed_pass", QByteArray::fromHex(hashed_pass.toUtf8()));

            if (!query.exec()) {
                qDebug() << "error: could not execute query.";
                qDebug() << query.lastError();
            }
            else {
                qDebug() << '\n';
                qDebug() << "new register: (login: " + login + "; name: " + name + "; email: " + email + ")";
            }
        }
        else {
            qDebug() << ("unhandled message (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "):") << data << "\n";

            QString reply = "";
            reply.append("Unhandled message. To be handled it should contain 'type' field in json format\necho: ");
            reply.append(data); reply.append("\n");
            client->write(reply.toUtf8());
        }
    }
}
void TCPServer::slotClientDisconnected() {
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
