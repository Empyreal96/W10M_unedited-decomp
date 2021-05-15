// AlpcpProcessSynchronousRequest 
 
int __fastcall AlpcpProcessSynchronousRequest(_DWORD *a1, int a2, int a3, int a4, unsigned int a5, unsigned int *a6, unsigned int a7, unsigned int a8, char a9, char a10)
{
  unsigned int v10; // lr
  int v11; // r2
  int v13; // r6
  unsigned int v14; // r5
  int v15; // r10
  __int64 *v16; // r2
  unsigned int *v17; // r4
  int *v18; // r2
  unsigned int *v19; // r2
  int *v20; // r8
  int *v21; // r2
  int v22; // r1
  unsigned int v23; // r2
  _DWORD **v24; // r6
  unsigned int *v25; // r10
  int v26; // r0
  int v27; // r5
  unsigned int v28; // r2
  unsigned int *v29; // r5
  unsigned int v30; // r2
  unsigned int *v31; // r4
  unsigned int v32; // r2
  int v34; // r0
  int v35; // r10
  int v36; // r6
  unsigned int v37; // r10
  int v38; // r8
  unsigned int *v39; // r5
  unsigned int v40; // r1
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v43; // r0
  int v44; // r0
  _DWORD *v45; // lr
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r3
  unsigned int v50; // r2
  int v51; // r1
  int v52; // r0
  int v53; // r5
  int v54; // r3
  int *v55; // r10
  int v56; // r3
  int v57; // r2
  int v58; // lr
  int v59; // r4
  unsigned int *v60; // r2
  unsigned int v61; // r0
  int v62; // r4
  int v63; // r0
  unsigned int *v64; // r2
  unsigned int v65; // r1
  int v66; // r1
  int v67; // r2
  int v68; // r1
  int v69; // r3
  int *v70; // r2
  int v71; // r3
  int v72; // r3
  int v73; // r3
  int v74; // r0
  int v75; // r3
  int v76; // r3
  unsigned int v77; // r2
  unsigned int *v78; // r2
  unsigned int v79; // r1
  int v80; // r0
  int v81; // r4
  unsigned int *v82; // r5
  unsigned int v83; // r1
  unsigned int *v84; // r2
  unsigned int v85; // r0
  int v86; // r0
  int v88; // [sp+8h] [bp-A0h]
  _DWORD *v89; // [sp+Ch] [bp-9Ch]
  int v90; // [sp+18h] [bp-90h] BYREF
  int v91; // [sp+1Ch] [bp-8Ch]
  int v92; // [sp+20h] [bp-88h]
  bool v93; // [sp+28h] [bp-80h] BYREF
  int v94; // [sp+2Ch] [bp-7Ch]
  __int64 *v95; // [sp+30h] [bp-78h]
  int v96; // [sp+34h] [bp-74h]
  int v97; // [sp+38h] [bp-70h]
  unsigned int *v98; // [sp+3Ch] [bp-6Ch]
  int v99; // [sp+40h] [bp-68h]
  _DWORD *v100; // [sp+44h] [bp-64h]
  int v101; // [sp+48h] [bp-60h]
  int v102; // [sp+4Ch] [bp-5Ch]
  __int64 v103; // [sp+50h] [bp-58h]
  int v104; // [sp+58h] [bp-50h]
  __int64 v105; // [sp+60h] [bp-48h] BYREF
  _DWORD _68[22]; // [sp+68h] [bp-40h] BYREF

  v96 = a4;
  _68[21] = a4;
  v10 = a3;
  v90 = a3;
  _68[20] = a3;
  v11 = a2;
  _68[19] = a2;
  _68[18] = a1;
  v13 = 0;
  v99 = 0;
  v102 = 0;
  v14 = -1;
  v97 = -1;
  v101 = -1;
  v15 = a9;
  v104 = a9;
  if ( a9 )
  {
    v16 = (__int64 *)a8;
    v95 = (__int64 *)a8;
    if ( a8 )
    {
      if ( a8 >= MmUserProbeAddress )
        v16 = (__int64 *)MmUserProbeAddress;
      v103 = *v16;
      v105 = v103;
      v95 = &v105;
    }
    v100 = (_DWORD *)a5;
    if ( (a5 & 7) != 0 )
      ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
    if ( a5 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a5 = *(_BYTE *)a5;
    *(_BYTE *)(a5 + 16) = *(_BYTE *)(a5 + 16);
    v17 = a6;
    v98 = a6;
    if ( a6 )
    {
      v18 = (int *)a6;
      if ( (unsigned int)a6 >= MmUserProbeAddress )
        v18 = (int *)MmUserProbeAddress;
      v97 = *v18;
      v14 = v97;
      v101 = v97;
      v19 = a6;
      if ( (unsigned int)a6 >= MmUserProbeAddress )
        v19 = (unsigned int *)MmUserProbeAddress;
      *v19 = *v19;
    }
    v20 = (int *)a7;
    if ( a7 )
    {
      v21 = (int *)a7;
      if ( a7 >= MmUserProbeAddress )
        v21 = (int *)MmUserProbeAddress;
      v22 = *v21;
      v23 = 8;
      if ( v22 < 0 )
        v23 = 20;
      if ( (v22 & 0x40000000) != 0 )
        v23 += 16;
      v92 = 0x20000000;
      if ( (v22 & 0x20000000) != 0 )
        v23 += 20;
      v91 = 0x10000000;
      if ( (v22 & 0x10000000) != 0 )
        v23 += 16;
      v94 = 0x8000000;
      if ( (v22 & 0x8000000) != 0 )
        v23 += 24;
      if ( (v22 & 0x4000000) != 0 )
        v23 += 4;
      if ( (a7 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
      if ( a7 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a7 = *(_BYTE *)a7;
      if ( v23 > 4 )
        *(_BYTE *)(((v23 - 1) & 0xFFFFFFFC) + a7) = *(_BYTE *)(((v23 - 1) & 0xFFFFFFFC) + a7);
      v13 = v22;
      v99 = v22;
      v102 = v22;
    }
    else
    {
      v92 = 0x20000000;
      v91 = 0x10000000;
      v94 = 0x8000000;
    }
    v11 = a2;
  }
  else
  {
    v17 = a6;
    v98 = a6;
    if ( a6 )
    {
      v14 = *a6;
      v97 = *a6;
    }
    v20 = (int *)a7;
    if ( a7 )
    {
      v13 = *(_DWORD *)a7;
      v99 = *(_DWORD *)a7;
    }
    v92 = 0x20000000;
    v91 = 0x10000000;
    v94 = 0x8000000;
    v95 = (__int64 *)a8;
    v100 = (_DWORD *)a5;
  }
  if ( (a1[61] & 6) != 6 )
  {
    v89 = a1;
    LODWORD(v103) = a1;
    goto LABEL_69;
  }
  v24 = (_DWORD **)a1[2];
  v25 = (unsigned int *)(v24 - 1);
  v26 = KeAbPreAcquire((unsigned int)(v24 - 1), 0, 0);
  v27 = v26;
  do
    v28 = __ldrex(v25);
  while ( !v28 && __strex(0x11u, v25) );
  __dmb(0xBu);
  if ( v28 )
    ExfAcquirePushLockSharedEx(v24 - 1, v26, (unsigned int)(v24 - 1));
  if ( v27 )
    *(_BYTE *)(v27 + 14) |= 1u;
  v89 = *v24;
  LODWORD(v103) = v89;
  if ( v89 && ObReferenceObjectSafe((int)v89) )
  {
    v29 = (unsigned int *)(v24 - 1);
    __dmb(0xBu);
    do
      v30 = __ldrex(v29);
    while ( v30 == 17 && __strex(0, v29) );
    if ( v30 != 17 )
      ExfReleasePushLockShared(v24 - 1);
    KeAbPostRelease((unsigned int)(v24 - 1));
    v14 = v97;
    v13 = v99;
    v11 = a2;
    v10 = v90;
    v15 = v104;
LABEL_69:
    _68[0] = a1;
    _68[6] = v11;
    if ( (a1[61] & 0x1000) != 0 )
      v34 = AlpcpSendLegacySynchronousRequest(a1, (int)_68, v10, v15);
    else
      v34 = AlpcpSendMessage(_68, v10);
    v35 = v34;
    if ( v34 >= 0 )
    {
      v90 = 0;
      _68[0] = v89;
      v35 = AlpcpReceiveSynchronousReply(_68, a10, &v90, v13, v95);
      if ( !v35 )
      {
        v36 = v90;
        v37 = *(unsigned __int16 *)(v90 + 120) + 24;
        if ( v17 && v37 > v14 )
        {
          v88 = AlpcpReturnMessageOnInsufficientBuffer(v89, v90);
          if ( v88 == -1073741789 )
          {
            if ( AlpcpMessageLogEnabled )
              AlpcpEnterStateChangeEventMessageLog(v36);
            v38 = 0;
            if ( (*(_BYTE *)(v36 - 16) & 1) != 0 )
            {
              v38 = 0x10000 - *(__int16 *)(v36 - 14);
              *(_BYTE *)(v36 - 16) &= 0xFEu;
              *(_WORD *)(v36 - 14) = 0;
            }
            v39 = (unsigned int *)(v36 - 4);
            __dmb(0xBu);
            do
              v40 = __ldrex(v39);
            while ( __strex(v40 - 1, v39) );
            if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)(v36 - 4));
            KeAbPostRelease(v36 - 4);
            if ( v38 > 0 )
            {
              __dmb(0xBu);
              v41 = (unsigned int *)(v36 - 12);
              do
              {
                v42 = __ldrex(v41);
                v43 = v42 - v38;
              }
              while ( __strex(v43, v41) );
              __dmb(0xBu);
              if ( v43 <= 0 )
              {
                if ( v43 )
                  KeBugCheckEx(24, 0, v36, 40, v43);
                AlpcpDestroyBlob(v36);
              }
            }
            *v17 = v37;
            v35 = -1073741789;
            v44 = (int)v89;
            goto LABEL_196;
          }
          AlpcpCancelMessage(v89, v36, 0x10000);
          v35 = v88;
        }
        else
        {
          v45 = v100;
          v46 = *(_DWORD *)(v90 + 124);
          v47 = *(_DWORD *)(v90 + 128);
          v48 = *(_DWORD *)(v90 + 132);
          *v100 = *(_DWORD *)(v90 + 120);
          v45[1] = v46;
          v45[2] = v47;
          v45[3] = v48;
          v49 = *(_DWORD *)(v36 + 140);
          v45[4] = *(_DWORD *)(v36 + 136);
          v45[5] = v49;
          if ( (a1[38] & 0x1000) != 0 )
            *((_WORD *)v45 + 2) &= 0xC00Fu;
          if ( *(_DWORD *)(v36 + 88) )
          {
            AlpcpGetDataFromUserVaSafe(v36, v45 + 6);
          }
          else
          {
            v50 = *(unsigned __int16 *)(v36 + 120);
            v51 = v36 + 144;
            v52 = (int)(v45 + 6);
            if ( v50 > 0x100 )
            {
              memmove(v52, v51, 0x100u);
              v50 = *(unsigned __int16 *)(v36 + 120) - 256;
              v51 = *(_DWORD *)(v36 + 108);
              v52 = (int)(v45 + 70);
            }
            memmove(v52, v51, v50);
          }
          if ( v98 )
            *v98 = v37;
          if ( v20 )
          {
            v53 = *v20;
            v20[1] = 0;
            if ( v53 < 0 && *(_DWORD *)(v36 + 72) )
            {
              v20[2] = 0;
              v20[4] = *(_DWORD *)(*(_DWORD *)(v36 + 72) + 4);
              v20[1] |= 0x80000000;
            }
            if ( (v53 & 0x40000000) != 0 )
            {
              v54 = 2;
              if ( (v53 & 0x80000000) != 0 )
                v54 = 5;
              v55 = &v20[v54];
              v56 = *(_DWORD *)(v36 + 76);
              if ( v56 )
              {
                v57 = *(_DWORD *)(v56 + 8);
                v96 = v57;
                v58 = *(_DWORD *)(v57 - 12);
                while ( v58 > 0 )
                {
                  v59 = v58;
                  __dmb(0xBu);
                  v60 = (unsigned int *)(v57 - 12);
                  do
                    v61 = __ldrex(v60);
                  while ( v61 == v58 && __strex(v58 + 1, v60) );
                  v58 = v61;
                  __dmb(0xBu);
                  if ( v61 == v59 )
                    goto LABEL_121;
                  v57 = v96;
                }
                if ( v58 )
                  KeBugCheckEx(24, 0, v57, 32, v58);
LABEL_121:
                v62 = AlpcpReceiveView((int)a1, v36, &v93);
                __dmb(0xBu);
                v63 = v96;
                v64 = (unsigned int *)(v96 - 12);
                do
                {
                  v65 = __ldrex(v64);
                  v66 = v65 - 1;
                }
                while ( __strex(v66, v64) );
                __dmb(0xBu);
                if ( v66 <= 0 )
                {
                  if ( v66 )
                    KeBugCheckEx(24, 0, v63, 33, v66);
                  AlpcpDestroyBlob(v63);
                }
                if ( v62 >= 0 )
                {
                  v67 = *(_DWORD *)(v36 + 76);
                  *v55 = 0;
                  v55[1] = 0;
                  v55[2] = 0;
                  v55[3] = 0;
                  v55[2] = *(_DWORD *)(v67 + 20);
                  v55[3] = *(_DWORD *)(v67 + 24);
                  if ( v93 )
                    *v55 = 0x40000;
                  v20[1] |= 0x40000000u;
                }
              }
            }
            v68 = v92;
            if ( (v53 & v92) != 0 )
            {
              v69 = 2;
              if ( (v53 & 0x80000000) != 0 )
                v69 = 5;
              if ( (v53 & 0x40000000) != 0 )
                v69 += 4;
              v70 = &v20[v69];
              if ( *(_DWORD **)(v36 + 32) == a1 || *(_DWORD **)(v36 + 36) == a1 )
                v71 = *(_DWORD *)(v36 + 68);
              else
                v71 = *(_DWORD *)(v36 + 64);
              *v70 = v71;
              if ( *(_DWORD **)(v36 + 32) == a1 || *(_DWORD **)(v36 + 36) == a1 )
                v72 = *(_DWORD *)(v36 + 40);
              else
                v72 = *(_DWORD *)(v36 + 24);
              v70[2] = v72;
              if ( (a1[61] & 6) == 4 )
                v73 = *(_DWORD *)(v36 + 56);
              else
                v73 = *(_DWORD *)(v36 + 60);
              v70[1] = v73;
              v70[3] = *(_DWORD *)(v36 + 136);
              v70[4] = *(_DWORD *)(v36 + 140);
              if ( *v70 )
                v20[1] |= v68;
            }
            v74 = v91;
            if ( (v53 & v91) != 0 )
            {
              v75 = 2;
              if ( (v53 & 0x80000000) != 0 )
                v75 = 5;
              if ( (v53 & 0x40000000) != 0 )
                v75 += 4;
              if ( (v53 & 0xE0000000 & v68) != 0 )
                v75 += 5;
              AlpcpExposeHandleAttribute(a1, v36, &v20[v75], v20 + 1);
              v68 = v92;
              v74 = v91;
            }
            if ( (v53 & v94) != 0 )
            {
              v76 = 2;
              v77 = v53 & 0xF0000000;
              if ( (v53 & 0x80000000) != 0 )
                v76 = 5;
              if ( (v53 & 0x40000000) != 0 )
                v76 += 4;
              if ( (v77 & v68) != 0 )
                v76 += 5;
              if ( (v77 & v74) != 0 )
                v76 += 4;
              AlpcpExposeTokenAttribute((int)a1, (_DWORD *)v36, &v20[v76], v20 + 1);
            }
          }
          v35 = 0;
          if ( (*(_DWORD *)(v36 + 20) & 0x200) != 0 && (a1[61] & 0x2000) != 0 )
          {
            __dmb(0xBu);
            v78 = a1 + 64;
            do
              v79 = __ldrex(v78);
            while ( !v79 && __strex(v36, v78) );
            __dmb(0xBu);
            if ( !v79 )
            {
              if ( AlpcpMessageLogEnabled )
                AlpcpEnterFreeEventMessageLog(v36);
              ++*(_WORD *)(v36 - 14);
              *(_DWORD *)(v36 + 136) |= 0x80000000;
              v80 = *(_DWORD *)(v36 + 12);
              if ( v80 )
              {
                if ( (*(_DWORD *)(v36 + 20) & 0x1000) != 0 )
                  ObfDereferenceObject(v80);
                *(_DWORD *)(v36 + 12) = 0;
              }
            }
          }
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v36);
          v81 = 0;
          if ( (*(_BYTE *)(v36 - 16) & 1) != 0 )
          {
            v81 = 0x10000 - *(__int16 *)(v36 - 14);
            *(_BYTE *)(v36 - 16) &= 0xFEu;
            *(_WORD *)(v36 - 14) = 0;
          }
          v82 = (unsigned int *)(v36 - 4);
          __dmb(0xBu);
          do
            v83 = __ldrex(v82);
          while ( __strex(v83 - 1, v82) );
          if ( (v83 & 2) != 0 && (v83 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v36 - 4));
          KeAbPostRelease(v36 - 4);
          if ( v81 > 0 )
          {
            __dmb(0xBu);
            v84 = (unsigned int *)(v36 - 12);
            do
            {
              v85 = __ldrex(v84);
              v86 = v85 - v81;
            }
            while ( __strex(v86, v84) );
            __dmb(0xBu);
            if ( v86 <= 0 )
            {
              if ( v86 )
                KeBugCheckEx(24, 0, v36, 40, v86);
              AlpcpDestroyBlob(v36);
            }
          }
        }
      }
    }
    v44 = (int)v89;
LABEL_196:
    if ( (_DWORD *)v44 != a1 )
      ObfDereferenceObject(v44);
    return v35;
  }
  v31 = (unsigned int *)(v24 - 1);
  __dmb(0xBu);
  do
    v32 = __ldrex(v31);
  while ( v32 == 17 && __strex(0, v31) );
  if ( v32 != 17 )
    ExfReleasePushLockShared(v24 - 1);
  KeAbPostRelease((unsigned int)(v24 - 1));
  return -1073741769;
}
