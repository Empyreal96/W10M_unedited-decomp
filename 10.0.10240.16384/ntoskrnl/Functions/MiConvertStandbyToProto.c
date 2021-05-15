// MiConvertStandbyToProto 
 
int __fastcall MiConvertStandbyToProto(int a1, __int16 **a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  unsigned int v9; // r8
  int v10; // r10
  int v11; // r4
  unsigned int v12; // r6
  unsigned __int8 *v13; // r1
  unsigned int v14; // r2
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r3
  unsigned int v19; // r2
  __int16 v20; // r3
  unsigned __int8 *v21; // r1
  unsigned int v22; // r2
  int v23; // r3
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned __int8 *v26; // r1
  unsigned int v27; // r2
  int v28; // r3
  char v29; // r2
  int v30; // r3
  int v31; // r0
  unsigned int v32; // r5
  int v33; // r0
  int v34; // r5
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r3
  unsigned int *v38; // r2
  unsigned int v39; // r0
  unsigned int v40; // r0
  unsigned int *v41; // r2
  unsigned int v42; // r4
  unsigned int v43; // r5
  int v44; // r3
  int v45; // r0
  int v46; // r5
  unsigned __int8 *v47; // r3
  unsigned int v48; // r1
  int v49; // r0
  int v50; // r6
  int v51; // r8
  unsigned int *v52; // r2
  unsigned int v53; // r0
  unsigned int *v54; // r2
  unsigned int v55; // r0
  int v56; // r1
  unsigned int *v57; // r2
  unsigned int v58; // r0
  unsigned int v59; // r5
  int v60; // r6
  int v61; // r3
  int v62; // r0
  int v63; // r5
  unsigned __int8 *v64; // r1
  unsigned int v65; // r2
  int v66; // r3
  unsigned int v67; // r2
  int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned int *v71; // r2
  unsigned int v72; // r0
  unsigned int *v73; // r2
  unsigned int v74; // r0
  unsigned int *v76; // r2
  unsigned int v77; // r0
  unsigned int *v78; // r2
  unsigned int v79; // r0
  unsigned int v80; // [sp+Ch] [bp-4Ch]
  int v81; // [sp+10h] [bp-48h]
  int v82; // [sp+14h] [bp-44h]
  int v83; // [sp+1Ch] [bp-3Ch]
  int v84; // [sp+1Ch] [bp-3Ch]
  int v85; // [sp+20h] [bp-38h]
  int v86; // [sp+28h] [bp-30h]
  int v87; // [sp+28h] [bp-30h]
  int *v88; // [sp+2Ch] [bp-2Ch]
  int v89; // [sp+2Ch] [bp-2Ch]
  __int16 *v90; // [sp+30h] [bp-28h]
  int v91; // [sp+34h] [bp-24h]
  int v92; // [sp+34h] [bp-24h]
  __int16 **varg_r1; // [sp+64h] [bp+Ch]

  varg_r1 = a2;
  v7 = a3;
  v83 = a3;
  v81 = a1;
  v90 = *a2;
  v9 = a4 + 32;
  v88 = (int *)(a4 + 32);
  v10 = *(_DWORD *)(a4 + 28);
  v80 = (a4 + 32) & 0x1FC | (4 * ((a4 + 32) & 0xFFFFFE00 | 0x100));
  v86 = *(_DWORD *)(a3 + 28);
  if ( a7 != -1 )
  {
    v84 = MmPfnDatabase + 24 * a7;
    v11 = a5;
    if ( MiFillCombinePage(v84, v84, a5, *(_DWORD *)(a3 + 28) << 10) )
    {
      v82 = 32 * (v10 & 0x1F | (a7 << 7) | 0x40);
      v12 = 0;
      v87 = *(_DWORD *)(((v9 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
      v85 = MmPfnDatabase + 24 * v87;
      v13 = (unsigned __int8 *)(a5 + 15);
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
          v15 = *(_DWORD *)(a5 + 12);
          __dmb(0xBu);
        }
        while ( (v15 & 0x80000000) != 0 );
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 | 0x80, v13) );
      }
      if ( (**(_DWORD **)(v7 + 28) & 2) == 0
        || a6 != (*(_DWORD *)(a5 + 4) | 0x80000000)
        || !MiRecheckCombineVm(a2, a5, v81)
        || ((*(_DWORD *)(a5 + 8) >> 5) & 0x1F) != v10 )
      {
        goto LABEL_10;
      }
      if ( !MiUnlinkPageFromList(a5, 0) )
        goto LABEL_17;
      if ( (*(_BYTE *)(a5 + 18) & 0x10) == 0 )
      {
        v18 = *(_DWORD *)(a5 + 8);
        if ( (v18 & 2) == 0 && (v18 & 0x400) == 0 && (v18 & 0x800) == 0 && (v18 & 0x10) == 0 )
          *(_BYTE *)(a5 + 18) |= 0x10u;
      }
      v19 = *(_DWORD *)(a5 + 8);
      if ( (v19 & 8) != 0 )
      {
        v20 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v19 >> 2) & 1) + 1800] + 96);
        if ( (v20 & 0x10) != 0 || (v20 & 0x20) != 0 && (v19 & 8) != 0 )
        {
          v12 = *(_DWORD *)(a5 + 8);
          if ( (v12 & 0x10) != 0 )
          {
            *(_DWORD *)(a5 + 8) = v12 & 0xFFFFFFEF;
          }
          else if ( (v12 & 8) == 0 )
          {
            v12 = 0;
          }
          *(_BYTE *)(a5 + 18) |= 0x10u;
        }
        else
        {
          v12 = *(_DWORD *)(a5 + 8);
        }
        *(_DWORD *)(a5 + 8) &= 0xFFFFFFF7;
      }
      v21 = (unsigned __int8 *)(v85 + 15);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v22 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v23 = *(_DWORD *)(v85 + 12);
          __dmb(0xBu);
        }
        while ( (v23 & 0x80000000) != 0 );
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 | 0x80, v21) );
      }
      *(_DWORD *)(v85 + 12) = *(_DWORD *)(v85 + 12) & 0xC0000000 | (*(_DWORD *)(v85 + 12) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v24 = (unsigned int *)(v85 + 12);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0x7FFFFFFF, v24) );
      v26 = (unsigned __int8 *)(v84 + 15);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 | 0x80, v26) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v27 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v28 = *(_DWORD *)(v84 + 12);
          __dmb(0xBu);
        }
        while ( (v28 & 0x80000000) != 0 );
        do
          v27 = __ldrex(v26);
        while ( __strex(v27 | 0x80, v26) );
      }
      MiFinalizePageAttribute(v84, *(unsigned __int8 *)(a5 + 18) >> 6, 1);
      MiCopyPfnEntry(v84, (int *)a5);
      v29 = *(_BYTE *)(v84 + 19);
      if ( (v29 & 8) == 0 && (v29 & 7u) < 5 )
        *(_BYTE *)(v84 + 19) = v29 & 0xF8 | 5;
      *(_DWORD *)(v84 + 4) = v9 & 0x7FFFFFFF;
      *(_DWORD *)(v84 + 20) = *(_DWORD *)(v84 + 20) & 0xFFF00000 | v87 | 0x8000000;
      *(_DWORD *)(v84 + 12) &= 0xC0000000;
      v30 = *(_DWORD *)(v84 + 8);
      if ( (v30 & 0x80) != 0 )
        *(_DWORD *)(v84 + 8) = v30 | 0x20;
      *v88 = 0;
      if ( (unsigned int)(v88 + 0x10000000) > 0x3FFFFF )
      {
        *v88 = v82;
      }
      else
      {
        __dmb(0xBu);
        *v88 = v82;
        if ( (unsigned int)(v88 + 267649024) <= 0xFFF )
        {
          v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v31, (_DWORD *)(v31 + 4 * ((unsigned __int16)v88 & 0xFFF)), v82);
        }
      }
      v89 = *(_DWORD *)(a5 + 20) & 0xFFFFF;
      v32 = (*(_DWORD *)(a5 + 4) & 0xFFF) + MiMapPageInHyperSpaceWorker(v89, 0, 0x80000000);
      if ( v32 < 0xC0000000 || v32 > 0xC03FFFFF )
      {
        *(_DWORD *)v32 = v80;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v32 = v80;
        if ( v32 + 1070596096 <= 0xFFF )
        {
          v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * (v32 & 0xFFF)), v80);
        }
      }
      MiUnmapPageInHyperSpaceWorker(v32, 17, 0x80000000);
      *(_DWORD *)(a5 + 12) |= 0x40000000u;
      v34 = v84;
      MiPfnReferenceCountIsZero(v84, a7);
      __dmb(0xBu);
      v35 = (unsigned int *)(v34 + 12);
      do
        v36 = __ldrex(v35);
      while ( __strex(v36 & 0x7FFFFFFF, v35) );
      v37 = *(_DWORD *)(a5 + 8);
      if ( (v37 & 0x10) != 0 )
      {
        *(_DWORD *)(a5 + 8) = v37 & 0xFFFFFFEF;
        if ( v12 )
          v12 &= 0xFFFFFFEF;
      }
      *(_DWORD *)(a5 + 12) &= 0xC0000000;
      MiPfnReferenceCountIsZero(a5, (a5 - MmPfnDatabase) / 24);
      __dmb(0xBu);
      v38 = (unsigned int *)(a5 + 12);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 & 0x7FFFFFFF, v38) );
      if ( v90 == MiSystemPartition )
      {
        MiReturnResidentAvailable(1);
        do
          v40 = __ldrex(&dword_634A2C[39]);
        while ( __strex(v40 + 1, &dword_634A2C[39]) );
      }
      else
      {
        v41 = (unsigned int *)(v90 + 1920);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 + 1, v41) );
      }
      MiReturnCommit((int)v90, 1);
      do
        v43 = __ldrex((unsigned int *)&dword_634D94);
      while ( __strex(v43 - 1, (unsigned int *)&dword_634D94) );
      MiLockAndDecrementShareCount(MmPfnDatabase + 24 * v89, 0);
      if ( v12 )
        MiReleasePageFileInfo((int)MiSystemPartition, v12, 1, v44);
      goto LABEL_133;
    }
    return 0;
  }
  v45 = MiLockProtoPoolPage(v9, 0);
  v46 = v45;
  if ( !v45 )
    return 0;
  v11 = a5;
  v47 = (unsigned __int8 *)(a5 + 15);
  do
    v48 = __ldrex(v47);
  while ( __strex(v48 | 0x80, v47) );
  __dmb(0xBu);
  if ( v48 >> 7 )
  {
    MiUnlockProtoPoolPage(v45, 17);
    return 0;
  }
  if ( a6 != (*(_DWORD *)(a5 + 4) | 0x80000000)
    || !MiRecheckCombineVm(a2, a5, v81)
    || (v49 = MiTryLockLeafPage((unsigned int *)v9, 1), (v50 = v49) == 0) )
  {
LABEL_88:
    MiUnlockNestedProtoPoolPage(v46);
LABEL_10:
    __dmb(0xBu);
    v16 = (unsigned int *)(v11 + 12);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 & 0x7FFFFFFF, v16) );
    return 0;
  }
  if ( (*(_BYTE *)(v49 + 19) & 0x40) != 0 || (*(_BYTE *)(v49 + 18) & 7) != 6 && (*(_BYTE *)(v49 + 18) & 0x20) != 0 )
  {
    __dmb(0xBu);
    v76 = (unsigned int *)(v49 + 12);
    do
      v77 = __ldrex(v76);
    while ( __strex(v77 & 0x7FFFFFFF, v76) );
    MiUnlockNestedProtoPoolPage(v46);
    __dmb(0xBu);
    v78 = (unsigned int *)(a5 + 12);
    do
      v79 = __ldrex(v78);
    while ( __strex(v79 & 0x7FFFFFFF, v78) );
    return 0;
  }
  v91 = MiMapPageInHyperSpaceWorker((v49 - MmPfnDatabase) / 24, 0, 0x80000000);
  v51 = MiComparePages(v91, v86 << 10);
  MiUnmapPageInHyperSpaceWorker(v91, 17, 0x80000000);
  if ( !v51 || (**(_DWORD **)(v83 + 28) & 2) == 0 || ((*(_DWORD *)(a5 + 8) >> 5) & 0x1F) != v10 )
  {
    __dmb(0xBu);
    v52 = (unsigned int *)(v50 + 12);
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 & 0x7FFFFFFF, v52) );
    goto LABEL_88;
  }
  if ( !MiUnlinkPageFromList(a5, 0) )
  {
    __dmb(0xBu);
    v54 = (unsigned int *)(v50 + 12);
    do
      v55 = __ldrex(v54);
    while ( __strex(v55 & 0x7FFFFFFF, v54) );
    MiUnlockNestedProtoPoolPage(v46);
LABEL_17:
    MiDiscardTransitionPte(v11);
    goto LABEL_10;
  }
  *(_DWORD *)(a5 + 12) &= 0xC0000000;
  if ( (*(_BYTE *)(a5 + 19) & 8) != 0 )
    v56 = 5;
  else
    v56 = *(_BYTE *)(a5 + 19) & 7;
  MiUpdatePfnPriority(v50, v56, 0);
  __dmb(0xBu);
  v57 = (unsigned int *)(v50 + 12);
  do
    v58 = __ldrex(v57);
  while ( __strex(v58 & 0x7FFFFFFF, v57) );
  MiUnlockNestedProtoPoolPage(v46);
  v92 = *(_DWORD *)(a5 + 20) & 0xFFFFF;
  v59 = (*(_DWORD *)(a5 + 4) & 0xFFF) + MiMapPageInHyperSpaceWorker(v92, 0, 0x80000000);
  if ( v59 < 0xC0000000 || v59 > 0xC03FFFFF )
  {
    *(_DWORD *)v59 = v80;
  }
  else
  {
    v60 = 0;
    v61 = *(_DWORD *)v59;
    __dmb(0xBu);
    *(_DWORD *)v59 = v80;
    if ( (v61 & 2) == 0 && (v80 & 2) != 0 )
      v60 = 1;
    if ( v59 + 1070596096 <= 0xFFF )
    {
      v62 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v62, (_DWORD *)(v62 + 4 * (v59 & 0xFFF)), v80);
    }
    if ( v60 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  MiUnmapPageInHyperSpaceWorker(v59, 17, 0x80000000);
  *(_DWORD *)(a5 + 12) |= 0x40000000u;
  MiPfnReferenceCountIsZero(a5, (a5 - MmPfnDatabase) / 24);
  v63 = MmPfnDatabase + 24 * v92;
  v64 = (unsigned __int8 *)(v63 + 15);
  do
    v65 = __ldrex(v64);
  while ( __strex(v65 | 0x80, v64) );
  __dmb(0xBu);
  if ( v65 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v66 = *(_DWORD *)(v63 + 12);
        __dmb(0xBu);
      }
      while ( (v66 & 0x80000000) != 0 );
      do
        v67 = __ldrex(v64);
      while ( __strex(v67 | 0x80, v64) );
      __dmb(0xBu);
    }
    while ( v67 >> 7 );
  }
  v68 = *(_DWORD *)(v63 + 12);
  if ( (*(_BYTE *)(v63 + 18) & 7) != 6 )
    KeBugCheckEx(78, 153, (v63 - MmPfnDatabase) / 24);
  *(_DWORD *)(v63 + 12) = v68 & 0xC0000000 | ((v68 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
  if ( (v68 & 0x3FFFFFFF) == 1 )
    MiPfnShareCountIsZero(v63, 0);
  __dmb(0xBu);
  v69 = (unsigned int *)(v63 + 12);
  do
    v70 = __ldrex(v69);
  while ( __strex(v70 & 0x7FFFFFFF, v69) );
  __dmb(0xBu);
  v71 = (unsigned int *)(a5 + 12);
  do
    v72 = __ldrex(v71);
  while ( __strex(v72 & 0x7FFFFFFF, v71) );
LABEL_133:
  if ( (*(_BYTE *)(v81 + 112) & 7) == 0 )
  {
    v73 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 276);
    do
      v74 = __ldrex(v73);
    while ( __strex(v74 - 1, v73) );
  }
  return 1;
}
