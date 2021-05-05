#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include "Dossier.h"
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
#include "Document.h"
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
#include "smtp.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{Dossier t;
  ui->tableView->setModel(t.triid());

}

void MainWindow::on_pushButton_3_clicked()
{     Dossier t;
    ui->tableView->setModel(t.afficher());
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
  ui->tableView->setModel(tab.afficher());

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DOSSIER n est pas ajouté"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
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


                     ui->tableView->setModel(supp.afficher());

              }
              else{
                  QMessageBox ::critical(this,"","erreur!")  ;
              }
}

void MainWindow::on_lineEdit_chercher_cursorPositionChanged()
{Dossier t;
    int i = ui->lineEdit_chercher->text().toInt();
    ui->tableView_2->setModel(t.chercher_parid(i));
}

void MainWindow::on_pushButton_5_clicked()
{Dossier t;
    ui->tableView->setModel(t.trinom());
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

                     const int rowCount = ui->tableView->model()->rowCount();
                     const int columnCount = ui->tableView->model()->columnCount();

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
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->tableView->setModel(tab.afficher_doc());
}

void MainWindow::on_pushButton_6_clicked()
{
   Document t;
       ui->tableView_4->setModel(t.afficher_doc());
}

void MainWindow::on_pushButton_8_clicked()
{
    Document t;
        ui->tableView_4->setModel(t.tri_titre());
}

void MainWindow::on_pushButton_7_clicked()
{
    Document t;
        ui->tableView_4->setModel(t.tri_nomauteur());
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

void MainWindow::on_pushButton_9_clicked()
{  Document t;
    QString a= ui->lineEdit_chercher_2->text();
    ui->tableView_3->setModel(t.recherche_iddoc(a));

}


/*void MainWindow::on_pushButton_10_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}*/

void MainWindow::on_commandLinkButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
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

void MainWindow::on_pushButton_10_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    ui->lineEdit_11->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_12->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),1)).toString() );
        ui->lineEdit_13->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),2)).toString() );
         ui->lineEdit_10->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),3)).toString() );
          ui->lineEdit_14->setText( ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),4)).toString() );
}

void MainWindow::on_commandLinkButton_4_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_12_clicked()
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

void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit->setText( ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString() );
    ui->lineEdit_5->setText( ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString() );
    ui->lineEdit_6->setText( ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString() );
    ui->lineEdit_7->setText( ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString() );
    ui->lineEdit_8->setText( ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString() );
  }







void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_commandLinkButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

