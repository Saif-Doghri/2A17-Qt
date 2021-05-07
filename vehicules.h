#ifndef VEHICULES_H
#define VEHICULES_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
class Vehicule{
private:
    QString matricule;
    QString marque;
    QString type;
    QString couleur;
    QDate date_acquisition;
public:
    Vehicule(QString matricule,QString marque,QString type,QString couleur,QDate date);
    void setmatricule(QString);
    void setmarque(QString);
    void settype(QString);
    void setcouleur(QString);
    void setDate(QDate);
    QString getmatricule();
    QString getmarque();
    QString gettype();
    QString getcouleur();
    QDate getDate();
    QString ToString();
};

#endif // vehicule_H
