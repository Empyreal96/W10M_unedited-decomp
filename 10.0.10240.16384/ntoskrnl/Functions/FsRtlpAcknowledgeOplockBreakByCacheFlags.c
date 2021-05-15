// FsRtlpAcknowledgeOplockBreakByCacheFlags 
 
int __fastcall FsRtlpAcknowledgeOplockBreakByCacheFlags(int *a1, _DWORD *a2, int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  int *v7; // r5
  int *v8; // r9
  unsigned int v9; // r8
  unsigned int v10; // r10
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // lr
  unsigned int v17; // r2
  int *i; // r10
  int v19; // r1
  int v20; // r0
  int v21; // r3
  int v22; // r4
  int v23; // r9
  int v24; // r4
  int v25; // r1
  int v26; // r9
  int v27; // r4
  int v28; // r3
  int v29; // r3
  unsigned int *v30; // r1
  unsigned int v31; // r4
  int v32; // r1
  int v33; // r0
  int *v34; // r0
  int v35; // r1
  int v36; // r3
  int v37; // r4
  __int16 v38; // lr
  int v39; // r2
  int v40; // r3
  int v41; // r0
  int v42; // r1
  int v43; // r3
  int v45; // r10
  int v46; // r3
  int v47; // r2
  int v48; // r3
  int v49; // r3
  BOOL v50; // r1
  int v51; // r2
  int v52; // r3
  unsigned int *v53; // r4
  unsigned int v54; // r1
  int v56; // [sp+Ch] [bp-54h]
  unsigned __int8 v57; // [sp+18h] [bp-48h] BYREF
  unsigned __int8 v58; // [sp+19h] [bp-47h] BYREF
  char v59; // [sp+1Ah] [bp-46h]
  char v60; // [sp+1Bh] [bp-45h]
  char v61; // [sp+1Ch] [bp-44h]
  int v62; // [sp+20h] [bp-40h]
  int v63; // [sp+24h] [bp-3Ch]
  _DWORD *v64; // [sp+28h] [bp-38h]
  int v65; // [sp+2Ch] [bp-34h]
  int *v66; // [sp+30h] [bp-30h] BYREF
  int v67; // [sp+34h] [bp-2Ch]
  int v68; // [sp+38h] [bp-28h]
  int *v69; // [sp+3Ch] [bp-24h]
  _DWORD *varg_r0[4]; // [sp+68h] [bp+8h] BYREF

  varg_r0[1] = a2;
  varg_r0[2] = (_DWORD *)a3;
  varg_r0[3] = a4;
  v65 = (int)a4;
  v64 = a2;
  v7 = a1;
  varg_r0[0] = a1;
  v62 = 0;
  v8 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v68 = 0;
  v57 = 0;
  v58 = 0;
  if ( !a1 )
  {
    *(_DWORD *)(a3 + 24) = -1073741597;
    pIofCompleteRequest(a3, 1);
    return -1073741597;
  }
  v9 = a1[19];
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = KeAbPreAcquire(v9, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex((unsigned __int8 *)v9);
  while ( __strex(v13 & 0xFE, (unsigned __int8 *)v9) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
    ExpAcquireFastMutexContended(v9, v11);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  *(_DWORD *)(v9 + 4) = v10;
  v59 = 1;
  v14 = v7[18];
  if ( (v14 & 0xF00000) == 0 && (v14 & 0x1F0FFDF) != 45056 && (v14 & 0x1F0FFDF) != 12288
    || ((v15 = v14 & 0x1F0FFDF, v15 == 45056) || v15 == 12288) && (int *)v7[9] == v7 + 9 )
  {
LABEL_15:
    v62 = -1073741597;
    *(_DWORD *)(a3 + 24) = -1073741597;
    pIofCompleteRequest(a3, 1);
    goto LABEL_137;
  }
  if ( (*(_DWORD *)(*(_DWORD *)(a3 + 12) + 8) & 4) != 0 )
  {
    v63 = 1;
    v8 = (int *)ExAllocatePoolWithTag(273, 12);
    v69 = v8;
    v66 = v8;
    *v8 = 0;
    v8[1] = 0;
    v8[2] = 0;
    v16 = 1;
  }
  else
  {
    v16 = 0;
    v63 = 0;
  }
  v17 = v7[18] & 0x1F0FFDF;
  if ( v17 <= 0x307040 )
  {
    if ( v17 != 3174464 )
    {
      if ( v17 != 12288 && v17 != 45056 && v17 != 1060864 )
      {
        if ( v17 != 1069120 && v17 != 1077312 )
          goto LABEL_15;
        goto LABEL_87;
      }
      goto LABEL_32;
    }
    if ( !v16 )
      goto LABEL_91;
LABEL_87:
    v32 = v7[1];
    v33 = v64[7];
    if ( v32 == v33 || !FsRtlpOplockKeysEqual(v33, v32, 0) )
      goto LABEL_15;
    if ( v63 )
    {
      v38 = v65;
      if ( !v65 )
      {
        FsRtlpModifyThreadPriorities(v7, 0, 0);
        FsRtlpClearOwnerThread((int)v7, 0);
        *((_BYTE *)v7 + 16) = 0;
        v7[18] = v7[18] & 0x20 | 1;
        v34 = v69;
        v69[2] = v7[1];
        v35 = v7[13];
        *v34 = v35;
        v34[1] = (int)(v7 + 13);
        if ( *(int **)(v35 + 4) != v7 + 13 )
          __fastfail(3u);
        *(_DWORD *)(v35 + 4) = v34;
        v7[13] = (int)v34;
        v66 = 0;
        v7[1] = 0;
        v7[18] |= 0x1000000u;
        *(_DWORD *)(a3 + 24) = 0;
        pIofCompleteRequest(a3, 1);
        goto LABEL_97;
      }
    }
    else
    {
LABEL_91:
      if ( v7[1] != v64[7] )
        goto LABEL_15;
      v38 = v65;
    }
    v39 = v7[18];
    v40 = v39 & 0x1F0FFDF;
    if ( ((v39 & 0x1F0FFDF) == 1069120
       || v40 == 1077312
       || v40 == 3174464
       || v40 == 5271616
       || v40 == 8409152
       || v40 == 8417344)
      && ((v39 & 0x100000) == 0 ? (v41 = 0) : (v41 = 4096),
          (v39 & 0x200000) == 0 ? (v42 = 0) : (v42 = 0x4000),
          (v39 & 0x400000) == 0 ? (v43 = 0) : (v43 = 0x2000),
          (v38 & 0x7000u) > ((v43 | v42 | v41) & 0x7000u) && (int *)v7[11] != v7 + 11) )
    {
      v45 = *(_DWORD *)(a3 + 12);
      memset((_BYTE *)v45, 0, 24);
      v46 = v7[18];
      if ( (v46 & 0x4000) != 0 )
        v47 = 4;
      else
        v47 = 0;
      if ( (v46 & 0x2000) != 0 )
        v48 = 2;
      else
        v48 = 0;
      *(_DWORD *)(v45 + 4) = v48 | v47 | ((v7[18] & 0x1000) != 0);
      v49 = v7[18];
      v50 = (v49 & 0x100000) != 0;
      if ( (v49 & 0x200000) != 0 )
        v51 = 4;
      else
        v51 = 0;
      if ( (v49 & 0x400000) != 0 )
        v52 = 2;
      else
        v52 = 0;
      *(_DWORD *)(v45 + 8) = v52 | v51 | v50;
      *(_DWORD *)(v45 + 12) |= 1u;
      *(_DWORD *)(a3 + 28) = 24;
      *(_DWORD *)(a3 + 24) = -2147483602;
      pIofCompleteRequest(a3, 1);
      v62 = -2147483602;
    }
    else
    {
      FsRtlpModifyThreadPriorities(v7, 0, 0);
      FsRtlpClearOwnerThread((int)v7, 0);
      *((_BYTE *)v7 + 16) = 0;
      v62 = FsRtlpGrantAnyOplockFromExclusive(v7, a3, v64, v65, a5, v63, &v66, &v58, &v57, a6);
      v37 = v57;
      v36 = v58;
LABEL_132:
      if ( v36 )
      {
        while ( (int *)v7[11] != v7 + 11 )
          FsRtlpRemoveAndCompleteWaitingIrp(v7[11]);
      }
      if ( v37 )
      {
        ObfDereferenceObjectWithTag(v7[1]);
        v7[1] = 0;
      }
    }
    goto LABEL_137;
  }
  if ( v17 == 5271616 )
    goto LABEL_87;
  if ( v17 != 8400896 )
  {
    if ( v17 != 8409152 && v17 != 8417344 )
      goto LABEL_15;
    goto LABEL_87;
  }
LABEL_32:
  for ( i = (int *)v7[9]; ; i = (int *)*i )
  {
    if ( i == v7 + 9 )
    {
      v24 = 0;
      goto LABEL_81;
    }
    if ( v16 )
      break;
    if ( i[3] == v64[7] )
      goto LABEL_41;
LABEL_40:
    ;
  }
  v19 = i[3];
  v20 = v64[7];
  if ( v19 == v20 )
    goto LABEL_40;
  if ( !FsRtlpOplockKeysEqual(v20, v19, 0) )
  {
    v16 = v63;
    goto LABEL_40;
  }
LABEL_41:
  v67 = 1;
  v60 = 1;
  v21 = i[6] & 0xF00000;
  if ( v21 == 0x800000 )
  {
    if ( v65 )
    {
      v22 = a6;
      if ( (int *)v7[11] != v7 + 11 || !FsRtlpOplockUpperLowerCompatible(v65, a6) )
      {
        v23 = *(_DWORD *)(a3 + 12);
        memset((_BYTE *)v23, 0, 24);
        *(_DWORD *)(v23 + 4) = 3;
        if ( (int *)v7[11] != v7 + 11 )
          v22 = 0;
LABEL_47:
        *(_DWORD *)(v23 + 8) = v22;
        *(_DWORD *)(v23 + 12) |= 1u;
        *(_DWORD *)(a3 + 28) = 24;
        *(_DWORD *)(a3 + 24) = -2147483602;
        pIofCompleteRequest(a3, 1);
        v62 = -2147483602;
        v24 = 1;
        goto LABEL_81;
      }
      goto LABEL_55;
    }
LABEL_54:
    v22 = a6;
    goto LABEL_55;
  }
  if ( v21 != 0x100000 || (v65 & 0x7000u) <= 0x3000 )
    goto LABEL_54;
  v22 = a6;
  if ( (int *)v7[11] != v7 + 11 || !FsRtlpOplockUpperLowerCompatible(v65, a6) )
  {
    v23 = *(_DWORD *)(a3 + 12);
    memset((_BYTE *)v23, 0, 24);
    *(_DWORD *)(v23 + 4) = 3;
    if ( (int *)v7[11] != v7 + 11 )
      v22 = 1;
    goto LABEL_47;
  }
LABEL_55:
  FsRtlpOplockDequeueRH(i);
  if ( v63 )
  {
    v8[2] = i[3];
    v25 = v7[13];
    *v8 = v25;
    v8[1] = (int)(v7 + 13);
    if ( *(int **)(v25 + 4) != v7 + 13 )
      __fastfail(3u);
    *(_DWORD *)(v25 + 4) = v8;
    v7[13] = (int)v8;
    v66 = 0;
    v26 = v65;
  }
  else
  {
    v68 = 1;
    v61 = 1;
    v26 = v65;
    if ( !v65 )
      ObfDereferenceObjectWithTag(i[3]);
  }
  if ( !v26 )
  {
    FsRtlpComputeShareableOplockState(v7);
    v62 = 0;
    *(_DWORD *)(a3 + 24) = 0;
    pIofCompleteRequest(a3, 1);
    goto LABEL_74;
  }
  if ( (v26 & 0x3010) == 0 || (v26 & 0x4040) != 0 )
  {
    *v7 = a3;
    *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
    v62 = 259;
    *(_DWORD *)(a3 + 28) = v7;
    v7[2] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7[3] = v28;
    ObfReferenceObjectWithTag(v28);
    *((_BYTE *)v7 + 16) = 0;
    v27 = v63;
    if ( v63 )
    {
      ObfReferenceObjectWithTag(v64[7]);
      v29 = v64[7];
    }
    else
    {
      v29 = i[3];
    }
    v7[1] = v29;
    v7[18] = v7[18] & 0x20 | v26 | 0x40;
    *(_BYTE *)(a3 + 37) = KeAcquireQueuedSpinLock(7);
    if ( *(_BYTE *)(a3 + 36) )
    {
      FsRtlpCancelExclusiveIrp(a3, 1, v27 == 0);
    }
    else
    {
      __dmb(0xBu);
      v30 = (unsigned int *)(a3 + 56);
      do
        v31 = __ldrex(v30);
      while ( __strex((unsigned int)FsRtlpExclusiveIrpCancelRoutine, v30) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a3 + 37));
LABEL_74:
      v27 = v63;
    }
  }
  else
  {
    v56 = v22;
    v27 = v63;
    v62 = FsRtlpRequestShareableOplock(varg_r0, (int)v64, a3, v26, a5, v63, 1u, v56);
    v7 = varg_r0[0];
  }
  FsRtlpModifyThreadPriorities(v7, i, 0);
  FsRtlpClearOwnerThread((int)v7, (int)i);
  if ( (int *)v7[9] == v7 + 9 )
    *((_BYTE *)v7 + 16) = 0;
  ExFreePoolWithTag(i);
  if ( v27 )
    v7[18] |= 0x1000000u;
  v24 = 1;
LABEL_81:
  if ( !v67 )
  {
    v62 = -1073741597;
    *(_DWORD *)(a3 + 24) = -1073741597;
    pIofCompleteRequest(a3, 1);
    goto LABEL_137;
  }
  if ( v68 )
    FsRtlpReleaseIrpsWaitingForRH((int)v7);
  if ( !v24 )
  {
LABEL_97:
    v36 = 0;
    v37 = 0;
    goto LABEL_132;
  }
LABEL_137:
  if ( v66 )
    ExFreePoolWithTag(v66);
  if ( v59 )
  {
    v53 = (unsigned int *)varg_r0[0][19];
    v53[1] = 0;
    __dmb(0xBu);
    do
      v54 = __ldrex(v53);
    while ( !v54 && __strex(1u, v53) );
    if ( v54 )
      ExpReleaseFastMutexContended(v53, v54);
    KeAbPostRelease((unsigned int)v53);
  }
  return v62;
}
