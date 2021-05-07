#ifndef PROFIL_H
#define PROFIL_H

#include<QString>
#include<QDate>
class Profil
{
private:
    QString id;
    int salaire;
    QString fonction;
    QString grade;
    QDate date_embauche;
    QString departement;
public:
    Profil(int,QString,QString,QDate,QString);
    void setSalaire(int);
    void setFonction(QString);
    void setGrade(QString);
    void setDateEmbauche(QDate);
    void setDapartement(QString);
    QString getDepartement();
    QDate getDateEmbauche();
    QString getGrade();
    QString getFonction();
    int getSalaire();
    QString getId();
    QString toString();
};

#endif // PROFIL_H
