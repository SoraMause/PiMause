/**
 * Mode.cpp
 * @author yuta seya
 * @date 2019 3.28 
*/

#include "Mode.h"

/**
 * @brief モードクラスのコンストラクタ
 * @param なし
 * @return　なし
*/
Mode::Mode()
{
  cases = new ModeCases();
  cases->init();
}

/**
 * @brief モードクラスのデストラクタ
 * @param なし
 * @return　なし
*/
Mode::~Mode()
{
  delete cases;
}

/**
 * @brief モードクラスの初期化
 * @param なし
 * @return　なし
*/
void Mode::init()
{
  if ( led == nullptr ){
    led = Led::getInstance();
  }

  if ( buzzer == nullptr ){
    buzzer = Buzzer::getInstance();
  }

  if ( sw == nullptr ){
    sw = Switch::getInstance();
  }

  led->illuminate( 0x00 );
}

/**
 * @brief モードセレクト
 * @param なし
 * @return　なし
*/
void Mode::select()
{
  init();

  bool sw0,sw1,sw2;
  int mode_count = 0;

  while( 1 ){
    sw0 = sw->get0();
    sw1 = sw->get1();
    sw2 = sw->get2();

    if ( sw0 ){
      mode_count++;
      if ( mode_count > 8 ) mode_count = 0;
      led->illuminate( mode_count );
      buzzer->on( A, 300 );
    }

    if ( sw1 ){
      mode_count--;
      if ( mode_count < 0 ) mode_count = 8;
      led->illuminate( mode_count );
      buzzer->on( C, 300 );
    }

    if ( sw2 ) {
      led->illuminate( 0x00 );
      buzzer->on( B, 300 );
      break;
    }
  }

  transition( mode_count );

}

/**
 * @brief モード遷移をする
 * @param int mode_number モードの番号
 * @return　なし
*/
void Mode::transition( int mode_number )
{

  switch( mode_number ){
    case 0:
      cases->checkMaze();
      break;

    case 1:
      cases->checkSensor();
      break;

    case 2:
      cases->checkTrape();
      break;

    case 3:
      cases->checkStepFrequency();
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;

    default:
      break;
  }
}