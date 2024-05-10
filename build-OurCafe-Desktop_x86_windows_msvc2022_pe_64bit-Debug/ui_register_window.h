/********************************************************************************
** Form generated from reading UI file 'register_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_WINDOW_H
#define UI_REGISTER_WINDOW_H

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

class Ui_register_window
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
    QLabel *HeadingText;
    QSpacerItem *verticalSpacer_2;
    QLabel *HeadingSubtext;
    QSpacerItem *verticalSpacer_3;
    QLabel *NameLabel;
    QSpacerItem *verticalSpacer_12;
    QLineEdit *NameInput;
    QSpacerItem *verticalSpacer_5;
    QLabel *EmailLabel;
    QLineEdit *EmailInput;
    QSpacerItem *verticalSpacer_13;
    QLabel *PhoneNumberLabel;
    QSpacerItem *verticalSpacer_14;
    QLineEdit *PhoneNumberInput;
    QSpacerItem *verticalSpacer_4;
    QLabel *PasswordLabel;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *PasswordInput;
    QSpacerItem *verticalSpacer_10;
    QLineEdit *RepeatPasswordInput;
    QSpacerItem *verticalSpacer_7;
    QPushButton *SingUpButton;
    QSpacerItem *verticalSpacer_8;
    QPushButton *AuthorizationButton;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QMainWindow *register_window)
    {
        if (register_window->objectName().isEmpty())
            register_window->setObjectName("register_window");
        register_window->resize(1088, 612);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(register_window->sizePolicy().hasHeightForWidth());
        register_window->setSizePolicy(sizePolicy);
        register_window->setMinimumSize(QSize(1088, 612));
        register_window->setMaximumSize(QSize(1088, 612));
        register_window->setStyleSheet(QString::fromUtf8("background-color: #E7D8CB;\n"
"color: #000000;"));
        Window = new QWidget(register_window);
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

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        NameLabel = new QLabel(LoginForm);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setStyleSheet(QString::fromUtf8("font: 400 17pt;"));

        verticalLayout->addWidget(NameLabel);

        verticalSpacer_12 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_12);

        NameInput = new QLineEdit(LoginForm);
        NameInput->setObjectName("NameInput");
        NameInput->setMinimumSize(QSize(0, 40));
        NameInput->setAutoFillBackground(false);
        NameInput->setStyleSheet(QString::fromUtf8("font: 13px;\n"
"color: #000000;\n"
"\n"
"background-color: #F5F0EB;\n"
"border-radius: 13px;\n"
"padding: 0 13px;"));
        NameInput->setInputMethodHints(Qt::ImhHiddenText);
        NameInput->setCursorPosition(0);

        verticalLayout->addWidget(NameInput);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        EmailLabel = new QLabel(LoginForm);
        EmailLabel->setObjectName("EmailLabel");
        EmailLabel->setStyleSheet(QString::fromUtf8("font: 400 17pt;"));

        verticalLayout->addWidget(EmailLabel);

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

        verticalSpacer_13 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_13);

        PhoneNumberLabel = new QLabel(LoginForm);
        PhoneNumberLabel->setObjectName("PhoneNumberLabel");
        PhoneNumberLabel->setStyleSheet(QString::fromUtf8("font: 400 17pt;"));

        verticalLayout->addWidget(PhoneNumberLabel);

        verticalSpacer_14 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_14);

        PhoneNumberInput = new QLineEdit(LoginForm);
        PhoneNumberInput->setObjectName("PhoneNumberInput");
        PhoneNumberInput->setMinimumSize(QSize(0, 40));
        PhoneNumberInput->setAutoFillBackground(false);
        PhoneNumberInput->setStyleSheet(QString::fromUtf8("font: 13px;\n"
"color: #000000;\n"
"\n"
"background-color: #F5F0EB;\n"
"border-radius: 13px;\n"
"padding: 0 13px;"));
        PhoneNumberInput->setInputMethodHints(Qt::ImhHiddenText);
        PhoneNumberInput->setCursorPosition(0);

        verticalLayout->addWidget(PhoneNumberInput);

        verticalSpacer_4 = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

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

        verticalSpacer_10 = new QSpacerItem(20, 7, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_10);

        RepeatPasswordInput = new QLineEdit(LoginForm);
        RepeatPasswordInput->setObjectName("RepeatPasswordInput");
        RepeatPasswordInput->setMinimumSize(QSize(0, 40));
        RepeatPasswordInput->setStyleSheet(QString::fromUtf8("font: 13px;\n"
"color: #000000;\n"
"\n"
"background-color: #F5F0EB;\n"
"border-radius: 13px;\n"
"padding: 0 13px;"));
        RepeatPasswordInput->setMaxLength(25);
        RepeatPasswordInput->setEchoMode(QLineEdit::Password);
        RepeatPasswordInput->setCursorPosition(0);

        verticalLayout->addWidget(RepeatPasswordInput);

        verticalSpacer_7 = new QSpacerItem(20, 21, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        SingUpButton = new QPushButton(LoginForm);
        SingUpButton->setObjectName("SingUpButton");
        SingUpButton->setMinimumSize(QSize(0, 47));
        SingUpButton->setCursor(QCursor(Qt::PointingHandCursor));
        SingUpButton->setStyleSheet(QString::fromUtf8("font: 700 18px;\n"
"color: #F5F0EB;\n"
"\n"
"background-color: #351A00;\n"
"border-radius: 13px;"));

        verticalLayout->addWidget(SingUpButton);

        verticalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        AuthorizationButton = new QPushButton(LoginForm);
        AuthorizationButton->setObjectName("AuthorizationButton");
        AuthorizationButton->setCursor(QCursor(Qt::PointingHandCursor));
        AuthorizationButton->setStyleSheet(QString::fromUtf8("font: 500 13px;\n"
"border: none;"));

        verticalLayout->addWidget(AuthorizationButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);


        horizontalLayout->addWidget(LoginForm);

        register_window->setCentralWidget(Window);

        retranslateUi(register_window);

        QMetaObject::connectSlotsByName(register_window);
    } // setupUi

    void retranslateUi(QMainWindow *register_window)
    {
        register_window->setWindowTitle(QCoreApplication::translate("register_window", "Registration", nullptr));
#if QT_CONFIG(tooltip)
        LoginForm->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        HeadingText->setText(QCoreApplication::translate("register_window", "Registration", nullptr));
        HeadingSubtext->setText(QCoreApplication::translate("register_window", "Fill in all fields below", nullptr));
        NameLabel->setText(QCoreApplication::translate("register_window", "Name", nullptr));
#if QT_CONFIG(tooltip)
        NameInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        NameInput->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        NameInput->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        NameInput->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        NameInput->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        NameInput->setInputMask(QString());
        NameInput->setText(QString());
        NameInput->setPlaceholderText(QCoreApplication::translate("register_window", "Enter your name", nullptr));
        EmailLabel->setText(QCoreApplication::translate("register_window", "Email", nullptr));
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
        EmailInput->setPlaceholderText(QCoreApplication::translate("register_window", "Enter your email", nullptr));
        PhoneNumberLabel->setText(QCoreApplication::translate("register_window", "Phone number", nullptr));
#if QT_CONFIG(tooltip)
        PhoneNumberInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        PhoneNumberInput->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        PhoneNumberInput->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        PhoneNumberInput->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        PhoneNumberInput->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        PhoneNumberInput->setInputMask(QString());
        PhoneNumberInput->setText(QString());
        PhoneNumberInput->setPlaceholderText(QCoreApplication::translate("register_window", "Enter your phone number", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("register_window", "Password", nullptr));
        PasswordInput->setText(QString());
        PasswordInput->setPlaceholderText(QCoreApplication::translate("register_window", "Enter your password", nullptr));
        RepeatPasswordInput->setText(QString());
        RepeatPasswordInput->setPlaceholderText(QCoreApplication::translate("register_window", "Repeat your password", nullptr));
        SingUpButton->setText(QCoreApplication::translate("register_window", "Sign up", nullptr));
        AuthorizationButton->setText(QCoreApplication::translate("register_window", "Remember you have an account. Return to login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_window: public Ui_register_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WINDOW_H
