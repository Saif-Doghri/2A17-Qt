#include "mainwindow.h"

#include <QApplication>
#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow w;
    QFile styleSheetFile("C:/Users/WIN10/Desktop/projet_youssef/ElegantDark.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);


    w.show();
    return a.exec();
}
