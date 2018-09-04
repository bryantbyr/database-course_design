#include "sign_up.h"
#include "ui_sign_up.h"
#include <QMessageBox>

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
    QMessageBox::information(0,"恭喜","注册成功！",QMessageBox::Ok);
    this->accept();
}
