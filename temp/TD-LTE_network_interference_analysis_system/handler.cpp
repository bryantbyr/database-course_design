#include "handler.h"
#include "ui_handler.h"
#include "selectwindow.h"
#include "linechart.h"
#include "prbchart.h"

#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QAxObject>
#include <QDateEdit>
#include <QDebug>
#include <QFile>

Handler::Handler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Handler)
{
    ui->setupUi(this);

    connect(ui->actionMRO,SIGNAL(triggered()),this,SLOT(insertCSVData()));
    connect(ui->actiontbCell,SIGNAL(triggered()),this,SLOT(inserttbCellExcelData()));
    connect(ui->actionKPI,SIGNAL(triggered()),this,SLOT(insertKPIExcelData()));
    connect(ui->actionPRB,SIGNAL(triggered()),this,SLOT(insertPRBExcelData()));

    connect(ui->exporttbCell,SIGNAL(triggered()),this,SLOT(exportData()));
    connect(ui->exporttbKPI,SIGNAL(triggered()),this,SLOT(exportData()));
    connect(ui->exporttbMROData,SIGNAL(triggered()),this,SLOT(exportData()));

    connect(ui->sectorSearch,SIGNAL(triggered()),this,SLOT(srearchSector()));
    connect(ui->eNodeBSearch,SIGNAL(triggered()),this,SLOT(srearchENodeB()));
    connect(ui->KPISearch,SIGNAL(triggered()),this,SLOT(srearchKPI()));
    connect(ui->exporttbPRNnew,SIGNAL(triggered()),this,SLOT(exporttbPRNnew()));
    connect(ui->searchtbPRBnew,SIGNAL(triggered()),this,SLOT(searchtbPRBnew()));
    connect(ui->tripleSearch,SIGNAL(triggered()),this,SLOT(searchTriple()));

    connect(ui->action_C2I,SIGNAL(triggered()),this,SLOT(analiseC2I()));


    db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = QString::fromLocal8Bit("TD-LTE-Users");      //数据源名称
    db.setHostName("127.0.0.1");
    db.setDatabaseName(dsn);
    db.setUserName("tdlte_user");
    db.setPassword("tdlte");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
    }
    else
    {
        qDebug()<<"TD-LTE database is connected successfully!!!!";
    }

}

Handler::~Handler()
{
    delete ui;

    db.close();
}

void Handler::insertCSVData()
{    
    QFileDialog* fd = new QFileDialog(this); //创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.csv)"));
    if(fileName == "")
        return;
    QDir dir = QDir::current();
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"OPEN FILE FAILED";
    QTextStream in(&file);  //QTextStream读取数据
    in.readLine();


    //批量插入数据
    QSqlQuery query;
    QStringList list;
    list.clear();
    while(!in.atEnd())
    {

        QVariantList TimeStamp;
        QVariantList ServingSector;
        QVariantList InterferingSector;
        QVariantList LteScRSRP;
        QVariantList LteNcRSRP;
        QVariantList LteNcEarfcn;
        QVariantList LteNcPci;

        for(int i=0;!in.atEnd()&&i<50;i++){
            QString fileLine = in.readLine();
            list = fileLine.split(",", QString::SkipEmptyParts);

            if(list.size()>6){
                TimeStamp = TimeStamp << list.at(0);
                ServingSector = ServingSector << list.at(1);
                InterferingSector = InterferingSector << list.at(2);
                LteScRSRP = LteScRSRP << list.at(3);
                LteNcRSRP = LteNcRSRP << list.at(4);
                LteNcEarfcn = LteNcEarfcn << list.at(5);
                LteNcPci = LteNcPci << list.at(6);
            }

        }

        query.prepare("INSERT INTO tbMROData (TimeStamp, ServingSector,InterferingSector,LteScRSRP,LteNcRSRP,LteNcEarfcn,LteNcPci) VALUES (?,?,?,?,?,?,?)"); //准备执行SQL查询
        query.addBindValue(TimeStamp);
        query.addBindValue(ServingSector);
        query.addBindValue(InterferingSector);
        query.addBindValue(LteScRSRP);
        query.addBindValue(LteNcRSRP);
        query.addBindValue(LteNcEarfcn);
        query.addBindValue(LteNcPci);

        if (!query.execBatch())
            qDebug() << query.lastError();
        else{
            qDebug()<<"csv导入中......";
        }
    }
    qDebug()<<"csv导入完成！";
    query.clear();

    
}

