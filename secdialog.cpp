#include "secdialog.h"
#include "ui_secdialog.h"
#include "gestouvrier.h"
#include<QMessageBox>
#include"mainwindow.h"

secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);

}
secDialog::~secDialog()
{
    delete ui;
}



