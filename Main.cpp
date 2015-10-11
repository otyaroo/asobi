#pragma once
#define _CRTDBG_MAP_ALLOC

#include "Header.h"

#include <stdlib.h>		//���������[�N���o�p
#include <crtdbg.h>		//���������[�N���o�p

using namespace std;

int JumpPower = 0;
double Player_X = 80;		//�����X�|�[���n
double Player_Y = 160;		//�����X�|�[���n

int jump_temp = 0;		//�W�����v�p
int jump_prev = 0;		//�W�����v�p


const int Player_Width = 35;	//�L�����N�^����p�@��
const int Player_Height = 70;	//�L�����N�^����p�@����

char Keys[256];			//�L�[���͕ۑ��p�z��

//-----dump�o�͗p�t�@�C��
std::ofstream dump("dump.txt", std::ios::out | std::ios::app);		//dump�t�@�C���ɂ��낢��o�͂��܂���B�������ݐ�p�A�ǋL���[�h


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//���������[�N���o�p
	SetWaitVSyncFlag(true);
	SetGraphMode(800, 640, 16);
	ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;
	}							// �G���[���N�����璼���ɏI��
	
	//�䂩�肳��ǂݍ��ݗp�摜�n���h���쐬			24
	int* yukari = new int[24];
	Load_Yukari(yukari);
	//�}�b�v�ǂݍ��ݗp�摜�n���h���쐬�{�ǂݍ���	9
	int* MapObjGraph = new int[9];
	MapObjLoad(MapObjGraph);

	//�ڒn����pbool
	bool gnd = false;
//----------------------------------------------------------------------------------------------------------------
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();

		MapDraw(MapObjGraph);															//���[�h�����}�b�v�z������ɁA�摜���[�Ă�B
		KeyShow(Keys);																	//�L�[���́{�L�[�������������
		Move(&Player_X, Keys);															//���͂Ɋ�Â��āA���E�Ɉړ��B
		gnd = ground_judge(Player_X, Player_Y, Player_Width, Player_Height);			//�ڒn����֐�
		Jump(&JumpPower, &Player_Y, Keys, &jump_temp, &jump_temp, gnd);					//�W�����v�֐�		Verlet�ϕ��H�Ȃ̂����Ă݂���B
		DrawExtendGraph(Player_X - 12, Player_Y- 15, Player_X + 52, Player_Y + 85, yukari[22], true);	//	2�{�͕���64,������100�ŌŒ�B
		
		
		{	//�䂩�肳�񔻒�B
			DrawLine(Player_X , 0, Player_X, 600, GetColor(255, 255, 0));	//������p
			DrawLine(Player_X + Player_Width, 0, Player_X + Player_Width, 600, GetColor(255, 255, 0)); //�E����p
			DrawLine(0, Player_Y , 800, Player_Y, GetColor(255, 255, 0));//�㔻��p
			DrawLine(0, Player_Y + Player_Height, 800, Player_Y + Player_Height, GetColor(255, 255, 0));//������p
		}	//�኱���C�����䂩�肳����x��Ă�悤�Ɍ�����B���莞�ɂǂ��������ƂɂȂ�̂��c�H 
			//��DrawLine���Ō�Ɏ����Ă�����x���Ȃ��œ����Ă܂����B
		
		{	//�ڒn����m�F�p
			if (gnd) { DrawFormatString(0, 600, WhiteColor, "True"); }
			else { DrawFormatString(0, 600, WhiteColor, "False"); }
		}
			
		ScreenFlip();

		if (Keys[KEY_INPUT_ESCAPE] == 1) {break;}		//�I������ Esc�������ƏI��
	}		
//----------------------------------------------------------------------------------------------------------------
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	//new�����
	delete[] yukari;
	delete[] MapObjGraph;

	_CrtDumpMemoryLeaks();		//���������[�N���|�[�g�� [�o��] �E�B���h�E�̃f�o�b�O�y�C���ɏo�͂��܂��B 
	
	return 0;				// �\�t�g�̏I�� 
}