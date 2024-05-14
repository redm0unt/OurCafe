#ifndef CUSTOM_WIDGET_H
#define CUSTOM_WIDGET_H

#include <QLabel>
#include <QMouseEvent>


class Custom_Widget
{
public:
    Custom_Widget();
};


class QLabel_Custom_Widget : QLabel
{
    Q_OBJECT
public:
    QLabel_Custom_Widget();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event) ;
    using QLabel::QLabel;
};
#endif // CUSTOM_WIDGET_H
