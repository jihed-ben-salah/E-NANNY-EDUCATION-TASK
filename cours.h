#ifndef COURS_H
#define COURS_H
#include <QString>
#include <QWidget>

namespace Ui {
class Cours;
}

class Cours : public QWidget
{
    Q_OBJECT

public:
    explicit Cours(QWidget *parent = nullptr);
    Cours();
    Cours(QString,QString,QString,QString);
    ~Cours();
    void set_nomC(QString);
    void set_nomE(QString);
    void set_heureD(QString);
    void set_heureF(QString);
    QString get_nomC();
    QString get_nomE();
    QString get_heureD();
    QString get_heureF();
    bool ajouter();


private slots:
    void on_b_ajoutC_clicked();
    QString nomC;
    QString nomE;
    QString heureD;
    QString heureF;

private:
    Ui::Cours *ui;
};

#endif // COURS_H
