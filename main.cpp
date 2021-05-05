#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QFile file("C:\\Users\\THINKPAD\\Documents\\build-InterfaceAgent-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\\debug\\ElegantDark.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

        //setup stylesheet
        a.setStyleSheet(styleSheet);
    //w.show();
    //Afficher aff;
    //aff.show();
        w.show();
    return a.exec();
}
