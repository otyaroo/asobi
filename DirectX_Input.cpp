#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//キーの押下状態を格納。
	if ( Keyinput[KEY_INPUT_Z] == 1) {	//Zキーが押された時
		DrawFormatString(0, 0, WhiteColor, "Zキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		DrawFormatString(0, 20, WhiteColor, "Xキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_C] == 1) {
		DrawFormatString(0, 40, WhiteColor, "Cキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_LEFT] == 1) {
		DrawFormatString(0, 60, WhiteColor, "←キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_RIGHT] == 1) {
		DrawFormatString(0, 80, WhiteColor, "→キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_UP] == 1) {
		DrawFormatString(0, 100, WhiteColor, "↑キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_DOWN] == 1) {
		DrawFormatString(0, 120, WhiteColor, "↓キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_SPACE] == 1) {
		DrawFormatString(0, 140, WhiteColor, "SPACEキーが押されました。");
	}
}

//方向キーは３つ同時押しには対応してない。MacbookAir 2012の仕様かもしれないけど。
//３つ同時に押して操作することはないだろうが一応。