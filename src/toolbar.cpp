/*
*  File     : toolbar.cpp
*  Writen by: alinden@gmx.de
*  Copyright: GPL
*
*  Draw the toolbar and place items on it
*/

#include "defs.h"
#include "qapp.h"
#include "toolbar.h"

pager   *tb_pg;     // pager
winlist *tb_wl;     // winlist
menu    *tb_mn;     // menu
procbar *tb_pb;     // procbar
apbar   *tb_ap;     // apbox

Toolbar::Toolbar(QWidget *parent) : QFrame(parent)
{
	layout = new QHBoxLayout(0);
	layout->setSpacing(1);
	
	setFrameStyle(QFrame::Panel|QFrame::Raised);
	setLineWidth(1);

	setGeometry(0, (defaults::toolbar_top)?(0):(QApplication::desktop()->height()-defaults::tb_height),
	QApplication::desktop()->width(), defaults::tb_height);

	layout->addSpacing(4);

	// pager
	tb_pg = new pager(this);
	layout->addWidget(tb_pg);
	layout->addSpacing(3);

	// winlist
	if(defaults::show_winlist)
	{
		tb_wl = new winlist(this);
		layout->addWidget(tb_wl);
	}
	else
		tb_wl = new winlist(0);

	// menu
	if(defaults::show_menu)
	{
		tb_mn = new menu(this);
		layout->addWidget(tb_mn);
	}	
	else
		tb_mn = new menu(0);
		
	tb_mn->readmenu();

	if(defaults::show_menu || defaults::show_winlist)
		addsep();

	// procbar
	tb_pb = new procbar(this);
	tb_pb->setFixedHeight(defaults::tc_height);
	layout->addWidget(tb_pb);

	tb_ap = new apbar(this);
	layout->addWidget(tb_ap);

	layout->addSpacing(2);
	layout->setMargin(1);
	setLayout(layout);
	show();
}

void Toolbar::addsep(void)
{
	layout->addSpacing(3);
	QFrame *frame = new QFrame(this);
	frame->setLineWidth(1);
	frame->setMidLineWidth(0);
	frame->setFrameStyle(QFrame::VLine|QFrame::Sunken);
	frame->setFixedHeight(height()-4);
	layout->addWidget(frame);
	layout->addSpacing(3);
}
