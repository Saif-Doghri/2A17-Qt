#ifndef PARKINGCONTROLLER_H
#define PARKINGCONTROLLER_H
#include "parking.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class ParkingController{
private:
    QSqlDatabase db;
public:
    void ajouterParking(Parking& a);
    QSqlTableModel* afficherParkings();
    void modifierParking(Parking& a,QString id);
    QSqlTableModel* afficherParking(QString id);
    void supprimerParking(QString id);
};
#endif // PARKINGCONTROLLER_H
