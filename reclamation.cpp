#include "reclamation.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "QMessageBox"
reclamation::reclamation()
{id_reclamation=0;
    id_citoyen=0;
    type_reclamation="";
}
reclamation::reclamation(int id_reclamation,int id_citoyen,QString type_reclamation,QDate date_reclamation )
{
  this->id_reclamation=id_reclamation;
  this->id_citoyen=id_citoyen;
  this->type_reclamation=type_reclamation;

  this->date_reclamation=date_reclamation;


}
bool reclamation::ajouter()
{
QSqlQuery query;
QString res   = QString::number(id_reclamation);
QString ress  = QString::number(id_citoyen);



query.prepare("INSERT INTO reclamation (id_reclamation,id_citoyen,type_reclamation,date_reclamation) "
                    "VALUES (:id_reclamation, :id_citoyen, :type_reclamation, :date_reclamation)");
query.bindValue(":id_reclamation", res);
query.bindValue(":id_citoyen", ress);
query.bindValue(":type_reclamation", type_reclamation);
query.bindValue(":date_reclamation", date_reclamation);

if(id_reclamation==  NULL || id_citoyen== NULL || type_reclamation.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}

QSqlQueryModel * reclamation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reclamation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_citoyen"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_reclamation"));

model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_reclamation"));


    return model;
}
bool reclamation::modifier()
{
    QSqlQuery query ;
QString res   = QString::number(id_reclamation);
QString ress  = QString::number(id_citoyen);


  query.prepare("update reclamation set id_reclamation='"+res+"',id_citoyen='"+ress+"',type_reclamation='"+type_reclamation+"',date_reclamation=:date_reclamation where id_reclamation='"+res+"'");
                query.bindValue(":id_reclamation",res);
                query.bindValue(":id_citoyen",ress);
                query.bindValue(":type_reclamation",type_reclamation);

                query.bindValue(":date_reclamation",date_reclamation);

                if(id_reclamation==  NULL || id_citoyen== NULL || type_reclamation.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }
                return    query.exec();
                }



bool reclamation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from reclamation where id_reclamation = :id_reclamation ");
query.bindValue(":id_reclamation", res);
return    query.exec();


}

QSqlQueryModel *reclamation:: tri_type_reclamation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from reclamation order by type_reclamation ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_reclamation"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_citoyen"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_reclamation"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_reclamation"));




    return model;
}
QSqlQueryModel * reclamation::rechercher_2(QString type_reclamation)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from reclamation where type_reclamation = '"+type_reclamation+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reclamation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_citoyen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_reclamation"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_reclamation"));


        return model;

}
//STAT
QList<QString> reclamation::listetyperec(){
    QSqlQuery query ;
    query.prepare("select DISTINCT type_reclamation from reclamation");
    query.exec();

    QList<QString> list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;
}

int reclamation::calculType(QString type){
    QSqlQuery query;
     query.prepare("select  COUNT(type_reclamation) from reclamation  WHERE type_reclamation=:type");
     query.bindValue(":type", type );
     query.exec();
      int total=0;

     while(query.next()){
       total++;

     }
     return total;
}



