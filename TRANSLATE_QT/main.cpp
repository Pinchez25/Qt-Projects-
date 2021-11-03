#include "widget.h"

#include <QApplication>
#include<QTranslator>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t, guiTranslator;

    QStringList languages;
    languages <<"English"<<"French"<<"Swahili";

    QString lang = QInputDialog::getItem(NULL,"Select Language","Language",languages);

    if(lang == "French"){
        t.load(":/french.qm");
        guiTranslator.load("D:\\Qt\\6.1.1\\mingw81_64\\translations\\qtbase_fr.qm");
    }else if(lang=="Swahili"){
        guiTranslator.load("D:\\Qt\\6.1.1\\mingw81_64\\translations\\qtbase_sk.qm");
        //t.load(":/sw_ke.qm");

    }
    if(lang != "English"){
        a.installTranslator(&t);
        a.installTranslator(&guiTranslator);
    }
    Widget w;
    w.show();
    return a.exec();
}
