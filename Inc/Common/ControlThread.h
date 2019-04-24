#ifndef __CONTROL_THREAD__H
#define __CONTROL_THREAD__H

#include "Mode.h"
#include "Interrupt.h"

class ControlThread
{
public:
  ControlThread();

  void run();

private:
  Mode *mode;
  Interrupt *interrupt;

};

#endif /* __THREAD__H */