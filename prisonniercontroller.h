#ifndef PRISONNIERCONTROLLER_H
#define PRISONNIERCONTROLLER_H
#include "prisonnier.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class PrisonnierController{
private:
    QSqlDatabase db;
public:
    void ajouterPrisonnier(Prisonnier& a);
    QSqlTableModel* afficherPrisonniers();
    void modifierPrisonnier(Prisonnier& a,QString id);
    QSqlTableModel* afficherPrisonnier(QString id);
    void supprimerPrisonnier(QString id);
    QSqlTableModel* trierPrisonniers();
    void affecterPrisonnier(QString id,int numCellule);
};
#endif // PRISONNIERCONTROLLER_H
