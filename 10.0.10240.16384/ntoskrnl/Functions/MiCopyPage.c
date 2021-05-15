// MiCopyPage 
 
int __fastcall MiCopyPage(int a1, int a2, char *a3, char a4)
{
  char v6; // r6
  int v7; // r8
  int v8; // r5
  int v10; // r0
  char v11; // lr
  int result; // r0
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r7
  unsigned int i; // r3
  unsigned int v18; // r1
  unsigned int v19; // r1
  int v20; // r0
  int v21; // r0
  char v22; // [sp+8h] [bp-40h]
  unsigned int v24; // [sp+10h] [bp-38h] BYREF
  char v25[48]; // [sp+18h] [bp-30h] BYREF

  v6 = 0;
  v7 = MmPfnDatabase + 24 * a2;
  v8 = MmPfnDatabase + 24 * a1;
  v22 = 0;
  if ( (a4 & 4) != 0 )
    v22 = 4;
  v10 = MiGetPagePrivilege(v7, a4 & 4, &v24);
  v11 = BYTE2(MiFlags);
  v24 = dword_63389C;
  if ( v10 == 1 )
    return sub_539F24();
  if ( (a4 & 2) == 0 )
    v6 = 4;
  if ( (v6 & 2) != 0 )
  {
    if ( (BYTE2(MiFlags) & 3) == 3 )
    {
      ++dword_63381C;
      KeFlushTb(3, 2);
      v11 = BYTE2(MiFlags);
      v19 = dword_63389C;
    }
    else
    {
      v19 = v24;
    }
    if ( (MiFlags & 0x80000) != 0 && (a4 & 2) == 0 && *(_DWORD *)(v8 + 4) << 10 < v19 )
    {
      __mrc(15, 0, 13, 0, 3);
      v11 = BYTE2(MiFlags);
    }
    if ( (v11 & 3) != 2 )
      KeBugCheckEx(26, 333066, a2);
  }
  if ( (*(_BYTE *)(v7 + 23) & 7) == 3 )
  {
    if ( (a4 & 2) != 0 )
      MiClearPfnImageVerified(v7, v22, (int)&MmPfnDatabase, 3);
    if ( (v6 & 4) == 0 && (*(_BYTE *)(v8 + 23) & 7) != 3 )
      MiMarkPfnVerified(v8, v22);
  }
  v13 = *(unsigned __int8 *)(v7 + 18);
  if ( *(unsigned __int8 *)(v8 + 18) >> 6 != v13 >> 6 )
    MiChangePageAttribute(v8, v13 >> 6, 0);
  if ( !a3 )
  {
    if ( (a4 & 1) != 0 )
      v6 |= 1u;
    a3 = v25;
    MiGetPteMappingPair(v6 & 1, v25);
  }
  v14 = MiGetPteFromCopyList(a3, a1, a2);
  v15 = (v14 << 10) + 4096;
  v16 = v14;
  result = memmove(v14 << 10, v15, 0x1000u);
  if ( (unsigned int)KiICacheFlushPromoteThreshold < 0x1000 )
  {
    result = KeSweepIcache(1);
  }
  else
  {
    for ( i = ~(KiMinimumDcacheLine - 1) & (v16 << 10); i < v15; i += KiMinimumDcacheLine )
      __mcr(15, 0, i, 7, 11, 1);
    __dsb(0xFu);
    if ( (KiCacheType & 0xC000) == 49152 )
      result = KiVoidIcacheRangePoUWithCatch(v16 << 10, 4096);
    else
      __mcr(15, 0, 0, 7, 1, 0);
    __mcr(15, 0, 0, 7, 5, 6);
    __dsb(0xFu);
    __isb(0xFu);
  }
  if ( v16 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v16 = 0;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v16 = 0;
    if ( v16 >= 0xC0300000 && v16 <= 0xC0300FFF )
    {
      v20 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v20, v20 + 4 * (v16 & 0xFFF), 0);
    }
  }
  v18 = v16 + 4;
  if ( v16 + 1073741828 > 0x3FFFFF )
  {
    *(_DWORD *)v18 = 0;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v18 = 0;
    if ( v18 >= 0xC0300000 && v18 <= 0xC0300FFF )
    {
      v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v21, v21 + 4 * (v18 & 0xFFF), 0);
    }
  }
  if ( a3 == v25 )
    result = MiReturnPteMappingPair(a3);
  return result;
}
