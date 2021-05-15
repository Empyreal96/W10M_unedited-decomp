// MiGetPteFromCopyList 
 
int __fastcall MiGetPteFromCopyList(__int64 *a1, int a2, int a3)
{
  int v3; // r7
  __int64 v7; // r2
  unsigned int v8; // r4
  int v9; // r5
  int v10; // r0
  int result; // r0
  unsigned int v12; // lr
  int v13; // r3
  int v14; // r5
  int v15; // r5
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r6
  int v20; // r3
  int v21; // r5
  int v22; // r1
  int v23; // r0
  int v24; // r0
  int v25; // [sp+0h] [bp-B8h] BYREF
  char v26; // [sp+4h] [bp-B4h]
  char v27; // [sp+5h] [bp-B3h]
  int v28; // [sp+8h] [bp-B0h]
  int v29; // [sp+Ch] [bp-ACh]
  int v30; // [sp+10h] [bp-A8h]
  int v31; // [sp+14h] [bp-A4h]

  v3 = 2;
  if ( a3 == -1 )
    v3 = 1;
  v7 = *a1;
  if ( (unsigned int)(*(_DWORD *)a1 + v3) > *((_DWORD *)a1 + 1) )
  {
    v25 = 0;
    v30 = 0;
    HIDWORD(v7) = *((_DWORD *)a1 + 3);
    v26 = 0;
    v28 = 33;
    v29 = 0;
    v27 = 0;
    v31 = 0;
    MiInsertTbFlushEntry((int)&v25, HIDWORD(v7) << 10, v7, 0);
    MiFlushTbList((unsigned int)&v25, v22);
    *(_DWORD *)a1 = 0;
  }
  v8 = *((_DWORD *)a1 + 3) + 4 * *(_DWORD *)a1;
  *(_DWORD *)a1 += v3;
  v9 = 4;
  v10 = *(unsigned __int8 *)(MmPfnDatabase + 24 * a2 + 18) >> 6;
  if ( !v10 )
    return sub_5434C0();
  if ( v10 == 2 )
    v9 = 28;
  v12 = (MiDetermineUserGlobalPteMask(v8) | MmProtectToPteMask[v9] & 0x1ED | (a2 << 12)) & 0xFFFFF1FF | 0x12;
  if ( v8 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v8 = v12;
  }
  else
  {
    v13 = *(_DWORD *)v8;
    v14 = 0;
    __dmb(0xBu);
    if ( (v13 & 2) == 0 )
      v14 = 1;
    *(_DWORD *)v8 = v12;
    if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
    {
      v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v23, (_DWORD *)(v23 + 4 * (v8 & 0xFFF)), v12);
    }
    if ( v14 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( a3 == -1 )
    return v8;
  v15 = 1;
  v16 = *(unsigned __int8 *)(MmPfnDatabase + 24 * a3 + 18) >> 6;
  if ( v16 )
  {
    if ( v16 == 2 )
      v15 = 25;
  }
  else
  {
    v15 = 9;
  }
  v17 = MiDetermineUserGlobalPteMask(v8);
  v18 = v8 + 4;
  v19 = (v17 | MmProtectToPteMask[v15] & 0x3ED | (a3 << 12)) & 0xFFFFF3FF | 0x12;
  if ( v8 + 1073741828 > 0x3FFFFF )
  {
    *(_DWORD *)v18 = v19;
    result = v8;
  }
  else
  {
    v20 = *(_DWORD *)v18;
    v21 = 0;
    __dmb(0xBu);
    if ( (v20 & 2) == 0 )
      v21 = 1;
    *(_DWORD *)v18 = v19;
    if ( v18 >= 0xC0300000 && v18 <= 0xC0300FFF )
    {
      v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v24, (_DWORD *)(v24 + 4 * (v18 & 0xFFF)), v19);
    }
    if ( v21 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    result = v8;
  }
  return result;
}
