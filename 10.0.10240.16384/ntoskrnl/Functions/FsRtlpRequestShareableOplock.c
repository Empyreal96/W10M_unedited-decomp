// FsRtlpRequestShareableOplock 
 
int __fastcall FsRtlpRequestShareableOplock(_DWORD **a1, int a2, int a3, int a4, _DWORD *a5, char a6, unsigned __int8 a7, int a8)
{
  int v11; // r10
  _DWORD *v12; // r4
  unsigned __int8 *v13; // r10
  int v14; // r0
  int v15; // r9
  unsigned int v16; // r2
  int v17; // r9
  _DWORD *v18; // r6
  int v19; // r0
  _DWORD *v20; // r1
  _DWORD *i; // r9
  _DWORD *v22; // r0
  int v23; // r2
  _DWORD *v24; // r9
  int v25; // r0
  _DWORD *v26; // r1
  int v27; // r3
  int v28; // lr
  int v29; // r2
  int v30; // r2
  int v31; // r3
  int **v32; // r10
  int v33; // r3
  int **v34; // r9
  _DWORD *l; // r9
  int v36; // r0
  _DWORD *v37; // r2
  int v38; // r0
  int v39; // r3
  int v40; // r2
  unsigned int *v41; // r1
  unsigned int v42; // r0
  int v43; // r3
  int v44; // r3
  int v45; // lr
  int v46; // r2
  _DWORD *v47; // r2
  _DWORD *v48; // r6
  _DWORD *k; // r6
  int v50; // r3
  int **j; // r6
  int *v52; // r1
  int v53; // r2
  int v54; // r0
  unsigned int *v55; // r1
  unsigned int v56; // r0
  unsigned int *v57; // r4
  unsigned int v58; // r1
  char v60; // [sp+10h] [bp-30h]
  int v61; // [sp+14h] [bp-2Ch]
  _DWORD *v63; // [sp+1Ch] [bp-24h] BYREF
  unsigned __int8 *v64; // [sp+20h] [bp-20h]
  _DWORD **varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v61 = 0;
  v64 = 0;
  v60 = 0;
  v11 = 0;
  v12 = *a1;
  if ( !*a1 )
  {
    v12 = (_DWORD *)FsRtlpAllocateOplock();
    *a1 = v12;
  }
  if ( !a7 && a4 != 0x10000 )
  {
    v64 = (unsigned __int8 *)v12[19];
    v13 = v64;
    v63 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v14 = KeAbPreAcquire(v64, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex(v64);
    while ( __strex(v16 & 0xFE, v64) );
    __dmb(0xBu);
    if ( (v16 & 1) == 0 )
      ExpAcquireFastMutexContended(v64, v14);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    *((_DWORD *)v13 + 1) = v63;
    v60 = 1;
    v11 = 0;
  }
  v17 = v12[18];
  if ( (v17 & 0x10000) != 0 && *(_BYTE *)a2 == 13 && FsRtlpCallerIsAtomicRequestor((int)v12, *(_DWORD *)(a2 + 28), &v63) )
  {
    if ( (v17 & 0x20000) != 0 )
    {
      v18 = v63;
      FsRtlpOplockDequeueRH(v63);
      v19 = v18[7];
      v20 = (_DWORD *)v18[8];
      if ( *(_DWORD **)(v19 + 4) != v18 + 7 || (_DWORD *)*v20 != v18 + 7 )
        __fastfail(3u);
      *v20 = v19;
      *(_DWORD *)(v19 + 4) = v20;
      if ( (_DWORD *)v12[15] == v12 + 15 )
        v12[18] &= 0xFFFCFFFF;
      if ( v18[5] )
        FsRtlpClearOwnerThread((int)v12, (int)v18);
      ExFreePoolWithTag(v18, 0);
      v63 = 0;
      FsRtlpComputeShareableOplockState(v12);
      goto LABEL_154;
    }
    for ( i = (_DWORD *)v12[11]; i != v12 + 11; i = (_DWORD *)*i )
    {
      v22 = i;
      v23 = *(_DWORD *)(i[2] + 96);
      if ( *(_BYTE *)v23 != 13 || *(_DWORD *)(v23 + 16) != 589844 || a4 != 12288 )
      {
        i = (_DWORD *)i[1];
        FsRtlpRemoveAndCompleteWaitingIrp(v22);
      }
    }
    v24 = v63;
    FsRtlpOplockDequeueRH(v63);
    v25 = v24[7];
    v26 = (_DWORD *)v24[8];
    if ( *(_DWORD **)(v25 + 4) != v24 + 7 || (_DWORD *)*v26 != v24 + 7 )
      __fastfail(3u);
    *v26 = v25;
    *(_DWORD *)(v25 + 4) = v26;
    if ( (_DWORD *)v12[15] == v12 + 15 )
      v12[18] &= 0xFFFCFFFF;
    if ( v24[5] )
      FsRtlpClearOwnerThread((int)v12, (int)v24);
    ExFreePoolWithTag(v24, 0);
    v63 = 0;
    FsRtlpComputeShareableOplockState(v12);
  }
  if ( !FsRtlpOplockUpperLowerCompatible(a4, a8) )
  {
    *(_DWORD *)(a3 + 24) = -1073741598;
LABEL_41:
    pIofCompleteRequest(a3, 1);
    goto LABEL_155;
  }
  if ( !a7 && (v12[18] & 0x40) != 0 )
  {
LABEL_44:
    if ( a4 == 0x10000 )
    {
      v27 = -1073739511;
LABEL_46:
      v61 = v27;
      goto LABEL_155;
    }
LABEL_154:
    *(_DWORD *)(a3 + 24) = -1073741598;
    pIofCompleteRequest(a3, 1);
    v61 = -1073741598;
    goto LABEL_155;
  }
  if ( a4 == 16 )
  {
    v43 = v12[18];
    if ( (v43 & 1) == 0 )
    {
      v44 = v43 & 0x1F0FFDF;
      if ( v44 != 16 && v44 != 4096 && v44 != 4112 )
        goto LABEL_154;
    }
LABEL_110:
    if ( !a7 )
    {
      v45 = v12[18];
      if ( (v45 & 1) == 0 )
      {
        v46 = v45 & 0x1F0FFDF;
        if ( (v45 & 0x1F0FFDF) != 16
          && v46 != 4096
          && v46 != 4112
          && v46 != 12288
          && v46 != 45056
          && v46 != 1060864
          && v46 != 8400896
          && (v45 & 0x10000) == 0 )
        {
          goto LABEL_154;
        }
      }
    }
    if ( a7 )
      goto LABEL_143;
    v47 = v12 + 7;
    if ( (_DWORD *)v12[7] == v12 + 7 )
    {
      if ( (_DWORD *)v12[9] == v12 + 9 )
      {
LABEL_132:
        v50 = v12[18] & 0x1F0FFDF;
        if ( v50 == 16 || v50 == 4096 || v50 == 4112 || v50 == 45056 )
        {
          for ( j = (int **)v12[5]; j != v12 + 5; j = (int **)*j )
          {
            v52 = j[2];
            if ( (v52[4] == 590400 || v52[7] != *(_DWORD *)(a2 + 28))
              && FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), v52[7], 0) )
            {
              FsRtlpRemoveAndCompleteReadOnlyIrp(*j[1], 533, a4 & 0x7000);
              break;
            }
          }
        }
LABEL_143:
        *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
        *(_DWORD *)(a3 + 24) = 0;
        v53 = a3 + 88;
        v54 = v12[5];
        *(_DWORD *)(a3 + 88) = v54;
        *(_DWORD *)(a3 + 92) = v12 + 5;
        if ( *(_DWORD **)(v54 + 4) != v12 + 5 )
          __fastfail(3u);
        *(_DWORD *)(v54 + 4) = v53;
        v12[5] = v53;
        *(_DWORD *)(a3 + 28) = v12;
        FsRtlpComputeShareableOplockState(v12);
        if ( a6 )
          ObfReferenceObjectWithTag(*(_DWORD *)(a2 + 28), 1953261124);
        *(_BYTE *)(a3 + 37) = KeAcquireQueuedSpinLock(7);
        if ( *(_BYTE *)(a3 + 36) )
        {
          FsRtlpCancelReadOnlyOplockIrp(a3, 1);
        }
        else
        {
          __dmb(0xBu);
          v55 = (unsigned int *)(a3 + 56);
          do
            v56 = __ldrex(v55);
          while ( __strex((unsigned int)FsRtlpReadOnlyOplockIrpCancelRoutine, v55) );
          __dmb(0xBu);
          KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a3 + 37));
        }
        v11 = 1;
        v61 = 259;
LABEL_153:
        if ( v11 )
          goto LABEL_155;
        goto LABEL_154;
      }
      v47 = v12 + 7;
    }
    v48 = (_DWORD *)v12[7];
    while ( v48 != v47 )
    {
      if ( FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), v48[3], 0) )
        goto LABEL_154;
      v48 = (_DWORD *)*v48;
      v47 = v12 + 7;
    }
    for ( k = (_DWORD *)v12[9]; k != v12 + 9; k = (_DWORD *)*k )
    {
      if ( FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), k[3], 0) )
        goto LABEL_154;
    }
    goto LABEL_132;
  }
  if ( a4 == 4096 )
    goto LABEL_110;
  if ( a4 != 12288 && a4 != 0x10000 )
    goto LABEL_153;
  if ( !a7 )
  {
    v28 = v12[18];
    if ( (v28 & 1) == 0 )
    {
      v29 = v28 & 0x1F0FFDF;
      if ( (v28 & 0x1F0FFDF) != 4096
        && v29 != 12288
        && v29 != 45056
        && v29 != 1060864
        && v29 != 8400896
        && (v28 & 0x10000) == 0 )
      {
        goto LABEL_44;
      }
    }
  }
  v30 = a2;
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 28) + 37) )
    goto LABEL_44;
  if ( !a7 )
  {
    v31 = v12[18] & 0x1F0FFDF;
    if ( v31 == 4096 || v31 == 45056 )
    {
      v32 = (int **)v12[5];
      while ( v32 != v12 + 5 )
      {
        if ( FsRtlpOplockKeysEqual(*(_DWORD *)(v30 + 28), v32[2][7], 0) )
        {
          if ( a4 == 0x10000 )
          {
LABEL_68:
            v27 = -1073741597;
            goto LABEL_46;
          }
          FsRtlpRemoveAndCompleteReadOnlyIrp(*v32[1], 533, 12288);
          v30 = a2;
          break;
        }
        v32 = (int **)*v32;
        v30 = a2;
      }
    }
    v33 = v12[18] & 0x1F0FFDF;
    if ( v33 == 12288 || v33 == 45056 )
    {
      v34 = (int **)v12[7];
      while ( v34 != v12 + 7 )
      {
        if ( FsRtlpOplockKeysEqual(*(_DWORD *)(v30 + 28), (int)v34[3], 0) && !v34[7] )
        {
          if ( a4 == 0x10000 )
            goto LABEL_68;
          FsRtlpRemoveAndBreakRHIrp((_DWORD *)*v34[1], (int)v12, 1, 533, 12288, 0);
          break;
        }
        v34 = (int **)*v34;
        v30 = a2;
      }
    }
    if ( (_DWORD *)v12[9] != v12 + 9 )
    {
      for ( l = (_DWORD *)v12[9]; l != v12 + 9; l = (_DWORD *)*l )
      {
        if ( FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), l[3], 0) )
        {
          if ( a4 != 0x10000 )
            goto LABEL_154;
          v27 = -1073741598;
          goto LABEL_46;
        }
      }
    }
  }
  *(_DWORD *)(*a5 + 16) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  *(_DWORD *)(*a5 + 12) = *(_DWORD *)(a2 + 28);
  v36 = FsRtlpOplockEnqueueRH(v12 + 7, *a5);
  v61 = v36;
  if ( v36 < 0 )
  {
    if ( a4 == 0x10000 )
      goto LABEL_155;
    *(_DWORD *)(a3 + 24) = v36;
    goto LABEL_41;
  }
  if ( a4 == 0x10000 )
  {
    v37 = (_DWORD *)(*a5 + 28);
    v38 = v12[15];
    *v37 = v38;
    v37[1] = v12 + 15;
    if ( *(_DWORD **)(v38 + 4) != v12 + 15 )
      __fastfail(3u);
    *(_DWORD *)(v38 + 4) = v37;
    v12[15] = v37;
    v61 = 0;
  }
  else
  {
    *(_DWORD *)(*a5 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    ObfReferenceObjectWithTag(*(_DWORD *)(*a5 + 20), 1953261124);
    *(_DWORD *)(*a5 + 8) = a3;
    *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
    v61 = 259;
    *(_DWORD *)(a3 + 24) = 0;
    *(_DWORD *)(a3 + 28) = v12;
    if ( a6 )
      ObfReferenceObjectWithTag(*(_DWORD *)(*a5 + 12), 1953261124);
    *(_BYTE *)(a3 + 37) = KeAcquireQueuedSpinLock(7);
    v39 = *(unsigned __int8 *)(a3 + 36);
    if ( *(_BYTE *)(a3 + 36) )
    {
      v40 = 1;
      if ( a6 )
      {
        v39 = a7;
        if ( a7 )
          v40 = 0;
      }
      FsRtlpCancelOplockRHIrp(a3, 1, v40, v39);
    }
    else
    {
      __dmb(0xBu);
      v41 = (unsigned int *)(a3 + 56);
      do
        v42 = __ldrex(v41);
      while ( __strex((unsigned int)FsRtlpOplockRHIrpCancelRoutine, v41) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a3 + 37));
    }
  }
  *a5 = 0;
  FsRtlpComputeShareableOplockState(v12);
  if ( a4 == 0x10000 )
    v12[18] |= 0x10000u;
LABEL_155:
  if ( v60 && varg_r3 != 0x10000 )
  {
    v57 = (unsigned int *)v64;
    *((_DWORD *)v64 + 1) = 0;
    __dmb(0xBu);
    do
      v58 = __ldrex(v57);
    while ( !v58 && __strex(1u, v57) );
    if ( v58 )
      ExpReleaseFastMutexContended(v57, v58, 1);
    KeAbPostRelease(v57);
  }
  return v61;
}
