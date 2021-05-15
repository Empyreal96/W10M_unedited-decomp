// MiRestoreTransitionPte 
 
int __fastcall MiRestoreTransitionPte(int a1, int a2)
{
  int v3; // r3
  unsigned int v4; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int *v8; // r1
  int v9; // r3
  int v10; // r6
  int v11; // r0
  _DWORD *v12; // r0
  int v13; // r6
  unsigned int *v14; // r2
  unsigned int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r1
  unsigned __int8 *v21; // r0
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r3
  int v28; // r2
  int *v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r6
  int v33; // r0
  int v34; // r6
  int v35; // r2
  int v36; // r3
  unsigned int v37; // lr
  unsigned int v38; // r3
  unsigned int v39; // r9
  unsigned int *v40; // r1
  unsigned int v41; // r3
  int v42; // r8
  int v43; // r0
  __int64 v44; // kr00_8
  unsigned int v45; // r8
  int v46; // r3
  int v47; // r9
  int v48; // r0
  int v49; // r10
  unsigned int v50; // r8
  int v51; // r9
  unsigned int v52; // r10
  int v53; // r9
  int v54; // r0
  unsigned int v55; // r2
  _DWORD *v56; // r9
  int v57; // r3
  unsigned int *v58; // r10
  unsigned __int8 *v59; // r3
  unsigned int v60; // r1
  unsigned int i; // r0
  unsigned int v62; // r1
  int v63; // r3
  int v64; // r3
  int v65; // r2
  unsigned int v66; // r1
  int j; // r0
  unsigned int v68; // r1
  int v69; // r1
  void **v70; // r5
  int v71; // r0
  int v72; // r3
  unsigned __int8 *v73; // r1
  unsigned int v74; // r2
  int v75; // r3
  unsigned int v76; // r2
  int v77; // r2
  unsigned int *v78; // r2
  int result; // r0
  char v80; // r3
  int v81; // r2
  unsigned int *v82; // r2
  unsigned int v83; // r1
  _DWORD *v84; // r4
  unsigned int v85; // r3
  int v86; // r3
  int v87; // r0
  unsigned int *v88; // r1
  unsigned int *v89; // r2
  int v90; // [sp+8h] [bp-E8h]
  unsigned int v91; // [sp+Ch] [bp-E4h]
  int v92[4]; // [sp+10h] [bp-E0h] BYREF
  int v93[2]; // [sp+20h] [bp-D0h] BYREF
  int v94; // [sp+28h] [bp-C8h]
  int v95; // [sp+2Ch] [bp-C4h]
  int v96; // [sp+38h] [bp-B8h] BYREF
  char v97; // [sp+3Ch] [bp-B4h]
  char v98; // [sp+3Dh] [bp-B3h]
  int v99; // [sp+40h] [bp-B0h]
  int v100; // [sp+44h] [bp-ACh]
  int v101; // [sp+48h] [bp-A8h]
  int v102; // [sp+4Ch] [bp-A4h]

  v3 = *(_BYTE *)(a1 + 23) & 7;
  v93[0] = a2;
  if ( v3 == 3 )
  {
    if ( MiGetPagePrivilege() )
    {
      v4 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
      if ( KeSetPagePrivilege() < 0 )
        KeBugCheckEx(26, 333067, v4 + (v4 >> 31));
    }
    *(_DWORD *)(a1 + 20) &= 0xF8FFFFFF;
  }
  v5 = *(_DWORD *)(a1 + 20);
  v94 = 0x8000000;
  if ( (v5 & 0x8000000) != 0 )
  {
    v27 = *(_DWORD *)(a1 + 4);
    if ( (v27 & 0x80000000) != 0 )
    {
      v28 = *(_DWORD *)(a1 + 8);
      if ( (v28 & 0x400) == 0
        && (v28 & 0x10) == 0
        && (v28 & 2) == 0
        && (v28 & 0xC00) == 0
        && (v28 & 0x10) == 0
        && (v28 & 8) == 0
        && (v28 & 0xFFFFE000) == 0x2000 )
      {
        v29 = (int *)(a1 + 8);
        v30 = *(_DWORD *)(a1 + 8) & 0x1FFF;
        if ( (unsigned int)(a1 + 1073741832) > 0x3FFFFF )
        {
          *v29 = v30;
        }
        else
        {
          v31 = *v29;
          v32 = 0;
          __dmb(0xBu);
          *v29 = v30;
          if ( (v31 & 2) == 0 && (v30 & 2) != 0 )
            v32 = 1;
          if ( (unsigned int)(a1 + 1070596104) <= 0xFFF )
          {
            v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * ((unsigned __int16)v29 & 0xFFF)), v30);
          }
          if ( v32 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
    }
    else
    {
      *(_DWORD *)(a1 + 4) = v27 | 0x80000000;
    }
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = 16;
    if ( (v6 & 0x10) == 0 )
    {
      if ( (v6 & 2) == 0 && (v6 & 0xC00) == 0 && (v6 & 0x10) == 0 && (v6 & 8) == 0 )
      {
        v7 = v6 & 0xFFFFE000;
        if ( (v6 & 0xFFFFE000) == 0x2000 )
        {
          v8 = (int *)(a1 + 8);
          v7 = a1 + 1073741832;
          v6 = *(_DWORD *)(a1 + 8) & 0x1FFF;
          if ( (unsigned int)(a1 + 1073741832) > 0x3FFFFF )
          {
            *v8 = v6;
          }
          else
          {
            v9 = *v8;
            v10 = 0;
            __dmb(0xBu);
            *v8 = v6;
            if ( (v9 & 2) == 0 && (v6 & 2) != 0 )
              v10 = 1;
            v7 = a1 + 1070596104;
            if ( (unsigned int)(a1 + 1070596104) <= 0xFFF )
            {
              v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * ((unsigned __int16)v8 & 0xFFF)), v6);
            }
            if ( v10 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
      }
      v12 = (_DWORD *)MiGetTopLevelPfn(a1, 0, v6, v7);
      v13 = *v12;
      if ( v12 != (_DWORD *)a1 )
      {
        __dmb(0xBu);
        v14 = v12 + 3;
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 & 0x7FFFFFFF, v14) );
      }
      v16 = (unsigned int *)(v13 + 276);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 - 1, v16) );
    }
    if ( (*(_DWORD *)(a1 + 20) & 0xFFFFF) == (a1 - MmPfnDatabase) / 24 )
    {
      v18 = (*(_DWORD *)(a1 + 4) | 0x80000000) - 352;
      if ( (*(_DWORD *)(((v18 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
        v19 = ((v18 >> 12) & 0x3FF) + (*(_DWORD *)(((v18 >> 20) & 0xFFC) - 1070596096) >> 12);
      else
        v19 = *(_DWORD *)(((v18 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
      *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 20) & 0xFFF00000 | v19 & 0xFFFFF;
      v20 = MmPfnDatabase + 24 * v19;
      v21 = (unsigned __int8 *)(v20 + 15);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      __dmb(0xBu);
      if ( v22 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v20 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v21);
          while ( __strex(v24 | 0x80, v21) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      *(_DWORD *)(v20 + 12) = *(_DWORD *)(v20 + 12) & 0xC0000000 | ((*(_DWORD *)(v20 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v25 = (unsigned int *)(v20 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
    }
  }
  v34 = MmPfnDatabase + 24 * (*(_DWORD *)(a1 + 20) & 0xFFFFF);
  v35 = 4;
  v36 = *(unsigned __int8 *)(v34 + 18) >> 6;
  if ( !v36 || v36 == 3 )
  {
    v35 = 12;
  }
  else if ( v36 == 2 )
  {
    v35 = 28;
  }
  v37 = (MmProtectToPteMask[v35] & 0xFED | (*(_DWORD *)(a1 + 20) << 12) | 0x12) & 0xFFFFF1FF;
  v38 = (unsigned int)KeGetPcr();
  v39 = (*(_DWORD *)((v38 & 0xFFFFF000) + 0x1384) & 0xFFFFF000)
      + ((*(_DWORD *)((v38 & 0xFFFFF000) + 0x1384) & 0xFFF) << 12);
  v40 = (unsigned int *)(((v39 >> 10) & 0x3FFFFC) - 0x40000000);
  v41 = *v40;
  v42 = 0;
  __dmb(0xBu);
  *v40 = v37;
  if ( (v41 & 2) == 0 )
    v42 = 1;
  if ( ((v39 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
  {
    v43 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v43, (_DWORD *)(v43 + 4 * ((v39 >> 10) & 0xFFC)), v37);
  }
  if ( v42 == 1 )
  {
    __dsb(0xFu);
    __isb(0xFu);
  }
  v44 = *(_QWORD *)(a1 + 4);
  v45 = v39 + 4 * (((unsigned int)v44 >> 2) & 0x3FF);
  if ( v45 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v45 = HIDWORD(v44);
  }
  else
  {
    v46 = *(_DWORD *)v45;
    v47 = 0;
    __dmb(0xBu);
    *(_DWORD *)v45 = HIDWORD(v44);
    if ( (v46 & 2) == 0 && (v44 & 0x200000000i64) != 0 )
      v47 = 1;
    if ( v45 + 1070596096 <= 0xFFF )
    {
      v48 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v48, (_DWORD *)(v48 + 4 * (v45 & 0xFFF)), SWORD2(v44));
    }
    if ( v47 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  v49 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384);
  v50 = v45 & 0xFFFFF000;
  v51 = v49 & 0xFFF;
  v52 = v49 & 0xFFFFF000;
  v53 = v51 + 1;
  __dmb(0xBu);
  *(_DWORD *)(((v50 >> 10) & 0x3FFFFC) - 0x40000000) = 0;
  if ( ((v50 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
  {
    v54 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v54, (_DWORD *)(v54 + 4 * ((v50 >> 10) & 0xFFC)), 0);
  }
  if ( v53 == 16 )
  {
    v100 = 0;
    v101 = 0;
    v96 = 0;
    v98 = 0;
    v99 = 33;
    v102 = 0;
    v97 = 1;
    MiInsertTbFlushEntry(&v96, v52, 16);
    MiFlushTbList(&v96);
    *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v52;
  }
  else
  {
    *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v53 | v52;
  }
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 && (*(_DWORD *)(a1 + 8) & 0x400) != 0 )
  {
    v55 = *(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC));
    v56 = *(_DWORD **)v55;
    v91 = v55;
    v57 = *(_DWORD *)(*(_DWORD *)v55 + 28);
    v95 = *(_DWORD *)v55;
    if ( (v57 & 0x20) != 0 || !v56[8] )
      v90 = 0;
    else
      v90 = v55;
    v58 = v56 + 9;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v56 + 9);
    }
    else
    {
      v59 = (unsigned __int8 *)v56 + 39;
      do
        v60 = __ldrex(v59);
      while ( __strex(v60 | 0x80, v59) );
      __dmb(0xBu);
      if ( v60 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v56 + 9);
      for ( i = *v58; (*v58 & 0xBFFFFFFF) != 0x80000000; i = *v58 )
      {
        if ( (i & 0x40000000) == 0 )
        {
          do
            v62 = __ldrex(v58);
          while ( v62 == i && __strex(i | 0x40000000, v58) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v90 )
    {
      v63 = *(_DWORD *)(v90 + 64) - 1;
      *(_DWORD *)(v90 + 64) = v63;
      if ( !v63 && !*(_DWORD *)(v90 + 60) && (*(_WORD *)(v91 + 18) & 1) == 0 && (*(_WORD *)(v90 + 18) & 8) != 0 )
      {
        MiRemoveUnusedSubsection(v90);
        MiInsertUnusedSubsection(v90, 1);
      }
    }
    v64 = v56[4] - 1;
    v56[4] = v64;
    if ( !v64 && !v56[5] && !v56[3] )
    {
      v65 = v56[7];
      if ( (v65 & 0x101) == 0 )
      {
        v56[7] = v65 | 1;
        MiClearFilePointer(v56);
        MiRemoveUnusedSegment(v56);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
        }
        else
        {
          do
            v66 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
          while ( __strex(v66 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
          __dmb(0xBu);
          if ( v66 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
          for ( j = dword_632D80; (dword_632D80 & 0xBFFFFFFF) != 0x80000000; j = dword_632D80 )
          {
            if ( (j & 0x40000000) == 0 )
            {
              do
                v68 = __ldrex((unsigned int *)&dword_632D80);
              while ( v68 == j && __strex(j | 0x40000000, (unsigned int *)&dword_632D80) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v69 = v95;
        v70 = (void **)dword_63FA24;
        v71 = v95 + 4;
        *(_DWORD *)(v95 + 4) = &unk_63FA20;
        *(_DWORD *)(v71 + 4) = v70;
        if ( *v70 != &unk_63FA20 )
          __fastfail(3u);
        *v70 = (void *)v71;
        dword_63FA24 = v71;
        *(_DWORD *)(v69 + 28) |= v94;
        v72 = dword_682604;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
        }
        else
        {
          __dmb(0xBu);
          dword_632D80 = 0;
        }
        KeReleaseSemaphoreEx((int)&unk_63FA0C, 0, 1, v72, 0);
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v58);
    }
    else
    {
      __dmb(0xBu);
      *v58 = 0;
    }
  }
  v73 = (unsigned __int8 *)(v34 + 15);
  do
    v74 = __ldrex(v73);
  while ( __strex(v74 | 0x80, v73) );
  __dmb(0xBu);
  if ( v74 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v75 = *(_DWORD *)(v34 + 12);
        __dmb(0xBu);
      }
      while ( (v75 & 0x80000000) != 0 );
      do
        v76 = __ldrex(v73);
      while ( __strex(v76 | 0x80, v73) );
      __dmb(0xBu);
    }
    while ( v76 >> 7 );
  }
  if ( (*(_BYTE *)(v34 + 18) & 7) != 6 )
    MiBadShareCount(v34);
  v77 = *(_DWORD *)(v34 + 12);
  *(_DWORD *)(v34 + 12) = v77 & 0xC0000000 | ((v77 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
  if ( (v77 & 0x3FFFFFFF) == 1 )
    MiPfnShareCountIsZero(v34, 0);
  __dmb(0xBu);
  v78 = (unsigned int *)(v34 + 12);
  do
    result = __ldrex(v78);
  while ( __strex(result & 0x7FFFFFFF, v78) );
  *(_DWORD *)(a1 + 8) &= 0xFFFFFC1F;
  *(_DWORD *)(a1 + 20) &= 0xF8FFFFFF;
  v80 = *(_BYTE *)(a1 + 19);
  if ( (v93[0] & 2) != 0 )
  {
    *(_BYTE *)(a1 + 19) = v80 & 0xF8;
    return result;
  }
  if ( (*(_BYTE *)(a1 + 19) & 8) != 0 )
    v81 = 5;
  else
    v81 = v80 & 7;
  v82 = (unsigned int *)((char *)&unk_6400B4 + 4 * v81);
  do
    v83 = __ldrex(v82);
  while ( __strex(v83 + 1, v82) );
  *(_BYTE *)(a1 + 19) &= 0xF8u;
  if ( dword_6346A0 )
  {
    KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634500, v92);
    v84 = (_DWORD *)dword_6346A0;
    if ( !dword_6346A0 )
      goto LABEL_157;
    v85 = *(_DWORD *)(dword_6346A0 + 32) & 0xFFF;
    if ( v85 )
    {
      **(_DWORD **)(dword_6346A0 + 32) = (a1 - MmPfnDatabase) / 24;
      v86 = v84[8] + 4;
      v84[8] = v86;
      v85 = v86 & 0xFFF;
    }
    if ( v85 < 0xC00 )
    {
      if ( v85 )
      {
        v84 = 0;
      }
      else
      {
        KeQueryTickCount(v93);
        v84[6] = v93[0];
        v84[7] = v93[1];
      }
    }
    else
    {
LABEL_157:
      v84 = (_DWORD *)dword_634484;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseQueuedSpinLockInstrumented(v92);
    }
    else
    {
      v87 = v92[0];
      if ( !v92[0] )
      {
        v88 = (unsigned int *)v92[1];
        __dmb(0xBu);
        do
          result = __ldrex(v88);
        while ( (int *)result == v92 && __strex(0, v88) );
        if ( (int *)result == v92 )
          goto LABEL_170;
        v87 = KxWaitForLockChainValid(v92);
      }
      v92[0] = 0;
      __dmb(0xBu);
      v89 = (unsigned int *)(v87 + 4);
      do
        result = __ldrex(v89);
      while ( __strex(result ^ 1, v89) );
    }
  }
  else
  {
    v84 = (_DWORD *)dword_634484;
  }
LABEL_170:
  if ( v84 )
    result = KiInsertQueueDpc(&byte_6346A4);
  return result;
}
