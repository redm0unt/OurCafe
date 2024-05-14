/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Window;
    QHBoxLayout *Window_horizontalLayout;
    QWidget *Sidebar;
    QVBoxLayout *Sidebar_verticalLayout;
    QWidget *MainLogoWrapper;
    QHBoxLayout *MainLogoWrapper_horizontalLayout;
    QPushButton *MainLogo;
    QSpacerItem *Sidebar_verticalSpacer_3;
    QPushButton *MenuButton;
    QPushButton *BookingButton;
    QPushButton *BasketButton;
    QSpacerItem *Sidebar_verticalSpacer;
    QLabel *ContactsHeader;
    QSpacerItem *Sidebar_verticalSpacer_4;
    QWidget *ContactsTextWrapper;
    QHBoxLayout *ContactsTextWrapper_horizontalLayout_2;
    QLabel *ContactsText;
    QSpacerItem *Sidebar_verticalSpacer_2;
    QWidget *Social;
    QHBoxLayout *Social_horizontalLayout;
    QPushButton *Telegram;
    QPushButton *VK;
    QPushButton *Instagram;
    QPushButton *Whatsapp;
    QFrame *Sidebar_line;
    QWidget *Content;
    QVBoxLayout *Content_verticalLayout;
    QWidget *Header;
    QHBoxLayout *Header_horizontalLayout;
    QLabel *Heading;
    QWidget *CartAccountBlock;
    QHBoxLayout *CartAccountBlock_horizontalLayout;
    QPushButton *Cart;
    QPushButton *Account;
    QSpacerItem *horizontalSpacer;
    QFrame *Header_line;
    QWidget *PageContent;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1360, 765);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 445));
        MainWindow->setMaximumSize(QSize(15360, 8640));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #E7D8CB;\n"
