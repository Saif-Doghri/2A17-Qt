#include "Agent.h"
#include <QCryptographicHash>
#include <QtAlgorithms>
Agent::Agent(QString nom,QString prenom,int age,QString cin,QString mdp,QDate date){
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->cin=cin;
    this->date_naissance=date;
    this->mdp=mdp;
    this->id=QString(QCryptographicHash::hash((this->nom+this->prenom).toLocal8Bit(),QCryptographicHash::Md5).toBase64());
}

void Agent::setAge(int a){
    this->age=a;
}

void Agent::setNom(QString nom){
    this->nom=nom;
}

void Agent::setMdp(QString mdp){
    this->mdp=mdp;
}

void Agent::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Agent::setCIN(QString cin){
    this->cin=cin;
}

void Agent::setDate(QDate date){
    this->date_naissance=date;
}

QString Agent::getId(){
    return this->id;
}

QString Agent::getNom(){
    return this->nom;
}

QString Agent::getPrenom(){
    return this->prenom;
}

QString Agent::getCIN(){
    return this->cin;
}

QString Agent::getMdp(){
    return this->mdp;
}

int Agent::getAge(){
    return this->age;
}

QDate Agent::getDate(){
    return this->date_naissance;
}

QString Agent::ToString(){
    return this->nom+" "+this->prenom+" "+this->cin;
}
