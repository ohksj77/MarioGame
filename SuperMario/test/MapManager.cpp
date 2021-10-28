#include "MapManager.h"
#include "Stage.h"
#include "Player.h"
#include "ObjectManager.h"
#include <string.h>

CMapManager* CMapManager::m_pInst = NULL;

CMapManager::CMapManager() {
	for (int i = 0; i < STAGE_MAX_COUNT; ++i) {
		m_pStage[i] = NULL;
	}
}

CMapManager::~CMapManager() {
	for (int i = 0; i < STAGE_MAX_COUNT; ++i) {
		SAFE_DELETE(m_pStage[i]);
	}
}

CMapManager* CMapManager::GetInst() {
	if (!m_pInst)
		m_pInst = new CMapManager;
	return m_pInst;
}

void CMapManager::DestroyInst() {
	SAFE_DELETE(m_pInst);
}

bool CMapManager::Init() {
	const char* pStageFile[3] = { "Stage1.txt", "Stage2.txt", "Stage3.txt" };
	for (int i = 0; i < STAGE_MAX_COUNT; ++i) {
		m_pStage[i] = new CStage;
		char save[40];
		strcpy_s(save, 20, pStageFile[i]);
		if (!m_pStage[i]->Init(save))
			return false;
	}
	return true;
}

void CMapManager::Run(int iStage) {
	CMapManager isStop;
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();
	int Save[10][50] = { 0, };
	m_iEnableStage = iStage;

	pPlayer->SetPos(m_pStage[iStage]->GetStart().x, m_pStage[iStage]->GetStart().y);

	while (true) {

		CStage* pStage = CMapManager::GetInst()->GetStage();
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 50; ++j) {
				if (pStage->SaveCoin(i, j) == 1)
					Save[i][j] = 1;
			}
		}

		system("cls");

		if (GetAsyncKeyState('E') & 0x8000) {
			pPlayer->SetNotComplete();
			pPlayer->SetZeroScore();
			isStop.SetStop();
			break;
		}

		pPlayer->Update();
		m_pStage[iStage]->Render();
		cout << "Score : " << pPlayer->GetScore() << endl;

		if (pPlayer->GetComplete()) {
			cout << "스테이지 클리어!" << endl;
			Sleep(1500);
			pPlayer->SetNotComplete();
			pPlayer->SetZeroScore();
			break;
		}
		Sleep(100);
	}

	if (pPlayer->GetComplete() == false) {
		CStage* pStage = CMapManager::GetInst()->GetStage();
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 50; ++j) {
				if (Save[i][j] == 1) {
					pStage->ChangeBlock(j, i, SBT_COIN);
				}
			}
		}
	}
	if (isStop.GetStop()) {
		CStage* pStage = CMapManager::GetInst()->GetStage();
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 50; ++j) {
				if (Save[i][j] == 1) {
					pStage->ChangeBlock(j, i, SBT_COIN);
				}
			}
		}
	}
}

void CMapManager::Render() {
	m_pStage[0]->Render();
}