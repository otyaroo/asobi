#pragma once
#define _CRTDBG_MAP_ALLOC
#include "initialize.h"
#include "Input.h"
#include "Jump.h"
#include "Move.h"
#include "MapScroll.h"

#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);		//���������[�N���o�p
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	

	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		
		MapDraw();
		KeyShow(Keys);
		Move(&Player_X, Keys);
		Jump(&JumpPower, &Player_Y, Keys);
		DrawPixel(Player_X, Player_Y, GetColor(255, 255, 255));	// �_��ł�
		
		
		ScreenFlip();
	}
				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	
	_CrtDumpMemoryLeaks();		//���������[�N���|�[�g�� [�o��] �E�B���h�E�̃f�o�b�O�y�C���ɏo�͂��܂��B 
	
	return 0;				// �\�t�g�̏I�� 
}