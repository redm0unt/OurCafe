#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "backendclient.h"



MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    BasketWindow* basketWindow = BackendClient::getclient()->basketWindow;

    //basketWindow = new BasketWindow;

    connect(this, &MenuWindow::signal, basketWindow, &BasketWindow::slot_cappuccino);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}
void MenuWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void MenuWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

void MenuWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

void MenuWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

void MenuWindow::on_cappuccino_pushButton_clicked()
{
    emit signal("border-image: url(:/resources/resources/cappuccino.png);", "cappuccino", 170);
}



