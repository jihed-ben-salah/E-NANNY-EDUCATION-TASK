#ifndef RECLAMATION_H
#define RECLAMATION_H

#include<QString>
#include<QSqlQueryModel>
class reclamation
{
public:
    reclamation();
     reclamation(int,QString,QString,QString,int);
     bool ajouter_reclamtion();
     QSqlQueryModel* afficher_reclamtion();
     bool supprimer_reclamtion(int);
     bool modifier_reclamtion();
         int Getidentifiant() { return identifiant; }
            void Setidentifiant(int val) { this->identifiant = val; }
            QString Getmail_destinataire() { return mail_destinataire; }
            void Setmail_destinataire(QString val) { this->mail_destinataire = val; }
            QString Getsujet() { return sujet; }
            void Setsujet(QString val) { this->sujet = val; }
            QString Getmessage() { return message; }
            void Setmessage(QString val) { this->message = val; }
            int Getpersonne_aide() { return personne_aide; }
            void Setpersonne_aide(int val) {this-> personne_aide = val; }
private:
            int identifiant;
            QString mail_destinataire;
            QString  sujet;
            QString  message;

            int personne_aide;

};

#endif // RECLAMATION_H
