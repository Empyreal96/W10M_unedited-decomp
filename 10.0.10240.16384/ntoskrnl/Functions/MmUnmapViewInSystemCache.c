// MmUnmapViewInSystemCache 
 
int __fastcall MmUnmapViewInSystemCache(unsigned int a1, int a2, char a3)
{
  unsigned int v3; // r7
  unsigned int v4; // r5
  unsigned int v5; // r6
  int v6; // r0
  int v7; // r9
  int result; // r0
  int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r4
  unsigned int *v13; // r10
  unsigned int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // t1
  int v17; // r4
  int v18; // r8
  int v19; // r6
  int v20; // lr
  int v21; // r7
  int v22; // r10
  _DWORD *v23; // r5
  int v24; // r4
  unsigned int v25; // r7
  int v26; // r6
  unsigned int v27; // r2
  unsigned int v28; // r6
  int v29; // r4
  unsigned __int8 *v30; // r3
  unsigned int v31; // r0
  int v32; // r2
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1
  unsigned __int8 *v35; // r1
  unsigned int v36; // r2
  unsigned int *v37; // r1
  unsigned int v38; // r2
  _DWORD *v39; // r5
  unsigned int *v40; // r4
  unsigned __int8 *v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r2
  int v45; // r4
  int *v46; // r2
  _DWORD *v47; // r1
  int v48; // r4
  int *v49; // r1
  int v50; // r2
  unsigned int *v51; // r2
  unsigned int v52; // r4
  unsigned int v53; // r2
  unsigned __int8 *v54; // r1
  int v55; // r3
  unsigned int v56; // r2
  unsigned int v57; // r0
  int v58; // r0
  int v59; // r3
  unsigned int v60; // r2
  int v61; // r0
  int v62; // r0
  int v63; // r0
  int v64; // [sp+8h] [bp-168h]
  unsigned int v65; // [sp+10h] [bp-160h]
  int v66; // [sp+14h] [bp-15Ch]
  int v67; // [sp+14h] [bp-15Ch]
  unsigned int v68; // [sp+1Ch] [bp-154h]
  int v69; // [sp+20h] [bp-150h]
  int v70; // [sp+24h] [bp-14Ch]
  unsigned int v71; // [sp+28h] [bp-148h]
  _DWORD *v72; // [sp+2Ch] [bp-144h]
  BOOL v73; // [sp+30h] [bp-140h]
  int v74; // [sp+38h] [bp-138h]
  int v75; // [sp+3Ch] [bp-134h]
  unsigned int v77; // [sp+44h] [bp-12Ch]
  _DWORD *v78; // [sp+48h] [bp-128h]
  int v79; // [sp+4Ch] [bp-124h]
  _DWORD v80[72]; // [sp+50h] [bp-120h] BYREF

  v3 = a1;
  v65 = a1;
  v73 = (a3 & 1) != 0;
  v4 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = ((a1 >> 10) & 0x3FFFFC) - 1073741568;
  v77 = v5;
  v78 = (_DWORD *)v4;
  v74 = MmPfnDatabase + 24 * (*(_DWORD *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v6 = MiSectionControlArea(a2);
  v68 = *(_DWORD *)(v6 + 32) & 0xFFFFFFF8;
  v75 = v6;
  v7 = 0;
  v70 = 0;
  v71 = 0;
  v66 = 2;
  if ( dword_634484 )
    return sub_538C3C();
  v9 = MiState[((int)(((v3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032]
     + 24 * ((v3 >> 18) & 0xF);
  v10 = *(_DWORD *)(v9 + 12);
  v79 = v9;
  v72 = (_DWORD *)v10;
  if ( v10 )
  {
    if ( (v10 & 1) != 0 )
    {
      v10 &= 0xFFFFFFFE;
      v66 = 4;
      v72 = (_DWORD *)v10;
      *(_DWORD *)(v9 + 12) = v10;
    }
    if ( *(_DWORD *)v10 != v6 )
      KeBugCheckEx(26, 1922, v9);
  }
  v69 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E00);
  }
  else
  {
    do
      v11 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
    while ( __strex(v11 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
    while ( 1 )
    {
      v12 = dword_634E00;
      if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_634E00 & 0x40000000) == 0 )
      {
        do
          v57 = __ldrex((unsigned int *)&dword_634E00);
        while ( v57 == v12 && __strex(v12 | 0x40000000, (unsigned int *)&dword_634E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v3 = v65;
  }
  v13 = v80;
  v14 = v4 + 1070596096;
  do
  {
    v16 = *(_DWORD *)v4;
    v4 += 4;
    v15 = v16;
    *v13++ = v16;
    if ( (v16 & 2) != 0 )
    {
      v25 = *(_DWORD *)(MmPfnDatabase + 24 * (v15 >> 12));
      v26 = MmPfnDatabase + 24 * (v15 >> 12);
      if ( v73 && (*(_DWORD *)(v26 + 12) & 0x3FFFFFFF) == 1 )
      {
        v53 = *(unsigned __int8 *)(v26 + 19);
        if ( ((v53 >> 3) & 1) == 1 || (v53 & 7) > 2 && (v53 & 7) <= 5 )
          MiLockSetPfnPriority(v26, 2);
      }
      v27 = v25;
      v3 = v65;
      MiTerminateWsle(v65, &dword_634E00, v27);
      if ( v68 )
        v71 = *(_DWORD *)(v26 + 4) | 0x80000000;
      v5 = v77;
      ++v70;
    }
    else
    {
      if ( (v15 & 0x400) == 0 )
        break;
      if ( v68 )
        v71 = (v15 & 0x1FC | (v15 >> 2) & 0x3FFFFE00) - 0x40000000;
    }
    if ( v14 + 3145728 > 0x3FFFFF )
    {
      *(_DWORD *)(v4 - 4) = 0;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v4 - 4) = 0;
      if ( v14 <= 0xFFF )
      {
        v58 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v58, v58 + 4 * (((_WORD)v4 - 4) & 0xFFF), 0);
      }
    }
    v3 += 4096;
    v14 += 4;
    v65 = v3;
    ++v7;
  }
  while ( v4 < v5 );
  if ( *(_DWORD *)(v79 + 8) )
  {
    *(_DWORD *)(v79 + 8) = 0;
    v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  MiUnlockWorkingSetExclusive(&dword_634E00, v69);
  v18 = 0;
  if ( v17 == 1 )
    MiManageSubsectionView(v72, v79, v66);
  __dmb(0xFu);
  v19 = KiTbFlushTimeStamp;
  v67 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v20 = 17;
  v21 = 0;
  v22 = 0;
  v64 = 17;
  if ( v7 <= 0 )
  {
LABEL_98:
    KfRaiseIrql(2);
    goto LABEL_60;
  }
  v23 = v80;
  while ( 1 )
  {
    if ( (*v23 & 2) == 0 )
      goto LABEL_29;
    v28 = 0;
    ++v22;
    v29 = MmPfnDatabase + 24 * (*v23 >> 12);
    if ( v21 )
    {
      v30 = (unsigned __int8 *)(v29 + 15);
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 | 0x80, v30) );
      __dmb(0xBu);
      if ( v31 >> 7 )
      {
        MiDecrementAndInsertStandbyPages(v80, v21, v20);
        v21 = 0;
        --v23;
        --v18;
        --v22;
        goto LABEL_29;
      }
    }
    else
    {
      v64 = KfRaiseIrql(2);
      v33 = (unsigned __int8 *)(v29 + 15);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 | 0x80, v33) );
      __dmb(0xBu);
      if ( v34 >> 7 )
      {
        v54 = (unsigned __int8 *)(v29 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v55 = *(_DWORD *)(v29 + 12);
            __dmb(0xBu);
          }
          while ( (v55 & 0x80000000) != 0 );
          do
            v56 = __ldrex(v54);
          while ( __strex(v56 | 0x80, v54) );
          __dmb(0xBu);
        }
        while ( v56 >> 7 );
      }
    }
    if ( (*v23 & 0x200) != 0 )
    {
      v32 = *(_DWORD *)(v29 + 12);
      if ( (v32 & 0x3FFFFFFF) == 1
        && *(_WORD *)(v29 + 16) == 1
        && (v32 & 0x40000000) == 0
        && (*(_BYTE *)(v29 + 19) & 0x40) == 0
        && (*(_BYTE *)(v29 + 18) & 0x10) == 0 )
      {
        v80[v21++] = v29;
LABEL_29:
        v24 = v64;
        goto LABEL_30;
      }
    }
    else
    {
      v28 = MiCaptureDirtyBitToPfn(v29);
    }
    if ( v21 )
    {
      MiDecrementAndInsertStandbyPages(v80, v21, 17);
      v21 = 0;
    }
    if ( (*(_BYTE *)(v29 + 18) & 7) != 6 )
      KeBugCheckEx(78, 153, (v29 - MmPfnDatabase) / 24);
    v50 = *(_DWORD *)(v29 + 12);
    *(_DWORD *)(v29 + 12) = v50 & 0xC0000000 | ((v50 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
    if ( (v50 & 0x3FFFFFFF) == 1 )
      MiPfnShareCountIsZero(v29, 0);
    __dmb(0xBu);
    v51 = (unsigned int *)(v29 + 12);
    do
      v52 = __ldrex(v51);
    while ( __strex(v52 & 0x7FFFFFFF, v51) );
    v24 = v64;
    KfLowerIrql(v64);
    if ( v28 )
      MiReleasePageFileInfo(MiSystemPartition, v28, 0);
LABEL_30:
    ++v18;
    ++v23;
    if ( v18 >= v7 )
      break;
    v20 = v64;
  }
  if ( v21 )
    MiDecrementAndInsertStandbyPages(v80, v21, v24);
  if ( !v22 )
  {
    v19 = v67;
    goto LABEL_98;
  }
  KfRaiseIrql(2);
  v35 = (unsigned __int8 *)(v74 + 15);
  do
    v36 = __ldrex(v35);
  while ( __strex(v36 | 0x80, v35) );
  __dmb(0xBu);
  if ( v36 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v59 = *(_DWORD *)(v74 + 12);
        __dmb(0xBu);
      }
      while ( (v59 & 0x80000000) != 0 );
      do
        v60 = __ldrex(v35);
      while ( __strex(v60 | 0x80, v35) );
      __dmb(0xBu);
    }
    while ( v60 >> 7 );
  }
  *(_DWORD *)(v74 + 12) = *(_DWORD *)(v74 + 12) & 0xC0000000 | (*(_DWORD *)(v74 + 12) - v22) & 0x3FFFFFFF;
  __dmb(0xBu);
  v37 = (unsigned int *)(v74 + 12);
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 & 0x7FFFFFFF, v37) );
  v19 = v67;
LABEL_60:
  if ( v68 )
    v39 = v72;
  else
    v39 = 0;
  v40 = (unsigned int *)(v75 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v75 + 36);
  }
  else
  {
    v41 = (unsigned __int8 *)(v75 + 39);
    do
      v42 = __ldrex(v41);
    while ( __strex(v42 | 0x80, v41) );
    __dmb(0xBu);
    if ( v42 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v40);
    while ( 1 )
    {
      v43 = *v40;
      if ( (*v40 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v43 & 0x40000000) == 0 )
      {
        do
          v42 = __ldrex(v40);
        while ( v42 == v43 && __strex(v43 | 0x40000000, v40) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v39 )
  {
    while ( 1 )
    {
      MiRemoveViewsFromSection(v39, v42, v39[7], 0);
      v44 = v39[1];
      if ( v71 >= v44 && v71 < v44 + 4 * v39[7] )
        break;
      v39 = (_DWORD *)v39[2];
      if ( !v39 )
        KeBugCheckEx(26, 1923, v80);
    }
  }
  if ( (a3 & 4) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v40);
    }
    else
    {
      __dmb(0xBu);
      *v40 = 0;
    }
    KfLowerIrql(v69);
  }
  else
  {
    --*(_DWORD *)(v75 + 20);
    --*(_DWORD *)(v75 + 48);
    MiCheckControlArea(v75, v69);
  }
  v45 = v19 << 12;
  result = 0x3FFFFF;
  v46 = v78 + 2;
  if ( (unsigned int)(v78 + 268435458) > 0x3FFFFF )
  {
    *v46 = v45;
  }
  else
  {
    __dmb(0xBu);
    *v46 = v45;
    if ( (unsigned int)(v78 + 267649026) <= 0xFFF )
    {
      v61 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v61, v61 + 4 * ((unsigned __int16)v46 & 0xFFF), v45);
      result = 0x3FFFFF;
    }
  }
  v47 = v78 + 1;
  if ( (unsigned int)(v78 + 268435457) > 0x3FFFFF )
  {
    *v47 = 0;
  }
  else
  {
    __dmb(0xBu);
    *v47 = 0;
    if ( (unsigned int)(v78 + 267649025) <= 0xFFF )
    {
      v62 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v62, v62 + 4 * ((unsigned __int16)v47 & 0xFFF), 0);
      result = 0x3FFFFF;
    }
  }
  if ( v70 )
    v48 = 0x2000;
  else
    v48 = 0;
  v49 = v78 + 3;
  if ( (unsigned int)(v78 + 268435459) > 0x3FFFFF )
  {
    *v49 = v48;
  }
  else
  {
    __dmb(0xBu);
    *v49 = v48;
    if ( (unsigned int)(v78 + 267649027) <= 0xFFF )
    {
      v63 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v63, v63 + 4 * ((unsigned __int16)v49 & 0xFFF), v48);
    }
  }
  if ( (a3 & 2) == 0 )
    result = MiReleaseSystemCacheView(v78);
  return result;
}
