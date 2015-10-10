#pragma once
#include "DxLib.h"
#define MAP_SIZE 64
#define MAP_WIDTH 80
#define MAP_HEIGHT 80

//-----キーボードからの入力
void KeyShow(char *);
const unsigned int WhiteColor = GetColor(255, 255, 255);//白色のカラーだああ。

//-----ジャンプするための関数
void Jump(int* JumpPower, double* Player_Y, const char* Keyinput,int* jump_temp, int* jump_prev, bool grund_judge);

//------マップオブジェクト画像のロード
void MapObjLoad(int*);

//------マップ表示するだけ。背景？かも
void MapDraw(int* MapObjGraph);

//-----接地判定用関数
bool ground_judge(const double Player_x, const double Player_y, const int width, const int height);

//------移動というか座標を動かすだけ
void Move(double* Player_X, const char* Keys);

//------キャラクター画像の読み込み
void Load_Yukari(int*);

const int MapDatas[8][10] = {

	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,1,1,1,1,1,1,0 },
	{ 0,1,0,1,1,0,0,0,1,0 },
	{ 0,1,1,1,1,0,0,0,1,0 },
	{ 0,1,0,1,0,0,0,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};

