#include <QtGui/QApplication>
#include "gbcwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GBCWindow w;
    w.show();
    
    return a.exec();
}
