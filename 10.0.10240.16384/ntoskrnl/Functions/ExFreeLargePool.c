// ExFreeLargePool 
 
int __fastcall ExFreeLargePool(unsigned int a1, int *a2, unsigned int *a3, int a4)
{
  int v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  int v8; // r0
  unsigned int *v9; // lr
  unsigned int v10; // r1
  int v11; // r2
  unsigned int *v12; // r4
  unsigned int v13; // r7
  int v14; // r9
  unsigned int v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r2
  int v20; // r5
  int v21; // r4
  int v22; // lr
  int v23; // r8
  int v24; // r2
  int v25; // r3
  unsigned int *v26; // r5
  unsigned int *v27; // r1
  unsigned int v28; // r0
  unsigned int *v29; // r1
  unsigned int v30; // r5
  unsigned __int16 *v31; // r5
  int v32; // r0
  char v33; // r2
  unsigned int v34; // r9
  unsigned int *v35; // r8
  unsigned int *v36; // r2
  unsigned int v37; // r4
  unsigned int *v38; // r2
  unsigned int v39; // r1
  unsigned int *v40; // r2
  unsigned int v41; // r4
  int result; // r0
  unsigned int *v43; // r2
  unsigned int v44; // r1
  unsigned int *v45; // r2
  unsigned int v46; // r4
  unsigned int v47; // r8
  unsigned int v48; // r9
  int v49; // r1
  unsigned int *v50; // r2
  unsigned int v51; // r4
  int v52; // lr
  int *v53; // r3
  int v54; // r4
  int v55; // r2
  int v56; // r10
  int v57; // r3
  unsigned int *v58; // r0
  unsigned int *v59; // r2
  unsigned int v60; // r1
  unsigned int *v61; // r0
  unsigned int v62; // r1
  int v63; // r10
  unsigned __int16 *v64; // r5
  unsigned int v65; // r4
  int v66; // r8
  int v67; // r10
  unsigned int v68; // r2
  int v69; // r2
  unsigned __int16 *v70; // lr
  __int64 v71; // r0
  unsigned int *v72; // r2
  unsigned int v73; // r1
  int v74; // r5
  unsigned int v75; // r1
  unsigned int *v76; // r2
  unsigned int v77; // r1
  unsigned int *v78; // r0
  unsigned int v79; // r1
  unsigned int v80; // lr
  unsigned int v81; // r0
  unsigned int v82; // r2
  __int64 v83; // r0
  unsigned int v84; // r3
  int v85; // lr
  int v86; // r0
  int v87; // r1
  bool v88; // zf
  unsigned int v89; // r1
  unsigned __int8 *i; // r2
  int v91; // t1
  unsigned int v92; // r3
  int v93; // [sp+8h] [bp-50h]
  unsigned int *v94; // [sp+Ch] [bp-4Ch]
  int v95; // [sp+10h] [bp-48h]
  __int16 v96; // [sp+14h] [bp-44h]
  int v97; // [sp+18h] [bp-40h]
  int v98; // [sp+18h] [bp-40h]
  int v100; // [sp+20h] [bp-38h]
  unsigned int v101; // [sp+24h] [bp-34h]
  int v103; // [sp+2Ch] [bp-2Ch]
  char var28[44]; // [sp+30h] [bp-28h] BYREF

  v93 = a4;
  v94 = (unsigned int *)PoolVector[a4 & 1];
  v95 = a4 & 1;
  if ( a4 == 33 )
  {
    v94 = (unsigned int *)MiSessionPoolVector();
  }
  else if ( (a4 & 1) == 0 && !MmIsNonPagedPoolNx(a1) )
  {
    return sub_54B950();
  }
  v97 = 1;
  v103 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&ExpLargePoolTableLock);
  }
  else
  {
    v5 = ExpLargePoolTableLock & 0x7FFFFFFF;
    v6 = (ExpLargePoolTableLock & 0x7FFFFFFF) + 1;
    do
      v7 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
    while ( v7 == v5 && __strex(v6, (unsigned int *)&ExpLargePoolTableLock) );
    __dmb(0xBu);
    if ( v7 != v5 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ExpLargePoolTableLock);
  }
  if ( (v93 & 0x20) != 0 )
  {
    v8 = *(_DWORD *)(MmSessionSpace + 8380);
    v10 = *(_DWORD *)(MmSessionSpace + 8384);
    v9 = (unsigned int *)(MmSessionSpace + 8304);
  }
  else
  {
    v8 = PoolBigPageTable;
    v9 = (unsigned int *)&ExpPoolBigEntriesInUse;
    v10 = PoolBigPageTableSize;
  }
  v11 = (v10 - 1) & ((int)(162172
                         * ((a1 >> 12 >> 16) ^ (4 * ((unsigned __int8)(a1 >> 20) ^ (4 * (unsigned __int8)(a1 >> 12)))))) >> 2);
  while ( *(_DWORD *)(16 * v11 + v8) != a1 )
  {
    if ( ++v11 >= v10 )
    {
      if ( v97 )
      {
        v11 = 0;
        v97 = 0;
      }
      else
      {
        if ( (v93 & 0x21) != 0
          || v8 != PoolBigPageTable
          || MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) == -1
          || (v8 = *(_DWORD *)(MmSessionSpace + 8380),
              v10 = *(_DWORD *)(MmSessionSpace + 8384),
              v9 = (unsigned int *)(MmSessionSpace + 8304),
              !v8)
          || !v10 )
        {
          KeBugCheckEx(25, 34, a1);
        }
        v11 = (v10 - 1) & ((int)(162172
                               * ((a1 >> 12 >> 16) ^ (4
                                                    * ((unsigned __int8)(a1 >> 20) ^ (4 * (unsigned __int8)(a1 >> 12)))))) >> 2);
        v97 = 1;
      }
    }
  }
  v12 = (unsigned int *)(v8 + 16 * v11);
  v13 = v12[3];
  *a2 = v12[1];
  v14 = (v12[2] >> 8) & 0xFFF;
  if ( a3 )
    *a3 = v13;
  if ( v8 != PoolBigPageTable || v12[1] == 1819242320 )
  {
    v100 = 0;
    v101 = 0;
  }
  else
  {
    v15 = v12[2];
    v100 = (unsigned __int8)v15;
    v101 = v15 >> 20;
  }
  do
    v16 = __ldrex(v9);
  while ( __strex(v16 - 1, v9) );
  do
    v17 = __ldrex(v12);
  while ( __strex(v17 + 1, v12) );
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ExpLargePoolTableLock);
  }
  else
  {
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
    while ( __strex(v18 & 0xBFFFFFFF, (unsigned int *)&ExpLargePoolTableLock) );
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
    while ( __strex(v19 - 1, (unsigned int *)&ExpLargePoolTableLock) );
  }
  KfLowerIrql(v103);
  if ( (v14 & 0x21) == 32 )
  {
    v20 = v14;
    v93 = v14;
  }
  else
  {
    v20 = v93;
  }
  v21 = *a2 & 0x7FFFFFFF;
  *a2 = v21;
  if ( v21 == PoolHitTag )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3618, v20, v21, a1, v13);
  v98 = v20 & 0x20;
  if ( (v20 & 0x20) != 0 )
  {
    v23 = ExpSessionPoolTrackTable;
    v22 = ExpSessionPoolTrackTableMask;
  }
  else
  {
    v22 = PoolTrackTableMask;
    v23 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
  }
  v24 = v22 & ((40543 * (HIBYTE(v21) ^ (4 * (BYTE2(v21) ^ (4 * (BYTE1(v21) ^ (4 * (unsigned __int8)v21))))))) >> 2);
  while ( 1 )
  {
    v25 = *(_DWORD *)(28 * v24 + v23);
    v26 = (unsigned int *)(28 * v24 + v23);
    if ( v25 == v21 )
      break;
    if ( v25 || v98 || (v84 = *(_DWORD *)(28 * v24 + PoolTrackTable)) == 0 )
    {
      v24 = (v24 + 1) & v22;
      if ( v24 == (v22 & ((40543 * (HIBYTE(v21) ^ (4 * (BYTE2(v21) ^ (4 * (BYTE1(v21) ^ (4 * (unsigned __int8)v21))))))) >> 2)) )
      {
        ExpRemovePoolTrackerExpansion(v21, v13, v93, 28);
        v85 = v93;
        goto LABEL_45;
      }
    }
    else
    {
      *v26 = v84;
    }
  }
  v85 = v93;
  if ( (v93 & 1) != 0 )
  {
    v27 = v26 + 5;
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 + 1, v27) );
    v29 = v26 + 6;
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 - v13, v29) );
  }
  else
  {
    v43 = v26 + 2;
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 + 1, v43) );
    v45 = v26 + 3;
    do
      v46 = __ldrex(v45);
    while ( __strex(v46 - v13, v45) );
  }
