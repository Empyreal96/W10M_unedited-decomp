// MiDeleteVad 
 
unsigned int *__fastcall MiDeleteVad(int a1, int a2)
{
  unsigned int v4; // r0
  __int64 v5; // kr00_8
  int v6; // lr
  int v7; // r1
  unsigned int *v8; // r6
  unsigned int *result; // r0
  int v10; // r8
  int v11; // r9
  unsigned int *v12; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // lr
  unsigned int v17; // r3
  int v18; // r2
  char v19; // r2
  int v20; // r8
  int v21; // r2
  int v22; // r7
  unsigned __int8 *v23; // r5
  int v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // r2
  unsigned int j; // r7
  int v28; // r2
  unsigned int k; // r5
  unsigned int v30; // r2
  unsigned int *v31; // r8
  unsigned int v32; // r1
  int v33; // r0
  int v34; // r3
  unsigned int *v35; // r4
  int v36; // r5
  unsigned __int8 *v37; // r3
  unsigned int v38; // r1
  unsigned int v39; // r0
  unsigned int i; // r3
  _DWORD *v41; // r3
  char v42; // r2
  int v43; // r3
  int v44; // r0
  int v45; // r3
  int v46; // r3
  int v47; // r5
  unsigned __int8 *v48; // r3
  unsigned int v49; // r1
  unsigned int v50; // r0
  unsigned int **v51; // r3
  unsigned int *v52; // r2
  unsigned int v53; // r1
  unsigned int v54; // r1
  unsigned int v55; // r1
  unsigned int v56; // r1
  int v57; // r0
  int v58; // r2
  int v59; // r5
  unsigned int v60; // r4
  int v61; // [sp+8h] [bp-70h]
  int v62; // [sp+Ch] [bp-6Ch]
  unsigned int v63; // [sp+10h] [bp-68h]
  unsigned int *v64; // [sp+14h] [bp-64h]
  int v65; // [sp+18h] [bp-60h]
  int v66; // [sp+1Ch] [bp-5Ch]
  int v67; // [sp+20h] [bp-58h]
  unsigned int *v68; // [sp+24h] [bp-54h] BYREF
  int v69; // [sp+28h] [bp-50h]
  int v70; // [sp+2Ch] [bp-4Ch]
  int v71; // [sp+30h] [bp-48h] BYREF
  int v72; // [sp+34h] [bp-44h]
  int v73; // [sp+38h] [bp-40h]
  int v74; // [sp+3Ch] [bp-3Ch]
  unsigned int *v75; // [sp+40h] [bp-38h] BYREF
  unsigned int *v76; // [sp+44h] [bp-34h]
  int v77; // [sp+48h] [bp-30h]
  unsigned int *v78; // [sp+4Ch] [bp-2Ch]
  int v79; // [sp+50h] [bp-28h]
  int v80; // [sp+54h] [bp-24h]

  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v78 = 0;
  v75 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v76 = 0;
  v77 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v79 = 0;
  v80 = 0;
  v70 = 0;
  v5 = *(_QWORD *)(a1 + 12);
  v6 = *(_DWORD *)(v4 + 116);
  v7 = *(_DWORD *)(a1 + 28);
  v69 = *(_DWORD *)(a1 + 12);
  v8 = 0;
  v66 = (HIDWORD(v5) << 12) | 0xFFF;
  v63 = v4;
  v61 = v6;
  if ( (v7 & 0x8000) == 0 && *(_DWORD *)(a1 + 72) )
    return (unsigned int *)sub_544218();
  v10 = a2 & 0x40000000;
  if ( (a2 & 0x40000000) == 0 )
  {
    v11 = v72;
    goto LABEL_6;
  }
  if ( (*(_DWORD *)(a1 + 28) & 0x8000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 28) & 7) == 5 )
    {
LABEL_136:
      v11 = MiFreeLargePageView(v6, a1, 1);
      v72 = v11;
      v4 = v63;
      goto LABEL_140;
    }
  }
  else if ( (*(_BYTE *)(a1 + 43) & 1) != 0 && (*(_DWORD *)(a1 + 28) & 7) == 2 )
  {
    goto LABEL_136;
  }
  v11 = v72;
LABEL_140:
  if ( v11 )
  {
    MiReturnCommit((int)MiSystemPartition, (*(_DWORD *)(a1 + 32) & 0x7FFFFFFF) - v11);
    v4 = v63;
    v11 = *(_DWORD *)(a1 + 32) & 0x7FFFFFFF;
    v72 = v11;
  }
