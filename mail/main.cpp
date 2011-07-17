/* main.cpp */

#include <QApplication>
#include "biff.h"


int main( int argc, char ** argv )
{
    QApplication a(argc, argv);
    biff b;
    return a.exec();
}
