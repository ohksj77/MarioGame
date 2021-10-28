#pragma once
#include "value.h"

class CObjectManager {
public:
	CObjectManager();
	~CObjectManager();
	static CObjectManager* GetInst() {
		if (!m_pInst)
			m_pInst = new CObjectManager;
		return m_pInst;
	}
	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}
	bool Init();
	class CPlayer* GetPlayer() { return m_pPlayer; }
private:
	static CObjectManager* m_pInst;
	class CPlayer* m_pPlayer;
};