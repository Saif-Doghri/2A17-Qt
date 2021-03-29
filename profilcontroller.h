#ifndef PROFILCONTROLLER_H
#define PROFILCONTROLLER_H
#include "profil.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class profilController{
private:
    QSqlDatabase db;
public:
    void ajouterProfil(Profil& p);
    QSqlTableModel* afficherProfils();
    void modifierProfil(Profil& p,QString id);
    QSqlTableModel* afficherProfil(QString id);
    void supprimerProfil(QString id);
};

#endif // PROFILCONTROLLER_H
