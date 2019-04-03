/**
 * main.cpp
 * @author yuta seya
 * @date 2019 3.25 
*/

#include <iostream>
#include <unistd.h>

#include "MauseSystem.h"
#include "Mode.h"

using namespace std;

int main()
{
 
  MauseSystem *mause = new MauseSystem();
  mause->peripheral_init();

  Interrupt *interrupt = Interrupt::getInstance();
  interrupt->run();

  Mode *mode = new Mode();
  mode->run();
  
  return 0;
}