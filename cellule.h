#ifndef CELLULE_H
#define CELLULE_H
#include <QSqlDatabase>
#include<QString>
#include <QSqlError>
#include <QSqlQuery>
#include<QDate>
class Cellule{
private:
   QString idC;
    int num;
    int capacite;
public:
    Cellule(QString,int,int);
    void setNum(int);
    void setCapacite(int);
    void setIdC(QString);
   QString getIdC();
    int getCapacite();
    int getNum();
    QString ToString();
};

#endif // Cellule_H
