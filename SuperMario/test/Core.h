#pragma once
#include "value.h"

class CCore
{
private:
	CCore();
	~CCore();
	static CCore* m_pInst;
	int OutputMenu();
public:
	static CCore* GetInst();
	static void DestroyInst();
	bool Init();
	void Run();
};