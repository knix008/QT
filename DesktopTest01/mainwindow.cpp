#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "println.h"
#include "ConnectDB.h"

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

void MainWindow::on_pushButton_clicked()
{
    if (connectDB()){
        printf("DB Connection Success!!!\n");
    }
    else{
        printf("DB Connection Failed!!!\n");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    println();
}

