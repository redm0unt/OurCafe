#include "mainwindow.h"
#include "backendclient.h"

#include <QApplication>
#include <QLabel>
#include <QString>
#include <iostream>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    // initialize connection with server and send message after drawing GUI
    BackendClient* interface = BackendClient::getInstance();
    interface->send_message_to_server(QString::fromStdString("Hi Server!!! I'm application"));

    return app.exec();
}
