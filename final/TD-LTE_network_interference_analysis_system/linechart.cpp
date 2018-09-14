#include "linechart.h"
#include "ui_linechart.h"

#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlRecord>
#include <QDebug>
#include <QMap>

LineChart::LineChart(QList<QString> t,QString str,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LineChart)
{
    ui->setupUi(this);

    for(int i=5;i<t.size();i++)
        ui->comboBox->addItem(t.at(i));
    name = str;

    image = QImage(1000,500,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

}

LineChart::~LineChart()
{
    delete ui;
}

void LineChart::on_pushButton_clicked()
{
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点
    int pointx=40,pointy=460;//确定坐标轴起点坐标，这里定义(35,280)
    int width=680-pointx,height=375;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定
    painter.drawRect(10,60,800-10,435-10);//外围的矩形
    painter.drawLine(pointx-5,pointy,width+pointx+10,pointy);//坐标轴x宽度为width
    painter.drawLine(pointx-5,pointy-height-5,pointx-5,pointy);//坐标轴y高度为height

    QString attr = ui->comboBox->currentText();
    QSqlQueryModel model;
    model.setQuery("SELECT 起始时间,["+ attr+"],小区  FROM tbKPI where 网元名称 = '" + name + "'");
    while(model.canFetchMore())
        model.fetchMore();
    QMap<QString,QPair<double,int>> map;
    QList<QString> order;
    int rows = model.rowCount();
    for(int i = 0;i < rows;i++){
        QString time = model.record(i).value("起始时间").toString();
        double val = model.record(i).value(attr).toDouble();
        if(!order.contains(time.split(" ")[0]))
            order.append(time.split(" ")[0]);
        if(map.find(time)==map.end()){
            map.insert(time,qMakePair(val,1));
        }
        else{
            map[time]=qMakePair(map.value(time).first+val,map.value(time).second+1);
        }
    }
    QMap<QString,double> data;
    QMap<QString,QPair<double,int>>::Iterator  it;
    int yMax = 1;
    for(it = map.begin();it != map.end();++it)
    {
        QString key = it.key().split(" ")[0];
        double var = it.value().first/it.value().second;
        if(var>yMax)
            yMax=var;
        data[key]=var;
    }
    //    QString startTime = ui->dateEdit->text().split(" ")[0];

    int xNum = data.size();
    double kx=(double)width/(xNum-1); //x轴的系数
    double ky=(double)height/yMax;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(1);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);

    QPen penMaxMin;//用于标注值的大小
    penMaxMin.setColor(Qt::darkGreen);//暗绿色

    int i=0;
    for(;i<xNum-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx+kx*i,pointy-data[order.at(i)]*ky,pointx+kx*(i+1),pointy-data[order.at(i+1)]*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx+kx*i,pointy-data[order.at(i)]*ky);

        painter.setPen(penMaxMin);
        painter.drawText(pointx+kx*i,pointy-data[order.at(i)]*ky,
                QString::number(data[order.at(i)]));
    }
    painter.setPen(penPoint);
    painter.drawPoint(pointx+kx*(xNum-1),pointy-data[order.at(xNum-1)]*ky);//绘制最后一个点
    painter.setPen(penMaxMin);
    painter.drawText(pointx+kx*i,pointy-data[order.at(i)]*ky,
            QString::number(data[order.at(i)]));

    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);
    //画上x轴刻度线
    for(int i=0;i<xNum;i++)//分成10份
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawLine(pointx+i*kx,pointy,pointx+i*kx,pointy+4);
        painter.drawText(pointx+i*kx,
                         pointy+10,order.at(i));
    }

    this->update();
}

void LineChart::on_pushButton_2_clicked()
{
    QString resultName = QFileDialog::getExistingDirectory(this);
    if(resultName.isEmpty())
        return;
    if(!resultName.endsWith(QString("/"))){
        resultName += "/";
    }
    QString attribute = ui->comboBox->currentText();
    resultName += name;

    QString start = ui->dateEdit->dateTime().toString("yyyy-MM-dd");
    QString end = ui->dateEdit_2->dateTime().toString("yyyy-MM-dd");
    resultName = resultName + "_" + attribute + "_from"+start+"_to"+end;

    image.save(resultName+".jpg","JPG");

    QMessageBox::information(0,"提示","保存成功！",QMessageBox::Ok);
}
