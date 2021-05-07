#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arduino.h"
#include <QTimer>
#include <vehiculecontroller.h>
#include "vehicules.h"
#include <parkingcontroller.h>
#include "parking.h"
#include"citoyen.h"
#include "reclamation.h"
#include <QMainWindow>
#include<QMediaPlayer>
#include "smtp.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

#include <QMainWindow>
#include <prisonniercontroller.h>
#include "prisonnier.h"
#include <cellulecontroller.h>
#include "cellule.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString id;
    QString sessionId;
    QString status;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getCurrentId();
    QString getSessionId();
    QString getStatus();
    void showEvent(QShowEvent* event);
    void setCurrentId(QString str);
    void setSessionId(QString str);
    void setStatus(QString str);
    void setTimer();
    void setmatricule(QString);
    void setid(QString);
    void setidP(QString);
    QString getmatricule();
    QString getid();
    QString getidP();
    void setIdPr(QString);
    QString getIdPr();
    void setIdC(QString);
    QString getIdC();

private slots:
    void toggleArd();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_10_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_buttonSignIn_clicked();

    void on_pushButton_18_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_banButton_clicked();

    void on_limiterModif_clicked();

    void on_limiterEquipements_clicked();

    void on_limiterVehicules_clicked();

    void on_modifierDroits_clicked();

    void on_actionImprimer_Profils_triggered();

    void on_actionImprimer_Agents_triggered();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_modifierDroits_2_clicked();

    void on_pushButton_22_clicked();

    void on_GestionAgents_clicked();

    void on_actionConfigure_Agents_et_Profils_triggered();

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

    void on_QR_clicked();

    void on_GestionVehicules_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();
    void on_ajouter_clicked();

     void on_afficher_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_recherche_citoyen_clicked();

    void on_tri_citoyen_clicked();



    void on_ajouter_2_clicked();

    void on_afficher_2_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void sendMail();
    void mailSent(QString);


    void statrefresh();


    void on_recherche_recl_clicked();

    void on_tri_recl_clicked();

    void on_pdf_citoyen_clicked();

    void on_impr_citoyen_clicked();

    void on_pdf_reclamation_clicked();

    void on_impr_reclamation_clicked();


    void  showTime();

    void on_makeShot_clicked();

    void on_excel_2_clicked();

    void on_excel_clicked();

    void on_GestionCitoyens_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supp_clicked();

    //void on_lineEdit_chercher_cursorPositionChanged();

    void on_pushButton_29_clicked();

    void on_pushButton_inp_clicked();

    void on_pushButton_imp_clicked();

    void on_pushButton_26_clicked();

    void on_commandLinkButton_2_clicked();

    void on_pushButton_supp_2_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_commandLinkButton_3_clicked();

    //void on_pushButton_ajouter_4_clicked();

    void on_pushButton_mod_clicked();

    void on_tableView_7_clicked(const QModelIndex &index);

    void on_commandLinkButton_4_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_35_clicked();


    void on_tableView_4_clicked(const QModelIndex &index);



    //void on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2);

    //void on_tableView_5_activated(const QModelIndex &index);


    void sendMail2();

    void mailSent2(QString);

    void on_pushButton_37_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_38_clicked();

  //  void on_tableView_6_activated(const QModelIndex &index);


    void on_GestionDocuments_clicked();

    void on_tab_prisonnier_doubleClicked(const QModelIndex &index);

   // void on_pushButton_3_clicked();

    void on_tab_prisonnier_clicked(const QModelIndex &index);

   // void on_pushButton_5_clicked();

    void on_tab_cellule_doubleClicked(const QModelIndex &index);

    void on_tab_cellule_clicked(const QModelIndex &index);

   // void on_pushButton_6_clicked();

   // void on_pushButton_4_clicked();

    //void on_pushButton_12_clicked();

   // void on_pushButton_16_clicked();

   // void on_pushButton_17_clicked();

   // void on_pushButton_19_clicked();

   // void on_pushButton_18_clicked();


    void on_affect_p_clicked(const QModelIndex &index);

    void on_affect_c_clicked(const QModelIndex &index);

   // void on_affecter_clicked();

  //  void on_affecter_2_clicked();

  //  void on_pushButton_10_clicked();

  //  void on_ajouterPr_clicked();

    void on_ajouter_prisonnier_clicked();

    void on_modifier_prisonnier_clicked();

    void on_supprimer_prisonnier_clicked();

    void on_triD_prisonnier_clicked();

    void on_triC_prisonnier_clicked();

    void on_rechercher_prisonnier_clicked();

    void on_ajouter_cellule_clicked();

    void on_modifier_cellule_clicked();

    void on_supprimer_cellule_clicked();

    void on_triD_cellule_clicked();

    void on_triC_cellule_clicked();

    void on_rechercher_cellule_clicked();

    void on_affecter_prisonnier_clicked();

    //void on_affecter_p_clicked();

    void on_envoyer_prisonnier_clicked();

    void on_GestionPrisonniers_clicked();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QByteArray data;
    QTimer timer;
    Arduino A;
    VehiculeController V;
    ParkingController P;
    QString matricule;
    //QString id;
    QString idP;
    citoyen *a;
    citoyen *b;
    citoyen *o;
    citoyen *d;

    reclamation *m;
    reclamation *n;
    reclamation *p;
    reclamation *x;
    QMediaPlayer *click;

    PrisonnierController Prisionniers;
    CelluleController Cellules;
    QString idPr;
    QString idC;
};

#endif // MAINWINDOW_H
