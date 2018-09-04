#ifndef HANDLER_H
#define HANDLER_H

#include <QMainWindow>

namespace Ui {
class Handler;
}

class Handler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Handler(QWidget *parent = 0);
    ~Handler();

private slots:
     void insertData();


private:
    Ui::Handler *ui;
};

#endif // HANDLER_H
