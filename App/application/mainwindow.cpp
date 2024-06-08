/**
 * @file MainWindow.cpp
 * @brief Файл с реализацией методов класса MainWindow для главного окна приложения.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса MainWindow.
 * 
 * @param parent Родительский объект.
 */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Деструктор класса MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Слот для обработки клика по кнопке "Меню".
 */
void MainWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

/**
 * @brief Слот для обработки клика по тексту "Контакты".
 */
void MainWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

/**
 * @brief Слот для обработки нажатия кнопки "Бронирование".
 */
void MainWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Корзина".
 */
void MainWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Аккаунт".
 */
void MainWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}
