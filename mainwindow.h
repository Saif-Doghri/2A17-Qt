#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
