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

// private slots:
//     void on_MainLogo_clicked();

private slots:
    void on_MainLogo_clicked();

    void on_ContactsText_clicked();

private:
    Ui::MenuWindow *ui;
};


#endif // MENUWINDOW_H
