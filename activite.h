#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQueryModel>

class Activite
{    int numero;
     QString cours;
     QString activite;
     QString etat;
public:
    Activite();
     Activite(int numero,QString cours,QString activite,QString etat);
      QSqlQueryModel * trier_done();
         QSqlQueryModel * trier_toDo();
          bool supprimer(int NUMERO);
           QSqlQueryModel* chercher(QString NOMC);
            bool modifier();
    bool ajouter();
     ~Activite();
       QSqlQueryModel* afficher();
};

#endif // ACTIVITE_H
