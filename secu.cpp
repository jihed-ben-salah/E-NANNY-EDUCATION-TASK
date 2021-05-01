#include "secu.h"
#include "ui_secu.h"
#include "motcle.h"
#include <time.h>
#include <QSqlQuery>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QDateTimeEdit>
secu::secu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secu)
{
    ui->setupUi(this);
    ui->tableView->setModel(T.afficher());
    ui->tableView_2->setModel(M.afficher());

update();

Sound = new QSound ("./music.wav");
Soundclic = new QSound ("./M.wav");

int ret=A.connect_arduino(); // lancer la connexion à arduino
switch(ret){
case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
   break;
case(-1):qDebug() << "arduino is not available";
}
timer = new QTimer(this);
 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
 QObject::connect(timer,SIGNAL(timeout()),this,SLOT(verif()));
 timer->start(1000);

}

secu::~secu()
{
    delete ui;
}
void secu::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
{
//mailing
        Smtp* smtp = new Smtp("yussefnaoui2001@gmail.com","minatovstobi17", "smtp.gmail.com");


            smtp->sendMail("yussefnaoui2001@gmail.com","yussef.naoui@esprit.tn","bouton panique","Bouton panique activé");



}


}

void secu::on_ajouter_clicked()
{
//system("shutdown -s -t 20");
     Soundclic->play();
    int hourdeb=ui->timeEdit->time().hour();
    int minutedeb=ui->timeEdit->time().minute();
    int hourfin=ui->timeEdit_2->time().hour();
    int minutefin=ui->timeEdit_2->time().minute();
QString enfant=ui->comboBox->currentText();
    timeclass T(enfant,hourdeb,minutedeb,hourfin,minutefin);
    bool test=T.ajouter();
    if (test)
    {

ui->tableView->setModel(T.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }
    else    { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Ajout non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }

    /* QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
     Etudiant E(id,nom,prenom);

 bool test=E.ajouter();
 if (test)
 {
     ui->tab_etudiant->setModel(E.afficher());

     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

 }
 else    { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Ajout non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

 }*/
}

void secu::on_pb_supp_clicked()
{
 Soundclic->play();
    bool test=T.supprimer(id_enfant);
    if (test){

ui->tableView->setModel(T.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué \n" "Click cancel to exit."), QMessageBox::Cancel);
    }else {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Suppression non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }
}

void secu::on_tableView_activated(const QModelIndex &index)
{
    QString heuredeb,minutedeb,heurefin,minutefin;
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from time where"
                      " enfant='"+val+"' or hourstart='"+val+"' or minutestart='"+val+"' or hourend='"+val+"' or minuteend ='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           {
                  if (qry.value(1)<10)
                  {
                       heuredeb="0"+qry.value(1).toString()  ;
                  }
                  if (qry.value(2)<10)
                  {
                       minutedeb="0"+qry.value(2).toString()  ;
                  }

                  if (qry.value(3)<10)
                  {
                       heurefin="0"+qry.value(3).toString()  ;
                  }

                  if (qry.value(4)<10)
                  {
                       minutefin="0"+qry.value(4).toString()  ;
                  }


                  QString heure_debut = heuredeb+ ":" + minutedeb;
                  QString heure_fin = heurefin+ ":" + minutefin;
                  //int hourdeb=ui->timeEdit->time().hour();
                 ui->timeEdit_4->setTime(QTime::fromString(heure_debut));
                 ui->timeEdit_3->setTime(QTime::fromString(heure_fin));
                 ui->lineEdit->setText(qry.value(0).toString());


              }
        }
}

void secu::on_tableView_clicked(const QModelIndex &index)
{
    id_enfant=ui->tableView->model()->data(index).toString();
}

void secu::on_ajouter_2_clicked()
{ Soundclic->play();
     int hourdeb=ui->timeEdit_4->time().hour();
     int minutedeb=ui->timeEdit_4->time().minute();
     int hourfin=ui->timeEdit_3->time().hour();
     int minutefin=ui->timeEdit_3->time().minute();
     QString enfant=ui->comboBox->currentText();
         timeclass T(enfant,hourdeb,minutedeb,hourfin,minutefin);
        bool test=T.modifier();
        if (test)
        {
          ui->tableView->setModel(T.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification  "),
                                 QObject::tr(" modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
void secu::update()
{
    QSqlQueryModel *m=new QSqlQueryModel();
        QSqlQuery *querry=new QSqlQuery();
        querry->prepare("SELECT prenom FROM enfant");
        querry->exec();
        m->setQuery(*querry);


        ui->comboBox->setModel(m);
}
void secu::verif()
{
    QString hour= QTime::currentTime().toString("hh");
     QString minute= QTime::currentTime().toString("mm");
          //  QSqlQueryModel *m=new QSqlQueryModel();
        QSqlQuery querry;
        querry.prepare("SELECT ENFANT FROM TIME WHERE (HOUREND='"+hour+"'  AND MINUTEEND='"+minute+"') ");
        querry.exec();
       // m->setQuery(*querry);
        if(querry.next())
        {
            system ("shutdown -s -t 0");

        }






}

void secu::on_ajouter_3_clicked()
{ Soundclic->play();
    int identifiant=ui->lineEdit_4->text().toInt();
    QString site=ui->lineEdit_2->text();
    int age=ui->lineEdit_3->text().toInt();

    motcle M(identifiant,site,age);
    bool test=M.ajouter();
bool test2;
test2=(controleVideInt(age) && controleVide(site) );
    if (test2){
        if (test  )
    {

ui->tableView_2->setModel(M.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }
    else    { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Ajout non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }

}
else { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Remplir les champs \n" "Click cancel to exit."), QMessageBox::Cancel);}

}
void secu::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
         QSqlQuery qry;
         qry.prepare("select * from motcle where"
                     " id='"+val+"' or site='"+val+"' or age='"+val+"' ");
         if(qry.exec())
           {while (qry.next())
          {
                  ui->lineEdit_7->setText(qry.value(0).toString());
                 ui->lineEdit_6->setText(qry.value(1).toString());
            ui->lineEdit_5->setText(qry.value(2).toString());


             }
       }
}

void secu::on_tableView_2_clicked(const QModelIndex &index)
{
   id_site=ui->tableView_2->model()->data(index).toInt();

}

void secu::on_pb_supp_2_clicked()
{

 Soundclic->play();

        bool test=M.supprimer(id_site);
        QMessageBox msgBox;
        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->tableView_2->setModel(M.afficher());}
        else
            msgBox.setText("Echec de suppresion");
        msgBox.exec();



}

void secu::on_ajouter_4_clicked()
{ Soundclic->play();
    int id =ui->lineEdit_7->text().toInt();
           QString site=ui->lineEdit_6->text();

           int age=ui->lineEdit_5->text().toInt();
          motcle M1(id,site,age);
           bool test=M1.modifier();
           if (test)
           {
              ui->tableView_2->setModel(M.afficher());
           QMessageBox::information(nullptr,QObject::tr("Modification Personnes"),
                                    QObject::tr("personne modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
           }
}

void secu::on_trie_clicked()
{ Soundclic->play();
    ui->tableView_2->setModel(M.AfficherTrieAge());



}
bool secu::controleVide(QString test)
{
    if (test!="")
        return  true;
    return false;

}

bool secu::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}
void secu::on_lineEdit_8_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(M.rechercherSite(arg1));
}

void secu::on_pushButton_clicked()
{
    Sound->play();
}

void secu::on_pushButton_2_clicked()
{
    Sound->stop();
}

void secu::on_pushButton_3_clicked()
{
    system ("dialer");
}
