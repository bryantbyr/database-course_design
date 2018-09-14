#ifndef PRBCHART_H
#define PRBCHART_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QtGui>
#include <QString>

namespace Ui {
class prbChart;
}

class prbChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit prbChart(QList<QString> t,QString str,QWidget *parent = 0);
    ~prbChart();

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::prbChart *ui;
    QImage image;

    QString name;

};

#endif // PRBCHART_H
