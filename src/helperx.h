#ifndef HELPERX_H
#define HELPERX_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <QSettings>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include "windowsearchgame.h"
#include <QFileDialog>




namespace Ui {
    class HelperX;
}

class HelperX : public QMainWindow {
    Q_OBJECT
public:
    HelperX(QWidget *parent = 0);
    ~HelperX();




protected:
    void changeEvent(QEvent *e);
    virtual void  closeEvent (QCloseEvent *);


private:
    Ui::HelperX *ui;
    QStringListModel videoStrl;
    QStringList stringL;
    QTableWidgetItem *ptw;
    QSettings *settings;
    QString curentTheme;
    QAction *HorSdescript;
    QSystemTrayIcon *treyIco;
    windowSearchGame *serachGm;
    QMenu *menuTrey;
    QAction *FullScreen;


    int winStatus;

    void findThemes();
    void writeSettings();
    void readSettings();


public slots:
   void addVideoContentAll();
   void removeItemAll(int);
   void setTheme();
   void showThemeSet();
   void showAbout();
   void refreshThemeList();
   void addImgAll();
   void removeImgAll(int);
   void resultForPsp();
   void resultForPs3();
   void resultForX();
   void resultForWii();
   void resultForDs();
   void hide_desc();
   void clearAll();

   void gametrailersOpen();
   void ignOpen();
   void igromaniaOpen();
   void radikalOpen();
   void fastpicOpen();
   void pspxOpen();
   void forumTheme();
   void setWindowSt();

   void veryficateData();

   void saveResultInFile();
};

#endif // HELPERX_H
