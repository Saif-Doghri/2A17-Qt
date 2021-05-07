#include "document.h"

Document::Document(){

}
Document::Document(int a,QString b,QString c,QString d,QString e){
    auteur_dep=b;
    id_doc=a;
    text_doc=c;
     tit_doc=d;
   date_doc=e;
}
QSqlQueryModel * Document:: afficher_doc(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * "
                    "from DOCUMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDOC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("AUTEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TITRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATTE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEXTE"));
    return model;
}
bool Document::ajouter_doc(int a,QString b,QString c,QString d,QString e){

QSqlQuery query;
query.prepare("INSERT INTO DOCUMENT (iddoc,auteur,titre,datte,texte) "
                    "VALUES (:iddoc,:auteur,:titre,:datte,:texte)");

query.bindValue(":iddoc",a);
query.bindValue(":auteur",b);
query.bindValue(":titre",c);
query.bindValue(":datte",d);
query.bindValue(":texte",e);
return    query.exec();}



bool Document::supprimer_2(QString i ){
    QSqlQuery query;
    query.prepare("Delete from DOCUMENT where titre = :titre ");
    query.bindValue(":titre", i);
    return    query.exec();
}
QSqlQueryModel * Document::tri_nomauteur(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT iddoc,auteur,titre,datte,texte FROM DOCUMENT ORDER BY auteur DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDOC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("AUTEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TITRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATTE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEXTE"));
    return model;
}
QSqlQueryModel * Document::tri_titre(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT iddoc,auteur,titre,datte,texte FROM DOCUMENT ORDER BY titre DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDOC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("AUTEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TITRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATTE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEXTE"));
    return model;
}
QSqlQueryModel * Document:: recherche_iddoc(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;


    query.prepare("SELECT * FROM DOCUMENT WHERE iddoc LIKE :valeur order by iddoc");


    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDOC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("AUTEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TITRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATTE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEXTE"));
    return model;

}
bool Document::update_doc(Ui::MainWindow *ui){
    QSqlQuery query;
    QString b = ui->lineEdit_11->text();
    int a = ui->lineEdit_12->text().toInt();
  QString c  = ui->lineEdit_13->text();
  QString d  = ui->lineEdit_10->text();
  QString e  = ui->lineEdit_14->text();
  QString teta= QString::number(a);
    Document(a,b,c,d,e);
    query.prepare ("update Document set iddoc ='"+teta+"', auteur ='"+b+"', titre='"+c+"',datte='"+d+"',texte='"+e+"' WHERE NOM='"+teta+"'");
   return query.exec();
}
