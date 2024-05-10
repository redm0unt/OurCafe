/********************************************************************************
** Form generated from reading UI file 'entering_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERING_WINDOW_H
#define UI_ENTERING_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_entering_window
{
public:
    QWidget *Window;
    QHBoxLayout *horizontalLayout;
    QWidget *Photo;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QWidget *LoginForm;
    QVBoxLayout *verticalLayout;
    QSpacerItem *LoginForm_verticalSpacer;
    QLabel *Logo;
    QSpacerItem *verticalSpacer;
    QLabel *HeadingText;
    QSpacerItem *verticalSpacer_2;
    QLabel *HeadingSubtext;
    QSpacerItem *verticalSpacer_3;
    QLabel *EmailLabel;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *EmailInput;
    QSpacerItem *verticalSpacer_4;
    QLabel *PasswordLabel;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *PasswordInput;
    QSpacerItem *verticalSpacer_7;
    QPushButton *SingInButton;
    QSpacerItem *verticalSpacer_8;
    QPushButton *RegisterButton;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QMainWindow *entering_window)
    {
        if (entering_window->objectName().isEmpty())
            entering_window->setObjectName("entering_window");
        entering_window->resize(1088, 612);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(entering_window->sizePolicy().hasHeightForWidth());
        entering_window->setSizePolicy(sizePolicy);
        entering_window->setMinimumSize(QSize(1088, 612));
        entering_window->setMaximumSize(QSize(1088, 612));
        entering_window->setStyleSheet(QString::fromUtf8("background-color: #E7D8CB;\n"
"color: #000000;"));
        Window = new QWidget(entering_window);
        Window->setObjectName("Window");
        horizontalLayout = new QHBoxLayout(Window);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(30, 30, 0, 30);
        Photo = new QWidget(Window);
        Photo->setObjectName("Photo");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Photo->sizePolicy().hasHeightForWidth());
        Photo->setSizePolicy(sizePolicy1);
        Photo->setMinimumSize(QSize(0, 0));
        Photo->setMaximumSize(QSize(8000, 8000));
        Photo->setBaseSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(Photo);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Photo);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(380, 510));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/Welcome_photo.png) 0 stretch cover;"));

        horizontalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(Photo);

        LoginForm = new QWidget(Window);
        LoginForm->setObjectName("LoginForm");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LoginForm->sizePolicy().hasHeightForWidth());
        LoginForm->setSizePolicy(sizePolicy2);
        LoginForm->setMinimumSize(QSize(660, 0));
        LoginForm->setMaximumSize(QSize(660, 16777215));
        LoginForm->setBaseSize(QSize(0, 0));
        LoginForm->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoginForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(110, 0, 110, 0);
        LoginForm_verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(LoginForm_verticalSpacer);

        Logo = new QLabel(LoginForm);
        Logo->setObjectName("Logo");
        sizePolicy.setHeightForWidth(Logo->sizePolicy().hasHeightForWidth());
        Logo->setSizePolicy(sizePolicy);
        Logo->setMinimumSize(QSize(140, 140));
        Logo->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/resources/MainLogo.png) 0 stretch stretch;"));
        Logo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Logo, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 14, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        HeadingText = new QLabel(LoginForm);
        HeadingText->setObjectName("HeadingText");
        sizePolicy2.setHeightForWidth(HeadingText->sizePolicy().hasHeightForWidth());
        HeadingText->setSizePolicy(sizePolicy2);
        HeadingText->setStyleSheet(QString::fromUtf8("font: 800 38px;"));

        verticalLayout->addWidget(HeadingText, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        HeadingSubtext = new QLabel(LoginForm);
        HeadingSubtext->setObjectName("HeadingSubtext");
        HeadingSubtext->setStyleSheet(QString::fromUtf8("font: 200 14px;"));

        verticalLayout->addWidget(HeadingSubtext, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_3 = new QSpacerItem(20, 34, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        EmailLabel = new QLabel(LoginForm);
        EmailLabel->setObjectName("EmailLabel");
        EmailLabel->setStyleSheet(QString::fromUtf8("font: 400 17pt;"));

        verticalLayout->addWidget(EmailLabel);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        EmailInput = new QLineEdit(LoginForm);
        EmailInput->setObjectName("EmailInput");
        EmailInput->setMinimumSize(QSize(0, 40));
        EmailInput->setAutoFillBackground(false);
        EmailInput->setStyleSheet(QString::fromUtf8("font: 13px;\n"
"color: #000000;\n"
"\n"
"background-color: #F5F0EB;\n"
"border-radius: 13px;\n"
"padding: 0 13px;"));
        EmailInput->setInputMethodHints(Qt::ImhHiddenText);
        EmailInput->setCursorPosition(0);

        verticalLayout->addWidget(EmailInput);

        verticalSpacer_4 = new QSpacerItem(20, 34, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        PasswordLabel = new QLabel(LoginForm);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setStyleSheet(QString::fromUtf8("font: 400 17pt;"));

        verticalLayout->addWidget(PasswordLabel);

        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        PasswordInput = new QLineEdit(LoginForm);
        PasswordInput->setObjectName("PasswordInput");
        PasswordInput->setMinimumSize(QSize(0, 40));
        PasswordInput->setStyleSheet(QString::fromUtf8("font: 13px;\n"
"color: #000000;\n"
"\n"
"background-color: #F5F0EB;\n"
"border-radius: 13px;\n"
"padding: 0 13px;"));
        PasswordInput->setMaxLength(25);
        PasswordInput->setEchoMode(QLineEdit::Password);
        PasswordInput->setCursorPosition(0);

        verticalLayout->addWidget(PasswordInput);

        verticalSpacer_7 = new QSpacerItem(20, 21, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        SingInButton = new QPushButton(LoginForm);
        SingInButton->setObjectName("SingInButton");
        SingInButton->setMinimumSize(QSize(0, 47));
        SingInButton->setCursor(QCursor(Qt::PointingHandCursor));
        SingInButton->setStyleSheet(QString::fromUtf8("font: 700 18px;\n"
"color: #F5F0EB;\n"
"\n"
"background-color: #351A00;\n"
"border-radius: 13px;"));

        verticalLayout->addWidget(SingInButton);

        verticalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        RegisterButton = new QPushButton(LoginForm);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setCursor(QCursor(Qt::PointingHandCursor));
        RegisterButton->setStyleSheet(QString::fromUtf8("font: 500 13px;\n"
"border: none;"));

        verticalLayout->addWidget(RegisterButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);


        horizontalLayout->addWidget(LoginForm);

        entering_window->setCentralWidget(Window);

        retranslateUi(entering_window);

        QMetaObject::connectSlotsByName(entering_window);
    } // setupUi

    void retranslateUi(QMainWindow *entering_window)
    {
        entering_window->setWindowTitle(QCoreApplication::translate("entering_window", "Authorization", nullptr));
#if QT_CONFIG(tooltip)
        LoginForm->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        Logo->setText(QString());
        HeadingText->setText(QCoreApplication::translate("entering_window", "Welcome back", nullptr));
        HeadingSubtext->setText(QCoreApplication::translate("entering_window", "Enter your email and password to access your account", nullptr));
        EmailLabel->setText(QCoreApplication::translate("entering_window", "Email", nullptr));
#if QT_CONFIG(tooltip)
        EmailInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        EmailInput->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        EmailInput->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        EmailInput->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        EmailInput->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        EmailInput->setInputMask(QString());
        EmailInput->setText(QString());
        EmailInput->setPlaceholderText(QCoreApplication::translate("entering_window", "Enter your email", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("entering_window", "Password", nullptr));
        PasswordInput->setText(QString());
        PasswordInput->setPlaceholderText(QCoreApplication::translate("entering_window", "Enter your password", nullptr));
        SingInButton->setText(QCoreApplication::translate("entering_window", "Sign in", nullptr));
        RegisterButton->setText(QCoreApplication::translate("entering_window", "If you don't have an account, then hurry up and register!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class entering_window: public Ui_entering_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERING_WINDOW_H
