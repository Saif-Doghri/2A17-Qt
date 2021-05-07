#ifndef CELLULECONTROLLER_H
#define CELLULECONTROLLER_H

#include "cellule.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class CelluleController{
private:
    QSqlDatabase db;
public:
    void ajouterCellule(Cellule& a);
    QSqlTableModel* afficherCellules();
    void modifierCellule(Cellule& a,QString idC);
    QSqlTableModel* afficherCellule(QString idC);
    void supprimerCellule(QString idC);
};


#endif // CELLULECONTROLLER_H
