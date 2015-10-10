#include "DxLib.h"
#include "Header.h"

bool ground_judge(const double Player_x, const double Player_y,  const int width, const int height) {
	double p_right_down_x;
	double p_right_down_y;
	double p_left_down_x;
	double p_left_down_y;

	p_left_down_x = Player_x;
	p_left_down_y = Player_y + height;			//�䂩�肳��̍������W

	p_right_down_x = Player_x + width;
	p_right_down_y = Player_y + height;			//�䂩�肳��̉E�����W

	//�䂩�肳��̂������̃}�b�v��?
	//����X���W����̃u���b�N�̕��ł���80�Ŋ���������{(int)�ɃL���X�g}���}�b�v��width�̈����ƂȂ�
	//Y��80�Ŋ���΂����͂��B

	int x, y;
	x = p_left_down_x / 80;
	y = p_left_down_y / 80;

	if (MapDatas[y][x] == 0) {
		return true;	//�����͒n�ʂ��Ă��
	}

	int rx, ry;
	rx = p_right_down_x / 80;
	ry = p_right_down_y / 80;

	if (MapDatas[ry][rx] == 0) {
		return true;	//�E���͒n�ʂ��Ă��
	}

	//�����n�ʂɂ��ĂȂ���
	return false;
}