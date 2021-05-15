// ExpAllocateBigPool 
 
int __fastcall ExpAllocateBigPool(int a1, int a2, unsigned int a3, int a4, char a5)
{
  unsigned int v5; // r6
  unsigned int v8; // r5
  int v9; // r1
  int v10; // r9
  int v11; // r10
  unsigned int *v12; // r2
  unsigned int v13; // r4
  unsigned int *v14; // r4
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // lr
  int v19; // r6
  int v20; // r4
  int v21; // r3
  int v22; // r10
  int v23; // r1
  int v24; // r6
  unsigned int *v25; // r4
  unsigned int *v26; // r1
  unsigned int v27; // r0
  unsigned int *v28; // r1
  unsigned int v29; // r4
  unsigned int *v31; // r2
  unsigned int v32; // r1
  unsigned int *v33; // r0
  unsigned int v34; // r1
  int v35; // r8
  unsigned int v36; // r7
  unsigned int v37; // r1
  int v38; // r0
  int v39; // r1
  int v40; // r6
  int v41; // r3
  unsigned int *v42; // r4
  unsigned int *v43; // r2
  unsigned int v44; // r1
  unsigned int *v45; // r0
  unsigned int v46; // r1
  unsigned int v47; // r1
  unsigned int *v48; // r5
  unsigned int v49; // r4
  int v50; // r6
  int v51; // r8
  unsigned int v52; // r2
  unsigned int **v53; // r1
  unsigned int v54; // r2
  int v55; // r5
  unsigned int v56; // r1
  int v57; // r1
  int v58; // r10
  int v59; // r2
  int v60; // r3
  unsigned int *v61; // r2
  unsigned int v62; // r1
  unsigned int *v63; // r2
  unsigned int v64; // r1
  unsigned int *v65; // r0
  unsigned int v66; // r1
  unsigned int v67; // r3
  unsigned int v68; // r3
  unsigned int v69; // r2
  unsigned int v70; // r2
  unsigned int v71; // r2
  int v72; // r10
  unsigned int v73; // [sp+8h] [bp-80h]
  int v74; // [sp+8h] [bp-80h]
  unsigned int *v75; // [sp+Ch] [bp-7Ch]
  int v77; // [sp+10h] [bp-78h]
  int v78; // [sp+14h] [bp-74h]
  int v79; // [sp+14h] [bp-74h]
  int v80; // [sp+18h] [bp-70h]
  int v81; // [sp+18h] [bp-70h]
  int v82; // [sp+1Ch] [bp-6Ch]
  int v83; // [sp+20h] [bp-68h]
  int v84; // [sp+24h] [bp-64h]
  unsigned int *v85; // [sp+30h] [bp-58h]
  int v86; // [sp+30h] [bp-58h]
  char v88[16]; // [sp+40h] [bp-48h] BYREF
  char v89[16]; // [sp+50h] [bp-38h] BYREF
  char v90[40]; // [sp+60h] [bp-28h] BYREF

  v5 = a3;
  if ( a1 )
  {
    if ( (a5 & 2) != 0 )
      return sub_5462C8();
    if ( (a5 & 1) != 0 )
      v5 = (a3 + 4095) & 0xFFFFF000;
  }
  if ( (v5 & 0xFFF) != 0 && (v5 & 0xFFF) <= 0xFE0 )
  {
    if ( v5 >= v5 + 31 )
      return 0;
    v8 = (v5 + 7) & 0xFFFFFFF8;
  }
  else
  {
    if ( v5 >= v5 + 4095 )
      return 0;
    v8 = (v5 + 4095) & 0xFFFFF000;
  }
  v9 = a2 & 1;
  if ( (a2 & 0x20) != 0 && v9 )
  {
    v75 = (unsigned int *)MiSessionPoolVector();
  }
  else
  {
    v75 = (unsigned int *)PoolVector[v9];
    if ( !v9 && (a2 & 0x200) == 0 )
      v75 = (unsigned int *)(PoolVector[v9] + 4736);
  }
  if ( v8 >= 0x10000 || (ExpPoolFlags & 0x20) != 0 )
  {
    if ( v8 < v8 + 4095 )
    {
      v8 = (v8 + 4095) & 0xFFFFF000;
      goto LABEL_9;
    }
    return 0;
  }
LABEL_9:
  v10 = a1;
  if ( !a1 )
  {
    v10 = MiAllocatePoolPages(a2 & 0x80000261, v8);
    if ( !v10 )
    {
      if ( (ExpPoolFlags & 0x200) == 0 )
        return 0;
      ExDeferredFreePool(v75, 0);
      v10 = MiAllocatePoolPages(a2 & 0x80000261, v8);
      if ( !v10 )
        return 0;
    }
  }
  v11 = a4;
  if ( !ExpAddTagForBigPages(v10, a4, v8, a2, 0, 0) )
  {
    if ( !a1 )
      MiFreePoolPages(v10, v8, a4);
    return 0;
  }
  if ( (v8 & 0xFFF) != 0 )
  {
    if ( (a2 & 1) != 0 )
    {
      if ( (a2 & 0x20) == 0 )
      {
        if ( (a2 & 0x80000000) != 0 )
        {
          LOWORD(v73) = 0;
          v59 = 0;
        }
        else
        {
          if ( (ExpPoolFlags & 0x100) != 0 )
          {
            if ( (a2 & 0x100) != 0 )
            {
              LOWORD(v73) = ExpNumberOfPagedPools;
              v59 = ExpNumberOfPagedPools;
              goto LABEL_89;
            }
            LOWORD(v73) = 1;
          }
          else
          {
            if ( (unsigned __int16)KeNumberNodes > 1u )
            {
              v73 = *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
              v59 = v73;
              if ( v73 < ExpNumberOfPagedPools )
              {
                LOWORD(v73) = v73 + 1;
                ++v59;
              }
              goto LABEL_89;
            }
            LOWORD(v73) = 1;
            if ( ExpNumberOfPagedPools != 1 )
            {
              v57 = ExpPoolIndex + 1;
              v74 = ExpPoolIndex + 1;
              if ( ExpPoolIndex + 1 > (unsigned int)ExpNumberOfPagedPools )
              {
                v57 = 1;
                v74 = 1;
              }
              ExpPoolIndex = v57;
              v58 = v74;
              do
              {
                if ( !*(_DWORD *)(ExpPagedPoolDescriptor[v58] + 8) )
                  break;
                if ( ++v58 > (unsigned int)ExpNumberOfPagedPools )
                  v58 = 1;
              }
              while ( v58 != v57 );
              v73 = v58;
              v11 = a4;
              v59 = v73;
              goto LABEL_89;
            }
          }
          v59 = 1;
        }
LABEL_89:
        v60 = ExpPagedPoolDescriptor[v59];
        v75 = (unsigned int *)v60;
        goto LABEL_90;
      }
    }
    else if ( (unsigned int)ExpNumberOfNonPagedPools > 1 )
    {
      v71 = *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
      LOWORD(v73) = v71;
      if ( v71 >= ExpNumberOfNonPagedPools )
      {
        v71 = ExpNumberOfNonPagedPools - 1;
        LOWORD(v73) = ExpNumberOfNonPagedPools - 1;
      }
      v75 = (unsigned int *)ExpNonPagedPoolDescriptor[v71];
      if ( (a2 & 0x200) == 0 )
      {
        v60 = ExpNonPagedPoolDescriptor[v71] + 4736;
        v75 = (unsigned int *)v60;
LABEL_90:
        v61 = (unsigned int *)(v60 + 384);
        do
          v62 = __ldrex(v61);
        while ( __strex(v62 + 1, v61) );
        goto LABEL_14;
      }
LABEL_95:
      v60 = (int)v75;
      goto LABEL_90;
    }
    LOWORD(v73) = 0;
    goto LABEL_95;
  }
  LOWORD(v73) = 0;
LABEL_14:
  v12 = v75 + 34;
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + (v8 >> 12), v12) );
  v14 = v75 + 36;
  v85 = v75 + 36;
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 + v8, v14) );
  v16 = v75 + 32;
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + 1, v16) );
  v18 = v11 & 0x7FFFFFFF;
  v78 = v11 & 0x7FFFFFFF;
  if ( (v11 & 0x7FFFFFFF) == PoolHitTag )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
  {
    EtwTracePool(3616, a2, v11 & 0x7FFFFFFF, v10, v8);
    v18 = v11 & 0x7FFFFFFF;
  }
  if ( (a2 & 0x20) != 0 )
  {
    v20 = ExpSessionPoolTrackTable;
    v19 = ExpSessionPoolTrackTableMask;
    v21 = ExpSessionPoolTrackTableSize;
  }
  else
  {
    v19 = PoolTrackTableMask;
    v20 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v21 = PoolTrackTableSize;
  }
  v80 = v21;
  v82 = v19;
  v84 = v20;
  v22 = v19 & ((int)(40543
                   * (((v11 & 0x7FFFFFFFu) >> 24) ^ (4
                                                   * ((unsigned __int8)((v11 & 0x7FFFFFFFu) >> 16) ^ (4 * (BYTE1(v11) ^ (4 * (unsigned __int8)v11))))))) >> 2);
  v23 = v22;
  v77 = v22;
  while ( 1 )
  {
    v24 = 28 * v22;
    v25 = (unsigned int *)(v20 + 28 * v22);
    if ( *v25 == v18 )
      break;
    if ( *v25 )
    {
LABEL_28:
      v20 = v84;
      v22 = (v22 + 1) & v82;
      if ( v22 == v23 )
      {
        ExpInsertPoolTrackerExpansion(v18, v8, a2, 28);
        v72 = a2 & 1;
        goto LABEL_35;
      }
    }
    else if ( (a2 & 0x20) != 0 || (v67 = *(_DWORD *)(v24 + PoolTrackTable)) == 0 )
    {
      if ( v22 == v80 - 1 )
        goto LABEL_28;
      if ( (a2 & 0x20) != 0 )
      {
        do
          v70 = __ldrex(v25);
        while ( !v70 && __strex(v18, v25) );
        v20 = v84;
      }
      else
      {
        KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v89);
        if ( !*(_DWORD *)(v24 + PoolTrackTable) )
        {
          *(_DWORD *)(v24 + PoolTrackTable) = v78;
          *v25 = v78;
        }
        KeReleaseInStackQueuedSpinLock((int)v89);
        v23 = v77;
        v18 = v78;
        v20 = v84;
      }
    }
    else
    {
      *v25 = v67;
      v20 = v84;
    }
  }
  v72 = a2 & 1;
  if ( (a2 & 1) != 0 )
  {
    v26 = v25 + 4;
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 + 1, v26) );
    v28 = v25 + 6;
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 + v8, v28) );
  }
  else
  {
    v31 = v25 + 1;
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 + 1, v31) );
    v33 = v25 + 3;
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 + v8, v33) );
  }
