// sub_96B050 
 
void __fastcall sub_96B050(int a1, int a2, int a3, int a4, __int16 a5, int a6)
{
  unsigned int *v6; // r2
  unsigned int v7; // r0
  unsigned int *v8; // r2
  unsigned int v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // lr
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r5
  int v16; // r6
  unsigned int v17; // r7
  unsigned int v18; // r8
  int v19; // r7
  int v20; // r9
  int v21; // r10
  unsigned __int8 *v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  unsigned __int8 *v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r6
  int v30; // r0
  int v31; // r0
  _DWORD *v32; // r1
  int v33; // r3
  int v34; // r4
  int v35; // r0

  v19 = MmPfnDatabase + 24 * (v17 >> 12);
  v20 = MmPfnDatabase + 24 * v16;
  v21 = KfRaiseIrql(2);
  v22 = (unsigned __int8 *)(v19 + 15);
  do
    v23 = __ldrex(v22);
  while ( __strex(v23 | 0x80, v22) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v23 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v24 = *(_DWORD *)(v19 + 12);
      __dmb(0xBu);
    }
    while ( (v24 & 0x80000000) != 0 );
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 | 0x80, v22) );
  }
  v25 = (unsigned __int8 *)(v20 + 15);
  do
    v26 = __ldrex(v25);
  while ( __strex(v26 | 0x80, v25) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v26 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v27 = *(_DWORD *)(v20 + 12);
      __dmb(0xBu);
    }
    while ( (v27 & 0x80000000) != 0 );
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 | 0x80, v25) );
  }
  MiFinalizePageAttribute(v20, *(unsigned __int8 *)(v19 + 18) >> 6, 1);
  MiCopyPfnEntry(v20, (int *)v19);
  __dmb(0xBu);
  v6 = (unsigned int *)(v20 + 12);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0x7FFFFFFF, v6) );
  __dmb(0xBu);
  v8 = (unsigned int *)(v19 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  KfLowerIrql(v21);
  v10 = ((v18 >> 10) & 0x3FFFFC) - 0x40000000;
  v11 = (dword_681120 & 0x1ED | (v16 << 12) | MiDetermineUserGlobalPteMask(v10)) & 0xFFFFF1FF | 0x12;
  if ( v10 < 0xC0000000 || v10 > 0xC03FFFFF )
  {
    *(_DWORD *)v10 = v11;
  }
  else
  {
    v28 = *(_DWORD *)v10;
    v29 = 0;
    __dmb(0xBu);
    *(_DWORD *)v10 = v11;
    if ( (v28 & 2) == 0 )
      v29 = 1;
    if ( ((v18 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
    {
      v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * (v10 & 0xFFF)), v11);
    }
    if ( v29 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  memmove(v18, v15 << 10, 0x1000u);
  if ( ((v10 ^ (v15 << 10)) & 0xFFFFF000) != 0 )
  {
    if ( v10 < 0xC0000000 || v10 > 0xC03FFFFF )
    {
      *(_DWORD *)v10 = 0;
      goto LABEL_45;
    }
    __dmb(0xBu);
    *(_DWORD *)v10 = 0;
    if ( ((v18 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
    {
      v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      v32 = (_DWORD *)(v31 + 4 * (v10 & 0xFFF));
      goto LABEL_25;
    }
  }
  else
  {
    v14 = v18 + 4 * ((v10 >> 2) & 0x3FF);
    if ( v14 < 0xC0000000 || v14 > 0xC03FFFFF )
    {
      *(_DWORD *)v14 = 0;
      goto LABEL_45;
    }
    __dmb(0xBu);
    *(_DWORD *)v14 = 0;
    if ( v14 + 1070596096 <= 0xFFF )
    {
      v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      v32 = (_DWORD *)(v31 + 4 * (v14 & 0xFFF));
LABEL_25:
      MiArmWriteConvertedHardwarePde(v31, v32, 0);
      goto LABEL_45;
    }
  }
LABEL_45:
  v12 = a5 & 0xFEF | (a6 << 12) | 0x10;
  if ( v15 < 0xC0000000 || v15 > 0xC03FFFFF )
  {
    *(_DWORD *)v15 = v12;
  }
  else
  {
    v33 = *(_DWORD *)v15;
    v34 = 0;
    __dmb(0xBu);
    *(_DWORD *)v15 = v12;
    if ( (v33 & 2) == 0 && ((a5 & 0xEF | 0x10) & 2) != 0 )
      v34 = 1;
    if ( v15 + 1070596096 <= 0xFFF )
    {
      v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v35, (_DWORD *)(v35 + 4 * (v15 & 0xFFF)), v12);
    }
    if ( v34 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  KeFlushSingleTb(v15 << 10, 1);
  KeFlushSingleTb(v18, 1);
  v13 = *(_DWORD *)(v19 + 12);
  *(_WORD *)(v19 + 16) = 0;
  *(_DWORD *)(v19 + 12) = v13 & 0xC0000000;
  *(_BYTE *)(v19 + 18) &= 0xD7u;
  MiLockAndInsertPageInFreeList(v19);
  JUMPOUT(0x95657C);
}
