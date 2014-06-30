#include "helperx.h"
#include "ui_helperx.h"
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QtWebKit/QWebPage>


HelperX::HelperX(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelperX)
{
    ui->setupUi(this);

    serachGm=new windowSearchGame;
    serachGm->setWindowModality(Qt::ApplicationModal);

    settings=new QSettings("PSPx","Ultimate PSPx Helper");

    treyIco=new QSystemTrayIcon(QIcon(":/ico.png"));
    treyIco->show();
    menuTrey=new QMenu;
    QAction *closetrey=new QAction("Выход",this);
    connect(closetrey,SIGNAL(triggered()),SLOT(close()));
    menuTrey->addAction(closetrey);
    treyIco->setContextMenu(menuTrey);

    ui->themeTab->setSortingEnabled(true);

    readSettings();

    findThemes();

    serachGm->setStyleSheet(this->styleSheet());


    ui->mainToolBar->addSeparator();

    HorSdescript=new QAction("Скрыть описание",this);
    connect(HorSdescript,SIGNAL(triggered()),SLOT(hide_desc()));
    ui->mainToolBar->addAction(HorSdescript);

    QPushButton *goSite=new QPushButton("Тема программы на форуме PSPx.ru",ui->AboutTextEdit);
    goSite->move(3,4);
    goSite->resize(250,18);
    goSite->show();
    connect(goSite,SIGNAL(clicked()),SLOT(forumTheme()));

    connect(ui->ExitAction,SIGNAL(triggered()),SLOT(close()));

    connect(ui->showPanel,SIGNAL(triggered()),ui->mainToolBar,SLOT(show()));
    /*------------------------------------------------------------------------------------------*/
    
    connect(ui->addVideoPsp,SIGNAL(clicked()),SLOT(addVideoContentAll()));
    connect(ui->videoPsp,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeItemAll(int)));

    connect(ui->addVideoPS3,SIGNAL(clicked()),SLOT(addVideoContentAll()));
    connect(ui->videoPs3,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeItemAll(int)));

    connect(ui->addVideoX,SIGNAL(clicked()),SLOT(addVideoContentAll()));
    connect(ui->videoX,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeItemAll(int)));

    connect(ui->addVideoWii,SIGNAL(clicked()),SLOT(addVideoContentAll()));
    connect(ui->videoWii,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeItemAll(int)));

    connect(ui->addVideoDs,SIGNAL(clicked()),SLOT(addVideoContentAll()));
    connect(ui->videoDs,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeItemAll(int)));
    /*-------------------------------------------------------------------------------------*/
    connect(ui->addImgPsp,SIGNAL(clicked()),SLOT(addImgAll()));
    connect(ui->imgPSP,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeImgAll(int)));

    connect(ui->addImgPs3,SIGNAL(clicked()),SLOT(addImgAll()));
    connect(ui->imgPs3,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeImgAll(int)));

    connect(ui->addImgX,SIGNAL(clicked()),SLOT(addImgAll()));
    connect(ui->imgX,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeImgAll(int)));

    connect(ui->addImgWii,SIGNAL(clicked()),SLOT(addImgAll()));
    connect(ui->imgWii,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeImgAll(int)));

    connect(ui->addImgDs,SIGNAL(clicked()),SLOT(addImgAll()));
    connect(ui->imgDs,SIGNAL(cellDoubleClicked(int,int)),SLOT(removeImgAll(int)));

    connect(ui->actTheme,SIGNAL(triggered()),SLOT(showThemeSet()));
    connect(ui->themeTab,SIGNAL(cellDoubleClicked(int,int)),SLOT(setTheme()));
    connect(ui->refreshThemes,SIGNAL(clicked()),SLOT(refreshThemeList()));
    connect(ui->actAbout,SIGNAL(triggered()),SLOT(showAbout()));

    connect(ui->clear_all,SIGNAL(triggered()),SLOT(clearAll()));
    connect(ui->clear_all,SIGNAL(triggered()),SLOT(veryficateData()));

    connect(ui->actSearchgame,SIGNAL(triggered()),serachGm,SLOT(show()));


    connect(ui->actionFastPic,SIGNAL(triggered()),SLOT(fastpicOpen()));
    connect(ui->actionGametrailers,SIGNAL(triggered()),SLOT(gametrailersOpen()));
    connect(ui->actionIGN,SIGNAL(triggered()),SLOT(ignOpen()));
    connect(ui->actionIgromania,SIGNAL(triggered()),SLOT(igromaniaOpen()));
    connect(ui->actionRadikal_ru,SIGNAL(triggered()),SLOT(radikalOpen()));
    connect(ui->action_PSPx_ru,SIGNAL(triggered()),SLOT(pspxOpen()));
    //-----------------------------------------------------------------------------------------------------------------
    connect(ui->boxArtPsp,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->boxArtPs3,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->boxArtX,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->boxArtWii,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->boxArtDs,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->nameGameDs,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->nameGamePs3,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->nameGamePsp,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->nameGameWii,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->nameGameX,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->publisherDs,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->publisherPs3,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->publisherPsp,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->publisherWii,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->publisherX,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->DevDs,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->DevPs3,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->DevPsp,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->DevWii,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->DevX,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->genreDs,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->genrePs3,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->genrePsp,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->genreWii,SIGNAL(editingFinished()),SLOT(veryficateData()));
    connect(ui->genreX,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->minFrimPsp,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->distribWii,SIGNAL(editingFinished()),SLOT(veryficateData()));

    connect(ui->boxArtPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->nameGamePsp,SIGNAL(textChanged(QString) ),SLOT(resultForPsp()));
    connect(ui->publisherPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->DevPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->genrePsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->minFrimPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->jpLnPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->usaLnPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->euLnPsp,SIGNAL(textChanged(QString)),SLOT(resultForPsp()));
    connect(ui->descrPsp,SIGNAL(textChanged()),SLOT(resultForPsp()));
    connect(ui->addVideoPsp,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->videoPsp,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForPsp()));
    connect(ui->imgPSP,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForPsp()));
    connect(ui->addImgPsp,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r3,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r7,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r11,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r12,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r16,SIGNAL(clicked()),SLOT(resultForPsp()));
    connect(ui->r18,SIGNAL(clicked()),SLOT(resultForPsp()));


    connect(ui->boxArtDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->nameGameDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->publisherDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->DevDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->genreDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->jpLnDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->usaLnDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->euLnDs,SIGNAL(textChanged(QString)),SLOT(resultForDs()));
    connect(ui->descrDs,SIGNAL(textChanged()),SLOT(resultForDs()));
    connect(ui->addImgDs,SIGNAL(clicked()),SLOT(resultForDs()));
    connect(ui->addVideoDs,SIGNAL(clicked()),SLOT(resultForDs()));
    connect(ui->videoDs,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForDs()));
    connect(ui->imgDs,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForDs()));


    connect(ui->boxArtPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->nameGamePs3,SIGNAL(textChanged(QString) ),SLOT(resultForPs3()));
    connect(ui->publisherPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->DevPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->genrePs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->jpLnPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->usaLnPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->euLnPs3,SIGNAL(textChanged(QString)),SLOT(resultForPs3()));
    connect(ui->descrPs3,SIGNAL(textChanged()),SLOT(resultForPs3()));
    connect(ui->addVideoPS3,SIGNAL(clicked()),SLOT(resultForPs3()));
    connect(ui->videoPs3,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForPs3()));
    connect(ui->imgPs3,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForPs3()));
    connect(ui->addImgPs3,SIGNAL(clicked()),SLOT(resultForPs3()));
    connect(ui->psn,SIGNAL(clicked()),SLOT(resultForPs3()));

    connect(ui->boxArtX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->nameGameX,SIGNAL(textChanged(QString) ),SLOT(resultForX()));
    connect(ui->publisherX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->DevX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->genreX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->jpLnX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->usaLnX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->euLnX,SIGNAL(textChanged(QString)),SLOT(resultForX()));
    connect(ui->descrX,SIGNAL(textChanged()),SLOT(resultForX()));
    connect(ui->addVideoX,SIGNAL(clicked()),SLOT(resultForX()));
    connect(ui->videoX,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForX()));
    connect(ui->imgX,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForX()));
    connect(ui->addImgX,SIGNAL(clicked()),SLOT(resultForX()));
    connect(ui->xboxLivePb,SIGNAL(clicked()),SLOT(resultForX()));

    connect(ui->boxArtWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->nameGameWii,SIGNAL(textChanged(QString) ),SLOT(resultForWii()));
    connect(ui->publisherWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->DevWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->distribWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->genreWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->jpLnWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->usaLnWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->euLnWii,SIGNAL(textChanged(QString)),SLOT(resultForWii()));
    connect(ui->descrWii,SIGNAL(textChanged()),SLOT(resultForWii()));
    connect(ui->addVideoWii,SIGNAL(clicked()),SLOT(resultForWii()));
    connect(ui->videoWii,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForWii()));
    connect(ui->imgWii,SIGNAL(cellDoubleClicked(int,int)),SLOT(resultForWii()));
    connect(ui->addImgWii,SIGNAL(clicked()),SLOT(resultForWii()));

    connect(ui->action_saveFile,SIGNAL(triggered()),SLOT(saveResultInFile()));
}

