#include "profilcontroller.h"

#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void profilController::ajouterProfil(Profil &p){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("PROFILS");
    if(ajout.prepare("INSERT INTO PROFILS(idprofil,grade,fonction,salaire,departement,date_embauche)"
                     " VALUES(:id,:grade,:fonction,:salaire,:departement,:date_embauche )")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<p.toString() << " ID: "<<p.getId() << " Departement : "<<p.getDepartement() << " Salaire : "<<p.getSalaire();
    ajout.bindValue(":id",p.getId());
    ajout.bindValue(":grade",p.getGrade());
    ajout.bindValue(":salaire",p.getSalaire());
    ajout.bindValue(":departement",p.getDepartement());
    ajout.bindValue(":fonction",p.getFonction());
    ajout.bindValue(":date_embauche",p.getDateEmbauche().toString("dd/MM/yyyy"));
    qDebug() << p.getDateEmbauche().toString("dd/MM/yyyy");
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            qDebug() << "Insertion Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* profilController::afficherProfils(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("PROFILS");
    if(ajout.prepare("SELECT * FROM PROFILS")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}

void profilController::modifierProfil(Profil &p, QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("PROFILS");
    if(ajout.prepare("UPDATE PROFILS SET grade=:grade,fonction=:fonction,departement=:departement,salaire=:salaire,date_embauche=TO_DATE(:date_embauche,'dd/MM/yyyy')"
                     " WHERE idprofil=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<p.toString();
    ajout.bindValue(":id",id);
    ajout.bindValue(":grade",p.getGrade());
    ajout.bindValue(":salaire",p.getSalaire());
    ajout.bindValue(":departement",p.getDepartement());
    ajout.bindValue(":fonction",p.getFonction());
    ajout.bindValue(":date_embauche",p.getDateEmbauche().toString("dd/MM/yyyy"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            qDebug() << "Update Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* profilController::afficherProfil(QString dept){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("PROFILS");
    if(ajout.prepare("SELECT * FROM PROFILS WHERE departement=:dept")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":dept",dept);
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->setFilter("departement='"+dept+"'");
            qDebug() << "Fetch Complete Departement = "<<dept;
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}

void profilController::supprimerProfil(QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM PROFILS WHERE idprofil=:id")){
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

QSqlTableModel* profilController::trierProfils(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("PROFILS");
    if(ajout.prepare("SELECT * FROM PROFILS ORDER BY departement ASC")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->sort(3,Qt::AscendingOrder);
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}