void Handler::inserttbCellExcelData()
{
    QFileDialog* fd = new QFileDialog(this); //创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.xlsx)"));
    if(fileName == "")
        return;

    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", fileName); //打开文件
    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); //访问第一个工作表
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    QAxObject * rows = usedrange->querySubObject("Rows");
    int intRows = rows->property("Count").toInt(); //行数

    QString Range = "A1:S" +QString::number(intRows);
    QAxObject *allEnvData = worksheet->querySubObject("Range(QString)", Range); //读取范围
    QVariant allEnvDataQVariant = allEnvData->property("Value");
    QVariantList allEnvDataList = allEnvDataQVariant.toList();

    QSqlQuery query;
    QVariantList CITY;
    QVariantList SECTOR_ID;
    QVariantList SECTOR_NAME;
    QVariantList ENODEBID;
    QVariantList ENODEB_NAME;
    QVariantList EARFCN;
    QVariantList PCI;
    QVariantList PSS;
    QVariantList SSS;
    QVariantList TAC;
    QVariantList VENDOR;
    QVariantList LONGITUDE;
    QVariantList LATITUDE;
    QVariantList STYLE;
    QVariantList AZIMUTH;
    QVariantList HEIGHT;
    QVariantList ELECTTILT;
    QVariantList MECHTILT;
    QVariantList TOTLETILT;
    for(int i=1; i< intRows; i++)
    {
        QVariantList allEnvDataList_i =  allEnvDataList[i].toList() ;
        if(allEnvDataList_i.size()>18){
            bool ok;
            allEnvDataList_i[15].toString().toFloat(&ok);
            if(ok==true){
                CITY = CITY << allEnvDataList_i[0].toString();
                SECTOR_ID = SECTOR_ID << allEnvDataList_i[1].toString();
                SECTOR_NAME = SECTOR_NAME << allEnvDataList_i[2].toString();
                ENODEBID = ENODEBID << allEnvDataList_i[3].toString();
                ENODEB_NAME = ENODEB_NAME << allEnvDataList_i[4].toString();
                EARFCN = EARFCN << allEnvDataList_i[5].toString();
                PCI = PCI << allEnvDataList_i[6].toString();
                PSS = PSS << allEnvDataList_i[7].toString();
                SSS = SSS << allEnvDataList_i[8].toString();
                TAC = TAC << allEnvDataList_i[9].toString();
                VENDOR = VENDOR << allEnvDataList_i[10].toString();
                LONGITUDE = LONGITUDE << allEnvDataList_i[11].toString();
                LATITUDE = LATITUDE << allEnvDataList_i[12].toString();
                STYLE = STYLE << allEnvDataList_i[13].toString();
                AZIMUTH = AZIMUTH << allEnvDataList_i[14].toString();
                HEIGHT = HEIGHT << allEnvDataList_i[15].toString();
                ELECTTILT = ELECTTILT << allEnvDataList_i[16].toString();
                MECHTILT = MECHTILT << allEnvDataList_i[17].toString();
                TOTLETILT = TOTLETILT << allEnvDataList_i[18].toString();
            }
        }

        if(i%50==0||i==intRows-1){
            query.prepare("INSERT INTO tbCell (CITY,SECTOR_ID,SECTOR_NAME,ENODEBID,ENODEB_NAME,EARFCN,PCI,PSS,SSS,TAC,VENDOR,LONGITUDE,LATITUDE,STYLE,AZIMUTH,HEIGHT,ELECTTILT,MECHTILT,TOTLETILT) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"); //准备执行SQL查询
            query.addBindValue(CITY);
            query.addBindValue(SECTOR_ID);
            query.addBindValue(SECTOR_NAME);
            query.addBindValue(ENODEBID);
            query.addBindValue(ENODEB_NAME);
            query.addBindValue(EARFCN);
            query.addBindValue(PCI);
            query.addBindValue(PSS);
            query.addBindValue(SSS);
            query.addBindValue(TAC);
            query.addBindValue(VENDOR);
            query.addBindValue(LONGITUDE);
            query.addBindValue(LATITUDE);
            query.addBindValue(STYLE);
            query.addBindValue(AZIMUTH);
            query.addBindValue(HEIGHT);
            query.addBindValue(ELECTTILT);
            query.addBindValue(MECHTILT);
            query.addBindValue(TOTLETILT);

            if (!query.execBatch())
                qDebug() <<"导入Error:"<< query.lastError()<<"!"<<i;
            else{
                qDebug()<<"excel导入中......";
            }

            CITY.clear();
            SECTOR_ID.clear();
            SECTOR_NAME.clear();
            ENODEBID.clear();
            ENODEB_NAME.clear();
            EARFCN.clear();
            PCI.clear();
            PSS.clear();
            SSS.clear();
            TAC.clear();
            VENDOR.clear();
            LONGITUDE.clear();
            LATITUDE.clear();
            STYLE.clear();
            AZIMUTH.clear();
            HEIGHT.clear();
            ELECTTILT.clear();
            MECHTILT.clear();
            TOTLETILT.clear();
        }
    }

    qDebug()<<"excel导入完成！";

    workbooks->dynamicCall("Close()");
    excel.dynamicCall("Quit()");
    query.clear();
}

