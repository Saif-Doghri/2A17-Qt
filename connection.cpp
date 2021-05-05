#include "connection.h"


Connection::Connection()
{

}
bool Connection::createconnection()
{
  db=QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
       db.setUserName("bop");//inserer nom de l'utilisateur
       db.setPassword("bop");//inserer mot de passe de cet utilisateur
       bool test=false;
       if (db.open())
       test=true;

           return  test;

}
void Connection::closeConnection(){db.close();}
