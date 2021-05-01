#ifndef DEVOIRS_H
#define DEVOIRS_H
#include <QString>
#include <QSqlQueryModel>

class Devoirs
{
    QString NOMD;
    int REFDEV;
    QString NOMC;
    QString DEADLINE;
public:
    Devoirs();
    Devoirs(QString,int,QString,QString);
    ~Devoirs();
    /*void set_nomC(QString);
    void set_nomE(QString);
    void set_heureD(QString);
    void set_heureF(QString);
    QString get_nomC();
    QString get_nomE();
    QString get_heureD();
    QString get_heureF();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(int);
    */
    QSqlQueryModel* chercher(QString);
    QSqlQueryModel* afficher_contact();
    QSqlQueryModel* trier_id();
    QSqlQueryModel * trier_nom();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();
};

#endif // DEVOIRS_H
