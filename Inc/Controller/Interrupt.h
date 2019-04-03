/**
 * Interrupt.h
 * @author yuta seya
 * @date 2019 4.2
*/
#ifndef __INTERRUPT__H
#define __INTERRUPT__H

#include "Trapezoid.h"
#include "TargetGenerator.h"

class Interrupt
{
private:
  static Interrupt *instance;

  Trapezoid *trape = nullptr;
  TargetGenerator *target_trans = nullptr;

  bool control = false;
  bool sensor = false;

public:
  // 割り込みクラスのコンストラクタ
  Interrupt();

  // 割り込みクラスのデストラクタ
  ~Interrupt();

  // インスタンスを得る
  static Interrupt* getInstance();

  // 処理を行う
  void processing();

  // センサのフラグをセットする
  void setSensor( bool flag );

  // コントロールのフラグをセットする
  void setControl( bool flag );

  // スレッドを実行する
  void run();

};


#endif /* __INTERRUPT__H */