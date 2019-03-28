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

class Mode {
private:
  Led *led = nullptr;
  Buzzer *buzzer = nullptr;
  Switch *sw = nullptr;

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
};

#endif /* __MODE__H */