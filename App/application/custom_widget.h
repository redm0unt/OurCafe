#ifndef CUSTOM_WIDGET_H
#define CUSTOM_WIDGET_H

#include <QLabel>
#include <QMouseEvent>

/**
 * @brief Класс пользовательского виджета.
 */
class Custom_Widget
{
public:
    /**
     * @brief Конструктор класса Custom_Widget.
     */
    Custom_Widget();
};

/**
 * @brief Класс пользовательского QLabel.
 */
class QLabel_Custom_Widget : public QLabel
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса QLabel_Custom_Widget.
     */
    QLabel_Custom_Widget();

signals:
    /**
     * @brief Сигнал, отправляемый при щелчке мышью на метке.
     */
    void clicked();

protected:
    /**
     * @brief Обработчик события нажатия мышью.
     * @param event Событие мыши.
     */
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CUSTOM_WIDGET_H
