#include "dialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#define DRIVER "QSQLITE"
#define NOMBRE_BASE_DATOS "./data.db"

int creaBaseDatos()
{
    // preparación de la base de datos
    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qDebug() << "Driver no existe";
        return -1;
    }
    auto db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(NOMBRE_BASE_DATOS);
    if (!db.open()) {
        qDebug() << db.lastError().text();
        return -2;
    }
    return 0;
}

void configuraBaseDatos()
{
    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS usuario (id INTEGER PRIMARY KEY "
           "NOT NULL,nombre TEXT NOT NULL UNIQUE, contrasenya TEXT NOT NULL)");
    q.exec("CREATE TABLE IF NOT EXISTS administrador (id INTEGER PRIMARY "
           "KEY NOT NULL,nombre TEXT NOT NULL UNIQUE, "
           "contrasenya TEXT NOT NULL)");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const int resultado = creaBaseDatos();
    if (resultado < 0) {
        return resultado;
    }
    configuraBaseDatos();
    a.setStyle("fusion");
    Dialog login;
    if (login.exec() == QDialog::Rejected) {
        return -1;
    }
    MainWindow mainWindow(login.getTipo());
    mainWindow.show();
    return a.exec();
}
