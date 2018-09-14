/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *user_name;
    QLineEdit *user_password;
    QPushButton *signin;
    QPushButton *sign_up;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(381, 300);
        MainWindow->setMinimumSize(QSize(381, 300));
        MainWindow->setMaximumSize(QSize(381, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        user_name = new QLineEdit(centralWidget);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(90, 40, 200, 35));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setBold(false);
        font.setWeight(50);
        user_name->setFont(font);
        user_name->setAutoFillBackground(false);
        user_name->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px;padding:2px 4px"));
        user_name->setDragEnabled(false);
        user_password = new QLineEdit(centralWidget);
        user_password->setObjectName(QStringLiteral("user_password"));
        user_password->setGeometry(QRect(90, 110, 200, 35));
        user_password->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px;padding:2px 4px"));
        user_password->setEchoMode(QLineEdit::Password);
        signin = new QPushButton(centralWidget);
        signin->setObjectName(QStringLiteral("signin"));
        signin->setGeometry(QRect(90, 180, 85, 30));
        signin->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px"));
        sign_up = new QPushButton(centralWidget);
        sign_up->setObjectName(QStringLiteral("sign_up"));
        sign_up->setGeometry(QRect(205, 180, 85, 30));
        sign_up->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 381, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        user_name->setInputMask(QString());
        user_name->setText(QString());
        user_name->setPlaceholderText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        user_password->setInputMask(QString());
        user_password->setText(QString());
        user_password->setPlaceholderText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        signin->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", Q_NULLPTR));
        sign_up->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
