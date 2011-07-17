/* 
*  File      :  biff.cpp
*  Written by:  alinden@gmx.de
*  Copyright :  GPL
*
*  Pops up a small envelope if mail is present.
*  Changes color if new mail arrives.
*/

#include <QFileInfo>
#include <QPixmap>
#include <QTimerEvent>
#include <QByteArray>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QDateTime>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "conf.h"
#include "mail.xpm"
#include "newmail.xpm"
#include "moc_biff.cpp"

biff::biff(QWidget *parent) : QWidget(parent)
{
	QString s(getenv("MAIL"));
	QFileInfo fi = s;
	if(! fi.exists()) 
	{
		s = MAILDIR;
		s += getlogin();
		fi.setFile(s);
	}

	if(fi.exists())
	{
		mailfile = fi.absoluteFilePath();
		startTimer(3000);
    	}
	else
	{
		QByteArray qb(s.toAscii());
		perror((char *)qb.data());
		exit(1);
	}

	hasmail = QPixmap((const char **)mail_xpm);
	newmail = QPixmap((const char **)newmail_xpm);
	
	mailstate = Empty;
}

void biff::timerEvent(QTimerEvent *)
{
	static mailbox *mbox = NULL;
	QFileInfo fi(mailfile);
	
	if(mailstate != Empty && fi.size() == 0)
	{
		if(mbox != NULL)
		{
			delete mbox;
			mbox = NULL;
		}
		mailstate = Empty;
	}
	else if(mailstate != Newmail && fi.lastModified() > fi.lastRead() && fi.size())
	{
		if(mbox == NULL)
			mbox = new mailbox();

		mbox->setPixmap(newmail);
		mailstate = Newmail;
	}
	else if(mailstate != Hasmail && fi.size() && fi.lastRead() > fi.lastModified() && fi.size())
	{
		if(mbox == NULL)
			mbox = new mailbox();

		mbox->setPixmap(hasmail);
		mailstate = Hasmail;
	}
}

mailbox::mailbox(QWidget *parent) : QLabel(parent)
{
	resize(16, 16);
	show();
}