"color: #000000;"));
        Window = new QWidget(MainWindow);
        Window->setObjectName("Window");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Window->sizePolicy().hasHeightForWidth());
        Window->setSizePolicy(sizePolicy1);
        Window_horizontalLayout = new QHBoxLayout(Window);
        Window_horizontalLayout->setSpacing(0);
        Window_horizontalLayout->setObjectName("Window_horizontalLayout");
        Window_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Sidebar = new QWidget(Window);
        Sidebar->setObjectName("Sidebar");
        Sidebar->setEnabled(true);
        sizePolicy1.setHeightForWidth(Sidebar->sizePolicy().hasHeightForWidth());
        Sidebar->setSizePolicy(sizePolicy1);
        Sidebar->setMinimumSize(QSize(230, 0));
        Sidebar->setMaximumSize(QSize(230, 16777215));
        Sidebar->setBaseSize(QSize(230, 0));
        Sidebar->setStyleSheet(QString::fromUtf8("font: 700 40px"));
        Sidebar_verticalLayout = new QVBoxLayout(Sidebar);
        Sidebar_verticalLayout->setSpacing(0);
        Sidebar_verticalLayout->setObjectName("Sidebar_verticalLayout");
        Sidebar_verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        Sidebar_verticalLayout->setContentsMargins(0, 20, 0, 20);
        MainLogoWrapper = new QWidget(Sidebar);
        MainLogoWrapper->setObjectName("MainLogoWrapper");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MainLogoWrapper->sizePolicy().hasHeightForWidth());
        MainLogoWrapper->setSizePolicy(sizePolicy2);
        MainLogoWrapper->setMinimumSize(QSize(190, 190));
        MainLogoWrapper->setMaximumSize(QSize(256, 256));
        MainLogoWrapper_horizontalLayout = new QHBoxLayout(MainLogoWrapper);
        MainLogoWrapper_horizontalLayout->setSpacing(0);
        MainLogoWrapper_horizontalLayout->setObjectName("MainLogoWrapper_horizontalLayout");
        MainLogoWrapper_horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        MainLogoWrapper_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MainLogo = new QPushButton(MainLogoWrapper);
        MainLogo->setObjectName("MainLogo");
        sizePolicy2.setHeightForWidth(MainLogo->sizePolicy().hasHeightForWidth());
        MainLogo->setSizePolicy(sizePolicy2);
        MainLogo->setMinimumSize(QSize(190, 190));
        MainLogo->setMaximumSize(QSize(190, 190));
        MainLogo->setCursor(QCursor(Qt::PointingHandCursor));
        MainLogo->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/MainLogo.png) 0 stretch stretch;"));

        MainLogoWrapper_horizontalLayout->addWidget(MainLogo);


        Sidebar_verticalLayout->addWidget(MainLogoWrapper);

        Sidebar_verticalSpacer_3 = new QSpacerItem(45, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        Sidebar_verticalLayout->addItem(Sidebar_verticalSpacer_3);

        MenuButton = new QPushButton(Sidebar);
        MenuButton->setObjectName("MenuButton");
        MenuButton->setMinimumSize(QSize(0, 90));
        MenuButton->setBaseSize(QSize(0, 0));
        MenuButton->setCursor(QCursor(Qt::PointingHandCursor));
        MenuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:hover {\n"
"	color: #ffffff;\n"
"	background-color: #E59C59;\n"
"}"));

        Sidebar_verticalLayout->addWidget(MenuButton);

        BookingButton = new QPushButton(Sidebar);
        BookingButton->setObjectName("BookingButton");
        BookingButton->setMinimumSize(QSize(0, 90));
        BookingButton->setBaseSize(QSize(0, 0));
        BookingButton->setCursor(QCursor(Qt::PointingHandCursor));

        Sidebar_verticalLayout->addWidget(BookingButton);

        BasketButton = new QPushButton(Sidebar);
        BasketButton->setObjectName("BasketButton");
        BasketButton->setMinimumSize(QSize(0, 90));
        BasketButton->setBaseSize(QSize(0, 0));
        BasketButton->setCursor(QCursor(Qt::PointingHandCursor));
        BasketButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:hover {\n"
"	color: #ffffff;\n"
"	background-color: #E59C59;\n"
"}"));

        Sidebar_verticalLayout->addWidget(BasketButton);

        Sidebar_verticalSpacer = new QSpacerItem(45, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        Sidebar_verticalLayout->addItem(Sidebar_verticalSpacer);

        ContactsHeader = new QLabel(Sidebar);
        ContactsHeader->setObjectName("ContactsHeader");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ContactsHeader->sizePolicy().hasHeightForWidth());
        ContactsHeader->setSizePolicy(sizePolicy3);
        ContactsHeader->setMaximumSize(QSize(16777215, 50));
        ContactsHeader->setStyleSheet(QString::fromUtf8("font: 700 26px;"));
        ContactsHeader->setAlignment(Qt::AlignCenter);
        ContactsHeader->setIndent(0);

        Sidebar_verticalLayout->addWidget(ContactsHeader);

        Sidebar_verticalSpacer_4 = new QSpacerItem(45, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        Sidebar_verticalLayout->addItem(Sidebar_verticalSpacer_4);

        ContactsTextWrapper = new QWidget(Sidebar);
        ContactsTextWrapper->setObjectName("ContactsTextWrapper");
        ContactsTextWrapper_horizontalLayout_2 = new QHBoxLayout(ContactsTextWrapper);
        ContactsTextWrapper_horizontalLayout_2->setSpacing(0);
        ContactsTextWrapper_horizontalLayout_2->setObjectName("ContactsTextWrapper_horizontalLayout_2");
        ContactsTextWrapper_horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        ContactsText = new QLabel(ContactsTextWrapper);
        ContactsText->setObjectName("ContactsText");
        sizePolicy1.setHeightForWidth(ContactsText->sizePolicy().hasHeightForWidth());
        ContactsText->setSizePolicy(sizePolicy1);
        ContactsText->setMaximumSize(QSize(180, 16777215));
        ContactsText->setCursor(QCursor(Qt::ArrowCursor));
        ContactsText->setMouseTracking(true);
        ContactsText->setFocusPolicy(Qt::NoFocus);
        ContactsText->setStyleSheet(QString::fromUtf8("font: 14px;"));
        ContactsText->setFrameShadow(QFrame::Plain);
        ContactsText->setTextFormat(Qt::AutoText);
        ContactsText->setScaledContents(false);
        ContactsText->setAlignment(Qt::AlignCenter);
        ContactsText->setWordWrap(true);
        ContactsText->setIndent(0);
        ContactsText->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        ContactsTextWrapper_horizontalLayout_2->addWidget(ContactsText);


        Sidebar_verticalLayout->addWidget(ContactsTextWrapper);

        Sidebar_verticalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        Sidebar_verticalLayout->addItem(Sidebar_verticalSpacer_2);

        Social = new QWidget(Sidebar);
        Social->setObjectName("Social");
        sizePolicy3.setHeightForWidth(Social->sizePolicy().hasHeightForWidth());
        Social->setSizePolicy(sizePolicy3);
        Social_horizontalLayout = new QHBoxLayout(Social);
        Social_horizontalLayout->setSpacing(0);
        Social_horizontalLayout->setObjectName("Social_horizontalLayout");
        Social_horizontalLayout->setContentsMargins(0, 2, 0, 3);
        Telegram = new QPushButton(Social);
        Telegram->setObjectName("Telegram");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Telegram->sizePolicy().hasHeightForWidth());
        Telegram->setSizePolicy(sizePolicy4);
        Telegram->setMinimumSize(QSize(35, 35));
        Telegram->setMaximumSize(QSize(35, 35));
        Telegram->setCursor(QCursor(Qt::PointingHandCursor));
        Telegram->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Telegram.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(Telegram);

        VK = new QPushButton(Social);
        VK->setObjectName("VK");
        sizePolicy4.setHeightForWidth(VK->sizePolicy().hasHeightForWidth());
        VK->setSizePolicy(sizePolicy4);
        VK->setMinimumSize(QSize(35, 35));
        VK->setMaximumSize(QSize(35, 35));
        VK->setCursor(QCursor(Qt::PointingHandCursor));
        VK->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/VK.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(VK);

        Instagram = new QPushButton(Social);
        Instagram->setObjectName("Instagram");
        sizePolicy4.setHeightForWidth(Instagram->sizePolicy().hasHeightForWidth());
        Instagram->setSizePolicy(sizePolicy4);
        Instagram->setMinimumSize(QSize(35, 35));
        Instagram->setMaximumSize(QSize(35, 35));
        Instagram->setCursor(QCursor(Qt::PointingHandCursor));
        Instagram->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Instagram.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(Instagram);

        Whatsapp = new QPushButton(Social);
        Whatsapp->setObjectName("Whatsapp");
        sizePolicy4.setHeightForWidth(Whatsapp->sizePolicy().hasHeightForWidth());
        Whatsapp->setSizePolicy(sizePolicy4);
        Whatsapp->setMinimumSize(QSize(35, 35));
        Whatsapp->setMaximumSize(QSize(35, 35));
        Whatsapp->setCursor(QCursor(Qt::PointingHandCursor));
        Whatsapp->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Whatsapp.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(Whatsapp);


        Sidebar_verticalLayout->addWidget(Social);


        Window_horizontalLayout->addWidget(Sidebar);

        Sidebar_line = new QFrame(Window);
        Sidebar_line->setObjectName("Sidebar_line");
        sizePolicy1.setHeightForWidth(Sidebar_line->sizePolicy().hasHeightForWidth());
        Sidebar_line->setSizePolicy(sizePolicy1);
        Sidebar_line->setMinimumSize(QSize(4, 0));
        Sidebar_line->setMaximumSize(QSize(4, 16777215));
        Sidebar_line->setFrameShadow(QFrame::Plain);
        Sidebar_line->setLineWidth(4);
        Sidebar_line->setFrameShape(QFrame::VLine);

        Window_horizontalLayout->addWidget(Sidebar_line);

        Content = new QWidget(Window);
        Content->setObjectName("Content");
        Content_verticalLayout = new QVBoxLayout(Content);
        Content_verticalLayout->setSpacing(0);
        Content_verticalLayout->setObjectName("Content_verticalLayout");
        Content_verticalLayout->setContentsMargins(0, 0, 0, 0);
        Header = new QWidget(Content);
        Header->setObjectName("Header");
        sizePolicy3.setHeightForWidth(Header->sizePolicy().hasHeightForWidth());
        Header->setSizePolicy(sizePolicy3);
        Header->setMinimumSize(QSize(0, 90));
        Header->setMaximumSize(QSize(16777215, 90));
        Header->setStyleSheet(QString::fromUtf8("font: 700 45px;"));
        Header_horizontalLayout = new QHBoxLayout(Header);
        Header_horizontalLayout->setSpacing(0);
        Header_horizontalLayout->setObjectName("Header_horizontalLayout");
        Header_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Heading = new QLabel(Header);
        Heading->setObjectName("Heading");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Heading->sizePolicy().hasHeightForWidth());
        Heading->setSizePolicy(sizePolicy5);
        Heading->setAlignment(Qt::AlignCenter);
        Heading->setIndent(0);

        Header_horizontalLayout->addWidget(Heading);

        CartAccountBlock = new QWidget(Header);
        CartAccountBlock->setObjectName("CartAccountBlock");
        sizePolicy4.setHeightForWidth(CartAccountBlock->sizePolicy().hasHeightForWidth());
        CartAccountBlock->setSizePolicy(sizePolicy4);
        CartAccountBlock->setMinimumSize(QSize(140, 0));
        CartAccountBlock->setMaximumSize(QSize(140, 16777215));
        CartAccountBlock_horizontalLayout = new QHBoxLayout(CartAccountBlock);
        CartAccountBlock_horizontalLayout->setSpacing(15);
        CartAccountBlock_horizontalLayout->setObjectName("CartAccountBlock_horizontalLayout");
        CartAccountBlock_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Cart = new QPushButton(CartAccountBlock);
        Cart->setObjectName("Cart");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Cart->sizePolicy().hasHeightForWidth());
        Cart->setSizePolicy(sizePolicy6);
        Cart->setMinimumSize(QSize(45, 45));
        Cart->setMaximumSize(QSize(45, 45));
        Cart->setCursor(QCursor(Qt::PointingHandCursor));
        Cart->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Cart.png) 0 stretch stretch;"));

        CartAccountBlock_horizontalLayout->addWidget(Cart);

        Account = new QPushButton(CartAccountBlock);
        Account->setObjectName("Account");
        sizePolicy6.setHeightForWidth(Account->sizePolicy().hasHeightForWidth());
        Account->setSizePolicy(sizePolicy6);
        Account->setMinimumSize(QSize(45, 45));
        Account->setMaximumSize(QSize(45, 45));
        Account->setCursor(QCursor(Qt::PointingHandCursor));
        Account->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Account.png) 0 stretch stretch;"));

        CartAccountBlock_horizontalLayout->addWidget(Account);


        Header_horizontalLayout->addWidget(CartAccountBlock);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        Header_horizontalLayout->addItem(horizontalSpacer);


        Content_verticalLayout->addWidget(Header);

        Header_line = new QFrame(Content);
        Header_line->setObjectName("Header_line");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(Header_line->sizePolicy().hasHeightForWidth());
        Header_line->setSizePolicy(sizePolicy7);
        Header_line->setMinimumSize(QSize(0, 4));
        Header_line->setMaximumSize(QSize(16777215, 4));
        Header_line->setFrameShadow(QFrame::Plain);
        Header_line->setLineWidth(4);
        Header_line->setFrameShape(QFrame::HLine);

        Content_verticalLayout->addWidget(Header_line);

        PageContent = new QWidget(Content);
        PageContent->setObjectName("PageContent");
        verticalLayout = new QVBoxLayout(PageContent);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(PageContent);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(70, 15, 70, 15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(0, 380));
        label->setMaximumSize(QSize(16777215, 380));
        label->setBaseSize(QSize(0, 380));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/dessert.png);"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(0, 390));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/cocoa.png);"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMinimumSize(QSize(0, 380));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/coffee.png);"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addWidget(widget);


        Content_verticalLayout->addWidget(PageContent);


        Window_horizontalLayout->addWidget(Content);

        MainWindow->setCentralWidget(Window);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OurCafe", nullptr));
        MainLogo->setText(QString());
        MenuButton->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        BookingButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"	\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:hover {\n"
"	color: #ffffff;\n"
"	background-color: #E59C59;\n"
"}", nullptr));
        BookingButton->setText(QCoreApplication::translate("MainWindow", "Booking", nullptr));
        BasketButton->setText(QCoreApplication::translate("MainWindow", "Basket", nullptr));
        ContactsHeader->setText(QCoreApplication::translate("MainWindow", "Contacts", nullptr));
        ContactsText->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Address:</span> 11 Kolotushkina St., Building 3, Moscow<br/><span style=\" font-weight:700;\">Metro station:</span> Pushkino<br/><span style=\" font-weight:700;\">Phone number:</span> +7-888-888-88-88<br/><span style=\" font-weight:700;\">Mail:</span> OurCafe@mail.ru</p></body></html>", nullptr));
        Telegram->setText(QString());
        VK->setText(QString());
        Instagram->setText(QString());
        Whatsapp->setText(QString());
        Heading->setText(QCoreApplication::translate("MainWindow", "Main", nullptr));
        Cart->setText(QString());
        Account->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
