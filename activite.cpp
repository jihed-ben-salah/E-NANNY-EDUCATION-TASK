#include "activite.h"
#include<QSqlQuery>
Activite::Activite()
{
    //numero=0;
    cours="";
    activite="";
    etat="";

}
Activite::~Activite()
{
    //vide
}
Activite::Activite(int numero,QString cours,QString activite,QString etat)
{
 this->numero = numero;
 this->cours = cours;
 this->activite = activite;
 this->etat = etat;
}

bool Activite::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO ACTIVITE (numero, cours ,activite ,etat) "
                        "VALUES (:numero, :cours, :activite,:etat)");
          query.bindValue(":numero",numero);
          query.bindValue(":cours",cours );
          query.bindValue(":activite",activite);
          query.bindValue(":etat",etat);
         return query.exec();
}
QSqlQueryModel* Activite::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT* FROM ACTIVITE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
   //model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero "));
   return model;
}
bool Activite::supprimer(int NUMERO)
{
    QSqlQuery query;
    int res = NUMERO;
    query.prepare("DELETE FROM ACTIVITE WHERE NUMERO = :NUMERO");
    query.bindValue(":NUMERO",res);
    return query.exec();

}
QSqlQueryModel* Activite::chercher(QString NOMC)
{
   QSqlQueryModel* model =new QSqlQueryModel();
   model->setQuery("SELECT * FROM ACTIVITE WHERE ACTIVITE='"+NOMC+"'"   );
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
   return model;
}
bool Activite::modifier()
{
    QSqlQuery query;
     QString res=QString::number(numero);
    query.prepare("UPDATE ACTIVITE SET COURS=:COURS,ACTIVITE=:ACTIVITE,ETAT=:ETAT WHERE NUMERO =:NUMERO");
    query.bindValue(":COURS",cours);
    query.bindValue(":ACTIVITE",activite);
    query.bindValue(":ETAT",etat);
    query.bindValue(":NUMERO",numero);
    return query.exec();
}
QSqlQueryModel * Activite::trier_toDo()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from ACTIVITE WHERE ETAT = 'TO DO'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model ;
}
QSqlQueryModel * Activite::trier_done()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from ACTIVITE WHERE ETAT = 'Done'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model ;
}

