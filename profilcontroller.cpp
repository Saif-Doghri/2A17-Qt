#include "profilcontroller.h"

#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void profilController::ajouterProfil(Profil &p){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("profils");
    if(ajout.prepare("INSERT INTO profils(idprofil,grade,fonction,salaire,departement,date_embauche)"
                     " VALUES(:id,:grade,:fonction,:salaire,:departement,:date_embauche)")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<p.toString();
    ajout.bindValue(":id",p.getId());
    ajout.bindValue(":grade",p.getGrade());
    ajout.bindValue(":salaire",p.getSalaire());
    ajout.bindValue(":departement",p.getDepartement());
    ajout.bindValue(":fonction",p.getFonction());
    ajout.bindValue(":date_embauche",p.getDateEmbauche().toString("yyyy-MM-dd"));
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
    agenttable->setTable("profils");
    if(ajout.prepare("SELECT * FROM profils")){
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
    agenttable->setTable("profils");
    if(ajout.prepare("UPDATE profils SET grade=:grade,fonction=:fonction,departement=:departement,salaire=:salaire,date_embauche=:date_embauche"
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
    ajout.bindValue(":date_embauche",p.getDateEmbauche().toString("yyyy-MM-dd"));
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
    agenttable->setTable("profils");
    if(ajout.prepare("SELECT * FROM profils WHERE departement=:dept")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":dept",dept);
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->setFilter("departement='"+dept+"'");
            qDebug() << "Fetch Complete";
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
    if(ajout.prepare("DELETE FROM profils WHERE idprofil=:id")){
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
    agenttable->setTable("profils");
    if(ajout.prepare("SELECT * FROM profils")){
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
