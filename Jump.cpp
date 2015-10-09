#include "Jump.h"

void Jump(int* JumpPower, double* Player_Y, const char* Keyinput,int* jump_temp, int* jump_prev) {
	*jump_temp = *Player_Y;
	if (Keyinput[KEY_INPUT_Z] == 1 && *Player_Y == 300) {
		*JumpPower = -20;
	}

	*JumpPower += 1;

	*Player_Y += (*Player_Y - *jump_prev) + *JumpPower;

	*jump_prev = *jump_temp;
	
	if (*Player_Y > 300) {	//Ú’n‚µ‚Ä‚¢‚é‚©‚Ì”»’è@//¡‚ÍY‚ª300ˆÈ‰º‚È‚çÚ’n‚Æ‚¢‚¤ðŒ
		*Player_Y = 300;
		*JumpPower = 0;
	}
}