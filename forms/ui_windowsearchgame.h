/********************************************************************************
** Form generated from reading UI file 'windowsearchgame.ui'
**
** Created: Tue 5. Oct 23:04:55 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSEARCHGAME_H
#define UI_WINDOWSEARCHGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowSearchGame
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *gametrailers;
    QCheckBox *ign;
    QCheckBox *igromania;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lnSearchGame;
    QPushButton *pbSearchGame;

    void setupUi(QWidget *windowSearchGame)
    {
        if (windowSearchGame->objectName().isEmpty())
            windowSearchGame->setObjectName(QString::fromUtf8("windowSearchGame"));
        windowSearchGame->setWindowModality(Qt::WindowModal);
        windowSearchGame->resize(576, 148);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        windowSearchGame->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(windowSearchGame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(windowSearchGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        gametrailers = new QCheckBox(windowSearchGame);
        gametrailers->setObjectName(QString::fromUtf8("gametrailers"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        gametrailers->setFont(font1);

        verticalLayout->addWidget(gametrailers);

        ign = new QCheckBox(windowSearchGame);
        ign->setObjectName(QString::fromUtf8("ign"));
        ign->setFont(font1);

        verticalLayout->addWidget(ign);

        igromania = new QCheckBox(windowSearchGame);
        igromania->setObjectName(QString::fromUtf8("igromania"));
        igromania->setFont(font1);

        verticalLayout->addWidget(igromania);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lnSearchGame = new QLineEdit(windowSearchGame);
        lnSearchGame->setObjectName(QString::fromUtf8("lnSearchGame"));

        horizontalLayout->addWidget(lnSearchGame);

        pbSearchGame = new QPushButton(windowSearchGame);
        pbSearchGame->setObjectName(QString::fromUtf8("pbSearchGame"));

        horizontalLayout->addWidget(pbSearchGame);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(windowSearchGame);

        QMetaObject::connectSlotsByName(windowSearchGame);
    } // setupUi

    void retranslateUi(QWidget *windowSearchGame)
    {
        windowSearchGame->setWindowTitle(QApplication::translate("windowSearchGame", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \321\201\320\260\320\271\321\202\320\260\320\274", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("windowSearchGame", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\260\320\271\321\202(\321\213):", 0, QApplication::UnicodeUTF8));
        gametrailers->setText(QApplication::translate("windowSearchGame", "Gametrailers.com", 0, QApplication::UnicodeUTF8));
        ign->setText(QApplication::translate("windowSearchGame", "Ign.com", 0, QApplication::UnicodeUTF8));
        igromania->setText(QApplication::translate("windowSearchGame", "Igromania.ru", 0, QApplication::UnicodeUTF8));
        pbSearchGame->setText(QApplication::translate("windowSearchGame", "\320\230\321\201\320\272\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class windowSearchGame: public Ui_windowSearchGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSEARCHGAME_H
