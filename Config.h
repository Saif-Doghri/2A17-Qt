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
         db->setDatabaseName("Projet2A");
         db->setPassword("SYSTEM");
         db->setUserName("SYSTEM");
         db->setPort(1215);
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
