#ifndef PRISONNIER_H
#define PRISONNIER_H
#include<QString>
#include<QDate>
class Prisonnier{
private:
    QString id;
    QString nom;
    QString prenom;
    QString crime;
    QString cin;
    QDate date_naissance;
public:
    Prisonnier(QString nom,QString prenom,QString crime,QString cin,QDate date);
    void setNom(QString);
    void setPrenom(QString);
    void setCrime(QString);
    void setCIN(QString);
    void setDate(QDate);
    QString getId();
    QString getNom();
    QString getPrenom();
    QString getCrime();
    QString getCIN();
    QDate getDate();
    QString ToString();
};

#endif // Prisonnier_H
