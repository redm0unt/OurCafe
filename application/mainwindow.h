#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuwindow.h"
#include "bookingwindow.h"
#include "basketwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MenuButton_clicked();

    void on_BookingButton_clicked();

    void on_BasketButton_clicked();

private:
    Ui::MainWindow *ui;
    MenuWindow *menuWindow;
    BookingWindow *bookingWindow;
    BasketWindow *basketWindow;
};


#endif // MAINWINDOW_H
