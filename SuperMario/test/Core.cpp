#include "Core.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "Player.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() {

}

CCore::~CCore() {
	CMapManager::DestroyInst();
	CObjectManager::DestroyInst();
}

CCore* CCore::GetInst() {
	if (!m_pInst)
		m_pInst = new CCore;
	return m_pInst;
}

void CCore::DestroyInst() {
	SAFE_DELETE(m_pInst);
}

bool CCore::Init() {
	if (!CMapManager::GetInst()->Init())
		return false;
	if (!CObjectManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run() {
	while (true)
	{
		int iStage = OutputMenu();
		if (iStage == 4)
			break;
		else if (iStage == 0)
			continue;
		CMapManager::GetInst()->Run(iStage - 1);
	}
}

int CCore::OutputMenu() {
	system("cls");
	cout << "     <<마리오 게임>>" << endl;
	cout << "- 왼쪽 이동: 왼쪽 방향키" << endl;
	cout << "- 오른쪽 이동: 오른쪽 방향키" << endl;
	cout << "- 점프: 윗방향키" << endl;
	cout << "- 플레이 중 종료하기: e" << endl << endl;
	cout << "1. 스테이지1" << endl;
	cout << "2. 스테이지2" << endl;
	cout << "3. 스테이지3" << endl;
	cout << "4. 종료" << endl;
	cout << "번호를 입력하세요: ";
	int iInput = InputInt();
	while (iInput < 1 || iInput > 4) {
		return 0;
	}
	return iInput;
}