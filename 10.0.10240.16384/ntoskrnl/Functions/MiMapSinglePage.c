// MiMapSinglePage 
 
int __fastcall MiMapSinglePage(int a1, int a2, int a3)
{
  int v5; // r10
  int v7; // r0
  unsigned int v8; // r5
  int v9; // r6
  char v10; // r0
  int v11; // r4
  unsigned int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r0
  int v17; // [sp+0h] [bp-20h]

  v5 = 3 * a2;
  v17 = MmPfnDatabase;
  if ( a1 )
    return sub_54F734();
  v7 = MiReservePtes(&dword_634D58, 1u);
  v8 = v7;
  if ( !v7 )
    return 0;
  v9 = v7 << 10;
  if ( a3 < 0 )
    v10 = 1;
  else
    v10 = 4;
  if ( (a3 & 0x40000000) == 0 )
    v10 |= 2u;
  v11 = MiMakeProtectionPfnCompatible(v10, v17 + 8 * v5);
  v12 = (MmProtectToPteMask[v11] | MiDetermineUserGlobalPteMask(v8)) & 0x3ED | 0xFFFFF012;
  if ( (v12 & 0x80) != 0 )
    LOWORD(v12) = v12 & 0xFDFF;
  v13 = v12 & 0xFFF | (a2 << 12);
  if ( v8 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v8 = v13;
  }
  else
  {
    v14 = *(_DWORD *)v8;
    v15 = 0;
    __dmb(0xBu);
    if ( (v14 & 2) == 0 )
      v15 = 1;
    *(_DWORD *)v8 = v13;
    if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
    {
      v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v8 & 0xFFF)), v13);
    }
    if ( v15 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return v9;
}
