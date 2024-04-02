#include "entering_window.h"
#include "ui_entering_window.h"
#include "backendclient.h"


entering_window::entering_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::entering_window)
{
    ui->setupUi(this);
}

entering_window::~entering_window()
{
    delete ui;
}

void entering_window::on_SingInButton_clicked()
{
    // Send info to server and evaluate it
    // –––––––––––––––––––––––––––––––––––
    BackendClient::open_main_window();
    this->hide();
}

void entering_window::on_RegisterButton_clicked()
{
    BackendClient::open_register_window();
    this->hide();
}

