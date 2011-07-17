#include <QApplication>
#include "dclock.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	dclock *dc = new dclock;
	dc->show();
	return a.exec();
}
