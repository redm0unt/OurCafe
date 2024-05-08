#include "backendclient.h"

#include <QApplication>
#include <QString>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/resources/AppIcon.png"));

    // Initialize connection with server and send message after drawing GUI
    BackendClient* client = BackendClient::getclient();

    client->send_message_to_server(QString::fromStdString("Hi Server!!! I'm application"));

    return app.exec();
}
