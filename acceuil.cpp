#include "acceuil.h"
#include "ui_acceuil.h"

acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);
}

acceuil::~acceuil()
{
    delete ui;
}
