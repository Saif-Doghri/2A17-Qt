#include "citoyen.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "QMessageBox"
citoyen::citoyen()
{
cin=0;
nom="";
prenom="";
adresse="";
num=0;



}

citoyen::citoyen(int cin,QString nom,QString prenom,QString adresse,int num)
{
    this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;

  this->num=num;

}

bool citoyen::ajouter()
{
QSqlQuery query;
QString res   = QString::number(cin);
QString ress   = QString::number(num);


query.prepare("INSERT INTO citoyen (cin,nom,prenom,adresse,num) "
                    "VALUES (:cin,:nom,:prenom,:adresse,:num)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":num", ress);

if(cin==  NULL || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || num== NULL)
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}

QSqlQueryModel * citoyen::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from citoyen");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));

    return model;
}
bool citoyen::modifier()
{


            QSqlQuery query ;
            QString res   = QString::number(cin);
            QString ress  = QString::number(num);


            query.prepare("update citoyen set cin='"+res+"',nom='"+nom+"',prenom='"+prenom+"',adresse='"+adresse+"',num='"+ress+"' where cin='"+res+"'");
                        query.bindValue(":cin",res);
                        query.bindValue(":nom",nom);
                        query.bindValue(":prenom",prenom);

                        query.bindValue(":adresse",adresse);
            query.bindValue(":num",ress);

            if(cin==  NULL || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || num== NULL)
            {
                QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
                     QObject::tr("Erreur champ vide!.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
                return false;
            }

                    return  query.exec();

}



bool citoyen::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from citoyen where cin = :cin ");
query.bindValue(":cin", res);


return    query.exec();


}
QSqlQueryModel *citoyen:: tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from citoyen order by nom ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));


    return model;
}

QSqlQueryModel * citoyen::rechercher(QString cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from citoyen where cin = '"+cin+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));


        return model;

}

