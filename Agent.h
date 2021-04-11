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
    QString mdp;
    QDate date_naissance;
public:
    Agent(QString nom,QString prenom,int age,QString cin,QString mdp,QDate date);
    void setNom(QString);
    void setPrenom(QString);
    void setAge(int);
    void setCIN(QString);
    void setDate(QDate);
    void setMdp(QString);
    QString getId();
    QString getNom();
    QString getPrenom();
    int getAge();
    QString getCIN();
    QString getMdp();
    QDate getDate();
    QString ToString();
};

#endif // AGENT_H
