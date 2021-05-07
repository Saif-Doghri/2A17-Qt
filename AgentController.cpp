#include "AgentController.h"
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
void AgentController::ajouterAgent(Agent &a){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("INSERT INTO Agents(idagent,nomagent,prenomagent,passwordAgent,ageagent,cinagent,date_naissance_agent)"
                     " VALUES(:id,:nom,:prenom,:mdp,:age,:cin,TO_DATE(:date_naissance,'YYYY/MM/dd'))")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":id",a.getId());
    ajout.bindValue(":nom",a.getNom());
    ajout.bindValue(":prenom",a.getPrenom());
    ajout.bindValue(":age",a.getAge());
    ajout.bindValue(":cin",a.getCIN());
    ajout.bindValue(":mdp",a.getMdp());
    ajout.bindValue(":date_naissance",a.getDate().toString("yyyy/MM/dd"));
    //qDebug() << "Date Format = "<<a.getDate().toString("yyyy/MM/dd");
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            qDebug() << "Insertion Complete";
            QMessageBox * message =new QMessageBox();
            message->setText("Agent ajoute avec succes");
            message->exec();
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* AgentController::afficherAgents(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("SELECT * FROM Agents")){
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

void AgentController::modifierAgent(Agent &a, QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("UPDATE Agents SET nomagent=:nom,prenomagent=:prenom,passwordAgent=:mdp,ageagent=:age,cinagent=:cin,date_naissance_agent=TO_DATE(:date_naissance,'YYYY/MM/dd')"
                     " WHERE idagent=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    qDebug() <<"Data Received : " <<a.ToString();
    ajout.bindValue(":id",id);
    ajout.bindValue(":nom",a.getNom());
    ajout.bindValue(":prenom",a.getPrenom());
    ajout.bindValue(":age",a.getAge());
    ajout.bindValue(":cin",a.getCIN());
    ajout.bindValue(":mdp",a.getMdp());
    ajout.bindValue(":date_naissance",a.getDate().toString("yyyy/MM/dd"));
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            qDebug() << "Update Complete";
            qDebug() << "Insertion Complete";
            QMessageBox * message =new QMessageBox();
            message->setText("Agent modifie avec succes");
            message->exec();
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* AgentController::afficherAgent(QString nom){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("SELECT * FROM Agents WHERE nomagent=:nom")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":nom",nom);
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->setFilter("nomagent='"+nom+"'");
            qDebug() << "Fetch Complete";
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}

void AgentController::supprimerAgent(QString id){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    if(ajout.prepare("DELETE FROM Agents WHERE idagent=:id")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
    ajout.bindValue(":id",id);
    if(ajout.exec()){
        qDebug() << "Success";
        qDebug() << "Delete Complete";
        qDebug() << "Insertion Complete";
        QMessageBox * message =new QMessageBox();
        message->setText("Agent supprime avec succes");
        message->exec();
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
}

QSqlTableModel* AgentController::trierAgents(){
    //QSqlDatabase* db=Config::ouvrirConnexion();
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("SELECT * FROM Agents ORDER BY nomagent ASC")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }

    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->sort(1,Qt::AscendingOrder);
            qDebug() << "Sort Complete";
            qDebug() << "Insertion Complete";
            QMessageBox * message =new QMessageBox();
            message->setText("Liste des Agents trie avec succes");
            message->exec();
        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}

QSqlTableModel* AgentController::authenticateAgent(QString nom,QString mdp){
    QSqlQuery ajout;
    QSqlTableModel* agenttable =new QSqlTableModel;
    agenttable->setTable("Agents");
    if(ajout.prepare("SELECT * FROM Agents where nomagent=:nom and passwordagent=:mdp")){
            qDebug() << "Query Prepared";
    }else{
        qDebug() << "Failed to Prepare Query";
    }
 ajout.bindValue(":nom",nom);
  ajout.bindValue(":mdp",mdp);
    if(ajout.exec()){
        qDebug() << "Success";
        if(agenttable->select()){
            agenttable->setFilter("nomagent='"+nom+"' and passwordAgent='"+mdp+"'");
            qDebug() << "Search Complete" <<agenttable->record(0).value("nomagent");

        }
    }else{
        qDebug() << ajout.executedQuery();
        qDebug() <<ajout.lastError().text();
    }
    //Config::fermerConnexion(*db);
    return agenttable;
}
