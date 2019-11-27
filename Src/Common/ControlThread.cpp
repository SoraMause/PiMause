/**
 * ControlThread.cpp
 * @author yuta seya
 * @date 2019 5.8
*/

#include "ControlThread.h"

#include <thread>

ControlThread::ControlThread()
{
  mode = new Mode();

  interrupt = Interrupt::getInstance();
}

void ControlThread::run()
{
  std::thread mode_th( [this]() { mode->select();} );
  std::thread interrupt_th( [this]() { interrupt->processing();} );
  
  mode_th.join();
  interrupt_th.join();
}
