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

}

/**
 * @brief モードクラスのデストラクタ
 * @param なし
 * @return　なし
*/
Mode::~Mode()
{

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
      if ( mode_count > 15 ) mode_count = 0;
      led->illuminate( mode_count );
      buzzer->on( A, 300 );
    }

    if ( sw1 ){
      mode_count--;
      if ( mode_count < 0 ) mode_count = 15;
      led->illuminate( mode_count );
      buzzer->on( C, 300 );
    }

    if ( sw2 ) {
      led->illuminate( 0x00 );
      break;
    }
    
  }
}