#pragma once
#include "DxLib.h"
//-----キーボードからの入力
void KeyShow(char *);
const unsigned int WhiteColor = GetColor(255, 255, 255);//白色のカラーだああ。

//-----ジャンプするための関数
void Jump(int* JumpPower, double* Player_Y, const char* Keyinput);

//------マップ表示するだけ。背景？かも
void MapDraw();

//------移動というか座標を動かすだけ
void Move(double* Player_X, const char* Keys);


void Load_Yukari(int*);