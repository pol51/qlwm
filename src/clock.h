#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <QtGui/QLabel>

class QTimer;

class Clock : public QLabel
{
  Q_OBJECT

  public:
    Clock(QWidget *parent = NULL);

  protected slots:
    void refreshTime();

  protected:
    QTimer *_refreshTimer;
};

#endif
