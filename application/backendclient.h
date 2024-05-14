#ifndef BACKENDCLIENT_H
#define BACKENDCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

#include "entering_window.h"
#include "register_window.h"
#include "mainwindow.h"
#include "menuwindow.h"
#include "bookingwindow.h"
#include "basketwindow.h"


class BackendClient;

class BackendClientDestroyer
{
    private:
        BackendClient* client;
    public:
        ~BackendClientDestroyer() { delete client; }
        void initialize(BackendClient* p) { client = p; }
};

class BackendClient : public QObject
{
    Q_OBJECT
    private:
        static BackendClient* client;
        static BackendClientDestroyer destroyer;

        // Client Server Socket
        QTcpSocket* TcpSocket;

        // Application Windows
        static entering_window* enteringWindow;
        static register_window* registerWindow;
        static MainWindow* mainWindow;
        static MenuWindow* menuWindow;
        static BookingWindow* bookingWindow;
        static BasketWindow* basketWindow;
    protected:
        explicit BackendClient (QObject* parent = nullptr);
        BackendClient( BackendClient& ) = delete;
        BackendClient & operator = (BackendClient &) = delete;
        ~BackendClient() {
            TcpSocket->close();
            delete enteringWindow;
            delete registerWindow;
            delete mainWindow;
            delete menuWindow;
            delete bookingWindow;
            delete basketWindow;
        }
        friend class BackendClientDestroyer;
    public:
        static BackendClient* getclient();
        void send_message_to_server ( QString query );
        static void start_application();

        static void open_entering_window();
        static void open_register_window();
        static void open_main_window();
        static void open_menu_window();
        static void open_booking_window();
        static void open_basket_window();


        signals:
            void message_from_server( QString message );

    private slots:
        void slotServerRead();
};


#endif // BACKENDCLIENT_H
