#pragma once
#include "Stage.h"
#include "value.h"

class Cstage;
class CMapManager
{
private:
	CMapManager();
	~CMapManager();
	static CMapManager* m_pInst;
	CStage* m_pStage[STAGE_MAX_COUNT];
	int m_iEnableStage;
	bool Stop = false;
public:
	static CMapManager* GetInst();
	static void DestroyInst();
	bool Init();
	void Run(int iStage);
	void Render();
	CStage* GetStage() { return m_pStage[m_iEnableStage]; }
	bool SetStop() { Stop = true; return Stop; }
	bool GetStop() { return Stop; }
};