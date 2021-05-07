#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
class Document
{
public:
    Document();
    Document(int a,QString b,QString c,QString d,QString e);
    QString get_auteurdoc(){return auteur_dep;};
    int get_iddoc(){return id_doc;}
    QString get_textdoc(){return text_doc;}
    QString get_titdoc(){return tit_doc;};
    QString get_datedoc(){return date_doc;};
    void set_auteurdoc(QString b){ auteur_dep=b;};
    void set_iddoc(int a){id_doc=a;};
    void set_textdoc(QString c){ text_doc=c;}
    void set_titdoc(QString d){ tit_doc=d;};
    void set_datedoc(QString e){ date_doc=e;};
    QSqlQueryModel * afficher_doc();
    bool ajouter_doc(int a,QString b,QString c,QString d,QString e);
    bool supprimer_2(QString i );
    QSqlQueryModel * tri_nomauteur();
    QSqlQueryModel * tri_titre();
    QSqlQueryModel * recherche_iddoc(QString valeur);
    bool update_doc(Ui::MainWindow *ui);
private:

  QString  auteur_dep,tit_doc,date_doc,text_doc;
  int id_doc;
};

#endif // DOCUMENT_H
