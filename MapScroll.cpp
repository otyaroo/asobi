#include "DxLib.h"

#define MAP_SIZE 64
#define MAP_WIDTH 80
#define MAP_HEIGHT 80

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

void MapDraw(int* MapObjGraph) {
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (MapDatas[i][j] == 0) {
				DrawExtendGraph(j * MAP_WIDTH, i * MAP_HEIGHT, j * MAP_WIDTH + MAP_WIDTH, i * MAP_HEIGHT + MAP_HEIGHT, MapObjGraph[0], true);
			}
		}
	}
}