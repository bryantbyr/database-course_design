#include "sign_up.h"
#include "ui_sign_up.h"

#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
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

    QString username = ui->user_name->text();
    QString password = ui->user_password->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = QString::fromLocal8Bit("TD-LTE-Users");      //数据源名称
    db.setHostName("127.0.0.1");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
    }
    else{
        qDebug()<<"TD-LTE-Users database is connected successfully!";
    }

    QSqlQueryModel model;
    model.setQuery("select * from tbUsers where username='"+username+"'");
    if(model.rowCount()>0){
        QMessageBox::warning(0,"警告","该用户已注册！",QMessageBox::Ok);
        db.close();
        return;
    }
    model.setQuery("insert into tbUsers  values('"+username+"','"+password+"')");

    QMessageBox::information(0,"恭喜","注册成功！",QMessageBox::Ok);
    db.close();
    this->accept();
}
