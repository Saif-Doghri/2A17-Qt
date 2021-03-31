#include "parking.h"

Parking::Parking(int taille,int nbVehicules,int placesVides, QString id)
{
    this->taille=taille;
    this->nbVehicules=nbVehicules;
    this->placesVides=placesVides;
    this->id=id;
}


void Parking::setplacesVides(int placesVides){
    this->placesVides=placesVides;
}

void Parking::settaille(int taille){
    this->taille=taille;
}

void Parking::setnbVehicules(int nbVehicules){
    this->nbVehicules=nbVehicules;
}
void Parking::setid(QString id){
    this->id=id;
}


int Parking::getplacesVides(){
    return this->placesVides;
}

int Parking::getnbVehicules(){
    return this->nbVehicules;
}

int Parking::gettaille(){
    return this->taille;
}
QString Parking::getid(){
    return this->id;
}


QString Parking::ToString(){
    return QString(this->taille)+" "+QString(this->nbVehicules)+" "+QString(this->placesVides);
}

