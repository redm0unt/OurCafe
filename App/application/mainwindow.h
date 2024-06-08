/**
 * @file MainWindow.h
 * @brief Заголовочный файл с объявлением класса MainWindow для главного окна приложения.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

/**
 * @brief Класс главного окна приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow.
     * 
     * @param parent Родительский объект.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Слот для обработки клика по кнопке "Меню".
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
     * @brief Слот для обработки нажатия кнопки "Аккаунт".
     */
    void on_AccountButton_clicked();

private:
    Ui::MainWindow *ui; /**< Указатель на объект пользовательского интерфейса. */
};

#endif // MAINWINDOW_H
