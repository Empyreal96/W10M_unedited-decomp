// FsRtlpOplockBreakByCacheFlags 
 
int __fastcall FsRtlpOplockBreakByCacheFlags(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _BYTE *a9, int a10)
{
  int v11; // r0
  int v12; // r10
  BOOL v13; // r2
  int v14; // r3
  int v15; // r1
  int v17; // r2
  int v18; // r1
  _DWORD *v19; // r9
  int v20; // lr
  unsigned int v21; // r3
  _DWORD *m; // r8
  int v23; // r6
  unsigned int *v24; // r2
  unsigned int v25; // r1
  int v26; // r8
  int v27; // r3
  int v28; // r1
  int v29; // r3
  int v30; // r2
  int v31; // r3
  int v32; // r8
  unsigned int *v33; // r2
  unsigned int v34; // r1
  int v35; // r6
  int v36; // r3
  int v37; // r1
  int v38; // r3
  int v39; // r5
  unsigned int *v40; // r2
  unsigned int v41; // r1
  int v42; // r8
  int v43; // r3
  int v44; // r1
  int v45; // r3
  int v46; // r5
  unsigned int *v47; // r2
  unsigned int v48; // r1
  int v49; // r8
  int v50; // r3
  int v51; // r1
  int v52; // r3
  int v53; // r8
  unsigned int *v54; // r2
  unsigned int v55; // r1
  int v56; // r6
  int v57; // r3
  int v58; // r1
  int v59; // r3
  _DWORD *i; // r6
  int v61; // r1
  _DWORD **j; // r9
  _DWORD *v63; // lr
  unsigned int *v64; // r2
  unsigned int v65; // r1
  int v66; // r2
  _DWORD *v67; // r6
  int v68; // lr
  unsigned int v69; // r3
  _DWORD *k; // r9
  int v71; // lr
  unsigned int *v72; // r2
  unsigned int v73; // r1
  _DWORD *v74; // r0
  _DWORD *l; // r8
  bool v76; // zf
  _DWORD *n; // r5
  int v78; // r3
  int v79; // r3
  char v81; // [sp+10h] [bp-60h]
  int v83; // [sp+1Ch] [bp-54h]
  _DWORD *v84; // [sp+20h] [bp-50h]
  int v85; // [sp+20h] [bp-50h]
  BOOL v86; // [sp+24h] [bp-4Ch]
  int v88; // [sp+2Ch] [bp-44h]
  int v89; // [sp+2Ch] [bp-44h]
  int v90; // [sp+2Ch] [bp-44h]
  int v91; // [sp+2Ch] [bp-44h]
  int v94; // [sp+38h] [bp-38h]
  BOOL v95; // [sp+3Ch] [bp-34h]
  int v96; // [sp+40h] [bp-30h] BYREF

  v11 = 0;
  v83 = 0;
  v12 = 0;
  v88 = 0;
  v95 = 0;
  v94 = 1;
  v13 = (a4 & 8) != 0;
  v86 = v13;
  if ( a5 == 28672 || a5 == 20480 || a5 == 0x4000 || a5 == 0x2000 )
  {
    if ( !a1 )
      return v11;
    v14 = a1[18];
    if ( v14 == 1 || (v14 & a5) == 0 || !v13 && FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), a1[1], a4) )
      return 0;
    v15 = a1[18];
    if ( (v15 & 0x40) != 0 && (a4 & 0x10010000) != 0 )
      return -1073739511;
    v17 = v15 & 0x1F0FFDF;
    if ( (v15 & 0x1F0FFDFu) <= 0x105040 )
    {
      if ( (v15 & 0x1F0FFDF) != 1069120 )
      {
        switch ( v17 )
        {
          case 4096:
          case 4112:
LABEL_104:
            if ( (a5 & 0x1000) != 0 )
            {
              for ( i = (_DWORD *)a1[5]; i != a1 + 5; i = (_DWORD *)*i )
              {
                v61 = i[2];
                if ( *(_DWORD *)(v61 + 16) == 590400
                  && (v86 || !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), *(_DWORD *)(v61 + 28), a4)) )
                {
                  if ( (a4 & 0x10010000) != 0 )
                    return -1073739511;
                  i = (_DWORD *)i[1];
                  FsRtlpRemoveAndCompleteReadOnlyIrp(*i, 0, 0);
                }
              }
            }
            if ( (a1[18] & 0x1F0FFDF) != 45056 )
            {
              FsRtlpComputeShareableOplockState(a1);
              goto LABEL_200;
            }
LABEL_115:
            if ( a5 == 0x2000 )
            {
              for ( j = (_DWORD **)a1[7]; j != a1 + 7; j = (_DWORD **)*j )
              {
                v84 = j[2];
                if ( v86 || !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), (int)j[3], 0) )
                {
                  if ( (a4 & 0x10010000) != 0 )
                    return -1073739511;
                  if ( j[7] )
                  {
                    v12 = 1;
                    v81 = 1;
                  }
                  else
                  {
                    j = (_DWORD **)j[1];
                    v63 = v84;
                    *((_BYTE *)v84 + 37) = KeAcquireQueuedSpinLock(7);
                    __dmb(0xBu);
                    v64 = v63 + 14;
                    do
                      v65 = __ldrex(v64);
                    while ( __strex(0, v64) );
                    __dmb(0xBu);
                    KeReleaseQueuedSpinLock(7, *((unsigned __int8 *)v84 + 37));
                    if ( *((_BYTE *)v84 + 36) )
                    {
                      FsRtlpRemoveAndBreakRHIrp(*j, (int)a1, 0, -1073741536, 0, 0);
                      v88 = 1;
                    }
                    else
                    {
                      v66 = 1;
                      if ( !*(_BYTE *)a2 )
                        v66 = 3;
                      FsRtlpRemoveAndBreakRHIrp(*j, (int)a1, 0, 0, 4096, v66);
                      v94 = 0;
                      v12 = 1;
                      v81 = 1;
                      v95 = v86;
                    }
                  }
                }
              }
            }
            else if ( (a5 & 0x5000) == 20480 )
            {
              v67 = (_DWORD *)a1[9];
              v68 = a4;
              while ( v67 != a1 + 9 )
              {
                if ( v86 || (v68 = a4, !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), v67[3], a4)) )
                {
                  if ( (v68 & 0x10010000) != 0 )
                    return -1073739511;
                  v69 = v67[6] & 0xFF0FFFFF;
                  v67[6] = v69;
                  v67[6] = v69 | 0x800000;
                  if ( (a5 & 0x2000) != 0 )
                  {
                    v12 = 1;
                    v81 = 1;
                  }
                }
                v67 = (_DWORD *)*v67;
              }
              for ( k = (_DWORD *)a1[7]; k != a1 + 7; k = (_DWORD *)*k )
              {
                v85 = k[2];
                if ( v86 || !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), k[3], a4) )
                {
                  if ( (a4 & 0x10010000) != 0 )
                    return -1073739511;
                  if ( !k[7] )
                  {
                    k = (_DWORD *)k[1];
                    v71 = v85;
                    *(_BYTE *)(v85 + 37) = KeAcquireQueuedSpinLock(7);
                    __dmb(0xBu);
                    v72 = (unsigned int *)(v71 + 56);
                    do
                      v73 = __ldrex(v72);
                    while ( __strex(0, v72) );
                    __dmb(0xBu);
                    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v85 + 37));
                    v74 = (_DWORD *)*k;
                    if ( *(_BYTE *)(v85 + 36) )
                    {
                      FsRtlpRemoveAndBreakRHIrp(v74, (int)a1, 0, -1073741536, 0, 0);
                      v88 = 1;
                    }
                    else
                    {
                      FsRtlpRemoveAndBreakRHIrp(v74, (int)a1, 0, 0, 0, 1);
                      v94 = 0;
                      if ( (a5 & 0x2000) != 0 )
                      {
                        v12 = 1;
                        v81 = 1;
                      }
                      v95 = v86;
                    }
                  }
                }
              }
            }
            if ( v88 )
              FsRtlpReleaseIrpsWaitingForRH((int)a1);
            if ( !v12 && (_DWORD *)a1[9] != a1 + 9 && (a5 & 0x2000) != 0 )
            {
              if ( v86 )
              {
LABEL_166:
                v81 = 1;
                v12 = 1;
              }
              else
              {
                for ( l = (_DWORD *)a1[9]; l != a1 + 9; l = (_DWORD *)*l )
                {
                  if ( !FsRtlpOplockKeysEqual(l[3], *(_DWORD *)(a2 + 28), 0) )
                    goto LABEL_166;
                }
              }
            }
            FsRtlpComputeShareableOplockState(a1);
            goto LABEL_200;
          case 12288:
            goto LABEL_115;
          case 20544:
            if ( (a5 & 0x5000) == 20480 )
            {
              v46 = *a1;
              v91 = *a1;
              *(_BYTE *)(v46 + 37) = KeAcquireQueuedSpinLock(7);
              __dmb(0xBu);
              v47 = (unsigned int *)(v46 + 56);
              do
                v48 = __ldrex(v47);
              while ( __strex(0, v47) );
              __dmb(0xBu);
              KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v46 + 37));
              if ( !*(_BYTE *)(v46 + 36) )
              {
                v49 = *(_DWORD *)(v46 + 12);
                memset((_BYTE *)v49, 0, 24);
                *(_WORD *)v49 = 1;
                *(_WORD *)(v49 + 2) = 24;
                v50 = a1[18];
                if ( (v50 & 0x4000) != 0 )
                  v51 = 4;
                else
                  v51 = 0;
                if ( (v50 & 0x2000) != 0 )
                  v52 = 2;
                else
                  v52 = 0;
                *(_DWORD *)(v49 + 4) = v52 | v51 | ((a1[18] & 0x1000) != 0);
                *(_DWORD *)(v49 + 8) = 0;
                *(_DWORD *)(v49 + 12) |= 1u;
                *(_DWORD *)(v91 + 28) = 24;
                *(_DWORD *)(*a1 + 24) = 0;
                pIofCompleteRequest(*a1, 1);
                *a1 = 0;
                v30 = a1[18] & 0x20;
                v31 = 8409152;
                goto LABEL_54;
              }
            }
            else
            {
              if ( (a5 & 0x4000) == 0 )
                goto LABEL_200;
              v53 = *a1;
              *(_BYTE *)(v53 + 37) = KeAcquireQueuedSpinLock(7);
              __dmb(0xBu);
              v54 = (unsigned int *)(v53 + 56);
              do
                v55 = __ldrex(v54);
              while ( __strex(0, v54) );
              __dmb(0xBu);
              KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v53 + 37));
              if ( !*(_BYTE *)(v53 + 36) )
              {
                v56 = *(_DWORD *)(v53 + 12);
                memset((_BYTE *)v56, 0, 24);
                *(_WORD *)v56 = 1;
                *(_WORD *)(v56 + 2) = 24;
                v57 = a1[18];
                if ( (v57 & 0x4000) != 0 )
                  v58 = 4;
                else
                  v58 = 0;
                if ( (v57 & 0x2000) != 0 )
                  v59 = 2;
                else
                  v59 = 0;
                *(_DWORD *)(v56 + 4) = v59 | v58 | ((a1[18] & 0x1000) != 0);
                *(_DWORD *)(v56 + 8) = 1;
                *(_DWORD *)(v56 + 12) |= 1u;
                *(_DWORD *)(v53 + 28) = 24;
                *(_DWORD *)(*a1 + 24) = 0;
                pIofCompleteRequest(*a1, 1);
                *a1 = 0;
                v31 = a1[18] & 0x20;
                v30 = 1069120;
                goto LABEL_54;
              }
            }
            break;
          case 28736:
            if ( a5 == 0x4000 )
            {
              v23 = *a1;
              *(_BYTE *)(v23 + 37) = KeAcquireQueuedSpinLock(7);
              __dmb(0xBu);
              v24 = (unsigned int *)(v23 + 56);
              do
                v25 = __ldrex(v24);
              while ( __strex(0, v24) );
              __dmb(0xBu);
              KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v23 + 37));
              if ( !*(_BYTE *)(v23 + 36) )
              {
                v26 = *(_DWORD *)(v23 + 12);
                memset((_BYTE *)v26, 0, 24);
                *(_WORD *)v26 = 1;
                *(_WORD *)(v26 + 2) = 24;
                v27 = a1[18];
                if ( (v27 & 0x4000) != 0 )
                  v28 = 4;
                else
                  v28 = 0;
                if ( (v27 & 0x2000) != 0 )
                  v29 = 2;
                else
                  v29 = 0;
                *(_DWORD *)(v26 + 4) = v29 | v28 | ((a1[18] & 0x1000) != 0);
                *(_DWORD *)(v26 + 8) = 3;
                *(_DWORD *)(v26 + 12) |= 1u;
                *(_DWORD *)(v23 + 28) = 24;
                *(_DWORD *)(*a1 + 24) = 0;
                pIofCompleteRequest(*a1, 1);
                *a1 = 0;
                v30 = a1[18] & 0x20;
                v31 = 5271616;
LABEL_54:
                a1[18] = v31 | v30;
                goto LABEL_198;
              }
            }
            else if ( a5 == 0x2000 )
            {
              v32 = *a1;
              *(_BYTE *)(v32 + 37) = KeAcquireQueuedSpinLock(7);
              __dmb(0xBu);
              v33 = (unsigned int *)(v32 + 56);
              do
                v34 = __ldrex(v33);
              while ( __strex(0, v33) );
              __dmb(0xBu);
              KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v32 + 37));
              if ( !*(_BYTE *)(v32 + 36) )
              {
                v35 = *(_DWORD *)(v32 + 12);
                memset((_BYTE *)v35, 0, 24);
                *(_WORD *)v35 = 1;
                *(_WORD *)(v35 + 2) = 24;
                v36 = a1[18];
                if ( (v36 & 0x4000) != 0 )
                  v37 = 4;
                else
                  v37 = 0;
                if ( (v36 & 0x2000) != 0 )
                  v38 = 2;
                else
                  v38 = 0;
                *(_DWORD *)(v35 + 4) = v38 | v37 | ((a1[18] & 0x1000) != 0);
                *(_DWORD *)(v35 + 8) = 5;
                *(_DWORD *)(v35 + 12) |= 1u;
                if ( !*(_BYTE *)a2 )
                {
                  *(_DWORD *)(v35 + 12) |= 2u;
                  *(_DWORD *)(v35 + 16) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 4) + 20);
                  *(_WORD *)(v35 + 20) = *(_WORD *)(a2 + 18);
                }
                *(_DWORD *)(v32 + 28) = 24;
                *(_DWORD *)(*a1 + 24) = 0;
                pIofCompleteRequest(*a1, 1);
                *a1 = 0;
                v30 = a1[18] & 0x20;
                v31 = 3174464;
                goto LABEL_54;
              }
            }
            else
            {
              if ( (a5 & 0x5000) != 20480 )
                goto LABEL_200;
              v39 = *a1;
              v90 = *a1;
              *(_BYTE *)(v39 + 37) = KeAcquireQueuedSpinLock(7);
              __dmb(0xBu);
              v40 = (unsigned int *)(v39 + 56);
              do
                v41 = __ldrex(v40);
              while ( __strex(0, v40) );
              __dmb(0xBu);
              KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v39 + 37));
              if ( !*(_BYTE *)(v39 + 36) )
              {
                v42 = *(_DWORD *)(v39 + 12);
                memset((_BYTE *)v42, 0, 24);
                *(_WORD *)v42 = 1;
                *(_WORD *)(v42 + 2) = 24;
                v43 = a1[18];
                if ( (v43 & 0x4000) != 0 )
                  v44 = 4;
                else
                  v44 = 0;
                if ( (v43 & 0x2000) != 0 )
                  v45 = 2;
                else
                  v45 = 0;
                *(_DWORD *)(v42 + 4) = v45 | v44 | ((a1[18] & 0x1000) != 0);
                *(_DWORD *)(v42 + 8) = 0;
                *(_DWORD *)(v42 + 12) |= 1u;
                *(_DWORD *)(v90 + 28) = 24;
                *(_DWORD *)(*a1 + 24) = 0;
                pIofCompleteRequest(*a1, 1);
                *a1 = 0;
                v30 = a1[18] & 0x20;
                v31 = 8417344;
                goto LABEL_54;
              }
            }
            break;
          case 45056:
            goto LABEL_104;
          case 1060864:
            v18 = 0;
            v89 = 0;
            if ( (a5 & 0x1000) != 0 )
            {
              v19 = (_DWORD *)a1[9];
              v20 = a4;
              while ( v19 != a1 + 9 )
              {
                if ( v86 || (v20 = a4, !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), v19[3], a4)) )
                {
                  v89 = 1;
                  if ( (v20 & 0x10010000) != 0 )
                    return -1073739511;
                  v21 = v19[6] & 0xFF0FFFFF;
                  v19[6] = v21;
                  v19[6] = v21 | 0x800000;
                }
                v19 = (_DWORD *)*v19;
              }
              FsRtlpComputeShareableOplockState(a1);
              v18 = v89;
            }
            if ( (a5 & 0x2000) == 0 )
              goto LABEL_200;
            if ( !v18 )
            {
              if ( (a5 & 0x1000) == 0 )
              {
                for ( m = (_DWORD *)a1[9]; m != a1 + 9; m = (_DWORD *)*m )
                {
                  if ( v86 || !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), m[3], 0) )
                    goto LABEL_36;
                }
              }
              goto LABEL_200;
            }
