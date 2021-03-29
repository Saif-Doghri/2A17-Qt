#ifndef AGENTCONTROLLER_H
#define AGENTCONTROLLER_H
#include "Agent.h"
#include "Config.h"
#include <QSqlTableModel>
#include <QTableView>
class AgentController{
private:
    QSqlDatabase db;
public:
    void ajouterAgent(Agent& a);
    QSqlTableModel* afficherAgents();
    void modifierAgent(Agent& a,QString id);
    QSqlTableModel* afficherAgent(QString id);
    void supprimerAgent(QString id);
};

#endif // AGENTCONTROLLER_H
