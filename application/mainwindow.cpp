#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "backendclient.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}
void MainWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void MainWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

void MainWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

