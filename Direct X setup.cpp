#include "DxLib.h"

void jump() {

}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	double Player_X = 0;
	double Player_Y = 0;
	double JumpPower = 0;

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);
	while (true) {
		if (Player_Y > 300) {
			Player_Y = 300;
			JumpPower = 0;
		}
		
		if ((Key & PAD_INPUT_A) && Player_Y == 300) JumpPower = 20;


		DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	}
	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}