LABEL_35:
  if ( a2 < 0 && (a3 & 0xFFF) != 0 )
    memset((_BYTE *)((a3 & 0xFFFFF000) + v10), 0, 4096);
  if ( (v8 & 0xFFF) == 0 )
    return v10;
  v35 = a2 & 0x221 | 2;
  v36 = v10 + v8;
  *(_WORD *)(v10 + v8) = (_WORD)v73 << 9;
  *(_WORD *)(v36 + 2) = ((_WORD)v35 << 9) | 2;
  *(_DWORD *)(v36 + 4) = 1734439494;
  *(_DWORD *)(v36 + 8) = v8;
  do
    v37 = __ldrex(v85);
  while ( __strex(v37 + 8, v85) );
  if ( PoolHitTag == 1734439494 )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, v35, 1734439494, v10 + v8, 16);
  if ( (v35 & 0x20) != 0 )
  {
    v38 = ExpSessionPoolTrackTable;
    v39 = ExpSessionPoolTrackTableMask;
    v83 = ExpSessionPoolTrackTableSize;
  }
  else
  {
    v38 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v39 = PoolTrackTableMask;
    v83 = PoolTrackTableSize;
  }
  v79 = v38;
  v81 = v39;
  v40 = v39 & 0x398FEF7;
  v86 = v39 & 0x398FEF7;
  while ( 1 )
  {
    v41 = *(_DWORD *)(28 * v40 + v38);
    v42 = (unsigned int *)(28 * v40 + v38);
    if ( v41 == 1734439494 )
      break;
    if ( v41 )
      goto LABEL_161;
    if ( (v35 & 0x20) == 0 )
    {
      v68 = *(_DWORD *)(28 * v40 + PoolTrackTable);
      if ( v68 )
      {
        *v42 = v68;
        continue;
      }
    }
    if ( v40 == v83 - 1 )
    {
LABEL_161:
      v40 = (v40 + 1) & v39;
      if ( v40 == v86 )
      {
        ExpInsertPoolTrackerExpansion(1734439494, 16, v35, 28);
        goto LABEL_62;
      }
    }
    else if ( (v35 & 0x20) != 0 )
    {
      do
        v69 = __ldrex(v42);
      while ( !v69 && __strex(0x67617246u, v42) );
    }
    else
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v88);
      if ( !*(_DWORD *)(28 * v40 + PoolTrackTable) )
      {
        *(_DWORD *)(28 * v40 + PoolTrackTable) = 1734439494;
        *v42 = 1734439494;
      }
      KeReleaseInStackQueuedSpinLock((int)v88);
      v38 = v79;
      v39 = v81;
    }
  }
  if ( (v35 & 1) != 0 )
  {
    v43 = v42 + 4;
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 + 1, v43) );
    v45 = v42 + 6;
    do
      v46 = __ldrex(v45);
    while ( __strex(v46 + 16, v45) );
  }
  else
  {
    v63 = v42 + 1;
    do
      v64 = __ldrex(v63);
    while ( __strex(v64 + 1, v63) );
    v65 = v42 + 3;
    do
      v66 = __ldrex(v65);
    while ( __strex(v66 + 16, v65) );
  }
