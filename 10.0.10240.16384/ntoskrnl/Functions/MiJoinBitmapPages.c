// MiJoinBitmapPages 
 
int __fastcall MiJoinBitmapPages(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r7
  int v5; // r0
  int v6; // r1
  unsigned int v7; // r10
  int v8; // r9
  unsigned int v9; // r4
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r3
  int v14; // r5
  int v15; // r0
  int v16; // r1
  int v18; // [sp+0h] [bp-C8h]
  int v21; // [sp+10h] [bp-B8h] BYREF
  char v22; // [sp+14h] [bp-B4h]
  char v23; // [sp+15h] [bp-B3h]
  int v24; // [sp+18h] [bp-B0h]
  int v25; // [sp+1Ch] [bp-ACh]
  int v26; // [sp+20h] [bp-A8h]
  int v27; // [sp+24h] [bp-A4h]

  v3 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = a3;
  v5 = MiDetermineUserGlobalPteMask(v3);
  v6 = 0;
  v18 = 0;
  v7 = (dword_681114 & 0xFEC | (dword_6348F4 << 12) | v5 | 0x13) & 0xFFFFF7FF;
  if ( v4 )
  {
    v8 = v4;
    v9 = v3 + 1070596096;
    while ( 1 )
    {
      v10 = 3 * (*(_DWORD *)v3 >> 12);
      v11 = MmPfnDatabase;
      *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v3 >> 12)) = v6;
      v18 = v11 + 8 * v10;
      if ( v9 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v3 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v3 = 0;
        if ( v9 <= 0xFFF )
        {
          v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * (v3 & 0xFFF)), 0);
        }
      }
      if ( v9 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v3 = v7;
      }
      else
      {
        v13 = *(_DWORD *)v3;
        v14 = 0;
        __dmb(0xBu);
        if ( (v13 & 2) == 0 )
          v14 = 1;
        *(_DWORD *)v3 = v7;
        if ( v9 <= 0xFFF )
        {
          v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * (v3 & 0xFFF)), v7);
        }
        if ( v14 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v3 += 4;
      v9 += 4;
      if ( !--v8 )
        break;
      v6 = v18;
    }
    v4 = a3;
  }
  v25 = 0;
  v26 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 33;
  v27 = 0;
  MiInsertTbFlushEntry((int)&v21, a2, v4, 0);
  MiFlushTbList((unsigned int)&v21, v16);
  return MiReturnSplitPages(v18);
}
