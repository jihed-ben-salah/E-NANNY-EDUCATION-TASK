#include "education.h"
#include "ui_education.h"
#include "cours1.h"
#include "arduino.h"
#include "activite.h"
#include "smtp.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPixmap>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQuery>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
#include <QFileDialog>
#include <QFile>
#include "secdialog.h"
#include<QTimeEdit>
#include<QTime>


Education::Education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Education)
{
    ui->setupUi(this);
    // MainWindow::makePlot();
    //player = new QMediaPlayer(this);
    // ui->heureD->setValidator(new QIntValidator(0, 99999999, this));
   //  ui->heureF->setValidator(new QIntValidator(0, 99999999, this));
     ui->coursView->setModel(C.afficher());
     ui->coursView_2->setModel(D.afficher());
     ui->activiteView->setModel(AC.afficher());
     ui->contactView->setModel(D.afficher_contact());
     update();
     combo_num();
     como_destinataire();
     combo_numero_activite();
     //combobox
     ui->etat->addItem("TO DO");
      ui->etat->addItem("Done");
      ui->etat_modifier->addItem("TO DO");
       ui->etat_modifier->addItem("Done");
     /*  ui->comboBox->addItem("Maths");
        ui->comboBox->addItem("Programmation");
         ui->comboBox->addItem("Physiques");
          ui->comboBox->addItem("Music");
           ui->comboBox->addItem("");
           */
           //background
           QPixmap pix5(":/img/background3.jpg");
           int w4 = ui->background->width();
           int h4 = ui->background->height();
           ui->background->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
           ui->background_2->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
            ui->background_3->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
             ui->background_4->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
              ui->background_5->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
               ui->background_6->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
               ui->background_7->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
                ui->background_8->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
                 ui->background_9->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
                  ui->background_10->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
                  ui->background_11->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
     //ajouter de l'image cours_pic
     QPixmap pix(":/img/dev.jpg");
     int w = ui->dev_pic->width();
     int h = ui->dev_pic->height();
     ui->dev_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     //logo
     QPixmap pix1(":/img/logo.jpg");
     int w1 = ui->logo->width();
     int h1 = ui->logo->height();
     ui->logo->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
      ui->logo_2->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
     //devoirs
     QPixmap pix2(":/img/devoir1.jpg");
     int w2 = ui->devoirs->width();
     int h2 = ui->devoirs->height();
     ui->devoirs->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
     //icons
     QPixmap pix3(":/img/home.png");
     QPixmap pix4(":/img/profil.png");
     int w3 = ui->home->width();
     int h3 = ui->home->height();
     ui->home->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
     ui->profile->setPixmap(pix4.scaled(w3,h3,Qt::KeepAspectRatio));
   //Arduino
       int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino est disponible and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).
}

