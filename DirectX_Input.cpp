#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//キーの押下状態を格納。
	int showpos = -20;
	int showpos2 = -20;
	if (Keyinput[KEY_INPUT_A] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Aキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_S] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Sキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_Z] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Zキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Xキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_C] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Cキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_LEFT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "←キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_RIGHT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "→キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_UP] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "↑キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_DOWN] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "↓キーが押されました。");
	}
	if (Keyinput[KEY_INPUT_SPACE] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "SPACEキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_LSHIFT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "左シフトキーが押されました。");
	}

}

//方向キーは３つ同時押しには対応してない。MacbookAir 2012の仕様かもしれないけど。
//３つ同時に押して操作することはないだろうが一応。

//とりあえずとして、ZXCキーの同時押しとカーソルキーの二つ同時押し。
//ZXC+カーソルキーｘ２＋シフト＋スペースキーの同時押しは可能。
