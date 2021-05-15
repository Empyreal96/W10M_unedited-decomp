// MmMapMemoryDumpMdlEx 
 
int __fastcall MmMapMemoryDumpMdlEx(unsigned int a1, int a2, int a3, char a4)
{
  int v4; // r5
  int v5; // r6
  char v6; // lr
  unsigned int v7; // r9
  unsigned int v8; // r4
  unsigned int v9; // r6
  int v10; // r2
  unsigned int v11; // r8
  int v12; // r7
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r3
  int result; // r0
  int v17; // r2
  int v18; // r7
  int v19; // r0
  int v20; // r7
  int v21; // r0
  int v22; // [sp+0h] [bp-C8h]
  int v25; // [sp+10h] [bp-B8h] BYREF
  char v26; // [sp+14h] [bp-B4h]
  char v27; // [sp+15h] [bp-B3h]
  int v28; // [sp+18h] [bp-B0h]
  int v29; // [sp+1Ch] [bp-ACh]
  int v30; // [sp+20h] [bp-A8h]
  int v31; // [sp+24h] [bp-A4h]

  v4 = a3;
  v5 = *(_DWORD *)(a3 + 24);
  v6 = a4;
  v7 = ((((_WORD)v5 + (unsigned __int16)*(_QWORD *)(a3 + 20)) & 0xFFF) != 0)
     + ((unsigned int)(v5 + *(_DWORD *)(a3 + 20)) >> 12);
  v8 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  *(_DWORD *)(a3 + 12) = v5 + a1;
  v29 = 0;
  v30 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 33;
  v31 = 0;
  v9 = ((a1 >> 10) & 0x3FFFFC) - 3145728;
  v10 = a3 + 28 - ((a1 >> 10) & 0x3FFFFC) + 0x40000000;
  v22 = v4 + 28 - ((a1 >> 10) & 0x3FFFFC) + 0x40000000;
  v11 = a1 & 0xFFFFF000;
  do
  {
    v12 = 4;
    if ( (v6 & 1) == 0 )
      v12 = MiMakeProtectionPfnCompatible(4, MmPfnDatabase + 24 * *(_DWORD *)(v10 + v8));
    v13 = MiDetermineUserGlobalPteMask(v8);
    v14 = *(_DWORD *)v8;
    v15 = (MmProtectToPteMask[v12] & 0x1ED | (*(_DWORD *)(v22 + v8) << 12) | v13) & 0xFFFFF1FF;
    result = 2;
    v17 = v15 | 0x12;
    if ( (*(_DWORD *)v8 & 2) != 0 )
    {
      if ( v14 != v17 )
      {
        if ( v9 + 3145728 > 0x3FFFFF )
        {
          *(_DWORD *)v8 = v17;
        }
        else
        {
          v18 = 0;
          __dmb(0xBu);
          if ( (v14 & 2) == 0 )
            v18 = 1;
          *(_DWORD *)v8 = v17;
          if ( v9 <= 0xFFF )
          {
            v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * (v8 & 0xFFF)), v17);
          }
          if ( v18 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        result = MiInsertTbFlushEntry((int)&v25, v11, 1, 0);
      }
    }
    else if ( v9 + 3145728 > 0x3FFFFF )
    {
      *(_DWORD *)v8 = v17;
    }
    else
    {
      v20 = 0;
      __dmb(0xBu);
      if ( (v14 & 2) == 0 )
        v20 = 1;
      *(_DWORD *)v8 = v17;
      if ( v9 <= 0xFFF )
      {
        v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v21, (_DWORD *)(v21 + 4 * (v8 & 0xFFF)), v17);
      }
      if ( v20 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v10 = v22;
    v6 = a4;
    v8 += 4;
    v9 += 4;
    --v7;
    v11 += 4096;
  }
  while ( v7 );
  *(_WORD *)(a3 + 6) |= 0x2002u;
  if ( v29 )
  {
    v26 = 3;
    result = MiFlushTbList((unsigned int)&v25, (int)&MmPfnDatabase);
  }
  return result;
}
