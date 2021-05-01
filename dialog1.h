#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include"accueil.h"
#include "arduino.h"
namespace Ui {
class Dialog1;
}
class QSystemTrayIcon;
class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
    bool controleVide(QString test);

private slots:
    void on_pushButton_clicked();
    void update_login();

void on_QUIT_clicked();
private:
    Ui::Dialog1 *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
    QSystemTrayIcon *icon;
};

#endif // DIALOG1_H
