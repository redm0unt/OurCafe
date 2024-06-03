#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    void on_ContactsText_clicked();

    void on_BookingButton_clicked();

    void on_BasketButton_clicked();

    void on_AccountButton_clicked();

    void on_Telegram_clicked();

    void on_VK_clicked();

    void on_Instagram_clicked();

    void on_Whatsapp_clicked();

private:
    Ui::MainWindow *ui;


};


#endif // MAINWINDOW_H
