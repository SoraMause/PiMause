/**
 * MauseSystem.cpp
 * @author yuta seya
 * @date 2019 3.28 
*/

#include "MauseSystem.h"

/**
 * @brief マウスシステムクラスのコンストラクタ
 * @param なし
 * @return　なし
*/
MauseSystem::MauseSystem()
{
  
}

/**
 * @brief マウスシステムクラスのデストラクタ
 * @param なし
 * @return　なし
*/
MauseSystem::~MauseSystem()
{

}

/**
 * @brief 周辺機能の初期化(インスタンスを得る)
 * @param なし
 * @return　なし
*/
void MauseSystem::peripheral_init()
{
  buzzer = Buzzer::getInstance();
  led = Led::getInstance();
  sw = Switch::getInstance();
  sensor = Sensor::getInstance();
  motor = Motor::getInstance();
  interrupt = Interrupt::getInstance();

  led->illuminate( 0x0f );
  buzzer->on( C, 300 );
  led->illuminate( 0x00 );
}

