#include "DirectX_Input.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
	char keys[256]; //�L�[�̉������i�[����z��B
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	while (true) {
		SetDrawScreen(DX_SCREEN_BACK);
		
		ClearDrawScreen();
		KeyShow(keys);
		DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
		ScreenFlip();
	}
				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}