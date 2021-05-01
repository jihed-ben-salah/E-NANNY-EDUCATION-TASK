
#include <QApplication>
#include "connection.h"
#include "dialog1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();

    Dialog1 d;
    if(test)

    d.show();

    return a.exec();
}
