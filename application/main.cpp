#include <QApplication>

#include "backendclient.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/resources/AppIcon.png"));

    // Initialize connection with server and send message after drawing GUI
    BackendClient* client = BackendClient::getclient();

    return app.exec();
}
