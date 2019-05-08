/**
 * Interrupt.cpp
 * @author yuta seya
 * @date 2019 4.2
*/
#include "Interrupt.h"

#include <iostream>
#include <unistd.h>

Interrupt* Interrupt::instance = nullptr;

/**
 * @brief 割り込みクラスのコンストラクタ
 * @param なし
 * @return　なし
*/
Interrupt::Interrupt()
{
  if ( trape == nullptr ){
    trape = Trapezoid::getInstance();
  }

  if ( target_trans == nullptr ){
    target_trans = new TargetGenerator();
  }

  if ( motor == nullptr ){
    motor = Motor::getInstance();
  }
}

/**
 * @brief 割り込みクラスのデストラクタ
 * @param なし
 * @return　なし
*/
Interrupt::~Interrupt()
{

}

/**
 * @brief interruptクラスのインスタンスを得る
 * @param なし
 * @return　interruptクラスのインスタンス
*/
Interrupt* Interrupt::getInstance()
{
  if ( instance == nullptr ){
    instance = new Interrupt();
  }
  return instance;
}

/**
 * @brief 割り込みの処理を行う
 * @param なし
 * @return　なし
*/
void Interrupt::processing()
{
  while( 1 ){
    processing_start = std::chrono::system_clock::now();
    
    velocity = trape->getNextVelocity();
    target_trans->calcStepFrequency( velocity );
    target_trans->getStepFrequency( &left, &right, trape->travelDirection() );    

    motor->control( left, right );

    processing_end = std::chrono::system_clock::now();
    
    double processing_time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(processing_end - processing_start).count() );

    uint32_t wait_time = (uint32_t)( 2000000 - processing_time );
    velocity = 0.0f;
    usleep( wait_time );
    
  }
}

/**
 * @brief コントロールフラグのセットをする
 * @param なし
 * @return　なし
*/
void Interrupt::setSensor( bool flag )
{
  sensor_light = flag;
}

/**
 * @brief センサフラグのセットをする
 * @param なし
 * @return　なし
*/
void Interrupt::setControl( bool flag )
{
  control = flag;
}

