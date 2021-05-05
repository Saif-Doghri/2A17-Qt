#include "profil.h"
#include <QCryptographicHash>
Profil::Profil(float salaire,QString grade,QString fonction,QDate date,QString dept)
{
    this->salaire=salaire;
    this->grade=grade;
    this->fonction=fonction;
    this->date_embauche=date;
    this->departement=dept;
    this->id=QString(QCryptographicHash::hash((this->grade+this->fonction+this->departement+this->date_embauche.toString()).toLocal8Bit(),QCryptographicHash::Md5).toBase64());
}

void Profil::setDapartement(QString dept){
    this->departement=dept;
}

void Profil::setFonction(QString fonct){
    this->fonction=fonct;
}

void Profil::setSalaire(float salaire){
    this->salaire=salaire;
}

void Profil::setGrade(QString grade){
    this->grade=grade;
}

void Profil::setDateEmbauche(QDate date){
    this->date_embauche=date;
}

QString Profil::getDepartement(){
    return this->departement;
}

QString Profil::getFonction(){
    return this->fonction;
}

QString Profil::getGrade(){
    return this->grade;
}

float Profil::getSalaire(){
    return this->salaire;
}

QDate Profil::getDateEmbauche(){
    return this->date_embauche;
}

QString Profil::getId(){
    return this->id;
}

QString Profil::toString(){
    return this->departement+" "+this->grade+" "+this->date_embauche.toString("yyyy/MM/dd");
}
