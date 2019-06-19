/**
 * main.cpp
 * @author yuta seya
 * @date 2019 3.25 
*/

#include <iostream>
#include <unistd.h>

#include "MauseSystem.h"

using namespace std;

int main()
{
 
  MauseSystem *mause = new MauseSystem();
  mause->peripheral_init();

  mause->waitStartThread();


  
  return 0;
}