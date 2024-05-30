#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "backendclient.h"
#include "ui_BasketWindow.h"

int number_of_card = 0;

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
, basketWindow(nullptr)

{
    ui->setupUi(this);
    basketWindow = BackendClient::getclient()->basketWindow;

    //basketWindow = new BasketWindow;

    connect(this, &MenuWindow::signal, basketWindow, &BasketWindow::slot_cappuccino);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

ui_elements MenuWindow::get_ui_elements(int index) {
    ui_elements elements;
    elements.card = basketWindow->cards[index];
    elements.picture = basketWindow->pictures[index];
    elements.description = basketWindow->descriptions[index];
    elements.price = basketWindow->prices[index];
    elements.price_full = basketWindow->prices_full[index];
    return elements;
}

void MenuWindow::on_MainLogo_clicked()
{
    BackendClient::open_main_window();
    this->hide();
}
void MenuWindow::on_BookingButton_clicked()
{
    BackendClient::open_booking_window();
    this->hide();
}

void MenuWindow::on_BasketButton_clicked()
{
    BackendClient::open_basket_window();
    this->hide();
}

void MenuWindow::on_AccountButton_clicked()
{
    BackendClient::open_profile_window();
    this->hide();
}

void MenuWindow::on_ContactsText_clicked()
{
    QString link = "https://yandex.ru/maps/-/CDbGVFIE";
    QDesktopServices::openUrl(QUrl(link));
}


void MenuWindow::on_cappuccino_pushButton_clicked(){
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
        "border-image: url(:/resources/resources/cappuccino.png);", "cappuccino", 170);}

void MenuWindow::on_latte_pushButton_clicked(){
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
        "border-image: url(:/resources/resources/latte.png);", "latte", 170);}

void MenuWindow::on_raf_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
        "border-image: url(:/resources/resources/raf.png);", "raf", 190);}

void MenuWindow::on_hotchocolate_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/hot_chocolate.png);", "hot chocolate", 200);
}
void MenuWindow::on_cocoa_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/cocoa.png);", "cocoa", 200);
}


void MenuWindow::on_espresso_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/espresso.png);", "espresso", 120);
}
void MenuWindow::on_americano_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/americano.png);", "americano", 130);
}
void MenuWindow::on_tea_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/tea.png);", "tea", 90);
}




void MenuWindow::on_matcha_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/matcha.png);", "matcha", 180);
}



void MenuWindow::on_milkshake_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/milkshake.png);", "milkshake", 210);
}



void MenuWindow::on_threechocolates_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/three_chocolates.png);", "three chocolates", 230);
}


void MenuWindow::on_birdsmilk_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/birds_milk.png);", "bird's milk", 210);
}



void MenuWindow::on_napoleon_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/napoleon.png);", "napoleon", 190);
}



void MenuWindow::on_medovik_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/medovik.png);", "medovik", 200);
}



void MenuWindow::on_shucake_pushButton_clicked()
{
    number_of_card += 1;
    ui_elements elements = get_ui_elements(number_of_card-1);
    emit signal(elements.card, elements.picture, elements.description, elements.price, elements.price_full,
                "border-image: url(:/resources/resources/shu_cake.png);", "shu cake", 150);
}

