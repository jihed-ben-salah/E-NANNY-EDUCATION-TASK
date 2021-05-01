#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include"personned_aides.h"
#include "reclamation.h"
#include"smtp.h"
#include<QtMultimedia/QSound>
#include<QTimer>
#include <QDialog>
#include <QFileDialog>
#include <QtCharts>
namespace Ui {
class accueil;
}

class accueil : public QDialog
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = nullptr);
    ~accueil();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_securite_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::accueil *ui;
};

#endif // ACCUEIL_H
