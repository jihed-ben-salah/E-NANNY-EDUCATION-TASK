#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();

private:
    Ui::acceuil *ui;
};

#endif // ACCEUIL_H
