#ifndef AGENT_H
#define AGENT_H
#include<QString>
#include<QDate>
class Agent{
private:
    QString id;
    QString nom;
    QString prenom;
    int age;
    QString cin;
    QDate date_naissance;
public:
    Agent(QString nom,QString prenom,int age,QString cin,QDate date);
    void setNom(QString);
    void setPrenom(QString);
    void setAge(int);
    void setCIN(QString);
    void setDate(QDate);
    QString getId();
    QString getNom();
    QString getPrenom();
    int getAge();
    QString getCIN();
    QDate getDate();
    QString ToString();
};

#endif // AGENT_H
