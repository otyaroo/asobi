#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {

	if (GetHitKeyStateAll(Keyinput) == KEY_INPUT_Z) {	//Zキーが押された時
		printfDx("Zキーが押されました");
	}
}