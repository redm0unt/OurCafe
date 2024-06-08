#ifndef BOOKINGWINDOW_H
#define BOOKINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class BookingWindow;
}

/**
 * @brief Класс окна бронирования.
 */
class BookingWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса BookingWindow.
     * @param parent Родительский виджет.
     */
    explicit BookingWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса BookingWindow.
     */
    ~BookingWindow();


private slots:
    /**
     * @brief Слот для нажатия на кнопку главного логотипа.
     */
    void on_MainLogo_clicked();

    /**
     * @brief Слот для нажатия на кнопку меню.
     */
    void on_MenuButton_clicked();

    /**
     * @brief Слот для нажатия на кнопку корзины.
     */
    void on_BasketButton_clicked();

    /**
     * @brief Слот для нажатия на текст контактов.
     */
    void on_ContactsText_clicked();

    /**
     * @brief Слот для нажатия на кнопку аккаунта.
     */
    void on_AccountButton_clicked();

private:
    Ui::BookingWindow *ui; /**< Указатель на объект интерфейса */
};

#endif // BOOKINGWINDOW_H
