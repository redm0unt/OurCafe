#include "custom_widget.h"

Custom_Widget::Custom_Widget()
{

}

QLabel_Custom_Widget::QLabel_Custom_Widget()
{

}

void QLabel_Custom_Widget::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
