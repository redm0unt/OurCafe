#ifndef BACKENDCLIENT_H
#define BACKENDCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>

#include "entering_window.h"
#include "register_window.h"
#include "mainwindow.h"
#include "menuwindow.h"
#include "hash.h"
#include "bookingwindow.h"
#include "basketwindow.h"
#include "profilewindow.h"


class BackendClient;

class BackendClientDestroyer
{
private:
    BackendClient *client;
public:
    ~BackendClientDestroyer() { delete client; }
    void initialize(BackendClient *p) { client = p; }
};

class BackendClient : public QObject
{
Q_OBJECT
private:
    static BackendClient *client;
    static BackendClientDestroyer destroyer;

    // Client Server Socket
    QTcpSocket* TcpSocket;

    static bool authorization_state;

    // Application Windows
    static entering_window* enteringWindow;
    static register_window* registerWindow;
    static MainWindow* mainWindow;

    static BookingWindow* bookingWindow;

    static ProfileWindow* profileWindow;
protected:
    explicit BackendClient (QObject* parent = nullptr);
    BackendClient( BackendClient& ) = delete;
    BackendClient & operator = (BackendClient &) = delete;
    ~BackendClient();
    friend class BackendClientDestroyer;
public:
    static BackendClient* getclient();
    static BasketWindow* basketWindow;
    static MenuWindow* menuWindow;

    void send_message_to_server ( QString query );

    bool get_auth_state() { return authorization_state; }
    bool authorization_server_responce(QString, QString);
    bool registration_server_responce(QString, QString, QString, QString);
    static void authentificate(QString, QString);
    static void registration(QString, QString, QString, QString, QString);
    static void start_application();

    static void open_entering_window();
    static void open_register_window();
    static void open_main_window();
    static void open_menu_window();
    static void open_booking_window();
    static void open_basket_window();
    static void open_profile_window();


signals:
    void message_from_server( QString message );

public slots:
    void slotServerRead();
};


#endif // BACKENDCLIENT_H
