/**
 * @file message.h
 * @brief Заголовочный файл с объявлением структуры Message для представления сообщения.
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

/**
 * @brief Структура для представления сообщения.
 */
struct Message {
    QString subject; /**< Тема сообщения. */
    QString body; /**< Текст сообщения. */
};

#endif // MESSAGE_H
