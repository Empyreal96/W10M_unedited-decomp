// CcUnmapVacbArray 
 
int __fastcall CcUnmapVacbArray(int a1, unsigned int *a2, unsigned int a3, int a4, unsigned __int8 a5)
{
  unsigned int v7; // r5
  int v8; // r6
  int v10; // r3
  unsigned __int8 *v11; // r9
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r10
  int v16; // r8
  int v17; // r1
  __int64 v18; // r2
  int v19; // r4
  int v20; // r6
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  unsigned int v24; // r8
  int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  int v28; // r10
  int v29; // r0
  int v30; // r8
  unsigned int v31; // r2
  int v32; // r0
  int v33; // r8
  unsigned int v34; // r3
  unsigned int v35; // kr10_4
  unsigned int *v36; // r4
  int v37; // r5
  unsigned int v38; // r1
  unsigned __int8 *v39; // r9
  int v40; // r4
  int v41; // r10
  unsigned int v42; // r2
  unsigned int v43; // r3
  unsigned int *v44; // r8
  int v45; // r10
  unsigned int v46; // r1
  unsigned __int8 *v47; // r10
  int v48; // r8
  int v49; // r1
  unsigned int v50; // r2
  int v51; // r0
  unsigned int v52; // r8
  unsigned int *v53; // r2
  unsigned int v54; // r1
  int v55; // r1
  unsigned int v56; // r0
  unsigned int v57; // r2
  unsigned int *v58; // r4
  int v59; // r10
  unsigned int v60; // r1
  unsigned __int8 *v61; // r8
  int v62; // r4
  int v63; // r10
  unsigned int v64; // r2
  unsigned int v65; // r3
  int v66; // r0
  int v67; // r4
  unsigned int v68; // r2
  int v69; // [sp+8h] [bp-38h]
  int v70; // [sp+Ch] [bp-34h]
  int v71; // [sp+10h] [bp-30h]
  int v72; // [sp+14h] [bp-2Ch]
  unsigned int v73; // [sp+18h] [bp-28h]
  int v74; // [sp+1Ch] [bp-24h]

  v70 = 0;
  v71 = 0;
  v7 = 0;
  v8 = 0;
  v72 = 1;
  if ( !*(_DWORD *)(a1 + 64) )
    return sub_53DBB4();
  if ( a2 )
  {
    v8 = a2[1];
    v34 = *a2;
    v7 = *a2 & 0xFFFC0000;
    if ( a3 )
    {
      v35 = v34 + a3;
      v10 = (__PAIR64__(v8, v34) + a3) >> 32;
      v73 = v35;
    }
    else
    {
      v73 = *(_DWORD *)(a1 + 240);
      v10 = *(_DWORD *)(a1 + 244);
    }
  }
  else
  {
    v73 = *(_DWORD *)(a1 + 24);
    v10 = *(_DWORD *)(a1 + 28);
  }
  v69 = v10;
  if ( (*(_DWORD *)(a1 + 96) & 0x200) != 0 )
  {
    v39 = (unsigned __int8 *)(a1 + 180);
    v71 = 1;
    v40 = KeAbPreAcquire(a1 + 180, 0, 0);
    v41 = KfRaiseIrql(1);
    do
      v42 = __ldrex(v39);
    while ( __strex(v42 & 0xFE, v39) );
    __dmb(0xBu);
    if ( (v42 & 1) == 0 )
      ExpAcquireFastMutexContended(a1 + 180, v40);
    if ( v40 )
      *(_BYTE *)(v40 + 14) |= 1u;
    v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a1 + 208) = v41;
    *(_DWORD *)(a1 + 184) = v43;
  }
  v11 = (unsigned __int8 *)(a1 + 72);
  v12 = KeAbPreAcquire(a1 + 72, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( __strex(v14 | 1, v11) );
  __dmb(0xBu);
  if ( (v14 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 72, v12, a1 + 72);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  v15 = v69;
  if ( a4 )
  {
    v16 = 1;
    v70 = 1;
    *(_DWORD *)(a1 + 216) = v73;
    *(_DWORD *)(a1 + 220) = v69;
  }
  else
  {
    v16 = 0;
  }
  if ( v8 > v69 || v8 >= v69 && v7 >= v73 )
  {
LABEL_26:
    v20 = 1;
    goto LABEL_27;
  }
  v17 = a5;
  while ( 1 )
  {
    v18 = *(_QWORD *)(a1 + 24);
    if ( __SPAIR64__(v8, v7) < v18 )
    {
      if ( v18 > 0x2000000 )
      {
        v51 = CcGetVacbLargeOffset(a1, v17, v7, v8);
        v17 = a5;
        v19 = v51;
      }
      else
      {
        v19 = *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4 * (v7 >> 18));
      }
      if ( v19 )
        break;
    }
LABEL_22:
    v8 = (__PAIR64__(v8, v7) + 0x40000) >> 32;
    v7 += 0x40000;
LABEL_23:
    v16 = v70;
    if ( v8 >= v15 && (v8 > v15 || v7 >= v73) )
      goto LABEL_26;
  }
  if ( !*(_WORD *)(v19 + 8) )
  {
    v72 = 1;
    SetVacb(a1, v17, v7, v8, 0);
    if ( CcNumberOfFreeHighPriorityVacbs < (unsigned int)CcMinimumFreeHighPriorityVacbs )
      v24 = v16 | 2;
    else
      v24 = v16 & 0xFFFFFFFD;
    v70 = v24;
    MmPropagateDirtyBitsToPfn(*(_DWORD *)v19);
    __pld(v11);
    v25 = *(_DWORD *)v11;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) > 0x10 )
      v26 = v25 - 16;
    else
      v26 = 0;
    if ( (v25 & 2) != 0 )
      goto LABEL_89;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)v11);
    while ( v27 == v25 && __strex(v26, (unsigned int *)v11) );
    if ( v27 != v25 )
