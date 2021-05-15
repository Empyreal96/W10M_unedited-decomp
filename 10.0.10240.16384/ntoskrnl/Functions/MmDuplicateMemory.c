// MmDuplicateMemory 
 
int __fastcall MmDuplicateMemory(int a1)
{
  int v1; // r10
  int (__fastcall **v2)(int); // r9
  int v3; // r6
  int v4; // r0
  int v5; // r7
  unsigned int v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r8
  int v9; // r4
  int *v10; // r6
  unsigned int v11; // r10
  unsigned int v12; // r6
  unsigned int *v13; // r9
  unsigned int v14; // r8
  __int16 *v15; // r6
  int v16; // r7
  unsigned int v17; // r0
  unsigned int v18; // r4
  int v19; // r9
  unsigned int v20; // r4
  int v21; // r7
  unsigned int v22; // r6
  unsigned int v23; // r9
  unsigned int v24; // r0
  unsigned int v25; // r7
  int v26; // r4
  int v27; // r3
  unsigned int v28; // r8
  unsigned int v29; // r3
  int v30; // r9
  unsigned int v31; // r4
  unsigned int v32; // r8
  int v33; // r0
  int v34; // r7
  unsigned int v35; // r3
  int v36; // r0
  unsigned int v37; // r9
  unsigned int v38; // r5
  int v39; // r4
  int v40; // r8
  unsigned int v41; // r1
  int v42; // r7
  unsigned int v43; // r1
  int v44; // r7
  int v45; // r9
  unsigned int v46; // r1
  unsigned int v47; // r1
  int v48; // r6
  int v49; // r1
  int *v50; // r10
  unsigned int v51; // r8
  int v52; // r3
  unsigned int v53; // r4
  unsigned int *v54; // r9
  unsigned int v55; // r7
  int v56; // r10
  int v57; // r6
  unsigned int v58; // r4
  _DWORD *v59; // r2
  int v60; // r7
  int v61; // r3
  unsigned int *v62; // r0
  unsigned int v63; // r4
  unsigned int v64; // r0
  unsigned int v65; // r7
  int v66; // r9
  int v67; // r3
  unsigned int v68; // r8
  unsigned int *v69; // r0
  unsigned int v70; // r4
  unsigned int v71; // r0
  unsigned int v72; // r7
  int v73; // r9
  int v74; // r3
  unsigned int v75; // r8
  int v76; // r0
  unsigned int v77; // r4
  int v79; // [sp+8h] [bp-70h]
  __int16 *v80; // [sp+8h] [bp-70h]
  int v81; // [sp+8h] [bp-70h]
  int v82; // [sp+8h] [bp-70h]
  unsigned int v83; // [sp+Ch] [bp-6Ch]
  int v84; // [sp+Ch] [bp-6Ch]
  unsigned int v85; // [sp+Ch] [bp-6Ch]
  int v86; // [sp+10h] [bp-68h]
  int v87; // [sp+10h] [bp-68h]
  int v89; // [sp+18h] [bp-60h]
  int v90; // [sp+18h] [bp-60h]
  char v91; // [sp+1Ch] [bp-5Ch]
  int v92; // [sp+1Ch] [bp-5Ch]
  int v93; // [sp+24h] [bp-54h]
  unsigned int v94; // [sp+24h] [bp-54h]
  int v95; // [sp+2Ch] [bp-4Ch]
  int v96; // [sp+30h] [bp-48h]
  int *v97; // [sp+30h] [bp-48h]
  int v98; // [sp+34h] [bp-44h] BYREF
  int v99; // [sp+38h] [bp-40h]
  int v100; // [sp+3Ch] [bp-3Ch]
  int v101; // [sp+40h] [bp-38h]
  int v102; // [sp+44h] [bp-34h]
  int v103; // [sp+48h] [bp-30h]
  unsigned int v104; // [sp+4Ch] [bp-2Ch]
  char v105[40]; // [sp+50h] [bp-28h] BYREF

  v1 = *(_DWORD *)(a1 + 16);
  v2 = (int (__fastcall **)(int))a1;
  v91 = v1;
  if ( (v1 & 5) == 5 )
    return -1073741811;
  if ( (v1 & 8) != 0 )
  {
    LOBYTE(v1) = v1 & 0xFA;
    v91 = v1;
  }
  if ( !dword_634384 && !MiInitializeMirroring(0) )
    return -1073741670;
  if ( (v1 & 0xA) != 0 )
  {
    v96 = 0;
  }
  else
  {
    CcNotifyWriteBehind(2);
    v96 = 1;
  }
  v103 = 0;
  v93 = 0;
  KeWaitForSingleObject((unsigned int)&unk_634358, 18, 0, 0, 0);
  v102 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  MiLockDynamicMemoryExclusive((int)MiSystemPartition, v102);
  if ( (MiFlags & 4) == 0 )
    MmLockPagableSectionByHandle(ExPageLockHandle);
  v4 = RtlSetAllBits((_DWORD *)dword_634388);
  v89 = 0;
  v99 = 0;
  v100 = 1;
  v5 = 8;
  v95 = 8;
  do
    v6 = __ldrex((unsigned int *)&dword_634C84);
  while ( __strex(v6 + 1, (unsigned int *)&dword_634C84) );
  __dmb(0xBu);
  if ( (v1 & 1) == 0 )
  {
    if ( (v1 & 4) != 0 )
    {
      v99 = 2;
      v100 = 0;
      v5 = 7;
    }
    else
    {
      if ( (v1 & 8) == 0 )
        goto LABEL_22;
      v100 = 0;
      v99 = 2;
      v5 = 0;
    }
    v95 = v5;
    goto LABEL_22;
  }
  v99 = 3;
  v100 = 0;
  v5 = 8;
LABEL_22:
  v3 = (*v2)(v4);
  if ( v3 < 0 )
    goto LABEL_117;
  while ( 2 )
  {
    RtlClearAllBits(dword_634384);
    if ( v89 == v96 )
    {
      v93 = 1;
      do
        v7 = __ldrex((unsigned int *)&dword_6348E0);
      while ( __strex(v7 + 1, (unsigned int *)&dword_6348E0) );
      __dmb(0xBu);
    }
    if ( (v1 & 4) == 0 )
    {
      if ( (v1 & 0x10) == 0 )
        MmEmptyAllWorkingSets();
      v5 = 0;
    }
    dword_634380 = 1;
    v8 = 0;
    v9 = v99;
    v79 = v99;
    v83 = 0;
    v86 = v5;
    do
    {
      v10 = *(int **)&MiSystemPartition[2 * v9 + 1226];
      if ( v9 <= 1 )
        v10 = (int *)(*(_DWORD *)&MiSystemPartition[2 * v9 + 512] + 20 * v8);
      if ( v9 == 2 )
        v10 = &dword_63FD00[5 * v5];
      if ( v9 == 3 )
      {
        if ( *v10 == dword_640718 )
          goto LABEL_66;
        v10 = (int *)((char *)&unk_63FF00 + 20 * v5);
      }
      KeAcquireInStackQueuedSpinLock((unsigned int *)v10 + 4, (unsigned int)v105);
      if ( *v10 )
      {
        v11 = dword_634388;
        v12 = v10[2];
        do
        {
          v13 = (unsigned int *)(MmPfnDatabase + 24 * v12);
          if ( v9 == 2 && MI_IS_DECAY_PFN(v12) )
          {
            v14 = v13[2] >> 12;
            if ( v14 != v12 )
            {
              do
              {
                v104 = 3 * v14;
                v101 = MmPfnDatabase;
                if ( ((*(int *)(*(_DWORD *)(v11 + 4) + 4 * (v14 >> 5)) >> (v14 & 0x1F)) & 1) != 0 )
                {
                  RtlInterlockedClearBitRun(v11, v14, 1u);
                  *(_BYTE *)((v14 >> 3) + *(_DWORD *)(dword_634384 + 4)) |= 1 << (v14 & 7);
                  v11 = dword_634388;
                }
                v14 = *(_DWORD *)(v101 + 8 * v104);
              }
              while ( v14 != v12 );
              v9 = v79;
            }
          }
          else if ( ((*(int *)(*(_DWORD *)(v11 + 4) + 4 * (v12 >> 5)) >> (v12 & 0x1F)) & 1) != 0 )
          {
            RtlInterlockedClearBitRun(v11, v12, 1u);
            *(_BYTE *)((v12 >> 3) + *(_DWORD *)(dword_634384 + 4)) |= 1 << (v12 & 7);
            v11 = dword_634388;
          }
          v12 = *v13;
        }
        while ( *v13 != 0xFFFFF );
        v8 = v83;
        v5 = v86;
        v2 = (int (__fastcall **)(int))a1;
      }
      KeReleaseInStackQueuedSpinLock((int)v105);
      if ( v9 > 1 )
      {
        if ( v9 == 2 )
        {
          if ( ++v5 != 8 )
            v9 = 1;
          v86 = v5;
          if ( v5 == 8 )
          {
            v5 = 0;
            v86 = 0;
          }
        }
        else if ( v9 == 3 )
        {
          if ( ++v5 != 16 )
            v9 = 2;
          v86 = v5;
        }
      }
      else
      {
        v83 = ++v8;
        if ( v8 >= dword_633818 )
        {
          v8 = 0;
          v83 = 0;
          if ( v9 == 1 )
            MiMirrorNodeLargePages(0, (int)v2);
        }
        else
        {
          --v9;
        }
      }
LABEL_66:
      v79 = ++v9;
    }
    while ( v9 <= 4 );
    KeAcquireInStackQueuedSpinLock((unsigned int *)algn_640690, (unsigned int)v105);
    v15 = MiSystemPartition;
    v16 = 2;
    v17 = dword_634388;
    v80 = MiSystemPartition;
    v84 = 2;
    do
    {
      v18 = *((_DWORD *)v15 + 482);
      if ( v18 != 0xFFFFF )
      {
        do
        {
          v19 = MmPfnDatabase;
          if ( ((*(int *)(*(_DWORD *)(v17 + 4) + 4 * (v18 >> 5)) >> (v18 & 0x1F)) & 1) != 0 )
          {
            RtlInterlockedClearBitRun(v17, v18, 1u);
            *(_BYTE *)((v18 >> 3) + *(_DWORD *)(dword_634384 + 4)) |= 1 << (v18 & 7);
            v17 = dword_634388;
          }
          v18 = *(_DWORD *)(v19 + 24 * v18);
        }
        while ( v18 != 0xFFFFF );
        v15 = v80;
        v16 = v84;
      }
      v15 += 10;
      --v16;
      v80 = v15;
      v84 = v16;
    }
    while ( v16 );
    LOBYTE(v1) = v91;
    v20 = dword_63FE08;
    if ( dword_63FE08 != 0xFFFFF )
    {
      do
      {
        v21 = MmPfnDatabase;
        if ( ((*(int *)(*(_DWORD *)(v17 + 4) + 4 * (v20 >> 5)) >> (v20 & 0x1F)) & 1) != 0 )
        {
          RtlInterlockedClearBitRun(v17, v20, 1u);
          *(_BYTE *)((v20 >> 3) + *(_DWORD *)(dword_634384 + 4)) |= 1 << (v20 & 7);
          v17 = dword_634388;
        }
        v20 = *(_DWORD *)(v21 + 24 * v20);
      }
      while ( v20 != 0xFFFFF );
      LOBYTE(v1) = v91;
    }
    KeReleaseInStackQueuedSpinLock((int)v105);
    v22 = 0;
    v81 = 0;
    v85 = 0;
    v23 = 0;
    do
    {
      v24 = RtlFindSetBits((unsigned int *)dword_634384, 1u, v22);
      v25 = v24;
      if ( v24 < v22 || v24 == -1 )
        break;
      v26 = RtlFindNextForwardRunClear(dword_634384, v24, (int)&v98);
      v87 = v26;
      if ( v26 )
        v27 = v98;
      else
        v27 = *(_DWORD *)dword_634384;
      v28 = v27 - v25;
      if ( (v1 & 8) == 0 )
      {
LABEL_103:
        v85 = v23 + v28;
        v24 = (*(int (__fastcall **)(unsigned int, unsigned int, unsigned int, unsigned int))(a1 + 8))(
                v25 << 12,
                v25 >> 20,
                v28 << 12,
                v28 >> 20);
        v3 = v24;
        if ( (v1 & 8) != 0 )
        {
          v37 = MmPfnDatabase + 24 * v25;
          v38 = v37 + 24 * v28;
          do
          {
            v39 = MiLockPage(v37);
            MiRemoveLockedPageChargeAndDecRef(v37);
            v24 = MiUnlockPage(v37, v39);
            v37 += 24;
          }
          while ( v37 < v38 );
        }
        if ( v3 < 0 )
        {
          if ( v93 == 1 )
          {
            __dmb(0xBu);
            do
              v41 = __ldrex((unsigned int *)&dword_6348E0);
            while ( __strex(v41 - 1, (unsigned int *)&dword_6348E0) );
          }
          dword_634380 = 0;
LABEL_117:
          v42 = 17;
          goto LABEL_118;
        }
        v29 = v87 + v28;
LABEL_108:
        v22 = v29 + v25;
        goto LABEL_109;
      }
      if ( v81 == 1 )
      {
        v24 = RtlInterlockedSetBitRun(dword_634388, v25, v28);
        v29 = v28 + v26;
        goto LABEL_108;
      }
      if ( v28 > 0x100 )
        v28 = 256;
      v87 = 0;
      v30 = -1;
      v22 = v25;
      v31 = MmPfnDatabase + 24 * v25;
      v32 = v31 + 24 * v28;
      while ( 1 )
      {
        v33 = MiLockPage(v31);
        v34 = v33;
        if ( *(_WORD *)(v31 + 16) || (v35 = *(_BYTE *)(v31 + 18) & 7, v35 < 2) || v35 > 4 )
        {
          v24 = MiUnlockPage(v31, v33);
          if ( v30 != -1 )
            goto LABEL_102;
          goto LABEL_98;
        }
        MiUnlinkPageFromList(v31, 0);
        v36 = MiAddLockedPageCharge(v31, 0);
        *(_DWORD *)(v31 + 12) &= 0xC0000000;
        if ( !v36 )
          break;
        RtlInterlockedClearBitRun(dword_634388, v22, 1u);
        v24 = MiUnlockPage(v31, v34);
        if ( v30 == -1 )
          v30 = v22;
LABEL_98:
        v31 += 24;
        ++v22;
        if ( v31 >= v32 )
          goto LABEL_101;
      }
      MiPfnReferenceCountIsZero(v31, v22);
      v24 = MiUnlockPage(v31, v34);
      v81 = 1;
LABEL_101:
      if ( v30 != -1 )
      {
LABEL_102:
        v25 = v30;
        v28 = v22 - v30;
        v23 = v85;
        goto LABEL_103;
      }
LABEL_109:
      v23 = v85;
    }
    while ( v22 < *(_DWORD *)dword_634384 );
    v40 = v93;
    if ( v93 != 1 && v23 >= 0x400 )
    {
      v2 = (int (__fastcall **)(int))a1;
      v5 = v95;
      ++v89;
      continue;
    }
    break;
  }
  if ( (v1 & 2) == 0 && v93 == 1 )
  {
    __dmb(0xBu);
    do
      v43 = __ldrex((unsigned int *)&dword_6348E0);
    while ( __strex(v43 - 1, (unsigned int *)&dword_6348E0) );
    v40 = 0;
  }
  v44 = a1;
  v45 = KeGetCurrentIrql(v24);
  v92 = v45;
  v3 = (*(int (__fastcall **)(_DWORD))(a1 + 4))(0);
  if ( v3 < 0 )
  {
    if ( v40 == 1 )
    {
      __dmb(0xBu);
      do
        v46 = __ldrex((unsigned int *)&dword_6348E0);
      while ( __strex(v46 - 1, (unsigned int *)&dword_6348E0) );
    }
    dword_634380 = 0;
    KfLowerIrql(v45);
    goto LABEL_117;
  }
  if ( *(_DWORD *)(a1 + 12) )
    RtlSetAllBits((_DWORD *)dword_634384);
  MiLockAllMemoryLists(dword_63438C);
  dword_63437C = v102;
  if ( v40 == 1 )
  {
    __dmb(0xBu);
    do
      v47 = __ldrex((unsigned int *)&dword_6348E0);
    while ( __strex(v47 - 1, (unsigned int *)&dword_6348E0) );
  }
  dword_634380 = 2;
  if ( (v1 & 0xD) != 0 )
  {
    v48 = 2;
    v90 = 2;
    if ( (v1 & 8) != 0 )
    {
      v48 = 1;
      v90 = 1;
    }
    v49 = 0;
    v82 = 0;
    v50 = dword_63FD00;
    v97 = dword_63FD00;
    v51 = 0;
    v94 = 0;
    while ( 1 )
    {
      if ( v48 > 1 )
        v52 = (int)v50;
      else
        v52 = *(_DWORD *)&MiSystemPartition[2 * v48 + 512] + 20 * v51;
      v53 = *(_DWORD *)(v52 + 8);
      if ( v53 != 0xFFFFF )
      {
        do
        {
          v54 = (unsigned int *)(MmPfnDatabase + 24 * v53);
          if ( v48 == 2 && MI_IS_DECAY_PFN(v53) )
          {
            v55 = v54[2] >> 12;
            if ( v55 != v53 )
            {
              do
              {
                v101 = MmPfnDatabase;
                RtlInterlockedClearBitRun(dword_634388, v55, 1u);
                if ( *(_DWORD *)(a1 + 12) )
                  *(_BYTE *)((v55 >> 3) + *(_DWORD *)(dword_634384 + 4)) &= ~(1 << (v55 & 7));
                v55 = *(_DWORD *)(v101 + 24 * v55);
              }
              while ( v55 != v53 );
              v48 = v90;
            }
            v44 = a1;
          }
          else
          {
            RtlInterlockedClearBitRun(dword_634388, v53, 1u);
            if ( *(_DWORD *)(v44 + 12) )
              *(_BYTE *)((v53 >> 3) + *(_DWORD *)(dword_634384 + 4)) &= ~(unsigned __int8)(1 << (v53 & 7));
          }
          v53 = *v54;
        }
        while ( *v54 != 0xFFFFF );
        v51 = v94;
        v50 = v97;
        v49 = v82;
      }
      if ( v48 <= 1 )
      {
        v94 = ++v51;
        if ( v51 < dword_633818 )
          continue;
        v51 = 0;
        v94 = 0;
      }
      if ( !v48 )
      {
        v56 = a1;
        MiMirrorNodeLargePages(1u, a1);
        goto LABEL_168;
      }
      if ( v48 == 2 )
      {
        ++v49;
        v50 += 5;
        v82 = v49;
        v97 = v50;
        if ( v49 != v95 )
          continue;
      }
      v90 = --v48;
    }
  }
  v56 = a1;
LABEL_168:
  v57 = 0;
  v58 = 0;
  v59 = (_DWORD *)MmPhysicalMemoryBlock;
  do
  {
    v60 = v59[2 * v57 + 2];
    if ( v60 != v58 )
    {
      RtlInterlockedClearBitRun(dword_634388, v58, v60 - v58);
      if ( *(_DWORD *)(v56 + 12) )
        RtlClearBits((_BYTE *)dword_634384, v58, v60 - v58);
      v59 = (_DWORD *)MmPhysicalMemoryBlock;
    }
    v61 = v59[2 * v57++ + 3];
    v58 = v61 + v60;
  }
  while ( v57 != *v59 );
  if ( v58 != dword_633850 + 1 )
  {
    RtlInterlockedClearBitRun(dword_634388, v58, dword_633850 - v58 + 1);
    if ( *(_DWORD *)(v56 + 12) )
      RtlClearBits((_BYTE *)dword_634384, v58, dword_633850 - v58 + 1);
  }
  v62 = (unsigned int *)dword_634388;
  v63 = 0;
  do
  {
    v64 = RtlFindSetBits(v62, 1u, v63);
    v65 = v64;
    if ( v64 < v63 || v64 == -1 )
      break;
    v66 = RtlFindNextForwardRunClear(dword_634388, v64, (int)&v98);
    if ( v66 )
      v67 = v98;
    else
      v67 = *(_DWORD *)dword_634388;
    v68 = v67 - v65;
    v3 = (*(int (__fastcall **)(unsigned int, unsigned int, unsigned int, unsigned int))(v56 + 8))(
           v65 << 12,
           v65 >> 20,
           (v67 - v65) << 12,
           (v67 - v65) >> 20);
    if ( v3 < 0 )
    {
LABEL_191:
      dword_63437C = 0;
      goto LABEL_192;
    }
    v63 = v68 + v66 + v65;
    v62 = (unsigned int *)dword_634388;
  }
  while ( v63 < *(_DWORD *)dword_634388 );
  if ( *(_DWORD *)(v56 + 12) )
  {
    v69 = (unsigned int *)dword_634384;
    v70 = 0;
    do
    {
      v71 = RtlFindSetBits(v69, 1u, v70);
      v72 = v71;
      if ( v71 < v70 || v71 == -1 )
        break;
      v73 = RtlFindNextForwardRunClear(dword_634384, v71, (int)&v98);
      if ( v73 )
        v74 = v98;
      else
        v74 = *(_DWORD *)dword_634384;
      v75 = v74 - v72;
      v3 = (*(int (__fastcall **)(unsigned int, unsigned int, unsigned int, unsigned int))(v56 + 12))(
             v72 << 12,
             v72 >> 20,
             (v74 - v72) << 12,
             (v74 - v72) >> 20);
      if ( v3 < 0 )
        goto LABEL_191;
      v70 = v75 + v73 + v72;
      v69 = (unsigned int *)dword_634384;
    }
    while ( v70 < *(_DWORD *)dword_634384 );
  }
  v76 = (*(int (__fastcall **)(int))(v56 + 4))(1);
  dword_63437C = 0;
  v3 = v76;
  if ( v76 == 1073742484 && !v100 )
  {
    v3 = 0;
    MiResumeFromHibernate(v95);
    v103 = 1;
  }
LABEL_192:
  v42 = v92;
  dword_634380 = 0;
LABEL_118:
  if ( v42 != 17 )
  {
    MiUnlockAllMemoryLists(dword_63438C);
    KfLowerIrql(v42);
  }
  if ( (MiFlags & 4) == 0 )
    MmUnlockPagableImageSection(ExPageLockHandle);
  if ( v103 == 1 )
  {
    dword_634374 = v95;
    ExQueueWorkItem(&dword_634368, 2);
  }
  else
  {
    __dmb(0xBu);
    do
      v77 = __ldrex((unsigned int *)&dword_634C84);
    while ( __strex(v77 - 1, (unsigned int *)&dword_634C84) );
    KeSetEvent((int)&unk_634358, 0, 0);
  }
  MiUnlockDynamicMemoryExclusive((int)MiSystemPartition, v102);
  return v3;
}
