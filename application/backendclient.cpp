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
    connect(TcpSocket, &QTcpSocket::readyRead, this, &BackendClient::slotServerRead);
}
BackendClient::~BackendClient() {
    if (TcpSocket->isOpen()) TcpSocket->close();
    if (!authorization_state) {
        delete enteringWindow;
        delete registerWindow;
    }
    delete mainWindow;
    delete menuWindow;
    delete bookingWindow;
    delete basketWindow;
    delete profileWindow;

}


// Check authorization

// Compare hash from server to locally obtained
bool BackendClient::authorization_server_responce(QString login, QString password) {
    QString hashed_pass = Hash(password.toStdString()).get_hash();

    qDebug() << "Checking password validity";

    // Create a JSON object to send to the server
    QJsonObject json;
    json.insert("type", "authorization");
    json.insert("login", login);
    json.insert("hashed_pass", hashed_pass);
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    // Write the JSON string to the server
    free_to_listen = false;
    TcpSocket->write(strJson.toUtf8());
    TcpSocket->flush();

    // Wait for the server to send a response
    while (TcpSocket->waitForReadyRead(5000)) {
        QByteArray response = TcpSocket->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();

        // Check if the password is correct
        free_to_listen = true;
        if (jsonObject["auth_status"].toBool()) {
            qDebug() << "success!";
            return true;
        }
        else {
            qDebug() << "error: authentification attempt failed\n";
            return false;
        }
    }
    free_to_listen = true;
    qDebug() << "error: response timed out\n";
    return false;
}

void BackendClient::authentificate(QString login, QString password) {
    QMessageBox message_box;
    message_box.setText("Authorization is not successful");

    if (login == "" || password == "") {
        message_box.setInformativeText(QString("Some fields are empty"));
        message_box.exec();
    }
    else {
        if (client->authorization_server_responce(login, password)) {
            qDebug() << QString("Authorized as " + login);

            open_main_window();

            authorization_state = true;
            delete enteringWindow;
            delete registerWindow;
        }
        else {
            message_box.setInformativeText(QString("Try another combination of login and password"));
            message_box.exec();
        }
    }
}


void BackendClient::registration_info_to_server(QString name, QString login, QString email, QString hashed_pass) {
    QJsonObject json;
    json.insert("type", "registration");
    json.insert("name", name);
    json.insert("login", login);
    json.insert("email", email);
    json.insert("hashed_pass", hashed_pass);
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    // Write the JSON string to the server
    TcpSocket->write(strJson.toUtf8());
    TcpSocket->flush();
}
void BackendClient::registration(QString name, QString login, QString email, QString password, QString password_repeat) {
    QMessageBox message_box;
    message_box.setText("Registration not successful");

    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = regex.match(email);

    if (password.isEmpty() || name.isEmpty() || login.isEmpty() || email.isEmpty() || password_repeat.isEmpty()) {
        message_box.setInformativeText(QString("Some fields are empty"));
        message_box.exec();
    }
    else if (!match.hasMatch()) {
        message_box.setInformativeText(QString("Not valid email format"));
        message_box.exec();
    }
    else if (password == password_repeat) {
        QString hashed_pass = Hash(password.toStdString()).get_hash();

        qDebug() << "\nsending info to server";

        client->registration_info_to_server(name, login, email, hashed_pass);

        qDebug() << ("successfully registred with name: " + name + "; login: " +  login + "; email: " + email);

        open_main_window();

        authorization_state = true;
        delete enteringWindow;
        delete registerWindow;
    }
    else {
        message_box.setInformativeText(QString("Passwords do not match"));
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

// default listener
void BackendClient::slotServerRead()
{
    if (free_to_listen) {
        QString message = "";
        while (TcpSocket->bytesAvailable()>0)
        {
            QByteArray array = TcpSocket->readAll();
            message.append(array);
        }
        qDebug() << message;
        emit message_from_server(message);
    }
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
        basketWindow = new BasketWindow();
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
// Booking
void BackendClient::open_booking_window()
{
    if (!bookingWindow) {
        bookingWindow = new BookingWindow();
    }
    bookingWindow->show();
}
// Basket
void BackendClient::open_basket_window()
{
    if (!basketWindow) {
        basketWindow = new BasketWindow();
    }
    basketWindow->show();
}
// Profile
void BackendClient::open_profile_window()
{
    if (!profileWindow) {
        profileWindow = new ProfileWindow();
    }
    profileWindow->show();
}


// ———————————————————————————————————————
// CLASS MEMBERS DECLARATION

// Singleton pattern
BackendClient* BackendClient::client;
BackendClientDestroyer BackendClient::destroyer;

bool BackendClient::authorization_state = false;
bool BackendClient::free_to_listen = true;

// Declare application windows
MainWindow* BackendClient::mainWindow;
MenuWindow* BackendClient::menuWindow;
entering_window* BackendClient::enteringWindow;
register_window* BackendClient::registerWindow;
BookingWindow* BackendClient::bookingWindow;
BasketWindow* BackendClient::basketWindow;
ProfileWindow* BackendClient::profileWindow;

