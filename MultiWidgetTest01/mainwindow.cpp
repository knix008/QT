#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , secondWindow(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete secondWindow;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!secondWindow) {
        secondWindow = new SecondWindow();
        connect(secondWindow, &SecondWindow::goBack, this, &MainWindow::showMainWindow);
    }
    printf("Showing second window!!!\n");
    fflush(stdout);
    secondWindow->show();
    this->hide();
}

void MainWindow::showMainWindow()
{
    this->show();
    if (secondWindow)
        secondWindow->hide();
}
