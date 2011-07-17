/* winfo.h */

#ifndef WINFO_H
#define WINFO_H

#include "xwindow.h"
#define NITEMS 9

class winfo : public QWidget
{
	Q_OBJECT

	QCheckBox *qcbox[NITEMS];
	QLabel *left;
	QLabel *right;
	QPushButton *qb1;
	QPushButton *qb2;
	QPushButton *qb3;
	xwindow *client;
	QString res_name;
	QString res_class;
	QString clientname;
	
private slots:
	void release_temporary(void);
	void release_permanent(void);

public slots:	
	void release_cancel(void);

public:
	winfo(QWidget *parent=0);
	void show_info(xwindow *, QString &, QString &, QString &, QString &, QString &, int, int, int, int);
	QWidget *get_client(void)  { return(client); }
};
#endif
