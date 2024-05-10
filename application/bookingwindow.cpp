#include "bookingwindow.h"
#include "ui_bookingwindow.h"
#include "backendclient.h"

BookingWindow::BookingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BookingWindow)
{
    ui->setupUi(this);
}

BookingWindow::~BookingWindow()
{
    delete ui;
}

void BookingWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}

void BookingWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

