#include "clock.h"

#include <QtCore/QTimer>
#include <QtCore/QDateTime>

Clock::Clock(QWidget *parent):
  QLabel(parent), _refreshTimer(new QTimer(this))
{
  connect(_refreshTimer,  SIGNAL(timeout()),
          this,           SLOT(refreshTime()));

  setSizePolicy(QSizePolicy::Minimum, sizePolicy().verticalPolicy());

  _refreshTimer->start(500);
}

void Clock::refreshTime()
{
  setText(QDateTime::currentDateTime().toString("dd/MM/yyyy - HH:mm:ss"));
}
