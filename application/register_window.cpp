#include "register_window.h"
#include "ui_register_window.h"
#include "backendclient.h"


register_window::register_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::register_window)
{
    ui->setupUi(this);
}

register_window::~register_window()
{
    delete ui;
}

void register_window::on_SingUpButton_clicked()
{
    // Send info to server
    // –––––––––––––––––––
    BackendClient::open_main_window();
    this->hide();
}


void register_window::on_AuthorizationButton_clicked()
{
    BackendClient::open_entering_window();
    this->hide();
}

