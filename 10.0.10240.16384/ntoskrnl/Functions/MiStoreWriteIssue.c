// MiStoreWriteIssue 
 
int __fastcall MiStoreWriteIssue(int a1, int a2, int *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r1
  int v10[6]; // [sp+10h] [bp-18h] BYREF

  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 56) = 4096;
  *(_DWORD *)(a1 + 36) = 0;
  *(_WORD *)(a1 + 40) = 32;
  *(_WORD *)(a1 + 42) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_WORD *)(a1 + 42) = 2;
  *(_DWORD *)(a1 + 64) = (a2 - MmPfnDatabase) / 24;
  v8 = *a3;
  *(_DWORD *)(a1 + 32) = a7;
  if ( (v8 & 0xF0000000) == -268435456 )
    return -1073741285;
  v10[0] = v8;
  return SmpPageWrite(v10, a4, a6, a1 + 36, a5, a1 + 8, a8);
}
