#include "Jump.h"

void Jump(int* JumpPower, int* Player_Y, const char* Keyinput) {
	if (Keyinput[KEY_INPUT_Z] == 1 && *Player_Y == 300) {
		*JumpPower = -10;
	}

	*JumpPower += 1;

	if (*Player_Y > 300) {	//�ڒn���Ă��邩�̔���@//����Y��300�ȉ��Ȃ�ڒn�Ƃ�������
		*Player_Y = 300;
		*JumpPower = 0;
	}

	*Player_Y += *JumpPower;
}