HelperX::~HelperX()
{

    delete ui;
}

void HelperX::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void HelperX::addVideoContentAll()
{
    QString o;
    o=sender()->objectName();

    if (o==ui->addVideoPsp->objectName()){

        ptw= new QTableWidgetItem();
        ui->videoPsp->setRowCount(ui->videoPsp->rowCount()+1);
        ptw->setText(ui->addVideoLnPsp->text());

        ui->videoPsp->setItem(ui->videoPsp->rowCount(),-1,ptw);
        ui->addVideoLnPsp->clear();
    }
    else


        if (o==ui->addVideoPS3->objectName())
        {

            ptw= new QTableWidgetItem();
            ui->videoPs3->setRowCount(ui->videoPs3->rowCount()+1);
            ptw->setText(ui->addVideoLnPs3->text());

            ui->videoPs3->setItem(ui->videoPs3->rowCount(),-1,ptw);
            ui->addVideoLnPs3->clear();

        }
        else
            if(o==ui->addVideoX->objectName())
            {

                ptw= new QTableWidgetItem();
                ui->videoX->setRowCount(ui->videoX->rowCount()+1);
                ptw->setText(ui->addVideoLnX->text());

                ui->videoX->setItem(ui->videoX->rowCount(),-1,ptw);
                ui->addVideoLnX->clear();

            }
            else
                if(o==ui->addVideoWii->objectName())
                {

                    ptw= new QTableWidgetItem();
                    ui->videoWii->setRowCount(ui->videoWii->rowCount()+1);
                    ptw->setText(ui->addVideoLnWii->text());

                    ui->videoWii->setItem(ui->videoWii->rowCount(),-1,ptw);
                    ui->addVideoLnWii->clear();

                }
                else
                    if(o==ui->addVideoDs->objectName())
                    {

                        ptw= new QTableWidgetItem();
                        ui->videoDs->setRowCount(ui->videoDs->rowCount()+1);
                        ptw->setText(ui->addVideoLnDs->text());

                        ui->videoDs->setItem(ui->videoDs->rowCount(),-1,ptw);
                        ui->addVideoLnDs->clear();

                    }

}

