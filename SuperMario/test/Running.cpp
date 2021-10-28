#include "Core.h"

int main() {
	if (!CCore::GetInst()->Init()) {
		cout << "게임 초기화 실패!!" << endl;
		CCore::DestroyInst();
		return 0;
	}
	CCore::GetInst()->Run();
	CCore::DestroyInst();

	return 0;
}