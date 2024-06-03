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

void BookingWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

void BookingWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}


void BookingWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}



void BookingWindow::on_Telegram_clicked()
{
    BackendClient::open_external("telegram");
}
void BookingWindow::on_Instagram_clicked()
{
    BackendClient::open_external("instagram");
}
void BookingWindow::on_VK_clicked()
{
    BackendClient::open_external("vk");
}
void BookingWindow::on_Whatsapp_clicked()
{
    BackendClient::open_external("whatsapp");
}

