#include "DxLib.h"
#include "Header.h"

using namespace std;

void Jump(int* JumpPower, double* Player_Y, const char* Keyinput, int* jump_temp, int* jump_prev, bool gnd) {
	
	extern ofstream dump;		//�O���Ő錾����dump���g����悤�ɂ��Ă���B

	*jump_temp = *Player_Y;
	if (Keyinput[KEY_INPUT_Z] == 1 && gnd) {
	//	dump << "------------------�W�����v�{�^���������ꂽ��I-------------------" << endl;		//�_���v�p
		*JumpPower = -15;																			//�W�����v��
		gnd = false;																				//�W�����v�����u�Ԃ�false�ɂ��Ȃ��ƁA���̔���ő��U��0�ɖ߂����B
	}
	

	*Player_Y += (*Player_Y - *jump_prev) + *JumpPower;
	*jump_prev = *jump_temp;
	if (*JumpPower < 10) {*JumpPower += 1;}		//�������x�����@�����x�͂P�Ł@�ō�����10�ƂȂ�
	
	if (gnd) {	//�ڒn���Ă��邩�̔���@
		int y = *Player_Y / 80;
		*Player_Y = y * 80 +10;
		*JumpPower = 0;
	}
	{//--------------------------------------------�_���v�p----------------------------------------------------------
		dump << "gnd " << gnd;
		dump << "JumpPower " << *JumpPower;
		dump << "Player_Y " << *Player_Y;
		dump << "jump_prev " << *jump_prev;
		dump << "jump_temp " << *jump_temp << endl;
	}//--------------------------------------------------------------------------------------------------------------
}