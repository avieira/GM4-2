#include "fencalculatrice.h"
#include "ui_fencalculatrice.h"

FenCalculatrice::FenCalculatrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenCalculatrice)
{
    ui->setupUi(this);
}

FenCalculatrice::~FenCalculatrice()
{
    delete ui;
}
