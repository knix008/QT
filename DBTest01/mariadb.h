#ifndef MARIADB_H
#define MARIADB_H

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool mariadb_connect();

#endif // MARIADB_H
