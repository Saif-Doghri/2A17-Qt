#ifndef PARKING_H
#define PARKING_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDate>
class Parking
{
private:
    int taille;
    int nbVehicules;
    int placesVides;
    QString id;
public:
    Parking(int,int,int,QString);
    void settaille(int);
    void setnbVehicules(int);
    void setplacesVides(int);
    void setid(QString);
    int getplacesVides();
    int getnbVehicules();
    int gettaille();
    QString getid();
    QString ToString();
};

#endif // Parking_H
