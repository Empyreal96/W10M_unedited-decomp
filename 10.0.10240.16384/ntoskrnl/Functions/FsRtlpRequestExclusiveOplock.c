// FsRtlpRequestExclusiveOplock 
 
int __fastcall FsRtlpRequestExclusiveOplock(int *a1, int a2, int a3, unsigned int a4, char a5, int a6, int a7)
{
  int v10; // r4
  unsigned int v11; // r8
  unsigned int v12; // r9
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r2
  int v16; // r6
  _DWORD *v17; // r6
  int v18; // r0
  _DWORD *v19; // r1
  int v20; // r4
  _DWORD *i; // r6
  int v22; // r0
  int v23; // r2
  _DWORD *v24; // r6
  int v25; // r0
  _DWORD *v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r2
  int v30; // r0
  int v31; // r2
  int v32; // r8
  unsigned int *v33; // r2
  unsigned int v34; // r1
  int v35; // r3
  int v36; // r9
  int v37; // r3
  int v38; // r2
  int v39; // r3
  int v40; // r2
  int v41; // r3
  _DWORD *v42; // r8
  int v43; // r10
  int k; // r2
  _DWORD **v45; // r8
  _DWORD *v46; // r8
  int v47; // r10
  int j; // r2
  _DWORD **v49; // r8
  int v50; // r9
  int v51; // r3
  unsigned int *v52; // r1
  unsigned int v53; // r0
  unsigned int *v54; // r4
  unsigned int v55; // r1
  int v57; // [sp+14h] [bp-34h]
  _DWORD *v58; // [sp+18h] [bp-30h] BYREF
  unsigned int v59; // [sp+1Ch] [bp-2Ch]
  int v60; // [sp+20h] [bp-28h]
  int v61; // [sp+24h] [bp-24h]

  v59 = a4;
  v60 = a2;
  v57 = 0;
  v10 = *a1;
  if ( !*a1 )
  {
    v10 = FsRtlpAllocateOplock();
    *a1 = v10;
  }
  v61 = v10;
  v11 = *(_DWORD *)(v10 + 76);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = KeAbPreAcquire(v11, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex((unsigned __int8 *)v11);
  while ( __strex(v15 & 0xFE, (unsigned __int8 *)v11) );
  __dmb(0xBu);
  if ( (v15 & 1) == 0 )
    ExpAcquireFastMutexContended(v11, v13);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  *(_DWORD *)(v11 + 4) = v12;
  v16 = *(_DWORD *)(v10 + 72);
  if ( (v16 & 0x10000) != 0 && *(_BYTE *)a2 == 13 && FsRtlpCallerIsAtomicRequestor(v10, *(_DWORD *)(a2 + 28), &v58) )
  {
    if ( (v16 & 0x20000) != 0 )
    {
      v17 = v58;
      FsRtlpOplockDequeueRH(v58);
      v18 = v17[7];
      v19 = (_DWORD *)v17[8];
      if ( *(_DWORD **)(v18 + 4) != v17 + 7 || (_DWORD *)*v19 != v17 + 7 )
        __fastfail(3u);
      *v19 = v18;
      *(_DWORD *)(v18 + 4) = v19;
      if ( *(_DWORD *)(v10 + 60) == v10 + 60 )
        *(_DWORD *)(v10 + 72) &= 0xFFFCFFFF;
      if ( v17[5] )
        FsRtlpClearOwnerThread(v10, (int)v17);
      ExFreePoolWithTag(v17);
      v58 = 0;
      FsRtlpComputeShareableOplockState((_DWORD *)v10);
      goto LABEL_21;
    }
    for ( i = *(_DWORD **)(v10 + 44); i != (_DWORD *)(v10 + 44); i = (_DWORD *)*i )
    {
      v22 = (int)i;
      v23 = *(_DWORD *)(i[2] + 96);
      if ( *(_BYTE *)v23 != 13 || *(_DWORD *)(v23 + 16) != 589844 )
      {
        i = (_DWORD *)i[1];
        FsRtlpRemoveAndCompleteWaitingIrp(v22);
      }
    }
    v24 = v58;
    FsRtlpOplockDequeueRH(v58);
    v25 = v24[7];
    v26 = (_DWORD *)v24[8];
    if ( *(_DWORD **)(v25 + 4) != v24 + 7 || (_DWORD *)*v26 != v24 + 7 )
      __fastfail(3u);
    *v26 = v25;
    *(_DWORD *)(v25 + 4) = v26;
    if ( *(_DWORD *)(v10 + 60) == v10 + 60 )
      *(_DWORD *)(v10 + 72) &= 0xFFFCFFFF;
    if ( v24[5] )
      FsRtlpClearOwnerThread(v10, (int)v24);
    ExFreePoolWithTag(v24);
    v58 = 0;
    FsRtlpComputeShareableOplockState((_DWORD *)v10);
  }
  if ( FsRtlpOplockUpperLowerCompatible(a6, a7) )
  {
    if ( a6 == 200 )
    {
      *(_DWORD *)v10 = a3;
      *(_DWORD *)(v10 + 4) = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(v10 + 72) = *(_DWORD *)(v10 + 72) & 0x20 | 0xC8;
      goto LABEL_125;
    }
    v27 = *(_DWORD *)(v10 + 72);
    if ( (v27 & 0x91) != 0 )
    {
      if ( (v27 & 0x10) != 0 && (a6 & 0x7000) != 0
        || (v27 & 0x80) != 0 && !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), *(_DWORD *)(v10 + 4), 0) )
      {
LABEL_43:
        if ( (a6 & 0x10000) != 0 )
        {
LABEL_44:
          v28 = -1073739511;
LABEL_45:
          v57 = v28;
          goto LABEL_125;
        }
        goto LABEL_21;
      }
      v29 = *(_DWORD *)(v10 + 72) & 0x1F0FFDF;
      if ( v29 == 16 || v29 == 4096 || v29 == 4112 )
        FsRtlpRemoveAndCompleteReadOnlyIrp(*(_DWORD **)(v10 + 20), 0, 0);
      if ( v59 <= 1 || (*(_DWORD *)(v10 + 72) & 1) == 0 || (a5 & 1) != 0 )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a2 + 28) + 37) && (a6 & 0x2000) != 0 )
          goto LABEL_43;
