#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>


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
    void on_ContactsText_clicked();
    void on_BookingButton_clicked();
    void on_BasketButton_clicked();
    void on_AccountButton_clicked();
    void on_cappuccino_pushButton_clicked();


signals:
    void signal(QString, QString, qint64);

private:
    Ui::MenuWindow *ui;
};


#endif // MENUWINDOW_H
