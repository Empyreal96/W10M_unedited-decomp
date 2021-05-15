// ExLockUserBuffer 
 
int __fastcall ExLockUserBuffer(int a1, int a2, int a3, int a4, int *a5, int *a6)
{
  unsigned int v8; // r0
  int v9; // r0
  int v10; // r4
  int v12; // r2
  __int16 v13; // r3
  int v14; // r0

  *a5 = 0;
  *a6 = 0;
  v8 = MmSizeOfMdl(a1, a2);
  v9 = ExAllocatePoolWithQuotaTag(0x208u, v8, 1868983881);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)v9 = 0;
    v12 = a1 & 0xFFF;
    *(_WORD *)(v9 + 4) = 4 * (((unsigned int)(v12 + a2 + 4095) >> 12) + 7);
    *(_WORD *)(v9 + 6) = 0;
    *(_DWORD *)(v9 + 16) = a1 & 0xFFFFF000;
    *(_DWORD *)(v9 + 24) = v12;
    *(_DWORD *)(v9 + 20) = a2;
    MmProbeAndLockPages(v9);
    v13 = *(_WORD *)(v10 + 6) | 0x2000;
    *(_WORD *)(v10 + 6) = v13;
    if ( (v13 & 5) != 0 )
      v14 = *(_DWORD *)(v10 + 12);
    else
      v14 = MmMapLockedPagesSpecifyCache(v10, 0, 1, 0, 0, 1073741856);
    *a5 = v14;
    if ( v14 )
    {
      *a6 = v10;
      return 0;
    }
    ExUnlockUserBuffer(v10);
  }
  return -1073741670;
}
