#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prisonnier.h"
#include "cellule.h"
#include "prisonnierController.h"
#include "celluleController.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->tab_prisonnier->setModel(P.afficherPrisonniers());
    QSqlDatabase* db=Config::ouvrirConnexion();
    ui->tab_prisonnier->setSortingEnabled(true);
    ui->tab_cellule->setSortingEnabled(true);
    ui->tab_prisonnier->hideColumn(6);
    QPieSeries *series = new QPieSeries();
    PrisonnierController prisonnierP;
   QSqlTableModel *MyModelS=prisonnierP.afficherPrisonniers();
   MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1995 and 2005");
   int num=MyModelS->rowCount();
    series->append("15-25",num);
    MyModelS=prisonnierP.afficherPrisonniers();
    MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1985 and 1995");
    num=MyModelS->rowCount();
    series->append("25-35", num);
    MyModelS=prisonnierP.afficherPrisonniers();
    MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1975 and 1985");
    num=MyModelS->rowCount();
    series->append("35-45", num);
    MyModelS=prisonnierP.afficherPrisonniers();
    MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1965 and 1975");
    num=MyModelS->rowCount();
    series->append("45-55", num);
    MyModelS=prisonnierP.afficherPrisonniers();
    MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1900 and 1975");
    num=MyModelS->rowCount();
    series->append("55+",num);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Les ages des Prisonniers");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{
    PrisonnierController prisonnierP;
    QSqlTableModel* myModel=prisonnierP.afficherPrisonniers();
    this->ui->tab_prisonnier->setModel(myModel);
    CelluleController celluleC;
    QSqlTableModel* myModel1=celluleC.afficherCellules();
    this->ui->tab_cellule->setModel(myModel1);
    //ui->tab_prisonnier->hideColumn(6);
    ui->affect_p->setModel(myModel);
    ui->affect_p->hideColumn(0);
    ui->affect_p->hideColumn(3);
    ui->affect_p->hideColumn(4);
    ui->affect_p->hideColumn(5);
    ui->affect_p->hideColumn(6);
    ui->affect_c->setModel(myModel1);
    ui->affect_c->hideColumn(0);
    ui->affect_c->hideColumn(2);
    ui->affect->setModel(myModel);
    ui->affect->hideColumn(0);
    ui->affect->hideColumn(3);
    ui->affect->hideColumn(4);
    ui->affect->hideColumn(5);
    QPieSeries *series = new QPieSeries();
   QSqlTableModel *MyModelS=prisonnierP.afficherPrisonniers();
   MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1995 and 2005");
   int num=MyModelS->rowCount();
    series->append("15-25",num);
    series->append("25-35", 70);
    series->append("35-45", 50);
    series->append("45-55", 40);
    series->append("55+", 30);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Qt5 Pie Chart Example");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}

void MainWindow::on_pushButton_clicked()//bouton ajouter
{
    PrisonnierController prisonnierP;
  QString cin=ui->le_cin->text();
  QString nom=ui->le_nom->text();
  QString prenom=ui->le_prenom->text();
  QDate date=ui->le_date->date();
  QString crime=ui->le_crime->text();
  Prisonnier P(nom,prenom,crime,cin,date);
  PrisonnierController prisonnierC;
  prisonnierC.ajouterPrisonnier(P);
  QSqlTableModel* myModel=prisonnierP.afficherPrisonniers();
  this->ui->tab_prisonnier->setModel(myModel);
  ui->tab_prisonnier->hideColumn(6);
  this->ui->affect_p->setModel(myModel);
  ui->affect_p->hideColumn(0);
  ui->affect_p->hideColumn(3);
  ui->affect_p->hideColumn(4);
  ui->affect_p->hideColumn(5);
  ui->affect_p->hideColumn(6);
}


void MainWindow::on_pushButton_2_clicked()//bouton modifier
{ PrisonnierController prisonnierC;
    QString cin=ui->le_cin->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QDate date=ui->le_date->date();
    QString crime=ui->le_crime->text();
    Prisonnier P(nom,prenom,crime,cin,date);
    prisonnierC.modifierPrisonnier(P,this->getId());
    QSqlTableModel* myModel=prisonnierC.afficherPrisonniers();
    this->ui->tab_prisonnier->setModel(myModel);
//void modifierPrisonnier(Prisonnier &a, QString id);
ui->tab_prisonnier->hideColumn(6);
this->ui->affect_p->setModel(myModel);
ui->affect_p->hideColumn(0);
ui->affect_p->hideColumn(3);
ui->affect_p->hideColumn(4);
ui->affect_p->hideColumn(5);
ui->affect_p->hideColumn(6);
}

void MainWindow::setId(QString id)
{
    this->id=id;
}

QString MainWindow::getId()
{
 return this->id;
}

void MainWindow::setIdC(QString idC)
{
    this->idC=idC;
}

