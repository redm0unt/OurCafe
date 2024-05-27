#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();

private slots:
    void on_MenuButton_clicked();
    void on_ContactsText_clicked();
    void on_BookingButton_clicked();
    void on_BasketButton_clicked();
    void on_MainLogo_clicked();

private:
    Ui::ProfileWindow *ui;
};

#endif // PROFILEWINDOW_H
