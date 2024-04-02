#include "mainwindow.h"
#include "menuwindow.h"
#include "backendclient.h"
#include "entering_window.h"
#include "register_window.h"

#include <QApplication>
#include <QLabel>
#include <QString>
#include <iostream>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    entering_window enter;
    enter.show();
    window.show();
    app.setWindowIcon(QIcon(":/resources/resources/AppIcon.png")); // Your path icon



    // Initialize connection with server and send message after drawing GUI
    BackendClient* interface = BackendClient::getInstance();
    interface->send_message_to_server(QString::fromStdString("Hi Server!!! I'm application"));

    return app.exec();
}
