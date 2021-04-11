#include "celluleController.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void CelluleController::ajouterCellule(Cellule& a){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Celluletable =new QSqlTableModel;
    Celluletable->setTable("Cellules");
    if(ajout.prepare("INSERT INTO Cellules(idCellule,numCellule,capaciteCellule)"
                     " VALUES(:idC,:num,:capacite)")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":idC",a.getIdC());
    ajout.bindValue(":num",a.getNum());
    ajout.bindValue(":capacite",a.getCapacite());
    if(ajout.exec()){
        qDebug() << "Success";
        if(Celluletable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}

QSqlTableModel* CelluleController::afficherCellules(){
   // QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Celluletable =new QSqlTableModel;
    Celluletable->setTable("Cellules");
    if(ajout.prepare("SELECT * FROM Cellules")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(Celluletable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
    return Celluletable;
}

void CelluleController::modifierCellule(Cellule &a, QString idC){
  //  QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Celluletable =new QSqlTableModel;
    Celluletable->setTable("Cellules");
    if(ajout.prepare("UPDATE Cellules SET numCellule=:num,capaciteCellule=:capacite"
                     " WHERE idCellule=:idC")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":idC",idC);
    ajout.bindValue(":num",a.getNum());
    ajout.bindValue(":capacite",a.getCapacite());
    if(ajout.exec()){
        qDebug() << "Success";
        if(Celluletable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
   // Config::fermerConnexion(*db);
}

QSqlTableModel* CelluleController::afficherCellule(QString idC){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Celluletable =new QSqlTableModel;
    Celluletable->setTable("Cellules");
    if(ajout.prepare("SELECT * FROM Cellules WHERE idCellule=:idC")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":idC",idC);
    if(ajout.exec()){
        qDebug() << "Success";
        if(Celluletable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return Celluletable;
}

void CelluleController::supprimerCellule(QString idC){
   // QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM Cellules WHERE idCellule=:idC")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":idC",idC);
    if(ajout.exec()){
        qDebug() << "Success";
        qDebug() << "Delete Complete";
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
  //  Config::fermerConnexion(*db);
}