LABEL_115:
        *(_DWORD *)v10 = a3;
        v50 = v60;
        *(_DWORD *)(v10 + 4) = *(_DWORD *)(v60 + 28);
        *(_DWORD *)(v10 + 8) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        FsRtlpClearOwnerThread(v10, 0);
        v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v10 + 12) = v51;
        ObfReferenceObjectWithTag(v51);
        *(_BYTE *)(v10 + 16) = 0;
        *(_DWORD *)(v10 + 72) = *(_DWORD *)(v10 + 72) & 0x20 | a6;
        ObfReferenceObjectWithTag(*(_DWORD *)(v50 + 28));
        *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
        *(_DWORD *)(a3 + 28) = v10;
        *(_BYTE *)(a3 + 37) = KeAcquireQueuedSpinLock(7);
        if ( *(_BYTE *)(a3 + 36) )
        {
          FsRtlpCancelExclusiveIrp(a3, 1, 1, *(unsigned __int8 *)(a3 + 36));
        }
        else
        {
          __dmb(0xBu);
          v52 = (unsigned int *)(a3 + 56);
          do
            v53 = __ldrex(v52);
          while ( __strex((unsigned int)FsRtlpExclusiveIrpCancelRoutine, v52) );
          __dmb(0xBu);
          KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a3 + 37));
        }
        v28 = 259;
        goto LABEL_45;
      }
    }
    else
    {
      if ( (v27 & 0x7000) != 0 && (v27 & 0x1F00F00) == 0 && *(_DWORD *)(v10 + 36) == v10 + 36 )
      {
        if ( (a6 & 0x10000) != 0 )
          goto LABEL_44;
        if ( (a6 & 0x7000) == 0 || (v30 = *(_DWORD *)(a2 + 28), *(_BYTE *)(v30 + 37)) && (a6 & 0x2000) != 0 )
        {
LABEL_21:
          v20 = -1073741598;
          goto LABEL_123;
        }
        v31 = v27 & 0x1F0FFDF;
        if ( v31 == 4096 )
        {
          if ( a6 != 20544 && a6 != 28736 )
            goto LABEL_21;
          v46 = *(_DWORD **)(v10 + 20);
          v47 = v60;
          while ( v46 != (_DWORD *)(v10 + 20) )
          {
            if ( !FsRtlpOplockKeysEqual(*(_DWORD *)(v47 + 28), *(_DWORD *)(v46[2] + 28), 0) )
              goto LABEL_21;
            v46 = (_DWORD *)*v46;
          }
          if ( v59 > 1 && (a5 & 1) == 0 )
            goto LABEL_21;
          for ( j = *(_DWORD *)(v10 + 20); j != v10 + 20; j = (int)*v49 )
          {
            v49 = *(_DWORD ***)(j + 4);
            FsRtlpRemoveAndCompleteReadOnlyIrp(*v49, 533, a6 & 0x7000);
          }
        }
        else if ( v31 == 12288 )
        {
          if ( a6 != 28736 || *(_DWORD *)(v10 + 36) != v10 + 36 )
            goto LABEL_21;
          v42 = *(_DWORD **)(v10 + 28);
          v43 = v60;
          while ( v42 != (_DWORD *)(v10 + 28) )
          {
            if ( !FsRtlpOplockKeysEqual(*(_DWORD *)(v43 + 28), v42[3], 0) )
              goto LABEL_21;
            if ( v42[7] )
            {
              v20 = -1073741597;
              goto LABEL_123;
            }
            v42 = (_DWORD *)*v42;
          }
          if ( v59 > 1 && (a5 & 1) == 0 )
            goto LABEL_21;
          for ( k = *(_DWORD *)(v10 + 28); k != v10 + 28; k = (int)*v45 )
          {
            v45 = *(_DWORD ***)(k + 4);
            FsRtlpRemoveAndBreakRHIrp(*v45, v10, 1, 533, 28672, 0);
          }
        }
        else
        {
          if ( v31 != 20544 && (v31 != 28736 || a6 != 28736)
            || a6 != 20544 && a6 != 28736
            || !FsRtlpOplockKeysEqual(v30, *(_DWORD *)(v10 + 4), 0) )
          {
            goto LABEL_21;
          }
          v32 = *(_DWORD *)v10;
          *(_BYTE *)(v32 + 37) = KeAcquireQueuedSpinLock(7);
          __dmb(0xBu);
          v33 = (unsigned int *)(v32 + 56);
          do
            v34 = __ldrex(v33);
          while ( __strex(0, v33) );
          __dmb(0xBu);
          KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v32 + 37));
          if ( *(_BYTE *)(v32 + 36) )
          {
            v35 = -1073741536;
          }
          else
          {
            v36 = *(_DWORD *)(v32 + 12);
            memset((_BYTE *)v36, 0, 24);
            *(_WORD *)v36 = 1;
            *(_WORD *)(v36 + 2) = 24;
            v37 = *(_DWORD *)(v10 + 72);
            if ( (v37 & 0x4000) != 0 )
              v38 = 4;
            else
              v38 = 0;
            if ( (v37 & 0x2000) != 0 )
              v39 = 2;
            else
              v39 = 0;
            *(_DWORD *)(v36 + 4) = v39 | v38 | ((*(_DWORD *)(v10 + 72) & 0x1000) != 0);
            if ( (a6 & 0x4000) != 0 )
              v40 = 4;
            else
              v40 = 0;
            if ( (a6 & 0x2000) != 0 )
              v41 = 2;
            else
              v41 = 0;
            *(_DWORD *)(v36 + 8) = v41 | v40 | ((a6 & 0x1000) != 0);
            *(_DWORD *)(v32 + 28) = 24;
            v35 = 533;
          }
          *(_DWORD *)(v32 + 24) = v35;
          pIofCompleteRequest(v32, 1);
          *(_DWORD *)v10 = 0;
          ObfDereferenceObjectWithTag(*(_DWORD *)(v10 + 4));
          *(_DWORD *)(v10 + 4) = 0;
        }
        goto LABEL_115;
      }
      if ( (a6 & 0x10000) != 0 )
        goto LABEL_44;
    }
    v20 = -1073741598;
    if ( !a3 )
    {
LABEL_124:
      v57 = v20;
      goto LABEL_125;
    }
LABEL_123:
    *(_DWORD *)(a3 + 24) = v20;
    pIofCompleteRequest(a3, 1);
    goto LABEL_124;
  }
  *(_DWORD *)(a3 + 24) = -1073741598;
  pIofCompleteRequest(a3, 1);
LABEL_125:
  v54 = *(unsigned int **)(v61 + 76);
  v54[1] = 0;
  __dmb(0xBu);
  do
    v55 = __ldrex(v54);
  while ( !v55 && __strex(1u, v54) );
  if ( v55 )
    ExpReleaseFastMutexContended(v54, v55);
  KeAbPostRelease((unsigned int)v54);
  return v57;
}
