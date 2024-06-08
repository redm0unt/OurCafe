#ifndef BASKETWINDOW_H
#define BASKETWINDOW_H

#include <QMainWindow>

namespace Ui {
class BasketWindow;
}

/**
 * @brief Класс для окна корзины.
 */
class BasketWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса окна корзины.
     * @param parent Родительский виджет.
     */
    explicit BasketWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса окна корзины.
     */
    ~BasketWindow();

private slots:
    void on_MainLogo_clicked(); /**< Обработчик нажатия на кнопку MainLogo. */
    void on_MenuButton_clicked(); /**< Обработчик нажатия на кнопку MenuButton. */
    void on_BookingButton_clicked(); /**< Обработчик нажатия на кнопку BookingButton. */
    void on_ContactsText_clicked(); /**< Обработчик нажатия на текст ContactsText. */
    void on_AccountButton_clicked(); /**< Обработчик нажатия на кнопку AccountButton. */

public slots:
    /**
     * @brief Обработчик сигнала о получении информации о продукте "капучино".
     * @param url URL изображения.
     * @param name Название продукта.
     * @param price Цена продукта.
     */
    void slot_cappuccino(QString url, QString name, qint64 price);

public:
    Ui::BasketWindow *ui; /**< Указатель на интерфейс окна. */

};

#endif // BASKETWINDOW_H