void Handler::insertKPIExcelData()
{
    QFileDialog* fd = new QFileDialog(this); //创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.xlsx)"));
    if(fileName == "")
        return;

    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", fileName); //打开文件
    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); //访问第一个工作表
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    QAxObject * rows = usedrange->querySubObject("Rows");
    int intRows = rows->property("Count").toInt(); //行数

    QString Range = "A1:AP" +QString::number(intRows);
    QAxObject *allEnvData = worksheet->querySubObject("Range(QString)", Range); //读取范围
    QVariant allEnvDataQVariant = allEnvData->property("Value");
    QVariantList allEnvDataList = allEnvDataQVariant.toList();

    QSqlQuery query;
    QVariantList startTime;
    QVariantList cycle;
    QVariantList wangyaun;
    QVariantList ENODEB;
    QVariantList sector;
    QVariantList RRCconnect;
    QVariantList RRCrequest;
    QVariantList RRCconnectRate;
    QVariantList E_RABconnect;
    QVariantList E_RABrequest;
    QVariantList E_RABconnectRate;
    QVariantList eNode_E_RAB;
    QVariantList handover_E_RAB;
    QVariantList E_RAB_lossRate;
    QVariantList wirelessRate;
    QVariantList eNodeB_Context_Realease;
    QVariantList UE_Context_Realease;
    QVariantList UE_Context_connect;
    QVariantList S;
    QVariantList T;
    QVariantList U;
    QVariantList V;
    QVariantList W;
    QVariantList X;
    QVariantList Y;
    QVariantList Z;
    QVariantList AA;
    QVariantList AB;
    QVariantList AC;
    QVariantList AD;
    QVariantList AE;
    QVariantList AF;
    QVariantList AG;
    QVariantList AH;
    QVariantList AI;
    QVariantList AJ;
    QVariantList AK;
    QVariantList AL;
    QVariantList AM;
    QVariantList AN;
    QVariantList AO;
    QVariantList AP;
    for(int i=1; i< intRows; i++)
    {
        QVariantList allEnvDataList_i =  allEnvDataList[i].toList() ;
        if(allEnvDataList_i.size()>41){
            bool isValid = true;
            for(int j=5;j<42;j++){
                bool ok;
                allEnvDataList_i[j].toString().toFloat(&ok);
                if(ok==false)
                    isValid = false;
            }
            if(isValid){
                startTime = startTime << allEnvDataList_i[0].toString();
                cycle = cycle << allEnvDataList_i[1].toString();
                wangyaun = wangyaun << allEnvDataList_i[2].toString();
                ENODEB = ENODEB << allEnvDataList_i[3].toString();
                sector = sector << allEnvDataList_i[4].toString();
                RRCconnect = RRCconnect << allEnvDataList_i[5].toString();
                RRCrequest = RRCrequest << allEnvDataList_i[6].toString();
                RRCconnectRate = RRCconnectRate << allEnvDataList_i[7].toString();
                E_RABconnect = E_RABconnect << allEnvDataList_i[8].toString();
                E_RABrequest = E_RABrequest << allEnvDataList_i[9].toString();
                E_RABconnectRate = E_RABconnectRate << allEnvDataList_i[10].toString();
                eNode_E_RAB = eNode_E_RAB << allEnvDataList_i[11].toString();
                handover_E_RAB = handover_E_RAB << allEnvDataList_i[12].toString();
                E_RAB_lossRate = E_RAB_lossRate << allEnvDataList_i[13].toString();
                wirelessRate = wirelessRate << allEnvDataList_i[14].toString();
                eNodeB_Context_Realease = eNodeB_Context_Realease << allEnvDataList_i[15].toString();
                UE_Context_Realease = UE_Context_Realease << allEnvDataList_i[16].toString();
                UE_Context_connect = UE_Context_connect << allEnvDataList_i[17].toString();
                S = S << allEnvDataList_i[18].toString();
                T = T << allEnvDataList_i[19].toString();
                U = U << allEnvDataList_i[20].toString();
                V = V << allEnvDataList_i[21].toString();
                W = W << allEnvDataList_i[22].toString();
                X = X << allEnvDataList_i[23].toString();
                Y = Y << allEnvDataList_i[24].toString();
                Z = Z << allEnvDataList_i[25].toString();
                AA = AA << allEnvDataList_i[26].toString();
                AB = AB << allEnvDataList_i[27].toString();
                AC = AC << allEnvDataList_i[28].toString();
                AD = AD << allEnvDataList_i[29].toString();
                AE = AE << allEnvDataList_i[30].toString();
                AF = AF << allEnvDataList_i[31].toString();
                AG = AG << allEnvDataList_i[32].toString();
                AH = AH << allEnvDataList_i[33].toString();
                AI = AI << allEnvDataList_i[34].toString();
                AJ = AJ << allEnvDataList_i[35].toString();
                AK = AK << allEnvDataList_i[36].toString();
                AL = AL << allEnvDataList_i[37].toString();
                AM = AM << allEnvDataList_i[38].toString();
                AN = AN << allEnvDataList_i[39].toString();
                AO = AO << allEnvDataList_i[40].toString();
                AP = AP << allEnvDataList_i[41].toString();
            }

        }

        if(i%50==0||i==intRows-1){
            query.prepare("INSERT INTO tbKPI (起始时间,周期,网元名称,基站,小区,[RRC连接建立完成次数 (无)],[RRC连接请求次数（包括重发） (无)],[RRC建立成功率qf (%)],[E-RAB建立成功总次数 (无)],[E-RAB建立尝试总次数 (无)],[E-RAB建立成功率2 (%)],[eNodeB触发的E-RAB异常释放总次数 (无)],[小区切换出E-RAB异常释放总次数 (无)],[E-RAB掉线率(新) (%)],[无线接通率ay (%)],[eNodeB发起的S1 RESET导致的UE Context释放次数 (无)],[UE Context异常释放次数 (无)],[UE Context建立成功总次数 (无)],[无线掉线率 (%)],[eNodeB内异频切换出成功次数 (无)],[eNodeB内异频切换出尝试次数 (无)],[eNodeB内同频切换出成功次数 (无)],[eNodeB内同频切换出尝试次数 (无)],[eNodeB间异频切换出成功次数 (无)],[eNodeB间异频切换出尝试次数 (无)],[eNodeB间同频切换出成功次数 (无)],[eNodeB间同频切换出尝试次数 (无)],[eNB内切换成功率 (%)],[eNB间切换成功率 (%)],[同频切换成功率zsp (%)],[异频切换成功率zsp (%)],[切换成功率 (%)],[小区PDCP层所接收到的上行数据的总吞吐量 (比特)],[小区PDCP层所发送的下行数据的总吞吐量 (比特)],[RRC重建请求次数 (无)],[RRC连接重建比率 (%)],[通过重建回源小区的eNodeB间同频切换出执行成功次数 (无)],[通过重建回源小区的eNodeB间异频切换出执行成功次数 (无)],[通过重建回源小区的eNodeB内同频切换出执行成功次数 (无)],[通过重建回源小区的eNodeB内异频切换出执行成功次数 (无)],[eNB内切换出成功次数 (次)],[eNB内切换出请求次数 (次)]) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"); //准备执行SQL查询
            query.addBindValue(startTime);
            query.addBindValue(cycle);
            query.addBindValue(wangyaun);
            query.addBindValue(ENODEB);
            query.addBindValue(sector);
            query.addBindValue(RRCconnect);
            query.addBindValue(RRCrequest);
            query.addBindValue(RRCconnectRate);
            query.addBindValue(E_RABconnect);
            query.addBindValue(E_RABrequest);
            query.addBindValue(E_RABconnectRate);
            query.addBindValue(eNode_E_RAB);
            query.addBindValue(handover_E_RAB);
            query.addBindValue(E_RAB_lossRate);
            query.addBindValue(wirelessRate);
            query.addBindValue(eNodeB_Context_Realease);
            query.addBindValue(UE_Context_Realease);
            query.addBindValue(UE_Context_connect);
            query.addBindValue(S);
            query.addBindValue(T);
            query.addBindValue(U);
            query.addBindValue(V);
            query.addBindValue(W);
            query.addBindValue(X);
            query.addBindValue(Y);
            query.addBindValue(Z);
            query.addBindValue(AA);
            query.addBindValue(AB);
            query.addBindValue(AC);
            query.addBindValue(AD);
            query.addBindValue(AE);
            query.addBindValue(AF);
            query.addBindValue(AG);
            query.addBindValue(AH);
            query.addBindValue(AI);
            query.addBindValue(AJ);
            query.addBindValue(AK);
            query.addBindValue(AL);
            query.addBindValue(AM);
            query.addBindValue(AN);
            query.addBindValue(AO);
            query.addBindValue(AP);

            if (!query.execBatch())
                qDebug() <<"导入Error:"<< query.lastError()<<"!"<<i;
            else{
                qDebug()<<"excel导入中......";
            }

            startTime.clear();
            cycle.clear();
            wangyaun.clear();
            ENODEB.clear();
            sector.clear();
            RRCconnect.clear();
            RRCrequest.clear();
            RRCconnectRate.clear();
            E_RABconnect.clear();
            E_RABrequest.clear();
            E_RABconnectRate.clear();
            eNode_E_RAB.clear();
            handover_E_RAB.clear();
            E_RAB_lossRate.clear();
            wirelessRate.clear();
            eNodeB_Context_Realease.clear();
            UE_Context_Realease.clear();
            UE_Context_connect.clear();
            S.clear();
            T.clear();
            U.clear();
            V.clear();
            W.clear();
            X.clear();
            Y.clear();
            Z.clear();
            AA.clear();
            AB.clear();
            AC.clear();
            AD.clear();
            AE.clear();
            AF.clear();
            AG.clear();
            AH.clear();
            AI.clear();
            AG.clear();
            AK.clear();
            AL.clear();
            AM.clear();
            AN.clear();
            AO.clear();
            AP.clear();
        }
    }

    qDebug()<<"excel导入完成！";

    workbooks->dynamicCall("Close()");
    excel.dynamicCall("Quit()");
    query.clear();
}

