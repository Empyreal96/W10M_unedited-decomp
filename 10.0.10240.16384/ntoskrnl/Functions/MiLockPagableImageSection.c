// MiLockPagableImageSection 
 
int __fastcall MiLockPagableImageSection(int result, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v6; // r5
  int v7; // r3
  int v8; // r5
  int v9; // r8
  int v10; // r9
  unsigned int v11; // r6
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // lr
  unsigned int v15; // r10
  int v16; // r1
  unsigned int v17; // lr
  int v18[8]; // [sp+8h] [bp-20h] BYREF

  v18[0] = a4;
  v4 = result;
  if ( result != 1 )
  {
    result = 4092;
    v6 = (v4 >> 20) & 0xFFC;
    if ( (*(_DWORD *)(v6 - 1070596096) & 0x402) != 1026 )
    {
      if ( v4 < dword_63389C
        || (v7 = *((unsigned __int8 *)&MiState[2423] + ((int)(v6 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
            v7 != 1)
        && v7 != 11 )
      {
        MmLockLoadedModuleListShared(v18);
        v8 = MiLookupDataTableEntry(v4, 1);
        if ( !v8 )
          sub_50EB40();
        MmUnlockLoadedModuleListShared(LOBYTE(v18[0]));
        v9 = *(_DWORD *)(v8 + 24);
        v10 = RtlImageNtHeader(v9);
        v11 = (int)(v4 - *(unsigned __int16 *)(v10 + 20) - v10 - 24) / 40;
        if ( v11 >= *(unsigned __int16 *)(v10 + 6) )
          KeBugCheckEx(26, 4115, v4 | a2);
        v12 = *(_DWORD *)(v4 + 16);
        v13 = *(_DWORD *)(v8 + 128);
        if ( v12 < *(_DWORD *)(v4 + 8) )
          v12 = *(_DWORD *)(v4 + 8);
        v14 = *(_DWORD *)(v10 + 56);
        v15 = *(_DWORD *)(v4 + 12) + v9;
        v16 = (v15 >> 10) & 0x3FFFFC;
        if ( v14 > 0x1000 )
          v14 = 4096;
        v17 = ((((v14 + v15 + v12 - 1) & ~(v14 - 1)) + 4095) >> 10) & 0x3FFFFC;
        if ( a2 == 1 )
          result = MiLockImageSection(v8, v13 + 4 * v11, v16 - 0x40000000, v17 - 1073741828);
        else
          result = MiUnlockImageSection((unsigned int *)(v13 + 4 * v11), v16 - 0x40000000, v17 - 1073741828);
      }
    }
  }
  return result;
}