void HelperX::removeItemAll(int s)
{
    QString o="";
    o=sender()->objectName();
    if(o==ui->videoPsp->objectName())
        ui->videoPsp->removeRow(s);
    else

        if (o==ui->videoPs3->objectName())
        {
            ui->videoPs3->removeRow(s);
        }
        else
            if(o==ui->videoX->objectName())
            {
                ui->videoX->removeRow(s);
            }
            else
                if(o==ui->videoWii->objectName())
                {
                    ui->videoWii->removeRow(s);
                }
                else
                    if(o==ui->videoDs->objectName())
                    {
                        ui->videoDs->removeRow(s);
                    }


}

void HelperX::findThemes()
{
    ui->themeTab->setRowCount(0);
    QDir *dr=new QDir();
    if(dr->exists("./themes")){
        dr->setPath("./themes");
        QStringList files;
        QString fileName;
        fileName="*.css";
        files=dr->entryList(QStringList(fileName),QDir::Files|QDir::NoSymLinks);
        for(int i=0; i<files.size();i++){
            ptw=new QTableWidgetItem(files[i]);

            ui->themeTab->setRowCount(ui->themeTab->rowCount()+1);
            ui->themeTab->setItem(ui->themeTab->rowCount(),-1,ptw);

            if((curentTheme!="")&(files[i]==curentTheme)){
                ui->themeTab->setCurrentItem(ptw);
                QFile *fl=new QFile("./themes/"+ui->themeTab->currentItem()->text());
                if(fl->exists()){

                    ui->useTheme->setText("<font color=green>Используеммая тема:</font> "+ui->themeTab->currentItem()->text());
                    fl->open(QIODevice::ReadOnly);
                    curentTheme=ui->themeTab->currentItem()->text();
                    this->setStyleSheet(fl->readAll());
                }

            }

        }
    }
}

void HelperX::setTheme()
{
    if(ui->themeTab->rowCount()!=0){
        QFile *fl=new QFile("./themes/"+ui->themeTab->currentItem()->text());
        if(fl->exists()){

            ui->useTheme->setText("<font color=green>Используеммая тема:</font> "+ui->themeTab->currentItem()->text());
            fl->open(QIODevice::ReadOnly);
            curentTheme=ui->themeTab->currentItem()->text();
            this->setStyleSheet(fl->readAll());
            serachGm->setStyleSheet(this->styleSheet());
        }
    }
}

void HelperX::showThemeSet()
{
    ui->tabWidget->setCurrentIndex(5);
}

void HelperX::showAbout()
{
    ui->tabWidget->setCurrentIndex(6);
}

void HelperX::writeSettings()
{

    settings->setValue("/tabWidget",ui->tabWidget->currentIndex());

    settings->setValue("/theme",curentTheme);

    if (this->isMaximized())
    {winStatus=1;}
    else
        if (this->isFullScreen())
        {winStatus=2;}
        else
        {winStatus=0;}

    settings->setValue("/window",winStatus);

}

void HelperX::readSettings()
{

    int tbIndx=settings->value("/tabWidget",0).toInt();
    ui->tabWidget->setCurrentIndex(tbIndx);

    QString str=settings->value("/theme","").toString();
    curentTheme=str;

    int st=settings->value("/window",0).toInt();

    FullScreen=new QAction ("Во весь экран",this);
    connect(FullScreen,SIGNAL(triggered()),SLOT(setWindowSt()));
    ui->mainToolBar->addAction(FullScreen);

    winStatus=st;
    if (winStatus==0)
    {
        this->showNormal();
        FullScreen->setText("Во весь экран");
    }
    else
        if (winStatus==1)
        {
            this->showMaximized();
            FullScreen->setText("Во весь экран");
        }
        else
            if (winStatus==2)
            {
                this->showFullScreen();
                FullScreen->setText("Нормальный режим отображения");
            }

    ui->r3->setChecked(true);


}

void HelperX::refreshThemeList()
{
    findThemes();
}

void HelperX::closeEvent(QCloseEvent*)
{
    serachGm->close();
    writeSettings();


}

