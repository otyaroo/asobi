#pragma once
#include "DxLib.h"
//-----�L�[�{�[�h����̓���
void KeyShow(char *);
const unsigned int WhiteColor = GetColor(255, 255, 255);//���F�̃J���[�������B

//-----�W�����v���邽�߂̊֐�
void Jump(int* JumpPower, int* Player_Y, const char* Keyinput);

//------�}�b�v�\�����邾���B�w�i�H����
void MapDraw();

//------�ړ��Ƃ��������W�𓮂�������
void Move(int* Player_X, const char* Keys);

