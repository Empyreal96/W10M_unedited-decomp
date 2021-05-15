// MiMapMdlCommon 
 
int __fastcall MiMapMdlCommon(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v5; // r7
  unsigned int v6; // r10
  int v7; // r8
  unsigned int v8; // r6
  unsigned int v9; // r5
  int v10; // r4
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r0
  __int16 v17; // r3
  __int16 v18; // r3
  int v20; // [sp+0h] [bp-28h]
  int v22; // [sp+8h] [bp-20h]

  v4 = *(_DWORD *)(a1 + 24);
  v5 = a2;
  v6 = (*(_DWORD *)(a1 + 20) + (((unsigned __int16)*(_DWORD *)(a1 + 16) + (_WORD)v4) & 0xFFFu) + 4095) >> 12;
  v7 = MiPlatformCacheAttributes[a4 + 6];
  v22 = v4 + (a2 << 10);
  v20 = MiPlatformCacheAttributes[a4];
  v8 = a1 + 28 - a2;
  do
  {
    v9 = *(_DWORD *)(v8 + v5);
    v10 = 4;
    if ( MI_IS_PFN(v9) )
    {
      v11 = MmPfnDatabase + 24 * v9;
      if ( !*(_WORD *)(v11 + 16) && !dword_634380 )
        MiShowBadMapper(v9, 1);
      if ( (*(_BYTE *)(v11 + 18) & 0xC0) == 192 )
        MiAssignInitialPageAttribute(v11, v20);
      v10 = MiMakeProtectionPfnCompatible(4, v11);
    }
    else if ( v7 )
    {
      if ( v7 == 2 )
        v10 = 60;
    }
    else
    {
      v10 = 44;
    }
    v12 = (MmProtectToPteMask[v10] | MiDetermineUserGlobalPteMask(v5)) & 0x3ED | 0xFFFFF012;
    if ( (v12 & 0x80) != 0 )
      LOWORD(v12) = v12 & 0xFDFF;
    v13 = v12 & 0xFFF | (*(_DWORD *)(v8 + v5) << 12);
    if ( v5 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v5 = v13;
    }
    else
    {
      v14 = *(_DWORD *)v5;
      v15 = 0;
      __dmb(0xBu);
      if ( (v14 & 2) == 0 )
        v15 = 1;
      *(_DWORD *)v5 = v13;
      if ( v5 + 1070596096 <= 0xFFF )
      {
        v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v5 & 0xFFF)), v13);
      }
      if ( v15 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v5 += 4;
    --v6;
  }
  while ( v6 );
  v17 = *(_WORD *)(a1 + 6);
  *(_DWORD *)(a1 + 12) = v22;
  v18 = v17 | 1;
  *(_WORD *)(a1 + 6) = v18;
  if ( (v18 & 0x10) != 0 )
    *(_WORD *)(a1 + 6) = v18 | 0x20;
  return v22;
}
