#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AgentController.h"
#include "Agent.h"
#include "profil.h"
#include "profilcontroller.h"
#include <QMessageBox>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include "qr.h"
#include <QTimer>
#include <QRegularExpression>
#include "vehicules.h"
#include "vehiculecontroller.h"
#include "parking.h"
#include "parkingcontroller.h"
#include "smtp.h"
#include"citoyen.h"
#include"reclamation.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include <QPixmap>
#include <QIntValidator>
#include <QTableView>
#include <QPainter>
#include <QPdfWriter>
#include"QTextDocumentWriter"
#include <QTextStream>
#include"QDesktopServices"
#include <QFileDialog>
#include <QPrinter>
#include"QFont"
#include"QPen"
#include <QPainter>
#include <QTextDocument>
#include <QDate>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QResizeEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QListWidget>
#include <QKeyEvent>
#include <QSound>
#include <QFile>
#include <QMediaPlayer>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>

#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include<QGridLayout>
#include "exportexcelobjet.h"
#include <QTimer>
#include <QDateTime>
//#include "secdialog.h"
#include "dossier.h"
#include <QTableWidget>
#include <QTableView>
#include<QMessageBox>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrinterInfo>
#include "document.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
    int res=A.connect_arduino();
    if(res==-1){
        qDebug()<<"Arduino not Connected";
        exit(-1);
    }else if(res==1){
        qDebug()<<"Arduino Found but not Connected";
        exit(1);
    }else{
        qDebug()<<"Arduino Connected Successfully";
    }
    setTimer();*/
    //
    ui->setupUi(this);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->tableView->setSortingEnabled(true);
    ui->tableView_2->setSortingEnabled(true);
    QSqlDatabase *db=Config::ouvrirConnexion();
    this->status="";
    ui->label_21->setStyleSheet("QLabel {color : black;}");
    ui->label_22->setStyleSheet("QLabel {color : black;}");
    /*ui->table_afficher->setModel(V.afficherVehicules());
    ui->table_p->setModel(P.afficherParkings());*/
    ui->table_afficher->setSortingEnabled(true);
    ui->table_p->setSortingEnabled(true);
    connect(ui->GestionAgents,SIGNAL(clicked()),this,SLOT(on_GestionAgents_clicked()));
    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start();
    click=new QMediaPlayer();
        click->setMedia(QUrl("qrc:/click.mp3"));
        //statrefresh();
        QStringList listrec;
        listrec << "meurte" << "suicide" << "accident" << "etronglement";
        ui->comboBox_aj_type->addItems(listrec);
        ui->mod_type->addItems(listrec);
        QIntValidator *cin = new QIntValidator(1,99999999);
        QIntValidator *num = new QIntValidator(1,9999);
        ui->aj_cin->setValidator(cin);
        ui->mod_cin->setValidator(cin);
        ui->aj_recl->setValidator(num);
        ui->mod_recl->setValidator(num);
        ui->aj_cit->setValidator(num);
        ui->mod_cit->setValidator(num);
        QPropertyAnimation * animation = new QPropertyAnimation(ui->animation, "geometry");
            animation->setDuration(10000);
            animation->setLoopCount(-1);
            animation->setStartValue(QRect(-20, 10, 371, 71));
            animation->setEndValue(QRect(1050, 10, 371, 71));
            animation->start();
            connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
            connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
            connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail2()));
            connect(ui->exitBtn_2, SIGNAL(clicked()),this, SLOT(close2()));
            ui->tab_prisonnier->setSortingEnabled(true);
            ui->tab_cellule->setSortingEnabled(true);
            ui->tab_prisonnier->hideColumn(6);
            QPieSeries *series = new QPieSeries();
            PrisonnierController prisonnierP;
           QSqlTableModel *MyModelS=prisonnierP.afficherPrisonniers();
           MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1995 and 2005");
           int num1=MyModelS->rowCount();
            series->append("15-25",num1);
            MyModelS=prisonnierP.afficherPrisonniers();
            MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1985 and 1995");
            num1=MyModelS->rowCount();
            series->append("25-35", num1);
            MyModelS=prisonnierP.afficherPrisonniers();
            MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1975 and 1985");
            num1=MyModelS->rowCount();
            series->append("35-45", num1);
            MyModelS=prisonnierP.afficherPrisonniers();
            MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1965 and 1975");
            num1=MyModelS->rowCount();
            series->append("45-55", num1);
            MyModelS=prisonnierP.afficherPrisonniers();
            MyModelS->setFilter("TO_NUMBER(extract(year from date_naissance_Prisonnier)) between 1900 and 1975");
            num1=MyModelS->rowCount();
            series->append("55+",num1);

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

QString MainWindow::getCurrentId(){
    return this->id;
}

void MainWindow::setCurrentId(QString str){
    this->id=str;
}

QString MainWindow::getSessionId(){
    return this->sessionId;
}

void MainWindow::setSessionId(QString str){
    this->sessionId=str;
}

QString MainWindow::getStatus(){
    return this->status;
}

void MainWindow::setStatus(QString str){
    this->status=str;
}

void MainWindow::showEvent(QShowEvent* event){
    this->ui->stackedWidget->setCurrentIndex(0);
    this->ui->subwindow->setFixedSize(QSize(ui->mdiArea->width(),ui->mdiArea->height()));

}

void MainWindow::on_pushButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(this->ui->stackedWidget->currentIndex()-1);
    AgentController agentc;
    QSqlTableModel *agenttable=agentc.afficherAgents();
    this->ui->tableView->setModel(agenttable);
    //mylayout->addWidget(agentlist);
    this->ui->tableView->horizontalHeader()->setStretchLastSection(true);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->model()->setHeaderData(1,Qt::Horizontal,tr("Nom"));
    this->ui->tableView->model()->setHeaderData(2,Qt::Horizontal,tr("Prenom"));
    this->ui->tableView->model()->setHeaderData(3,Qt::Horizontal,tr("Mot de Passe"));
    this->ui->tableView->model()->setHeaderData(4,Qt::Horizontal,tr("Age"));
    this->ui->tableView->model()->setHeaderData(5,Qt::Horizontal,tr("CIN"));
    this->ui->tableView->model()->setHeaderData(6,Qt::Horizontal,tr("Date Naissance"));
    this->ui->tableView->model()->setHeaderData(7,Qt::Horizontal,tr("Droits"));
    this->ui->tableView->hideColumn(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(this->ui->stackedWidget->currentIndex()+1);
}

void MainWindow::on_pushButton_3_clicked()
{
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idagent='"+this->getSessionId()+"'");
    qDebug() << mymodel->record(0).value("droitAccesAgent").toString();
    if(mymodel->record(0).value("droitAccesAgent").toString()!="LimiteModif"){
        this->ui->stackedWidget->setCurrentIndex(this->ui->stackedWidget->currentIndex()+2);
    }else{
        QMessageBox * newmessage=new QMessageBox();
        newmessage->warning(this,"Limited Access","Limited Rights");
    }
}

