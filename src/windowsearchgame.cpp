#include "windowsearchgame.h"
#include "ui_windowsearchgame.h"
#include <QDesktopServices>
#include <QUrl>

windowSearchGame::windowSearchGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowSearchGame)
{
    ui->setupUi(this);


    connect(ui->pbSearchGame,SIGNAL(clicked()),SLOT(finGame()));
    this->resize(700,150);
}

windowSearchGame::~windowSearchGame()
{
    delete ui;
}

void windowSearchGame::finGame()
{
    if(ui->gametrailers->isChecked()){

        QDesktopServices::openUrl(QUrl("http://www.gametrailers.com/search.php?s="+ui->lnSearchGame->text()));}

        if(ui->ign->isChecked())
            QDesktopServices::openUrl(QUrl("http://search.ign.com/product?query="+ui->lnSearchGame->text()));

        if (ui->igromania->isChecked())
            QDesktopServices::openUrl(QUrl("http://igromania.ru/search/?q="+ui->lnSearchGame->text()));
}

void windowSearchGame::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Escape)
        this->close();
}
