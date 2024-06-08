#include "entering_window.h"
#include "ui_entering_window.h"
#include "backendclient.h"

/**
 * @brief Конструктор класса entering_window.
 * @param parent Указатель на родительский QWidget.
 */
entering_window::entering_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::entering_window)
{
    ui->setupUi(this);
}

/**
 * @brief Деструктор класса entering_window.
 */
entering_window::~entering_window()
{
    delete ui;
}

/**
 * @brief Обработчик нажатия кнопки "Войти".
 * Вызывает метод authentificate() из класса BackendClient для авторизации пользователя.
 */
void entering_window::on_SingInButton_clicked()
{
    BackendClient::authentificate(ui->EmailInput->text(), ui->PasswordInput->text());
}

/**
 * @brief Обработчик нажатия кнопки "Зарегистрироваться".
 * Переключает на окно регистрации и скрывает текущее окно входа.
 */
void entering_window::on_RegisterButton_clicked()
{
    BackendClient::open_register_window();
    this->hide();
}