void HelperX::addImgAll()
{
    QString o;
    o=sender()->objectName();

    if (o==ui->addImgPsp->objectName()){

        ptw= new QTableWidgetItem();
        ui->imgPSP->setRowCount(ui->imgPSP->rowCount()+1);
        ptw->setText(ui->addImgLnPsp->text());

        ui->imgPSP->setItem(ui->imgPSP->rowCount(),-1,ptw);
        ui->addImgLnPsp->clear();
    }

    else


        if (o==ui->addImgPs3->objectName())
        {

            ptw= new QTableWidgetItem();
            ui->imgPs3->setRowCount(ui->imgPs3->rowCount()+1);
            ptw->setText(ui->addImgLnPs3->text());

            ui->imgPs3->setItem(ui->imgPs3->rowCount(),-1,ptw);
            ui->addImgLnPs3->clear();

        }
        else
            if(o==ui->addImgX->objectName())
            {

                ptw= new QTableWidgetItem();
                ui->imgX->setRowCount(ui->imgX->rowCount()+1);
                ptw->setText(ui->addImgLnX->text());

                ui->imgX->setItem(ui->imgX->rowCount(),-1,ptw);
                ui->addImgLnX->clear();

            }
            else
                if(o==ui->addImgWii->objectName())
                {

                    ptw= new QTableWidgetItem();
                    ui->imgWii->setRowCount(ui->imgWii->rowCount()+1);
                    ptw->setText(ui->addImgLnWii->text());

                    ui->imgWii->setItem(ui->imgWii->rowCount(),-1,ptw);
                    ui->addImgLnWii->clear();

                }
                else
                    if(o==ui->addImgDs->objectName())
                    {

                        ptw= new QTableWidgetItem();
                        ui->imgDs->setRowCount(ui->imgDs->rowCount()+1);
                        ptw->setText(ui->addImgLnDs->text());

                        ui->imgDs->setItem(ui->imgDs->rowCount(),-1,ptw);
                        ui->addImgLnDs->clear();

                    }
}

void HelperX::removeImgAll(int s)
{
    QString o="";
    o=sender()->objectName();

    if(o==ui->imgPSP->objectName())
        ui->imgPSP->removeRow(s);
    else

        if (o==ui->imgPs3->objectName())
        {
            ui->imgPs3->removeRow(s);
        }
        else
            if(o==ui->imgX->objectName())
            {
                ui->imgX->removeRow(s);
            }
            else
                if(o==ui->imgWii->objectName())
                {
                    ui->imgWii->removeRow(s);
                }
                else
                    if(o==ui->imgDs->objectName())
                    {
                        ui->imgDs->removeRow(s);
                    }
}

void HelperX::resultForPsp()
{
    QString videoStr="";
    for (int i=1;i<=ui->videoPsp->rowCount();i++){
        videoStr=videoStr+ui->videoPsp->item(i,-1)->text()+"\n";
    }

    QString imgStr="";
    for(int i=1;i<=ui->imgPSP->rowCount();i++){
        imgStr=imgStr+"[IMG]"+ui->imgPSP->item(i,-1)->text()+"[/IMG]\n";
    }

    QString rateStr="";
    if(ui->r3->isChecked()){
        rateStr="[IMG]http://s46.radikal.ru/i113/0909/75/dc2ba4e649cc.gif[/IMG]";}
    else
        if(ui->r7->isChecked())
        {rateStr="[IMG]http://s09.radikal.ru/i182/0909/aa/93639fd684ea.gif[/IMG]";}
        else
            if(ui->r11->isChecked())
            {rateStr="[IMG]http://s43.radikal.ru/i100/0909/42/67e62501c8b7.gif[/IMG]";}
            else
                if(ui->r12->isChecked())
                {rateStr="[IMG]http://i075.radikal.ru/0909/9e/cab410b5c7cf.gif[/IMG]";}
                else
                    if(ui->r16->isChecked())
                    {rateStr="[IMG]http://i037.radikal.ru/0909/fb/6e9ee640f490.gif[/IMG]";}
                    else
                        if(ui->r18->isChecked())
                        {rateStr="[IMG]http://s52.radikal.ru/i135/0909/f1/9d78c9d520d7.gif[/IMG]";}

    ui->resultPsp->setText("[pic=right]"+ui->boxArtPsp->text()+"[/pic]\n"
                           +"[b][size=\"3\"]"+ui->nameGamePsp->text()+"[/size][/b]\n"
                           +"[b]Издатель:[/b]"+ui->publisherPsp->text()+"\n"
                           +"[b]Разработчик:[/b]"+ui->DevPsp->text()+"\n"
                           +"[b]Жанр:[/b]"+ui->genrePsp->text()+"\n"
                           +"[b]Минимальная версия прошивки:[/b]"+ui->minFrimPsp->text()+"\n"
                           +"[b]Дата выхода:[/b]\n"
                           +"[IMG]http://s49.radikal.ru/i125/0807/f4/02a21f230643.png[/IMG] "+ui->jpLnPsp->text()+"\n"
                           +"[IMG]http://s56.radikal.ru/i154/0807/a0/08647eb771d2.png[/IMG] "+ui->usaLnPsp->text()+"\n"
                           +"[IMG]http://s42.radikal.ru/i098/0807/81/fc27d094ef4d.png[/IMG] "+ui->euLnPsp->text()+"\n"
                           +"[b][size=\"3\"]Описание:[/size][/b]\n"+ui->descrPsp->toPlainText()+"\n"
                           +"[b][size=\"3\"]Видео[/size][/b]\n"
                           +videoStr+"\n"
                           +"[spoiler=Screenshots]"
                           +imgStr+"\n"
                           +"[/spoiler]\n"
                           +rateStr);
    ui->resultPsp->selectAll();
    ui->resultPsp->copy();
    //treyIco->showMessage("Сообщение","Данные скопированны в буфер обмена");

}

