#pragma once
#include "value.h"

enum STAGE_BLOCK_TYPE {
	SBT_WALL = '0',
	SBT_ROAD = '1',
	SBT_START = '2',
	SBT_END = '3',
	SBT_COIN = '4'
};

class CStage {
private:
	char m_cOriginStage[BLOCK_Y][BLOCK_X];
	char m_cStage[BLOCK_Y][BLOCK_X];
	POINT m_tStart;
	POINT m_tEnd;
public:
	CStage();
	~CStage();
	bool Init();
	bool Init(char* pFileName);
	void Render();
	POINT GetStart() {
		return m_tStart;
	}
	POINT GetEnd() {
		return m_tEnd;
	}
	char GetBlock(int x, int y) { return m_cStage[y][x]; }
	void ChangeBlock(int x, int y, STAGE_BLOCK_TYPE eBlock) {
		m_cStage[y][x] = eBlock;
	}
	void ResetStage();
	int SaveCoin(int y, int x);
	char** GetStage() { return (char**)m_cStage; }
}; 