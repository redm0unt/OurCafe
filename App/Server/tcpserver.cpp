#include "tcpserver.h"

/*!
 * \brief Возвращает единственный экземпляр TCPServer.
 * \return Указатель на экземпляр TCPServer.
 */
TCPServer *TCPServer::getserver() {
    if (!server) {
        server = new TCPServer();
        destroyer.initialize(server);
    }
    return server;
}

/*!
 * \brief Конструирует объект TCPServer.
 * \param parent Указатель на родительский объект QObject.
 */
TCPServer::TCPServer(QObject *parent) : QObject(parent) {
    TcpServer = new QTcpServer(this);

    connect(TcpServer, &QTcpServer::newConnection, this, &TCPServer::slotNewConnection);

    if (!TcpServer->listen(QHostAddress::Any, 33333)) {
        server_status = false;
        qDebug() << "error: server is not started";
    } else {
        server_status = true;
        qDebug() << "server is started";
    }

    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("OURCAFEDB.db");

    if (!Database.open()) {
        database_status = false;
        qDebug() << "error: could not open database.";
    } else {
        database_status = true;
        qDebug() << "database opened";
    }
}

/*!
 * \brief Останавливает TCP-сервер и закрывает соединение с базой данных.
 */
void TCPServer::stopServer() {
    qDebug() << "\nзакрытие базы данных";
    Database.close();
    database_status = false;

    qDebug() << "\nзакрытие сервера";
    if (clients.size()) {
        for (QTcpSocket *client : clients) {
            client->write("вы были отключены от сервера");
            client->close();
        }
    }
    TcpServer->close();
    qDebug() << "успешно закрыто";
    server_status = false;
}

/*!
 * \brief Уничтожает объект TCPServer.
 */
TCPServer::~TCPServer() {
    stopServer();
}

/*!
 * \brief Слот для обработки новых подключений клиентов.
 */
void TCPServer::slotNewConnection() {
    if (server_status) {
        QTcpSocket *client = TcpServer->nextPendingConnection();
        clients.append(client);
        qDebug() << "\nновый клиент на" << client->peerAddress().toString() << client->peerPort() << "\n";

        client->write("успешное подключение к серверу!");
        client->write("\n");

        connect(client, &QTcpSocket::readyRead, this, &TCPServer::slotServerRead);
        connect(client, &QTcpSocket::disconnected, this, &TCPServer::slotClientDisconnected);
    }
}

/*!
 * \brief Слот для чтения данных от подключенных клиентов.
 */
void TCPServer::slotServerRead() {
    QTcpSocket *client = (QTcpSocket *)sender();

    while (client->bytesAvailable() > 0) {
        QByteArray data = client->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject incomingMessage = doc.object();

        QString type;
        if (incomingMessage.contains("type")) {
            type = incomingMessage["type"].toString();
        }

        // Обработчик авторизации
        if (type == "authorization") {
            QString login = incomingMessage["login"].toString();
            QString incoming_hashed_pass = incomingMessage["hashed_pass"].toString();

            qDebug() << ("авторизация (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "): логин '" + login + "'");

            QSqlQuery query;
            query.prepare("SELECT user_pass_hash FROM users WHERE user_login = :login");
            query.bindValue(":login", login);

            if (!query.exec()) {
                qDebug() << "ошибка: не удалось выполнить запрос.";
                qDebug() << query.lastError();
            }

            bool auth_status = false;
            if (query.next()) {
                QByteArray blob_hash = query.value("user_pass_hash").toByteArray();
                QString hashed_pass_from_server = blob_hash.toHex();

                if (hashed_pass_from_server == incoming_hashed_pass) {
                    auth_status = true;
                    qDebug() << "попытка входа выполнена успешно";
                } else {
                    auth_status = false;
                    qDebug() << "попытка входа отклонена";
                }                
            }
            QJsonObject outgoingMessage;
            outgoingMessage["auth_status"] = auth_status;

            QJsonDocument out_doc(outgoingMessage);
            QString out_strJson(out_doc.toJson(QJsonDocument::Compact));

            client->write(out_strJson.toUtf8());
        }

        // Обработчик регистрации
        else if (type == "registration") {
            QString name = incomingMessage["name"].toString();
            QString login = incomingMessage["login"].toString();
            QString email = incomingMessage["email"].toString();
            QString hashed_pass = incomingMessage["hashed_pass"].toString();

            qDebug() << "регистрация нового пользователя" << login;

            // ...
            // ...
            // ...

            qDebug() << '\n';
            qDebug() << "новая регистрация: (логин: " + login + "; имя: " + name + "; email: " + email + ")";
        } else {
            qDebug() << ("необработанное сообщение (" + client->peerAddress().toString() + " " + QString::number(client->peerPort()) + "):") << data << "\n";

            QString reply = "";
            reply.append("Необработанное сообщение. Для обработки оно должно содержать поле 'type' в формате JSON\nэхо: ");
            reply.append(data); reply.append("\n");
            client->write(reply.toUtf8());
        }
    }
}

/*!
 * \brief Слот для обработки отключения клиента.
 */
void TCPServer::slotClientDisconnected() {
    QTcpSocket *client = (QTcpSocket *)sender();

    clients.removeOne(client);
    client->deleteLater();

    qDebug() << "клиент" << client->peerAddress().toString() << client->peerPort() << "отключился";
}

// Паттерн Singleton
TCPServer *TCPServer::server;
ServerDestroyer TCPServer::destroyer;
