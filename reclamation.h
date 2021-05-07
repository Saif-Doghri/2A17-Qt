#ifndef RECLAMATION_H
#define RECLAMATION_H
#include "qstring.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class reclamation
{
public:
    reclamation();
    reclamation(int,int,QString,QDate);
    int getid_reclamation();
    int getid_citoyen();
    QString gettype_reclamation();

    QString getdate_reclamation();

    void setid_reclamation(int);
    void setid_citoyen(int);
    void settype_reclamation (QString);

    void setdate_reclamationt (QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher_2(QString);
   QSqlQueryModel * tri_type_reclamation();
   QList<QString> listetyperec();
   int calculType(QString);



private:
int id_reclamation,id_citoyen;
QString type_reclamation;
QDate  date_reclamation;

};

#endif // RECLAMATION_H
