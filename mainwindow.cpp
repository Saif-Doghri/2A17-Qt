#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicules.h"
#include "vehiculecontroller.h"
#include "parking.h"
#include "parkingcontroller.h"
#include "QMessageBox"
#include "smtp.h"
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_afficher->setModel(V.afficherVehicules());
    ui->table_p->setModel(P.afficherParkings());
    QSqlDatabase* db=Config::ouvrirConnexion();
    ui->table_afficher->setSortingEnabled(true);
    ui->table_p->setSortingEnabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setmatricule(QString matricule)
{
    this->matricule=matricule;
}

QString MainWindow::getmatricule()
{
 return this->matricule;
}
void MainWindow::setid(QString id)
{
    this->id=id;
}
void MainWindow::setidP(QString idP)
{
    this->idP=idP;
}
QString MainWindow::getid()
{
    return this->id;
}
QString MainWindow::getidP()
{
    return this->idP;
}

void MainWindow::on_Ajouter_clicked()
{
  QString matricule=ui->matricule->text();
  QString marque=ui->marque->text();
  QString type=ui->type->text();
  QString couleur=ui->couleur->text();
  QDate date_acquisition=ui->date_acquisition->date();
  Vehicule V(matricule,marque,type,couleur,date_acquisition);
  VehiculeController VehiculeC;
  VehiculeC.ajouterVehicule(V);
  QSqlTableModel* myModel=VehiculeC.afficherVehicules();
    this->ui->table_afficher->setModel(myModel);
  this->ui->affecter_v->setModel(myModel);
}



void MainWindow::on_ajouterP_clicked()
{
    QString id=ui->id->text();
    int taille=ui->taille->text().toInt();
    int nbVehicules=ui->nbvehicules->text().toInt();
    int placesVides=ui->placesvides->text().toInt();
    Parking P(taille,nbVehicules,placesVides,id);
    ParkingController ParkingC;
    ParkingC.ajouterParking(P);
    QSqlTableModel* myModel=ParkingC.afficherParkings();
      this->ui->table_p->setModel(myModel);
    this->ui->affecter_p->setModel(myModel);
    ui->affecter_p->hideColumn(0);

    ui->affecter_p->hideColumn(1);

}
void MainWindow::showEvent(QShowEvent *event)
{
  VehiculeController VehiculeC;
   ParkingController ParkingC;
  QSqlTableModel* myModel=VehiculeC.afficherVehicules();
  QSqlTableModel* myModel2=ParkingC.afficherParkings();
  this->ui->table_afficher->setModel(myModel);
  this->ui->table_p->setModel(myModel2);
  this->ui->affecter_v->setModel(myModel);
  this->ui->affecter_p->setModel(myModel2);
  ui->affecter_p->hideColumn(0);

  ui->affecter_p->hideColumn(1);
  qDebug() <<"show_working";
}



void MainWindow::on_table_afficher_doubleClicked(const QModelIndex &index)
{
    VehiculeController V;
      this->ui->matricule->setText(V.afficherVehicules()->record(index.row()).value("matriculevehicule").toString());
      this->ui->marque->setText(V.afficherVehicules()->record(index.row()).value("marquevehicule").toString());
      this->ui->type->setText(V.afficherVehicules()->record(index.row()).value("typevehicule").toString());
      this->ui->couleur->setText(V.afficherVehicules()->record(index.row()).value("couleurvehicule").toString());
       this->ui->date_acquisition->setDate(V.afficherVehicules()->record(index.row()).value("date_acquisition").toDate());
      this->setmatricule(V.afficherVehicules()->record(index.row()).value("matriculevehicule").toString());
}

void MainWindow::on_Modifier_clicked()
{
    VehiculeController VehiculeC;
        QString matricule=ui->matricule->text();
        QString marque=ui->marque->text();
        QString type=ui->type->text();
        QString couleur=ui->couleur->text();
        QDate date_acquisition=ui->date_acquisition->date();
        Vehicule V(matricule,marque,type,couleur,date_acquisition);
        VehiculeC.modifierVehicule(V,this->getmatricule());
        QSqlTableModel* myModel=VehiculeC.afficherVehicules();
        this->ui->table_afficher->setModel(myModel);
        this->ui->affecter_v->setModel(myModel);

}

void MainWindow::on_Supprimer_clicked()
{
    VehiculeController VehiculeC;
       VehiculeC.supprimerVehicule(this->getmatricule());
       QSqlTableModel* myModel=VehiculeC.afficherVehicules();
       this->ui->table_afficher->setModel(myModel);
       this->ui->affecter_v->setModel(myModel);
}

void MainWindow::on_table_p_doubleClicked(const QModelIndex &index)
{
    ParkingController P;
      this->ui->id->setText(P.afficherParkings()->record(index.row()).value("idparking").toString());
      this->ui->taille->setText(P.afficherParkings()->record(index.row()).value("tailleparking").toString());
      this->ui->nbvehicules->setText(P.afficherParkings()->record(index.row()).value("nbVehiculesparking").toString());
      this->ui->placesvides->setText(P.afficherParkings()->record(index.row()).value("placesVidesparking").toString());
      this->setid(P.afficherParkings()->record(index.row()).value("idparking").toString());

}

