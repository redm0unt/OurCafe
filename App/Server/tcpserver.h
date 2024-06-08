#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

/**
 * @brief Класс TCPServer представляет TCP сервер для обработки клиентских соединений.
 */
class TCPServer;

/**
 * @brief Класс ServerDestroyer представляет объект для уничтожения сервера.
 */
class ServerDestroyer {
private:
    TCPServer *server;
public:
    ~ServerDestroyer() { delete server; }
    void initialize(TCPServer *Server) { server = Server; }
};

/**
 * @brief The TCPServer class
 */
class TCPServer : public QObject
{
Q_OBJECT
private:
    static TCPServer *server; /**< Указатель на экземпляр класса сервера. */
    static ServerDestroyer destroyer; /**< Объект для уничтожения сервера. */

    QTcpServer *TcpServer; /**< Указатель на объект QTcpServer. */
    QSqlDatabase Database; /**< Объект для работы с базой данных. */
    QList<QTcpSocket *> clients; /**< Список клиентских сокетов. */
    bool server_status; /**< Статус сервера (запущен/остановлен). */
    bool database_status; /**< Статус базы данных (открыта/закрыта). */
protected:
    /**
     * @brief Конструктор класса.
     * @param parent Родительский объект.
     */
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer(); /**< Деструктор класса. */
    TCPServer( TCPServer& ) = delete;
    TCPServer& operator = (TCPServer&) = delete;
    friend class ServerDestroyer;
public:
    /**
     * @brief Получить экземпляр сервера.
     * @return Указатель на экземпляр сервера.
     */
    static TCPServer *getserver();
public slots:
    void slotNewConnection(); /**< Слот для обработки нового клиентского соединения. */
    void slotClientDisconnected(); /**< Слот для обработки отключения клиента. */
    void slotServerRead(); /**< Слот для чтения данных от клиента. */
    void stopServer(); /**< Остановить сервер. */
};

#endif // TCPSERVER_H
