#include "prisonnierController.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void PrisonnierController::ajouterPrisonnier(Prisonnier& a){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Prisonniertable =new QSqlTableModel;
    Prisonniertable->setTable("Prisonniers");
    if(ajout.prepare("INSERT INTO Prisonniers(idPrisonnier,nomPrisonnier,prenomPrisonnier,crimePrisonnier,cinPrisonnier,date_naissance_Prisonnier)"
                     " VALUES(:id,:nom,:prenom,:crime,:cin,:date_naissance)")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":id",a.getId());
    ajout.bindValue(":nom",a.getNom());
    ajout.bindValue(":prenom",a.getPrenom());
    ajout.bindValue(":crime",a.getCrime());
    ajout.bindValue(":cin",a.getCIN());
    ajout.bindValue(":date_naissance",a.getDate().toString("dd-MM-yyyy"));
    qDebug() << a.getDate();
    if(ajout.exec()){
        qDebug() << "Success";
        if(Prisonniertable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //
}

QSqlTableModel* PrisonnierController::afficherPrisonniers(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Prisonniertable =new QSqlTableModel;
    Prisonniertable->setTable("Prisonniers");
    if(ajout.prepare("SELECT* FROM Prisonniers" )){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(Prisonniertable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return Prisonniertable;
}


void PrisonnierController::modifierPrisonnier(Prisonnier &a, QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Prisonniertable =new QSqlTableModel;
    Prisonniertable->setTable("Prisonniers");
    if(ajout.prepare("UPDATE Prisonniers SET nomPrisonnier=:nom,prenomPrisonnier=:prenom,CrimePrisonnier=:Crime,cinPrisonnier=:cin,date_naissance_Prisonnier=:date_naissance"
                     " WHERE idPrisonnier=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":id",id);
    ajout.bindValue(":nom",a.getNom());
    ajout.bindValue(":prenom",a.getPrenom());
    ajout.bindValue(":Crime",a.getCrime());
    ajout.bindValue(":cin",a.getCIN());
    ajout.bindValue(":date_naissance",a.getDate().toString("dd-MM-yyyy"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(Prisonniertable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* PrisonnierController::afficherPrisonnier(QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Prisonniertable =new QSqlTableModel;
    Prisonniertable->setTable("Prisonniers");
    if(ajout.prepare("SELECT * FROM Prisonniers WHERE idPrisonnier=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":id",id);
    if(ajout.exec()){
        qDebug() << "Success";
        if(Prisonniertable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return Prisonniertable;
}

void PrisonnierController::supprimerPrisonnier(QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM Prisonniers WHERE idPrisonnier=:id")){
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
    //Config::fermerConnexion(*db);
}

void PrisonnierController::affecterPrisonnier(QString id , int numCellule){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* Prisonniertable =new QSqlTableModel;
    Prisonniertable->setTable("Prisonniers");
    if(ajout.prepare("UPDATE Prisonniers set numCellule=:num WHERE idPrisonnier=:id"
                     )){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"num mech kaada tji";
    ajout.bindValue(":id",id);
    ajout.bindValue(":num",numCellule);

    if(ajout.exec()){
        qDebug() << "Success";
        if(Prisonniertable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //
}
