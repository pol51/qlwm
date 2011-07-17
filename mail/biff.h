/* 
*  File      :  biff.cpp
*  Written by:  alinden@gmx.de
*  Copyright :  GPL
*
*  Pops up a small envelope if mail is present.
*  Changes color if new mail arrives.
*/

#ifndef MAILBOX_H
#define MAILBOX_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QTimerEvent>
#include <QResizeEvent>
#include <QPaintEvent>

class biff : public QWidget
{
	Q_OBJECT

	QPixmap     hasmail;
	QPixmap     newmail;
	QString     mailfile;
	int         mailstate;

	enum state { Empty, Hasmail, Newmail };
	
protected:
	void	timerEvent(QTimerEvent *);
	void	paint_mailbox(void);
    
public:
	biff(QWidget *parent=0);
};

class mailbox : public QLabel
{
    QPixmap	envelope;
    void 	paint_mailbox(void);

public:
    mailbox(QWidget *parent=0);
    void 	set_pixmap(QPixmap &);
};
#endif
