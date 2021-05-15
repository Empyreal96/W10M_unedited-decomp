// MiInitializeSlowPte 
 
int __fastcall MiInitializeSlowPte(unsigned int a1, unsigned int a2, int a3)
{
  int v6; // r5
  int v7; // r3
  int result; // r0
  unsigned int v9; // r6
  int v10; // r3
  int v11; // r5
  int v12; // r0

  v6 = 4;
  if ( MI_IS_PFN(a2) )
  {
    v6 = MiMakeProtectionPfnCompatible(4, MmPfnDatabase + 24 * a2);
  }
  else
  {
    v7 = MiPlatformCacheAttributes[a3 + 6];
    if ( v7 )
    {
      if ( v7 == 2 )
        v6 = 28;
    }
    else
    {
      v6 = 12;
    }
  }
  result = MiDetermineUserGlobalPteMask(a1);
  v9 = (MmProtectToPteMask[v6] & 0x1ED | (a2 << 12) | result) & 0xFFFFF1FF | 0x12;
  if ( a1 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a1 = v9;
  }
  else
  {
    v10 = *(_DWORD *)a1;
    v11 = 0;
    __dmb(0xBu);
    if ( (v10 & 2) == 0 )
      v11 = 1;
    *(_DWORD *)a1 = v9;
    if ( a1 + 1070596096 <= 0xFFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * (a1 & 0xFFF)), v9);
    }
    if ( v11 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return result;
}
