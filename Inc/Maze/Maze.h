/**
 * maze.h
 * @author yuta seya
 * @date 2019 3.13 
*/
#ifndef __MAZE__H
#define __MAZE__H

#include <stdint.h>
#include "mazeConf.h"
#include "Map.h"

struct Position
{
public:
  uint8_t x;
  uint8_t y;
  uint8_t direction;

  void init()
  {
    x = 0;
    y = 0;
    direction = 0;
  }
};

class Maze {
private:
  static Maze* instance;
  #define MAX_STEP 0xffff
  Map *map;
  uint8_t gx = 0;
  uint8_t gy = 0;
  uint16_t step[16][16];
  bool start = true;

public:
  // コンストラクタ
  Maze();

  Maze( uint8_t _gx, uint8_t _gy );

  // デストラクタ
  ~Maze();

  // インスタンスを得る
  static Maze* getInstance();

  // ゴール座標をセットする
  void setGoal( uint8_t _gx, uint8_t _gy );

  // 迷路情報のアップデートを行い、次の動作を返す
  uint8_t getNextAction( Position *pos, ExistWall *exist );

  // 歩数マップと壁情報を表示する
  void show( Position pos);

  // スタート動作かどうかのフラグをセットする
  void setStartFlag( bool _flag ) 
  {
    start = _flag;
  }

  // マップをリセットする
  void resetMap();
  
private:
  // 歩数マップを更新
  void updateStepMap();

  // 次の動作を決める
  uint8_t updateNextAction( Position *pos );

  // マシンの座標を更新する
  void updatePosition( Position *pos, uint8_t action );

};

#endif /* __MAZE__H */
