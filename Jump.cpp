#include "DxLib.h"
#include "Header.h"

void Jump(int* JumpPower, double* Player_Y, const char* Keyinput, int* jump_temp, int* jump_prev, bool gnd) {
	*jump_temp = *Player_Y;
	if (Keyinput[KEY_INPUT_Z] == 1 && gnd) {
		*JumpPower = -20;
	}

	*JumpPower += 1;

	*Player_Y += (*Player_Y - *jump_prev) + *JumpPower;

	*jump_prev = *jump_temp;
	
	if (gnd) {	//Ú’n‚µ‚Ä‚¢‚é‚©‚Ì”»’è@
		int y = *Player_Y / 80;
		*Player_Y = y * 80;
		*JumpPower = 0;
	}
}