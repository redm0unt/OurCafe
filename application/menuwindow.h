#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

// private slots:
//     void on_MainLogo_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
