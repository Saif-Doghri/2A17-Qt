#include "vehicules.h"
Vehicule::Vehicule(QString matricule,QString marque,QString type,QString couleur,QDate date){
    this->matricule=matricule;
    this->marque=marque;
    this->type=type;
    this->couleur=couleur;
    this->date_acquisition=date;
}

void Vehicule::settype(QString a){
    this->type=a;
}

void Vehicule::setmatricule(QString matricule){
    this->matricule=matricule;
}

void Vehicule::setmarque(QString marque){
    this->marque=marque;
}

void Vehicule::setcouleur(QString couleur){
    this->couleur=couleur;
}

void Vehicule::setDate(QDate date){
    this->date_acquisition=date;
}

QString Vehicule::getmatricule(){
    return this->matricule;
}

QString Vehicule::getmarque(){
    return this->marque;
}

QString Vehicule::getcouleur(){
    return this->couleur;
}

QString Vehicule::gettype(){
    return this->type;
}

QDate Vehicule::getDate(){
    return this->date_acquisition;
}

QString Vehicule::ToString(){
    return this->matricule+" "+this->marque+" "+this->couleur;
}
