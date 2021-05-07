#include "cellule.h"
#include <QCryptographicHash>
#include <QtAlgorithms>
Cellule::Cellule(QString idC,int num,int capacite){
    this->num=num;
    this->capacite=capacite;
    this->idC=QString(QCryptographicHash::hash(QByteArray::number(this->num+this->capacite),QCryptographicHash::Md5).toBase64());
}

void Cellule::setNum(int a){
    this->num=a;
}

void Cellule::setCapacite(int b){
    this->capacite=b;
}


QString Cellule::getIdC(){
    return this->idC;
}

int Cellule::getNum(){
    return this->num;
}



int Cellule::getCapacite(){
    return this->capacite;
}

QString Cellule::ToString(){
        return QString(this->num)+" "+QString(this->capacite);
    }




