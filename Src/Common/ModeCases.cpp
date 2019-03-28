#include "ModeCases.h"

#include <cstdio>
#include <unistd.h>

/**
 * @brief モードケースクラスのコンストラクタ
 * @param なし
 * @return　なし
*/
ModeCases::ModeCases()
{

}

/**
 * @brief モードケースクラスのデストラクタ
 * @param なし
 * @return　なし
*/
ModeCases::~ModeCases()
{

}

/**
 * @brief モードケースクラスの初期化
 * @param なし
 * @return　なし
*/
void ModeCases::init()
{
  if ( led == nullptr ){
    led = Led::getInstance();
  }

  if ( sw == nullptr ){
    sw = Switch::getInstance();
  }

  if ( sensor == nullptr ){
    sensor = Sensor::getInstance();
  }

  if ( motor == nullptr ){
    motor = Motor::getInstance();
  }

  if ( maze == nullptr ){
    maze = Maze::getInstance();
  }  
}

/**
 * @brief センサ値をチェック
 * @param なし
 * @return　なし
 * @detail スイッチ1が押されたら終了
*/
void ModeCases::checkSensor()
{
  while( 1 ){
    sensor->show();
    if ( sw->get1() ) break;
  }
}

/**
 * @brief 壁情報をチェック
 * @param なし
 * @return　なし
*/
void ModeCases::checkMaze()
{
  Position pos;
  pos.init();
  maze->show( pos );
}