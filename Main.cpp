#pragma once
#define _CRTDBG_MAP_ALLOC

#include "Header.h"

#include <stdlib.h>		//メモリリーク検出用
#include <crtdbg.h>		//メモリリーク検出用

using namespace std;

int JumpPower = 0;
int Player_X = 60;
int Player_Y = 0;
char Keys[256];



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);		//メモリリーク検出用
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//ウィンドウモードで起動
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	
//----------------------------------------------------------------------------------------------------------------
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		
		//MapDraw();
		KeyShow(Keys);
		Move(&Player_X, Keys);
		Jump(&JumpPower, &Player_Y, Keys);
		DrawPixel(Player_X, Player_Y, GetColor(255, 255, 255));	// 点を打つ
		
		
		ScreenFlip();
	}
				// キー入力待ち
//----------------------------------------------------------------------------------------------------------------
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	
	_CrtDumpMemoryLeaks();		//メモリリークレポートを [出力] ウィンドウのデバッグペインに出力します。 
	
	return 0;				// ソフトの終了 
}