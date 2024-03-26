#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Draw Main Logo
    QString MainLogoPixmapPath = ":/resources/resources/MainLogo.png";
    QPixmap MainLogoPixmap(MainLogoPixmapPath);

    qDebug() << "Width: " << MainLogoPixmap.width();
    qDebug() << "Height: " << MainLogoPixmap.height();
    qDebug() << ui->MainLogo->width();
    qDebug() << ui->MainLogo->height();

    int MainLogoWidth = 180;
    ui->MainLogo->setPixmap(MainLogoPixmap.scaled(MainLogoWidth, MainLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Draw Cart Logo
    QString cartPixmapPath = ":/resources/resources/Cart.png";
    QPixmap CartPixmap(cartPixmapPath);
    int cartLogoWidth = 45;
    ui->Cart->setPixmap(CartPixmap.scaled(cartLogoWidth, cartLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Draw Account Logo
    QString accountPixmapPath = ":/resources/resources/Account.png";
    QPixmap AccountPixmap(accountPixmapPath);
    int accountLogoWidth = 45;
    ui->Account->setPixmap(AccountPixmap.scaled(accountLogoWidth, accountLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    // Social Logos
    int socialLogoSize = 35;

    // Draw Telegram
    QString TelegramPixmapPath = ":/resources/resources/Telegram.png";
    QPixmap TelegramPixmap(TelegramPixmapPath);
    int TelegramLogoWidth = socialLogoSize;
    ui->Telegram->setPixmap(TelegramPixmap.scaled(TelegramLogoWidth, TelegramLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Draw Whatsapp
    QString WhatsappPixmapPath = ":/resources/resources/Whatsapp.png";
    QPixmap WhatsappPixmap(WhatsappPixmapPath);
    int WhatsappLogoWidth = socialLogoSize;
    ui->Whatsapp->setPixmap(WhatsappPixmap.scaled(WhatsappLogoWidth, WhatsappLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Draw VK
    QString VKPixmapPath = ":/resources/resources/VK.png";
    QPixmap VKPixmap(VKPixmapPath);
    int VKLogoWidth = socialLogoSize;
    ui->VK->setPixmap(VKPixmap.scaled(VKLogoWidth, VKLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Draw Instagram
    QString InstagramPixmapPath = ":/resources/resources/Instagram.png";
    QPixmap InstagramPixmap(InstagramPixmapPath);
    int InstagramLogoWidth = socialLogoSize;
    ui->Instagram->setPixmap(InstagramPixmap.scaled(InstagramLogoWidth, InstagramLogoWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}
