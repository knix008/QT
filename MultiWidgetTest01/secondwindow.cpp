#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    this->setGeometry(100, 100, 240, 320);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_backButton_clicked()
{
    printf("Go back to main window!!!\n");
    fflush(stdout);
    emit goBack();
}

