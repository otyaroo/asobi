#include "DirectX_Input.h"

void KeyShow(char* Keyinput) {
	GetHitKeyStateAll(Keyinput);//�L�[�̉�����Ԃ��i�[�B
	int showpos = -20;
	int showpos2 = -20;
	if (Keyinput[KEY_INPUT_A] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "A�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_S] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "S�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_Z] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "Z�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_X] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "X�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_C] == 1) {
		showpos += 20;
		DrawFormatString(0, showpos, WhiteColor, "C�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_LEFT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_RIGHT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_UP] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_DOWN] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "���L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_SPACE] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "SPACE�L�[��������܂����B");
	}
	if (Keyinput[KEY_INPUT_LSHIFT] == 1) {
		showpos2 += 20;
		DrawFormatString(600, showpos2, WhiteColor, "���V�t�g�L�[��������܂����B");
	}

}

//�����L�[�͂R���������ɂ͑Ή����ĂȂ��BMacbookAir 2012�̎d�l��������Ȃ����ǁB
//�R�����ɉ����đ��삷�邱�Ƃ͂Ȃ����낤���ꉞ�B

//�Ƃ肠�����Ƃ��āAZXC�L�[�̓��������ƃJ�[�\���L�[�̓���������B
//ZXC+�J�[�\���L�[���Q�{�V�t�g�{�X�y�[�X�L�[�̓��������͉\�B
