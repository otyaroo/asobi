#include "DxLib.h"

class Player {
private:
	int x;
	int y;
	bool flag;
public:
	void position(int* ,int *) const;
	void Jamp(int *);
};

void Player::position(int* p_x, int* p_y) const {	//�v���C���[���W�������ɕԂ��֐��B
	*p_x = x;
	*p_y = y;
}

void Player::Jamp(int* p_y) {
	if (!flag) { return; } //�W�����v���t���O�@false�Ȃ�W�����v���ł͂Ȃ��B

}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}



	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}