#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/login.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();


    ui->label_pic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test") {
       QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
       // ui->statusbar->showMessage("username and password are correct");
    }
    else {
      //QMessageBox::warning(this, "Login", "Username and password are not correct");
        ui->statusbar->showMessage("username and password are not correct", 5000);

    }
}