Education::~Education()
{
    delete ui;
}
// COURS
void Education::on_b_ajoutC_clicked()
{      int numero=ui->numero->text().toInt();
       QString nomC=ui->nomC->text();
       QString nomE=ui->nomE->text();
       QString heureD=ui->heureD->text();
       QString heureF=ui->heureF->text();
       QString email=ui->email->text();
       Cours1 C(nomC,nomE,heureD,heureF,email,numero);
                bool test=C.ajouter();
          QMessageBox msgBox;

       if(test)
       {
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("Ajout effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
           ui->coursView->setModel(C.afficher());
            ui->contactView->setModel(D.afficher_contact());
           update();
           combo_num();
           como_destinataire();
}

       else
       {
           QMessageBox::information(nullptr,QObject::tr("not ok"),
                                    QObject::tr("Ajout n'est pas effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
       }
}
//*****************ComboBox******************
  void Education::update()
  {
          QSqlQueryModel *m=new QSqlQueryModel();
          QSqlQuery *querry=new QSqlQuery();
          querry->prepare("SELECT NOMC FROM COURS");
          querry->exec();
          m->setQuery(*querry);
          ui->comboBox->setModel(m);
          ui->cours->setModel(m);
          ui->cours_modifier->setModel(m);

  }
  void Education::combo_num()
  {
          QSqlQueryModel *m=new QSqlQueryModel();
          QSqlQuery *querry=new QSqlQuery();
          querry->prepare("SELECT NUMERO FROM COURS");
          querry->exec();
          m->setQuery(*querry);
          ui->numC->setModel(m);


  }
  void Education::como_destinataire()
  {
          QSqlQueryModel *m=new QSqlQueryModel();
          QSqlQuery *querry=new QSqlQuery();
          querry->prepare("SELECT EMAIL FROM COURS");
          querry->exec();
          m->setQuery(*querry);
          ui->Destinataire->setModel(m);


  }
  void Education::combo_numero_activite()
  {
          QSqlQueryModel *m=new QSqlQueryModel();
          QSqlQuery *querry=new QSqlQuery();
          querry->prepare("SELECT NUMERO FROM ACTIVITE");
          querry->exec();
          m->setQuery(*querry);
          ui->comboBox_supprimer_activiter->setModel(m);
           ui->num_modifier->setModel(m);

  }
//**********************************************
void Education::on_suppCours_3_clicked()
{
    QString NomC=ui->suppCours->text();
    bool test=C.supprimer(NomC);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
        update();
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("suppression n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}


void Education::on_modif_button_3_clicked()
{
    QString NOMC=ui->nomC_4->text();
    QString NOME=ui->nomE_2->text();
    QString HEURED=ui->heureD_2->text();
    QString HEUREF=ui->heureF_3->text();
    QString email=ui->email_2->text();
    int Numero=ui->numC->currentText().toInt();
    Cours1 C(NOMC,NOME,HEURED,HEUREF,email,Numero);
    bool test=C.modifier();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
        update();
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Modification n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}


void Education::on_chercher_clicked()
{
    ui->coursView->setModel(C.afficher());
    QString NOM = ui->lineEdit_chercher->text();
    ui->chercher_cours_2->setModel(C.chercher(NOM));
}
void Education::on_trier_cours_clicked()
{   if(ui->radioButton_numero->isChecked())
   {
        ui->coursView->setModel(C.trier_id());
    }
    else if(ui->radioButton_nom->isChecked())
    {
          ui->coursView->setModel(C.trier_nom());
    }
}
void Education::on_lineEdit_chercher_textChanged(const QString &arg1)
{
    ui->chercher_cours_2->setModel(C.chercher(arg1));

}
void Education::on_coursView_activated(const QModelIndex &index)
{
    QString val=ui->coursView->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from COURS where"
                          "NUMERO ='"+val+"'");
              if(qry.exec())
                {while (qry.next())
               { ui->nomC_4->setText(qry.value(0).toString());
                 //ui->numC->setText(qry.value(1).toString());
                 ui->nomE_2->setText(qry.value(2).toString());
                 //ui->heureD_2->setDateTime(qry.value(3).toString());
                 //ui->heureF_3->setTime(qry.value(4).toString());
               }
            }
}
void Education::on_coursView_clicked(const QModelIndex &index)
{
    id_eq=ui->coursView->model()->data(index).toInt();
}
void Education::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->coursView->render(&printer);
}

//DEVOIRS
void Education::on_b_ajout_dev_clicked()
{
    QString nomD=ui->nomD_lineEdit->text();
    int RefDev=ui->numD_lineEdit->text().toInt();
    QString NomC=ui->comboBox->currentText();
    QString Deadline=ui->deadline_lineEdit->text();
    Devoirs D(nomD,RefDev,NomC,Deadline);
    bool test=D.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Ajout effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
         ui->coursView_2->setModel(D.afficher());
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Ajout n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}



void Education::on_suppCours_4_clicked()
{
        QString NomD=ui->suppCours_6->text();
        bool test=D.supprimer(NomD);
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("supprission effectué\n"
                                                 "click Cancel to exit"),QMessageBox::Cancel);
           ui->coursView_2->setModel(D.afficher());
        }
        else
        {
            QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                     QObject::tr("supprission n'est pas effectué\n"
                                                 "click Cancel to exit"),QMessageBox::Cancel);
        }
}


void Education::on_imprimer_devoirs_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->coursView->render(&printer);
}

void Education::on_coursView_2_activated(const QModelIndex &indexx)
{
    QString vall=ui->coursView_2->model()->data(indexx).toString();
              QSqlQuery qry;
              qry.prepare("select * from DEVOIRS where"
                          "NOMD ='"+vall+"' or REFDEV='"+vall+"' or DEADLINE='"+vall+"' or NOMC='"+vall+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->nomD_modif->setText(qry.value(0).toString());
                 ui->numD_modif->setText(qry.value(1).toString());
                 ui->deadline_modif->setText(qry.value(2).toString());
                 ui->nomC_modif->setText(qry.value(3).toString());
               }
            }
}

void Education::on_coursView_2_clicked(const QModelIndex &indexx)
{
    id_Dev=ui->coursView_2->model()->data(indexx).toInt();
}

void Education::on_modifier_clicked()
{
    QString NOMD=ui->nomD_modif->text();
    QString DEADLINE=ui->deadline_modif->text();
    QString NOMC=ui->nomC_modif->text();
    Devoirs D(NOMD,id_Dev,DEADLINE,NOMC);
    bool test=D.modifier();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(D.afficher());
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Modification n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}

void Education::on_trier_cours_2_clicked()
{
    if(ui->radioButton_numero_2->isChecked())
    {
         ui->coursView_2->setModel(D.trier_id());
    }
    else if(ui->radioButton_nom_2->isChecked())
    {
        ui->coursView_2->setModel(D.trier_nom());
    }

}

