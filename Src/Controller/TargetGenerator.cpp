/**
 * TargetGenerator.h
 * @author yuta seya
 * @date 2019 4.2
*/

#include "TargetGenerator.h"

/**
 * @brief 目標値の生成クラスのコンストラクタ
 * @param なし
 * @return　なし
*/
TargetGenerator::TargetGenerator()
{
  trape = Trapezoid::getInstance();
}

/**
 * @brief 目標値の生成クラスのコンストラクタ
 * @param なし
 * @return　なし
*/
TargetGenerator::~TargetGenerator()
{

}

/**
 * @brief ステップ周波数を返す
 * @param なし
 * @return　なし
*/
void TargetGenerator::getStepFrequency( int *left, int *right, bool back_right )
{
  // step_sensorの足し引きは暫定
  if ( back_right ){
    *left += -1 * (step_vel - step_sensor);
    *right += -1 * (step_vel + step_sensor);
  } else {
    *left += step_vel + step_sensor;
    *right += step_vel - step_sensor;
  }
}

/**
 * @brief 速度からステップ周波数を計算する
 * @param なし
 * @return　なし
*/
void TargetGenerator::calcStepFrequency( float velocity )
{
  float frequency = 0.0f;

  store_velocity = velocity;
  // v_step[step/sec] = v[mm/s] / d[mm/step]
  // v_step パルス周波数
  frequency = velocity / STEP_DISTANCE_CONST;

  step_vel = int(frequency);
}

/**
 * @brief センサの情報からフィードバック用ステップ周波数を計算する
 * @param なし
 * @return　なし
*/
int16_t TargetGenerator::clacSideSensorP(Sensor_Data& sen_left, Sensor_Data& sen_right, bool act, bool rotation)
{
  float step_value = 0.0f;
  if( act && !rotation && (store_velocity > 100.0f) && (sen_left.diff_3ms < 100 || sen_right.diff_3ms < 100) ){
    if(sen_left.now > sen_left.threshold && sen_right.now > sen_right.threshold){
      // 両壁があるとき
      step_value = (float)(sen_left.now-sen_left.reference) - (sen_right.now-sen_right.reference);
      step_value *= sensor_kp;
      if(step_value > 200) step_value = 200.0f;
      else if(step_value < -200) step_value = -200.0f;
    } else if(sen_left.now > sen_left.threshold){
      // 左壁があるとき
      step_value = (float)(sen_left.now-sen_left.reference);
      step_value *= 2.0f * sensor_kp;
      if(step_value > 200) step_value = 200.0f;
      else if(step_value < -50) step_value = -200.0f;
    } else if(sen_right.now > sen_right.threshold){
      // 右壁があるとき
      step_value = (float)(sen_right.now-sen_right.reference);
      step_value *= -2.0f * sensor_kp;
      if(step_value > 200) step_value = 200.0f;
      else if(step_value < -200) step_value = -200.0f;
    } else {
      step_value = 0.0f;
    } 
  }

  step_sensor = (int16_t)step_value;
  return step_sensor;
}