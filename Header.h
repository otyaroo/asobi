#pragma once
#include "DxLib.h"
#define MAP_SIZE 64
#define MAP_WIDTH 80
#define MAP_HEIGHT 80

//-----�L�[�{�[�h����̓���
void KeyShow(char *);
const unsigned int WhiteColor = GetColor(255, 255, 255);//���F�̃J���[�������B

//-----�W�����v���邽�߂̊֐�
void Jump(int* JumpPower, double* Player_Y, const char* Keyinput,int* jump_temp, int* jump_prev, bool grund_judge);

//------�}�b�v�I�u�W�F�N�g�摜�̃��[�h
void MapObjLoad(int*);

//------�}�b�v�\�����邾���B�w�i�H����
void MapDraw(int* MapObjGraph);

//-----�ڒn����p�֐�
bool ground_judge(const double Player_x, const double Player_y, const int width, const int height);

//------�ړ��Ƃ��������W�𓮂�������
void Move(double* Player_X, const char* Keys);

//------�L�����N�^�[�摜�̓ǂݍ���
void Load_Yukari(int*);

const int MapDatas[8][10] = {

	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,1,1,1,1,1,1,0 },
	{ 0,1,0,1,1,0,0,0,1,0 },
	{ 0,1,1,1,1,0,0,0,1,0 },
	{ 0,1,0,1,0,0,0,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};

