#include "DxLib.h"

void jump() {

}


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	double Player_X = 0;
	double Player_Y = 0;
	double JumpPower = 0;

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);
	while (true) {
		if (Player_Y > 300) {
			Player_Y = 300;
			JumpPower = 0;
		}
		
		if ((Key & PAD_INPUT_A) && Player_Y == 300) JumpPower = 20;


		DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	}
	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}