/**
 * map.cpp
 * @author yuta seya
 * @date 2019 3.13
*/

#include "Map.h"

#include <cstdio>

/**
 * @brief マップクラスのコンストラクタ
 * @param なし
 * @return　なし
*/
Map::Map()
{

}

/**
 * @brief マップクラスのデストラクタ
 * @param なし
 * @return　なし
*/
Map::~Map()
{

}

/**
 * @brief 壁情報の初期化
 * @param なし
 * @return　なし
 * @detail マイクロマウスのルールに合わせて初期壁の追加,
 *         壁情報の初期化を行う.
*/
void Map::init()
{
  for ( int i = 0; i < 17; i++ ){
    wall.vertical[i] = 0x0000;
    wall.horizontal[i] = 0x0000;
    wall.vertical_known[i] = 0x0000;
    wall.horizontal_knwon[i] = 0x0000;

  }

  // 外周、スタートの右壁を追加
  wall.vertical[0] = 0xffff;
  wall.vertical[1] = 0x0001;
  wall.horizontal[0] = 0xffff;
  wall.vertical[16] = 0xffff;
  wall.horizontal[16] = 0xffff;

  wall.vertical_known[0] = 0xffff;
  wall.vertical_known[1] = 0x0001;
  wall.horizontal_knwon[0] = 0xffff;
  wall.vertical_known[16] = 0xffff;
  wall.horizontal_knwon[16] = 0xffff;
}

/**
 * @brief 壁情報の追加
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param ExistWall *exist 壁があるかないかの情報が入っている構造体
 * @param uint8_t direction マウスの向き
 * @return　なし
 * @detail 引数に与えられた座標の壁情報を追加する.
*/
void Map::addWall(  uint8_t x, uint8_t y, ExistWall *exist, uint8_t direction )
{
  switch( direction ){
    case North:
      if ( exist->left ){
        manegeWestWall( x, y, true );
      } else {
        manegeWestWall( x, y, false );
      }

      if ( exist->right ){
        manegeEastWall( x, y, true );
      } else {
        manegeEastWall( x, y, false );
      }

      if ( exist->front ){
        manegeNorthWall( x, y, true );
      } else {
        manegeNorthWall( x, y, false );
      }
      break;

    case West:
      if ( exist->left ){
        manegeSouthWall( x, y, true );
      } else {
        manegeSouthWall( x, y, false );
      }

      if ( exist->right ){
        manegeNorthWall( x, y, true );
      } else {
        manegeNorthWall( x, y, false );
      }

      if ( exist->front ){
        manegeWestWall( x, y, true );
      } else {
        manegeWestWall( x, y, false );
      }
      break;

    case South:
      if ( exist->left ){
        manegeEastWall( x, y, true );
      } else {
        manegeEastWall( x, y, false );
      }

      if ( exist->right ){
        manegeWestWall( x, y, true );
      } else {
        manegeWestWall( x, y, false );
      }

      if ( exist->front ){
        manegeSouthWall( x, y, true );
      } else {
        manegeSouthWall( x, y, false );
      }
      break;

    case East:
      if ( exist->left ){
        manegeNorthWall( x, y, true );
      } else {
        manegeNorthWall( x, y, false );
      }

      if ( exist->right ){
        manegeSouthWall( x, y, true );
      } else {
        manegeSouthWall( x, y, false );
      }

      if ( exist->front ){
        manegeEastWall( x, y, true );
      } else {
        manegeEastWall( x, y, false );
      }
      break;

  }
}

/**
 * @brief 壁情報の読み出し
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param uint8_t direction 取得したい壁の方位
 * @return bool 壁情報　有 : true, 無 : false
 * @detail 引数に与えられた座標、方向の壁情報を返す
*/
bool Map::getData( uint8_t x, uint8_t y, uint8_t direction )
{
  uint16_t check_wall = 1;
  bool exist = false;

  if ( direction > East ){
    direction -= 4;
  }

  if ( direction == North ){
        check_wall <<= x;
        check_wall &= wall.horizontal[y + 1];
        if (check_wall != 0) {
            exist = true;
        } else {
      exist = false;
    }

  } else if ( direction == East ){
        check_wall <<= y;
        check_wall &= wall.vertical[x + 1];
        if (check_wall != 0) {
            exist = true;
        } else {
      exist = false;
    }

  } else if ( direction == South ){
        check_wall <<= x;
        check_wall &= wall.horizontal[y];
        if (check_wall != 0) {
            exist = true;
        } else {
      exist = false;
    }
  } else if ( direction == West ){
        check_wall <<= y;
        check_wall &= wall.vertical[x];
        if (check_wall != 0) {
            exist = true;
        } else {
      exist = false;
    }
  }

  return exist;
}

/**
 * @brief 北壁情報の追加/削除
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param bool exist 壁が存在するか否か
 * @return　なし
 * @detail 引数に与えられた座標の北壁情報を追加する.
*/
void Map::manegeNorthWall( uint8_t x, uint8_t y, bool exist )
{
  uint16_t data = 1;
  data <<= x;
  wall.horizontal_knwon[y+1] |= data;
  if ( exist ){
    wall.horizontal[y+1] |= data;
  } else {
    wall.horizontal[y+1] &= ~data;
  }
}

