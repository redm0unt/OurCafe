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
                QByteArray blob_hash = query.value("user_pass_hash").toByteArray();
                QString hashed_pass_from_server = blob_hash.toHex();

                if (hashed_pass_from_server == incoming_hashed_pass) auth_status = true;
                else auth_status = false;
            }
            QJsonObject outgoingMessage;
            outgoingMessage["auth_status"] = auth_status;

            if (auth_status) {
                qDebug() << ("authorization (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "): login attempt satisfied");
            }
            else {
                qDebug() << ("authorization (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "): login attempt failed");
            }

            QJsonDocument out_doc(outgoingMessage);
            QString out_strJson(out_doc.toJson(QJsonDocument::Compact));

            client->write(out_strJson.toUtf8());
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
        // Admin handler
        else if (type =="admin_delete_user") {
            QString login = incomingMessage["login"].toString();
            QSqlQuery query;
            bool user_exists = false;
            query.prepare("select count(*) from users where user_login = :login");
            query.bindValue(":login", login);

            bool user_delete_state = false;


            if (query.exec()) {
                if (query.next()) {
                    QVariant cellValue = query.value(0);
                    if (cellValue.toInt() > 0) {
                        user_exists = true;
                        qDebug() << "User with this login found";
                    }
                    else {
                        qDebug() << "There is no users with this login";
                    }
                }
                else{
                    qDebug() << "error: could not execute query";
                    qDebug() << query.lastError();}
            }
            else{
                qDebug() << "error: could not execute query";
                qDebug() << query.lastQuery();
                qDebug() << query.lastError();}



            if (user_exists){
                query.prepare("delete from users where user_login = :login ");
                query.bindValue(":login", login);

                if (!query.exec()) {
                    qDebug() << "error: could not execute query";
                    qDebug() << query.lastError();
                }
                else {
                    qDebug() << '\n';
                    qDebug() << "user " + login + " successfully deleted!";
                    user_delete_state = true;
                }
            }
            QJsonObject outgoingMessage;
            outgoingMessage["user_delete_state"] = user_delete_state;
            QJsonDocument out_doc(outgoingMessage);
            QString out_strJson(out_doc.toJson(QJsonDocument::Compact));
            client->write(out_strJson.toUtf8());
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
