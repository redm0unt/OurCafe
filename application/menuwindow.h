#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QLabel>
#include <basketwindow.h>
#include <QVector>

struct ui_elements {
    QWidget *card;
    QLabel *picture;
    QLabel *description;
    QLabel *price;
    QLabel *price_full;
};

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    QVector<bool> flags_for_cards;





private slots:
    void incrementCardCount();
    void return_flag(int index);
    ui_elements get_ui_elements(int index);
    bool flags(int a);
    void on_MainLogo_clicked();
    void on_ContactsText_clicked();
    void on_BookingButton_clicked();
    void on_BasketButton_clicked();
    void on_AccountButton_clicked();
    void on_cappuccino_pushButton_clicked();    
    void on_latte_pushButton_clicked();
    void on_raf_pushButton_clicked();

    void on_hotchocolate_pushButton_clicked();

    void on_cocoa_pushButton_clicked();

    void on_espresso_pushButton_clicked();

    void on_americano_pushButton_clicked();

    void on_tea_pushButton_clicked();

    void on_matcha_pushButton_clicked();

    void on_milkshake_pushButton_clicked();

    void on_threechocolates_pushButton_clicked();

    void on_birdsmilk_pushButton_clicked();

    void on_napoleon_pushButton_clicked();

    void on_medovik_pushButton_clicked();

    void on_shucake_pushButton_clicked();


    void on_Telegram_clicked();

    void on_VK_clicked();

    void on_Instagram_clicked();

    void on_Whatsapp_clicked();
signals:
    void signal(QWidget *card, QLabel *picture, QLabel *description, QLabel *price, QLabel *price_full, QString url, QString name, qint64 price_num);

private:
    Ui::MenuWindow *ui;
    BasketWindow *basketWindow;
};


#endif // MENUWINDOW_H