void Education::on_chercher_2_clicked()
{
    ui->coursView_2->setModel(D.afficher());
    QString NOM = ui->lineEdit_chercher_2->text();
    ui->chercher_cours_3->setModel(D.chercher(NOM));
}
void Education::on_lineEdit_chercher_2_textChanged(const QString &arg1)
{
    ui->coursView_2->setModel(D.afficher());
    ui->chercher_cours_3->setModel(D.chercher(arg1));

}
void Education::on_pushButton_2_clicked()
{   QString filter = "All File (*.*)";
    QString file_name=QFileDialog::getOpenFileName(this,"Open a file","C:/cours/projet QT/Gestion des Cours/Supports/",filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
     file.flush();
     file.close();
}
bool Education::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool Education::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}
void Education::on_envoyer_clicked()
{
    QString mail_destinataire=ui->Destinataire->currentText();
    QString objet=ui->objet->text();
    QString message=ui->Message->text();
Smtp* smtp = new Smtp("jihedca111@gmail.com","Jiji@jiji123", "smtp.gmail.com");
smtp->sendMail("jihedca111@gmail.com",ui->Destinataire->currentText(),ui->objet->text(),ui->Message->text());

QMessageBox::information(nullptr,QObject::tr("ok"),
                         QObject::tr("Mail envoyé\n"
                                     "click Cancel to exit"),QMessageBox::Cancel);
 ui->Destinataire->clear();
 ui->objet->clear();
 ui->Message->clear();
}
//*********************Arduino*************************
void Education::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_11->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_11->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
      else if (data=="2")

       ui->label_11->setText("+");
    else if (data=="3")

     ui->label_11->setText("-");
}
void Education::on_on_clicked()
{
      A.write_to_arduino("1"); //envoyer 1 à arduino
}

void Education::on_off_clicked()
{
     A.write_to_arduino("0");  //envoyer 0 à arduino
}

void Education::on_plus_clicked()
{
     A.write_to_arduino("2");   //envoyer 2 à arduino
}

void Education::on_moins_clicked()
{
     A.write_to_arduino("3");  //envoyer 3 à arduino
}
//**********************************Activite***********************************
void Education::on_activite_ajouter_clicked()
{
    int numero=ui->numero_2->text().toInt();
    QString cours=ui->cours->currentText();
     QString activite=ui->activite->text();
      QString etat=ui->etat->currentText();
      Activite A(numero,cours,activite,etat);
      bool test;
      test = A.ajouter();
         QMessageBox msgBox;
      if(test)
      {
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("Ajout effectué\n"
                                               "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
        update();
}


      else
      {
          QMessageBox::information(nullptr,QObject::tr("not ok"),
                                   QObject::tr("Ajout n'est pas effectué\n"
                                               "click Cancel to exit"),QMessageBox::Cancel);
      }
}
/*void Education::makePlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
      ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
      ui->customPlot->xAxis->setLabel("x");
      ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
      ui->customPlot->xAxis->setRange(-1, 1);
      ui->customPlot->yAxis->setRange(0, 1);
      ui->customPlot->replot();
}
*/
QVector<double> Education::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    q.prepare("SELECT ETAT FROM ACTIVITE WHERE ETAT = 'TO DO'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT ETAT FROM ACTIVITE WHERE ETAT = 'Done'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    return stat;
}
void Education::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
        x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
        y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, Education::Statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"To Do"<<"Done";//<<"15-25"<<"25-35"<<"35-50";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);

}

void Education::on_stat_clicked()
{

   Education::makePlot();

}

void Education::on_trier_activite_clicked()
{
    if(ui->trie_done->isChecked())
     {
          ui->activiteView->setModel(AC.trier_done());
      }
      else if(ui->trie_toDo->isChecked())
      {
            ui->activiteView->setModel(AC.trier_toDo());
      }
    else if(ui->trie_all->isChecked())
    {
        ui->activiteView->setModel(AC.afficher());
    }
}

void Education::on_supprimer_activite_clicked()
{
    int NUMERO=ui->comboBox_supprimer_activiter->currentText().toInt();
    bool test=AC.supprimer(NUMERO);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->activiteView->setModel(AC.afficher());
        combo_numero_activite();
        update();
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("suppression n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}

void Education::on_nomrecherch_textChanged(const QString &arg1)
{
     ui->activiteView->setModel(AC.chercher(arg1));
}

void Education::on_activite_pushButton_modifier_clicked()
{
    QString COURS=ui->cours_modifier->currentText();
    QString ACTIVITE=ui->activite_modifier->text();
    QString ETAT=ui->etat_modifier->currentText();
    int NUMERO=ui->num_modifier->currentText().toInt();
    Activite AC(NUMERO,COURS,ACTIVITE,ETAT);
    bool test=AC.modifier();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);

        ui->activiteView->setModel(AC.afficher());
        update();
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Modification n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}
