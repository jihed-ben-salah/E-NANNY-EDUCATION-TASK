#ifndef SECU_H
#define SECU_H

#include <QDialog>
#include "timeclass.h"
#include "motcle.h"
#include "QtMultimedia/QSound"
#include "smtp.h"
#include "arduino.h"
namespace Ui {
class secu;
}

class secu : public QDialog
{
    Q_OBJECT

public:
    explicit secu(QWidget *parent = nullptr);
    ~secu();
    void update ();
    int difference ();
private slots:

     void update_label();
    void on_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_ajouter_2_clicked();

    void on_ajouter_3_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pb_supp_2_clicked();

    void on_ajouter_4_clicked();

    void on_trie_clicked();

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
bool controleVide(QString );
bool controleVideInt(int );

void verif();

void on_pushButton_3_clicked();
private:
    Ui::secu *ui;
    timeclass T;
    QString id_enfant;
    motcle M;
    int id_site=0;
    QSound *Sound;
QSound *Soundclic;
QTimer  *timer;

QByteArray data;
Arduino A;
};

#endif // SECU_H
