#include "profilewindow.h"
#include "ui_profilewindow.h"
#include "backendclient.h"

ProfileWindow::ProfileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}



void ProfileWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}
void ProfileWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}


void ProfileWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void ProfileWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

void ProfileWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}



void ProfileWindow::on_Telegram_clicked()
{
    BackendClient::open_external("telegram");
}
void ProfileWindow::on_Instagram_clicked()
{
    BackendClient::open_external("instagram");
}
void ProfileWindow::on_VK_clicked()
{
    BackendClient::open_external("vk");
}
void ProfileWindow::on_Whatsapp_clicked()
{
    BackendClient::open_external("whatsapp");
}

