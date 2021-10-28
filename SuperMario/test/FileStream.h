#pragma once
#include "value.h"

class CFileStream {
private:
	FILE* m_pFile;
	int m_iFileSize;
	bool m_bOpen;
public:
	CFileStream();
	~CFileStream();
	bool Open(char* pFileName, char* pNode);
	bool Close();
	void Read(void* pData, int iSize);
	void Write(void* pData, int iSize);
	void ReadLine(void* pData, int& iSize);
	void WriteLine(void* pData, int iSize);
};