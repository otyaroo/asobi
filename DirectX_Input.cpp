#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//�L�[�̉�����Ԃ��i�[�B
	if ( Keyinput[KEY_INPUT_Z] == 1) {	//Z�L�[�������ꂽ��
		DrawFormatString(0, 0, WhiteColor, "Z�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		DrawFormatString(0, 20, WhiteColor, "X�L�[��������܂����B");
	}
}