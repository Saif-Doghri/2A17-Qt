#include "dossier.h"

Dossier::Dossier(){

}
Dossier::Dossier(int a, QString b, QString c,QString d,QString e){
  id_dos=a;
  nom_dos=b;
  date_dos=c;
  cont_dos=d;
  prop_dos=e;

}
//ajouter fonction
bool Dossier::ajouter(int a, QString b, QString c , QString d , QString e)
{
QSqlQuery query;
query.prepare("INSERT INTO DOSSIER (iddos,nom,datte,contenu,prop) "
                    "VALUES (:iddos,:nom,:datte,:contenu,:prop)");

query.bindValue(":iddos",a);
query.bindValue(":nom",b);
query.bindValue(":datte",c);
query.bindValue(":contenu",d);
query.bindValue(":prop",e);

return query.exec();
}
//afficher
QSqlQueryModel * Dossier::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * "
                "from DOSSIER");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("contenu"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("proprietere"));

return model;
}
bool Dossier::supprimer(Ui::MainWindow *ui)
{
    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM DOSSIER WHERE IDDOS ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM DOSSIER WHERE IDDOS ='"+ref+"'");
        return q.exec();
    }
    else{
        return false;
    }


}


QSqlQueryModel * Dossier::chercher_parid(int i)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(i);
    model->setQuery("select * from DOSSIER where (iddos LIKE'"+res+"%') ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("contenu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("proprietere"));

    return model;
}
QSqlQueryModel * Dossier::triid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT *"
                    "FROM DOSSIER ORDER BY iddos DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("contenu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("proprietere"));
    return model;
}
QSqlQueryModel * Dossier::trinom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT *"
                    " FROM DOSSIER ORDER BY nom DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("contenu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("proprietere"));

    return model;
}
bool Dossier::update_dossier(Ui::MainWindow *ui){
    QSqlQuery query;
    int a = ui->lineEdit->text().toInt();
    QString b = ui->lineEdit_5->text();
    QString c = ui->lineEdit_6->text();
    QString d = ui->lineEdit_7->text();
    QString e = ui->lineEdit_8->text();
   QString teta= QString::number(a);

   Dossier(a,b,c,d,e);
    query.prepare ("update Dossier set IDDOS ='"+teta+"', NOM='"+b+"', datte='"+c+"',contenu ='"+d+"',prop ='"+e+"' WHERE iddos ='"+teta+"'");
   return query.exec();

 }
