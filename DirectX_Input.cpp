#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//�L�[�̉�����Ԃ��i�[�B
	if ( Keyinput[KEY_INPUT_Z] == 1) {	//Z�L�[�������ꂽ��
		DrawFormatString(0, 0, WhiteColor, "Z�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		DrawFormatString(0, 20, WhiteColor, "X�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_C] == 1) {
		DrawFormatString(0, 40, WhiteColor, "C�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_LEFT] == 1) {
		DrawFormatString(0, 60, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_RIGHT] == 1) {
		DrawFormatString(0, 80, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_UP] == 1) {
		DrawFormatString(0, 100, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_DOWN] == 1) {
		DrawFormatString(0, 120, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_SPACE] == 1) {
		DrawFormatString(0, 140, WhiteColor, "SPACE�L�[��������܂����B");
	}
}

//�����L�[�͂R���������ɂ͑Ή����ĂȂ��BMacbookAir 2012�̎d�l��������Ȃ����ǁB
//�R�����ɉ����đ��삷�邱�Ƃ͂Ȃ����낤���ꉞ�B