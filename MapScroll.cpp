#include "Header.h"



void MapDraw(int* MapObjGraph) {
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (MapDatas[i][j] == 0) {
				DrawExtendGraph(j * MAP_WIDTH, i * MAP_HEIGHT, j * MAP_WIDTH + MAP_WIDTH, i * MAP_HEIGHT + MAP_HEIGHT, MapObjGraph[0], true);
			}
			if (MapDatas[i][j] == 1) {
				DrawExtendGraph(j * MAP_WIDTH, i * MAP_HEIGHT, j * MAP_WIDTH + MAP_WIDTH, i * MAP_HEIGHT + MAP_HEIGHT, MapObjGraph[1], true);
			}
		}
	}
}