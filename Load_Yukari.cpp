#pragma once
#include "DxLib.h"


void Load_Yukari(int* y) {
	LoadDivGraph("yukari", 24, 8, 3, 32, 50, y);
	
}

void MapObjLoad(int* m) {
	LoadDivGraph("block.png", 9, 3, 3, 80, 80, m);
}