#ifndef FENCALCULATRICE_H
#define FENCALCULATRICE_H

#include <QMainWindow>

namespace Ui {
class FenCalculatrice;
}

class FenCalculatrice : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenCalculatrice(QWidget *parent = 0);
    ~FenCalculatrice();

private:
    Ui::FenCalculatrice *ui;
};

#endif // FENCALCULATRICE_H
