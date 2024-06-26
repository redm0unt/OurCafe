#ifndef ENTERING_WINDOW_H
#define ENTERING_WINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class entering_window;
}
QT_END_NAMESPACE

class entering_window : public QMainWindow
{
Q_OBJECT

public:
    entering_window(QWidget *parent = nullptr);
    ~entering_window();

private slots:
    void on_SingInButton_clicked();

    void on_RegisterButton_clicked();

private:
    Ui::entering_window *ui;
};


#endif // ENTERING_WINDOW_H
