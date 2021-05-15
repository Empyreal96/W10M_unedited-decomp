// MiDeleteLockedTransitionPte 
 
int __fastcall MiDeleteLockedTransitionPte(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r9
  int v7; // r6
  int v8; // r4
  int v9; // lr
  int v10; // r10
  int v11; // r3
  int v12; // r5
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r4
  unsigned __int8 *v16; // r7
  unsigned int v17; // r0
  int v18; // r2
  bool v19; // zf
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v23; // r2
  int v24; // r3
  int v25; // r3
  unsigned int v26; // r2
  int v27; // r0
  unsigned int v28; // r4
  int v29; // [sp+8h] [bp-30h]
  __int16 *v30; // [sp+Ch] [bp-2Ch]

  v6 = (int)((unsigned __int64)(715827883i64 * (a2 - MmPfnDatabase)) >> 32) >> 2;
  if ( (*(_DWORD *)(a2 + 4) | 0x80000000) != a1 )
    sub_537BE4();
  v7 = 0;
  v8 = *(_DWORD *)(a2 + 20) & 0xFFFFF;
  v30 = 0;
  if ( (*(_DWORD *)(a2 + 8) & 0x400) != 0 )
  {
    MiDereferenceControlAreaPfn(
      *(_DWORD *)(*(_DWORD *)(a2 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a2 + 8) & 0x3FC))),
      *(_DWORD *)(a2 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a2 + 8) & 0x3FC)),
      2);
    v9 = *(_DWORD *)(a2 + 8);
  }
  else
  {
    v9 = 0;
  }
  v10 = 0;
  if ( *(_WORD *)(a2 + 16) )
  {
    *(_DWORD *)(a2 + 12) |= 0x40000000u;
    if ( (*(_BYTE *)(a2 + 18) & 0x20) != 0 && (*(_BYTE *)(a2 + 18) & 8) == 0 )
    {
      v10 = *(_DWORD *)a2 - 16;
      if ( *(_DWORD *)(*(_DWORD *)a2 - 8) == *(_DWORD *)a2 - 8 )
        v10 = 0;
    }
    v12 = 3;
  }
  else
  {
    MiUnlinkPageFromList(a2, 0);
    v11 = *(_DWORD *)(a2 + 8);
    if ( (v11 & 0x400) == 0 )
    {
      v7 = *(_DWORD *)(a2 + 8);
      if ( (v11 & 0x10) == 0 && (v11 & 8) == 0 )
        v7 = 0;
      v30 = MiSystemPartition;
    }
    v12 = 4;
  }
  if ( a1 + 0x40000000 <= 0x3FFFFF )
  {
    v23 = 0;
    v24 = *(_DWORD *)a1;
    v29 = 0;
    __dmb(0xBu);
    *(_DWORD *)a1 = v9;
    if ( (v24 & 2) == 0 && (v9 & 2) != 0 )
    {
      v23 = 1;
      v29 = 1;
    }
    if ( a1 >= 0xC0300000 && a1 <= 0xC0300FFF )
    {
      v27 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v27, v27 + 4 * (a1 & 0xFFF), v9);
      v23 = v29;
    }
    if ( v23 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  else
  {
    *(_DWORD *)a1 = v9;
  }
  if ( v12 == 4 )
    MiInsertPageInFreeOrZeroedList(v6 + (v6 >> 31), 2);
  __dmb(0xBu);
  v13 = (unsigned int *)(a2 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  v15 = MmPfnDatabase + 24 * v8;
  v16 = (unsigned __int8 *)(v15 + 15);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 | 0x80, v16) );
  __dmb(0xBu);
  if ( v17 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v25 = *(_DWORD *)(v15 + 12);
        __dmb(0xBu);
      }
      while ( (v25 & 0x80000000) != 0 );
      do
        v26 = __ldrex(v16);
      while ( __strex(v26 | 0x80, v16) );
      __dmb(0xBu);
    }
    while ( v26 >> 7 );
  }
  v18 = *(_DWORD *)(v15 + 12);
  if ( (*(_BYTE *)(v15 + 18) & 7) != 6 )
    KeBugCheckEx(78, 153, (v15 - MmPfnDatabase) / 24);
  *(_DWORD *)(v15 + 12) = v18 & 0xC0000000 | ((v18 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
  if ( (v18 & 0x3FFFFFFF) == 1 )
    MiPfnShareCountIsZero(v15, 0);
  v19 = a3 == 17;
  __dmb(0xBu);
  v20 = (unsigned int *)(v15 + 12);
  if ( v19 )
  {
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 & 0x7FFFFFFF, v20) );
  }
  else
  {
    do
      v28 = __ldrex(v20);
    while ( __strex(v28 & 0x7FFFFFFF, v20) );
    KfLowerIrql(a3);
  }
  if ( v10 )
    MiInvalidateCollidedIos(v10);
  if ( v7 && a4 )
    MiReleasePageFileInfo(v30, v7, a3 == 17);
  return v12;
}
