#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supp_clicked();

    void on_lineEdit_chercher_cursorPositionChanged();

    void on_pushButton_5_clicked();

    void on_pushButton_inp_clicked();

    void on_pushButton_imp_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_2_clicked();

    void on_pushButton_supp_2_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_commandLinkButton_3_clicked();

    void on_pushButton_ajouter_4_clicked();

    void on_pushButton_mod_clicked();

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_commandLinkButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();


    void on_tableView_clicked(const QModelIndex &index);



    void on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2);

    void on_tableView_2_activated(const QModelIndex &index);
    void sendMail();
    void mailSent(QString);
    void sendMail2();
    void mailSent2(QString);

    void on_pushButton_13_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_14_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
