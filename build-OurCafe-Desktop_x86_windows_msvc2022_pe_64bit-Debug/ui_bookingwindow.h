/********************************************************************************
** Form generated from reading UI file 'bookingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGWINDOW_H
#define UI_BOOKINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookingWindow
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
    QPushButton *DeliveryButton;
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
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_top_2;
    QLabel *label_bottom_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *form_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *name_2;
    QLineEdit *number_2;
    QLineEdit *people_2;
    QDateEdit *dateEdit_2;
    QPushButton *ButtonBook_2;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QMainWindow *BookingWindow)
    {
        if (BookingWindow->objectName().isEmpty())
            BookingWindow->setObjectName("BookingWindow");
        BookingWindow->resize(1360, 765);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BookingWindow->sizePolicy().hasHeightForWidth());
        BookingWindow->setSizePolicy(sizePolicy);
        BookingWindow->setMinimumSize(QSize(800, 445));
        BookingWindow->setMaximumSize(QSize(15360, 8640));
        BookingWindow->setSizeIncrement(QSize(0, 0));
        BookingWindow->setStyleSheet(QString::fromUtf8("background-color: #E7D8CB;\n"
"color: #000000;"));
        Window = new QWidget(BookingWindow);
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
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(230);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Sidebar->sizePolicy().hasHeightForWidth());
        Sidebar->setSizePolicy(sizePolicy2);
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
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MainLogoWrapper->sizePolicy().hasHeightForWidth());
        MainLogoWrapper->setSizePolicy(sizePolicy3);
        MainLogoWrapper->setMinimumSize(QSize(190, 190));
        MainLogoWrapper->setMaximumSize(QSize(256, 256));
        MainLogoWrapper_horizontalLayout = new QHBoxLayout(MainLogoWrapper);
        MainLogoWrapper_horizontalLayout->setSpacing(0);
        MainLogoWrapper_horizontalLayout->setObjectName("MainLogoWrapper_horizontalLayout");
        MainLogoWrapper_horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        MainLogoWrapper_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MainLogo = new QPushButton(MainLogoWrapper);
        MainLogo->setObjectName("MainLogo");
        sizePolicy3.setHeightForWidth(MainLogo->sizePolicy().hasHeightForWidth());
        MainLogo->setSizePolicy(sizePolicy3);
        MainLogo->setMinimumSize(QSize(190, 190));
        MainLogo->setMaximumSize(QSize(190, 190));
        MainLogo->setCursor(QCursor(Qt::PointingHandCursor));
        MainLogo->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/MainLogo.png) 0 stretch stretch;"));

        MainLogoWrapper_horizontalLayout->addWidget(MainLogo);


        Sidebar_verticalLayout->addWidget(MainLogoWrapper);

        Sidebar_verticalSpacer_3 = new QSpacerItem(45, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

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

        DeliveryButton = new QPushButton(Sidebar);
        DeliveryButton->setObjectName("DeliveryButton");
        DeliveryButton->setMinimumSize(QSize(0, 90));
        DeliveryButton->setBaseSize(QSize(0, 0));
        DeliveryButton->setCursor(QCursor(Qt::PointingHandCursor));
        DeliveryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:hover {\n"
"	color: #ffffff;\n"
"	background-color: #E59C59;\n"
"}"));

        Sidebar_verticalLayout->addWidget(DeliveryButton);

        Sidebar_verticalSpacer = new QSpacerItem(45, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        Sidebar_verticalLayout->addItem(Sidebar_verticalSpacer);

        ContactsHeader = new QLabel(Sidebar);
        ContactsHeader->setObjectName("ContactsHeader");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ContactsHeader->sizePolicy().hasHeightForWidth());
        ContactsHeader->setSizePolicy(sizePolicy4);
        ContactsHeader->setMinimumSize(QSize(0, 20));
        ContactsHeader->setMaximumSize(QSize(16777215, 40));
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
        ContactsText->setStyleSheet(QString::fromUtf8("font: 14px"));
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
        sizePolicy4.setHeightForWidth(Social->sizePolicy().hasHeightForWidth());
        Social->setSizePolicy(sizePolicy4);
        Social_horizontalLayout = new QHBoxLayout(Social);
        Social_horizontalLayout->setSpacing(0);
        Social_horizontalLayout->setObjectName("Social_horizontalLayout");
        Social_horizontalLayout->setContentsMargins(0, 2, 0, 3);
        Telegram = new QPushButton(Social);
        Telegram->setObjectName("Telegram");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Telegram->sizePolicy().hasHeightForWidth());
        Telegram->setSizePolicy(sizePolicy5);
        Telegram->setMinimumSize(QSize(35, 35));
        Telegram->setMaximumSize(QSize(35, 35));
        Telegram->setCursor(QCursor(Qt::PointingHandCursor));
        Telegram->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Telegram.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(Telegram);

        VK = new QPushButton(Social);
        VK->setObjectName("VK");
        sizePolicy5.setHeightForWidth(VK->sizePolicy().hasHeightForWidth());
        VK->setSizePolicy(sizePolicy5);
        VK->setMinimumSize(QSize(35, 35));
        VK->setMaximumSize(QSize(35, 35));
        VK->setCursor(QCursor(Qt::PointingHandCursor));
        VK->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/VK.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(VK);

        Instagram = new QPushButton(Social);
        Instagram->setObjectName("Instagram");
        sizePolicy5.setHeightForWidth(Instagram->sizePolicy().hasHeightForWidth());
        Instagram->setSizePolicy(sizePolicy5);
        Instagram->setMinimumSize(QSize(35, 35));
        Instagram->setMaximumSize(QSize(35, 35));
        Instagram->setCursor(QCursor(Qt::PointingHandCursor));
        Instagram->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Instagram.png) 0 stretch stretch;"));

        Social_horizontalLayout->addWidget(Instagram);

        Whatsapp = new QPushButton(Social);
        Whatsapp->setObjectName("Whatsapp");
        sizePolicy5.setHeightForWidth(Whatsapp->sizePolicy().hasHeightForWidth());
        Whatsapp->setSizePolicy(sizePolicy5);
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
        sizePolicy4.setHeightForWidth(Header->sizePolicy().hasHeightForWidth());
        Header->setSizePolicy(sizePolicy4);
        Header->setMinimumSize(QSize(0, 90));
        Header->setMaximumSize(QSize(16777215, 90));
        Header->setStyleSheet(QString::fromUtf8("font: 700 45px;"));
        Header_horizontalLayout = new QHBoxLayout(Header);
        Header_horizontalLayout->setSpacing(0);
        Header_horizontalLayout->setObjectName("Header_horizontalLayout");
        Header_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Heading = new QLabel(Header);
        Heading->setObjectName("Heading");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Heading->sizePolicy().hasHeightForWidth());
        Heading->setSizePolicy(sizePolicy6);
        Heading->setAlignment(Qt::AlignCenter);
        Heading->setIndent(0);

        Header_horizontalLayout->addWidget(Heading);

        CartAccountBlock = new QWidget(Header);
        CartAccountBlock->setObjectName("CartAccountBlock");
        sizePolicy5.setHeightForWidth(CartAccountBlock->sizePolicy().hasHeightForWidth());
        CartAccountBlock->setSizePolicy(sizePolicy5);
        CartAccountBlock->setMinimumSize(QSize(140, 0));
        CartAccountBlock->setMaximumSize(QSize(140, 16777215));
        CartAccountBlock_horizontalLayout = new QHBoxLayout(CartAccountBlock);
        CartAccountBlock_horizontalLayout->setSpacing(15);
        CartAccountBlock_horizontalLayout->setObjectName("CartAccountBlock_horizontalLayout");
        CartAccountBlock_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Cart = new QPushButton(CartAccountBlock);
        Cart->setObjectName("Cart");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(Cart->sizePolicy().hasHeightForWidth());
        Cart->setSizePolicy(sizePolicy7);
        Cart->setMinimumSize(QSize(45, 45));
        Cart->setMaximumSize(QSize(45, 45));
        Cart->setCursor(QCursor(Qt::PointingHandCursor));
        Cart->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Cart.png) 0 stretch stretch;"));

        CartAccountBlock_horizontalLayout->addWidget(Cart);

        Account = new QPushButton(CartAccountBlock);
        Account->setObjectName("Account");
        sizePolicy7.setHeightForWidth(Account->sizePolicy().hasHeightForWidth());
        Account->setSizePolicy(sizePolicy7);
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
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(Header_line->sizePolicy().hasHeightForWidth());
        Header_line->setSizePolicy(sizePolicy8);
        Header_line->setMinimumSize(QSize(0, 4));
        Header_line->setMaximumSize(QSize(16777215, 4));
        Header_line->setFrameShadow(QFrame::Plain);
        Header_line->setLineWidth(4);
        Header_line->setFrameShape(QFrame::HLine);

        Content_verticalLayout->addWidget(Header_line);

        PageContent = new QWidget(Content);
        PageContent->setObjectName("PageContent");
        sizePolicy6.setHeightForWidth(PageContent->sizePolicy().hasHeightForWidth());
        PageContent->setSizePolicy(sizePolicy6);
        PageContent->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(PageContent);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_2 = new QWidget(PageContent);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy9);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_top_2 = new QLabel(widget_2);
        label_top_2->setObjectName("label_top_2");
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy10.setHorizontalStretch(50);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_top_2->sizePolicy().hasHeightForWidth());
        label_top_2->setSizePolicy(sizePolicy10);
        label_top_2->setMinimumSize(QSize(0, 50));
        label_top_2->setMaximumSize(QSize(16777215, 50));
        label_top_2->setBaseSize(QSize(0, 50));
        label_top_2->setStyleSheet(QString::fromUtf8("font: 700 26pt \"Segoe UI\";"));
        label_top_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_top_2);

        label_bottom_2 = new QLabel(widget_2);
        label_bottom_2->setObjectName("label_bottom_2");
        sizePolicy4.setHeightForWidth(label_bottom_2->sizePolicy().hasHeightForWidth());
        label_bottom_2->setSizePolicy(sizePolicy4);
        label_bottom_2->setMinimumSize(QSize(0, 50));
        label_bottom_2->setStyleSheet(QString::fromUtf8("font: 700 26pt \"Segoe UI\";"));
        label_bottom_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_bottom_2);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        QSizePolicy sizePolicy11(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy11.setHorizontalStretch(100);
        sizePolicy11.setVerticalStretch(105);
        sizePolicy11.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy11);
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        form_2 = new QWidget(widget_3);
        form_2->setObjectName("form_2");
        QSizePolicy sizePolicy12(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy12.setHorizontalStretch(100);
        sizePolicy12.setVerticalStretch(100);
        sizePolicy12.setHeightForWidth(form_2->sizePolicy().hasHeightForWidth());
        form_2->setSizePolicy(sizePolicy12);
        form_2->setMinimumSize(QSize(500, 400));
        form_2->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 176, 130);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;"));
        horizontalLayout_4 = new QHBoxLayout(form_2);
        horizontalLayout_4->setSpacing(22);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(15, 15, 15, 15);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName("verticalLayout_5");
        name_2 = new QLineEdit(form_2);
        name_2->setObjectName("name_2");
        QSizePolicy sizePolicy13(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(name_2->sizePolicy().hasHeightForWidth());
        name_2->setSizePolicy(sizePolicy13);
        name_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;\n"
""));

        verticalLayout_5->addWidget(name_2);

        number_2 = new QLineEdit(form_2);
        number_2->setObjectName("number_2");
        sizePolicy13.setHeightForWidth(number_2->sizePolicy().hasHeightForWidth());
        number_2->setSizePolicy(sizePolicy13);
        number_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;"));

        verticalLayout_5->addWidget(number_2);

        people_2 = new QLineEdit(form_2);
        people_2->setObjectName("people_2");
        sizePolicy13.setHeightForWidth(people_2->sizePolicy().hasHeightForWidth());
        people_2->setSizePolicy(sizePolicy13);
        people_2->setMinimumSize(QSize(20, 0));
        people_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;"));

        verticalLayout_5->addWidget(people_2);

        dateEdit_2 = new QDateEdit(form_2);
        dateEdit_2->setObjectName("dateEdit_2");
        sizePolicy13.setHeightForWidth(dateEdit_2->sizePolicy().hasHeightForWidth());
        dateEdit_2->setSizePolicy(sizePolicy13);
        dateEdit_2->setMinimumSize(QSize(150, 0));
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;"));

        verticalLayout_5->addWidget(dateEdit_2);

        ButtonBook_2 = new QPushButton(form_2);
        ButtonBook_2->setObjectName("ButtonBook_2");
        sizePolicy13.setHeightForWidth(ButtonBook_2->sizePolicy().hasHeightForWidth());
        ButtonBook_2->setSizePolicy(sizePolicy13);
        ButtonBook_2->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Segoe UI\";\n"
"background-color: rgb(217, 217, 217);\n"
"border-top-left-radius: 13px;\n"
"border-top-right-radius: 13px;\n"
"border-bottom-left-radius: 13px;\n"
"border-bottom-right-radius: 13px;"));

        verticalLayout_5->addWidget(ButtonBook_2);


        horizontalLayout_4->addLayout(verticalLayout_5);


        horizontalLayout_3->addWidget(form_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_4->addWidget(widget_3);


        verticalLayout->addLayout(verticalLayout_4);


        verticalLayout_2->addWidget(widget_2);


        Content_verticalLayout->addWidget(PageContent);


        Window_horizontalLayout->addWidget(Content);

        BookingWindow->setCentralWidget(Window);

        retranslateUi(BookingWindow);

        QMetaObject::connectSlotsByName(BookingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BookingWindow)
    {
        BookingWindow->setWindowTitle(QCoreApplication::translate("BookingWindow", "OurCafe", nullptr));
        MainLogo->setText(QString());
        MenuButton->setText(QCoreApplication::translate("BookingWindow", "Menu", nullptr));
        BookingButton->setStyleSheet(QCoreApplication::translate("BookingWindow", "QPushButton {\n"
"	\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:hover {\n"
"	color: #ffffff;\n"
"	background-color: #E59C59;\n"
"}", nullptr));
        BookingButton->setText(QCoreApplication::translate("BookingWindow", "Booking", nullptr));
        DeliveryButton->setText(QCoreApplication::translate("BookingWindow", "Delivery", nullptr));
        ContactsHeader->setText(QCoreApplication::translate("BookingWindow", "Contacts", nullptr));
        ContactsText->setText(QCoreApplication::translate("BookingWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Address:</span> 11 Kolotushkina St., Building 3, Moscow<br/><span style=\" font-weight:700;\">Metro station:</span> Pushkino<br/><span style=\" font-weight:700;\">Phone number:</span> +7-888-888-88-88<br/><span style=\" font-weight:700;\">Mail:</span> OurCafe@mail.ru</p></body></html>", nullptr));
        Telegram->setText(QString());
        VK->setText(QString());
        Instagram->setText(QString());
        Whatsapp->setText(QString());
        Heading->setText(QCoreApplication::translate("BookingWindow", "Booking", nullptr));
        Cart->setText(QString());
        Account->setText(QString());
        label_top_2->setText(QCoreApplication::translate("BookingWindow", "Book a table or an event.", nullptr));
        label_bottom_2->setText(QCoreApplication::translate("BookingWindow", "And we will take care of all the details.", nullptr));
        name_2->setText(QString());
        name_2->setPlaceholderText(QCoreApplication::translate("BookingWindow", "What is your name?", nullptr));
        number_2->setText(QString());
        number_2->setPlaceholderText(QCoreApplication::translate("BookingWindow", "+7(___)___ ___ ___", nullptr));
        people_2->setText(QString());
        people_2->setPlaceholderText(QCoreApplication::translate("BookingWindow", "Specify the number of people", nullptr));
        ButtonBook_2->setText(QCoreApplication::translate("BookingWindow", "To book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookingWindow: public Ui_BookingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGWINDOW_H
