#include <QCoreApplication>

#include "tcpserver.h"

/**
 * @brief Точка входа в приложение.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCPServer *server = TCPServer::getserver(); /**< Создание экземпляра сервера. */

    return a.exec(); /**< Запуск цикла обработки событий приложения. */
}
