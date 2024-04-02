#include "menuwindow.h"
#include "ui_menuwindow.h"
//#include "mainwindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

// void MenuWindow::on_MainLogo_clicked()
// {
//     hide();
//     mainWindow = new MainWindow(this);
//     mainWindow->show();
// }

