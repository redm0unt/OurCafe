#include "basketwindow.h"
#include "ui_basketwindow.h"
#include "backendclient.h"


BasketWindow::BasketWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BasketWindow)
{
    ui->setupUi(this);
}

BasketWindow::~BasketWindow()
{
    delete ui;
}

void BasketWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}

void BasketWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

void BasketWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void BasketWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

void BasketWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

