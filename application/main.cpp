#include "mainwindow.h"
#include "backendclient.h"

#include <QApplication>
#include <QLabel>
#include <QString>
#include <iostream>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/resources/AppIcon.png"));

    BackendClient::start_application();


    // Initialize connection with server and send message after drawing GUI
    BackendClient* client = BackendClient::getclient();
    client->send_message_to_server(QString::fromStdString("Hi Server!!! I'm application"));

    return app.exec();
}
