#ifndef ENTERING_WINDOW_H
#define ENTERING_WINDOW_H

#include <QMainWindow>

// Объявление пространства имён для UI
QT_BEGIN_NAMESPACE
namespace Ui {
    class entering_window;
}
QT_END_NAMESPACE

/**
 * @brief Класс entering_window представляет собой окно входа в систему.
 */
class entering_window : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса entering_window.
     * @param parent Указатель на родительский QWidget.
     */
    entering_window(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса entering_window.
     */
    ~entering_window();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Войти".
     * Вызывает метод authentificate() из класса BackendClient для авторизации пользователя.
     */
    void on_SingInButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Зарегистрироваться".
     * Переключает на окно регистрации и скрывает текущее окно входа.
     */
    void on_RegisterButton_clicked();

private:
    Ui::entering_window *ui; ///< Указатель на объект интерфейса окна входа.
};

#endif // ENTERING_WINDOW_H