LABEL_36:
            v12 = 1;
            goto LABEL_199;
          default:
            goto LABEL_181;
        }
        FsRtlpModifyThreadPriorities(a1, 0, 0);
        FsRtlpClearOwnerThread((int)a1, 0);
        *((_BYTE *)a1 + 16) = 0;
        *(_DWORD *)(*a1 + 24) = -1073741536;
        pIofCompleteRequest(*a1, 1);
        *a1 = 0;
        ObfDereferenceObjectWithTag(a1[1]);
        a1[1] = 0;
        a1[18] = a1[18] & 0x20 | 1;
        while ( (_DWORD *)a1[11] != a1 + 11 )
          FsRtlpRemoveAndCompleteWaitingIrp(a1[11]);
        goto LABEL_200;
      }
      if ( (a5 & 0x1000) != 0 )
        a1[18] = a1[18] & 0x20 | 0x805040;
LABEL_172:
      v76 = (a5 & 0x5000) == 0;
      goto LABEL_173;
    }
    if ( v17 != 1077312 )
    {
      if ( v17 == 3174464 )
      {
        if ( a5 == 0x4000 )
        {
LABEL_191:
          v78 = a1[18] & 0x20 | 0x107040;
LABEL_197:
          a1[18] = v78;
          goto LABEL_198;
        }
        if ( (a5 & 0x5000) != 20480 )
          goto LABEL_198;
LABEL_196:
        v78 = a1[18] & 0x20 | 0x807040;
        goto LABEL_197;
      }
      if ( v17 != 5271616 )
      {
        if ( v17 == 8400896 )
        {
          if ( (a5 & 0x3000) != 0 )
          {
            if ( (a4 & 0x10010000) != 0 )
              return -1073739511;
            if ( (a5 & 0x2000) != 0 )
            {
              for ( n = (_DWORD *)a1[9]; n != a1 + 9; n = (_DWORD *)*n )
              {
                if ( v86 || !FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), n[3], 0) )
                  goto LABEL_198;
              }
            }
          }
LABEL_200:
          if ( !v12 )
            return v83;
          if ( (a4 & 1) == 0 )
          {
            if ( v94 )
            {
              FsRtlpModifyThreadPriorities(a1, 0, 1);
              FsRtlpOplockSendModernAppTermination(a1, 0);
            }
            *a9 = 0;
            return FsRtlpWaitOnIrp(a1, a3, a6, a7, a8, &v96, v95, a10, v81);
          }
          v79 = a1[18];
          if ( (v79 & 0x10000) != 0 )
            a1[18] = v79 | 0x20000;
          return 264;
        }
        if ( v17 != 8409152 )
        {
          if ( v17 != 8417344 )
          {
LABEL_181:
            v76 = (v15 & 0x1000000) == 0;
LABEL_173:
            if ( v76 )
              goto LABEL_200;
          }
LABEL_198:
          v12 = 1;
LABEL_199:
          v81 = 1;
          goto LABEL_200;
        }
        goto LABEL_172;
      }
      if ( a5 == 0x2000 )
        goto LABEL_191;
    }
    if ( (a5 & 0x1000) == 0 )
      goto LABEL_198;
    goto LABEL_196;
  }
  if ( a3 )
  {
    *(_DWORD *)(a3 + 24) = -1073741597;
    pIofCompleteRequest(a3, 1);
  }
  return -1073741597;
}
