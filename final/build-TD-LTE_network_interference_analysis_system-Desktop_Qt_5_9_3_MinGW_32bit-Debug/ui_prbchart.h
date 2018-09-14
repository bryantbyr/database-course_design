/********************************************************************************
** Form generated from reading UI file 'prbchart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRBCHART_H
#define UI_PRBCHART_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prbChart
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *startdateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateTimeEdit *enddateTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *prbChart)
    {
        if (prbChart->objectName().isEmpty())
            prbChart->setObjectName(QStringLiteral("prbChart"));
        prbChart->resize(800, 500);
        centralwidget = new QWidget(prbChart);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 403, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        startdateTimeEdit = new QDateTimeEdit(centralwidget);
        startdateTimeEdit->setObjectName(QStringLiteral("startdateTimeEdit"));
        startdateTimeEdit->setDate(QDate(2016, 7, 17));
        startdateTimeEdit->setTime(QTime(1, 0, 0));

        horizontalLayout->addWidget(startdateTimeEdit);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        enddateTimeEdit = new QDateTimeEdit(centralwidget);
        enddateTimeEdit->setObjectName(QStringLiteral("enddateTimeEdit"));
        enddateTimeEdit->setDate(QDate(2016, 7, 17));
        enddateTimeEdit->setTime(QTime(13, 0, 0));

        horizontalLayout_2->addWidget(enddateTimeEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);

        horizontalLayout_3->addWidget(comboBox);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        prbChart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(prbChart);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        prbChart->setMenuBar(menubar);
        statusbar = new QStatusBar(prbChart);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        prbChart->setStatusBar(statusbar);

        retranslateUi(prbChart);

        QMetaObject::connectSlotsByName(prbChart);
    } // setupUi

    void retranslateUi(QMainWindow *prbChart)
    {
        prbChart->setWindowTitle(QApplication::translate("prbChart", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("prbChart", "\350\265\267\345\247\213\346\227\266\351\227\264:", Q_NULLPTR));
        label_2->setText(QApplication::translate("prbChart", "\346\210\252\346\255\242\346\227\266\351\227\264:", Q_NULLPTR));
        label_3->setText(QApplication::translate("prbChart", "\345\261\236\346\200\247:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("prbChart", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("prbChart", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prbChart: public Ui_prbChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRBCHART_H
