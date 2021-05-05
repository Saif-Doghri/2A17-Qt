#ifndef PROFIL_H
#define PROFIL_H

#include<QString>
#include<QDate>
class Profil
{
private:
    QString id;
    float salaire;
    QString fonction;
    QString grade;
    QDate date_embauche;
    QString departement;
public:
    Profil(float,QString,QString,QDate,QString);
    void setSalaire(float);
    void setFonction(QString);
    void setGrade(QString);
    void setDateEmbauche(QDate);
    void setDapartement(QString);
    QString getDepartement();
    QDate getDateEmbauche();
    QString getGrade();
    QString getFonction();
    float getSalaire();
    QString getId();
    QString toString();
};

#endif // PROFIL_H
