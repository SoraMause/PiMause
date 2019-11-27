/**
 * Mode.h
 * @author yuta seya
 * @date 2019 3.28 
*/

#ifndef __MODE__H
#define __MODE__H

#include "Led.h"
#include "Buzzer.h"
#include "Switch.h"
#include "ModeCases.h"
#include "ControlThread.h"

class Mode {
private:
  Led *led = nullptr;
  Switch *sw = nullptr;
  ModeCases *cases = nullptr;
  ControlThread *th;

public:
  // コンストラクタ
  Mode();

  // デストラクタ
  ~Mode();

  // モードセレクト
  void select();


private:
  // 初期化
  void init();

  // モードに遷移させる
  void transition( int mode_number );
};

#endif /* __MODE__H */