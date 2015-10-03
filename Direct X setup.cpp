#include "DirectX_Input.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//ウィンドウモードで起動
	char keys[256]; //キーの押下を格納する配列。
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		
		ClearDrawScreen();
		KeyShow(keys);
		DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
		ScreenFlip();
	}
				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}