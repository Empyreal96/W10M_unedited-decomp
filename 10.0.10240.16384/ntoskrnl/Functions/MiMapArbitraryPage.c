// MiMapArbitraryPage 
 
int __fastcall MiMapArbitraryPage(int a1, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  int v7; // r6
  unsigned __int8 *v8; // r1
  unsigned int v9; // r5
  int v11; // r0
  int v12; // r4
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r4
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r0
  int v24; // [sp+4h] [bp-24h]

  v4 = *(_QWORD *)(a2 + 32);
  v24 = ((int)v4 - MmPfnDatabase) / 24;
  v7 = KfRaiseIrql(2);
  v8 = (unsigned __int8 *)(v4 + 15);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    return sub_54EF20();
  v11 = MiCombineCandidate(a1, v4);
  if ( !a3 )
  {
    if ( v11 )
      goto LABEL_7;
LABEL_24:
    __dmb(0xBu);
    v20 = (unsigned int *)(v4 + 12);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 & 0x7FFFFFFF, v20) );
    KfLowerIrql(v7);
    return 0;
  }
  if ( v11 != a3 )
    goto LABEL_24;
LABEL_7:
  if ( a4 == 1 )
  {
    v19 = *(_BYTE *)(v4 + 18) & 7;
    if ( v19 < 2 || v19 > 3 )
      goto LABEL_24;
  }
  if ( (*(_BYTE *)(v4 + 18) & 0xC0) == 192 )
    goto LABEL_24;
  v12 = MiMakeProtectionPfnCompatible(1, v4);
  v13 = MiDetermineUserGlobalPteMask(HIDWORD(v4)) | MmProtectToPteMask[v12] & 0x3ED | (v24 << 12);
  *(_QWORD *)(a2 + 24) = v4;
  v14 = v13 & 0xFFFFF3FF | 0x12;
  if ( (unsigned int)(HIDWORD(v4) + 0x40000000) > 0x3FFFFF )
  {
    *(_DWORD *)HIDWORD(v4) = v14;
  }
  else
  {
    v15 = *(_DWORD *)HIDWORD(v4);
    v16 = 0;
    __dmb(0xBu);
    if ( (v15 & 2) == 0 )
      v16 = 1;
    *(_DWORD *)HIDWORD(v4) = v14;
    if ( HIDWORD(v4) >= 0xC0300000 && HIDWORD(v4) <= 0xC0300FFF )
    {
      v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v22, (_DWORD *)(v22 + 4 * (WORD2(v4) & 0xFFF)), v14);
    }
    if ( v16 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  __dmb(0xBu);
  v17 = (unsigned int *)(v4 + 12);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
  KfLowerIrql(v7);
  return 1;
}
