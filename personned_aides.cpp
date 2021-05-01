#include "personned_aides.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
Personned_aides::Personned_aides()
{
    identifiant=0;
    nom="";
    prenom="";
    adresse="";
    email="";
    metier="";
    prix_heure=0;
    num_tel=0;
}
Personned_aides::Personned_aides(int id,QString nom,QString prenom,QString adresse,QString email,QString metier,int num_tel,int prix_heure)
{
    this->identifiant=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->email=email;
   this-> metier=metier;
    this->prix_heure=prix_heure;
    this->num_tel=num_tel;
}
bool Personned_aides::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(identifiant);
     QString num_tel_string=QString::number(num_tel);
       QString prix_heure_string=QString::number(prix_heure);
     query.prepare("INSERT INTO personne (identifiant, nom, prenom, adresse, email, metier, num_tel, prix_heure) "
                       "VALUES (:identifiant, :nom, :prenom, :adresse, :email, :metier, :num_tel, :prix_heure)");
         query.bindValue(":identifiant", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":adresse", adresse);
         query.bindValue(":email", email);
         query.bindValue(":metier", metier);
         query.bindValue(":num_tel",num_tel_string);
         query.bindValue(":prix_heure", prix_heure_string);

    return  query.exec();
}
bool Personned_aides::supprimer(int identifiant)
{

    QSqlQuery query;

     query.prepare(" delete from personne where identifiant=:identifiant ");
     query.bindValue(":identifiant", identifiant);


    return  query.exec();
}

QSqlQueryModel* Personned_aides::afficher()
{

   QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM personne");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Métier"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("numéro"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("prix par heure"));
   return  model;
}

bool Personned_aides::modifier()
{ QSqlQuery query;
    QString id_string=QString::number(identifiant);
     QString num_tel_string=QString::number(num_tel);
       QString prix_heure_string=QString::number(prix_heure);
  query.prepare("Update personne set identifiant=:identifiant, nom=:nom, prenom=:prenom, adresse=:adresse ,email=:email, metier=:metier, num_tel=:num_tel,prix_heure=:prix_heure where identifiant=:identifiant");
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":adresse",adresse);
  query.bindValue(":email",email);
  query.bindValue(":metier",metier);
  query.bindValue(":num_tel",num_tel_string);
  query.bindValue(":prix_heure",prix_heure_string);
  return query.exec();
}
QSqlQueryModel * Personned_aides::AfficherTrieNom()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM personne ORDER BY nom");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Métier"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("numéro"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("prix par heure"));
    return  model;
}
QSqlQueryModel * Personned_aides::rechercherNom(QString metier)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from personne where metier like ?");
    q.addBindValue("%"+ metier +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