QString MainWindow::getIdC()
{
 return this->idC;
}
void MainWindow::on_tab_prisonnier_doubleClicked(const QModelIndex &index)
{
   PrisonnierController P;
  this->ui->le_nom->setText(P.afficherPrisonniers()->record(index.row()).value("nomPrisonnier").toString());
  this->ui->le_prenom->setText(P.afficherPrisonniers()->record(index.row()).value("prenomPrisonnier").toString());
  this->ui->le_cin->setText(P.afficherPrisonniers()->record(index.row()).value("cinPrisonnier").toString());
  this->ui->le_date->setDate(P.afficherPrisonniers()->record(index.row()).value("date_naissance_Prisonnier").toDate());
   this->ui->le_crime->setText(P.afficherPrisonniers()->record(index.row()).value("crimePrisonnier").toString());
  this->setId(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
 ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_pushButton_3_clicked()//bouton supprimer
{
   PrisonnierController prisonnierC;
   prisonnierC.supprimerPrisonnier(this->getId());
   QSqlTableModel* myModel=prisonnierC.afficherPrisonniers();
   this->ui->tab_prisonnier->setModel(myModel);
   ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_tab_prisonnier_clicked(const QModelIndex &index)
{
    PrisonnierController P;
    this->setId(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
    ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_pushButton_8_clicked()//bouton ajouter cellule
{
    CelluleController celluleC;
  int num=ui->le_num->text().toInt();
  int capacite=ui->la_capacite->text().toInt();
  Cellule C(idC,num,capacite);
  CelluleController celluleP;
  celluleP.ajouterCellule(C);
  QSqlTableModel* myModel1=celluleC.afficherCellules();
  this->ui->tab_cellule->setModel(myModel1);
  this->ui->affect_c->setModel(myModel1);
  ui->affect_c->hideColumn(0);
  ui->affect_c->hideColumn(2);
}



void MainWindow::on_pushButton_5_clicked() //bouton modifier cellule
{CelluleController celluleC;
    int capacite=ui->la_capacite->text().toInt();
    int num=ui->le_num->text().toInt();
    Cellule C(idC,num,capacite);
    celluleC.modifierCellule(C,this->getId());
    QSqlTableModel* myModel1=celluleC.afficherCellules();
    this->ui->tab_cellule->setModel(myModel1);
//void modifierCellule(Cellule &a, QString idC);
    this->ui->affect_c->setModel(myModel1);
    ui->affect_c->hideColumn(0);
    ui->affect_c->hideColumn(2);

}

void MainWindow::on_tab_cellule_doubleClicked(const QModelIndex &index) //cellule
{
    CelluleController C;
   this->ui->le_num->setText(C.afficherCellules()->record(index.row()).value("numCellule").toString());
   this->ui->la_capacite->setText(C.afficherCellules()->record(index.row()).value("capaciteCellule").toString());
   this->setIdC(C.afficherCellules()->record(index.row()).value("idCellule").toString());

}

void MainWindow::on_tab_cellule_clicked(const QModelIndex &index) //cellule
{
    CelluleController C;
    this->setId(C.afficherCellules()->record(index.row()).value("idCellule").toString());
}

void MainWindow::on_pushButton_6_clicked() // bouton supprimer cellule
{
    CelluleController celluleP;
    celluleP.supprimerCellule(this->getIdC());
    QSqlTableModel* myModel1=celluleP.afficherCellules();
    this->ui->tab_cellule->setModel(myModel1);
    this->ui->affect_c->setModel(myModel1);
    ui->affect_c->hideColumn(0);
    ui->affect_c->hideColumn(2);
}

void MainWindow::on_pushButton_4_clicked() //Tri Decroissant Prisonnier
{
    this->ui->tab_prisonnier->sortByColumn(1,Qt::DescendingOrder);
}



void MainWindow::on_pushButton_12_clicked() //Tri croissant Prisonnier
{
    this->ui->tab_prisonnier->sortByColumn(1,Qt::AscendingOrder);
}


void MainWindow::on_pushButton_16_clicked() //Tri croissant Prisonnier
{
    this->ui->tab_cellule->sortByColumn(1,Qt::DescendingOrder);
}



void MainWindow::on_pushButton_17_clicked()
{
    this->ui->tab_cellule->sortByColumn(1,Qt::AscendingOrder);
}

void MainWindow::on_pushButton_19_clicked()
{
    PrisonnierController PrisonnierP;
    QSqlTableModel* myModel=PrisonnierP.afficherPrisonniers();
    myModel->setFilter("nomPrisonnier='"+this->ui->R_prisonnier->text()+"'");
    this->ui->tab_prisonnier->setModel(myModel);
    ui->tab_prisonnier->hideColumn(6);

}

void MainWindow::on_pushButton_18_clicked()
{
    CelluleController celluleC;
    QSqlTableModel* myModel1=celluleC.afficherCellules();
    myModel1->setFilter("numCellule='"+this->ui->R_cellule->text()+"'");
    this->ui->tab_cellule->setModel(myModel1);
    ui->tab_prisonnier->hideColumn(6);
}



void MainWindow::on_affect_p_clicked(const QModelIndex &index) // affichage prisonnier dans affectation
{
    PrisonnierController P;
    this->setId(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
    ui->affect_p->hideColumn(0);
    ui->affect_p->hideColumn(3);
    ui->affect_p->hideColumn(4);
    ui->affect_p->hideColumn(5);
    ui->affect_p->hideColumn(6);
}

void MainWindow::on_affect_c_clicked(const QModelIndex &index) // affichage cellule dans affectation
{
    CelluleController C;
    this->setIdC(C.afficherCellules()->record(index.row()).value("idCellule").toString());
    ui->affect_c->hideColumn(0);
    ui->affect_c->hideColumn(2);

}



void MainWindow::on_affecter_2_clicked() // affichage affectation
{
    int num;
    CelluleController P;
    PrisonnierController C;
    QSqlTableModel *MyModel = P.afficherCellules();
    MyModel->setFilter("idCellule='"+this->getIdC()+"'");
    num=MyModel->record(0).value("numCellule").toInt();
    qDebug() <<num;
    C.affecterPrisonnier(this->getId(),num);
     QSqlTableModel *MyModel1 =C.afficherPrisonniers();
    this->ui->affect->setModel(MyModel1);
     ui->affect->hideColumn(0);
     ui->affect->hideColumn(3);
     ui->affect->hideColumn(4);
     ui->affect->hideColumn(5);

}
