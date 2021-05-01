#ifndef PERSONNED_AIDES_H
#define PERSONNED_AIDES_H

#include<QString>
#include<QSqlQueryModel>
class Personned_aides
{
public:
     Personned_aides();
     Personned_aides(int,QString,QString,QString,QString,QString,int,int);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier();
     QSqlQueryModel * AfficherTrieNom();
     QSqlQueryModel * rechercherNom(QString metier);
         int Getidentifiant() { return identifiant; }
            void Setidentifiant(int val) { this->identifiant = val; }
            QString Getnom() { return nom; }
            void Setnom(QString val) { this->nom = val; }
            QString Getprenom() { return prenom; }
            void Setprenom(QString val) { this->prenom = val; }
            QString Getadresse() { return adresse; }
            void Setadresse(QString val) { this->adresse = val; }
            QString Getemail() { return email; }
            void Setemail(QString val) { this->email = val; }
            QString Getmetier() { return metier; }
            void Setmetier(QString val) { this->metier = val; }
            int Getprix_heure() { return prix_heure; }
            void Setprix_heure(int val) { this->prix_heure = val; }
            int Getnum_tel() { return num_tel; }
            void Setnum_tel(int val) {this-> num_tel = val; }
private:
    int identifiant;
            QString nom;
            QString  prenom;
            QString  adresse;
            QString  email;
            QString  metier;
            int prix_heure;
            int num_tel;
};

#endif // PERSONNED_AIDES_H
