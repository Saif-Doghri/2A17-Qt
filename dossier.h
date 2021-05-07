#ifndef Dossier_H
#define Dossier_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Dossier
{
public:
    Dossier();
    Dossier(int,QString,QString,QString,QString);
    QString get_nom(){return nom_dos;};
    QString get_date(){return date_dos;};
    QString get_contenu(){return cont_dos;};
    QString get_prop(){return prop_dos;};
    int get_id(){return id_dos;};
    void set_nom(QString b){nom_dos=b;};
    void set_date(QString c){date_dos=c;};
    void set_contenu(QString d){cont_dos=d;};
    void set_prop(QString e){prop_dos=e;};
    void set_id(int a){id_dos=a;};
   bool ajouter(int a, QString b, QString c , QString d , QString e);
    QSqlQueryModel * afficher();
    bool supprimer(Ui::MainWindow *ui);
    QSqlQueryModel * chercher_parid(int i);
    QSqlQueryModel * triid();
    QSqlQueryModel * trinom();
    bool update_dossier(Ui::MainWindow *ui);
private:
   QString nom_dos,prop_dos,date_dos, cont_dos;
   int  id_dos;
};

#endif // Dossier_H
