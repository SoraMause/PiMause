/**
 * ModeCases.h
 * @author yuta seya
 * @date 2019 4.2
*/

#ifndef __MODE_CASES__H
#define __MODE_CASES__H

#include "Led.h"
#include "Sensor.h"
#include "Buzzer.h"
#include "Motor.h"
#include "Switch.h"
#include "Maze.h"

#include "Trapezoid.h"

class ModeCases {
private:
  Led *led = nullptr;
  Sensor *sensor = nullptr;
  Motor *motor = nullptr;
  Switch *sw = nullptr;
  Maze *maze = nullptr;
  Trapezoid *trape = nullptr;

public:
  // コンストラクタ
  ModeCases();

  // デストラクタ
  ~ModeCases();

  // 初期化
  void init();

  // センサの値をチェック
  void checkSensor();

  // 迷路情報のチェック
  void checkMaze();

  // 台形加速のチェック
  void checkTrape();

  // 台形加速の周波数のチェック
  void checkStepFrequency();

  // 台形加速を動作させる
  void moveTrapezoid();

  // 左90度ターン
  void moveTrapezoidTurnLeft();

  // 右90度ターン
  void moveTrapezoidTurnRight();

  // 180度ターン(左)
  void moveTrapezoidTurn180();

private:
};

#endif /* __MODE_CASES__H */