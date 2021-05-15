// FsRtlpOplockFsctrlInternal 
 
int __fastcall FsRtlpOplockFsctrlInternal(int *a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v8; // r5
  int v9; // r8
  int v10; // r3
  unsigned int v11; // r3
  int v12; // r2
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r5
  unsigned int v16; // r10
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  int *v20; // r5
  _BYTE *v21; // r4
  _BYTE *v22; // r5
  unsigned int *v23; // r4
  unsigned int v24; // r1
  int v25; // r4
  unsigned int v26; // r2
  unsigned __int16 *v27; // r5
  int v28; // r3
  int v29; // r3
  int v30; // r1
  int v31; // r0
  int v32; // r3
  int v33; // r3
  int v34; // r0
  int v35; // r1
  int v36; // r2
  __int16 v37; // r1
  __int16 v38; // r2
  __int16 v39; // r3
  _DWORD *v40; // r4
  int v41; // r3
  int v42; // r0
  int v43; // r1
  int v44; // r2
  _DWORD *v45; // r4
  int *v46; // r5
  int v47; // r0
  int **v48; // r1
  _DWORD *v49; // r0
  int v50; // r3
  int v51; // r9
  int v52; // r1
  int v53; // r0
  int v54; // r3
  int v55; // r3
  __int16 v56; // r1
  __int16 v57; // r2
  __int16 v58; // r3
  _DWORD *v59; // r4
  int v60; // r3
  int v61; // r0
  int v62; // r1
  int v63; // r2
  _BYTE *v64; // r4
  char v66; // [sp+0h] [bp-48h]
  int v67; // [sp+4h] [bp-44h]
  int v68; // [sp+8h] [bp-40h]
  _BYTE *v69; // [sp+10h] [bp-38h] BYREF
  int v70; // [sp+14h] [bp-34h]
  _BYTE *v71; // [sp+18h] [bp-30h]
  int v72; // [sp+1Ch] [bp-2Ch]
  int v73; // [sp+20h] [bp-28h]
  int *v74; // [sp+24h] [bp-24h] BYREF
  int v75; // [sp+28h] [bp-20h]
  int *varg_r0; // [sp+50h] [bp+8h]
  _DWORD *varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v75 = a4;
  v74 = a1;
  varg_r0 = a1;
  v8 = 0;
  v70 = 0;
  v71 = 0;
  v69 = 0;
  v9 = a2[24];
  if ( *(_BYTE *)v9 )
  {
    v25 = 2;
    v26 = *(_DWORD *)(v9 + 16);
    if ( v26 <= 0x90010 )
    {
      switch ( v26 )
      {
        case 0x90010u:
          v13 = FsRtlpOpBatchBreakClosePending(*a1, a2[24], a2);
          goto LABEL_175;
        case 0x90000u:
LABEL_166:
          if ( a3 == 1
            && !IoIsOperationSynchronous((int)a2)
            && (a2[2] & 0x40) == 0
            && (*(_DWORD *)(*(_DWORD *)(v9 + 28) + 44) & 0x4000) == 0 )
          {
            v68 = a5;
            v67 = v25 | 0x40;
            v66 = 0;
            v11 = 1;
LABEL_79:
            v12 = (int)a2;
            goto LABEL_8;
          }
          goto LABEL_171;
        case 0x90004u:
          if ( !a3
            && !IoIsOperationSynchronous((int)a2)
            && (a2[2] & 0x40) == 0
            && (*(_DWORD *)(*(_DWORD *)(v9 + 28) + 44) & 0x4000) == 0 )
          {
            v13 = FsRtlpRequestShareableOplock((_DWORD **)a1, v9, (int)a2, 16, 0, 1, 0, a5);
            goto LABEL_175;
          }
          goto LABEL_171;
      }
      if ( v26 != 589832 )
      {
        if ( v26 == 589836 )
        {
          v13 = FsRtlpAcknowledgeOplockBreak(*a1, v9, (int)a2, 1, a5);
          goto LABEL_175;
        }
        goto LABEL_51;
      }
LABEL_165:
      v25 *= 2;
      goto LABEL_166;
    }
    switch ( v26 )
    {
      case 0x90014u:
        v13 = FsRtlpOplockBreakNotify(*a1);
        goto LABEL_175;
      case 0x90050u:
        v13 = FsRtlpAcknowledgeOplockBreak(*a1, v9, (int)a2, 0, a5);
        goto LABEL_175;
      case 0x9005Cu:
        v25 = 4;
        goto LABEL_165;
    }
    if ( v26 != 590400 )
      goto LABEL_51;
    v27 = (unsigned __int16 *)a2[3];
    if ( *(_DWORD *)(v9 + 12) < 0xCu || *(_DWORD *)(v9 + 8) < 0x18u )
    {
      v8 = -1073741789;
      goto LABEL_172;
    }
    if ( *v27 > 1u )
    {
LABEL_51:
      v8 = -1073741811;
LABEL_172:
      a2[6] = v8;
      IofCompleteRequest((int)a2, 1);
      return v8;
    }
    v28 = *((_DWORD *)v27 + 2);
    if ( (v28 & 1) != 0 )
    {
      v29 = *((_DWORD *)v27 + 1);
      v72 = v29 & 1;
      if ( (v29 & 1) != 0 )
        v30 = 4096;
      else
        v30 = 0;
      v73 = v29 & 4;
      if ( (v29 & 4) != 0 )
        v31 = 0x4000;
      else
        v31 = 0;
      v74 = (int *)(v29 & 2);
      if ( (v29 & 2) != 0 )
        v32 = 0x2000;
      else
        v32 = 0;
      v33 = v32 | v31 | v30;
      if ( v33 )
      {
        if ( v33 != 4096 && v33 != 12288 )
        {
          if ( v33 == 20480 || v33 == 28672 )
          {
            if ( !IoIsOperationSynchronous((int)a2) && (*(_DWORD *)(*(_DWORD *)(v9 + 28) + 44) & 0x4000) == 0 )
            {
              if ( v72 )
                v34 = 4096;
              else
                v34 = 0;
              if ( v73 )
                v35 = 0x4000;
              else
                v35 = 0;
              if ( v74 )
                v36 = 0x2000;
              else
                v36 = 0;
              v68 = a5;
              v67 = v36 | v35 | v34 | 0x40;
              v66 = v75;
              v11 = a3;
              goto LABEL_79;
            }
LABEL_171:
            v8 = -1073741598;
            goto LABEL_172;
          }
          goto LABEL_51;
        }
        if ( a3 || IoIsOperationSynchronous((int)a2) || (*(_DWORD *)(*(_DWORD *)(v9 + 28) + 44) & 0x4000) != 0 )
          goto LABEL_171;
        if ( v72 )
          v37 = 4096;
        else
          v37 = 0;
        if ( v73 )
          v38 = 0x4000;
        else
          v38 = 0;
        if ( v74 )
          v39 = 0x2000;
        else
          v39 = 0;
        if ( (((unsigned __int16)(v39 | v38) | (unsigned __int16)v37) & 0x2000) != 0 )
        {
          v71 = (_BYTE *)ExAllocatePoolWithTag(273, 36, 1869763398);
          v69 = v71;
          memset(v71, 0, 36);
        }
        if ( v71 )
          v40 = &v69;
        else
          v40 = 0;
        v41 = *((_DWORD *)v27 + 1);
        if ( (v41 & 1) != 0 )
          v42 = 4096;
        else
          v42 = 0;
        if ( (v41 & 4) != 0 )
          v43 = 0x4000;
        else
          v43 = 0;
        if ( (v41 & 2) != 0 )
          v44 = 0x2000;
        else
          v44 = 0;
        v70 = FsRtlpRequestShareableOplock((_DWORD **)a1, v9, (int)a2, v44 | v43 | v42, v40, 1, 0, a5);
LABEL_161:
        v64 = v69;
        if ( v69 )
        {
          FsRtlpClearOwnerThread(*varg_r0, (int)v69);
          ExFreePoolWithTag((unsigned int)v64);
        }
        return v70;
      }
      v45 = (_DWORD *)*a1;
      if ( *a1 )
      {
        v74 = 0;
        if ( (v45[18] & 0x10000) != 0 )
        {
          if ( FsRtlpCallerIsAtomicRequestor((int)v45, *(_DWORD *)(v9 + 28), &v74) )
          {
            v46 = v74;
            FsRtlpOplockDequeueRH(v74);
            v47 = v46[7];
            v48 = (int **)v46[8];
            if ( *(int **)(v47 + 4) != v46 + 7 || *v48 != v46 + 7 )
              __fastfail(3u);
            *v48 = (int *)v47;
            *(_DWORD *)(v47 + 4) = v48;
            if ( (_DWORD *)v45[15] == v45 + 15 )
              v45[18] &= 0xFFFCFFFF;
            if ( v46[5] )
              FsRtlpClearOwnerThread((int)v45, (int)v46);
            ExFreePoolWithTag((unsigned int)v46);
            v49 = FsRtlpComputeShareableOplockState(v45);
            FsRtlpReleaseIrpsWaitingForRH((int)v49);
          }
        }
      }
    }
    else
    {
      if ( (v28 & 2) == 0 )
        goto LABEL_51;
      v50 = *((_DWORD *)v27 + 1);
      v51 = v50 & 1;
      v52 = (v50 & 1) != 0 ? 4096 : 0;
      v75 = v50 & 4;
      v53 = (v50 & 4) != 0 ? 0x4000 : 0;
      v74 = (int *)(v50 & 2);
      v54 = (v50 & 2) != 0 ? 0x2000 : 0;
      v55 = v54 | v53 | v52;
      if ( v55 )
      {
        if ( v55 != 4096 && v55 != 12288 && v55 != 20480 && v55 != 28672 )
          goto LABEL_51;
      }
      if ( IoIsOperationSynchronous((int)a2) )
        goto LABEL_51;
      if ( (*(_DWORD *)(*(_DWORD *)(v9 + 28) + 44) & 0x4000) == 0 )
      {
        if ( v51 )
          v56 = 4096;
        else
          v56 = 0;
        if ( v75 )
          v57 = 0x4000;
        else
          v57 = 0;
        if ( v74 )
          v58 = 0x2000;
        else
          v58 = 0;
        if ( (((unsigned __int16)(v58 | v57) | (unsigned __int16)v56) & 0x2000) != 0 )
        {
          v71 = (_BYTE *)ExAllocatePoolWithTag(273, 36, 1869763398);
          v69 = v71;
          memset(v71, 0, 36);
        }
        if ( v71 )
          v59 = &v69;
        else
          v59 = 0;
        v60 = *((_DWORD *)v27 + 1);
        if ( (v60 & 1) != 0 )
          v61 = 4096;
        else
          v61 = 0;
        if ( (v60 & 4) != 0 )
          v62 = 0x4000;
        else
          v62 = 0;
        if ( (v60 & 2) != 0 )
          v63 = 0x2000;
        else
          v63 = 0;
        v70 = FsRtlpAcknowledgeOplockBreakByCacheFlags(
                (int *)*a1,
                (_DWORD *)v9,
                (int)a2,
                (_DWORD *)(v63 | v62 | v61),
                v59,
                a5);
        goto LABEL_161;
      }
      memset(v27, 0, 24);
      *v27 = 1;
      v27[1] = 24;
      a2[7] = 24;
    }
    a2[6] = 0;
    IofCompleteRequest((int)a2, 1);
    return 0;
  }
  v10 = *(_DWORD *)(v9 + 12);
  if ( (v10 & 0x100000) == 0 )
  {
    if ( (v10 & 0x10000) == 0 )
      return v8;
    v8 = FsRtlpAttachOplockKey((int)a2);
    v70 = v8;
    if ( v8 )
      return v8;
    v14 = *a1;
    if ( !*a1 )
    {
      v14 = FsRtlpAllocateOplock();
      *a1 = v14;
    }
    v71 = (_BYTE *)v14;
    v15 = *(_DWORD *)(v14 + 76);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = KeAbPreAcquire(v15, 0, 0);
    v18 = v17;
    do
      v19 = __ldrex((unsigned __int8 *)v15);
    while ( __strex(v19 & 0xFE, (unsigned __int8 *)v15) );
    __dmb(0xBu);
    if ( (v19 & 1) == 0 )
      ExpAcquireFastMutexContended(v15, v17);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    *(_DWORD *)(v15 + 4) = v16;
    v20 = v74;
    v70 = FsRtlCheckOplockEx((_DWORD **)v74, (int)a2, 805306368, 0, 0, 0);
    if ( !v70 )
    {
      v69 = (_BYTE *)ExAllocatePoolWithTag(273, 36, 1869763398);
      memset(v69, 0, 36);
      v70 = FsRtlpRequestShareableOplock((_DWORD **)v20, v9, 0, 0x10000, &v69, 0, 0, a5);
    }
    v21 = v69;
    v22 = v71;
    if ( v69 )
    {
      FsRtlpClearOwnerThread((int)v71, (int)v69);
      ExFreePoolWithTag((unsigned int)v21);
    }
    v23 = (unsigned int *)*((_DWORD *)v22 + 19);
    v23[1] = 0;
    __dmb(0xBu);
    do
      v24 = __ldrex(v23);
    while ( !v24 && __strex(1u, v23) );
    if ( v24 )
      ExpReleaseFastMutexContended(v23, v24);
    KeAbPostRelease((unsigned int)v23);
    return v70;
  }
  if ( a3 != 1 || (*(_DWORD *)(*(_DWORD *)(v9 + 8) + 8) & 0xFFFFFF7F) != 0 || (*(_WORD *)(v9 + 18) & 7) != 7 )
    return -1073741598;
  v8 = FsRtlpAttachOplockKey((int)a2);
  if ( !v8 )
  {
    v68 = a5;
    v67 = 200;
    v66 = 0;
    v11 = 1;
    v12 = 0;
LABEL_8:
    v13 = FsRtlpRequestExclusiveOplock(a1, v9, v12, v11, v66, v67, v68);
LABEL_175:
    v8 = v13;
  }
  return v8;
}
