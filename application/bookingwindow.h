#ifndef BOOKINGWINDOW_H
#define BOOKINGWINDOW_H

#include <QMainWindow>
// #include "menuwindow.h"

namespace Ui {
class BookingWindow;
}

class BookingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookingWindow(QWidget *parent = nullptr);
    ~BookingWindow();


private slots:
    void on_MainLogo_clicked();
    void on_MenuButton_clicked();
    void on_BasketButton_clicked();

    void on_ContactsText_clicked();

private:
    Ui::BookingWindow *ui;
    //MenuWindow *menuWindow;
};

#endif // BOOKINGWINDOW_H
