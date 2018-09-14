/********************************************************************************
** Form generated from reading UI file 'handler.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLER_H
#define UI_HANDLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Handler
{
public:
    QAction *actiontbCell;
    QAction *actionKPI;
    QAction *actionPRB;
    QAction *actionMRO;
    QAction *exporttbCell;
    QAction *exporttbKPI;
    QAction *exporttbMROData;
    QAction *sectorSearch;
    QAction *eNodeBSearch;
    QAction *KPISearch;
    QAction *exporttbPRNnew;
    QAction *searchtbPRBnew;
    QAction *action_C2I;
    QAction *tripleSearch;
    QAction *exportResult;
    QAction *group;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *monitoirView;
    QProgressBar *bar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuexcel;
    QMenu *menucsv;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menuPRB;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Handler)
    {
        if (Handler->objectName().isEmpty())
            Handler->setObjectName(QStringLiteral("Handler"));
        Handler->resize(894, 655);
        actiontbCell = new QAction(Handler);
        actiontbCell->setObjectName(QStringLiteral("actiontbCell"));
        actionKPI = new QAction(Handler);
        actionKPI->setObjectName(QStringLiteral("actionKPI"));
        actionPRB = new QAction(Handler);
        actionPRB->setObjectName(QStringLiteral("actionPRB"));
        actionMRO = new QAction(Handler);
        actionMRO->setObjectName(QStringLiteral("actionMRO"));
        exporttbCell = new QAction(Handler);
        exporttbCell->setObjectName(QStringLiteral("exporttbCell"));
        exporttbKPI = new QAction(Handler);
        exporttbKPI->setObjectName(QStringLiteral("exporttbKPI"));
        exporttbMROData = new QAction(Handler);
        exporttbMROData->setObjectName(QStringLiteral("exporttbMROData"));
        sectorSearch = new QAction(Handler);
        sectorSearch->setObjectName(QStringLiteral("sectorSearch"));
        eNodeBSearch = new QAction(Handler);
        eNodeBSearch->setObjectName(QStringLiteral("eNodeBSearch"));
        KPISearch = new QAction(Handler);
        KPISearch->setObjectName(QStringLiteral("KPISearch"));
        exporttbPRNnew = new QAction(Handler);
        exporttbPRNnew->setObjectName(QStringLiteral("exporttbPRNnew"));
        searchtbPRBnew = new QAction(Handler);
        searchtbPRBnew->setObjectName(QStringLiteral("searchtbPRBnew"));
        action_C2I = new QAction(Handler);
        action_C2I->setObjectName(QStringLiteral("action_C2I"));
        tripleSearch = new QAction(Handler);
        tripleSearch->setObjectName(QStringLiteral("tripleSearch"));
        exportResult = new QAction(Handler);
        exportResult->setObjectName(QStringLiteral("exportResult"));
        group = new QAction(Handler);
        group->setObjectName(QStringLiteral("group"));
        centralwidget = new QWidget(Handler);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        monitoirView = new QTableView(centralwidget);
        monitoirView->setObjectName(QStringLiteral("monitoirView"));

        verticalLayout->addWidget(monitoirView);

        bar = new QProgressBar(centralwidget);
        bar->setObjectName(QStringLiteral("bar"));
        bar->setValue(24);

        verticalLayout->addWidget(bar);


        verticalLayout_2->addLayout(verticalLayout);

        Handler->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Handler);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 894, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menuexcel = new QMenu(menu);
        menuexcel->setObjectName(QStringLiteral("menuexcel"));
        menucsv = new QMenu(menu);
        menucsv->setObjectName(QStringLiteral("menucsv"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menuPRB = new QMenu(menu_3);
        menuPRB->setObjectName(QStringLiteral("menuPRB"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        Handler->setMenuBar(menubar);
        statusbar = new QStatusBar(Handler);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Handler->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(menuexcel->menuAction());
        menu->addSeparator();
        menu->addAction(menucsv->menuAction());
        menu->addSeparator();
        menu->addAction(group);
        menuexcel->addAction(actiontbCell);
        menuexcel->addAction(actionKPI);
        menuexcel->addAction(actionPRB);
        menucsv->addAction(actionMRO);
        menu_2->addAction(exporttbCell);
        menu_2->addAction(exporttbKPI);
        menu_2->addAction(exporttbMROData);
        menu_2->addSeparator();
        menu_2->addAction(exportResult);
        menu_3->addAction(sectorSearch);
        menu_3->addSeparator();
        menu_3->addAction(eNodeBSearch);
        menu_3->addSeparator();
        menu_3->addAction(KPISearch);
        menu_3->addSeparator();
        menu_3->addAction(menuPRB->menuAction());
        menu_3->addSeparator();
        menu_3->addAction(tripleSearch);
        menuPRB->addAction(exporttbPRNnew);
        menuPRB->addAction(searchtbPRBnew);
        menu_4->addAction(action_C2I);

        retranslateUi(Handler);

        QMetaObject::connectSlotsByName(Handler);
    } // setupUi

    void retranslateUi(QMainWindow *Handler)
    {
        Handler->setWindowTitle(QApplication::translate("Handler", "MainWindow", Q_NULLPTR));
        actiontbCell->setText(QApplication::translate("Handler", "\347\275\221\347\273\234\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        actionKPI->setText(QApplication::translate("Handler", "KPI\346\214\207\346\240\207\344\277\241\346\201\257", Q_NULLPTR));
        actionPRB->setText(QApplication::translate("Handler", "PRB\345\271\262\346\211\260\344\277\241\346\201\257", Q_NULLPTR));
        actionMRO->setText(QApplication::translate("Handler", "MRO\346\225\260\346\215\256", Q_NULLPTR));
        exporttbCell->setText(QApplication::translate("Handler", "tbCell", Q_NULLPTR));
        exporttbKPI->setText(QApplication::translate("Handler", "tbKPI", Q_NULLPTR));
        exporttbMROData->setText(QApplication::translate("Handler", "tbMROData", Q_NULLPTR));
        sectorSearch->setText(QApplication::translate("Handler", "\345\260\217\345\214\272\351\205\215\347\275\256\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        eNodeBSearch->setText(QApplication::translate("Handler", "\345\237\272\347\253\231eNodeB\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        KPISearch->setText(QApplication::translate("Handler", "KPI\346\214\207\346\240\207\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        exporttbPRNnew->setText(QApplication::translate("Handler", "\345\257\274\345\207\272tbPRBnew", Q_NULLPTR));
        searchtbPRBnew->setText(QApplication::translate("Handler", "tbPRBnew\346\237\245\350\257\242", Q_NULLPTR));
        action_C2I->setText(QApplication::translate("Handler", "\344\270\273\351\202\273\345\260\217\345\214\272C2I\345\271\262\346\211\260\345\210\206\346\236\220", Q_NULLPTR));
        tripleSearch->setText(QApplication::translate("Handler", "\346\237\245\350\257\242\351\207\215\345\217\240\350\246\206\347\233\226\345\271\262\346\211\260\344\270\211\345\205\203\347\273\204", Q_NULLPTR));
        exportResult->setText(QApplication::translate("Handler", "\346\237\245\350\257\242\347\273\223\346\236\234\345\257\274\345\207\272", Q_NULLPTR));
        group->setText(QApplication::translate("Handler", "\346\226\207\344\273\266\345\210\206\347\273\204", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Handler", "\346\225\260\346\215\256\345\257\274\345\205\245", Q_NULLPTR));
        menuexcel->setTitle(QApplication::translate("Handler", "excel\346\240\274\345\274\217", Q_NULLPTR));
        menucsv->setTitle(QApplication::translate("Handler", "csv\346\240\274\345\274\217", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("Handler", "\346\225\260\346\215\256\345\257\274\345\207\272", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("Handler", "\346\237\245\350\257\242", Q_NULLPTR));
        menuPRB->setTitle(QApplication::translate("Handler", "PRB\344\277\241\346\201\257\347\273\237\350\256\241\344\270\216\346\237\245\350\257\242", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("Handler", "\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Handler: public Ui_Handler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLER_H
