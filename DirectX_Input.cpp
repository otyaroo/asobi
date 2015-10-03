#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//キーの押下状態を格納。
	if ( Keyinput[KEY_INPUT_Z] == 1) {	//Zキーが押された時
		DrawFormatString(0, 0, WhiteColor, "Zキーが押されました。");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		DrawFormatString(0, 20, WhiteColor, "Xキーが押されました。");
	}
}