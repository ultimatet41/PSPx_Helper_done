#include <QtGui/QApplication>
#include "helperx.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("windows-1251"));
    HelperX w;
    w.show();
    return a.exec();
}
