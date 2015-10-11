#include "DxLib.h"
#include "Header.h"

using namespace std;

void Jump(int* JumpPower, double* Player_Y, const char* Keyinput, int* jump_temp, int* jump_prev, bool gnd) {
	
	extern ofstream dump;		//外部で宣言したdumpを使えるようにしている。

	*jump_temp = *Player_Y;
	if (Keyinput[KEY_INPUT_Z] == 1 && gnd) {
	//	dump << "------------------ジャンプボタンが押されたよ！-------------------" << endl;		//ダンプ用
		*JumpPower = -15;																			//ジャンプ力
		gnd = false;																				//ジャンプした瞬間にfalseにしないと、下の判定で速攻で0に戻される。
	}
	

	*Player_Y += (*Player_Y - *jump_prev) + *JumpPower;
	*jump_prev = *jump_temp;
	if (*JumpPower < 10) {*JumpPower += 1;}		//落下速度調整　加速度は１で　最高速は10となる
	
	if (gnd) {	//接地しているかの判定　
		int y = *Player_Y / 80;
		*Player_Y = y * 80 +10;
		*JumpPower = 0;
	}
	{//--------------------------------------------ダンプ用----------------------------------------------------------
		dump << "gnd " << gnd;
		dump << "JumpPower " << *JumpPower;
		dump << "Player_Y " << *Player_Y;
		dump << "jump_prev " << *jump_prev;
		dump << "jump_temp " << *jump_temp << endl;
	}//--------------------------------------------------------------------------------------------------------------
}