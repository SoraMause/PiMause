/**
 * ControlThread.h
 * @author yuta seya
 * @date 2019 5.8
*/

#ifndef __CONTROL_THREAD__H
#define __CONTROL_THREAD__H

#include "Interrupt.h"

class ControlThread
{
public:
  ControlThread();

  void run();

private:
  Interrupt *interrupt;

};

#endif /* __THREAD__H */