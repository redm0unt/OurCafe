#ifndef REGISTER_WINDOW_H
#define REGISTER_WINDOW_H

#include <QMainWindow>


namespace Ui {
class register_window;
}

class register_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit register_window(QWidget *parent = nullptr);
    ~register_window();

private slots:
    void on_SingUpButton_clicked();

    void on_AuthorizationButton_clicked();

private:
    Ui::register_window *ui;
};


#endif // REGISTER_WINDOW_H
