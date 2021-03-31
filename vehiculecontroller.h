#ifndef VEHICULECONTROLLER_H
#define VEHICULECONTROLLER_H
#include "vehicules.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class VehiculeController{
private:
    QSqlDatabase db;
public:
    void ajouterVehicule(Vehicule& a);
    QSqlTableModel* afficherVehicules();
    void modifierVehicule(Vehicule& a,QString matricule);
    QSqlTableModel* afficherVehicule(QString matricule);
    void supprimerVehicule(QString matricule);
};

#endif // VEHICULECONTROLLER_H
