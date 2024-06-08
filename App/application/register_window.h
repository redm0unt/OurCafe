/**
 * @file register_window.h
 * @brief Заголовочный файл с объявлением класса register_window для окна регистрации пользователей.
 */

#ifndef REGISTER_WINDOW_H
#define REGISTER_WINDOW_H

#include <QMainWindow>

namespace Ui {
class register_window;
}

/**
 * @brief Класс окна регистрации пользователей.
 */
class register_window : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса register_window.
     * 
     * @param parent Родительский объект.
     */
    explicit register_window(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса register_window.
     */
    ~register_window();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "Зарегистрироваться".
     */
    void on_SingUpButton_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Авторизация".
     */
    void on_AuthorizationButton_clicked();

private:
    Ui::register_window *ui; /**< Указатель на объект пользовательского интерфейса. */
};

#endif // REGISTER_WINDOW_H
