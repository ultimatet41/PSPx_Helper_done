/********************************************************************************
** Form generated from reading UI file 'edittext.ui'
**
** Created: Thu 13. Jan 03:31:54 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTEXT_H
#define UI_EDITTEXT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editText
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *editText)
    {
        if (editText->objectName().isEmpty())
            editText->setObjectName(QString::fromUtf8("editText"));
        editText->resize(486, 443);
        verticalLayout = new QVBoxLayout(editText);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(editText);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        pushButton_2 = new QPushButton(editText);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(editText);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(editText);

        QMetaObject::connectSlotsByName(editText);
    } // setupUi

    void retranslateUi(QWidget *editText)
    {
        editText->setWindowTitle(QApplication::translate("editText", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("editText", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("editText", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class editText: public Ui_editText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTEXT_H
