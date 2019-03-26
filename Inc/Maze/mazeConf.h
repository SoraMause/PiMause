/**
 * mazeConf.h
 * @author yuta seya
 * @date 2019 3.13 
*/
#ifndef __MAZE_CONF__H
#define __MAZE_CONF__H

#include <stdint.h>

typedef enum {
  Front = 0,
  Left,
  Rear,
  Right,
}Action;

typedef enum {
  North = 0,
  West,
  South,
  East,
}Direction;


#endif /* __MAZE_CONF__H */