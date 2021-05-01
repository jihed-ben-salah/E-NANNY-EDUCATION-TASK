#include "cours.h"
#include "ui_cours.h"
#include <QString>
#include<QSqlQuery>
Cours::Cours(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cours)
{
    ui->setupUi(this);
}

Cours::~Cours()
{
    delete ui;
}
Cours::Cours()
{
    nomC="";
    nomE="";
    heureD="";
    heureF="";

}
Cours::Cours(QString nomC,QString nomE,QString heureD,QString heureF)
{
 this->nomC = nomC;
 this->nomE = nomE;
 this->heureD = heureD;
 this->heureF = heureF;
}
void Cours::set_nomC(QString nomC)
{
  this->nomC=nomC;
}
void Cours::set_nomE(QString nomE)
{
    this->nomE=nomE;
}
void Cours::set_heureD(QString heureD)
{
    this->heureD=heureD;
}
void Cours::set_heureF(QString heureF)
{
    this->heureF=heureF;
}
QString Cours::get_nomC()
{
    return nomC;
}
QString Cours::get_nomE()
{
    return nomE;
}
QString Cours::get_heureD()
{
    return heureD;
}
QString Cours::get_heureF()
{
    return heureF;
}
void Cours::on_b_ajoutC_clicked()
{  QString nomC=ui->nomC->text();
   QString nomE=ui->nomE->text();
   QString heureD=ui->heureD->text();
   QString heureF=ui->heureF->text();
   Cours C(nomC,nomE,heureD,heureF);
}
bool Cours::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO cours (nomC, nomE,heureD ,heureF) "
                        "VALUES (:nomC, :nomE, :heureD,:heureF)");
          query.bindValue(":nomC",nomC );
          query.bindValue(":nomE",nomE );
          query.bindValue(":heureD",heureD);
          query.bindValue(":heureF",heureF);
         return query.exec();
}

