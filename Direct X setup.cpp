#include "initialize.h"
#include "DirectX_Input.h"
#include "Jump.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	


	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		
		KeyShow(Keys);
		Jump(&JumpPower, &Player_Y, Keys);
		DrawPixel(Player_X, Player_Y, GetColor(255, 255, 255));	// �_��ł�
		
		
		ScreenFlip();
	}
				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}