void MainWindow::on_pushButton_6_clicked()
{

    bool ajout=true;
    QRegularExpression mdpreg("^(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}$");
    QRegularExpression nomreg("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
    QRegularExpression cinreg("(?<!\\d)\\d{8}(?!\\d)");
   // QRegularExpression agereg("^(0?[1-9]|[1-9][0-9]|[1][1-9][1-9]|200)$");
    QString Nom=this->ui->nom->text();
    if(!nomreg.match(Nom).hasMatch()){
        ui->nomErrorAjout->setText("Le Nom doit etre compose que de lettres!");
        ui->nomErrorAjout->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->nomErrorAjout->setText("");
    }
    QString Prenom=this->ui->prenom->text();
    if(!nomreg.match(Prenom).hasMatch()){
        ui->PrenomErrorAjout->setText("Le Prenom doit etre compose que de lettres!");
        ui->PrenomErrorAjout->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->PrenomErrorAjout->setText("");
    }
    QString Cin=this->ui->cin->text();
    if(!cinreg.match(Cin).hasMatch()){
        ui->CINErrorAjout->setText("Le CIN doit etre compose de 8 Chiffres!");
        ui->CINErrorAjout->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->CINErrorAjout->setText("");
    }
    QString Mdp=this->ui->mdp->text();
    if(!mdpreg.match(Mdp).hasMatch()){
        ui->MdpErrorAjout2->setText("Le Mdp doit etre compose de 8 caracteres avec une lettre speciale et un chiffre au minimum!");
        ui->MdpErrorAjout2->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->MdpErrorAjout2->setText("");
    }
    int Age=this->ui->age->text().toInt();
    if(!(typeid(Age)==typeid (int) && (Age >18 && Age <60))){
        ui->AgeErrorAjout->setText("L Age doit etre compose que de chiffres >17 et <61!");
        ui->AgeErrorAjout->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->AgeErrorAjout->setText("");
    }
    QDate dateNaissance=this->ui->dateEdit->date();
    Agent agent(Nom,Prenom,Age,Cin,Mdp,dateNaissance);
    AgentController agentc;
    if(ajout){
        agentc.ajouterAgent(agent);
        this->ui->tableView->setModel(agentc.afficherAgents());
        this->ui->stackedWidget->setCurrentIndex(1);
    }

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    AgentController agentc;
        this->setCurrentId(agentc.afficherAgents()->record(index.row()).value("idagent").toString());
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idagent='"+this->getSessionId()+"'");
        if(mymodel->record(0).value("droitAccesAgent").toString()!="LimiteModif"){
        this->ui->nomModif->setText(agentc.afficherAgents()->record(index.row()).value("nomagent").toString()) ;
        this->ui->prenomModif->setText(agentc.afficherAgents()->record(index.row()).value("prenomagent").toString()) ;
        this->ui->cinModif->setText(agentc.afficherAgents()->record(index.row()).value("cinagent").toString()) ;
        this->ui->ageModif->setText(agentc.afficherAgents()->record(index.row()).value("ageagent").toString()) ;
        this->ui->dateNaissanceModif->setDate(agentc.afficherAgents()->record(index.row()).value("date_naissance_agent").toDate());
        this->ui->mdpModif->setText(agentc.afficherAgents()->record(index.row()).value("passwordAgent").toString());
        this->setCurrentId(agentc.afficherAgents()->record(index.row()).value("idagent").toString());
        this->ui->stackedWidget->setCurrentIndex(4);
        }else{
            QMessageBox * newmessage=new QMessageBox();
            newmessage->warning(this,"Limited Access","Limited Rights");
        }
}

void MainWindow::on_pushButton_7_clicked()
{
    bool ajout=true;
    QRegularExpression mdpreg("^(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}$");
    QRegularExpression nomreg("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
    QRegularExpression cinreg("(?<!\\d)\\d{8}(?!\\d)");
    QString newnom=this->ui->nomModif->text();
    if(nomreg.match(newnom).hasMatch()){
        ui->nomErrorModif->setText("Le Nom doit etre compose que de lettres!");
        ui->nomErrorModif->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
         ui->nomErrorModif->setText("");
    }
    QString newprenom=this->ui->prenomModif->text();
    if(nomreg.match(newprenom).hasMatch()){
        ui->PrenomErrorModif->setText("Le Prenom doit etre compose que de lettres!");
        ui->PrenomErrorModif->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
         ui->PrenomErrorModif->setText("");
    }
    QString newcin=this->ui->cinModif->text();
    if(cinreg.match(newcin).hasMatch()){
        ui->CINErrorModif->setText("Le CIN doit etre compose de 8 chiffres!");
        ui->CINErrorModif->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
         ui->CINErrorModif->setText("");
    }
    QString newmdp=this->ui->mdpModif->text();
    if(mdpreg.match(newmdp).hasMatch()){
        ui->MdpErrorModif2->setText("Le Mdp doit etre compose de 8 caracteres dont 1 special et 1 Majus et 1 Chiffre!");
        ui->MdpErrorModif2->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
         ui->MdpErrorModif2->setText("");
    }
    int newage=this->ui->ageModif->text().toInt();
    if(!(typeid(newage)==typeid (int) && (newage >18 && newage <60))){
        ui->AgeErrorModif->setText("L Age doit etre compose que de chiffres >17 et <61!");
        ui->AgeErrorModif->setStyleSheet("QLabel  {color : red; }");
        ajout=false;
    }else{
        ui->AgeErrorModif->setText("");
    }
    QDate newdateNaissance=this->ui->dateNaissanceModif->date();
    Agent agent(newnom,newprenom,newage,newcin,newmdp,newdateNaissance);
    AgentController agentc;
    if(ajout){
        agentc.modifierAgent(agent,this->getCurrentId());
        QSqlTableModel *agenttable=agentc.afficherAgents();
        this->ui->tableView->setModel(agenttable);
        this->ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idagent='"+this->getSessionId()+"'");
    if(mymodel->record(0).value("droitAccesAgent").toString()!="LimiteModif"){
        agentc.supprimerAgent(this->getCurrentId());
        QSqlTableModel *agenttable=agentc.afficherAgents();
        this->ui->tableView->setModel(agenttable);
    }else{
        QMessageBox * newmessage=new QMessageBox();
        newmessage->warning(this,"Limited Access","Limited Rights");
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_13_clicked()
{
    bool ajout=true;
    QRegularExpression allreg("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
    QString fonction = this->ui->fonction->text();
    if(!allreg.match(fonction).hasMatch()){
        ajout=false;
        ui->fonctionAjoutError->setText("la fonction consiste seulement de lettres!");
        ui->fonctionAjoutError->setStyleSheet("QLabel {color:red;}");
    }else{
        ui->fonctionAjoutError->setText("");

    }
    QString grade = this->ui->grade->text();
    if(!allreg.match(grade).hasMatch()){
        ajout=false;
        ui->gradeAjoutError->setText("la grade consiste seulement de lettres!");
        ui->gradeAjoutError->setStyleSheet("QLabel {color:red;}");
    }else{
        ui->gradeAjoutError->setText("");

    }
    QString dept= this->ui->departement->text();
    if(!allreg.match(dept).hasMatch()){
        ajout=false;
        ui->departementAjoutError->setText("la fonction consiste seulement de lettres!");
        ui->departementAjoutError->setStyleSheet("QLabel {color:red;}");
    }else{
        ui->departementAjoutError->setText("");
    }
    int salaire = this->ui->salaire->text().toInt();
    if(!(salaire>0 && typeid(salaire)==typeid(int))){
        ajout=false;
        ui->salaireAjoutError->setText("Salaire doit etre >0");
        ui->salaireAjoutError->setStyleSheet("QLabel {color:red;}");
    }
    QDate dateEmbauche = this->ui->dateEmbauche->date();
    Profil profil(salaire,grade,fonction,dateEmbauche,dept);
    profilController profilc;
    if(ajout==true){
        profilc.ajouterProfil(profil);
        QSqlTableModel *profiltable=profilc.afficherProfils();
        this->ui->tableView_2->setModel(profiltable);
        this->ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
    profilController profilc;
    QSqlTableModel *profiltable=profilc.afficherProfils();
    this->ui->tableView_2->setModel(profiltable);
    //mylayout->addWidget(agentlist);
    this->ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    this->ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView_2->model()->setHeaderData(1,Qt::Horizontal,tr("Fonction"));
    this->ui->tableView_2->model()->setHeaderData(2,Qt::Horizontal,tr("Grade"));
    this->ui->tableView_2->model()->setHeaderData(3,Qt::Horizontal,tr("Departement"));
    this->ui->tableView_2->model()->setHeaderData(4,Qt::Horizontal,tr("Date Embauche"));
    this->ui->tableView_2->model()->setHeaderData(5,Qt::Horizontal,tr("Salaire"));
    this->ui->tableView_2->hideColumn(0);
  }

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    profilController profilc;
    this->ui->fonctionModif->setText(profilc.afficherProfils()->record(index.row()).value("fonction").toString()) ;
    this->ui->gradeModif->setText(profilc.afficherProfils()->record(index.row()).value("grade").toString()) ;
    this->ui->departementModif->setText(profilc.afficherProfils()->record(index.row()).value("departement").toString()) ;
    this->ui->salaireModif->setText(profilc.afficherProfils()->record(index.row()).value("salaire").toString()) ;
    this->ui->dateEmbaucheModif->setDate(profilc.afficherProfils()->record(index.row()).value("date_embauche").toDate());
    this->setCurrentId(profilc.afficherProfils()->record(index.row()).value("idprofil").toString());
    this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_12_clicked()
{
    AgentController agentc;
    profilController profilc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idagent='"+this->getSessionId()+"'");
    if(mymodel->record(0).value("droitAccesAgent").toString()!="LimiteModif"){
        profilc.supprimerProfil(this->getCurrentId());
        QSqlTableModel *profiltable=profilc.afficherProfils();
        this->ui->tableView_2->setModel(profiltable);
    }else{
        QMessageBox * newmessage=new QMessageBox();
        newmessage->warning(this,"Limited Access","Limited Rights");
    }
}




void MainWindow::on_pushButton_10_clicked()
{
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idagent='"+this->getSessionId()+"'");
    if(mymodel->record(0).value("droitAccesAgent").toString()!="LimiteModif"){
        this->ui->stackedWidget->setCurrentIndex(6);
    }else{
        QMessageBox * newmessage=new QMessageBox();
        newmessage->warning(this,"Limited Access","Limited Rights");
    }
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    profilController profilc;
        this->setCurrentId(profilc.afficherProfils()->record(index.row()).value("idprofil").toString());
}

void MainWindow::on_pushButton_11_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_15_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_16_clicked()
{
    bool ajout=true;
    QRegularExpression allreg("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
    QString newfonction=this->ui->fonctionModif->text();
    if(!allreg.match(newfonction).hasMatch()){
        ajout=false;
        ui->fonctionModifError->setText("la fonction consiste seulement de lettres!");
        ui->fonctionModifError->setStyleSheet("QLabel {recolor:red;}");
    }else{
        ui->fonctionModifError->setText("");

    }
    QString newgrade=this->ui->gradeModif->text();
    if(!allreg.match(newgrade).hasMatch()){
        ajout=false;
        ui->gradeModifError->setText("la grade consiste seulement de lettres!");
        ui->gradeModifError->setStyleSheet("QLabel {color:red;}");
    }else{
        ui->gradeModifError->setText("");

    }
    QString newdepartement=this->ui->departementModif->text();
    if(!allreg.match(newdepartement).hasMatch()){
        ajout=false;
        ui->departementModifError->setText("le departement consiste seulement de lettres!");
        ui->departementModifError->setStyleSheet("QLabel {color:red;}");
    }else{
        ui->departementModifError->setText("");

    }
    int newsalaire=this->ui->salaireModif->text().toInt();
    if(!(typeid (newsalaire)==typeid (newsalaire) && newsalaire>0)){
        ajout=false;
        ui->salaireModifError->setText("Salaire doit etre > 0");
        ui->salaireModifError->setStyleSheet("QLabel {color:red;}");
    }
    QDate newdateEmbauche=this->ui->dateEmbaucheModif->date();
    Profil profil(newsalaire,newgrade,newfonction,newdateEmbauche,newdepartement);
    profilController profilc;
    if(ajout==true){
        profilc.modifierProfil(profil,this->getCurrentId());
        QSqlTableModel *profiltable=profilc.afficherProfils();
        this->ui->tableView_2->setModel(profiltable);
        this->ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_17_clicked()
{
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    if(this->ui->search_agent->text()!=""){
        mymodel=agentc.afficherAgent(this->ui->search_agent->text());
        //mymodel->setFilter("nomagent='"+this->ui->search_agent->text()+"'");
    }
    this->ui->tableView->setModel(mymodel);
}

void MainWindow::on_buttonSignIn_clicked()
{
    QString nomAgent=this->ui->nomSignIN->text();
    QString mdpAgent=this->ui->mdpSignIn->text();
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.authenticateAgent(nomAgent,mdpAgent);
    qDebug() <<mymodel->record(0).value("nomagent").toString();
    if(mymodel->rowCount()==0){
            QMessageBox * newmessage1=new QMessageBox(this);
            newmessage1->setModal(true);
            newmessage1->setText("Wrong Data");
            newmessage1->exec();
   }else{
            if(mymodel->record(0).value("droitAccesAgent")=="Banned"){
                QMessageBox* newmessage=new QMessageBox(this);
                newmessage->critical(this,"Banned User","Banned User");
            }else if(nomAgent.toLower()=="root"){
                this->setSessionId("root");
                this->ui->stackedWidget->setCurrentIndex(2);
            }else{
                this->setSessionId(mymodel->record(0).value("idagent").toString());
                this->ui->stackedWidget->setCurrentIndex(2);
           }
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(8);
    AgentController agentc;
    QSqlTableModel *agenttable=agentc.afficherAgents();
    this->ui->tableView_3->setModel(agenttable);
    //mylayout->addWidget(agentlist);
    this->ui->tableView_3->horizontalHeader()->setStretchLastSection(true);
    this->ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView_3->model()->setHeaderData(0,Qt::Horizontal,tr("Nom"));
    this->ui->tableView_3->model()->setHeaderData(1,Qt::Horizontal,tr("Prenom"));
    this->ui->tableView_3->model()->setHeaderData(2,Qt::Horizontal,tr("Mot de Passe"));
    this->ui->tableView_3->model()->setHeaderData(3,Qt::Horizontal,tr("Age"));
    this->ui->tableView_3->model()->setHeaderData(4,Qt::Horizontal,tr("CIN"));
    this->ui->tableView_3->model()->setHeaderData(5,Qt::Horizontal,tr("Date Naissance"));
    this->ui->tableView_3->model()->setHeaderData(7,Qt::Horizontal,tr("Droits"));
    this->ui->tableView_3->hideColumn(6);
}

void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    AgentController agentc;
        this->setCurrentId(agentc.afficherAgents()->record(index.row()).value("idagent").toString());
}

void MainWindow::on_banButton_clicked()
{
    this->setStatus("Banned");
}

void MainWindow::on_limiterModif_clicked()
{
    this->setStatus("LimiteModif");
}

void MainWindow::on_limiterEquipements_clicked()
{
    this->setStatus("LimiteEquipement");
}


void MainWindow::on_limiterVehicules_clicked()
{
    this->setStatus("LimiteVehicule");

}

void MainWindow::on_modifierDroits_clicked()
{
    AgentController agentc;
    QSqlTableModel* mymodel=agentc.afficherAgents();
    mymodel->setFilter("idAgent='"+this->getCurrentId()+"'");
    mymodel->setData(mymodel->index(0,7),this->getStatus());
    mymodel->submitAll();
    this->ui->tableView_3->setModel(agentc.afficherAgents());
    ui->tableView_3->hideColumn(6);
}

void MainWindow::on_actionImprimer_Profils_triggered()
{
        QString strStream;
        QTextStream out(&strStream);
        QString fileName =QFileDialog::getSaveFileName(this, "Enregistrer les Profils", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
         int rowCount = ui->tableView_2->model()->rowCount();
         int columnCount = ui->tableView_2->model()->columnCount();
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
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_actionImprimer_Agents_triggered()
{
    QFileDialog dialog;
    dialog.setOption(QFileDialog::DontUseNativeDialog);
    QString strStream;
    QTextStream out(&strStream);
    QString fileName = dialog.getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - AGENTS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES AGENTS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 25;\" border=1>\n "
          "</br> </br>";
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_19_clicked()
{
    AgentController agentc;
    this->ui->tableView->setModel(agentc.trierAgents());
}

void MainWindow::on_pushButton_20_clicked()
{
    profilController profilc;
    this->ui->tableView_2->setModel(profilc.trierProfils());
}

void MainWindow::on_pushButton_21_clicked()
{
    profilController profilc;
    QSqlTableModel* mymodel=profilc.afficherProfils();
    if(ui->profil_search->text()!=""){
        mymodel=profilc.afficherProfil(ui->profil_search->text());
        this->ui->tableView_2->setModel(mymodel);
    }else{
        this->ui->tableView_2->setModel(mymodel);
    }
}

void MainWindow::on_modifierDroits_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_22_clicked()
{
        QString ids;
        ids="ID: "+getCurrentId()+" Session: "+this->getSessionId()+" Date de debut: "+QDate::currentDate().toString();
        QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

        // Read the black & white pixels
        QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                int color = qr.getModule(x, y);  // 0 for white, 1 for black

                // You need to modify this part
                if(color==0)
                    im.setPixel(x, y,qRgb(254, 254, 254));
                else
                    im.setPixel(x, y,qRgb(0, 0, 0));
            }
        }
        im=im.scaled(200,200);
        ui->qrlabel->setPixmap(QPixmap::fromImage(im));
}


void MainWindow::setTimer(){
    timer.start();
    timer.setInterval(500);
    connect(&timer,SIGNAL(timeout()),this,SLOT(toggleArd()));
}

void MainWindow::toggleArd(){
    qDebug() << "Arduino Circuit Activated";
    data="1";
    A.write_to_arduino(data);
    data=A.read_from_arduino();
    qDebug() << data;
    if(data=="1"){
        QMessageBox * message=new QMessageBox();
        message->setText("Notification:Citoyen detecte");
        message->addButton(new QPushButton("Stop"),QMessageBox::YesRole);
        int result = message->exec();
        if(result==QMessageBox::Yes){
            A.write_to_arduino("0");
        }
    }
}

void MainWindow::on_GestionAgents_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    qDebug() << "Switch to Agents ";
}

void MainWindow::on_actionConfigure_Agents_et_Profils_triggered()
{
    AgentController agentc;
    profilController profilc;
    ui->stackedWidget->setCurrentIndex(9);
    ui->inputSessionConfiguration->setText(getSessionId());
    ui->inputAgentConfiguration->setText(QString(agentc.afficherAgents()->rowCount()));
    ui->inputProfilsConfiguration->setText(QString(profilc.afficherProfils()->rowCount()));
    ui->inputAgentColonneConfiguration->setText(QString(agentc.afficherAgents()->columnCount()));
    ui->inputColonneProfilConfiguration->setText(QString(profilc.afficherProfils()->columnCount()));
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_23_clicked()
{
    bool configure=true;
    AgentController agentc;
    profilController profilc;
    //QRegularExpression sessionreg("");
    QString sessionId=ui->inputSessionConfiguration->text();
    /*if(!sessionreg.match(sessionId).hasMatch()){
        configure=false;
    }*/
    int nombreAgents=ui->inputAgentConfiguration->text().toInt();
    if(nombreAgents<=0 || nombreAgents>agentc.afficherAgents()->rowCount()){
        configure=true;
        qDebug() << " Nombreagent erroné";
    }
    int nombreProfils=ui->inputProfilsConfiguration->text().toInt();
    if(nombreProfils<=0 || nombreProfils>profilc.afficherProfils()->rowCount()){
        configure=false;
        qDebug() << " NombreProfil erroné";

    }
    int nombreAgentsColonne=ui->inputAgentColonneConfiguration->text().toInt();
    if(nombreAgentsColonne<=0 && nombreAgents>agentc.afficherAgents()->columnCount()){
        configure=false;
        qDebug() << " NombreagentColonne erroné";

    }
    int nombreProfilsColonne=ui->inputColonneProfilConfiguration->text().toInt();
    if(nombreProfilsColonne<=0 && nombreProfils>profilc.afficherProfils()->columnCount()){
        configure=false;
        qDebug() << " Nombreprofilcolonne erroné";

    }
    if(configure==true){
        ui->tableView->setModel(agentc.afficherAgents());
        ui->tableView_2->setModel(profilc.afficherProfils());
        setSessionId(sessionId);
        for(int i=0;i<agentc.afficherAgents()->rowCount();i++){
            if(i>(nombreAgents)){
                ui->tableView->hideRow(i);
            }
        }
        for(int i=0;i<profilc.afficherProfils()->rowCount();i++){
            if(i>(nombreProfils)){
                ui->tableView_2->hideRow(i);
            }
        }
        for(int j=0;j<agentc.afficherAgents()->columnCount();j++){
            if(j>(nombreAgentsColonne)){
                ui->tableView->hideColumn(j);
            }
        }
        for(int j=0;j<profilc.afficherProfils()->columnCount();j++){
            if(j>(nombreProfilsColonne)){
                ui->tableView_2->hideColumn(j);
            }
        }

        QMessageBox *message=new QMessageBox();
        message->warning(this,"Configuration","Confirm Configuration");
        int res=message->exec();
        if(res==QMessageBox::Yes){
            message->warning(this,"Configuration fait avec succes","");
            message->show();
        }
    }
    ui->stackedWidget->setCurrentIndex(1);
}




//Yassine
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
  bool ajout=true;
  //QRegularExpression matriculeV("^[0-9]{1,3}[\\s][A-Z]{1,3}[\\s][0-9]{1,4}$‎");
  QRegularExpression marqueV("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
  QRegularExpression typeV("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
  QString matriculeA=ui->matricule->text();
 /*if(!matriculeV.match(matriculeA).hasMatch())
  {
      ajout=false;
      qDebug()<<"error houni"<<matriculeA;
  }*/
  QString marque=ui->marque->text();
  if(!marqueV.match(marque).hasMatch())
  {
      ajout=false;
      qDebug()<<"error houni2";
  }
  QString type=ui->type->text();
  if(!typeV.match(type).hasMatch())
  {
      ajout=false;
      qDebug()<<"error houni3";
  }
  QString couleur=ui->couleur->currentText();
  QDate date_acquisition=ui->date_acquisition->date();
  Vehicule V(matriculeA,marque,type,couleur,date_acquisition);
  VehiculeController VehiculeC;
  if(ajout==true)
  {
  VehiculeC.ajouterVehicule(V);
  }
  QSqlTableModel* myModel=VehiculeC.afficherVehicules();
    this->ui->table_afficher->setModel(myModel);
  this->ui->affecter_v->setModel(myModel);
}



void MainWindow::on_ajouterP_clicked()
{ bool ajout=true;
    //QRegularExpression idV("^[0-9][0-9][0-9]$");
    QString id=ui->id->text();
    QIntValidator valid(0,200);
    int pos=0;
    if(valid.validate(id,pos)==QIntValidator::Invalid)
      {
          ajout=false;
          qDebug()<<"error houni";
      }
    int taille=ui->taille->text().toInt();
    int nbVehicules=ui->nbvehicules->text().toInt();
    int placesVides=ui->placesvides->text().toInt();
    Parking P(taille,nbVehicules,placesVides,id);
    ParkingController ParkingC;
    if(ajout==true)
    {
    ParkingC.ajouterParking(P);
    }
    QSqlTableModel* myModel=ParkingC.afficherParkings();
      this->ui->table_p->setModel(myModel);
    this->ui->affecter_p->setModel(myModel);
    ui->affecter_p->hideColumn(0);

    ui->affecter_p->hideColumn(1);

}

void MainWindow::on_table_afficher_doubleClicked(const QModelIndex &index)
{
    VehiculeController V;
      this->ui->matricule->setText(V.afficherVehicules()->record(index.row()).value("matriculevehicule").toString());
      this->ui->marque->setText(V.afficherVehicules()->record(index.row()).value("marquevehicule").toString());
      this->ui->type->setText(V.afficherVehicules()->record(index.row()).value("typevehicule").toString());
      this->ui->couleur->setCurrentIndex(ui->couleur->findData(V.afficherVehicules()->record(index.row()).value("couleurvehicule").toString(),Qt::DisplayRole));
       this->ui->date_acquisition->setDate(V.afficherVehicules()->record(index.row()).value("date_acquisition").toDate());
      this->setmatricule(V.afficherVehicules()->record(index.row()).value("matriculevehicule").toString());
}

void MainWindow::on_Modifier_clicked()
{
    VehiculeController VehiculeC;
        QString matricule=ui->matricule->text();
        QString marque=ui->marque->text();
        QString type=ui->type->text();
        QString couleur=ui->couleur->itemData(ui->couleur->currentIndex()).toString();
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
    smtp = new Smtp("mestiriyassine69@gmail.com", "Piecegeretout123", "smtp.gmail.com");
    //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

    smtp->sendMail("mestiriyassine69@gmail.com", "mestiriyassine69@gmail.com" , "alerte d'inactivité","le vehicule avec la matricule "+this->getmatricule()+ " est inactive,veuillez prendre en consideration cette inactivité. \nCordialement ");
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

void MainWindow::on_QR_clicked()
{
    QString ids;
            ids="ID: "+getmatricule()+" Session: "+this->getmatricule()+" Date de debut: "+QDate::currentDate().toString();
            QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

            // Read the black & white pixels
            QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
            for (int y = 0; y < qr.getSize(); y++) {
                for (int x = 0; x < qr.getSize(); x++) {
                    int color = qr.getModule(x, y);  // 0 for white, 1 for black

                    // You need to modify this part
                    if(color==0)
                        im.setPixel(x, y,qRgb(254, 254, 254));
                    else
                        im.setPixel(x, y,qRgb(0, 0, 0));
                }
            }
            im=im.scaled(200,200);
            ui->qrlabel_2->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_GestionVehicules_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
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

//Mehdi

void MainWindow::on_ajouter_clicked()
{ click->play();
    int cin= ui->aj_cin->text().toInt();
    QString nom= ui->aj_nom->text();
    QString prenom= ui->aj_prenom->text();
    QString adresse=ui->aj_adresse->text();
    int num = ui->aj_num->text().toInt();


    citoyen c(cin,nom,prenom,adresse,num);
          bool test=c.ajouter();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter un citoyen "),
                          QObject::tr("citoye ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter un citoyen "),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);





}



void MainWindow::on_afficher_clicked()
{click->play();
ui->tab_citoyen->setModel(a->afficher());
}

void MainWindow::on_modifier_clicked()
{click->play();
     int cin = ui->mod_cin->text().toInt();
    QString nom= ui->mod_nom->text();
    QString prenom=ui->mod_prenom->text();
    QString adresse=ui->mod_adresse->text();
 int num = ui->mod_num->text().toInt();


              citoyen c(cin,nom,prenom,adresse,num);

                 bool test =c.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un citoyen"),
                                 QObject::tr("citoyen modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_citoyen->setModel(a->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier une citoyen"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_citoyen->setModel(a->afficher());

                 }

}



void MainWindow::on_supprimer_clicked()
{
click->play();
if (ui->sup_cin->text().isEmpty())
   {

       QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP cin!!!!") ;

   }
  else {
    int id = ui->sup_cin->text().toInt();

        bool test=b->supprimer(id);
        if(test)
        {
            ui->tab_citoyen->setModel(b->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un citoyen"),
                        QObject::tr("citoyen supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un citoyen"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_citoyen->setModel(b->afficher());

}

}
void MainWindow::on_recherche_citoyen_clicked()
{
click->play();
    QString cin= ui->type_recherche->text();
    ui->resultat_2->setModel(d->rechercher(cin));
    ui->tab_citoyen->setModel(b->afficher());
}

void MainWindow::on_tri_citoyen_clicked()
{click->play();
    bool test = o->tri_nom();
        if (test){
            QMessageBox::information(nullptr, QObject::tr("tri des citoyens"),
                        QObject::tr("succès.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_citoyen->setModel(o->tri_nom());}//refresh
        else
            QMessageBox::critical(nullptr, QObject::tr("tri des citoyens"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_citoyen->setModel(o->tri_nom());//refresh


}


void MainWindow::on_ajouter_2_clicked()
{click->play();
    int id_reclamation = ui->aj_recl->text().toInt();
    int id_citoyen = ui->aj_cit->text().toInt();
    QString type_reclamation= ui->comboBox_aj_type->currentText();

    QDate date_reclamation=ui->aj_date->date();


          reclamation r(id_reclamation,id_citoyen,type_reclamation,date_reclamation);
          bool test=r.ajouter();
          if(test)
        {
              sendMail();

        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation "),
                          QObject::tr("reclamation ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter une reclamation "),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("sebai.mehdi@esprit.tn", "191JMT3027", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("sebai.mehdi@esprit.tn", "sebai.mehdi@esprit.tn" ," Reclamation","Reclamation ajouter.");
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void MainWindow::on_afficher_2_clicked()
{click->play();
     ui->tab_reclamation->setModel(m->afficher());
}

void MainWindow::on_modifier_2_clicked()
{click->play();
    int id_reclamation = ui->mod_recl->text().toInt();
    int id_citoyen = ui->mod_cit->text().toInt();
    QString type_reclamation= ui->mod_type->currentText();

    QDate date_reclamation=ui->mod_date->date();


              reclamation r(id_reclamation,id_citoyen,type_reclamation,date_reclamation);

                 bool test =r.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un reclamation"),
                                 QObject::tr("reclamation modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_reclamation->setModel(m->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un reclamation"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_reclamation->setModel(m->afficher());

                 }

}

void MainWindow::on_supprimer_2_clicked()
{click->play();
    if (ui->sup_recl->text().isEmpty())
       {

           QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP reclamation!!!!") ;

       }
      else {
    int id = ui->sup_recl->text().toInt();

        bool test=n->supprimer(id);
        if(test)
        {
            ui->tab_reclamation->setModel(n->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                        QObject::tr("reclamation supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_reclamation->setModel(n->afficher());


}


}

void MainWindow::on_recherche_recl_clicked()
{click->play();
    QString type_reclamation= ui->type_rech->text();
    ui->resultat->setModel(p->rechercher_2(type_reclamation));
    ui->tab_reclamation->setModel(m->afficher());

}

void MainWindow::on_tri_recl_clicked()
{
    click->play();
    bool test = x->tri_type_reclamation();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("tri des publicités"),
                    QObject::tr("succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_reclamation->setModel(x->tri_type_reclamation());}//refresh
    else
        QMessageBox::critical(nullptr, QObject::tr("tri des publicités"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_reclamation->setModel(x->tri_type_reclamation());

}

void MainWindow::on_pdf_citoyen_clicked()
{click->play();
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_citoyen->model()->rowCount();
    const int columnCount = ui->tab_citoyen->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - EVENEMENTS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES EVENEMENTS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_citoyen->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_citoyen->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_citoyen->isColumnHidden(column)) {
                QString data =ui->tab_citoyen->model()->data(ui->tab_citoyen->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_impr_citoyen_clicked()
{click->play();
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();



}

void MainWindow::on_pdf_reclamation_clicked()
{click->play();
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_reclamation->model()->rowCount();
    const int columnCount = ui->tab_reclamation->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - EVENEMENTS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES EVENEMENTS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_reclamation->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_reclamation->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_reclamation->isColumnHidden(column)) {
                QString data =ui->tab_reclamation->model()->data(ui->tab_reclamation->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_impr_reclamation_clicked()
{click->play();
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();


}
// STATISTIQUE

void MainWindow::statrefresh(){

    QtCharts::QPieSeries *series=new QtCharts::QPieSeries();
    reclamation r ;
    QList<QString> l=r.listetyperec();
   for (int i = 0; i < l.size(); ++i){

       series->append("Type  Reclamation :"+l[i] ,r.calculType(l[i]));
   }


    QtCharts::QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QtCharts::QChart *chart =new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques");
    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    QtCharts::QChartView *chartview=new QtCharts::QChartView(chart);

    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(chartview,0,0);
    ui->statistiques->setLayout(mainLayout);

}


void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);
       ui->DigitalClock2->setText(time_text);
          ui->DigitalClock3->setText(time_text);
             ui->DigitalClock4->setText(time_text);

}



void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*
 WORKAROUND to escape "protected" limitation and use that freaking static function!
 */
class Kek : public QThread
{
public:
    static void wait(unsigned long)
    {
        QThread::msleep(200);
    }
};

void MainWindow::on_makeShot_clicked()
{
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    Sleep(3000);
#else
    Kek::wait(200);
#endif

    QPixmap okno = QPixmap::grabWindow(QApplication::desktop()->winId());
    QDateTime t = QDateTime::currentDateTime();
    QString saveWhere = qApp->applicationDirPath() + QString("/Scr_%1-%2-%3-%4-%5-%6.png")
            .arg(t.date().year()).arg(t.date().month()).arg(t.date().day())
            .arg(t.time().hour()).arg(t.time().minute()).arg(t.time().second());
    QString saveAs = QFileDialog::getSaveFileName(NULL, "Save screenshot as...",
                                                  saveWhere,
                                                  "PNG Picture (*.png)",
                                                  nullptr,
                                                  QFileDialog::DontUseNativeDialog);
    if(!saveAs.isEmpty())
        okno.save(saveAs, "PNG");

    this->show();
}

void MainWindow::on_excel_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tab_citoyen);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "CIN", "char(20)");
            obj.addField(1, "nom", "char(20)");
            obj.addField(2, "prenom", "char(20)");
            obj.addField(3, "adresse", "char(20)");
            obj.addField(4, "numero", "char(20)");



            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}

void MainWindow::on_excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tab_reclamation);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "id_reclamation", "char(20)");
            obj.addField(1, "id_citoyen", "char(20)");
            obj.addField(2, "type_reclamation", "char(20)");
            obj.addField(3, "date_reclamation", "char(20)");



            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}

void MainWindow::on_GestionCitoyens_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

//Ahmed

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_pushButton_28_clicked()
{Dossier t;
  ui->tableView_4->setModel(t.triid());

}

void MainWindow::on_pushButton_27_clicked()
{     Dossier t;
    ui->tableView_4->setModel(t.afficher());
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int a = ui->lineEdit_001->text().toInt();
    QString b= ui->lineEdit_002->text();
    QString c=ui->lineEdit_003->text();
    QString d= ui->lineEdit_004->text();
    QString e= ui->lineEdit_005->text();

    Dossier tab;
    Dossier(a,b,c,d,e);
    bool test =tab.ajouter(a,b,c,d,e);
    if(test)
  {
  QMessageBox::information(nullptr, QObject::tr("DOSSIER est ajouté"),
                    QObject::tr("DOSSIER ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tableView_4->setModel(tab.afficher());

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DOSSIER n est pas ajouté"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

}
/*void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}*/
void MainWindow::sendMail2()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text(), ui->server_2->text(), ui->port_2->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

void MainWindow::mailSent2(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pushButton_supp_clicked()
{
   Dossier supp;

              if(supp.supprimer(ui))
              {
                  QMessageBox ::information(this,"","supp")  ;


                     ui->tableView_4->setModel(supp.afficher());

              }
              else{
                  QMessageBox ::critical(this,"","erreur!")  ;
              }
}

/*void MainWindow::on_lineEdit_chercher_cursorPositionChanged()
{Dossier t;
    int i = ui->lineEdit_chercher->text().toInt();
    ui->tableView_5->setModel(t.chercher_parid(i));
}*/

void MainWindow::on_pushButton_29_clicked()
{Dossier t;
    ui->tableView_4->setModel(t.trinom());
}

void MainWindow::on_pushButton_inp_clicked()
{//imprimer
  QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_pushButton_imp_clicked()
{//pdf
  QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_4->model()->rowCount();
                     const int columnCount = ui->tableView_4->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_4->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_4->isColumnHidden(column)) {
                                 QString data = ui->tableView_4->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);


}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_supp_2_clicked()
{
    Dossier supp;

              if(supp.supprimer(ui))
              {
                  QMessageBox ::information(this,"","supp")  ;


                     ui->tableView->setModel(supp.afficher());

              }
              else{
                  QMessageBox ::critical(this,"","erreur!")  ;
              }
}

void MainWindow::on_pushButton_ajouter_2_clicked()
{

    QString b= ui->lineEdit_3->text();
    int a=ui->lineEdit_2->text().toInt();
    QString c=ui->lineEdit_4->text();
    QString d=ui->lineEdit_15->text();
    QString e=ui->lineEdit_16->text();
     Document   tab;
     Document(a,b,c,d,e);
    bool test =tab.ajouter_doc(a,b,c,d,e);
    if (test){QMessageBox::information(nullptr,QObject::tr("ajouter appliquee"),
                                       QObject::tr("marche avec succesful.\n""click Cancel to exit"),
                                       QMessageBox::Cancel);}
              else
                  QMessageBox::critical(nullptr, QObject::tr("non ajouter"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_4->setModel(tab.afficher_doc());
}

void MainWindow::on_pushButton_30_clicked()
{
   Document t;
       ui->tableView_7->setModel(t.afficher_doc());
}

void MainWindow::on_pushButton_32_clicked()
{
    Document t;
        ui->tableView_7->setModel(t.tri_titre());
}

void MainWindow::on_pushButton_31_clicked()
{
    Document t;
        ui->tableView_7->setModel(t.tri_nomauteur());
}

void MainWindow::on_pb_supprimer_clicked()
{ Document t;
   QString i= ui->lineEdit_supprimer->text();
bool test=t.supprimer_2(i);
ui->lineEdit_supprimer->setText("");
if (test)
{QMessageBox::information(nullptr,QObject::tr("supprimation appliquee"),
                         QObject::tr("marche avec succesful.\n""click Cancel to exit"),
                         QMessageBox::Cancel);}
else
    QMessageBox::critical(nullptr, QObject::tr("non supprimer"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_4->setModel(t.afficher_doc());
}

void MainWindow::on_pushButton_33_clicked()
{  Document t;
    QString a= ui->lineEdit_chercher_2->text();
    ui->tableView_6->setModel(t.recherche_iddoc(a));

}


/*void MainWindow::on_pushButton_10_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}*/

void MainWindow::on_commandLinkButton_3_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(3);
}



void MainWindow::on_pushButton_mod_clicked()
{
   Document p;
   bool test;
   test=p.update_doc(ui);
   if(test)
   {QMessageBox::information(nullptr,QObject::tr("modification appliquee"),
                            QObject::tr("marche avec succesful.\n""click Cancel to exit"),
                            QMessageBox::Cancel);}
   else
       QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tableView_4->setModel(p.afficher_doc());
}

void MainWindow::on_pushButton_34_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_tableView_7_clicked(const QModelIndex &index)
{
    ui->lineEdit_11->setText( ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_12->setText( ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),1)).toString() );
        ui->lineEdit_13->setText( ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),2)).toString() );
         ui->lineEdit_10->setText( ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),3)).toString() );
          ui->lineEdit_14->setText( ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),4)).toString() );
}

void MainWindow::on_commandLinkButton_4_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_36_clicked()
{
    Dossier p;
    bool test;
    test=p.update_dossier(ui);
    if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("modifie un DOSSIER"),
                             QObject::tr("dOSSIER modifie.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   ui->tableView->setModel(p.afficher());
}

void MainWindow::on_pushButton_35_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    ui->lineEdit->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),0)).toString() );
    ui->lineEdit_5->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),1)).toString() );
    ui->lineEdit_6->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),2)).toString() );
    ui->lineEdit_7->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),3)).toString() );
    ui->lineEdit_8->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),4)).toString() );
  }







void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(5);
}

void MainWindow::on_commandLinkButton_5_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_6_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_pushButton_38_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(6);
}



