#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {

	if (GetHitKeyStateAll(Keyinput) == KEY_INPUT_Z) {	//Z�L�[�������ꂽ��
		printfDx("Z�L�[��������܂���");
	}
}