#include "parkingcontroller.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>

void ParkingController::ajouterParking(Parking& a){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* parkingtable =new QSqlTableModel;
    parkingtable->setTable("parkings");
    if(ajout.prepare("INSERT INTO parkings(idparking,tailleparking,nbVehiculesparking,placesVidesparking)"
                     " VALUES(:id,:taille,:nbVehicules,:placesVides)")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":id",a.getid());
    ajout.bindValue(":taille",a.gettaille());
    ajout.bindValue(":nbVehicules",a.getnbVehicules());
    ajout.bindValue(":placesVides",a.getplacesVides());
    if(ajout.exec()){
        QMessageBox* NewMessage=new QMessageBox ;
        NewMessage->setText("Ajout fait avec succès !");
        NewMessage->show();
        qDebug() << "Success";
        if(parkingtable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
  //  Config::fermerConnexion(*db);
}

QSqlTableModel* ParkingController::afficherParkings(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* parkingtable =new QSqlTableModel;
    parkingtable->setTable("parkings");
    if(ajout.prepare("SELECT * FROM parkings")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(parkingtable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
    return parkingtable;
}

void ParkingController::modifierParking(Parking &a, QString id){
   // QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* parkingtable =new QSqlTableModel;
    parkingtable->setTable("parkings");
    if(ajout.prepare("UPDATE parkings SET tailleparking=:taille,nbVehiculesparking=:nbVehicules,placesVidesparking=:placesVides WHERE idparking=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    qDebug() <<"Data Received2 : " <<a.gettaille();
    ajout.bindValue(":id",id);
    ajout.bindValue(":taille",a.gettaille());
    ajout.bindValue(":nbVehicules",a.getnbVehicules());
    ajout.bindValue(":placesVides",a.getplacesVides());
    if(ajout.exec()){
        qDebug() << "Success";
        if(parkingtable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}

QSqlTableModel* ParkingController::afficherParking(QString id){
   // QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* parkingtable =new QSqlTableModel;
    parkingtable->setTable("parkings");
    if(ajout.prepare("SELECT * FROM parkings WHERE idparking=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":id",id);
    if(ajout.exec()){
        qDebug() << "Success";
        if(parkingtable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
 //   Config::fermerConnexion(*db);
    return parkingtable;
}

void ParkingController::supprimerParking(QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM parkings WHERE idparking=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":id",id);
    if(ajout.exec()){
        qDebug() << "Success";
        qDebug() << "Delete Complete";
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}
