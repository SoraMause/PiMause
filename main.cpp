/**
 * main.cpp
 * @author yuta seya
 * @date 2019 3.25 
*/

#include <iostream>
#include <unistd.h>

#include "MauseSystem.h"
#include "Mode.h"
#include <thread>
#include "Interrupt.h"

using namespace std;

Mode *mode = new Mode();;
Interrupt * interrupt = Interrupt::getInstance();

void mode_run()
{  
  mode->select();
}

void interrupt_run()
{
  interrupt->processing();
}

void sensor_run()
{
  interrupt->sensorProcessing();
}

int main()
{
 
  MauseSystem *mause = new MauseSystem();
  mause->peripheral_init();
  std::thread th_a(mode_run);
  std::thread th_b(interrupt_run);
  std::thread th_c(sensor_run);

  th_a.join();
  th_b.join();
  th_c.join();
  
  return 0;
}