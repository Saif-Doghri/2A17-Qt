#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vehiculecontroller.h>
#include "vehicules.h"
#include <parkingcontroller.h>
#include "parking.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showEvent(QShowEvent *event);
    void setmatricule(QString);
    void setid(QString);
    void setidP(QString);
    QString getmatricule();
    QString getid();
    QString getidP();

private slots:

    void on_Ajouter_clicked();


    void on_ajouterP_clicked();



    void on_table_afficher_doubleClicked(const QModelIndex &index);

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

    void on_table_p_doubleClicked(const QModelIndex &index);

    void on_modifierP_clicked();

    void on_supprimerP_clicked();

    void on_table_p_clicked(const QModelIndex &index);

    void on_trier_clicked();

    void on_trierP_clicked();

    void on_rechercher_v_clicked();

    void on_Rechercher_P_clicked();

    void on_affecter_v_clicked(const QModelIndex &index);

    void on_affecter_p_clicked(const QModelIndex &index);

    void on_affecter_clicked();

    void on_Mail_clicked();

    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    VehiculeController V;
    ParkingController P;
    QString matricule;
    QString id;
    QString idP;
};
#endif // MAINWINDOW_H