void HelperX::resultForPs3()
{
    QString videoStr="";
    for (int i=1;i<=ui->videoPs3->rowCount();i++){
        videoStr=videoStr+ui->videoPs3->item(i,-1)->text()+"\n";
    }

    QString imgStr="";
    for(int i=1;i<=ui->imgPs3->rowCount();i++){
        imgStr=imgStr+"[IMG]"+ui->imgPs3->item(i,-1)->text()+"[/IMG]\n";
    }

    QString strPsn="";
    if(ui->psn->isChecked())
        strPsn="[pic=right]http://s45.radikal.ru/i108/0809/76/5ee4fddab21a.png[/pic]";
    else
        strPsn="[pic=right]http://s55.radikal.ru/i147/0811/1a/38ce934d616c.png[/pic]";


    ui->resultPs3->setText("[pic=right]"+ui->boxArtPs3->text()+"[/pic]\n"
                           +"[pic=right]http://s48.radikal.ru/i121/0809/b7/fa7a9dfe4e4f.png[/pic]"
                           +strPsn+"\n"
                           +"[size=\"4\"][b]"+ui->nameGamePs3->text()+"[/b][/size]\n"
                           +"[b]Издатель: "+ui->publisherPs3->text()+"\n"
                           +"Разработчик: "+ui->DevPs3->text()+"\n"
                           +"Жанр: "+ui->genrePs3->text()+"\n"
                           +"Дата выхода:[/b]\n"
                           +"[IMG]http://s49.radikal.ru/i125/0807/f4/02a21f230643.png[/IMG] "+ui->jpLnPs3->text()+"\n"
                           +"[IMG]http://s56.radikal.ru/i154/0807/a0/08647eb771d2.png[/IMG] "+ui->usaLnPs3->text()+"\n"
                           +"[IMG]http://s42.radikal.ru/i098/0807/81/fc27d094ef4d.png[/IMG] "+ui->euLnPs3->text()+"\n"
                           +"\n"
                           +"[b][size=\"3\"]Описание:[/size][/b] \n"
                           +ui->descrPs3->toPlainText()+"\n"
                           +"[b][size=\"3\"]Видео:[/size][/b]\n"
                           +videoStr+"\n"
                           +"[spoiler=\"Screeenshots\"] [center]\n"
                           +imgStr+"\n"
                           +"[/center] [/spoiler]");
    ui->resultPs3->selectAll();
    ui->resultPs3->copy();
    //treyIco->showMessage("Сообщение","Данные скопированны в буфер обмена");

}

void HelperX::resultForX()
{
    QString videoStr="";
    for (int i=1;i<=ui->videoX->rowCount();i++){
        videoStr=videoStr+ui->videoX->item(i,-1)->text()+"\n";
    }

    QString imgStr="";
    for(int i=1;i<=ui->imgX->rowCount();i++){
        imgStr=imgStr+"[IMG]"+ui->imgX->item(i,-1)->text()+"[/IMG]\n";
    }

    QString strLive="";
    if(ui->xboxLivePb->isChecked())
        strLive="[pic=right]http://s45.radikal.ru/i108/0809/76/5ee4fddab21a.png[/pic]";
    else
        strLive="[pic=right]http://s55.radikal.ru/i147/0811/1a/38ce934d616c.png[/pic]";


    ui->resultX->setText("[pic=right]"+ui->boxArtX->text()+"[/pic]\n"
                         +"[pic=right]http://s54.radikal.ru/i145/1008/8f/31c6a090f512.png[/pic]"
                         +strLive+"\n"
                         +"[b][size=\"3\"]"+ui->nameGameX->text()+"[/size][/b]\n"
                         +"[b]Издатель:[/b]"+ui->publisherX->text()+"\n"
                         +"[b]Разработчик:[/b]"+ui->DevX->text()+"\n"
                         +"[b]Жанр:[/b]"+ui->genreX->text()+"\n"
                         +"[b]Дата выхода:[/b]\n"
                         +"[IMG]http://s49.radikal.ru/i125/0807/f4/02a21f230643.png[/IMG] "+ui->jpLnX->text()+"\n"
                         +"[IMG]http://s56.radikal.ru/i154/0807/a0/08647eb771d2.png[/IMG] "+ui->usaLnX->text()+"\n"
                         +"[IMG]http://s42.radikal.ru/i098/0807/81/fc27d094ef4d.png[/IMG] "+ui->euLnX->text()+"\n"
                         +"[b][size=\"3\"]Описание:[/size][/b]\n"+ui->descrX->toPlainText()+"\n"
                         +"[b][size=\"3\"]Видео[/size][/b]\n"
                         +videoStr+"\n"
                         +"[spoiler=Screenshots]"
                         +imgStr+"\n"
                         +"[/spoiler]\n"
                         );
    ui->resultX->selectAll();
    ui->resultX->copy();
    // treyIco->showMessage("Сообщение","Данные скопированны в буфер обмена");
}

