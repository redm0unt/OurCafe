// // GUI Application
// #include "mainwindow.h"
// #include "backendclient.h"

// #include <QApplication>
// #include <QString>
// #include <iostream>


// int main(int argc, char* argv[])
// {

//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();

// }

// Console Client (Terminal interface only)
#include "mainwindow.h"
#include "backendclient.h"

#include <QCoreApplication>
#include <QString>
#include <iostream>


int main(int argc, char* argv[])
{
    QCoreApplication core(argc, argv);
    std::string message;
    std::cin >> message;
    BackendClient::getInstance()->send_message_to_server(QString::fromStdString(message));
    return core.exec();
}