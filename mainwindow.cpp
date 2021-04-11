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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setSortingEnabled(true);
    ui->tableView_2->setSortingEnabled(true);
    QSqlDatabase *db=Config::ouvrirConnexion();
    this->status="";
    ui->label_21->setStyleSheet("QLabel {color : black;}");
    ui->label_22->setStyleSheet("QLabel {color : black;}");
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
    this->ui->tableView->model()->setHeaderData(0,Qt::Horizontal,tr("Nom"));
    this->ui->tableView->model()->setHeaderData(1,Qt::Horizontal,tr("Prenom"));
    this->ui->tableView->model()->setHeaderData(2,Qt::Horizontal,tr("Mot de Passe"));
    this->ui->tableView->model()->setHeaderData(3,Qt::Horizontal,tr("Age"));
    this->ui->tableView->model()->setHeaderData(4,Qt::Horizontal,tr("CIN"));
    this->ui->tableView->model()->setHeaderData(5,Qt::Horizontal,tr("Date Naissance"));
    this->ui->tableView->model()->setHeaderData(7,Qt::Horizontal,tr("Droits"));
    this->ui->tableView->hideColumn(6);
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
    QString Nom=this->ui->nom->text();
    QString Prenom=this->ui->prenom->text();
    QString Cin=this->ui->cin->text();
    QString Mdp=this->ui->mdp->text();
    int Age=this->ui->age->text().toInt();
    QDate dateNaissance=this->ui->dateEdit->date();
    Agent agent(Nom,Prenom,Age,Cin,Mdp,dateNaissance);
    AgentController agentc;
    agentc.ajouterAgent(agent);
    this->ui->tableView->setModel(agentc.afficherAgents());
    this->ui->stackedWidget->setCurrentIndex(1);
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
    QString newnom=this->ui->nomModif->text();
    QString newprenom=this->ui->prenomModif->text();
    QString newcin=this->ui->cinModif->text();
    QString newmdp=this->ui->mdpModif->text();
    int newage=this->ui->ageModif->text().toInt();
    QDate newdateNaissance=this->ui->dateNaissanceModif->date();
    Agent agent(newnom,newprenom,newage,newcin,newmdp,newdateNaissance);
    AgentController agentc;
    agentc.modifierAgent(agent,this->getCurrentId());
    QSqlTableModel *agenttable=agentc.afficherAgents();
    this->ui->tableView->setModel(agenttable);
    this->ui->stackedWidget->setCurrentIndex(1);
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
    QString fonction = this->ui->fonction->text();
    QString grade = this->ui->grade->text();
    QString dept= this->ui->departement->text();
    float salaire = this->ui->salaire->text().toFloat();
    QDate dateEmbauche = this->ui->dateEmbauche->date();
    Profil profil(salaire,grade,fonction,dateEmbauche,dept);
    profilController profilc;
    profilc.ajouterProfil(profil);
    QSqlTableModel *profiltable=profilc.afficherProfils();
    this->ui->tableView_2->setModel(profiltable);
    this->ui->stackedWidget->setCurrentIndex(5);
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
    QString newfonction=this->ui->fonctionModif->text();
    QString newgrade=this->ui->gradeModif->text();
    QString newdepartement=this->ui->departementModif->text();
    float newsalaire=this->ui->salaireModif->text().toFloat();
    QDate newdateEmbauche=this->ui->dateEmbaucheModif->date();
    Profil profil(newsalaire,newgrade,newfonction,newdateEmbauche,newdepartement);
    profilController profilc;
    profilc.modifierProfil(profil,this->getCurrentId());
    QSqlTableModel *profiltable=profilc.afficherProfils();
    this->ui->tableView_2->setModel(profiltable);
    this->ui->stackedWidget->setCurrentIndex(4);
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

    if(mymodel->rowCount()==0){
            QMessageBox * newmessage1=new QMessageBox(this);
            newmessage1->setModal(true);
            newmessage1->setText("Wrong Data");
            newmessage1->exec();
   }else{
            if(nomAgent.toLower()=="root"){
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