void HelperX::resultForWii()
{
    QString videoStr="";
    for (int i=1;i<=ui->videoWii->rowCount();i++){
        videoStr=videoStr+ui->videoWii->item(i,-1)->text()+"\n";
    }

    QString imgStr="";
    for(int i=1;i<=ui->imgWii->rowCount();i++){
        imgStr=imgStr+"[IMG]"+ui->imgWii->item(i,-1)->text()+"[/IMG]\n";
    }


    ui->resultWii->setText("[b][size=\"3\"]"+ui->nameGameWii->text()+"[/size][/b]\n"
                           +"[pic=right]"+ui->boxArtWii->text()+"[/pic]\n"
                           +"[b]Издатель:[/b]"+ui->publisherWii->text()+"\n"
                           +"[b]Разработчик:[/b]"+ui->DevWii->text()+"\n"
                           +"[b]Дистрибьютор:[/b]"+ui->distribWii->text()+"\n"
                           +"[b]Жанр:[/b]"+ui->genreWii->text()+"\n"
                           +"[b]Дата выхода:[/b]\n"
                           +"[IMG]http://s49.radikal.ru/i125/0807/f4/02a21f230643.png[/IMG] "+ui->jpLnWii->text()+"\n"
                           +"[IMG]http://s56.radikal.ru/i154/0807/a0/08647eb771d2.png[/IMG] "+ui->usaLnWii->text()+"\n"
                           +"[IMG]http://s42.radikal.ru/i098/0807/81/fc27d094ef4d.png[/IMG] "+ui->euLnWii->text()+"\n"
                           +"[b][size=\"3\"]Описание:[/size][/b]\n"+ui->descrWii->toPlainText()+"\n"
                           +"[b][size=\"3\"]Видео[/size][/b]\n"
                           +videoStr+"\n"
                           +"[spoiler=Screenshots]"
                           +imgStr+"\n"
                           +"[/spoiler]\n"
                           );
    ui->resultWii->selectAll();
    ui->resultWii->copy();
    // treyIco->showMessage("Сообщение","Данные скопированны в буфер обмена");
}

void HelperX::resultForDs()
{
    QString videoStr="";
    for (int i=1;i<=ui->videoDs->rowCount();i++){
        videoStr=videoStr+ui->videoDs->item(i,-1)->text()+"\n";
    }

    QString imgStr="";
    for(int i=1;i<=ui->imgDs->rowCount();i++){
        imgStr=imgStr+"[IMG]"+ui->imgDs->item(i,-1)->text()+"[/IMG]\n";
    }


    ui->resultDs->setText("[pic=right]"+ui->boxArtDs->text()+"[/pic]\n"
                          +"[b][size=\"3\"]"+ui->nameGameDs->text()+"[/size][/b]\n"
                          +"[b]Издатель:[/b]"+ui->publisherDs->text()+"\n"
                          +"[b]Разработчик:[/b]"+ui->DevDs->text()+"\n"
                          +"[b]Жанр:[/b]"+ui->genreDs->text()+"\n"
                          +"[b]Дата выхода:[/b]\n"
                          +"[IMG]http://s49.radikal.ru/i125/0807/f4/02a21f230643.png[/IMG] "+ui->jpLnDs->text()+"\n"
                          +"[IMG]http://s56.radikal.ru/i154/0807/a0/08647eb771d2.png[/IMG] "+ui->usaLnDs->text()+"\n"
                          +"[IMG]http://s42.radikal.ru/i098/0807/81/fc27d094ef4d.png[/IMG] "+ui->euLnDs->text()+"\n"
                          +"[b][size=\"3\"]Описание:[/size][/b]\n"+ui->descrDs->toPlainText()+"\n"
                          +"[b][size=\"3\"]Видео[/size][/b]\n"
                          +videoStr+"\n"
                          +"[spoiler=Screenshots]"
                          +imgStr+"\n"
                          +"[/spoiler]\n"
                          );
    ui->resultDs->selectAll();
    ui->resultDs->copy();
    // treyIco->showMessage("Сообщение","Данные скопированны в буфер обмена");
}

void HelperX::hide_desc()
{
    if (!ui->label->isHidden()){
        ui->label->hide();
        ui->label123->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label123_2->hide();
        ui->label123_3->hide();
        ui->label123_4->hide();
        ui->label123_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        ui->label_14->hide();
        ui->label_15->hide();
        ui->label_16->hide();
        ui->label_17->hide();
        ui->label_18->hide();
        ui->label_19->hide();
        ui->label_20->hide();
        ui->label_21->hide();
        ui->label_22->hide();
        HorSdescript->setText("Отобразить описание");
    }
    else
    {
        ui->label->show();
        ui->label123->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->label123_2->show();
        ui->label123_3->show();
        ui->label123_4->show();
        ui->label123_5->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_8->show();
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->label_13->show();
        ui->label_14->show();
        ui->label_15->show();
        ui->label_16->show();
        ui->label_17->show();
        ui->label_18->show();
        ui->label_19->show();
        ui->label_20->show();
        ui->label_21->show();
        ui->label_22->show();
        HorSdescript->setText("Скрыть описание");
    }
}

