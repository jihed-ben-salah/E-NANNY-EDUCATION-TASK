#include "motcle.h"


#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

motcle::motcle()
{
id=0;site=""; age=0;
}
motcle::motcle(int id,QString site,int age)
{
    this->id=id;
    this->site=site;
    this->age=age;

}
bool motcle::ajouter()
{

    QSqlQuery query;

         query.prepare("INSERT INTO motcle (id,site, age) "
                      "VALUES (:id,:site, :age)");
          query.bindValue(":id", id);
         query.bindValue(":age", age);
         query.bindValue(":site", site);


         return  query.exec();


}

QSqlQueryModel* motcle::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();


         model->setQuery("SELECT* FROM motcle");



return model;
}
bool motcle::supprimer(int id)
{


    QSqlQuery query;

         query.prepare("Delete from motcle where id=:id ");
         query.bindValue(0,id);

         return  query.exec();
}

bool motcle::modifier()
{
QSqlQuery query;
    //QString id_string=QString::number(identifiant);
    // QString personne_aide_string=QString::number(personne_aide);
  query.prepare("Update motcle set id=:id, site=:site, age=:age where id=:id");
  query.bindValue(":id", id);
 query.bindValue(":site", site);
 query.bindValue(":age", age);


  return query.exec();

}


QSqlQueryModel * motcle::AfficherTrieAge()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM motcle ORDER BY age");

    return  model;
}

QSqlQueryModel * motcle ::rechercherSite(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from motcle where site like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}



