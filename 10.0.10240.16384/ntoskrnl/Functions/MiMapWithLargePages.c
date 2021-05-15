// MiMapWithLargePages 
 
int __fastcall MiMapWithLargePages(unsigned int a1, unsigned int a2, char a3, int a4, int a5)
{
  unsigned int v7; // r9
  int v8; // r7
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r9
  unsigned int v16; // r7
  unsigned int v17; // r1
  unsigned int v18; // r9
  int v19; // r3
  int v20; // r8
  unsigned int v21; // r4
  unsigned int v22; // r3
  unsigned int v23; // r5
  unsigned int v24; // r9
  unsigned int v25; // r7
  int v26; // r3
  int v27; // r8
  int v28; // r0
  int v29; // r3
  int v30; // r0
  unsigned int v31; // [sp+0h] [bp-38h]
  unsigned int v33; // [sp+Ch] [bp-2Ch]
  unsigned int v34; // [sp+10h] [bp-28h]

  v7 = a1;
  if ( a5 == 9 )
    v8 = 16;
  else
    v8 = a5;
  v9 = a2 >> 10;
  v33 = a2 >> 10 << 10;
  v10 = a3 & 7;
  if ( (a2 & 0x3FF) != 0 )
    ++v9;
  v11 = MiObtainSystemVa(v9, v8);
  v12 = v11;
  v34 = v11;
  if ( !v11 )
    JUMPOUT(0x551D16);
  v31 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( MI_IS_PFN(v7) )
  {
    v29 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v7 + 18) >> 6;
    if ( v29 )
    {
      if ( v29 == 2 )
        v10 |= 0x18u;
    }
    else
    {
      v10 |= 8u;
    }
  }
  else if ( a4 )
  {
    if ( a4 == 2 )
      v10 |= 0x38u;
  }
  else
  {
    v10 |= 0x28u;
  }
  if ( a2 != v33 )
  {
    v13 = v31 + 4 * v33;
    v14 = v31 + 4 * a2;
    if ( !MiMakeZeroedPageTables(v13, v14 - 4, a5 == 12) )
      return sub_551D08();
    v16 = (MmProtectToPteMask[v10] & 0x3ED ^ ((a1 + v33) << 12) | MiDetermineUserGlobalPteMask(0)) & 0xFFFFF3FF | 0x12;
    if ( (v16 & 0x80) != 0 )
      v16 &= 0xFFFFFDFF;
    if ( v13 < v14 )
    {
      v17 = v31;
      v18 = v13 + 0x40000000;
      do
      {
        if ( v18 > 0x3FFFFF )
        {
          *(_DWORD *)v13 = v16;
        }
        else
        {
          v19 = *(_DWORD *)v13;
          v20 = 0;
          __dmb(0xBu);
          *(_DWORD *)v13 = v16;
          if ( (v19 & 2) == 0 && (v16 & 2) != 0 )
            v20 = 1;
          if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
          {
            v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * (v13 & 0xFFF)), v16);
          }
          if ( v20 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
          v17 = v31;
        }
        v16 = v16 & 0xFFF ^ ((v16 & 0xFFFFF000) + 4096);
        v13 += 4;
        v18 += 4;
      }
      while ( v13 < v17 + 4 * a2 );
      v12 = v34;
    }
    v7 = a1;
  }
  v21 = ((v31 >> 10) & 0x3FFFFC) - 0x40000000;
  v22 = (MmProtectToPteMask[v10] & 0x3ED | MiDetermineUserGlobalPteMask(0) | (v7 << 12)) & 0xFFFFF3FF | 0x12;
  if ( (v22 & 0x80) != 0 )
    v22 &= 0xFFFFFDFF;
  v23 = v22 | 0x400;
  v24 = v21 + 4 * (v33 >> 10);
  if ( v21 < v24 )
  {
    v25 = ((v31 >> 10) & 0x3FFFFC) - 3145728;
    do
    {
      if ( v25 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v21 = v23;
      }
      else
      {
        v26 = *(_DWORD *)v21;
        v27 = 0;
        __dmb(0xBu);
        *(_DWORD *)v21 = v23;
        if ( (v26 & 2) == 0 && (v23 & 2) != 0 )
          v27 = 1;
        if ( v25 <= 0xFFF )
        {
          v28 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v28, (_DWORD *)(v28 + 4 * (v21 & 0xFFF)), v23);
        }
        if ( v27 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v21 += 4;
      v23 = v23 & 0xFFF ^ ((v23 & 0xFFFFF000) + 0x400000);
      v25 += 4;
    }
    while ( v21 < v24 );
    v12 = v34;
  }
  MiReplicatePteChange(v31, v31 + 4 * a2 - 4);
  return v12;
}
