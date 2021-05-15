// MiReadyStandbyPageForActive 
 
int __fastcall MiReadyStandbyPageForActive(int a1, int a2)
{
  int v3; // r7
  unsigned int v4; // r4
  char v5; // r2
  int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  int result; // r0
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r0

  v3 = (a1 - MmPfnDatabase) / 24;
  v4 = *(_DWORD *)(a1 + 4) | 0x80000000;
  v5 = *(_BYTE *)(a1 + 18);
  ++*(_WORD *)(a1 + 16);
  v6 = v5 & 0xF8;
  v7 = *(_DWORD *)(a1 + 8);
  v8 = v6 | 6;
  *(_BYTE *)(a1 + 18) = v6 | 6;
  if ( (v7 & 0x400) != 0 )
    v9 = (*(unsigned __int16 *)((v7 & 0xFFFFF800 | (2 * (v7 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v9 = (v7 >> 5) & 0x1F;
  if ( v8 >> 6 != 1 )
    return sub_51F048();
  result = MiDetermineUserGlobalPteMask(a2) | MmProtectToPteMask[v9 & 0xFFFFFFE7] & 0x3ED | (v3 << 12);
  v11 = result & 0xFFFFF3FF | 0x12;
  if ( v4 + 0x40000000 <= 0x3FFFFF )
  {
    v12 = *(_DWORD *)v4;
    v13 = 0;
    __dmb(0xBu);
    *(_DWORD *)v4 = v11;
    if ( (v12 & 2) == 0 )
      v13 = 1;
    if ( v4 + 1070596096 <= 0xFFF )
    {
      v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v14, v14 + 4 * (v4 & 0xFFF), v11);
    }
    if ( v13 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  else
  {
    *(_DWORD *)v4 = v11;
  }
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a1 + 12) & 0xC0000000 | 1;
  return result;
}