LABEL_45:
  if ( (v14 & 0x40) != 0 )
  {
    VerifierFreeTrackedPool(a1, v13, v14, 0);
    v85 = v93;
  }
  v31 = 0;
  v96 = 0;
  if ( (v13 & 0xFFF) != 0 )
  {
    v31 = (unsigned __int16 *)(v13 + a1);
    if ( *(_DWORD *)(v13 + a1 + 8) != v13 )
      KeBugCheckEx(25, 33, a1);
    v32 = v95;
    v47 = 1;
    v48 = *v31 >> 9;
    v96 = v48;
    if ( v95 )
    {
      if ( v98 )
        goto LABEL_75;
      v47 = ExpNumberOfPagedPools + 1;
      v49 = ExpPagedPoolDescriptor[v48];
    }
    else
    {
      if ( (unsigned int)ExpNumberOfNonPagedPools <= 1
        || (v47 = ExpNumberOfNonPagedPools,
            v94 = (unsigned int *)ExpNonPagedPoolDescriptor[v48],
            v86 = MmIsNonPagedPoolNx(v13 + a1),
            v85 = v93,
            v88 = v86 == 0,
            v32 = 0,
            !v88) )
      {
LABEL_75:
        if ( v48 >= v47 )
          KeBugCheckEx(25, 36, v48);
        goto LABEL_50;
      }
      v49 = v87 + 4736;
    }
    v94 = (unsigned int *)v49;
    goto LABEL_75;
  }
  if ( v100 )
  {
    v89 = 0;
    for ( i = (unsigned __int8 *)(v13 - v101 + a1); v89 < v101; ++v89 )
    {
      v91 = *i++;
      if ( v91 != v100 )
        KeBugCheckEx(194, 98, a1);
    }
    v85 = v93;
  }
  v32 = v95;
