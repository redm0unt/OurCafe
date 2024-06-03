#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "backendclient.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow(){
    delete ui;
}



void AdminWindow::on_SingInButton_clicked()
{
    QMessageBox message_box;
    if (ui->login->text() == "")
        message_box.setInformativeText(QString("Field is empty"));
    else{
        if (BackendClient::admin_delete_user(ui->login->text()))
            message_box.setInformativeText(QString("user successfully deleted"));
        else message_box.setInformativeText(QString("error deliting user"));
    }
    message_box.exec();
}

