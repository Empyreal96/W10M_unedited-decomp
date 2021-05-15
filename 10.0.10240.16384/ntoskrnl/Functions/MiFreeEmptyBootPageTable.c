// MiFreeEmptyBootPageTable 
 
unsigned int __fastcall MiFreeEmptyBootPageTable(int a1)
{
  unsigned int v2; // r4
  unsigned int result; // r0
  int v4; // r0

  v2 = *(_DWORD *)(a1 + 4) | 0x80000000;
  result = v2 << 20;
  if ( v2 << 20 < MiLowHalVa )
  {
    if ( result >= dword_63389C
      && *((_BYTE *)&MiState[2423] + ((int)((v2 & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) )
    {
      MiReturnSystemVa(
        result,
        result + 0x400000,
        *((unsigned __int8 *)&MiState[2423] + ((int)((v2 & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
        0);
    }
    *(_DWORD *)(a1 + 12) &= 0xC0000000;
    *(_WORD *)(a1 + 16) = 0;
    if ( v2 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v2 = 0;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v2 = 0;
      if ( v2 + 1070596096 <= 0xFFF )
      {
        v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v2 & 0xFFF)), 0);
      }
    }
    result = MiLockAndInsertPageInFreeList(a1);
  }
  return result;
}
