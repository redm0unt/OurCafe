/**
 * @file ProfileWindow.cpp
 * @brief Файл с реализацией методов класса ProfileWindow для окна профиля пользователя.
 */

#include "profilewindow.h"
#include "ui_profilewindow.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса ProfileWindow.
 * 
 * @param parent Родительский объект.
 */
ProfileWindow::ProfileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Деструктор класса ProfileWindow.
 */
ProfileWindow::~ProfileWindow()
{
    delete ui;
}

/**
 * @brief Слот для обработки нажатия кнопки "Меню".
 */
void ProfileWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

/**
 * @brief Слот для обработки клика по тексту "Контакты".
 */
void ProfileWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

/**
 * @brief Слот для обработки нажатия кнопки "Бронирование".
 */
void ProfileWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

/**
 * @brief Слот для обработки нажатия кнопки "Корзина".
 */
void ProfileWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

/**
 * @brief Слот для обработки клика по главному логотипу.
 */
void ProfileWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}
