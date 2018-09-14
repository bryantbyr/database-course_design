/********************************************************************************
** Form generated from reading UI file 'sign_up.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_H
#define UI_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sign_up
{
public:
    QLineEdit *user_password;
    QPushButton *ok;
    QLineEdit *user_name;
    QPushButton *cancel;

    void setupUi(QDialog *sign_up)
    {
        if (sign_up->objectName().isEmpty())
            sign_up->setObjectName(QStringLiteral("sign_up"));
        sign_up->resize(381, 300);
        user_password = new QLineEdit(sign_up);
        user_password->setObjectName(QStringLiteral("user_password"));
        user_password->setGeometry(QRect(90, 140, 200, 35));
        user_password->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px;padding:2px 4px"));
        user_password->setEchoMode(QLineEdit::Password);
        ok = new QPushButton(sign_up);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(90, 210, 85, 30));
        ok->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px"));
        user_name = new QLineEdit(sign_up);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(90, 70, 200, 35));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setBold(false);
        font.setWeight(50);
        user_name->setFont(font);
        user_name->setAutoFillBackground(false);
        user_name->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px;padding:2px 4px"));
        user_name->setDragEnabled(false);
        cancel = new QPushButton(sign_up);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(205, 210, 85, 30));
        cancel->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:8px"));

        retranslateUi(sign_up);

        QMetaObject::connectSlotsByName(sign_up);
    } // setupUi

    void retranslateUi(QDialog *sign_up)
    {
        sign_up->setWindowTitle(QApplication::translate("sign_up", "Dialog", Q_NULLPTR));
        user_password->setInputMask(QString());
        user_password->setText(QString());
        user_password->setPlaceholderText(QApplication::translate("sign_up", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        ok->setText(QApplication::translate("sign_up", "\347\241\256\345\256\232", Q_NULLPTR));
        user_name->setInputMask(QString());
        user_name->setText(QString());
        user_name->setPlaceholderText(QApplication::translate("sign_up", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        cancel->setText(QApplication::translate("sign_up", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sign_up: public Ui_sign_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_H
