#include "Stage.h"
#include "FileStream.h"
#include "Player.h"
#include "ObjectManager.h"
#include "MapManager.h"
#include <string.h>

CStage::CStage() {
}

CStage::~CStage() {
}

bool CStage::Init() {
	return true;
}

bool CStage::Init(char* pFileName) {
	CFileStream file;
	char rt[20] = "rt";
	if (!file.Open(pFileName, rt))
		return false;
	for (int i = 0; i < 10; ++i) {
		int iSize = 0;
		file.ReadLine(m_cOriginStage[i], iSize);
		for (int j = 0; j < 50; ++j) {
			m_cStage[i][j] = m_cOriginStage[i][j];
			if (m_cOriginStage[i][j] == SBT_START) {
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cOriginStage[i][j] == SBT_END) {
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
		}
	}
	return true;
}

void CStage::Render() {
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();
	int iX = pPlayer->GetX();
	int iY = pPlayer->GetY();

	int iYCount = iY + (RENDER_BLOCK_Y / 2);
	if (iYCount >= BLOCK_Y)
		iYCount = BLOCK_Y - 1;
	
	int iYMin = iYCount - (RENDER_BLOCK_Y - 1);
	if (iYMin < 0)
		iYMin = 0;

	int iXCount = iX + RENDER_BLOCK_X;
	if (iXCount > BLOCK_X)
		iXCount = BLOCK_X;

	int iXMin = iX;
	if (iXMin > BLOCK_X - RENDER_BLOCK_X)
		iXMin = BLOCK_X - RENDER_BLOCK_X;

	for (int i = iYMin; i <= iYCount; ++i) {

		for (int j = iXMin; j < iXCount; ++j) {
			if (i == iY && j == iX)
				cout << 't';
			else if (m_cStage[i][j] == SBT_WALL)
				cout << "бс";
			else if (m_cStage[i][j] == SBT_ROAD)
				cout << "  ";
			else if (m_cStage[i][j] == SBT_START)
				cout << "  ";
			else if (m_cStage[i][j] == SBT_END)
				cout << "E";
			else if (m_cStage[i][j] == SBT_COIN)
				cout << "б┌";
		}
		cout << endl;
	}
}

void CStage::ResetStage() {
	for (int i = 0; i < BLOCK_Y; ++i) {
		for (int j = 0; j < BLOCK_X; ++j) {
			m_cStage[i][j] = m_cOriginStage[i][j];
		}
	}
}

int CStage::SaveCoin(int y, int x) {
	int SaveData[10][50] = { 0, };
	CStage* pStage = CMapManager::GetInst()->GetStage();
	if (pStage->GetBlock(x, y) == SBT_COIN)
		SaveData[y][x] = 1;
	return SaveData[y][x];
}