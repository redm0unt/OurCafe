#ifndef ENTERING_WINDOW_H
#define ENTERING_WINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class entering_window;
}
QT_END_NAMESPACE

class entering_window : public QWidget
{
    Q_OBJECT

public:
    entering_window(QWidget *parent = nullptr);
    ~entering_window();

private:
    Ui::entering_window *ui;
};


#endif // ENTERING_WINDOW_H
