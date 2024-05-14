#include "backendclient.h"


BackendClient::BackendClient(QObject* parent) : QObject(parent)
{
    TcpSocket = new QTcpSocket(this);
    TcpSocket->connectToHost("127.0.0.1", 33333);
    // connect(TcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead));
}
BackendClient* BackendClient::getclient()
{
    if (!client)
    {
        client = new BackendClient();
        destroyer.initialize(client);
    }
    return client;
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

void BackendClient::start_application()
{
    // Some checks before application starts
    if (!enteringWindow) {
        enteringWindow = new entering_window();
    }
    enteringWindow->show();
}


// Window starters
void BackendClient::open_entering_window()
{
    if (!enteringWindow) {
        enteringWindow = new entering_window();
    }
    enteringWindow->show();
}
void BackendClient::open_register_window()
{
    if (!registerWindow) {
        registerWindow = new register_window();
    }
    registerWindow->show();
}
void BackendClient::open_main_window()
{
    if (!mainWindow) {
        mainWindow = new MainWindow();
    }
    mainWindow->show();
}
void BackendClient::open_menu_window()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
}
void BackendClient::open_booking_window()
{
    if (!bookingWindow) {
        bookingWindow = new BookingWindow();
    }
    bookingWindow->show();
}
void BackendClient::open_basket_window()
{
    if (!basketWindow) {
        basketWindow = new BasketWindow();
    }
    basketWindow->show();
}


BackendClient* BackendClient::client;
BackendClientDestroyer BackendClient::destroyer;

// Declare static members (application windows)
MainWindow* BackendClient::mainWindow;
MenuWindow* BackendClient::menuWindow;
entering_window* BackendClient::enteringWindow;
register_window* BackendClient::registerWindow;
BookingWindow* BackendClient::bookingWindow;
BasketWindow* BackendClient::basketWindow;

