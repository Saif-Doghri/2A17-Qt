#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QFile file("C:/Users/WIN10/Desktop/projet_youssef/ElegantDark.qss");
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
