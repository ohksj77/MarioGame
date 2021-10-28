#include "ObjectManager.h"
#include "Player.h "

CObjectManager* CObjectManager::m_pInst = NULL;

CObjectManager::CObjectManager():m_pPlayer(NULL) {

}

CObjectManager::~CObjectManager() {
	SAFE_DELETE(m_pPlayer);
}

bool CObjectManager::Init() {
	m_pPlayer = new CPlayer;
	m_pPlayer->Init();
	return true;
}