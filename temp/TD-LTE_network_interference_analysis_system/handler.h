#ifndef HANDLER_H
#define HANDLER_H

#include <QMainWindow>

#include <QSqlQueryModel>
#include <QSqlDatabase>

namespace Ui {
class Handler;
}

class Handler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Handler(QWidget *parent = 0);
    ~Handler();

    void convertToColName(int data, QString &res);
    void setMonitorSector(QString str);
    void setMonitorENodeB(QString str);
    void setMonitorKPI(QString str);
    void setMonitorPRB(QString str);
    void setMonitorC2Inew(QString str);
    void setMonitorC2I3(QString str);



private slots:
    void insertCSVData();
    void inserttbCellExcelData();
    void insertKPIExcelData();
    void insertPRBExcelData();
    void exportData();
    void srearchSector();
    void srearchENodeB();
    void srearchKPI();
    void exporttbPRNnew();
    void searchtbPRBnew();
    void searchTriple();
    void analiseC2I();

private:
    Ui::Handler *ui;

    QSqlDatabase db;


};

#endif // HANDLER_H



