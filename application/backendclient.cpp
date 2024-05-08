#include "backendclient.h"


// Get instance of backend processor
BackendClient* BackendClient::getclient()
{
    if (!client)
    {
        client = new BackendClient();
        destroyer.initialize(client);
    }
    return client;
}
// Initialization of BackendClient. Being called in @getclient()
BackendClient::BackendClient(QObject* parent) : QObject(parent)
{
    open_entering_window();

    TcpSocket = new QTcpSocket(this);
    TcpSocket->connectToHost("127.0.0.1", 33333);
    // connect(TcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead));
}
BackendClient::~BackendClient() {
    if (TcpSocket->isOpen()) TcpSocket->close();
    if (!authorization_state) delete enteringWindow;
    delete registerWindow;
    delete mainWindow;
    delete menuWindow;
}


// Check authorization

// Compare hash from server to locally obtained
bool BackendClient::registration_server_responce(QString login, QString password) {
    QString hashed_pass = Hash(password.toStdString()).get_hash();
    // Send this tuple to server
    // Function that sends only login and returns only hash
    // ...

    // Hashed placeholder password "1111"
    QString hashed_pass_from_server = QString("1011110111010100011101010001001001110010111101000010101101000110000010000000011010110100010000100011000111000100001111100000010110001011000111011011011000100000110100110111111010010100111101101000010101100010101111011110110011001010010001100111110010010000");

    qDebug() << "Input hashed password:" << hashed_pass;
    qDebug() << "Hashed password from server:" << hashed_pass_from_server;
    if (hashed_pass == hashed_pass_from_server) {
        return true;
    }
    return false;
}

bool BackendClient::authentificate(QString login, QString password) {
    if (client->registration_server_responce(login, password)) {
        qDebug() << QString("Authorized as " + login);

        open_main_window();

        authorization_state = true;
        delete enteringWindow;
    }
    else{
        QMessageBox message_box;
        message_box.setText("Authorization not successful");
        message_box.setInformativeText(QString("Try another combination of login and password"));
        message_box.exec();
    }
}


// ———————————————————————————————————————
// SIGNALS

// Basic message sender
void BackendClient::send_message_to_server(QString query)
{
    TcpSocket->write(query.toUtf8());
}


// ———————————————————————————————————————
// SLOTS


// ???
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


// ———————————————————————————————————————
// WINDOW STARTERS

// Entering
void BackendClient::open_entering_window()
{
    if (!enteringWindow) {
        enteringWindow = new entering_window();

    }
    enteringWindow->show();
}
// Register
void BackendClient::open_register_window()
{
    if (!registerWindow) {
        registerWindow = new register_window();
    }
    registerWindow->show();
}
// Main
void BackendClient::open_main_window()
{
    if (!mainWindow) {
        mainWindow = new MainWindow();
    }
    mainWindow->show();
}
// Menu
void BackendClient::open_menu_window()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
}


// ———————————————————————————————————————
// CLASS MEMBERS DECLARATION

// Singleton pattern
BackendClient* BackendClient::client;
BackendClientDestroyer BackendClient::destroyer;

bool BackendClient::authorization_state = false;

// Declare application windows
MainWindow* BackendClient::mainWindow;
MenuWindow* BackendClient::menuWindow;
entering_window* BackendClient::enteringWindow;
register_window* BackendClient::registerWindow;