void MainWindow::on_modifierP_clicked()
{
    ParkingController ParkingC;
        QString id=ui->id->text();
        int taille=ui->taille->text().toInt();
        int nbvehicules=ui->nbvehicules->text().toInt();
        int placesvides=ui->placesvides->text().toInt();
        Parking P(taille,nbvehicules,placesvides,id);
        qDebug() <<"Data Received2 : " <<P.gettaille();
        ParkingC.modifierParking(P,this->getid());
        QSqlTableModel* myModel=ParkingC.afficherParkings();
        this->ui->table_p->setModel(myModel);
        this->ui->affecter_p->setModel(myModel);
        ui->affecter_p->hideColumn(0);

        ui->affecter_p->hideColumn(1);

}

void MainWindow::on_supprimerP_clicked()
{
    ParkingController ParkingC;
       qDebug() <<"Data Received2 : " <<this->getid();
       ParkingC.supprimerParking(this->getid());
       QSqlTableModel* myModel=ParkingC.afficherParkings();
       this->ui->table_p->setModel(myModel);
       this->ui->affecter_p->setModel(myModel);
       ui->affecter_p->hideColumn(0);

       ui->affecter_p->hideColumn(1);
}



void MainWindow::on_table_p_clicked(const QModelIndex &index)
{
   this->setid(P.afficherParkings()->record(index.row()).value("idparking").toString());
}

void MainWindow::on_trier_clicked()
{
   this->ui->table_afficher->sortByColumn(0,Qt::AscendingOrder);
}

void MainWindow::on_trierP_clicked()
{
    this->ui->table_p->sortByColumn(0,Qt::AscendingOrder);
}

void MainWindow::on_rechercher_v_clicked()
{
  VehiculeController VehiculeC;
QSqlTableModel* myModel=VehiculeC.afficherVehicules();
myModel->setFilter("matriculevehicule='"+this->ui->v_search->text()+"'");
this->ui->table_afficher->setModel(myModel);
}

void MainWindow::on_Rechercher_P_clicked()
{
    ParkingController ParkingC;
  QSqlTableModel* myModel=ParkingC.afficherParkings();
  myModel->setFilter("idparking='"+this->ui->p_search->text()+"'");
  this->ui->table_p->setModel(myModel);
}

void MainWindow::on_affecter_v_clicked(const QModelIndex &index)
{
    VehiculeController V;

        this->setmatricule(V.afficherVehicules()->record(index.row()).value("matriculevehicule").toString());

}

void MainWindow::on_affecter_p_clicked(const QModelIndex &index)
{
    ParkingController P;

        this->setidP(P.afficherParkings()->record(index.row()).value("idparking").toString());

        ui->affecter_p->hideColumn(0);

        ui->affecter_p->hideColumn(1);
}

void MainWindow::on_affecter_clicked()
{
    QString id;

        ParkingController P;

        VehiculeController V;

        QSqlTableModel *MyModel = P.afficherParkings();

        MyModel->setFilter("idparking='"+this->getidP()+"'");

        id=MyModel->record(0).value("idparking").toString();

        qDebug() <<id;
        if(MyModel->record(0).value("placesVidesparking").toInt()>0)
        {
        V.affecterVehicule(this->getmatricule(),id);
        QSqlTableModel *MyModel1 =V.afficherVehicules();
        QSqlTableModel *MyModel2 =P.afficherParkings();
        MyModel2->setFilter("idparking='"+this->getidP()+"'");
       this->ui->affecter_p_v->setModel(MyModel1);
        MyModel2->setData(MyModel2->index(0,2),MyModel2->record(0).value("placesVidesparking").toInt()-1);
        MyModel2->submitAll();
        this->ui->affecter_p_v->setModel(MyModel1);
        this->ui->affecter_p->setModel(MyModel2);
        }
        else {
        QMessageBox* newMessage=new QMessageBox();
        newMessage->warning(this,"pas de place vide","pas de place vide");
        newMessage->exec();

        }




}

void MainWindow::on_Mail_clicked()
{ Smtp* smtp;
    smtp = new Smtp("yyass1215@gmail.com", "Piecegeretout24%", "smtp.gmail.com");
    //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

    smtp->sendMail("yyass1215@gmail.com", "yyass1215@gmail.com" , "alerte d'inactivité","la vehicule avec la matricule "+this->getmatricule()+ "est inactive,veuillez prendre en consideration cette inactivité. \nCordialement ");
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            QString fileName =QFileDialog::getSaveFileName(this, "Enregistrer les vehicules", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);
             int rowCount = ui->table_afficher->model()->rowCount();
             int columnCount = ui->table_afficher->model()->columnCount();
            QString dateProfils = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - PROFILES LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> LISTE DES PROFILS </strong></h1>"
                "<h5 style=\"text-align: center;\">Le : "+dateProfils+"</h5>"
                "<br>\n"
                "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
                  "</br> </br>";
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->table_afficher->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->table_afficher->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->table_afficher->isColumnHidden(column)) {
                        QString data =ui->table_afficher->model()->data(ui->table_afficher->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.print(&printer);
}
