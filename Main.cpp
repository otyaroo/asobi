#pragma once
#define _CRTDBG_MAP_ALLOC

#include "Header.h"

#include <stdlib.h>		//���������[�N���o�p
#include <crtdbg.h>		//���������[�N���o�p

using namespace std;

int JumpPower = 0;
double Player_X = 60;
double Player_Y = 0;




const int Player_Width = 40;
const int Player_Height = 70;

char Keys[256];



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//���������[�N���o�p
	SetWaitVSyncFlag(true);
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//�䂩�肳��ǂݍ��ݗp�摜�n���h���쐬
	int* yukari = new int[24];
	Load_Yukari(yukari);

//----------------------------------------------------------------------------------------------------------------
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		{	//�䂩�肳�񔻒�B
			DrawLine(Player_X, 0, Player_X, 600, GetColor(255, 255, 0));	//������p
			DrawLine(Player_X + Player_Width, 0, Player_X + Player_Width, 600, GetColor(255, 255, 0)); //�E����p
			DrawLine(0, Player_Y, 800, Player_Y, GetColor(255, 255, 0));//�㔻��p
			DrawLine(0, Player_Y + Player_Height, 800, Player_Y + Player_Height, GetColor(255, 255, 0));//������p
		}	//�኱���C�����䂩�肳����x��Ă�悤�Ɍ�����B���莞�ɂǂ��������ƂɂȂ�̂��c�H
																									//MapDraw();
		KeyShow(Keys);
		Move(&Player_X, Keys);
		Jump(&JumpPower, &Player_Y, Keys,&jump_temp,&jump_temp);	//Verlet�ϕ��H�Ȃ̂����Ă݂���B
		DrawExtendGraph(Player_X -12 , Player_Y - 15, Player_X +52, Player_Y + 85 ,yukari[22], true);	//����64,������100�ŌŒ�B����œ�{��B
		
		
		ScreenFlip();
	}
				// �L�[���͑҂�
//----------------------------------------------------------------------------------------------------------------
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	
	_CrtDumpMemoryLeaks();		//���������[�N���|�[�g�� [�o��] �E�B���h�E�̃f�o�b�O�y�C���ɏo�͂��܂��B 
	
	return 0;				// �\�t�g�̏I�� 
}