LABEL_89:
      ExfReleasePushLock(a1 + 72);
    KeAbPostRelease(a1 + 72);
    v28 = v71;
    if ( v71 )
    {
      v44 = (unsigned int *)(a1 + 180);
      v45 = *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 184) = 0;
      __dmb(0xBu);
      do
        v46 = __ldrex(v44);
      while ( !v46 && __strex(1u, v44) );
      if ( v46 )
        ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v46);
      KfLowerIrql((unsigned __int8)v45);
      KeAbPostRelease(a1 + 180);
      v24 = v70;
      v28 = v71;
    }
    if ( *(_WORD *)(v19 + 8) )
      KeBugCheckEx(52, 3195, -1073740768);
    CcUnmapVacb(v19, a1, v24);
    if ( v28 )
    {
      v47 = (unsigned __int8 *)(a1 + 180);
      v48 = KeAbPreAcquire(a1 + 180, 0, 0);
      v49 = KfRaiseIrql(1);
      v74 = v49;
      do
        v50 = __ldrex(v47);
      while ( __strex(v50 & 0xFE, v47) );
      __dmb(0xBu);
      if ( (v50 & 1) == 0 )
      {
        ExpAcquireFastMutexContended(a1 + 180, v48);
        v49 = v74;
      }
      if ( v48 )
        *(_BYTE *)(v48 + 14) |= 1u;
      *(_DWORD *)(a1 + 184) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(a1 + 208) = v49;
    }
    v29 = KeAbPreAcquire(a1 + 72, 0, 0);
    v30 = v29;
    do
      v31 = __ldrex(v11);
    while ( __strex(v31 | 1, v11) );
    __dmb(0xBu);
    if ( (v31 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 72, v29, a1 + 72);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    v32 = KeAcquireQueuedSpinLock(4);
    *(_DWORD *)(v19 + 4) = 0;
    v33 = v32;
    CcSetVacbInFreeList(v19, (v70 & 2) != 0);
    KeReleaseQueuedSpinLock(4, v33);
    v15 = v69;
    v17 = a5;
    goto LABEL_22;
  }
  if ( v17 )
  {
    v52 = *(_DWORD *)(a1 + 116);
    if ( v52 )
    {
      if ( v72 )
      {
        KeResetEvent(*(_DWORD *)(a1 + 116));
        __dmb(0xFu);
        v72 = 0;
      }
      else
      {
        __pld(v11);
        v55 = *(_DWORD *)v11;
        if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
          v56 = 0;
        else
          v56 = v55 - 16;
        if ( (v55 & 2) != 0 )
          goto LABEL_108;
        __dmb(0xBu);
        do
          v57 = __ldrex((unsigned int *)v11);
        while ( v57 == v55 && __strex(v56, (unsigned int *)v11) );
        if ( v57 != v55 )
LABEL_108:
          ExfReleasePushLock(a1 + 72);
        KeAbPostRelease(a1 + 72);
        if ( v71 )
        {
          v58 = (unsigned int *)(a1 + 180);
          v59 = *(_DWORD *)(a1 + 208);
          *(_DWORD *)(a1 + 184) = 0;
          __dmb(0xBu);
          do
            v60 = __ldrex(v58);
          while ( !v60 && __strex(1u, v58) );
          if ( v60 )
            ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v60);
          KfLowerIrql((unsigned __int8)v59);
          KeAbPostRelease(a1 + 180);
          v15 = v69;
        }
        KeWaitForSingleObject(v52, 0, 0, 0, 0);
        v72 = 1;
        if ( v71 )
        {
          v61 = (unsigned __int8 *)(a1 + 180);
          v62 = KeAbPreAcquire(a1 + 180, 0, 0);
          v63 = KfRaiseIrql(1);
          do
            v64 = __ldrex(v61);
          while ( __strex(v64 & 0xFE, v61) );
          __dmb(0xBu);
          if ( (v64 & 1) == 0 )
            ExpAcquireFastMutexContended(a1 + 180, v62);
          if ( v62 )
            *(_BYTE *)(v62 + 14) |= 1u;
          v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(a1 + 208) = v63;
          v15 = v69;
          *(_DWORD *)(a1 + 184) = v65;
        }
        v66 = KeAbPreAcquire(a1 + 72, 0, 0);
        v67 = v66;
        do
          v68 = __ldrex(v11);
        while ( __strex(v68 | 1, v11) );
        __dmb(0xBu);
        if ( (v68 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(a1 + 72, v66, a1 + 72);
        if ( v67 )
          *(_BYTE *)(v67 + 14) |= 1u;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 224) = 0;
      *(_BYTE *)(a1 + 225) = 0;
      *(_DWORD *)(a1 + 228) = 0;
      *(_BYTE *)(a1 + 226) = 4;
      *(_DWORD *)(a1 + 232) = a1 + 232;
      *(_DWORD *)(a1 + 236) = a1 + 232;
      __dmb(0xBu);
      v53 = (unsigned int *)(a1 + 116);
      do
        v54 = __ldrex(v53);
      while ( __strex(a1 + 224, v53) );
      __dmb(0xBu);
      v72 = 0;
    }
    v17 = a5;
    goto LABEL_23;
  }
  v20 = 0;
LABEL_27:
  __pld(v11);
  v21 = *(_DWORD *)v11;
  if ( (*(_DWORD *)v11 & 0xFFFFFFF0) > 0x10 )
    v22 = v21 - 16;
  else
    v22 = 0;
  if ( (v21 & 2) != 0 )
    goto LABEL_91;
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)v11);
  while ( v23 == v21 && __strex(v22, (unsigned int *)v11) );
  if ( v23 != v21 )
LABEL_91:
    ExfReleasePushLock(a1 + 72);
  KeAbPostRelease(a1 + 72);
  if ( v71 )
  {
    v36 = (unsigned int *)(a1 + 180);
    v37 = *(_DWORD *)(a1 + 208);
    *(_DWORD *)(a1 + 184) = 0;
    __dmb(0xBu);
    do
      v38 = __ldrex(v36);
    while ( !v38 && __strex(1u, v36) );
    if ( v38 )
      ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v38);
    KfLowerIrql((unsigned __int8)v37);
    KeAbPostRelease(a1 + 180);
  }
  return v20;
}
