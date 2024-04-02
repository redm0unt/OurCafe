#include "entering_window.h"
#include "ui_entering_window.h"


entering_window::entering_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::entering_window)
{
    ui->setupUi(this);
    ui->EmailInput->setPlaceholderText("Enter your email");
    ui->PasswordInput->setPlaceholderText("Enter your password");
}

entering_window::~entering_window()
{
    delete ui;
}
