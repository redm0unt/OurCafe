/**
 * @file MenuWindow.cpp
 * @brief Файл с реализацией методов класса MenuWindow для окна меню.
 */

#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса MenuWindow.
 * 
 * @param parent Родительский объект.
 */
MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    BasketWindow* basketWindow = BackendClient::getclient()->basketWindow;

    //basketWindow = new BasketWindow;

    connect(this, &MenuWindow::signal, basketWindow, &BasketWindow::slot_cappuccino);
}

/**
 * @brief Деструктор класса MenuWindow.
 */
MenuWindow::~MenuWindow()
{
    delete ui;
}

/**
 * @brief Слот для обработки клика по главному логотипу.
 */
void MenuWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Бронирование".
 */
void MenuWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Корзина".
 */
void MenuWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Аккаунт".
 */
void MenuWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

/**
 * @brief Слот для обработки клика по тексту "Контакты".
 */
void MenuWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

/**
 * @brief Слот для обработки нажатия кнопки "Капучино".
 */
void MenuWindow::on_cappuccino_pushButton_clicked()
{
    emit signal("border-image: url(:/resources/resources/cappuccino.png);", "cappuccino", 170);
}
