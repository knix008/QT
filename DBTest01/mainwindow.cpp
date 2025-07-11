#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "printhelloworld.h"
#include "mariadb.h"
#include "sqlite.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_print_hellowold_clicked()
{
    printhelloworld();
}


void MainWindow::on_mariadb_connect_clicked()
{
    mariadb_connect();
}


void MainWindow::on_sqlite_connect_clicked()
{
    sqlite_connect();
}

