#include "MapScroll.h"

#define MAP_SIZE 64
#define MAP_WIDTH 10
#define MAP_HEIGHT 8

const int MapDatas[MAP_HEIGHT][MAP_WIDTH] = {

	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,1,1,1,1,1,1,0 },
	{ 0,1,0,1,1,0,0,0,1,0 },
	{ 0,1,1,1,1,0,0,0,1,0 },
	{ 0,1,0,1,0,0,0,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};

void MapDraw() {
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (MapDatas[i][j] == 0) {
				DrawBox(j* MAP_SIZE, i* MAP_SIZE, j* MAP_SIZE + MAP_SIZE, i*MAP_SIZE + MAP_SIZE, GetColor(255, 0, 0), TRUE);
			}
		}
	}
}