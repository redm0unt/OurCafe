/**
 * @file MenuWindow.h
 * @brief Заголовочный файл с объявлением класса MenuWindow для окна меню.
 */

#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>

namespace Ui {
class MenuWindow;
}

/**
 * @brief Класс окна меню.
 */
class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MenuWindow.
     * 
     * @param parent Родительский объект.
     */
    explicit MenuWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MenuWindow.
     */
    ~MenuWindow();

private slots:
    /**
     * @brief Слот для обработки клика по главному логотипу.
     */
    void on_MainLogo_clicked();

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
     * @brief Слот для обработки нажатия кнопки "Аккаунт".
     */
    void on_AccountButton_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Капучино".
     */
    void on_cappuccino_pushButton_clicked();

signals:
    /**
     * @brief Сигнал для отправки сообщения.
     * 
     * @param subject Тема сообщения.
     * @param body Текст сообщения.
     * @param timestamp Временная метка сообщения.
     */
    void signal(QString subject, QString body, qint64 timestamp);

private:
    Ui::MenuWindow *ui; /**< Указатель на объект пользовательского интерфейса. */
};

#endif // MENUWINDOW_H
