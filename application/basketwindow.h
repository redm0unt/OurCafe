#ifndef BASKETWINDOW_H
#define BASKETWINDOW_H

#include <QMainWindow>
//#include "menuwindow.h"

namespace Ui {
class BasketWindow;
}

class BasketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BasketWindow(QWidget *parent = nullptr);
    ~BasketWindow();

private slots:
    void on_MainLogo_clicked();
    void on_MenuButton_clicked();
    void on_BookingButton_clicked();

    void on_ContactsText_clicked();

private:
    Ui::BasketWindow *ui;
//    MenuWindow *menuWindow;
};

#endif // BASKETWINDOW_H
