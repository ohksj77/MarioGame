#pragma once
#include "value.h"
#define JUMP_BLOCK_MAX 2

enum JUMP_DIR {
	JD_STOP,
	JD_UP,
	JD_DOWN
};

class CPlayer {
private:
	POINT m_tPos;
	bool m_bJump;
	int m_iJumpDir;
	int m_iJumpState;
	int m_iScore;
	bool m_bComplete;
public:
	CPlayer();
	~CPlayer();
	bool Init();
	int GetX() { return m_tPos.x; }
	int GetY() { return m_tPos.y; }
	void SetPos(int x, int y) {
		m_tPos.x = x;
		m_tPos.y = y;
	}
	void Update();
	int GetScore() { return m_iScore; }
	bool GetComplete() { return m_bComplete; }
	bool SetNotComplete() { m_bComplete = false; return m_bComplete; }
	int SetZeroScore() { m_iScore = 0; return m_iScore; }
};