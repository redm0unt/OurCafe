#include "basketwindow.h"
#include "ui_basketwindow.h"
#include "backendclient.h"
int lastAddedCardIndex = 0;

BasketWindow::BasketWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BasketWindow)
{
    ui->setupUi(this);
    for (int i = 1; i <= 15; i++) {
        QString cardName = QString("card_%1").arg(i);
        QWidget *card = findChild<QWidget*>(cardName);
        if (card) {
            card->hide();
        }
    }

    for (int i = 1; i <= 5; i++) {
        cards.append(findChild<QWidget*>("card_" + QString::number(i)));
        pictures.append(findChild<QLabel*>("picture_" + QString::number(i)));
        descriptions.append(findChild<QLabel*>("description_" + QString::number(i)));
        prices.append(findChild<QLabel*>("price_" + QString::number(i)));
        prices_full.append(findChild<QLabel*>("price_full_" + QString::number(i)));
    }
}

BasketWindow::~BasketWindow()
{
    delete ui;
}

void BasketWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}

void BasketWindow::on_MenuButton_clicked()
{
    BackendClient::open_menu_window();
    this->hide();
}

void BasketWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void BasketWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

QString last_url;
QString last_name;
qint64 last_price_num;

void BasketWindow::slot_cappuccino(QWidget *card, QLabel *picture, QLabel *description, QLabel *price, QLabel *price_full, QString url, QString name, qint64 price_num)
{
    card->show();
    picture->setStyleSheet(url);
    description->setText(name);
    QString price_string = QString::number(price_num);
    price->setText(price_string);
    price_full->setText(QString::number(price_num));
    lastAddedCardIndex += 1;
    last_url = url;
    last_name = name;
    last_price_num = price_num;
}

void BasketWindow::on_ContactsText_clicked(){
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}

void BasketWindow::for_plus(QLabel *counter, QLabel *price_full, QLabel *price_per_unit) {
    int counter_value = counter->text().toInt();
    int price_per_unit_int = price_per_unit->text().toInt();
    QString new_counter = QString::number(counter_value + 1);
    counter->setText(new_counter);
    QString price_full_string = QString::number(price_per_unit_int * (counter_value + 1));
    price_full->setText(price_full_string);
}



void BasketWindow::for_minus(QLabel *counter, QLabel *price_full, QLabel *price_per_unit, qint64 number_card) {
    int counter_value = counter->text().toInt();
    if (counter_value == 1){
        cards[number_card - 1]->hide();
        emit incrementCardCount();
        emit return_flag(number_card - 1);
    }
    else{
        int price_per_unit_int = price_per_unit->text().toInt();
        QString new_counter = QString::number(counter_value - 1);
        counter->setText(new_counter);
        QString price_full_string = QString::number(price_per_unit_int * (counter_value - 1));
        price_full->setText(price_full_string);}

}

void BasketWindow::on_plus_1_clicked(){
    for_plus(ui->counter_1, ui->price_full_1, ui->price_1);}
void BasketWindow::on_minus_1_clicked(){
    for_minus(ui->counter_1, ui->price_full_1, ui->price_1, 1);}
void BasketWindow::on_plus_2_clicked(){
    for_plus(ui->counter_2, ui->price_full_2, ui->price_2);}
void BasketWindow::on_minus_2_clicked(){
    for_minus(ui->counter_2, ui->price_full_2, ui->price_2, 2);}
void BasketWindow::on_plus_3_clicked(){
    for_plus(ui->counter_3, ui->price_full_3, ui->price_3);}
void BasketWindow::on_minus_3_clicked(){
    for_minus(ui->counter_3, ui->price_full_3, ui->price_3, 3);}
void BasketWindow::on_plus_4_clicked(){
    for_plus(ui->counter_4, ui->price_full_4, ui->price_4);}
void BasketWindow::on_minus_4_clicked(){
    for_minus(ui->counter_4, ui->price_full_4, ui->price_4, 4);}
void BasketWindow::on_plus_5_clicked(){
    for_plus(ui->counter_5, ui->price_full_5, ui->price_5);}
void BasketWindow::on_minus_5_clicked(){
    for_minus(ui->counter_5, ui->price_full_5, ui->price_5, 5);}



void BasketWindow::on_Telegram_clicked()
{
    BackendClient::open_external("telegram");
}
void BasketWindow::on_Instagram_clicked()
{
    BackendClient::open_external("instagram");
}
void BasketWindow::on_VK_clicked()
{
    BackendClient::open_external("vk");
}
void BasketWindow::on_Whatsapp_clicked()
{
    BackendClient::open_external("whatsapp");
}







