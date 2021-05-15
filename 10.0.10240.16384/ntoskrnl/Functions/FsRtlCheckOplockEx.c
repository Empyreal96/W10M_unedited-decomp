// FsRtlCheckOplockEx 
 
int __fastcall FsRtlCheckOplockEx(_DWORD **a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v7; // r6
  int v9; // r4
  _DWORD *v10; // r9
  unsigned __int8 *v11; // r10
  int v12; // r6
  unsigned int v13; // r8
  int v14; // r0
  int v15; // r5
  unsigned int v16; // r2
  int v17; // r5
  _DWORD *v18; // r4
  int v19; // r0
  _DWORD *v20; // r1
  _DWORD *v21; // r0
  unsigned int *v22; // r4
  unsigned int v23; // r1
  BOOL v24; // r8
  int v25; // r2
  int v26; // r0
  int v27; // r1
  _DWORD *v28; // r0
  int v29; // r8
  unsigned __int8 *v30; // r0
  unsigned int v31; // r2
  int v32; // r0
  int v33; // lr
  unsigned int v34; // r3
  int v35; // r8
  int v36; // r2
  unsigned int v37; // r2
  unsigned int v38; // r2
  int v39; // r3
  int v40; // r0
  unsigned int *v41; // r4
  unsigned int v42; // r1
  bool v44; // [sp+18h] [bp-48h] BYREF
  char v45; // [sp+19h] [bp-47h]
  char v46; // [sp+1Ah] [bp-46h]
  char v47; // [sp+1Bh] [bp-45h] BYREF
  unsigned __int8 i; // [sp+1Ch] [bp-44h]
  unsigned int v49; // [sp+20h] [bp-40h]
  int v50; // [sp+24h] [bp-3Ch]
  int v51; // [sp+28h] [bp-38h]
  _DWORD *v52; // [sp+2Ch] [bp-34h] BYREF
  _DWORD *v53; // [sp+30h] [bp-30h]
  int v54; // [sp+34h] [bp-2Ch]
  int v55; // [sp+38h] [bp-28h]
  unsigned __int8 *v56; // [sp+3Ch] [bp-24h]
  _DWORD **varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  v54 = a4;
  varg_r3 = a4;
  v6 = a3;
  varg_r2 = a3;
  v7 = a2;
  varg_r1 = a2;
  v9 = 0;
  v51 = 0;
  v10 = *a1;
  v53 = *a1;
  v11 = *(unsigned __int8 **)(a2 + 96);
  v56 = v11;
  if ( (a3 & 4) == 0 )
  {
    if ( (a3 & 0x10000000) == 0 )
    {
      v9 = FsRtlpAttachOplockKey(a2);
      v51 = v9;
    }
    FsRtlpOplockStoreKeyForDeleteOperation(a1, v7, v6);
    if ( v10 != *a1 )
    {
      v10 = *a1;
      v53 = *a1;
    }
    if ( (v6 & 2) != 0 || !v10 || (*(_DWORD *)(v7 + 8) & 2) != 0 || v9 )
      return v9;
    v24 = (v6 & 0x20000000) != 0;
    v44 = (v6 & 0x20000000) != 0;
    v25 = 1;
    for ( i = 1; ; v25 = i )
    {
      v47 = 0;
      v55 = v6 & 0x10;
      if ( (v6 & 0x10) == 0 && !v24 )
      {
        v26 = v10[18];
        __dmb(0xBu);
        v27 = *v11;
        if ( v27 != 3 || (v26 & 0xFFFF4FFE) != 0 )
        {
          v25 = i;
        }
        else
        {
          v25 = 0;
          i = 0;
        }
        if ( v27 == 4 && (v26 & 0xFFFFDFFE) == 0 )
        {
          i = 0;
          goto LABEL_122;
        }
        v9 = v51;
        v24 = v44;
      }
      if ( v25 )
      {
        if ( !v24 )
        {
          v52 = (_DWORD *)v10[19];
          v28 = v52;
          v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v29 = KeAbPreAcquire(v28, 0, 0);
          v30 = (unsigned __int8 *)v52;
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 & 0xFE, v30) );
          __dmb(0xBu);
          if ( (v31 & 1) == 0 )
          {
            ExpAcquireFastMutexContended(v30, v29);
            v30 = (unsigned __int8 *)v52;
          }
          if ( v29 )
            *(_BYTE *)(v29 + 14) |= 1u;
          *((_DWORD *)v30 + 1) = v49;
        }
        v44 = 1;
        v32 = v10[18];
        if ( v32 != 1 )
          break;
      }
LABEL_122:
      v24 = v44;
      v6 = varg_r2;
      v10 = v53;
      if ( v44 && (varg_r2 & 0x20000000) == 0 )
      {
        v41 = (unsigned int *)v53[19];
        v41[1] = 0;
        __dmb(0xBu);
        do
          v42 = __ldrex(v41);
        while ( !v42 && __strex(1u, v41) );
        if ( v42 )
          ExpReleaseFastMutexContended(v41, v42);
        KeAbPostRelease(v41);
      }
      v9 = v51;
      if ( !v47 )
        return v9;
      v54 = varg_r3;
      v7 = varg_r1;
      v11 = v56;
    }
    v33 = 0;
    v52 = 0;
    v46 = 0;
    v34 = 0;
    v49 = 0;
    v45 = 0;
    v35 = 0;
    v50 = 0;
    if ( v55 )
    {
      v35 = 20480;
      v50 = 20480;
      goto LABEL_110;
    }
    if ( *v11 == 18 )
    {
LABEL_105:
      FsRtlpOplockCleanup((int)v10, (int)v11);
      if ( *v11 == 18 && (v6 & 0x20) != 0 )
      {
        v35 = 0x2000;
        v50 = 0x2000;
      }
    }
    else
    {
      if ( *v11 )
      {
        switch ( *v11 )
        {
          case 2u:
            if ( (*(_DWORD *)(*((_DWORD *)v11 + 7) + 44) & 0x4000) != 0 )
              goto LABEL_109;
            goto LABEL_105;
          case 3u:
            goto LABEL_65;
          case 4u:
            goto LABEL_69;
          case 5u:
          case 7u:
          case 8u:
          case 0xAu:
          case 0xBu:
          case 0xCu:
          case 0xEu:
          case 0xFu:
          case 0x10u:
          case 0x12u:
          case 0x13u:
          case 0x14u:
            goto LABEL_109;
          case 6u:
            v36 = *((_DWORD *)v11 + 3);
            if ( v36 > 20 )
            {
              if ( v36 == 39 )
                goto LABEL_69;
              if ( v36 == 40 )
              {
                v35 = 0x2000;
                v50 = 0x2000;
                if ( (v32 & 0xC) != 0 )
                {
                  v34 = 1;
                  v45 = 1;
                  goto LABEL_110;
                }
              }
            }
            else if ( v36 == 20 )
            {
              if ( !v11[21] )
                goto LABEL_69;
            }
            else
            {
              v37 = v36 - 10;
              if ( v37 <= 9 )
                __asm { ADD             PC, R3 }
            }
            goto LABEL_109;
          case 9u:
            goto LABEL_66;
          case 0xDu:
            v38 = *((_DWORD *)v11 + 4);
            if ( v38 > 0x98268 )
            {
              if ( v38 == 623428 )
                goto LABEL_69;
              if ( v38 == 639668 )
              {
                v34 = 1;
                v45 = 1;
                v35 = 20480;
                v50 = 20480;
                goto LABEL_110;
              }
            }
            else
            {
              switch ( v38 )
              {
                case 0x98268u:
                  goto LABEL_69;
                case 0x94264u:
LABEL_65:
                  if ( (v32 & 8) == 0 )
                  {
LABEL_66:
                    v33 = 1;
                    v46 = 1;
                  }
                  v35 = 0x4000;
                  v50 = 0x4000;
                  break;
                case 0x980C8u:
                case 0x98208u:
LABEL_69:
                  v34 = 1;
                  v45 = 1;
                  v35 = 20480;
                  v50 = 20480;
                  goto LABEL_110;
              }
            }
            break;
          case 0x11u:
            if ( (v32 & 8) != 0 )
              goto LABEL_109;
            goto LABEL_69;
          case 0x15u:
            v35 = 0x2000;
            v50 = 0x2000;
            goto LABEL_109;
          default:
            goto LABEL_110;
        }
        goto LABEL_109;
      }
      if ( ((v32 & 0x7000) != 0 && (*(_DWORD *)(*((_DWORD *)v11 + 2) + 8) & 0xFFEDFE7F) != 0
         || (v32 & 0x1E) != 0 && (*(_DWORD *)(*((_DWORD *)v11 + 2) + 8) & 0xFFEFFE7F) != 0
         || (*((_DWORD *)v11 + 3) & 0x100000) != 0)
        && ((v32 & 8) == 0 || (*(_DWORD *)(*((_DWORD *)v11 + 2) + 8) & 0xFFEDFE56) != 0
                           || (*((_WORD *)v11 + 9) & 1) == 0) )
      {
        v39 = v11[15];
        if ( !v11[15] || v39 == 4 || v39 == 5 || (*((_DWORD *)v11 + 3) & 0x100000) != 0 )
        {
          v34 = 1;
          v45 = 1;
          v35 = 20480;
          v50 = 20480;
          v33 = (int)v52;
          goto LABEL_110;
        }
        v33 = 1;
        v46 = 1;
        v35 = 0x4000;
        v50 = 0x4000;
LABEL_109:
        v34 = v49;
LABEL_110:
        if ( v33 )
        {
          if ( (v10[18] & 0x1F0FFDF) != 16 && !FsRtlpOplockKeysEqual(*((_DWORD *)v11 + 7), v10[1], 0) )
          {
            v40 = FsRtlpOplockBreakToII(v10, (int)v11, v7, v6, v54, a5, a6, &v44, (int)&v47);
LABEL_118:
            v9 = v40;
            v51 = v40;
            goto LABEL_119;
          }
        }
        else if ( v34 && ((v10[18] & 0x1F0FFDF) == 16 || !FsRtlpOplockKeysEqual(*((_DWORD *)v11 + 7), v10[1], 0)) )
        {
          v40 = FsRtlpOplockBreakToNone(v10, v11, v7, v6, v54, a5, a6, &v44, &v47);
          goto LABEL_118;
        }
LABEL_119:
        if ( !v9 && (v35 & v10[18]) != 0 )
          v51 = FsRtlpOplockBreakByCacheFlags(v10, v11, v7, v6, v35, v54, a5, a6, &v44, &v47);
        goto LABEL_122;
      }
    }
    v33 = (int)v52;
    goto LABEL_109;
  }
  v52 = 0;
  if ( !v10 )
    return 0;
  v12 = v10[19];
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = KeAbPreAcquire(v12, 0, 0);
  v15 = v14;
  do
    v16 = __ldrex((unsigned __int8 *)v12);
  while ( __strex(v16 & 0xFE, (unsigned __int8 *)v12) );
  __dmb(0xBu);
  if ( (v16 & 1) == 0 )
    ExpAcquireFastMutexContended(v12, v14);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  *(_DWORD *)(v12 + 4) = v13;
  if ( *v11 )
  {
    v17 = -1073741811;
  }
  else
  {
    if ( (v10[18] & 0x10000) != 0 && FsRtlpCallerIsAtomicRequestor((int)v10, *((_DWORD *)v11 + 7), &v52) )
    {
      v18 = v52;
      FsRtlpOplockDequeueRH(v52);
      v19 = v18[7];
      v20 = (_DWORD *)v18[8];
      if ( *(_DWORD **)(v19 + 4) != v18 + 7 || (_DWORD *)*v20 != v18 + 7 )
        __fastfail(3u);
      *v20 = v19;
      *(_DWORD *)(v19 + 4) = v20;
      if ( (_DWORD *)v10[15] == v10 + 15 )
        v10[18] &= 0xFFFCFFFF;
      if ( v18[5] )
        FsRtlpClearOwnerThread((int)v10, (int)v18);
      ExFreePoolWithTag(v18, 0);
      v21 = FsRtlpComputeShareableOplockState(v10);
      FsRtlpReleaseIrpsWaitingForRH((int)v21);
    }
    v17 = 0;
  }
  v22 = (unsigned int *)v10[19];
  v22[1] = 0;
  __dmb(0xBu);
  do
    v23 = __ldrex(v22);
  while ( !v23 && __strex(1u, v22) );
  if ( v23 )
    ExpReleaseFastMutexContended(v22, v23);
  KeAbPostRelease(v22);
  return v17;
}
