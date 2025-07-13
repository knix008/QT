#include "dialog01.h"
#include "ui_dialog01.h"

Dialog01::Dialog01(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog01)
{
    ui->setupUi(this);
}

Dialog01::~Dialog01()
{
    delete ui;
}
