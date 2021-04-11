#include "vehiculecontroller.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
void VehiculeController::ajouterVehicule(Vehicule& a){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("INSERT INTO vehicules(matriculevehicule,marquevehicule,typevehicule,couleurvehicule,date_acquisition)"
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
    ajout.bindValue(":date_acquisition",a.getDate().toString("dd-MM-yyyy"));
    if(ajout.exec()){
        QMessageBox* NewMessage=new QMessageBox ;
        NewMessage->setText("Ajout fait avec succès !");
        NewMessage->show();
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}

QSqlTableModel* VehiculeController::afficherVehicules(){
   // QSqlDatabase* db=Config::ouvrirConnexion();
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
  //  Config::fermerConnexion(*db);
    return vehiculetable;
}


void VehiculeController::modifierVehicule(Vehicule &a, QString matricule){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* vehiculetable =new QSqlTableModel;
    vehiculetable->setTable("vehicules");
    if(ajout.prepare("UPDATE vehicules SET marquevehicule=:marque,typevehicule=:type,couleurvehicule=:couleur,date_acquisition=:date_acquisition"
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
    ajout.bindValue(":date_acquisition",a.getDate().toString("dd-MM-yyyy"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(vehiculetable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}

QSqlTableModel* VehiculeController::afficherVehicule(QString matricule){
    //QSqlDatabase* db=Config::ouvrirConnexion();
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
   // Config::fermerConnexion(*db);
    return vehiculetable;
}

void VehiculeController::supprimerVehicule(QString matricule){
   // QSqlDatabase* db=Config::ouvrirConnexion();
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
 //   Config::fermerConnexion(*db);
}
void VehiculeController::affecterVehicule(QString matriculevehicule , QString idparking){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Vehiculetable =new QSqlTableModel;
    Vehiculetable->setTable("Vehicules");
    if(ajout.prepare("UPDATE Vehicules set idparking=:idP WHERE matriculevehicule=:id"
                     )){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"num mech kaada tji";
    ajout.bindValue(":id",matriculevehicule);
    ajout.bindValue(":idP",idparking);

    if(ajout.exec()){
        qDebug() << "Success";
        if(Vehiculetable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //
}
