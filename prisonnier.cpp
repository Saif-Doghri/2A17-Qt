#include "prisonnier.h"
#include <QCryptographicHash>
#include <QtAlgorithms>
Prisonnier::Prisonnier(QString nom,QString prenom,QString crime,QString cin,QDate date){
    this->nom=nom;
    this->prenom=prenom;
    this->crime=crime;
    this->cin=cin;
    this->date_naissance=date;
    this->id=QString(QCryptographicHash::hash((this->nom+this->prenom).toLocal8Bit(),QCryptographicHash::Md5).toBase64());
}

void Prisonnier::setCrime(QString crime){
    this->crime=crime;
}

void Prisonnier::setNom(QString nom){
    this->nom=nom;
}

void Prisonnier::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Prisonnier::setCIN(QString cin){
    this->cin=cin;
}

void Prisonnier::setDate(QDate date){
    this->date_naissance=date;
}

QString Prisonnier::getId(){
    return this->id;
}

QString Prisonnier::getNom(){
    return this->nom;
}

QString Prisonnier::getPrenom(){
    return this->prenom;
}

QString Prisonnier::getCIN(){
    return this->cin;
}

QString Prisonnier::getCrime(){
    return this->crime;
}

QDate Prisonnier::getDate(){
    return this->date_naissance;
}

QString Prisonnier::ToString(){
    return this->nom+" "+this->prenom+" "+this->cin;
}
