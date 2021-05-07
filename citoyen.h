#ifndef CITOYEN_H
#define CITOYEN_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include "qstring.h"

class citoyen
{
public:
    citoyen();
    citoyen(int,QString,QString,QString,int);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();
     int getnum();


    void setcin(int);
    void setnom (QString);
    void setprenom(QString);
     void setadresse (QString);
    void setnum (int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_nom();


private:
    int cin;

    QString nom,prenom,adresse;
    int num;
};

#endif // CITOYEN_H
