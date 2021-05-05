#ifndef AGENTCONTROLLER_H
#define AGENTCONTROLLER_H
#include "Agent.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
class AgentController{
private:
    QSqlDatabase db;
public:
    void ajouterAgent(Agent& a);
    QSqlTableModel* afficherAgents();
    void modifierAgent(Agent& a,QString id);
    QSqlTableModel* afficherAgent(QString name);
    void supprimerAgent(QString id);
    QSqlTableModel* trierAgents();
    QSqlTableModel* authenticateAgent(QString nom,QString mdp);
};

#endif // AGENTCONTROLLER_H
