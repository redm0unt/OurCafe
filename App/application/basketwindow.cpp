#include "basketwindow.h"
#include "ui_basketwindow.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса окна корзины.
 * @param parent Родительский виджет.
 */
BasketWindow::BasketWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BasketWindow)
{
    ui->setupUi(this);
    ui->card_1->hide(); /**< Скрытие элемента card_1 по умолчанию. */
}

/**
 * @brief Деструктор класса окна корзины.
 */
BasketWindow::~BasketWindow()
{
    delete ui;
}

/**
 * @brief Обработчик нажатия на кнопку MainLogo.
 */
void BasketWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window(); /**< Открытие главного окна. */
    this->hide(); /**< Скрытие текущего окна. */
}

/**
 * @brief Обработчик нажатия на кнопку MenuButton.
 */
void BasketWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window(); /**< Открытие окна меню. */
    this->hide(); /**< Скрытие текущего окна. */
}

/**
 * @brief Обработчик нажатия на кнопку BookingButton.
 */
void BasketWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window(); /**< Открытие окна бронирования. */
    this->hide(); /**< Скрытие текущего окна. */
}

/**
 * @brief Обработчик нажатия на кнопку AccountButton.
 */
void BasketWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window(); /**< Открытие окна профиля. */
    this->hide(); /**< Скрытие текущего окна. */
}

/**
 * @brief Обработчик сигнала о получении информации о продукте "капучино".
 * @param url URL изображения.
 * @param name Название продукта.
 * @param price Цена продукта.
 */
void BasketWindow::slot_cappuccino(QString url, QString name, qint64 price)
{
    ui->card_1->show(); /**< Отображение элемента card_1. */
    ui->picture_1->setStyleSheet(url); /**< Установка стиля для изображения. */
    ui->description_1->setText(name); /**< Установка названия продукта. */
    int multiplier = ui->counter_1->text().toInt(); /**< Получение текущего количества продукта. */
    QString price_string = QString::number(price); /**< Преобразование цены в строку. */
    ui->price_1->setText(price_string); /**< Установка цены продукта. */
    QString price_full_string = QString::number(price * multiplier); /**< Вычисление полной стоимости. */
    ui->price_full_1->setText(price_full_string); /**< Установка полной стоимости. */
}

/**
 * @brief Обработчик нажатия на текст "ContactsText".
 */
void BasketWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE"; /**< Ссылка на страницу контактов. */
    QDesktopServices::openUrl(QUrl(link)); /**< Открытие ссылки в стандартном браузере. */
}
