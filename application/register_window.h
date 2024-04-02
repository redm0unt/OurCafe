#ifndef REGISTER_WINDOW_H
#define REGISTER_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class register_window;
}
QT_END_NAMESPACE

class register_window : public QMainWindow
{
    Q_OBJECT

public:
    register_window(QWidget *parent = nullptr);
    ~register_window();

private:
    Ui::register_window *ui;
};
#endif // REGISTER_WINDOW_H
