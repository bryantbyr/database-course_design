#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sign_up.h"
#include "handler.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sign_up_clicked()
{
    sign_up w;
    w.setWindowTitle(QString("register"));
    w.exec();

}

void MainWindow::on_signin_clicked()
{
    //检查用户名和密码
    if(ui->user_name->text().isEmpty()){
        QMessageBox::warning(0,"警告","用户名不能为空！",QMessageBox::Ok);
        return;
    }
    if(ui->user_password->text().isEmpty()){
        QMessageBox::warning(0,"警告","密码不能为空！",QMessageBox::Ok);
        return;
    }
//    if(ui->user_name->text() is not existed){
//        QMessageBox::warning(0,"警告","该用户未注册！",QMessageBox::Ok);
//        return;
//    }
//    if(ui->user_password->text()!=answer){
//        QMessageBox::warning(0,"警告","用户密码错误！",QMessageBox::Ok);
//        return;
//    }

    Handler* h = new Handler();
    h->setWindowTitle(QString("welcome,Qi!"));
    h->show();

}