void Handler::insertPRBExcelData()
{
    QFileDialog* fd = new QFileDialog(this); //创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.xlsx)"));
    if(fileName == "")
        return;

    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", fileName); //打开文件
    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); //访问第一个工作表
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    QAxObject * rows = usedrange->querySubObject("Rows");
    int intRows = rows->property("Count").toInt(); //行数

    //    QString Range = "A1:DA" +QString::number(90000);
    //    qDebug()<<"Range: "<< Range;
    //    QAxObject *allEnvData = worksheet->querySubObject("Range(QString)", Range); //读取范围

    QVariantList params;
    params << "A"+QString::number(1) << "DA"+QString::number(1);  //A1至A5的数据
    QAxObject *allEnvData = worksheet->querySubObject("Range(QVariant,QVariant)",params);

    QVariant allEnvDataQVariant = allEnvData->property("Value");
    QVariantList allEnvDataList = allEnvDataQVariant.toList();

    QVariantList allEnvDataList_1 = allEnvDataList[0].toList();
    QString sSql;
    sSql = QString("INSERT INTO tbPRB ");
    sSql += "(";
    for(int k=0;k<104;k++){
        sSql += "["+allEnvDataList_1[k].toString()+"]"+",";
    }
    sSql += "["+allEnvDataList_1[104].toString()+"]";
    sSql += ") VALUES (";
    for(int k=0;k<104;k++){
        sSql += "?,";
    }
    sSql += "?";
    sSql += ")";

    qDebug()<<"sSql: "<< sSql;

    QSqlQuery query;

    QList<QVariantList> list= {};
    for(int k=0;k<105;k++){
        QVariantList l;
        list.append(l);
    }

    for(int i=2; i< intRows+1; i++)
    {
        QVariantList params;
        params << "A"+QString::number(i) << "DA"+QString::number(i);
        QAxObject *allEnvData = worksheet->querySubObject("Range(QVariant,QVariant)",params);
        QVariant allEnvDataQVariant = allEnvData->property("Value");
        QVariantList allEnvDataList = allEnvDataQVariant.toList();
        QVariantList allEnvDataList_i = allEnvDataList[0].toList();

        if(allEnvDataList_i.size()>104){
            for(int m = 0;m < 105;m++){
                list[m] = list[m] << allEnvDataList_i[m].toString();
            }
        }

        if(i%50==0||i==intRows){
            query.prepare(sSql); //准备执行SQL查询

            for(int m = 0;m < 105;m++){
                query.addBindValue(list[m]);
            }

            if (!query.execBatch())
                qDebug() <<"导入Error:"<< query.lastError()<<"!"<<i;
            else{
                qDebug()<<"excel导入中......";
            }

            for(int m = 0;m < 105;m++){
                list[m].clear();
            }
        }
    }

    qDebug()<<"excel导入完成！";

    workbooks->dynamicCall("Close()");
    excel.dynamicCall("Quit()");
    query.clear();
}

