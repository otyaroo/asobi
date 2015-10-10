#pragma once
#define _CRTDBG_MAP_ALLOC

#include "Header.h"

#include <stdlib.h>		//メモリリーク検出用
#include <crtdbg.h>		//メモリリーク検出用

using namespace std;

int JumpPower = 0;
double Player_X = 80;
double Player_Y = 160;

int jump_temp = 0;		//ジャンプ用
int jump_prev = 0;		//ジャンプ用


const int Player_Width = 40;
const int Player_Height = 70;

char Keys[256];			//キー入力保存用配列



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//メモリリーク検出用
	SetWaitVSyncFlag(true);
	SetGraphMode(800, 640, 16);
	ChangeWindowMode(TRUE);		//ウィンドウモードで起動
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;
	}							// エラーが起きたら直ちに終了
	
	//ゆかりさん読み込み用画像ハンドル作成			24
	int* yukari = new int[24];
	Load_Yukari(yukari);
	//マップ読み込み用画像ハンドル作成＋読み込み	9
	int* MapObjGraph = new int[9];
	MapObjLoad(MapObjGraph);

	//接地判定用bool
	bool gnd = false;
//----------------------------------------------------------------------------------------------------------------
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();

		MapDraw(MapObjGraph);
		KeyShow(Keys);
		Move(&Player_X, Keys);
		gnd = ground_judge(Player_X, Player_Y, Player_Width, Player_Height);
		Jump(&JumpPower, &Player_Y, Keys, &jump_temp, &jump_temp, gnd);	//Verlet積分？なのを入れてみたよ。
		DrawExtendGraph(Player_X - 12, Player_Y - 15, Player_X + 52, Player_Y + 85, yukari[22], true);	//幅は64,高さは100で固定。それで二倍よ。
		{	//ゆかりさん判定。
			DrawLine(Player_X, 0, Player_X, 600, GetColor(255, 255, 0));	//左判定用
			DrawLine(Player_X + Player_Width, 0, Player_X + Player_Width, 600, GetColor(255, 255, 0)); //右判定用
			DrawLine(0, Player_Y, 800, Player_Y, GetColor(255, 255, 0));//上判定用
			DrawLine(0, Player_Y + Player_Height, 800, Player_Y + Player_Height, GetColor(255, 255, 0));//下判定用
		}	//若干ラインがゆかりさんより遅れてるように見える。判定時にどういうことになるのか…？
		
		{	//接地判定確認用
			if (gnd) { DrawFormatString(0, 600, WhiteColor, "True"); }
			else { DrawFormatString(0, 600, WhiteColor, "False"); }
		}
			
		ScreenFlip();

		if (Keys[KEY_INPUT_ESCAPE] == 1) {break;}		//終了条件 Escを押すと終了
	}		
//----------------------------------------------------------------------------------------------------------------
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	//newを解放
	delete[] yukari;
	delete[] MapObjGraph;

	_CrtDumpMemoryLeaks();		//メモリリークレポートを [出力] ウィンドウのデバッグペインに出力します。 
	
	return 0;				// ソフトの終了 
}