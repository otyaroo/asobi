#include "Move.h"

void Move(int* Player_X, const char* Keys) {
	if (Keys[KEY_INPUT_RIGHT] == 1) {
		*Player_X += 2;
	}
	if (Keys[KEY_INPUT_LEFT] == 1) {
		*Player_X -= 2;
	}
}