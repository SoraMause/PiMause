/**
 * Sensor.cpp
 * @author yuta seya
 * @date 2019 3.27
*/

#ifndef __SENSOR__H
#define __SENSOR__H

#include "Map.h"
#include <cstdio>


struct Sensor_Data
{
  int now;            // 現在の値
  int reference;      // 真ん中のときのセンサー値
  int threshold;      // 閾値
  int diff_1ms;
  int diff_3ms;
  int before_1ms;
  int before_2ms;
  int before_3ms;
};

class Sensor{
private:
  static Sensor* instance;

  ExistWall exist;
  Sensor_Data sen_front;
  Sensor_Data sen_left;
  Sensor_Data sen_right;

  std::FILE *sensor_fp;

public:
  // センサークラスのコンストラクタ
  Sensor();

  // センサークラスのデストラクタ
  ~Sensor();

  // インスタンスを得る
  static Sensor* getInstance();

  // センサの情報を返す
  void get( Sensor_Data *front, Sensor_Data *left, Sensor_Data *right, ExistWall *real );

  // リファレンス値をセットする
  void setConstant( Sensor_Data *data, int reference, int threshold, int dir );

  // センサ値を表示
  void show();

private:
  // センサの処理を更新
  void update();
  
  // 壁があるかどうか判断する
  void checkWall();

  // センサの値を読み込む
  void read();

  // diffを更新
  void updateDiff();
  
};

#endif /* __SENSOR__H */