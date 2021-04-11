#ifndef CONFIG_H
#define CONFIG_H

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
        db->setUserName("Saif");
        db->setPassword("Esprit21");
        db->setDatabaseName("Projet2A");
        if(db->open()){
            qDebug() << "Successfully started database";
        }else{
            qDebug() << "Error";
        }
        return db;
    }
    static void fermerConnexion(QSqlDatabase& db){
        QSqlDatabase::removeDatabase("projetc++");
        db.close();
    }
};

#endif // CONFIG_H