LABEL_6:
  if ( (*(_DWORD *)(a1 + 28) & 7) == 3 )
  {
    MiAweViewRemover(v6, a1);
    MiRemoveUserPhysicalPagesVad(a1);
    v4 = v63;
  }
  --*(_WORD *)(v4 + 310);
  --*(_WORD *)(v4 + 310);
  v64 = (unsigned int *)(v6 + 492);
  v62 = KfRaiseIrql(2);
  v12 = (unsigned int *)(v6 + 492);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12);
  }
  else
  {
    v13 = (unsigned __int8 *)(v6 + 495);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v12);
    while ( 1 )
    {
      v15 = *v64;
      if ( (*v64 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v54 = __ldrex(v64);
        while ( v54 == v15 && __strex(v15 | 0x40000000, v64) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v16 = v62;
  v17 = *(_DWORD *)(a1 + 28) | 0x80000000;
  v18 = *(_BYTE *)(a1 + 28) & 7;
  *(_DWORD *)(a1 + 28) = v17;
  if ( (v17 & 7) == 3 )
  {
    MiDeletePageTablesForPhysicalRange(a1, v17);
    goto LABEL_91;
  }
  if ( (v17 & 0x8000) != 0 )
  {
    if ( v18 != 1 )
    {
      if ( !v10 )
      {
        if ( v18 == 5 )
        {
          v16 = v62;
          v65 = MiUnmapLargeUserPages(a1, v17);
        }
        v42 = 0;
        if ( (*(_DWORD *)(a1 + 28) & 7) == 6 )
          v42 = 8;
        MiDeleteVirtualAddresses(v69 << 12, v66, v42, v16, (int)&v71);
        v11 = v72;
      }
      goto LABEL_91;
    }
  }
  else if ( v18 != 1 )
  {
    v8 = **(unsigned int ***)(a1 + 44);
    if ( v18 != 2 )
    {
      if ( v8[8] )
      {
        v43 = (unsigned __int8)v17 >> 3;
        if ( v43 == 4 || v43 == 6 )
          v79 = 1;
        MiGetProtoPteAddress((_DWORD *)a1, *(_DWORD *)(a1 + 12), 1, &v68);
        MiGetProtoPteAddress((_DWORD *)a1, *(_DWORD *)(a1 + 16), 1, &v75);
        v78 = v75;
        v76 = v68;
      }
      goto LABEL_19;
    }
    if ( (*(_BYTE *)(a1 + 43) & 1) == 0 )
    {
LABEL_19:
      if ( (*(_DWORD *)(a1 + 28) & 7) == 7 )
      {
        v20 = v62;
        v65 = MiUnmapLargeUserPages(a1, 1);
      }
      else
      {
        v19 = 2;
        if ( (a2 & 0x80000000) != 0 )
          v19 = 3;
        if ( (a2 & 1) != 0 )
          v19 |= 4u;
        v20 = v62;
        MiDeleteVirtualAddresses(v69 << 12, v66, v19, v62, (int)&v71);
        if ( *(_DWORD *)(v61 + 500) )
        {
          MiEmptyPageAccessLog();
          *(_DWORD *)(v61 + 500) = 0;
        }
        v11 = v72;
      }
      if ( (*(_DWORD *)(a1 + 68) & 0x80000000) != 0 )
        v80 = 1;
      v21 = *(_DWORD *)(a1 + 28) & 7;
      if ( v21 == 2 && (v8[7] & 0x4000000) != 0 )
        v77 = 1;
      if ( *(_DWORD *)(a1 + 44) && v21 != 1 )
        v70 = 1;
      goto LABEL_33;
    }
    if ( !v10 )
      v65 = MiUnmapLargeUserPages(a1, 1);
    v70 = 1;
    v67 = 1;
LABEL_91:
    v20 = v62;
    goto LABEL_33;
  }
  v51 = *(unsigned int ***)(a1 + 44);
  if ( v51 )
    v8 = *v51;
  MiDeletePhysmemVad(a1);
  v20 = v62;
LABEL_33:
  v22 = 0;
  v23 = (unsigned __int8 *)(v61 + 252);
  v24 = KeAbPreAcquire(v61 + 252, 0, 1);
  do
    v25 = __ldrex(v23);
  while ( __strex(v25 | 1, v23) );
  __dmb(0xBu);
  if ( (v25 & 1) != 0 )
  {
    if ( !v24 )
      goto LABEL_102;
LABEL_148:
    KeAbPostReleaseEx(v23, v24);
LABEL_102:
    v44 = MiUnlockWorkingSetExclusive((int)v64, v20);
    v45 = (__int16)(*(_WORD *)(v63 + 310) + 1);
    *(_WORD *)(v63 + 310) = v45;
    if ( !v45 && *(_DWORD *)(v63 + 100) != v63 + 100 )
      v44 = KiCheckForKernelApcDelivery(v44);
    if ( !v22 )
    {
      v46 = (__int16)(*(_WORD *)(v63 + 310) + 1);
      *(_WORD *)(v63 + 310) = v46;
      if ( !v46 && *(_DWORD *)(v63 + 100) != v63 + 100 )
        KiCheckForKernelApcDelivery(v44);
      MiLockAddressSpaceToo(v61, a1);
    }
    LOCK_PAGE_TABLE_COMMITMENT(v63, v61);
    v47 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v64);
    }
    else
    {
      v48 = (unsigned __int8 *)v64 + 3;
      do
        v49 = __ldrex(v48);
      while ( __strex(v49 | 0x80, v48) );
      __dmb(0xBu);
      if ( v49 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v64);
      while ( 1 )
      {
        v50 = *v64;
        if ( (*v64 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v50 & 0x40000000) == 0 )
        {
          do
            v56 = __ldrex(v64);
          while ( v56 == v50 && __strex(v50 | 0x40000000, v64) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v20 = v47;
    goto LABEL_43;
  }
  if ( v24 )
    *(_BYTE *)(v24 + 14) |= 1u;
  v22 = 1;
  *(_BYTE *)(v63 + 968) |= 1u;
  v23 = (unsigned __int8 *)(v61 + 256);
  v24 = KeAbPreAcquire(v61 + 256, 0, 1);
  do
    v26 = __ldrex(v23);
  while ( __strex(v26 | 1, v23) );
  __dmb(0xBu);
  if ( (v26 & 1) != 0 )
  {
    if ( !v24 )
      goto LABEL_102;
    goto LABEL_148;
  }
  if ( v24 )
    *(_BYTE *)(v24 + 14) |= 1u;
LABEL_43:
  MiCaptureDeleteHierarchy(v69 << 12, v66, v20, &v68);
  j = *(_DWORD *)a1;
  v28 = a1;
  if ( *(_DWORD *)a1 )
  {
    for ( i = *(_DWORD *)(j + 4); i; i = *(_DWORD *)(i + 4) )
      j = i;
  }
  else
  {
    for ( j = *(_DWORD *)(a1 + 8) & 0xFFFFFFFC; j; j = *(_DWORD *)(j + 8) & 0xFFFFFFFC )
    {
      if ( *(_DWORD *)(j + 4) == v28 )
        break;
      v28 = j;
    }
  }
  k = *(_DWORD *)(a1 + 4);
  v30 = a1;
  if ( k )
  {
    v41 = *(_DWORD **)k;
    if ( *(_DWORD *)k )
    {
      do
      {
        k = (unsigned int)v41;
        v41 = (_DWORD *)*v41;
      }
      while ( v41 );
    }
  }
  else
  {
    for ( k = *(_DWORD *)(a1 + 8) & 0xFFFFFFFC; k; k = *(_DWORD *)(k + 8) & 0xFFFFFFFC )
    {
      if ( *(_DWORD *)k == v30 )
        break;
      v30 = k;
    }
  }
  MiRemoveVad(a1, v61);
  MiUnlockWorkingSetExclusive((int)v64, v20);
  v31 = (unsigned int *)(v61 + 256);
  __dmb(0xBu);
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 - 1, v31) );
  if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
    ExfTryToWakePushLock(v31);
  v33 = KeAbPostRelease((unsigned int)v31);
  v34 = (__int16)(*(_WORD *)(v63 + 310) + 1);
  *(_WORD *)(v63 + 310) = v34;
  if ( !v34 && *(_DWORD *)(v63 + 100) != v63 + 100 )
    KiCheckForKernelApcDelivery(v33);
  if ( v65 )
    v11 = *(_DWORD *)(a1 + 32) & 0x7FFFFFFF;
  *(_DWORD *)a1 = v73;
  *(_DWORD *)(a1 + 4) = v11;
  if ( v79 == 1 )
  {
    __dmb(0xBu);
    v52 = v8 + 13;
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 - 1, v52) );
  }
  if ( v80 == 1 )
    MiDereferenceExtendInfo(a1, v8);
  if ( v77 == 1 )
  {
    v57 = MmGetSessionIdEx(v61);
    MiDereferencePerSessionProtos(v8, v57, v58);
  }
  if ( v70 == 1 )
  {
    MiRemoveSharedCommitNode(v8, v61, 0);
    MiManageSubsectionView(*(_DWORD *)(a1 + 44), a1 + 56, 4);
  }
  result = (unsigned int *)MiFinishVadDeletion(a1, j, k, v69 << 12, v66, &v68);
  if ( v65 )
  {
    result = (unsigned int *)MiFreeLargePages(v65);
    v59 = (int)result;
    if ( result )
    {
      MiReturnCommit((int)MiSystemPartition, (int)result);
      result = MiReturnResidentAvailable(v59);
      do
        v60 = __ldrex(&dword_634A2C[40]);
      while ( __strex(v60 + v59, &dword_634A2C[40]) );
    }
  }
  if ( v67 == 1 )
    return (unsigned int *)MiDereferenceControlArea(v8);
  if ( v8 )
  {
    v35 = v8 + 9;
    v36 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8 + 9);
    }
    else
    {
      v37 = (unsigned __int8 *)v8 + 39;
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 0x80, v37) );
      __dmb(0xBu);
      if ( v38 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v8 + 9);
      while ( 1 )
      {
        v39 = *v35;
        if ( (*v35 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v39 & 0x40000000) == 0 )
        {
          do
            v55 = __ldrex(v35);
          while ( v55 == v39 && __strex(v39 | 0x40000000, v35) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v76 )
      MiDecrementSubsections((int)v76, (int)v78);
    --v8[5];
    --v8[6];
    result = (unsigned int *)MiCheckControlArea(v8, v36);
  }
  return result;
}
