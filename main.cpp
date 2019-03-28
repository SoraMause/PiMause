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

  Mode *mode = new Mode();

  mode->select();
  
  return 0;
}