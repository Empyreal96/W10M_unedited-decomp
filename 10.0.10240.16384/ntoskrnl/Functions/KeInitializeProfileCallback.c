// KeInitializeProfileCallback 
 
int __fastcall KeInitializeProfileCallback(int a1, unsigned int a2, unsigned int a3, __int16 a4)
{
  unsigned __int64 v4; // r4
  int v7; // r2
  int v8; // r3

  v4 = __PAIR64__(a3, a2);
  memset((_BYTE *)a1, 0, 52);
  *(_WORD *)a1 = 17;
  *(_QWORD *)(a1 + 16) = v4;
  *(_WORD *)(a1 + 2) = 52;
  *(_BYTE *)(a1 + 50) = 0;
  *(_WORD *)(a1 + 48) = a4;
  v7 = dword_681D74;
  v8 = dword_681D78[0];
  *(_DWORD *)(a1 + 36) = *(_DWORD *)&KeActiveProcessors;
  *(_DWORD *)(a1 + 40) = v7;
  *(_DWORD *)(a1 + 44) = v8;
  return a1 + 48;
}
