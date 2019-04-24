#include "ControlThread.h"

#include <thread>

ControlThread::ControlThread()
{
  mode = new Mode();

  interrupt = new Interrupt();
}

void ControlThread::run()
{
  std::thread mode_th( [this]() { mode->select();} );
  std::thread interrupt_th( [this]() { interrupt->processing();} );
  
  mode_th.join();
  interrupt_th.detach();
}
