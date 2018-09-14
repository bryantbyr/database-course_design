#include "sign_up.h"
#include "ui_sign_up.h"
#include <QMessageBox>
#include <QFile>
#include <QCryptographicHash>
#include <QTextStream>
#include <QDebug>

sign_up::sign_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::on_cancel_clicked()
{
    this->close();
}

void sign_up::on_ok_clicked()
{

    if(ui->user_name->text().isEmpty()){
        QMessageBox::warning(0,"警告","用户名不能为空！",QMessageBox::Ok);
        return;
    }
    if(ui->user_password->text().isEmpty()){
        QMessageBox::warning(0,"警告","密码不能为空！",QMessageBox::Ok);
        return;
    }
    QFile file("D:\\user.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,"","文件不存在",QMessageBox::Ok);
    }else{
        QTextStream textStream(&file);
        textStream.readLine();

        //读数据
        QStringList list;
        list.clear();
        while(!textStream.atEnd()){
            qDebug()<<1;
            QString fileLine = textStream.readLine();
            list = fileLine.split(",", QString::SkipEmptyParts);
            if (ui->user_name->text()==list.at(0)){
                QMessageBox::warning(0,"警告","用户已注册",QMessageBox::Ok);
                return;
            }
            list.clear();
        }
    }
    file.close();

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)){
        QMessageBox::information(this,"","无生成盘符，应生成在C:/20171114.csv",QMessageBox::Ok);
    }else{
        QTextStream textStream(&file);

        //写数据
        QString nameStr=ui->user_name->text();
        QString PWDStr;
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(ui->user_password->text().toLatin1());
        QByteArray result = hash.result();  // 返回最终的哈希值
        PWDStr = result.toHex();
        textStream << nameStr <<','<<PWDStr<<'\n';
        qDebug()<<nameStr<<PWDStr;
        nameStr.clear();
        PWDStr.clear();
    }
    file.close();
    this->close();
    QMessageBox::information(0,"恭喜","注册成功！",QMessageBox::Ok);
    this->accept();
}
