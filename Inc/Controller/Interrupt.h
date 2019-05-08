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

class Interrupt
{
private:
  static Interrupt *instance;
  Trapezoid *trape = nullptr;
  TargetGenerator *target_trans = nullptr;
  Sensor *sensor = nullptr;

  bool control = false;
  bool sensor_light = false;

public:
  // 割り込みクラスのコンストラクタ
  Interrupt();

  // 割り込みクラスのデストラクタ
  ~Interrupt();

  // クラスのインスタンスを返す
  static Interrupt* getInstance();

  // 処理を行う
  void processing();

  // センサの割り込み処理を行う
  void sensorProcessing();

  // センサのフラグをセットする
  void setSensor( bool flag );

  // コントロールのフラグをセットする
  void setControl( bool flag );


private:
  ExistWall exist;
  Sensor_Data sen_front;
  Sensor_Data sen_left;
  Sensor_Data sen_right;
  
};


#endif /* __INTERRUPT__H */