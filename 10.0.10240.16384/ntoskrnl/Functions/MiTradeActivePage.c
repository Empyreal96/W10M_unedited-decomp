// MiTradeActivePage 
 
int __fastcall MiTradeActivePage(int a1, _DWORD *a2, unsigned int a3, int a4)
{
  int v7; // lr
  unsigned int v8; // r4
  int v9; // r7
  unsigned int v10; // r0
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  unsigned __int8 *v13; // r1
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r7
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r2
  unsigned int v26; // r2
  int v27; // r0
  int v28; // r3
  int v29; // r3
  int v30; // r0
  int v31; // r3
  int v32; // r7
  int v33; // r0
  int v34; // r4
  int v35; // r0
  int v37; // [sp+4h] [bp-2Ch]
  int v38; // [sp+8h] [bp-28h]
  unsigned int v39; // [sp+Ch] [bp-24h]

  v37 = a3;
  if ( (*(_DWORD *)(a1 + 12) & 0x3FFFFFFF) != 1 || *(_WORD *)(a1 + 16) != 1 )
    return 0;
  v38 = ((int)a2 - MmPfnDatabase) / 24;
  v39 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
  if ( (MiFlags & 0x80000) != 0 )
    return sub_528048();
  v7 = a3;
  v8 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = *(_DWORD *)v8;
  if ( a4 == 2 )
  {
    if ( (v9 & 0x200) != 0 )
      goto LABEL_7;
    return 0;
  }
  v26 = v9 & 0xFFFFFFFC | 0x400;
  if ( v8 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v8 = v26;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v8 = v26;
    if ( v8 + 1070596096 <= 0xFFF )
    {
      v27 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v27, (_DWORD *)(v27 + 4 * (v8 & 0xFFF)), v26);
      v7 = v37;
    }
  }
  KeFlushSingleTb(v7, a4);
LABEL_7:
  v10 = *(unsigned __int8 *)(a1 + 18);
  v11 = (unsigned __int8 *)(a1 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v12 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v28 = *(_DWORD *)(a1 + 12);
      __dmb(0xBu);
    }
    while ( (v28 & 0x80000000) != 0 );
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
  }
  v13 = (unsigned __int8 *)a2 + 15;
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 | 0x80, v13) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v14 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v29 = a2[3];
      __dmb(0xBu);
    }
    while ( (v29 & 0x80000000) != 0 );
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
  }
  MiFinalizePageAttribute((int)a2, v10 >> 6, 1);
  MiCopyPfnEntry((int)a2, (int *)a1);
  MiCopyPage(v38, v39 + (v39 >> 31), 0, 6);
  __dmb(0xBu);
  v15 = a2 + 3;
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 & 0x7FFFFFFF, v15) );
  *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xC0 | 5;
  *(_BYTE *)(a1 + 19) &= 0xD7u;
  __dmb(0xBu);
  v17 = (unsigned int *)(a1 + 12);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
  v19 = a4;
  v20 = v9 & 0xFFF | (v38 << 12);
  if ( a4 == 2 )
  {
    if ( v8 + 0x40000000 <= 0x3FFFFF )
    {
      v21 = *(_DWORD *)v8;
      v22 = 0;
      __dmb(0xBu);
      *(_DWORD *)v8 = v20;
      if ( (v21 & 2) == 0 && (v20 & 2) != 0 )
        v22 = 1;
      if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
      {
        v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * (v8 & 0xFFF)), v20);
        v19 = 2;
      }
      if ( v22 != 1 )
        goto LABEL_23;
      goto LABEL_22;
    }
LABEL_28:
    *(_DWORD *)v8 = v20;
    goto LABEL_23;
  }
  if ( v8 + 0x40000000 > 0x3FFFFF )
    goto LABEL_28;
  v31 = *(_DWORD *)v8;
  v32 = 0;
  __dmb(0xBu);
  *(_DWORD *)v8 = v20;
  if ( (v31 & 2) == 0 && (v20 & 2) != 0 )
    v32 = 1;
  if ( v8 + 1070596096 <= 0xFFF )
  {
    v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * (v8 & 0xFFF)), v20);
    v19 = a4;
  }
  if ( v32 != 1 )
    goto LABEL_23;
LABEL_22:
  __dsb(0xFu);
  __isb(0xFu);
LABEL_23:
  KeFlushSingleTb(v37, v19);
  if ( (a2[5] & 0x8000000) != 0 )
  {
    v23 = a2[1] | 0x80000000;
    v24 = *(_DWORD *)v23;
    v25 = *(_DWORD *)v23 & 0xFFF | (v38 << 12);
    if ( v23 + 0x40000000 <= 0x3FFFFF )
    {
      v34 = 0;
      __dmb(0xBu);
      *(_DWORD *)v23 = v25;
      if ( (v24 & 2) == 0 && (v25 & 2) != 0 )
        v34 = 1;
      if ( v23 + 1070596096 <= 0xFFF )
      {
        v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v35, (_DWORD *)(v35 + 4 * (v23 & 0xFFF)), v25);
      }
      if ( v34 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    else
    {
      *(_DWORD *)v23 = v25;
    }
  }
  return 1;
}
