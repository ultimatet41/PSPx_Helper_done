#ifndef WINDOWSEARCHGAME_H
#define WINDOWSEARCHGAME_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
    class windowSearchGame;
}

class windowSearchGame : public QWidget
{
    Q_OBJECT

public:
    explicit windowSearchGame(QWidget *parent = 0);
    ~windowSearchGame();

private:
    Ui::windowSearchGame *ui;

    virtual void keyPressEvent(QKeyEvent *);

public slots:
    void finGame();

};

#endif // WINDOWSEARCHGAME_H
