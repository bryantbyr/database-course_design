#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sign_up.h"
#include "handler.h"

#include <QMessageBox>
#include <QFile>
#include <QCryptographicHash>
#include <QTextStream>
#include <QDebug>

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
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(ui->user_password->text().toLatin1());
    QByteArray result = hash.result();  // 返回最终的哈希值
    QString strMD5 = result.toHex();
    QString answer;
    QFile file("D:\\user.csv");
    int flag=0;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,"","文件不存在",QMessageBox::Ok);
    }else{
        QTextStream textStream(&file);
        textStream.readLine();

        //读数据
        QStringList list;
        list.clear();
        while(!textStream.atEnd()){
            QString fileLine = textStream.readLine();
            list = fileLine.split(",", QString::SkipEmptyParts);
            if (ui->user_name->text()==list.at(0)){
                answer=list.at(1);
                flag=1;
            }
        }
    }

    file.close();
    if(flag==0){
        QMessageBox::warning(0,"警告","该用户未注册！",QMessageBox::Ok);
        return;
    }
    if(strMD5!=answer){
        QMessageBox::warning(0,"警告","用户密码错误！",QMessageBox::Ok);
        return;
    }

    Handler* h = new Handler();
    h->setWindowTitle(QString("welcome,"+ui->user_name->text()+"!"));
    this->hide();
    h->show();

}

