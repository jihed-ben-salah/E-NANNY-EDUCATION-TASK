#include "reclamation.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
reclamation::reclamation()
{
     identifiant=0;
    mail_destinataire="";
    sujet="";
    message="";
   personne_aide=0;
}
reclamation:: reclamation(int id,QString mail,QString sujet,QString msg,int personne)
{this->identifiant=id;
   this-> mail_destinataire=mail;
  this->  sujet=sujet;
   this-> message=msg;
  this-> personne_aide=personne;
}


bool reclamation::ajouter_reclamtion()
{
    QSqlQuery query;
    QString id_string=QString::number(identifiant);
     QString personne_aide_string=QString::number(personne_aide);
     query.prepare("INSERT INTO reclamation (identifiant, mail_destinataire, sujet, message, personne_aide) "
                       "VALUES (:identifiant, :mail_destinataire, :sujet, :message, :personne_aide)");
         query.bindValue(":identifiant", id_string);
         query.bindValue(":mail_destinataire", mail_destinataire);
         query.bindValue(":sujet", sujet);
         query.bindValue(":message", message);
         query.bindValue(":personne_aide", personne_aide_string);

    return  query.exec();
}
QSqlQueryModel* reclamation::afficher_reclamtion()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM reclamation");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Mail_destinataire"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sujet"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Message"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Personne_aide"));

    return  model;
}

bool reclamation::supprimer_reclamtion(int identifiant)
{

    QSqlQuery query;

     query.prepare(" delete from reclamation where identifiant=:identifiant ");
     query.bindValue(":identifiant", identifiant);


    return  query.exec();
}
bool reclamation::modifier_reclamtion()
{ QSqlQuery query;
    QString id_string=QString::number(identifiant);
     QString personne_aide_string=QString::number(personne_aide);
  query.prepare("Update reclamation set identifiant=:identifiant, mail_destinataire=:mail_destinataire, sujet=:sujet, message=:message ,personne_aide=:personne_aide where identifiant=:identifiant");
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":mail_destinataire",mail_destinataire);
  query.bindValue(":sujet",sujet);
  query.bindValue(":message",message);
  query.bindValue(":personne_aide",personne_aide);

  return query.exec();
}
