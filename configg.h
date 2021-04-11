#ifndef CONFIG_H
#define CONFIG_H
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include "QSqlDatabase"
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QString>
#include<QException>
class Config{
private:
public:
    static QSqlDatabase* ouvrirConnexion(){
        QSqlDatabase *db= new QSqlDatabase;
        *db=QSqlDatabase::addDatabase("QODBC");
        db->setUserName("Youssef");
        db->setPassword("esprit21");
        db->setDatabaseName("Source_Projet2A");
        if(db->open()){
            qDebug() << "Successfully started database";
        }else{
            qDebug() << "Error";
        }
        return db;
    }
    static void fermerConnexion(QSqlDatabase& db){
        QSqlDatabase::removeDatabase("Source_Projet2A");
        db.close();
    }
};

#endif // CONFIG_H
