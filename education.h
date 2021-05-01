#ifndef EDUCATION_H
#define EDUCATION_H

#include <QDialog>
#include <cours1.h>
#include <devoirs.h>
#include<activite.h>

#include "arduino.h"
namespace Ui {
class Education;
}

class Education : public QDialog
{
    Q_OBJECT

public:
    explicit Education(QWidget *parent = nullptr);
    ~Education();
private slots:
    void on_b_ajoutC_clicked();

    void on_suppCours_3_clicked();

    void on_modif_button_clicked();

   void on_chercher_cours_clicked();

    void on_chercher_clicked();


    void on_trier_cours_clicked();

    void on_pushButton_clicked();

    void on_stat_clicked();

    void on_b_ajout_dev_clicked();

    void on_suppCours_4_clicked();

    void on_lineEdit_chercher_textChanged(const QString &arg1);

    void on_lineEdit_chercher_2_textChanged(const QString &arg1);

    void on_coursView_clicked(const QModelIndex &index);

    void on_coursView_activated(const QModelIndex &index);

    void on_modif_button_3_clicked(bool checked);

    void on_modif_button_3_clicked();

    void on_imprimer_devoirs_clicked();

    void on_coursView_2_activated(const QModelIndex &index);

    void on_coursView_2_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_trier_cours_2_clicked();

    void on_chercher_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);
    bool controleVide(QString test);
    bool controleVideInt(int test);

    void on_envoyer_clicked();

    void on_on_clicked();

    void on_off_clicked();

    void on_plus_clicked();

    void on_moins_clicked();
      void update_label();
    void  update();

      void on_activite_ajouter_clicked();
      QVector<double> Statistique();
      void makePlot ();
      void combo_num();
      void como_destinataire();
      void on_trier_activite_clicked();
      void combo_numero_activite();
      bool supprimer(int NUMERO);

      void on_supprimer_activite_clicked();

      void on_nomrecherch_textChanged(const QString &arg1);

      void on_activite_pushButton_modifier_clicked();
private:
    Ui::Education *ui;
    Cours1 C;
    Devoirs D;
    Activite AC;
   // QMediaPlayer *player;
    int id_eq=0;
    int id_Dev=0;
    QStringList files;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire

};

#endif // EDUCATION_H
