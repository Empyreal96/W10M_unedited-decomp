// PfSnInitializePrefetchHeader 
 
int __fastcall PfSnInitializePrefetchHeader(int a1)
{
  __int64 v2; // r3
  int result; // r0

  memset((_BYTE *)a1, 0, 148);
  *(_DWORD *)(a1 + 88) = a1 + 88;
  *(_DWORD *)(a1 + 92) = a1 + 88;
  *(_DWORD *)(a1 + 96) = a1 + 96;
  *(_DWORD *)(a1 + 100) = a1 + 96;
  memset((_BYTE *)(a1 + 4), 0, 80);
  LODWORD(v2) = PfpPrefetchSharedConflictNotify;
  HIDWORD(v2) = a1 + 4;
  *(_QWORD *)(HIDWORD(v2) + 20) = v2;
  result = KeInitializeEvent(a1 + 64, 0, 0);
  *(_DWORD *)(a1 + 36) = 250;
  *(_DWORD *)(a1 + 32) = 15;
  *(_DWORD *)(a1 + 20) = a1;
  return result;
}
