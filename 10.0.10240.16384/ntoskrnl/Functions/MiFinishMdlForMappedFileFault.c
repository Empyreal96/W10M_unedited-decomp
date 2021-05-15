// MiFinishMdlForMappedFileFault 
 
int __fastcall MiFinishMdlForMappedFileFault(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r8
  int v8; // r7
  int v9; // r10
  unsigned __int8 *v10; // r0
  unsigned int v11; // r5
  unsigned int *v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r4
  __int64 v15; // kr00_8
  unsigned __int64 v16; // r0
  int v17; // r8
  int v18; // lr
  int result; // r0
  _DWORD *v20; // r2
  __int16 v21; // r2
  int v22; // r3
  unsigned int v23; // r2
  unsigned int v24; // [sp+0h] [bp-28h]
  _DWORD *v26; // [sp+4h] [bp-24h]

  v5 = *(_DWORD **)(a1 + 120);
  v8 = *v5;
  v24 = *(_DWORD *)(a1 + 104);
  MiReferenceControlAreaPfn(*v5, v5, a3);
  v9 = *(_DWORD *)(a1 + 92);
  MiObtainProtoReference(v9, 0);
  v10 = (unsigned __int8 *)(v9 + 15);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v22 = *(_DWORD *)(v9 + 12);
        __dmb(0xBu);
      }
      while ( (v22 & 0x80000000) != 0 );
      do
        v23 = __ldrex(v10);
      while ( __strex(v23 | 0x80, v10) );
      __dmb(0xBu);
    }
    while ( v23 >> 7 );
  }
  *(_DWORD *)(v9 + 12) = *(_DWORD *)(v9 + 12) & 0xC0000000 | (*(_DWORD *)(v9 + 12) + a3) & 0x3FFFFFFF;
  __dmb(0xBu);
  v12 = (unsigned int *)(v9 + 12);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 & 0x7FFFFFFF, v12) );
  v14 = *(_DWORD *)(MmPfnDatabase + 24 * *(_DWORD *)(a1 + 180) + 4) | 0x80000000;
  if ( a4 )
    MiFlowThroughInsertNode(a1, a4);
  v26 = *(_DWORD **)(a1 + 132);
  *(_DWORD *)(a1 + 96) = *v26;
  v15 = MiStartingOffset(v5, v14, a5);
  LODWORD(v16) = MiEndingOffsetWithLock(v5);
  if ( (*(_BYTE *)(a1 + 115) & 1) != 0 )
  {
    *(_BYTE *)(a1 + 115) &= 0xFEu;
    v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  v18 = v24;
  if ( (*(_DWORD *)(v8 + 28) & 0x20) != 0 && v15 + (unsigned __int64)v24 > v16 )
  {
    v18 = (v16 - v15 + 511) & 0xFFFFFE00;
    *(_BYTE *)(a1 + 115) |= 1u;
  }
  if ( (a2 & 1) != 0 && *(_BYTE *)(a2 & 0xFFFFFFFE) == 1 )
  {
    if ( (a2 & 0xFFFFFFFE) != 0 )
      *(_BYTE *)(a1 + 113) |= 4u;
  }
  else if ( (a2 & 1) != 0 )
  {
    return sub_544C0C();
  }
  v20 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( ((*(_DWORD *)(v20[84] + 192) & 0x100000) != 0 || ((v20[240] >> 9) & 7u) < 2)
    && (v20 != (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !v20[250]) )
  {
    *(_BYTE *)(a1 + 113) |= 0x40u;
  }
  *(_DWORD *)(a1 + 152) = 0;
  *(_WORD *)(a1 + 158) = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 172) = v18;
  *(_DWORD *)(a1 + 176) = 0;
  *(_WORD *)(a1 + 156) = 4 * (((unsigned int)(v18 + 4095) >> 12) + 7);
  MiUnlockProtoPoolPage(v9, 17);
  result = MmPfnDatabase + 24 * *(_DWORD *)(a1 + 180 + 4 * ((int)((int)v26 - v14) >> 2));
  v21 = *(_WORD *)(a1 + 158) | 0x42;
  *(_WORD *)(a1 + 158) = v21;
  if ( !v17 )
    *(_WORD *)(a1 + 158) = v21 | 0x4000;
  *(_DWORD *)(a1 + 116) = 0;
  *(_DWORD *)(a1 + 120) = v8;
  *(_QWORD *)(a1 + 56) = v15;
  *(_DWORD *)(a1 + 136) = v14;
  *(_DWORD *)(a1 + 140) = result;
  return result;
}
