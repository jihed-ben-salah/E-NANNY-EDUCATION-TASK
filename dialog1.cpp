#include "dialog1.h"
#include "ui_dialog1.h"
#include <QSystemTrayIcon>
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_login()));
    connect(ui->QUIT,SIGNAL(clicked()),this,SLOT(quit()));

icon=new QSystemTrayIcon(this);
icon->setIcon(QIcon(":/img/myappico.png"));
icon->setVisible(true);

}

Dialog1::~Dialog1()
{
    delete ui;
}
bool Dialog1::controleVide(QString test)
{
    if(test=="admin")
        return  true;
    return false;

}

void Dialog1::on_pushButton_clicked()
{A.write_to_arduino("1");
    bool test1;
   QMessageBox msgBox;

     QString login=ui->login->text();
     QString mdp=ui->mdp->text();
     accueil a;
    test1=(controleVide(login)&&controleVide(mdp));
    if (test1==true)
    {icon->showMessage(tr("notification"),tr("vous êtes toujours la bienvenue "));
    a.setModal(true);

    a.exec();

    }
    else
         {

        msgBox.setText("mot de passe ou login incorrect ");


        msgBox.exec();
    }

}
void Dialog1::update_login()
{
      ui->acces->setText("");
    data=A.read_from_arduino();
    qDebug()<< "data est  "<<data;


    if(data=="0")

       { ui->login->setText("admin");
         ui->mdp->setText("admin");

       }
    else if(data=="2")
        {
        ui->acces->setText("accés non autorisé");
        }



}
void Dialog1::on_QUIT_clicked()
{
   A.write_to_arduino("5");


}
