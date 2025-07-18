#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_print_hellowold_clicked();

    void on_mariadb_connect_clicked();

    void on_sqlite_connect_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
