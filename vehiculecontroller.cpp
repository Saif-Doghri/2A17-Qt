#include "vehiculecontroller.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void VehiculeController::ajouterVehicule(Vehicule& a){
    QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("INSERT INTO vehicules(matriculevehicule,marquevehicule,typevehicule,couleurvehicule,date_acquisition_vehicule)"
                     " VALUES(:matricule,:marque,:type,:couleur,:date_acquisition)")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":matricule",a.getmatricule());
    ajout.bindValue(":marque",a.getmarque());
    ajout.bindValue(":type",a.gettype());
    ajout.bindValue(":couleur",a.getcouleur());
    ajout.bindValue(":date_acquisition",a.getDate().toString("yyyy-MM-dd"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    Config::fermerConnexion(*db);
}

QSqlTableModel* VehiculeController::afficherVehicules(){
    QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("SELECT * FROM vehicules")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    Config::fermerConnexion(*db);
    return vehiculetable;
}

void VehiculeController::modifierVehicule(Vehicule &a, QString matricule){
    QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("UPDATE vehicules SET marquevehicule=:marque,typevehicule=:type,couleurvehicule=:couleur,date_acquisition_vehicule=:date_acquisition"
                     " WHERE matriculevehicule=:matricule")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":matricule",matricule);
    ajout.bindValue(":marque",a.getmarque());
    ajout.bindValue(":type",a.gettype());
    ajout.bindValue(":couleur",a.getcouleur());
    ajout.bindValue(":date_acquisition",a.getDate().toString("yyyy-MM-dd"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    Config::fermerConnexion(*db);
}

QSqlTableModel* VehiculeController::afficherVehicule(QString matricule){
    QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("SELECT * FROM vehicules WHERE matriculevehicule=:matricule")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":matricule",matricule);
    if(ajout.exec()){
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    Config::fermerConnexion(*db);
    return vehiculetable;
}

void VehiculeController::supprimerVehicule(QString matricule){
    QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM vehicules WHERE matriculevehicule=:matricule")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":matricule",matricule);
    if(ajout.exec()){
        qDebug() << "Success";
        qDebug() << "Delete Complete";
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    Config::fermerConnexion(*db);
}
