#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "backendclient.h"


MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
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
void MenuWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

