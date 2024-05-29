#include "basketwindow.h"
#include "ui_basketwindow.h"
#include "backendclient.h"


BasketWindow::BasketWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BasketWindow)
{
    ui->setupUi(this);
    ui->card_1->hide();
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

void BasketWindow::slot_cappuccino(QString url, QString name, qint64 price)
{
    ui->card_1->show();
    ui->picture_1->setStyleSheet(url);
    ui->description_1->setText(name);
    int multiplier = ui->counter_1->text().toInt();
    QString price_string = QString::number(price);
    ui->price_1->setText(price_string);
    QString price_full_string = QString::number(price*multiplier);
    ui->price_full_1->setText(price_full_string);

}

void BasketWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

