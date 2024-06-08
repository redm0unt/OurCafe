/**
 * @file main.cpp
 * @brief Главный файл приложения, содержащий функцию main.
 */

#include <QApplication>
#include "backendclient.h"

/**
 * @brief Главная функция приложения.
 * 
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата приложения.
 */
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/resources/AppIcon.png"));

    // Инициализация соединения с сервером и отправка сообщения после отрисовки графического интерфейса
    BackendClient* client = BackendClient::getclient();

    return app.exec();
}
