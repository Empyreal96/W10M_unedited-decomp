// CmpRebuildKcbCache 
 
int __fastcall CmpRebuildKcbCache(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r5
  int v12; // r2
  unsigned int v13; // r2
  int v15[4]; // [sp+0h] [bp-10h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = *(_DWORD *)(a1 + 4);
  v15[0] = -1;
  if ( (v5 & 0x10) == 0 && (*(_WORD *)(a1 + 106) & 0x40) == 0 )
  {
    if ( (v5 & 8) != 0 )
      return 0;
    v6 = *(_DWORD *)(a1 + 20);
    if ( !v6 )
      return 0;
    v7 = *(_DWORD *)(a1 + 24);
    if ( v7 == -1 )
      return 0;
    v11 = (*(int (__fastcall **)(_DWORD, int, int *))(v6 + 4))(*(_DWORD *)(a1 + 20), v7, v15);
    if ( !v11 )
      return 0;
    CmpCleanUpSubKeyInfo((_DWORD *)a1, v8, v9, v10);
    CmpCleanUpKcbValueCache(a1);
    v12 = *(_DWORD *)(a1 + 104);
    *(_DWORD *)(a1 + 52) = *(_DWORD *)(v11 + 36);
    *(_DWORD *)(a1 + 56) = *(_DWORD *)(v11 + 40);
    *(_DWORD *)(a1 + 88) = *(_DWORD *)(v11 + 4);
    *(_DWORD *)(a1 + 92) = *(_DWORD *)(v11 + 8);
    *(_WORD *)(a1 + 96) = *(_DWORD *)(v11 + 52);
    *(_WORD *)(a1 + 98) = *(_DWORD *)(v11 + 60);
    *(_DWORD *)(a1 + 100) = *(_DWORD *)(v11 + 64);
    v13 = v12 & 0xFFFFFFF0 | *(_WORD *)(v11 + 54) & 0xF;
    *(_DWORD *)(a1 + 104) = v13;
    *(_DWORD *)(a1 + 104) = ((unsigned __int8)*(_WORD *)(v11 + 54) ^ (unsigned __int8)v13) & 0xF0 ^ v13;
    *(_BYTE *)(a1 + 105) = *(_BYTE *)(v11 + 55);
    *(_WORD *)(a1 + 106) = *(_WORD *)(v11 + 2);
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), v15);
  }
  return 1;
}
