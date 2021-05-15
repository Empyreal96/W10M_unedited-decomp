// MmFreeSpecialPool 
 
// local variable allocation has failed, the output may be wrong!
__int16 *__fastcall MmFreeSpecialPool(unsigned int a1)
{
  int v1; // r10
  unsigned int v2; // r8
  unsigned int v4; // r4
  int v5; // r6
  unsigned int v6; // r0
  int v7; // r1
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r9
  _DWORD *v11; // r0
  unsigned __int8 *v12; // r1
  unsigned int v13; // r2
  unsigned int i; // lr
  int v15; // t1
  int v16; // r10
  int *v17; // r1
  unsigned int v18; // r2 OVERLAPPED
  int v19; // r5
  int v20; // r6
  unsigned int v21; // r1
  int v22; // r0
  int v23; // r3
  int v24; // r1
  unsigned __int8 *v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned __int8 *v32; // r1
  unsigned int v33; // r2
  int v34; // r3
  unsigned int v35; // r2
  int v36; // r3
  unsigned int *v37; // r2
  unsigned int v38; // r0
  int v39; // r6
  int v40; // r5
  int *v41; // r4
  int v42; // r1
  unsigned int v43; // r4
  int v44; // r5
  int v45; // r0
  unsigned int v46; // r4
  unsigned int v47; // r4
  unsigned int v48; // r4
  unsigned int *v49; // r4
  __int16 *result; // r0
  unsigned int *v51; // r2
  unsigned int v52; // r0
  unsigned int v53; // r4
  int v54[2]; // [sp+8h] [bp-E0h] BYREF
  int v55; // [sp+10h] [bp-D8h]
  unsigned int *v56; // [sp+14h] [bp-D4h]
  int v57; // [sp+18h] [bp-D0h] BYREF
  int v58; // [sp+20h] [bp-C8h] BYREF
  int v59; // [sp+24h] [bp-C4h]
  int v60; // [sp+28h] [bp-C0h]
  int v61; // [sp+2Ch] [bp-BCh]
  int v62; // [sp+30h] [bp-B8h] BYREF
  char v63; // [sp+34h] [bp-B4h]
  char v64; // [sp+35h] [bp-B3h]
  int v65; // [sp+38h] [bp-B0h]
  int v66; // [sp+3Ch] [bp-ACh]
  int v67; // [sp+40h] [bp-A8h]
  int v68; // [sp+44h] [bp-A4h]

  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v1 = a1 & 0xFFF;
  v2 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = a1 & 0xFFFFF000;
  if ( (a1 & 0xFFF) != 0 )
  {
    v57 = 1;
    v5 = a1 & 0xFFFFF000;
  }
  else
  {
    v57 = 0;
    v5 = v4 + 4088;
  }
  v6 = KeGetCurrentIrql(a1);
  v7 = *(_DWORD *)v5;
  if ( (*(_DWORD *)v5 & 0x8000) != 0 )
  {
    v8 = 1;
    v9 = 1;
  }
  else
  {
    v8 = 0;
    v9 = 2;
  }
  v55 = v8;
  if ( v6 > v9 )
    KeBugCheckEx(193, v6, 1, a1, 49);
  v56 = (unsigned int *)&unk_634D00;
  if ( (v7 & 0x2000) != 0 )
  {
    v55 = v8 | 0x20;
    v56 = (unsigned int *)dword_63501C;
  }
  v10 = v7 & 0x1FFF;
  if ( v57 == 1 )
  {
    if ( ((v10 + 7) & 0xFFFFFFF8) != 4096 - v1 )
      KeBugCheckEx(193, a1, v7 & 0x1FFF, 4096 - v1, 33);
    v11 = (_DWORD *)(v5 + 8);
    if ( (v7 & 0x4000) != 0 )
      v11 = (_DWORD *)(v5 + 12);
    MiCheckSpecialPoolSlop(v11, a1, v5);
  }
  v12 = (unsigned __int8 *)(a1 + v10);
  v13 = (a1 & 0xFFFFF000) - (a1 + v10) + 4096;
  if ( !v57 )
  {
    v13 = (a1 & 0xFFFFF000) - (a1 + v10) + 4088;
    if ( (*(_DWORD *)v5 & 0x4000) != 0 )
      v13 = (a1 & 0xFFFFF000) - (a1 + v10) + 4084;
  }
  for ( i = 0; i < v13; ++i )
  {
    v15 = *v12++;
    if ( v15 != (*(_WORD *)(v5 + 2) & 0x1FF) )
      KeBugCheckEx(193, a1, (int)(v12 - 1), *(_DWORD *)v5, 36);
  }
  v16 = v55;
  if ( (*(_DWORD *)v5 & 0x6000) == 0x4000 )
    VerifierFreeTrackedPool(a1, v10, v55, 1);
  *(_DWORD *)(v4 + 12) = -1737080031;
  KeQueryTickCount(&v57);
  *(_DWORD *)(v4 + 16) = v57;
  *(_DWORD *)(v4 + 20) = v10;
  *(_DWORD *)(v4 + 24) = v16;
  *(_DWORD *)(v4 + 28) = a1;
  *(_DWORD *)(v4 + 40) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = v54;
  v18 = 4096 - ((unsigned int)v54 & 0xFFF);
  *(_QWORD *)(v4 + 32) = *(_QWORD *)(&v18 - 1);
  if ( ((unsigned int)v54 & 0xFFF) != 4096 )
  {
    if ( v18 > 0x400 )
      v18 = 1024;
    memmove(v4 + 44, (int)v54, v18);
  }
  if ( (v16 & 1) != 0 )
  {
    if ( (v16 & 0x20) != 0 )
      v41 = (int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
    else
      v41 = &dword_634E80;
    MiDeleteSystemPagableVm(v41, 0, v2, 1, 1, &v58);
    if ( v59 )
      v39 = v61 - v59;
    else
      v39 = v61;
    if ( (v16 & 0x20) == 0 )
      MiChargeWsles((int)v41, -1, 0);
    v42 = *(_DWORD *)v2;
    v43 = *(_DWORD *)v2 | 0xFFFFF000;
    if ( v2 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v2 = v43;
    }
    else
    {
      v44 = 0;
      __dmb(0xBu);
      *(_DWORD *)v2 = v43;
      if ( (v42 & 2) == 0 && (v43 & 2) != 0 )
        v44 = 1;
      if ( v2 + 1070596096 <= 0xFFF )
      {
        v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v45, (_DWORD *)(v45 + 4 * (v2 & 0xFFF)), v43);
      }
      if ( v44 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v40 = v58;
  }
  else
  {
    v19 = MmPfnDatabase + 24 * (*(_DWORD *)v2 >> 12);
    v20 = MmPfnDatabase + 24 * (*(_DWORD *)(v19 + 20) & 0xFFFFF);
    do
      v21 = __ldrex((unsigned int *)&dword_632D4C);
    while ( __strex(v21 - 1, (unsigned int *)&dword_632D4C) );
    if ( v2 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v2 = -4096;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v2 = -4096;
      if ( v2 + 1070596096 <= 0xFFF )
      {
        v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v22, (_DWORD *)(v22 + 4 * (v2 & 0xFFF)), -4096);
      }
    }
    if ( v56 == (unsigned int *)&unk_634D00 )
      v23 = 0;
    else
      v23 = 2;
    v62 = v23;
    v63 = 0;
    v64 = 0;
    v67 = 0;
    v65 = 33;
    v66 = 0;
    v68 = 0;
    MiInsertTbFlushEntry((int)&v62, v4, 1, 0);
    MiFlushTbList((unsigned int)&v62, v24);
    v57 = KfRaiseIrql(2);
    v25 = (unsigned __int8 *)(v19 + 15);
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
        v27 = *(_DWORD *)(v19 + 12);
        __dmb(0xBu);
      }
      while ( (v27 & 0x80000000) != 0 );
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 | 0x80, v25) );
    }
    v28 = *(_DWORD *)(v19 + 12) | 0x40000000;
    *(_DWORD *)(v19 + 12) = v28;
    if ( (v28 & 0x3FFFFFFF) != 1 )
      KeBugCheckEx(78, 153, (v19 - MmPfnDatabase) / 24, *(_BYTE *)(v19 + 18) & 7, v28 & 0x3FFFFFFF);
    if ( *(_WORD *)(v19 + 16) != 1 )
      KeBugCheckEx(78, 154, (v19 - MmPfnDatabase) / 24, *(_BYTE *)(v19 + 18) & 7, *(unsigned __int16 *)(v19 + 16));
    v29 = *(_BYTE *)(v19 + 18) & 7;
    if ( v29 != 6 )
      KeBugCheckEx(78, 153, (v19 - MmPfnDatabase) / 24, v29, v28 & 0x3FFFFFFF);
    if ( !MiUpdateShareCount(v19, -1) )
      MiPfnShareCountIsZero(v19, 0);
    __dmb(0xBu);
    v30 = (unsigned int *)(v19 + 12);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0x7FFFFFFF, v30) );
    v32 = (unsigned __int8 *)(v20 + 15);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 | 0x80, v32) );
    __dmb(0xBu);
    if ( v33 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v34 = *(_DWORD *)(v20 + 12);
          __dmb(0xBu);
        }
        while ( (v34 & 0x80000000) != 0 );
        do
          v35 = __ldrex(v32);
        while ( __strex(v35 | 0x80, v32) );
        __dmb(0xBu);
      }
      while ( v35 >> 7 );
    }
    v36 = *(_BYTE *)(v20 + 18) & 7;
    if ( v36 != 6 )
      KeBugCheckEx(78, 153, (v20 - MmPfnDatabase) / 24, v36, *(_DWORD *)(v20 + 12) & 0x3FFFFFFF);
    if ( !MiUpdateShareCount(v20, -1) )
      MiPfnShareCountIsZero(v20, 0);
    __dmb(0xBu);
    v37 = (unsigned int *)(v20 + 12);
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 & 0x7FFFFFFF, v37) );
    KfLowerIrql(v57);
    v39 = 1;
    v40 = 1;
  }
  do
  {
    v46 = __ldrex((unsigned int *)&dword_634D9C);
    v47 = v46 - 1;
  }
  while ( __strex(v47, (unsigned int *)&dword_634D9C) );
  if ( !v47 )
  {
    do
      v48 = __ldrex((unsigned int *)&dword_634C84);
    while ( __strex(v48 - 1, (unsigned int *)&dword_634C84) );
  }
  v49 = v56;
  result = MiRemoveSpecialPoolRange(v56, v16, (int *)v2);
  if ( v49 != (unsigned int *)&unk_634D00 )
  {
    v51 = v49 + 7;
    do
    {
      v52 = __ldrex(v51);
      result = (__int16 *)(v52 - 1);
    }
    while ( __strex((unsigned int)result, v51) );
  }
  if ( v40 )
  {
    MiReturnResidentAvailable(v40);
    do
    {
      v53 = __ldrex(&dword_634A2C[66]);
      result = (__int16 *)(v53 + v40);
    }
    while ( __strex(v53 + v40, &dword_634A2C[66]) );
  }
  if ( v39 )
    result = (__int16 *)MiReturnCommit((int)MiSystemPartition, v39);
  return result;
}
