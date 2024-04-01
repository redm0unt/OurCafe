#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MenuButton_clicked()
{
    hide();
    menuWindow = new MenuWindow(this);
    menuWindow->show();
}

