#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/Users/admin/Downloads/_Original Turquoise, Blue and White Abstract Painting- Ocean Art, Modern Wall Art, Office Art, Bedroom Art, Living room Art, 18__ x 24___ 1.png");
    int w = ui->label_4->width();
    int h = ui->label_4->height();
    ui->label_4->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{

    delete ui;
}