void HelperX::clearAll()
{
    QMessageBox *msgb=new QMessageBox();
    msgb->setWindowTitle("Внимание!");
    msgb->setWindowIcon(QIcon(":/clear.png"));
    msgb->setIcon(QMessageBox::Question);
    msgb->setText("Вы действительно хотите очистить ВСЁ?");
    msgb->setModal(true);
    msgb->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgb->setStyleSheet(this->styleSheet());
    int ret=msgb->exec();

    switch(ret){
    case QMessageBox::Yes:
        ui->nameGameDs->clear();
        ui->nameGamePs3->clear();
        ui->nameGamePsp->clear();
        ui->nameGameWii->clear();
        ui->nameGameX->clear();

        ui->psn->setChecked(false);

        ui->boxArtDs->clear();
        ui->boxArtPs3->clear();
        ui->boxArtPsp->clear();
        ui->boxArtWii->clear();
        ui->boxArtX->clear();

        ui->distribWii->clear();

        ui->publisherDs->clear();
        ui->publisherPs3->clear();
        ui->publisherPsp->clear();
        ui->publisherWii->clear();
        ui->publisherX->clear();

        ui->DevDs->clear();
        ui->DevPs3->clear();
        ui->DevPsp->clear();
        ui->DevWii->clear();
        ui->DevX->clear();

        ui->genreDs->clear();
        ui->genrePs3->clear();
        ui->genrePsp->clear();
        ui->genreWii->clear();
        ui->genreX->clear();

        ui->jpLnDs->clear();
        ui->jpLnPs3->clear();
        ui->jpLnPsp->clear();
        ui->jpLnWii->clear();
        ui->jpLnX->clear();

        ui->usaLnDs->clear();
        ui->usaLnPs3->clear();
        ui->usaLnPsp->clear();
        ui->usaLnWii->clear();
        ui->usaLnX->clear();

        ui->euLnDs->clear();
        ui->euLnPs3->clear();
        ui->euLnPsp->clear();
        ui->euLnWii->clear();
        ui->euLnX->clear();

        ui->minFrimPsp->clear();

        ui->descrDs->clear();
        ui->descrPs3->clear();
        ui->descrPsp->clear();
        ui->descrWii->clear();
        ui->descrX->clear();


        ui->addVideoLnDs->clear();
        ui->addVideoLnPs3->clear();
        ui->addVideoLnPsp->clear();
        ui->addVideoLnWii->clear();
        ui->addVideoLnX->clear();

        for (int i=ui->videoDs->rowCount(); i>=0;i--){
            ui->videoDs->removeRow(i);
        }
        for (int i=ui->videoPs3->rowCount(); i>=0;i--){
            ui->videoPs3->removeRow(i);
        }
        for (int i=ui->videoPsp->rowCount(); i>=0;i--){
            ui->videoPsp->removeRow(i);
        }
        for (int i=ui->videoWii->rowCount(); i>=0;i--){
            ui->videoWii->removeRow(i);
        }
        for (int i=ui->videoX->rowCount(); i>=0;i--){
            ui->videoX->removeRow(i);
        }

        ui->addImgLnDs->clear();
        ui->addImgLnPs3->clear();
        ui->addImgLnPsp->clear();
        ui->addImgLnWii->clear();
        ui->addImgLnX->clear();

        for (int i=ui->imgDs->rowCount(); i>=0;i--){
            ui->imgDs->removeRow(i);
        }
        for (int i=ui->imgPs3->rowCount(); i>=0;i--){
            ui->imgPs3->removeRow(i);
        }
        for (int i=ui->imgPSP->rowCount(); i>=0;i--){
            ui->imgPSP->removeRow(i);
        }
        for (int i=ui->imgWii->rowCount(); i>=0;i--){
            ui->imgWii->removeRow(i);
        }
        for (int i=ui->imgX->rowCount(); i>=0;i--){
            ui->imgX->removeRow(i);
        }

        ui->resultDs->clear();
        ui->resultPs3->clear();
        ui->resultPsp->clear();
        ui->resultWii->clear();
        ui->resultX->clear();
        break;
        //msgb->close();
    case QMessageBox::No:
        msgb->close();
        break;}
}

void HelperX::gametrailersOpen()
{
    QDesktopServices::openUrl(QUrl("http://www.gametrailers.com/"));
}

void HelperX::ignOpen()
{
    QDesktopServices::openUrl(QUrl("http://www.ign.com/"));
}

void HelperX::igromaniaOpen()
{
    QDesktopServices::openUrl(QUrl("http://igromania.ru/"));
}

void HelperX::radikalOpen()
{
    QDesktopServices::openUrl(QUrl("http://www.radikal.ru/"));
}

void HelperX::fastpicOpen()
{
    QDesktopServices::openUrl(QUrl("http://fastpic.ru/"));
}

void HelperX::pspxOpen()
{
    QDesktopServices::openUrl(QUrl("http://www.pspx.ru/forum/index.php"));
}

void HelperX::forumTheme()
{
    QDesktopServices::openUrl(QUrl("http://www.pspx.ru/forum/showthread.php?t=82412"));
}

