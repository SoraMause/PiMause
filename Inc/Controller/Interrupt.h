/**
 * Interrupt.h
 * @author yuta seya
 * @date 2019 4.2
*/
#ifndef __INTERRUPT__H
#define __INTERRUPT__H

#include "Trapezoid.h"
#include "TargetGenerator.h"
#include "Sensor.h"
#include "Map.h"

#include <chrono>
#include "Motor.h"

class Interrupt
{
private:
  static Interrupt *instance;
  Trapezoid *trape = nullptr;
  TargetGenerator *target_trans = nullptr;
  Sensor *sensor = nullptr;
  Motor *motor = nullptr;

  int left = 0;
  int right = 0;
  float velocity = 0.0f;
  
  // 時間を計測するための変数
  std::chrono::system_clock::time_point processing_start, processing_end;

public:
  // 割り込みクラスのコンストラクタ
  Interrupt();

  // 割り込みクラスのデストラクタ
  ~Interrupt();

  // クラスのインスタンスを返す
  static Interrupt* getInstance();

  // 処理を行う
  void processing();

  // sensor
  void sensorProcessing();

private:
  Sensor_Data sen_front;
  Sensor_Data sen_left;
  Sensor_Data sen_right;
  
};


#endif /* __INTERRUPT__H */
