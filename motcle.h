#ifndef MOTCLE_H
#define MOTCLE_H

#include <QString>
#include <QSqlQueryModel>
class motcle
{
public:
    motcle();

    motcle(int,QString,int);
    int Getid() { return id; }
               void Setid(int val) { this->id = val; }
    QString getsite()   { return site; }
    void setsite(QString val){ this->site = val; }
    int getage(){ return age; }
    void setage(int val){ this->age = val; }
   bool ajouter();
   QSqlQueryModel* afficher();
  bool supprimer(int);
  bool modifier ();
  QSqlQueryModel * AfficherTrieAge();
  QSqlQueryModel * rechercherSite(QString );
private:
    int id,age;
    QString site;
};

#endif // MOTCLE_H