void HelperX::setWindowSt()
{
    if (this->isFullScreen())
    {
        this->showNormal();
        FullScreen->setText("Во весь экран");
    }
    else
    {
        this->showFullScreen();
        FullScreen->setText("Нормальный режим отображения");
    }
}

void HelperX::veryficateData()
{
    if  (ui->boxArtPsp->text()!="")
        ui->isNoyNullLb01->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb01->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->nameGamePsp->text()!="")
        ui->isNoyNullLb02->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb02->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->publisherPsp->text()!="")
        ui->isNoyNullLb03->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb03->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->DevPsp->text()!="")
        ui->isNoyNullLb04->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb04->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->genrePsp->text()!="")
        ui->isNoyNullLb05->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb05->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->minFrimPsp->text()!="")
        ui->isNoyNullLb06->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb06->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->boxArtPs3->text()!="")
        ui->isNoyNullLb07->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb07->setPixmap(QPixmap(":/cancel.png"));

    /*--------------------------------------------------------------*/
    if  (ui->nameGamePs3->text()!="")
        ui->isNoyNullLb08->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb08->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->publisherPs3->text()!="")
        ui->isNoyNullLb09->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb09->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->DevPs3->text()!="")
        ui->isNoyNullLb10->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb10->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->genrePs3->text()!="")
        ui->isNoyNullLb11->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb11->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->boxArtX->text()!="")
        ui->isNoyNullLb12->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb12->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->nameGameX->text()!="")
        ui->isNoyNullLb13->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb13->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->publisherX->text()!="")
        ui->isNoyNullLb14->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb14->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->DevX->text()!="")
        ui->isNoyNullLb15->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb15->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->genreX->text()!="")
        ui->isNoyNullLb16->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb16->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->nameGameWii->text()!="")
        ui->isNoyNullLb17->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb17->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->boxArtWii->text()!="")
        ui->isNoyNullLb18->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb18->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->publisherWii->text()!="")
        ui->isNoyNullLb19->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb19->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->DevWii->text()!="")
        ui->isNoyNullLb20->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb20->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->distribWii->text()!="")
        ui->isNoyNullLb21->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb21->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->genreWii->text()!="")
        ui->isNoyNullLb22->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb22->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->boxArtDs->text()!="")
        ui->isNoyNullLb23->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb23->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->nameGameDs->text()!="")
        ui->isNoyNullLb24->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb24->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->publisherDs->text()!="")
        ui->isNoyNullLb25->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb25->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->DevDs->text()!="")
        ui->isNoyNullLb26->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb26->setPixmap(QPixmap(":/cancel.png"));
    /*--------------------------------------------------------------*/

    if  (ui->genreDs->text()!="")
        ui->isNoyNullLb27->setPixmap(QPixmap(":/ok .png"));

    else
        ui->isNoyNullLb27->setPixmap(QPixmap(":/cancel.png"));

}

void HelperX::saveResultInFile()
{

    if(ui->tabWidget->currentIndex()==0)
    {
        QString filename = QFileDialog::getSaveFileName(
                    this,
                    tr("Save as"),
                    QDir::currentPath(),
                    tr("Text file (*.txt)") );
        if(!filename.isNull())
        {

            QFile f(filename);
            f.open(QIODevice::WriteOnly);
            QByteArray bt=ui->resultPsp->toPlainText().toAscii();
            f.write(bt);
        }
    }

    else

        if (ui->tabWidget->currentIndex()==1)
        {
            QString filename = QFileDialog::getSaveFileName(
                        this,
                        tr("Save as"),
                        QDir::currentPath(),
                        tr("Text file (*.txt)") );
            if(!filename.isNull())
            {

                QFile f(filename);
                f.open(QIODevice::WriteOnly);
                QByteArray bt=ui->resultPs3->toPlainText().toAscii();
                f.write(bt);
            }
        }
        else
            if(ui->tabWidget->currentIndex()==2)
            {
                QString filename = QFileDialog::getSaveFileName(
                            this,
                            tr("Save as"),
                            QDir::currentPath(),
                            tr("Text file (*.txt)") );
                if(!filename.isNull())
                {

                    QFile f(filename);
                    f.open(QIODevice::WriteOnly);
                    QByteArray bt=ui->resultX->toPlainText().toAscii();
                    f.write(bt);
                }
            }
            else
                if(ui->tabWidget->currentIndex()==3)
                {
                    QString filename = QFileDialog::getSaveFileName(
                                this,
                                tr("Save as"),
                                QDir::currentPath(),
                                tr("Text file (*.txt)") );
                    if(!filename.isNull())
                    {

                        QFile f(filename);
                        f.open(QIODevice::WriteOnly);
                        QByteArray bt=ui->resultWii->toPlainText().toAscii();
                        f.write(bt);
                    }
                }
                else
                    if(ui->tabWidget->currentIndex()==4)
                    {
                        QString filename = QFileDialog::getSaveFileName(
                                    this,
                                    tr("Save as"),
                                    QDir::currentPath(),
                                    tr("Text file (*.txt)") );
                        if(!filename.isNull())
                        {
                            QFile f(filename);
                            f.open(QIODevice::WriteOnly);
                            QByteArray bt=ui->resultDs->toPlainText().toAscii();
                            f.write(bt);

                        }
                        else
                            if(ui->tabWidget->currentIndex()>4)
                            {

                            }

                    }

}

