#include "fencalculatrice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenCalculatrice w;
    w.show();

    return a.exec();
}
