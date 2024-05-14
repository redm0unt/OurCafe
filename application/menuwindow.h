#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
//#include "bookingwindow.h"
//#include "basketwindow.h"


namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_MainLogo_clicked();
    void on_BookingButton_clicked();
    void on_BasketButton_clicked();


private:
    Ui::MenuWindow *ui;
    //BookingWindow *bookingWindow;
    //BasketWindow *basketWindow;
};


#endif // MENUWINDOW_H
