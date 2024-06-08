#include "custom_widget.h"

/**
 * @brief Custom_Widget::Custom_Widget
 * Конструктор класса Custom_Widget.
 */
Custom_Widget::Custom_Widget()
{

}

/**
 * @brief QLabel_Custom_Widget::QLabel_Custom_Widget
 * Конструктор класса QLabel_Custom_Widget.
 */
QLabel_Custom_Widget::QLabel_Custom_Widget()
{

}

/**
 * @brief QLabel_Custom_Widget::mousePressEvent
 * Обработчик события нажатия кнопки мыши.
 * Отправляет сигнал clicked при нажатии на метку.
 * @param event Событие нажатия кнопки мыши.
 */
void QLabel_Custom_Widget::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
