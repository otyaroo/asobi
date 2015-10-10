#include "DxLib.h"
#include "Header.h"

bool ground_judge(const double Player_x, const double Player_y,  const int width, const int height) {
	double p_right_down_x;
	double p_right_down_y;
	double p_left_down_x;
	double p_left_down_y;

	p_left_down_x = Player_x;
	p_left_down_y = Player_y + height;			//ゆかりさんの左下座標

	p_right_down_x = Player_x + width;
	p_right_down_y = Player_y + height;			//ゆかりさんの右下座標

	//ゆかりさんのお足元のマップは?
	//今のX座標を一つのブロックの幅である80で割ったもの{(int)にキャスト}がマップのwidthの引数となる
	//Yも80で割ればいいはず。

	int x, y;
	x = p_left_down_x / 80;
	y = p_left_down_y / 80;

	if (MapDatas[y][x] == 0) {
		return true;	//左足は地面ついてるよ
	}

	int rx, ry;
	rx = p_right_down_x / 80;
	ry = p_right_down_y / 80;

	if (MapDatas[ry][rx] == 0) {
		return true;	//右足は地面ついてるよ
	}

	//両足地面についてないよ
	return false;
}