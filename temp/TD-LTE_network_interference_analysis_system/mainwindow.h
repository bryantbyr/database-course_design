#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sign_up_clicked();

    void on_signin_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
};

#endif // MAINWINDOW_H
