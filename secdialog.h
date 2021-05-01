#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QTranslator>

#include <QDialog>
class QSqlTableModel;

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private:
    Ui::SecDialog *ui;
    QSqlTableModel *model;

private slots:

    QVector<double> Statistique();
    void makePlot ();
    void on_afficher_clicked();
};
#endif // SECDIALOG_H
