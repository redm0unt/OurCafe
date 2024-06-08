/**
 * @file ProfileWindow.h
 * @brief Заголовочный файл с объявлением класса ProfileWindow для окна профиля пользователя.
 */

#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>

namespace Ui {
class ProfileWindow;
}

/**
 * @brief Класс окна профиля пользователя.
 */
class ProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса ProfileWindow.
     * 
     * @param parent Родительский объект.
     */
    explicit ProfileWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса ProfileWindow.
     */
    ~ProfileWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "Меню".
     */
    void on_MenuButton_clicked();

    /**
     * @brief Слот для обработки клика по тексту "Контакты".
     */
    void on_ContactsText_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Бронирование".
     */
    void on_BookingButton_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Корзина".
     */
    void on_BasketButton_clicked();

    /**
     * @brief Слот для обработки клика по главному логотипу.
     */
    void on_MainLogo_clicked();

private:
    Ui::ProfileWindow *ui; /**< Указатель на объект пользовательского интерфейса. */
};

#endif // PROFILEWINDOW_H
