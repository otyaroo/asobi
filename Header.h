#pragma once
#include "DxLib.h"
//-----�L�[�{�[�h����̓���
void KeyShow(char *);
const unsigned int WhiteColor = GetColor(255, 255, 255);//���F�̃J���[�������B

//-----�W�����v���邽�߂̊֐�
int jump_temp = 0;
int jump_prev = 0;
void Jump(int* JumpPower, double* Player_Y, const char* Keyinput,int* jump_temp, int* jump_prev);

//------�}�b�v�\�����邾���B�w�i�H����
void MapDraw();

//------�ړ��Ƃ��������W�𓮂�������
void Move(double* Player_X, const char* Keys);


void Load_Yukari(int*);