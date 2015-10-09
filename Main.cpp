#pragma once
#define _CRTDBG_MAP_ALLOC

#include "Header.h"

#include <stdlib.h>		//メモリリーク検出用
#include <crtdbg.h>		//メモリリーク検出用

using namespace std;

int JumpPower = 0;
double Player_X = 60;
double Player_Y = 0;




const int Player_Width = 40;
const int Player_Height = 70;

char Keys[256];



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//メモリリーク検出用
	SetWaitVSyncFlag(true);
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//ウィンドウモードで起動
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	//ゆかりさん読み込み用画像ハンドル作成
	int* yukari = new int[24];
	Load_Yukari(yukari);

//----------------------------------------------------------------------------------------------------------------
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		{	//ゆかりさん判定。
			DrawLine(Player_X, 0, Player_X, 600, GetColor(255, 255, 0));	//左判定用
			DrawLine(Player_X + Player_Width, 0, Player_X + Player_Width, 600, GetColor(255, 255, 0)); //右判定用
			DrawLine(0, Player_Y, 800, Player_Y, GetColor(255, 255, 0));//上判定用
			DrawLine(0, Player_Y + Player_Height, 800, Player_Y + Player_Height, GetColor(255, 255, 0));//下判定用
		}	//若干ラインがゆかりさんより遅れてるように見える。判定時にどういうことになるのか…？
																									//MapDraw();
		KeyShow(Keys);
		Move(&Player_X, Keys);
		Jump(&JumpPower, &Player_Y, Keys,&jump_temp,&jump_temp);	//Verlet積分？なのを入れてみたよ。
		DrawExtendGraph(Player_X -12 , Player_Y - 15, Player_X +52, Player_Y + 85 ,yukari[22], true);	//幅は64,高さは100で固定。それで二倍よ。
		
		
		ScreenFlip();
	}
				// キー入力待ち
//----------------------------------------------------------------------------------------------------------------
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	
	_CrtDumpMemoryLeaks();		//メモリリークレポートを [出力] ウィンドウのデバッグペインに出力します。 
	
	return 0;				// ソフトの終了 
}