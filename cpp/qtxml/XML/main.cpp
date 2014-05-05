#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
#ifdef Q_OS_SYMBIAN
    mainWin.showFullScreen();
#endif
    mainWin.show();
    mainWin.open();
    return app.exec();
}