LABEL_50:
  v33 = ExpPoolFlags;
  if ( (ExpPoolFlags & 0x417) != 0 )
  {
    if ( (ExpPoolFlags & 0x400) != 0 && !v32 )
    {
      ExpCheckForLookaside(a1, v13);
      v85 = v93;
      v33 = ExpPoolFlags;
    }
    if ( (v33 & 1) != 0 )
    {
      KeCheckForTimer(a1, v13);
      v85 = v93;
      v33 = ExpPoolFlags;
    }
    if ( (v33 & 4) != 0 )
    {
      ExpCheckForResource(a1, v13);
      v85 = v93;
      v33 = ExpPoolFlags;
    }
    if ( (v33 & 2) != 0 )
    {
      ExpCheckForWorker(a1, v13);
      v85 = v93;
      v33 = ExpPoolFlags;
    }
    if ( (v33 & 0x10) != 0 )
    {
      VfFreePoolNotification(a1, v13);
      v85 = v93;
    }
  }
  v34 = v13;
  if ( (v13 & 0xFFF) != 0 )
  {
    v50 = v94 + 36;
    do
      v51 = __ldrex(v50);
    while ( __strex(v51 - 16, v50) );
    if ( PoolHitTag == 1734439494 )
      __debugbreak();
    if ( (dword_682604 & 0x41) != 0 )
      EtwTracePool(3618, v85, 1734439494, v31, 16);
    if ( v98 )
    {
      v52 = ExpSessionPoolTrackTable;
      v53 = &ExpSessionPoolTrackTableMask;
    }
    else
    {
      v52 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
      v53 = &PoolTrackTableMask;
    }
    v54 = *v53;
    v55 = *v53 & 0x398FEF7;
    v56 = v55;
    while ( 1 )
    {
      v57 = *(_DWORD *)(28 * v55 + v52);
      v58 = (unsigned int *)(28 * v55 + v52);
      if ( v57 == 1734439494 )
        break;
      if ( v57 || v98 || (v92 = *(_DWORD *)(28 * v55 + PoolTrackTable)) == 0 )
      {
        v55 = (v55 + 1) & v54;
        if ( v55 == v56 )
        {
          ExpRemovePoolTrackerExpansion(1734439494, 16, v93, 28);
          goto LABEL_91;
        }
      }
      else
      {
        *v58 = v92;
      }
    }
    if ( (v93 & 1) != 0 )
    {
      v59 = v58 + 5;
      do
        v60 = __ldrex(v59);
      while ( __strex(v60 + 1, v59) );
      v61 = v58 + 6;
      do
        v62 = __ldrex(v61);
      while ( __strex(v62 - 16, v61) );
    }
    else
    {
      v76 = v58 + 2;
      do
        v77 = __ldrex(v76);
      while ( __strex(v77 + 1, v76) );
      v78 = v58 + 3;
      do
        v79 = __ldrex(v78);
      while ( __strex(v79 - 16, v78) );
    }
LABEL_91:
    v63 = v95;
    v64 = v31 + 8;
    if ( v95 )
    {
      v65 = (unsigned int)(v94 + 1);
      v66 = KeAbPreAcquire((unsigned int)(v94 + 1), 0, 0);
      v67 = KfRaiseIrql(1);
      do
        v68 = __ldrex((unsigned __int8 *)v65);
      while ( __strex(v68 & 0xFE, (unsigned __int8 *)v65) );
      __dmb(0xBu);
      if ( (v68 & 1) == 0 )
        ExpAcquireFastMutexContended(v65, v66);
      if ( v66 )
        *(_BYTE *)(v66 + 14) |= 1u;
      v94[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v94[8] = v67;
      PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
      v35 = v94;
      v63 = v95;
    }
    else
    {
      v35 = v94;
      v65 = (unsigned int)(v94 + 1);
      KeAcquireInStackQueuedSpinLock(v94 + 1, (unsigned int)var28);
    }
    v69 = v64[1] & 0x1FF;
    v70 = &v64[4 * v69];
    if ( (v64[1] & 0xFE00) != 0 )
    {
      v70 = v64;
    }
    else
    {
      if ( v69 != 1 )
      {
        v71 = *((_QWORD *)v64 + 1);
        if ( *(unsigned __int16 **)(v71 + 4) != v64 + 4 || *(unsigned __int16 **)HIDWORD(v71) != v64 + 4 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v71) = v71;
        *(_DWORD *)(v71 + 4) = HIDWORD(v71);
      }
      v64 += 4 * v69;
    }
    if ( ((unsigned __int16)v70 & 0xFFF) != 0 )
    {
      v80 = (unsigned int)v70 & 0xFFFFF000;
      v81 = (((unsigned int)v64 - v80) >> 3) & 0x1FF;
      *(_WORD *)(v80 + 2) = v81;
      *(_WORD *)v80 = v96 << 9;
      *(_DWORD *)(v80 + 4) = 1701147206;
      *v64 ^= (v81 ^ *v64) & 0x1FF;
      v82 = v80 + 8;
      LODWORD(v83) = &v35[2 * (*(_WORD *)(v80 + 2) & 0x1FF) + 158];
      HIDWORD(v83) = *(_DWORD *)(v83 + 4);
      *(_QWORD *)(v80 + 8) = v83;
      if ( *(_DWORD *)HIDWORD(v83) != (_DWORD)v83 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v83) = v82;
      *(_DWORD *)(v83 + 4) = v82;
      v13 &= 0xFFFFF000;
    }
    else
    {
      v72 = v35 + 96;
      do
        v73 = __ldrex(v72);
      while ( __strex(v73 - 1, v72) );
    }
    if ( v63 )
    {
      PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
      v74 = *(_DWORD *)(v65 + 28);
      *(_DWORD *)(v65 + 4) = 0;
      __dmb(0xBu);
      do
        v75 = __ldrex((unsigned int *)v65);
      while ( !v75 && __strex(1u, (unsigned int *)v65) );
      if ( v75 )
        ExpReleaseFastMutexContended((unsigned int *)v65, v75);
      KfLowerIrql((unsigned __int8)v74);
      KeAbPostRelease(v65);
    }
    else
    {
      KeReleaseInStackQueuedSpinLock((int)var28);
    }
  }
  else
  {
    v35 = v94;
  }
  if ( v13 )
  {
    if ( !a3 )
      MiFreePoolPages(a1, v13, *a2);
    v36 = v35 + 34;
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 - (v13 >> 12), v36) );
  }
  v38 = v35 + 33;
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 + 1, v38) );
  v40 = v35 + 36;
  do
  {
    v41 = __ldrex(v40);
    result = v41 - v34;
  }
  while ( __strex(v41 - v34, v40) );
  return result;
}
