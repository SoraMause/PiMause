/**
 * TargetGenerator.h
 * @author yuta seya
 * @date 2019 4.2
*/
#ifndef __TARGET_GENERATOR__H
#define __TARGET_GENERATOR__H

#include "Trapezoid.h"

#include "Sensor.h"

class TargetGenerator
{
private:
  Trapezoid *trape;

  int step_vel = 0;
  int step_sensor = 0.0f;

  // TIRE_RADIUS 48.0f
  // d[mm/step] = 48.0 * ( 0.9 * pi / 360)
  #define STEP_DISTANCE_CONST 0.37699111843 

public:
  // コンストラクタ
  TargetGenerator();

  // デストラクタ
  ~TargetGenerator();

  // ステップ周波数を返す
  void getStepFrequency( int *left, int *right, bool back_right );

  // 速度からステップ周波数の目標値を計算する
  void calcStepFrequency( float velocity );

  // センサの値からフィードバックする
  int16_t clacSensorP( Sensor_Data *sen_front, Sensor_Data *sen_left, Sensor_Data *sen_roght, bool rotation );
};




#endif /* __TARGET_GENERATOR__H */