void Handler::exportData(){
    QString table;
    if(qobject_cast<QAction*>(this->sender())==ui->exporttbCell)
        table = "tbCell";
    else if(qobject_cast<QAction*>(this->sender())==ui->exporttbKPI)
        table = "tbKPI";
    else
        table = "tbMROData";

    //创建excel
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
    QAxObject *work_books = excel.querySubObject("WorkBooks");

    QString fileName = QFileDialog::getExistingDirectory(this);
    if(fileName.isEmpty())
        return;

    if(!fileName.endsWith(QString("/"))){
        fileName += "/";
    }

    fileName += table;
    fileName += "_export.xlsx";
    QFile xlsFile(fileName);

    QAxObject* work_book = NULL;
    if (xlsFile.exists()) {
        work_book = work_books->querySubObject("Open(const QString &)", fileName);
    }
    else {
        work_books->dynamicCall("Add");
        work_book = excel.querySubObject("ActiveWorkBook");
    }

    //写excel
    QAxObject *work_sheets = work_book->querySubObject("Sheets");
    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);

    QSqlQueryModel model;
    QString sSql = QString("SELECT * FROM ");
    sSql += table;
    model.setQuery(sSql);
    while(model.canFetchMore())
        model.fetchMore();
    int rows = model.rowCount();
    int columns = model.columnCount();

    QVariantList vars;
    QList<QVariant> t;
    QSqlRecord head = model.record(0);
    for(int n = 0;n < columns;n++)
        t.append(head.fieldName(n));
    vars.append(QVariant(t));
    for (int i = 0; i < rows; ++i) {
        t.clear();
        for(int n = 0;n < columns;n++)
            t.append(model.record(i).value(head.fieldName(n)));
        vars.append(QVariant(t));
        if(i==0){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(2);
            rangStr = "A"+QString::number(1)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
        else if(i==rows-1){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(i+2);
            int s = vars.size();
            rangStr = "A"+QString::number(i+2-s+1)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
        else if(i%1000==0){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(i+2);
            rangStr = "A"+QString::number(i-1000+3)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
    }

    //保存excel
    qDebug()<<"fileName"<<fileName;
    QString strPath = fileName;
    strPath = strPath.replace('/','\\');
    qDebug()<<"strPath"<<strPath;
    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(strPath)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    qDebug()<<table+"导出完成!";

}

/// \brief 把列数转换为excel的字母列号
/// \param data 大于0的数
/// \return 字母列号，如1->A 26->Z 27 AA
void Handler::convertToColName(int data, QString &res)
{
    Q_ASSERT(data>0 && data<65535);
    int tempData = data / 26;
    if(tempData > 0)
    {
        int mode = data % 26;
        convertToColName(mode,res);
        convertToColName(tempData,res);
    }
    else
    {
        res=(QString(QChar(data+0x40))+res);
    }
}

void Handler::srearchSector(){
    QList<QString> idList;
    QSqlQuery query;
    query.exec("SELECT SECTOR_ID FROM tbCell");
    while (query.next()) {
        QString id = query.value(0).toString();
        idList.append(id);
    }

    selectWindow *mainWindow = new selectWindow(idList,QString("SECTOR_ID"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("selectSector"));
    mainWindow->show();
}

void Handler::srearchENodeB(){
    QList<QString> idList;
    QSqlQuery query;
    query.exec("SELECT ENODEBID FROM tbCell");
    while (query.next()) {
        QString id = query.value(0).toString();
        idList.append(id);
    }

    selectWindow *mainWindow = new selectWindow(idList,QString("ENODEBID"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("selectSector"));
    mainWindow->show();

}

void Handler::srearchKPI(){
    QList<QString> idList;
    QSqlQuery query;
    query.exec("SELECT 网元名称 FROM tbKPI");
    while (query.next()) {
        QString id = query.value(0).toString();
        idList.append(id);
    }

    selectWindow *mainWindow = new selectWindow(idList,QString("网元名称"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("selectSector"));
    mainWindow->show();

}

void Handler::exporttbPRNnew(){

    //    QSqlQuery query;
    //    query.prepare("exec PRB1");
    //    query.exec();
    //    while (query.next()) {
    //        for(int i=0;i<query.record().count();i++)
    //            qDebug()<<"query "<<i<<" : "<<query.value(i);
    //    }
    //    qDebug()<<"EXEC PRB1 completed!";


    //创建excel
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
    QAxObject *work_books = excel.querySubObject("WorkBooks");

    QString fileName = QFileDialog::getExistingDirectory(this);
    if(fileName.isEmpty())
        return;

    if(!fileName.endsWith(QString("/"))){
        fileName += "/";
    }

    fileName += "tbPRBnew";
    fileName += "_export.xlsx";
    QFile xlsFile(fileName);

    QAxObject* work_book = NULL;
    if (xlsFile.exists()) {
        work_book = work_books->querySubObject("Open(const QString &)", fileName);
    }
    else {
        work_books->dynamicCall("Add");
        work_book = excel.querySubObject("ActiveWorkBook");
    }

    //写excel
    QAxObject *work_sheets = work_book->querySubObject("Sheets");
    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);

    //        QSqlQueryModel *model = new QSqlQueryModel;
    //        model->setQuery("exec PRB1");
    //        ui->monitoirView->setModel(model);

    //        qDebug()<<"rows"<<model.rowCount();
    //        qDebug()<<"EXEC PRB1 completed!";

    QSqlQueryModel model;
    //        model.setQuery("exec PRB1");
    //        qDebug()<<"EXEC PRB1 completed!";

    QString sSql = QString("SELECT * FROM tbPRBnew");
    model.setQuery(sSql);
    while(model.canFetchMore())
        model.fetchMore();
    int rows = model.rowCount();
    int columns = model.columnCount();

    QVariantList vars;
    QList<QVariant> t;
    QSqlRecord head = model.record(0);
    for(int n = 0;n < columns;n++)
        t.append(head.fieldName(n));
    vars.append(QVariant(t));
    for (int i = 0; i < rows; ++i) {
        t.clear();
        for(int n = 0;n < columns;n++)
            t.append(model.record(i).value(head.fieldName(n)));
        vars.append(QVariant(t));
        if(i==0){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(2);
            rangStr = "A"+QString::number(1)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
        else if(i==rows-1){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(i+2);
            int s = vars.size();
            rangStr = "A"+QString::number(i+2-s+1)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
        else if(i%1000==0){
            QVariant var = QVariant(vars);
            QString rangStr;
            convertToColName(columns,rangStr);
            rangStr += QString::number(i+2);
            rangStr = "A"+QString::number(i-1000+3)+":" + rangStr;
            qDebug()<<rangStr;
            QAxObject *range = first_sheet->querySubObject("Range(const QString&)",rangStr);
            range->setProperty("Value", var);
            vars.clear();
        }
    }

    //保存excel
    qDebug()<<"fileName"<<fileName;
    QString strPath = fileName;
    strPath = strPath.replace('/','\\');
    qDebug()<<"strPath"<<strPath;
    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(strPath)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    qDebug()<<"tbPRBnew 导出完成!";
}

void Handler::searchtbPRBnew(){
    QList<QString> idList;
    QSqlQuery query;
    query.exec("SELECT 网元名称 FROM tbPRBnew");
    while (query.next()) {
        QString id = query.value(0).toString();
        idList.append(id);
    }

    selectWindow *mainWindow = new selectWindow(idList,QString("网元名称:"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("selectSector"));
    mainWindow->show();

}


void Handler::setMonitorSector(QString str){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM tbCell where SECTOR_ID = '" + str + "'");
    ui->monitoirView->setModel(model);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->monitoirView->setRowHeight(i, 30);
    }
}

void Handler::setMonitorENodeB(QString str){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT SECTOR_ID FROM tbCell where ENODEBID = '" + str + "'");
    ui->monitoirView->setModel(model);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->monitoirView->setRowHeight(i, 30);
    }
}

void Handler::setMonitorKPI(QString str){

    QSqlQueryModel model;
    model.setQuery("SELECT * FROM tbKPI where 网元名称 = '" + str + "'");
    int columns = model.columnCount();

    QList<QString> t;
    QSqlRecord head = model.record(0);
    for(int n = 0;n < columns;n++)
        t.append(head.fieldName(n));
    LineChart* linechart = new LineChart(t,str);
    linechart->setWindowTitle(QString("query"));
    linechart->show();
}

void Handler::setMonitorPRB(QString str){

    QSqlQueryModel model;
    model.setQuery("SELECT * FROM tbPRBnew where 网元名称 = '" + str + "'");
    int columns = model.columnCount();

    QList<QString> t;
    QSqlRecord head = model.record(0);
    for(int n = 0;n < columns;n++)
        t.append(head.fieldName(n));
    prbChart* linechart = new prbChart(t,str);
    linechart->setWindowTitle(QString("query"));
    linechart->show();

}


void Handler::analiseC2I(){

    QList<QString> idList;
    int i = 10;
    while (i<=9000) {
        idList.append(QString::number(i));
        i+=1;
    }
    selectWindow *mainWindow = new selectWindow(idList,QString("参数(10~9000):"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("select"));
    mainWindow->show();

}

void Handler::setMonitorC2Inew(QString str){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("exec c2i '"+str+"'");

    db.close();
    db.open();

    model->setQuery("select * from tbC2Inew");
    while(model->canFetchMore())
        model->fetchMore();

    ui->monitoirView->setModel(model);
    int row_count = model->rowCount();
    qDebug()<<"rows:"<<row_count;

    for(int i =0; i < row_count; i++)
    {
        ui->monitoirView->setRowHeight(i, 30);
    }

}


void Handler::searchTriple(){
    QList<QString> idList;
    idList.append(QString::number(50));
    int i = 1;
    while (i<=99) {
        if(i!=50)
            idList.append(QString::number(i));
        i+=1;
    }
    selectWindow *mainWindow = new selectWindow(idList,QString("参数(1~100):"),this);
    mainWindow->resize(200, 100);
    mainWindow->setWindowTitle(QWidget::tr("select"));
    mainWindow->show();

}

void Handler::setMonitorC2I3(QString str){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("exec C2I2 '"+str+"'");

    db.close();
    db.open();

    model->setQuery("select * from tbC2I3");
    while(model->canFetchMore())
        model->fetchMore();

    ui->monitoirView->setModel(model);
    int row_count = model->rowCount();
    qDebug()<<"rows:"<<row_count;

    for(int i =0; i < row_count; i++)
    {
        ui->monitoirView->setRowHeight(i, 30);
    }

}
