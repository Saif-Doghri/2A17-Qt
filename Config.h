#ifndef CONFIG_H
#define CONFIG_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "QSqlDatabase"
#include <QDebug>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QException>
class Config{
private:
public:
    static QSqlDatabase* ouvrirConnexion(){
        QSqlDatabase *db= new QSqlDatabase;
        *db=QSqlDatabase::addDatabase("ODBC");
        db->setUserName("SYSTEM");
        db->setPassword("SYSTEM");
        db->setDatabaseName("projet_2A");
        if(db->open()){
            qDebug() << "Successfully started database";
        }else{
            qDebug() << "Error";
        }
        return db;
    }
    static void fermerConnexion(QSqlDatabase& db){
        QSqlDatabase::removeDatabase("projet_2A");
        db.close();
    }
};
#endif // CONFIG_H
