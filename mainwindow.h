#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

#include <QMainWindow>
#include <prisonnierController.h>
#include "prisonnier.h"
#include <celluleController.h>
#include "cellule.h"

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
void setId(QString);
QString getId();
void setIdC(QString);
QString getIdC();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_tab_prisonnier_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_tab_prisonnier_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_tab_cellule_doubleClicked(const QModelIndex &index);

    void on_tab_cellule_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();


    void on_affect_p_clicked(const QModelIndex &index);

    void on_affect_c_clicked(const QModelIndex &index);

   // void on_affecter_clicked();

    void on_affecter_2_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    PrisonnierController P;
    CelluleController C;
    QString id;
    QString idC;
};
#endif // MAINWINDOW_H
