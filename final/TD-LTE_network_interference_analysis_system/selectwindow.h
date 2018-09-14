#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include "handler.h"

#include <QSqlQueryModel>
#include <QMainWindow>
#include <QTableView>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlRecord>
#include <QComboBox>
#include <QLineEdit>
#include <QSqlQuery>
#include <QLayout>
#include <QDialog>
#include <QString>
#include <QLabel>
#include <QDebug>
#include <QList>

class selectWindow : public QMainWindow
{
    Q_OBJECT

public:
    selectWindow(QList<QString> idList,QString name,Handler* h,QWidget *parent = NULL):QMainWindow(parent)
    {
        this->handler=h;
        this->name=name;

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);

        gridLayout->setMargin(10);

        QLabel *lbl_caption = new QLabel(name);
        cbo_sex = new QComboBox();
        cbo_sex->setEditable(true);

        for(int i=0;i<idList.size();i++){
            cbo_sex->addItem(idList[i]);
        }

        gridLayout->addWidget(lbl_caption, 0, 0);
        gridLayout->addWidget(cbo_sex, 0, 1);

        QHBoxLayout *bomLayout = new QHBoxLayout;
        QPushButton *btn = new QPushButton(QWidget::tr("search"));
        bomLayout->addStretch();
        bomLayout->addWidget(btn);
        bomLayout->addStretch();

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(gridLayout);
        mainLayout->addLayout(bomLayout);

        QWidget *mainWidget = new QWidget;
        mainWidget->setLayout(mainLayout);

        setCentralWidget(mainWidget);

        connect(btn, SIGNAL(clicked()), this, SLOT(on_click_sel()));
    }

private:
    QComboBox *cbo_sex;

    Handler *handler = NULL;
    QString name;

private slots:

    void on_click_sel()
    {

//        QSqlQuery query;
//        qDebug()<<"SELECT * FROM tbCell where SECTOR_ID = '" + cbo_sex->currentText() + "'";
//        if(!query.exec("SELECT * FROM tbCell where SECTOR_ID = '" + cbo_sex->currentText() + "'")){
//            qDebug()<<"query failed!";
//        }
//        while (query.next()) {
//            for(int i=0;i<query.record().count();i++)
//                qDebug()<<"query "<<i<<" : "<<query.value(i);
//        }

        if(QString::compare(this->name,QString("SECTOR_ID"))==0){
            handler->setMonitorSector(cbo_sex->currentText());
        }
        else if(QString::compare(this->name,QString("ENODEBID"))==0){
            handler->setMonitorENodeB(cbo_sex->currentText());
        }
        else if(QString::compare(this->name,QString("网元名称"))==0){
            handler->setMonitorKPI(cbo_sex->currentText());
        }else if(QString::compare(this->name,QString("网元名称:"))==0) {
            handler->setMonitorPRB(cbo_sex->currentText());
        }else if(QString::compare(this->name,QString("参数(10~9000):"))==0) {
            handler->setMonitorC2Inew(cbo_sex->currentText());
        }else if(QString::compare(this->name,QString("参数(1~100):"))==0) {
            handler->setMonitorC2I3(cbo_sex->currentText());
        }

        this->hide();
    }

};


#endif // SELECTWINDOW_H
