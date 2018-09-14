#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QtGui>
#include <QString>

namespace Ui {
class LineChart;
}

class LineChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineChart(QList<QString> t,QString str,QWidget *parent = 0);
    ~LineChart();

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LineChart *ui;
    QImage image;

    QString name;
};

#endif // LINECHART_H
