#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("jihed");//inserer nom de l'utilisateur
db.setPassword("jihed123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
