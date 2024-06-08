/**
 * @file register_window.cpp
 * @brief Файл с реализацией методов класса register_window для окна регистрации пользователей.
 */

#include "register_window.h"
#include "ui_register_window.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса register_window.
 * 
 * @param parent Родительский объект.
 */
register_window::register_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::register_window)
{
    ui->setupUi(this);
}

/**
 * @brief Деструктор класса register_window.
 */
register_window::~register_window()
{
    delete ui;
}

/**
 * @brief Обработчик нажатия кнопки "Зарегистрироваться".
 * 
 * Вызывает метод BackendClient::registration для выполнения регистрации пользователя.
 */
void register_window::on_SingUpButton_clicked()
{
    BackendClient::registration(ui->NameInput->text(), ui->LoginInput->text(), ui->EmailInput->text(), ui->PasswordInput->text(), ui->RepeatPasswordInput->text());
}

/**
 * @brief Обработчик нажатия кнопки "Авторизация".
 * 
 * Вызывает метод BackendClient::open_entering_window для открытия окна входа в систему.
 */
void register_window::on_AuthorizationButton_clicked()
{
    BackendClient::open_entering_window();
    this->hide();
}
