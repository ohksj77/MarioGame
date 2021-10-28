#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
#define SAFE_DELETE(p) if(p){delete p; p = NULL;}
#define STAGE_MAX_COUNT 3
#define BLOCK_X 50
#define BLOCK_Y 10
#define RENDER_BLOCK_X 20
#define RENDER_BLOCK_Y 5


static int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}