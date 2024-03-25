#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Draw MainLogo
    QString mainLogoPixmapPath = ":/resources/resources/MainLogo.png";
    QPixmap MainLogoPixmap(mainLogoPixmapPath);
    int mainLogoWidth = ui->MainLogo->width();
    ui->MainLogo->setPixmap(MainLogoPixmap.scaled(mainLogoWidth, mainLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Draw CartLogo
    QString cartPixmapPath = ":/resources/resources/Cart.png";
    QPixmap CartPixmap(cartPixmapPath);
    int cartLogoWidth = 45;
    ui->Cart->setPixmap(CartPixmap.scaled(cartLogoWidth, cartLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Draw AccountLogo
    QString accountPixmapPath = ":/resources/resources/Account.png";
    QPixmap AccountPixmap(accountPixmapPath);
    int accountLogoWidth = 45;
    ui->Account->setPixmap(AccountPixmap.scaled(accountLogoWidth, accountLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}
