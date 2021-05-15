// MiInsertCachedPte 
 
int __fastcall MiInsertCachedPte(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  char v5; // r4
  int v6; // r8
  int v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r4
  int v10; // r7
  unsigned int v11; // r0
  int v12; // r2
  int v13; // r3
  unsigned __int64 v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int *v18; // r1
  unsigned int v19; // r2
  int v20; // r3
  unsigned int v21; // r3
  unsigned __int64 v22; // r2
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r4
  int v26; // r0
  unsigned int *v27; // r2
  unsigned int v28; // r4
  int v29; // r0
  int v30; // r0
  int v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r4
  int v34; // r0
  unsigned int *v35; // r2
  unsigned int v36; // r4
  unsigned int i; // [sp+0h] [bp-50h]
  int v38; // [sp+4h] [bp-4Ch]
  int v39; // [sp+8h] [bp-48h]
  int v41; // [sp+10h] [bp-40h]
  unsigned __int64 v42; // [sp+14h] [bp-3Ch]
  unsigned int v43; // [sp+1Ch] [bp-34h]
  int v44; // [sp+20h] [bp-30h]
  int v45; // [sp+24h] [bp-2Ch]

  if ( a3 > 0x40 )
    return 0;
  v43 = a1[2];
  if ( a2 == v43 )
    return 0;
  if ( a3 == 1 )
  {
    v5 = 1;
  }
  else
  {
    v18 = (unsigned int *)(a2 + 4);
    v5 = 0;
    v19 = a3 << 13;
    if ( a2 + 1073741828 > 0x3FFFFF )
    {
      *v18 = v19;
    }
    else
    {
      __dmb(0xBu);
      *v18 = v19;
      if ( (unsigned int)v18 >= 0xC0300000 )
        return sub_542568(-1070592001);
    }
  }
  v38 = a1[11] + 72 * *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
  while ( 1 )
  {
    __dmb(0xFu);
    v6 = KiTbFlushTimeStamp;
    __dmb(0xBu);
    if ( v6 )
      break;
    KeFlushTb(0, 1);
  }
  v7 = v5 & 1;
  v9 = *(_DWORD *)(v38 + 8 * (v6 & 7) + 4);
  v8 = *(_DWORD *)(v38 + 8 * (v6 & 7));
  v39 = v38 + 8 * (v6 & 7);
  v44 = 4 * v7;
  LOWORD(v10) = 4 * v7;
LABEL_8:
  for ( i = v8; ; v8 = i )
  {
    while ( 1 )
    {
      v11 = v9;
      v42 = __PAIR64__(v8, v9);
      if ( v8 != v6 )
      {
        if ( v9 )
          break;
      }
      v10 = v10 & 0x1FFF | (v9 << 13);
      if ( a2 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a2 = v10;
      }
      else
      {
        v12 = 0;
        v13 = *(_DWORD *)a2;
        v41 = 0;
        __dmb(0xBu);
        *(_DWORD *)a2 = v10;
        if ( (v13 & 2) == 0 && (v10 & 2) != 0 )
        {
          v12 = 1;
          v41 = 1;
        }
        if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
        {
          v29 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v29, (_DWORD *)(v29 + 4 * (a2 & 0xFFF)), v10);
          v8 = i;
          v12 = v41;
          v11 = v9;
        }
        if ( v12 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      __dmb(0xBu);
      do
        v14 = __ldrexd((unsigned __int64 *)v39);
      while ( v14 == __PAIR64__(v9, v8) && __strexd(__PAIR64__((int)(a2 - v43) >> 2, v6), (unsigned __int64 *)v39) );
      v9 = HIDWORD(v14);
      v8 = v14;
      i = v14;
      if ( v14 == __PAIR64__(v11, HIDWORD(v42)) )
      {
        v15 = (unsigned int *)(v38 + 64);
        do
          v16 = __ldrex(v15);
        while ( __strex(v16 + a3, v15) );
        return 1;
      }
    }
    if ( !v8 )
    {
      v9 = *(_DWORD *)(v39 + 4);
      v8 = *(_DWORD *)v39;
      goto LABEL_8;
    }
    __dmb(0xFu);
    v20 = KiTbFlushTimeStamp;
    __dmb(0xBu);
    v21 = (v20 - v8) & 0xFFFFF;
    if ( v21 <= 2 && ((v8 & 1) != 0 || v21 < 2) )
      break;
    v45 = KfRaiseIrql(2);
    __dmb(0xBu);
    do
      v22 = __ldrexd((unsigned __int64 *)v39);
    while ( v22 == __PAIR64__(v9, i) && __strexd(0i64, (unsigned __int64 *)v39) );
    v9 = HIDWORD(v22);
    i = v22;
    if ( __PAIR64__(v22, HIDWORD(v22)) == v42 )
    {
      v23 = MiReplenishBitMap(a1, v42, 0);
      v24 = a1 + 12;
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 + v23, v24) );
      v26 = -v23;
      v27 = (unsigned int *)(v38 + 64);
      do
        v28 = __ldrex(v27);
      while ( __strex(v28 + v26, v27) );
      i = 0;
      v9 = 0;
    }
    KfLowerIrql(v45);
  }
  if ( a2 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a2 = v44;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a2 = v44;
    if ( a2 + 1070596096 <= 0xFFF )
    {
      v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * (a2 & 0xFFF)), v44);
    }
  }
  v31 = MiReplenishBitMap(a1, (int)(a2 - v43) >> 2, 0);
  v32 = a1 + 12;
  do
    v33 = __ldrex(v32);
  while ( __strex(v33 + v31, v32) );
  v34 = -v31;
  v35 = (unsigned int *)(v38 + 64);
  do
    v36 = __ldrex(v35);
  while ( __strex(v36 + v34, v35) );
  return 1;
}
