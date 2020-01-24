#pragma once
#include <Windows.h>	
#include "Capcom/MemoryController.h"

class CapcomDriverManualMapper
{
public:
	CapcomDriverManualMapper(const char* ProxyDriverName, const char* DriverName, DWORD64 BaseAddress);
	~CapcomDriverManualMapper();

	void map();
private:

	SIZE_T SizeOfImage;
	SIZE_T SizeOfFile;

	BYTE* pMappedImage;
	BYTE* pFileBuffer;
	DWORD64 BaseAddress;

	KernelContext* KrCtx;
	CapcomContext* CpCtx;
	MemoryController Controller;

	wchar_t* mProxyDriverName;

	FORCEINLINE void FixImports();
	FORCEINLINE void FixRelocation();
	FORCEINLINE BOOL MakePageWritable();
	
	DWORD64 GetKernelModule(const char* ModuleName);
	DWORD64 GetFunctionAddressByName(DWORD64 Base, const char* Name);
	DWORD64 GetFunctionAddressByOrdinal(DWORD64 Base, UINT16 oridnal);
};