void MainWindow::on_GestionDocuments_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

//Youssef

void MainWindow::on_ajouter_prisonnier_clicked()//bouton ajouter
{
    bool ajout=true;

    QRegularExpression nomV("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
    QRegularExpression prenomV("^(?=.{1,40}$)[a-zA-Z]+(?:[-'\\s][a-zA-Z]+)*$");
     QRegularExpression cinV("(?<!\\d)\\d{8}(?!\\d)");
    PrisonnierController prisonnierP;
  QString cin=ui->le_cin->text();
  if(!cinV.match(cin).hasMatch())
    {
        ajout=false;
        qDebug()<<"erroooor3";
    }
  QString nom=ui->le_nom->text();
  if(!nomV.match(nom).hasMatch())
    {
        ajout=false;
        qDebug()<<"erroooor1";
    }
  QString prenom=ui->le_prenom->text();
  if(!prenomV.match(prenom).hasMatch())
    {
        ajout=false;
        qDebug()<<"erroooor2";
    }
  QDate date=ui->le_date->date();
  QString crime=ui->le_crime->text();
  Prisonnier P(nom,prenom,crime,cin,date);
  PrisonnierController prisonnierC;
  if(ajout==true)
    {
    prisonnierC.ajouterPrisonnier(P);
    }

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


void MainWindow::on_modifier_prisonnier_clicked()//bouton modifier
{ PrisonnierController prisonnierC;
    QString cin=ui->le_cin->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QDate date=ui->le_date->date();
    QString crime=ui->le_crime->text();
    Prisonnier P(nom,prenom,crime,cin,date);
    prisonnierC.modifierPrisonnier(P,this->getIdPr());
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

void MainWindow::setIdPr(QString id)
{
    this->idPr=id;
}

QString MainWindow::getIdPr()
{
 return this->idPr;
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
  this->setIdPr(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
 ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_supprimer_prisonnier_clicked()//bouton supprimer
{
   PrisonnierController prisonnierC;
   prisonnierC.supprimerPrisonnier(this->getIdPr());
   QSqlTableModel* myModel=prisonnierC.afficherPrisonniers();
   this->ui->tab_prisonnier->setModel(myModel);
   ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_tab_prisonnier_clicked(const QModelIndex &index)
{
    PrisonnierController P;
    this->setIdPr(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
    ui->tab_prisonnier->hideColumn(6);
}

void MainWindow::on_ajouter_cellule_clicked()//bouton ajouter cellule
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



void MainWindow::on_modifier_cellule_clicked() //bouton modifier cellule
{CelluleController celluleC;
    int capacite=ui->la_capacite->text().toInt();
    int num=ui->le_num->text().toInt();
    Cellule C(idC,num,capacite);
    celluleC.modifierCellule(C,this->getIdC());
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
    this->setIdC(C.afficherCellules()->record(index.row()).value("idCellule").toString());
}

void MainWindow::on_supprimer_cellule_clicked() // bouton supprimer cellule
{
    CelluleController celluleP;
    celluleP.supprimerCellule(this->getIdC());
    QSqlTableModel* myModel1=celluleP.afficherCellules();
    this->ui->tab_cellule->setModel(myModel1);
    this->ui->affect_c->setModel(myModel1);
    ui->affect_c->hideColumn(0);
    ui->affect_c->hideColumn(2);
}

void MainWindow::on_triD_prisonnier_clicked() //Tri Decroissant Prisonnier
{
    this->ui->tab_prisonnier->sortByColumn(1,Qt::DescendingOrder);
}



void MainWindow::on_triC_prisonnier_clicked() //Tri croissant Prisonnier
{
    this->ui->tab_prisonnier->sortByColumn(1,Qt::AscendingOrder);
}


void MainWindow::on_triD_cellule_clicked() //Tri decroissant cellule
{
    this->ui->tab_cellule->sortByColumn(1,Qt::DescendingOrder);
}



void MainWindow::on_triC_cellule_clicked()
{
    this->ui->tab_cellule->sortByColumn(1,Qt::AscendingOrder);
}

void MainWindow::on_rechercher_prisonnier_clicked()
{
    PrisonnierController PrisonnierP;
    QSqlTableModel* myModel=PrisonnierP.afficherPrisonniers();
    myModel->setFilter("nomPrisonnier='"+this->ui->R_prisonnier->text()+"'");
    this->ui->tab_prisonnier->setModel(myModel);
    ui->tab_prisonnier->hideColumn(6);

}

void MainWindow::on_rechercher_cellule_clicked()
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
    this->setIdPr(P.afficherPrisonniers()->record(index.row()).value("idPrisonnier").toString());
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



void MainWindow::on_affecter_prisonnier_clicked() // affichage affectation
{
    int num;
    CelluleController P;
    PrisonnierController C;
    QSqlTableModel *MyModel = P.afficherCellules();
    MyModel->setFilter("idCellule='"+this->getIdC()+"'");
    num=MyModel->record(0).value("numCellule").toInt();
    qDebug() <<num;
    C.affecterPrisonnier(this->getIdPr(),num);
     QSqlTableModel *MyModel1 =C.afficherPrisonniers();
    this->ui->affect->setModel(MyModel1);
     ui->affect->hideColumn(0);
     ui->affect->hideColumn(3);
     ui->affect->hideColumn(4);
     ui->affect->hideColumn(5);

}

void MainWindow::on_envoyer_prisonnier_clicked()
{   Smtp* smtp;
    QString cause=ui->la_cause->text();
    QString rapport=ui->le_rapport->text();
    smtp = new Smtp("youssefbenyahia6@gmail.com", "200369Yc", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));
    smtp->sendMail("youssefbenyahia6@gmail.com", "youssefbenyahia6@gmail.com" , "alerte d'inactivité","la cause "+cause+".\nle Rapport:"+rapport);
}






void MainWindow::on_GestionPrisonniers_clicked()
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
    ui->stackedWidget_2->setCurrentIndex(5);
}
