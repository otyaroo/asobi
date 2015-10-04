#include "Jump.h"

void Jump(int* JumpPower, int* Player_Y, const char* Keyinput) {
	if (Keyinput[KEY_INPUT_Z] == 1 && *Player_Y == 300) {
		*JumpPower = -10;
	}

	*JumpPower += 1;

	if (*Player_Y > 300) {	//Ú’n‚µ‚Ä‚¢‚é‚©‚Ì”»’è@//¡‚ÍY‚ª300ˆÈ‰º‚È‚çÚ’n‚Æ‚¢‚¤ğŒ
		*Player_Y = 300;
		*JumpPower = 0;
	}

	*Player_Y += *JumpPower;
}