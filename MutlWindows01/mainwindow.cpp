#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "dialog01.h"

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
    // SecondWindow를 포인터로 생성합니다.
    Dialog01 *secondWindow = new Dialog01(this); // 'this'를 부모로 지정
    secondWindow->setAttribute(Qt::WA_DeleteOnClose);
    secondWindow->show();

    /*
     * 또는, 모달(Modal) 대화상자로 열고 싶다면 (QDialog 기반으로 생성했을 경우)
     * QDialog *dialog = new QDialog(this);
     * dialog->exec();
     */
}

