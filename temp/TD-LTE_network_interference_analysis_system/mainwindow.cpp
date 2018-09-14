#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sign_up.h"
#include "handler.h"

#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
//    QString dsn = QString::fromLocal8Bit("TD-LTE-Users");      //数据源名称
//    db.setHostName("127.0.0.1");
//    db.setDatabaseName(dsn);
//    if(!db.open()){
//        qDebug()<<db.lastError().text();
//        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
//    }
//    else{
//        qDebug()<<"TD-LTE-Users database is connected successfully!";
//    }
}

MainWindow::~MainWindow()
{
    delete ui;

    QString name = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(name);

    qDebug()<<"! ~MainWindow() !";

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
    //    if(ui->user_name->text().isEmpty()){
    //        QMessageBox::warning(0,"警告","用户名不能为空！",QMessageBox::Ok);
    //        return;
    //    }
    //    if(ui->user_password->text().isEmpty()){
    //        QMessageBox::warning(0,"警告","密码不能为空！",QMessageBox::Ok);
    //        return;
    //    }

    //    QString username = ui->user_name->text();
    //    QString password = ui->user_password->text();

    //    QSqlQueryModel model;
    //    qDebug()<<"select * from tbUsers where username='"+username+"'";
    //    model.setQuery("select * from tbUsers where username='"+username+"'");
    //    if(model.rowCount()==0){
    //        QMessageBox::warning(0,"警告","该用户未注册！",QMessageBox::Ok);
    //        return;
    //    }
    //    if(QString::compare(password,model.record(0).value("userpassword").toString())!=0){
    //        QMessageBox::warning(0,"警告","用户密码错误！",QMessageBox::Ok);
    //        return;
    //    }
    //    QMessageBox::information(0,"提示","登陆成功！",QMessageBox::Ok);


    //    QString name;
    //    name = db.connectionName();
    //    db.close();
    //    db = QSqlDatabase();
    //    db.removeDatabase(name);
    //    qDebug()<<"---------";


    Handler* h = new Handler();
    h->setWindowTitle(QString("welcome,Qi!"));
    this->hide();
    h->show();

}


