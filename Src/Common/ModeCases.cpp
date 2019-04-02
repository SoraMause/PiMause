#include "ModeCases.h"

#include <cstdio>
#include <unistd.h>

#include "TargetGenerator.h"

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

  if ( trape == nullptr ){
    trape = Trapezoid::getInstance();
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

/**
 * @brief 台形加速をチェック
 * @param なし
 * @return　なし
*/
void ModeCases::checkTrape()
{
  float vel = 0.0f;

  trape->makeTrapezoid( 180.0f, 2000.0f, 500.0f, 0.0f, 0.0f );

  while( trape->status() == false ){
    vel = trape->getNextVelocity();
    std::printf( "%f\n", vel );
  }
}

void ModeCases::checkStepFrequency()
{
  float velocity = 0.0f;
  int left = 0;
  int right = 0;

  TargetGenerator *trans_target = new TargetGenerator();

  trape->makeTrapezoid( 180.0f, 2000.0f, 500.0f, 0.0f, 0.0f );

  std::printf("velocity ,left, right \r\n");

  while( trape->status() == false ){
    velocity = trape->getNextVelocity();
    trans_target->calcStepFrequency( velocity );
    trans_target->getStepFrequency( &left, &right, false );
    std::printf("%5.5f, %d, %d\r\n", velocity, left, right );
  }

  delete trans_target;
}