LABEL_62:
  v47 = (4096 - (((_WORD)v8 + 16) & 0xFFFu)) >> 3;
  *(_DWORD *)(v36 + 20) = 1701147206;
  v48 = &v75[2 * v47 + 158];
  *(_WORD *)(v36 + 16) = ((_WORD)v73 << 9) | 2;
  *(_WORD *)(v36 + 18) = v47 & 0x1FF;
  if ( v72 )
  {
    v49 = (unsigned int)(v75 + 1);
    v50 = KeAbPreAcquire((unsigned int)(v75 + 1), 0, 0);
    v51 = KfRaiseIrql(1);
    do
      v52 = __ldrex((unsigned __int8 *)v49);
    while ( __strex(v52 & 0xFE, (unsigned __int8 *)v49) );
    __dmb(0xBu);
    if ( (v52 & 1) == 0 )
      ExpAcquireFastMutexContended(v49, v50);
    if ( v50 )
      *(_BYTE *)(v50 + 14) |= 1u;
    v75[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v75[8] = v51;
    PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
  }
  else
  {
    v49 = (unsigned int)(v75 + 1);
    KeAcquireInStackQueuedSpinLock(v75 + 1, (unsigned int)v90);
  }
  v53 = (unsigned int **)v48[1];
  v54 = v36 + 24;
  *(_DWORD *)(v36 + 24) = v48;
  *(_DWORD *)(v36 + 28) = v53;
  if ( *v53 != v48 )
    __fastfail(3u);
  *v53 = (unsigned int *)v54;
  v48[1] = v54;
  if ( v72 )
  {
    PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
    v55 = *(_DWORD *)(v49 + 28);
    *(_DWORD *)(v49 + 4) = 0;
    __dmb(0xBu);
    do
      v56 = __ldrex((unsigned int *)v49);
    while ( !v56 && __strex(1u, (unsigned int *)v49) );
    if ( v56 )
      ExpReleaseFastMutexContended((unsigned int *)v49, v56);
    KfLowerIrql((unsigned __int8)v55);
    KeAbPostRelease(v49);
    return v10;
  }
  KeReleaseInStackQueuedSpinLock((int)v90);
  return v10;
}
