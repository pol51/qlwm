/*  
*   File      : dclock.h
*   Written by: alinden@gmx.de
*   Copyright : GPL
*
*   Shows a label with current time.
*/

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QFont>
#include <QLabel>
#include <QResizeEvent>

class dclock : public QLabel
{
	Q_OBJECT
	
	QTime time;
	QTimer *timer;
	void settime(QTime &);
	
public slots:
	void timeout(void);

protected:
	virtual void resizeEvent(QResizeEvent *);
	
public:
	dclock(QWidget *parent=0);
};
