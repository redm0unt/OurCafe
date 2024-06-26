#ifndef BASKETWINDOW_H
#define BASKETWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>

namespace Ui {
class BasketWindow;
}

class BasketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BasketWindow(QWidget *parent = nullptr);
    ~BasketWindow();
    QVector<QWidget*> cards;
    QVector<QLabel*> pictures;
    QVector<QLabel*> descriptions;
    QVector<QLabel*> prices;
    QVector<QLabel*> prices_full;

private slots:
    void on_MainLogo_clicked();
    void on_MenuButton_clicked();
    void on_BookingButton_clicked();
    void on_ContactsText_clicked();
    void on_AccountButton_clicked();

    void on_plus_1_clicked();
    void on_minus_1_clicked();
    void on_plus_2_clicked();
    void on_minus_2_clicked();
    void on_plus_3_clicked();
    void on_minus_3_clicked();
    void on_plus_4_clicked();
    void on_minus_4_clicked();
    void on_plus_5_clicked();
    void on_minus_5_clicked();

    void for_plus(QLabel *counter, QLabel *price_full, QLabel *price_per_unit);
    void for_minus(QLabel *counter, QLabel *price_full, QLabel *price_per_unit, qint64 number_card);

signals:
    void incrementCardCount();
    void return_flag(int index);
    void requestNumberOfCard(); // Сигнал для запроса значения number_of_card
    void sendNumberOfCard(int number);

public slots:
    void slot_cappuccino(QWidget *card, QLabel *picture, QLabel *description, QLabel *price, QLabel *price_full, QString url, QString name, qint64 price_num);

private slots:
    void on_Telegram_clicked();
    void on_VK_clicked();
    void on_Instagram_clicked();
    void on_Whatsapp_clicked();

public:
    Ui::BasketWindow *ui;
};

#endif // BASKETWINDOW_H
