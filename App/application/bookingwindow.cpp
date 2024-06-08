#include "bookingwindow.h"
#include "ui_bookingwindow.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса BookingWindow.
 * @param parent Родительский виджет.
 */
BookingWindow::BookingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BookingWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Деструктор класса BookingWindow.
 */
BookingWindow::~BookingWindow()
{
    delete ui;
}

/**
 * @brief Слот для нажатия на кнопку главного логотипа.
 * Открывает главное окно и скрывает текущее.
 */
void BookingWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}

/**
 * @brief Слот для нажатия на кнопку меню.
 * Открывает окно меню и скрывает текущее.
 */
void BookingWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

/**
 * @brief Слот для нажатия на кнопку корзины.
 * Открывает окно корзины и скрывает текущее.
 */
void BookingWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

/**
 * @brief Слот для нажатия на кнопку аккаунта.
 * Открывает окно профиля и скрывает текущее.
 */
void BookingWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

/**
 * @brief Слот для нажатия на текст контактов.
 * Открывает ссылку на карту Яндекса в браузере.
 */
void BookingWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE"; /**< URL контактной ссылки */
    QDesktopServices::openUrl(QUrl(link)); /**< Открывает указанный URL */
}