/**
 * @brief 南壁情報の追加/削除
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param bool exist 壁が存在するか否か
 * @return　なし
 * @detail 引数に与えられた座標の南壁情報を追加する.
*/
void Map::manegeSouthWall( uint8_t x, uint8_t y, bool exist )
{
  uint16_t data = 1;
  data <<= x;
  wall.horizontal_knwon[y] |= data;
  if ( exist ){
    wall.horizontal[y] |= data;
  } else {
    wall.horizontal[y] &= ~data;
  }
}

/**
 * @brief 西壁情報の追加/削除
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param bool exist 壁が存在するか否か
 * @return　なし
 * @detail 引数に与えられた座標の西壁情報を追加する.
*/
void Map::manegeWestWall( uint8_t x, uint8_t y, bool exist )
{
  uint16_t data = 1;
  data <<= y;
  wall.vertical_known[x] |= data;
  if ( exist ){
    wall.vertical[x] |= data;
  } else {
    wall.vertical[x] &= ~data;
  }
}

/**
 * @brief 東壁情報の追加/削除
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param bool exist 壁が存在するか否か
 * @return　なし
 * @detail 引数に与えられた座標の東壁情報を追加する.
*/
void Map::manegeEastWall( uint8_t x, uint8_t y, bool exist )
{
  uint16_t data = 1;
  data <<= y;
  wall.vertical_known[x+1] |= data;
  if ( exist ){
    wall.vertical[x+1] |= data;
  } else {
    wall.vertical[x+1] &= ~data;
  }
}

/**
 * @brief 壁情報の追加
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @param bool n,w,s,e それぞれの方向の壁情報を入力
 * @return　なし
 * @detail 引数に与えられた座標の壁情報を追加する.
*/
void Map::addWall(uint8_t x, uint8_t y, bool n, bool w, bool s, bool e )
{
    if ( n ) manegeNorthWall(x,y,true);
    else manegeNorthWall(x,y,false);

    if ( w ) manegeWestWall(x,y,true);
    else manegeWestWall(x,y,false);

    if ( s ) manegeSouthWall(x,y,true);
    else manegeSouthWall(x,y,false);

    if ( e ) manegeEastWall(x,y,true);
    else manegeEastWall(x,y,false);
}

/**
 * @brief 探索をしたかどうかを返す
 * @param uint8_t x マウスのx座標
 * @param uint8_t y マウスのy座標
 * @return bool t or f
 * @detail 引数に与えられた座標が探索済みかどうかを返す
*/
bool Map::checkWall(uint8_t x, uint8_t y)
{
    bool n,s,w,e;
    uint16_t check_wall = 1;
    bool check = false;

    // north
    check_wall <<= x;
    check_wall &= wall.horizontal_knwon[y + 1];
    if (check_wall != 0) n = true;
    else n = false;
    check_wall = 1;


    // east
    check_wall <<= y;
    check_wall &= wall.vertical_known[x + 1];
    if (check_wall != 0) e = true;
    else e = false;
    check_wall = 1;

    // south
    check_wall <<= x;
    check_wall &= wall.horizontal_knwon[y];
    if (check_wall != 0) s = true;
    else s = false;
    check_wall = 1;

    // west
    check_wall <<= y;
    check_wall &= wall.vertical_known[x];
    if (check_wall != 0) w = true;
    else w = false;

    if ( n == true && e == true && s == true && w == true ) check = true;
    else check = false;

    return check;

}

void Map::storeWall()
{
  std::FILE *fp;
  fp = std::fopen("maze.txt", "w");
  fprintf(fp,"dummy\n");
  for (int i = 0; i < 17; i++)
  {
    std::fprintf(fp, "%d\n", wall.horizontal[i]);
  }

  for (int i = 0; i < 17; i++)
  {
    std::fprintf(fp, "%d\n", wall.vertical[i]);
  };

  for (int i = 0; i < 17; i++)
  {
    std::fprintf(fp, "%d\n", wall.horizontal_knwon[i]);
  }

  for (int i = 0; i < 17; i++)
  {
    std::fprintf(fp, "%d\n", wall.vertical_known[i]);
  };

  std::fclose(fp);

}

void Map::loadWall()
{
  std::FILE *fp;
  fp = std::fopen("maze.txt", "r");

  if(fp == NULL){
    std::printf("maze.txt not found\n");
    return;
  }

  char dummy[10];
  std::fscanf(fp ,"%s", dummy);
  std::printf("%s", dummy);
  for(int i = 0; i < 17; i++){
    std::fscanf(fp, "%d", &wall.horizontal[i]);
  }
  wall.horizontal[0] = 0xffff;

  for(int i = 0; i < 17; i++){
    std::fscanf(fp, "%d", &wall.vertical[i]);
  }

  for(int i = 0; i < 17; i++){
    std::fscanf(fp, "%d", &wall.horizontal_knwon[i]);
  }
  wall.horizontal_knwon[0] = 0xffff;

  for(int i = 0; i < 17; i++){
    std::fscanf(fp, "%d", &wall.vertical_known[i]);
  }
  

  fclose(fp);
  
}