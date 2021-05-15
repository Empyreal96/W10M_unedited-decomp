// NtNotifyChangeMultipleKeys 
 
int __fastcall NtNotifyChangeMultipleKeys(int a1, int a2, int a3, int a4, int (*a5)(), int a6, int *a7, int a8, unsigned __int8 a9, unsigned int a10, int a11, char a12)
{
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r4
  unsigned int v20; // r4
  unsigned int v21; // r1
  bool v22; // zf
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // lr
  int v26; // r6
  int (*v27)(); // r8
  unsigned int v28; // r1
  int v29; // r0
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r9
  int v33; // r4
  int v34; // r0
  _DWORD *v35; // r6
  int v36; // r3
  _DWORD *v37; // r0
  _DWORD *v38; // r0
  char v39; // r1
  _DWORD *v40; // r3
  int v41; // r8
  _DWORD *v42; // r0
  _DWORD *v43; // r0
  unsigned int v44; // r2
  unsigned int v45; // r3
  unsigned int v46; // r8
  int v47; // r0
  int v48; // r4
  unsigned int v49; // r2
  unsigned int v50; // r8
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r2
  int v54; // r10
  unsigned int v55; // r8
  int v56; // r0
  int v57; // r4
  unsigned int v58; // r2
  int v59; // r0
  int v60; // r4
  unsigned int v61; // r2
  unsigned int v62; // r8
  int v63; // r0
  int v64; // r4
  unsigned int v65; // r2
  int v66; // r0
  int v67; // r4
  unsigned int v68; // r2
  unsigned int v69; // r1
  unsigned int *v70; // r6
  unsigned int v71; // r1
  unsigned int *v72; // r6
  unsigned int v73; // r1
  unsigned int *v74; // r6
  unsigned int v75; // r1
  _DWORD *v76; // r0
  int v77; // r1
  _DWORD *v78; // r2
  int v79; // r0
  int v80; // lr
  _DWORD *v81; // r2
  unsigned int v82; // r1
  int v83; // r3
  unsigned int *v84; // r10
  unsigned int v85; // r1
  unsigned int *v86; // r10
  unsigned int v87; // r1
  unsigned int *v88; // r10
  unsigned int v89; // r1
  _DWORD *v90; // r0
  unsigned int v91; // r0
  unsigned int v92; // r1
  int v93; // r0
  __int16 v94; // r3
  int v95; // r0
  unsigned int v96; // r9
  int v97; // r0
  int v98; // r4
  unsigned int v99; // r2
  int v100; // r4
  _DWORD *v101; // r9
  int v102; // r2
  _DWORD **v103; // r1
  int v104; // r0
  _DWORD *v105; // r1
  int v106; // r2
  _DWORD *v107; // r1
  int v108; // r0
  _DWORD *v109; // r1
  unsigned int v110; // r1
  int *v111; // r2
  int v112; // r8
  int v113; // r0
  int v114; // r9
  unsigned int v115; // r2
  int v116; // lr
  int v117; // r10
  _DWORD *v118; // r9
  int v119; // r2
  _DWORD **v120; // r1
  int v121; // r0
  _DWORD *v122; // r1
  int v123; // r2
  _DWORD *v124; // r1
  int v125; // r0
  _DWORD *v126; // r1
  unsigned int v127; // r1
  unsigned int v128; // r1
  __int16 v129; // r3
  int v131; // [sp+0h] [bp-D0h]
  int v132; // [sp+0h] [bp-D0h]
  int *v133; // [sp+4h] [bp-CCh]
  int v134; // [sp+4h] [bp-CCh]
  int *v135; // [sp+8h] [bp-C8h]
  int v136; // [sp+8h] [bp-C8h]
  int v137; // [sp+10h] [bp-C0h] BYREF
  char v138; // [sp+14h] [bp-BCh]
  int v139; // [sp+18h] [bp-B8h] BYREF
  int v140; // [sp+1Ch] [bp-B4h]
  char v141; // [sp+20h] [bp-B0h]
  int v142; // [sp+24h] [bp-ACh]
  _DWORD *v143; // [sp+28h] [bp-A8h]
  int v144; // [sp+2Ch] [bp-A4h]
  int v145; // [sp+30h] [bp-A0h]
  int v146; // [sp+34h] [bp-9Ch]
  char v147; // [sp+38h] [bp-98h]
  int v148; // [sp+3Ch] [bp-94h]
  unsigned int v149; // [sp+40h] [bp-90h]
  int *v150; // [sp+44h] [bp-8Ch]
  int v151; // [sp+48h] [bp-88h] BYREF
  _DWORD *v152; // [sp+4Ch] [bp-84h]
  int v153; // [sp+50h] [bp-80h]
  int v154; // [sp+54h] [bp-7Ch]
  int v155; // [sp+5Ch] [bp-74h]
  int v156; // [sp+60h] [bp-70h] BYREF
  _BYTE v157[76]; // [sp+64h] [bp-6Ch] BYREF
  int varg_r0; // [sp+D8h] [bp+8h]
  int varg_r1; // [sp+DCh] [bp+Ch]
  int varg_r2; // [sp+E0h] [bp+10h]
  int varg_r3; // [sp+E4h] [bp+14h]

  v154 = a4;
  varg_r3 = a4;
  v155 = a3;
  varg_r2 = a3;
  v149 = a2;
  varg_r1 = a2;
  v137 = a1;
  varg_r0 = a1;
  v144 = 0;
  v151 = 0;
  v143 = 0;
  v152 = 0;
  v145 = 1;
  v153 = 1;
  v142 = 0;
  v138 = 0;
  v156 = 0;
  memset(v157, 0, sizeof(v157));
  v146 = 0;
  v139 = 0;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  __pld(&CmpShutdownRundown);
  v14 = CmpShutdownRundown & 0xFFFFFFFE;
  v15 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v16 != v14 )
  {
    v14 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v14 )
    {
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x134) + 1;
      *(_WORD *)(v17 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
        KiCheckForKernelApcDelivery(0);
      return -1073741431;
    }
  }
  v140 = 1;
  v141 = 1;
  if ( v149 > 1 )
  {
    __pld(&CmpShutdownRundown);
    v20 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v21 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
    v22 = v21 == v20;
LABEL_16:
    if ( !v22 )
      v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v14);
    return -1073741811;
  }
  if ( v149 == 1 )
  {
    v142 = 1;
    v138 = 1;
  }
  v25 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v148 = v25;
  v147 = v25;
  if ( !v25 )
  {
    if ( !a12 || (v145 = 3, !v149) )
    {
      v26 = a8;
      v150 = a7;
      v27 = a5;
      goto LABEL_40;
    }
LABEL_31:
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v28 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
    v22 = v28 == v14;
    goto LABEL_16;
  }
  v26 = a8;
  if ( (a8 & 0x10000000) != 0 )
  {
    if ( a12 )
    {
      v27 = a5;
      if ( !a5 )
      {
        if ( a4 )
        {
          v145 = 4;
          v150 = a7;
LABEL_40:
          v29 = v137;
          goto LABEL_41;
        }
      }
    }
    goto LABEL_31;
  }
  v150 = a7;
  ProbeForWrite((unsigned int)a7, 8, 4);
  ProbeForWrite(a10, a11, 4);
  *a7 = 259;
  a7[1] = 0;
  v29 = v137;
  v25 = v148;
  v27 = a5;
  if ( a12 )
    v145 = 2;
LABEL_41:
  if ( v26 != (v26 & 0x1000000F) )
    goto LABEL_31;
  v19 = CmObReferenceObjectByHandle(v29, 16, (int)CmKeyObjectType, v25, &v137, 0);
  if ( v19 >= 0 )
  {
    v32 = 0;
    v151 = 0;
    v33 = v142;
    if ( v142 )
    {
      v135 = &v151;
      v133 = &v156;
      v131 = v148;
      v19 = ObReferenceObjectByNameEx(v155);
      if ( v19 < 0 )
        goto LABEL_290;
      v32 = v151;
      if ( *(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) == *(_DWORD *)(*(_DWORD *)(v151 + 4) + 20) )
      {
        ObfDereferenceObject(v151);
        v19 = -1073741811;
        goto LABEL_290;
      }
      v33 = v142;
    }
    v34 = CmpAllocatePostBlock(v145, 0x10000, 0, 0, v131, v133, v135);
    v35 = (_DWORD *)v34;
    v153 = v34;
    if ( !v34 )
    {
      if ( v33 )
        ObfDereferenceObject(v32);
      goto LABEL_55;
    }
    if ( v33 )
    {
      v143 = (_DWORD *)CmpAllocatePostBlock(v145, 0, v32, v34, v132, v134, v136);
      v152 = v143;
      if ( !v143 )
      {
        ObfDereferenceObject(v32);
        CmpFreePostBlock(v35);
LABEL_55:
        v19 = -1073741670;
        goto LABEL_290;
      }
    }
    v36 = v145;
    if ( v145 != 1 )
    {
      if ( v154 )
      {
        v19 = ObReferenceObjectByHandle(v154, 2, ExEventObjectType, v148, (int)&v139, 0);
        v144 = v139;
        if ( v19 < 0 )
        {
          if ( !v142 )
          {
LABEL_65:
            v38 = v35;
LABEL_66:
            CmpFreePostBlock(v38);
            goto LABEL_290;
          }
          v37 = v143;
LABEL_64:
          CmpFreePostBlock(v37);
          goto LABEL_65;
        }
        KeResetEvent(v139);
        v33 = v142;
        v36 = v145;
      }
      if ( v36 == 2 )
      {
        *(_DWORD *)(v35[8] + 56) = v150;
        *(_DWORD *)(v35[8] + 4) = v144;
        v39 = v148;
        if ( !v27 )
        {
          v27 = AlpcMessageDeleteProcedure;
          v39 = 0;
        }
        KeInitializeApc(
          v35[8] + 8,
          __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
          2,
          (int)CmpPostApc,
          (int)CmpPostApcRunDown,
          (int)v27,
          v39,
          a6);
      }
      else
      {
        v22 = v36 == 4;
        v40 = (_DWORD *)v35[8];
        if ( v22 )
        {
          v41 = v144;
          *v40 = v144;
          goto LABEL_76;
        }
        *v40 = v144;
        *(_DWORD *)(v35[8] + 4) = v27;
        *(_DWORD *)(v35[8] + 8) = a6;
      }
    }
    v41 = v144;
LABEL_76:
    CmpLockRegistry();
    v42 = *(_DWORD **)(v137 + 4);
    if ( v149 == 1 )
      CmpLockTwoKcbsShared((unsigned int)v42, *(_DWORD **)(v32 + 4));
    else
      CmpLockKcbShared(v42);
    v43 = *(_DWORD **)(v137 + 4);
    if ( (v43[1] & 0x20000) == 0 )
    {
      if ( !v33 )
        goto LABEL_111;
      if ( (*(_DWORD *)(*(_DWORD *)(v32 + 4) + 4) & 0x20000) == 0 )
      {
        v44 = v43[5];
        v45 = *(_DWORD *)(*(_DWORD *)(v32 + 4) + 20);
        if ( v44 != v45 )
        {
          if ( v44 >= v45 )
          {
            v55 = *(_DWORD *)(v45 + 1864);
            v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v56 = KeAbPreAcquire(v55, 0, 0);
            v57 = v56;
            do
              v58 = __ldrex((unsigned __int8 *)v55);
            while ( __strex(v58 & 0xFE, (unsigned __int8 *)v55) );
            __dmb(0xBu);
            if ( (v58 & 1) == 0 )
              ExpAcquireFastMutexContended(v55, v56);
            if ( v57 )
              *(_BYTE *)(v57 + 14) |= 1u;
            *(_DWORD *)(v55 + 4) = v139;
            v50 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) + 1864);
            v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v59 = KeAbPreAcquire(v50, 0, 0);
            v60 = v59;
            do
              v61 = __ldrex((unsigned __int8 *)v50);
            while ( __strex(v61 & 0xFE, (unsigned __int8 *)v50) );
            __dmb(0xBu);
            if ( (v61 & 1) == 0 )
              ExpAcquireFastMutexContended(v50, v59);
            if ( v60 )
              *(_BYTE *)(v60 + 14) |= 1u;
            v54 = 3;
          }
          else
          {
            v46 = *(_DWORD *)(v44 + 1864);
            v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v47 = KeAbPreAcquire(v46, 0, 0);
            v48 = v47;
            do
              v49 = __ldrex((unsigned __int8 *)v46);
            while ( __strex(v49 & 0xFE, (unsigned __int8 *)v46) );
            __dmb(0xBu);
            if ( (v49 & 1) == 0 )
              ExpAcquireFastMutexContended(v46, v47);
            if ( v48 )
              *(_BYTE *)(v48 + 14) |= 1u;
            *(_DWORD *)(v46 + 4) = v139;
            v50 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v32 + 4) + 20) + 1864);
            v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v51 = KeAbPreAcquire(v50, 0, 0);
            v52 = v51;
            do
              v53 = __ldrex((unsigned __int8 *)v50);
            while ( __strex(v53 & 0xFE, (unsigned __int8 *)v50) );
            __dmb(0xBu);
            if ( (v53 & 1) == 0 )
              ExpAcquireFastMutexContended(v50, v51);
            if ( v52 )
              *(_BYTE *)(v52 + 14) |= 1u;
            v54 = 2;
          }
          *(_DWORD *)(v50 + 4) = v139;
          v146 = *(_DWORD *)(*(_DWORD *)(v32 + 4) + 20);
          goto LABEL_118;
        }
LABEL_111:
        v62 = *(_DWORD *)(v43[5] + 1864);
        v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v63 = KeAbPreAcquire(v62, 0, 0);
        v64 = v63;
        do
          v65 = __ldrex((unsigned __int8 *)v62);
        while ( __strex(v65 & 0xFE, (unsigned __int8 *)v62) );
        __dmb(0xBu);
        if ( (v65 & 1) == 0 )
          ExpAcquireFastMutexContended(v62, v63);
        if ( v64 )
          *(_BYTE *)(v64 + 14) |= 1u;
        *(_DWORD *)(v62 + 4) = v139;
        v54 = 1;
LABEL_118:
        v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v66 = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
        v67 = v66;
        do
          v68 = __ldrex((unsigned __int8 *)&CmpPostLock);
        while ( __strex(v68 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
        __dmb(0xBu);
        if ( (v68 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&CmpPostLock, v66);
        if ( v67 )
          *(_BYTE *)(v67 + 14) |= 1u;
        dword_632444 = v139;
        v19 = CmpNotifyChangeKey(v137, v35, a8, a9);
        if ( v19 < 0 )
        {
          dword_632444 = 0;
          __dmb(0xBu);
          do
            v69 = __ldrex((unsigned int *)&CmpPostLock);
          while ( !v69 && __strex(1u, (unsigned int *)&CmpPostLock) );
          if ( v69 )
            ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v69);
          KeAbPostRelease((unsigned int)&CmpPostLock);
          if ( v54 == 1 )
          {
            v70 = *(unsigned int **)(*(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) + 1864);
            v70[1] = 0;
          }
          else
          {
            if ( v54 != 2 )
            {
              v74 = *(unsigned int **)(*(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) + 1864);
              v74[1] = 0;
              __dmb(0xBu);
              do
                v75 = __ldrex(v74);
              while ( !v75 && __strex(1u, v74) );
              if ( v75 )
                ExpReleaseFastMutexContended(v74, v75);
              KeAbPostRelease((unsigned int)v74);
              v70 = *(unsigned int **)(v146 + 1864);
              v70[1] = 0;
              __dmb(0xBu);
              do
                v71 = __ldrex(v70);
              while ( !v71 && __strex(1u, v70) );
              goto LABEL_151;
            }
            v72 = *(unsigned int **)(v146 + 1864);
            v72[1] = 0;
            __dmb(0xBu);
            do
              v73 = __ldrex(v72);
            while ( !v73 && __strex(1u, v72) );
            if ( v73 )
              ExpReleaseFastMutexContended(v72, v73);
            KeAbPostRelease((unsigned int)v72);
            v70 = *(unsigned int **)(*(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) + 1864);
            v70[1] = 0;
          }
          __dmb(0xBu);
          do
            v71 = __ldrex(v70);
          while ( !v71 && __strex(1u, v70) );
LABEL_151:
          if ( v71 )
            ExpReleaseFastMutexContended(v70, v71);
          KeAbPostRelease((unsigned int)v70);
          v76 = *(_DWORD **)(v137 + 4);
          if ( v149 == 1 )
            CmpUnlockTwoKcbs(v76, *(_DWORD **)(v32 + 4));
          else
            CmpUnlockKcb(v76);
          CmpUnlockRegistry();
          if ( v144 )
            ObfDereferenceObject(v144);
          if ( !v142 )
            goto LABEL_290;
          v38 = v143;
          goto LABEL_66;
        }
        if ( v142 )
        {
          ObfReferenceObject(v32);
          if ( v19 )
          {
            v19 = CmpNotifyChangeKey(v32, v143, a8, a9);
            if ( v19 < 0 )
            {
              v77 = *v35;
              v78 = (_DWORD *)v35[1];
              if ( *(_DWORD **)(*v35 + 4) != v35 || (_DWORD *)*v78 != v35 )
                __fastfail(3u);
              *v78 = v77;
              *(_DWORD *)(v77 + 4) = v78;
              v79 = KfRaiseIrql(1);
              v80 = v35[2];
              v81 = (_DWORD *)v35[3];
              if ( *(_DWORD **)(v80 + 4) != v35 + 2 || (_DWORD *)*v81 != v35 + 2 )
                __fastfail(3u);
              *v81 = v80;
              *(_DWORD *)(v80 + 4) = v81;
              KfLowerIrql(v79);
            }
          }
          else
          {
            CmpFreePostBlock(v143);
            v142 = 0;
            v138 = 0;
          }
        }
        dword_632444 = 0;
        __dmb(0xBu);
        do
          v82 = __ldrex((unsigned int *)&CmpPostLock);
        while ( !v82 && __strex(1u, (unsigned int *)&CmpPostLock) );
        if ( v82 )
          ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v82);
        KeAbPostRelease((unsigned int)&CmpPostLock);
        if ( v54 == 1 )
        {
          v83 = *(_DWORD *)(v137 + 4);
        }
        else
        {
          if ( v54 != 2 )
          {
            v88 = *(unsigned int **)(*(_DWORD *)(*(_DWORD *)(v137 + 4) + 20) + 1864);
            v88[1] = 0;
            __dmb(0xBu);
            do
              v89 = __ldrex(v88);
            while ( !v89 && __strex(1u, v88) );
            if ( v89 )
              ExpReleaseFastMutexContended(v88, v89);
            KeAbPostRelease((unsigned int)v88);
            v84 = *(unsigned int **)(v146 + 1864);
            v84[1] = 0;
            __dmb(0xBu);
            do
              v85 = __ldrex(v84);
            while ( !v85 && __strex(1u, v84) );
LABEL_197:
            if ( v85 )
              ExpReleaseFastMutexContended(v84, v85);
            KeAbPostRelease((unsigned int)v84);
            v90 = *(_DWORD **)(v137 + 4);
            if ( v149 == 1 )
              CmpUnlockTwoKcbs(v90, *(_DWORD **)(v32 + 4));
            else
              CmpUnlockKcb(v90);
            CmpUnlockRegistry();
            if ( v32 )
              ObfDereferenceObject(v32);
            if ( v19 < 0 )
            {
              CmpFreePostBlock(v35);
              if ( v144 )
                ObfDereferenceObject(v144);
              goto LABEL_290;
            }
            if ( v145 == 1 )
            {
              __pld(&CmpShutdownRundown);
              v91 = CmpShutdownRundown & 0xFFFFFFFE;
              __dmb(0xBu);
              do
                v92 = __ldrex((unsigned int *)&CmpShutdownRundown);
              while ( v92 == v91 && __strex(v91 - 2, (unsigned int *)&CmpShutdownRundown) );
              if ( v92 != v91 )
                ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
              v93 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v94 = *(_WORD *)(v93 + 0x134) + 1;
              *(_WORD *)(v93 + 308) = v94;
              if ( !v94 && *(_DWORD *)(v93 + 100) != v93 + 100 && !*(_WORD *)(v93 + 310) )
                KiCheckForKernelApcDelivery(v93);
              v140 = 0;
              v141 = 0;
              v95 = KeWaitForSingleObject(v35[8], 0, v148, (_DWORD *)1, 0);
              v19 = v95;
              if ( v95 != 257 && v95 != 192 )
              {
                CmpLockRegistry();
                v96 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v97 = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
                v98 = v97;
                do
                  v99 = __ldrex((unsigned __int8 *)&CmpPostLock);
                while ( __strex(v99 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
                __dmb(0xBu);
                if ( (v99 & 1) == 0 )
                  ExpAcquireFastMutexContended((int)&CmpPostLock, v97);
                if ( v98 )
                  *(_BYTE *)(v98 + 14) |= 1u;
                dword_632444 = v96;
                v100 = KfRaiseIrql(1);
                v101 = v143;
                if ( v142 )
                {
                  v102 = *v143;
                  if ( *v143 )
                  {
                    v103 = (_DWORD **)v143[1];
                    if ( *(_DWORD **)(v102 + 4) != v143 || *v103 != v143 )
                      __fastfail(3u);
                    *v103 = (_DWORD *)v102;
                    *(_DWORD *)(v102 + 4) = v103;
                  }
                  v104 = v101[2];
                  v105 = (_DWORD *)v101[3];
                  if ( *(_DWORD **)(v104 + 4) != v101 + 2 || (_DWORD *)*v105 != v101 + 2 )
                    __fastfail(3u);
                  *v105 = v104;
                  *(_DWORD *)(v104 + 4) = v105;
                }
                v106 = *v35;
                if ( *v35 )
                {
                  v107 = (_DWORD *)v35[1];
                  if ( *(_DWORD **)(v106 + 4) != v35 || (_DWORD *)*v107 != v35 )
                    __fastfail(3u);
                  *v107 = v106;
                  *(_DWORD *)(v106 + 4) = v107;
                }
                v108 = v35[2];
                v109 = (_DWORD *)v35[3];
                if ( *(_DWORD **)(v108 + 4) != v35 + 2 || (_DWORD *)*v109 != v35 + 2 )
                  __fastfail(3u);
                *v109 = v108;
                *(_DWORD *)(v108 + 4) = v109;
                KfLowerIrql(v100);
                dword_632444 = 0;
                __dmb(0xBu);
                do
                  v110 = __ldrex((unsigned int *)&CmpPostLock);
                while ( !v110 && __strex(1u, (unsigned int *)&CmpPostLock) );
                if ( v110 )
                  ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v110);
                KeAbPostRelease((unsigned int)&CmpPostLock);
                CmpUnlockRegistry();
                v19 = *(_DWORD *)(v35[8] + 16);
                v111 = v150;
                *v150 = v19;
                v111[1] = 0;
                v112 = v140;
                if ( v142 )
                  CmpFreePostBlock(v101);
                CmpFreePostBlock(v35);
                goto LABEL_291;
              }
              CmpLockRegistry();
              v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v113 = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
              v114 = v113;
              do
                v115 = __ldrex((unsigned __int8 *)&CmpPostLock);
              while ( __strex(v115 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
              __dmb(0xBu);
              if ( (v115 & 1) == 0 )
                ExpAcquireFastMutexContended((int)&CmpPostLock, v113);
              if ( v114 )
                *(_BYTE *)(v114 + 14) |= 1u;
              dword_632444 = v139;
              v116 = KfRaiseIrql(1);
              v117 = v142;
              v118 = v143;
              if ( v142 )
              {
                v119 = *v143;
                if ( *v143 )
                {
                  v120 = (_DWORD **)v143[1];
                  if ( *(_DWORD **)(v119 + 4) != v143 || *v120 != v143 )
                    __fastfail(3u);
                  *v120 = (_DWORD *)v119;
                  *(_DWORD *)(v119 + 4) = v120;
                }
                v121 = v118[2];
                v122 = (_DWORD *)v118[3];
                if ( *(_DWORD **)(v121 + 4) != v118 + 2 || (_DWORD *)*v122 != v118 + 2 )
                  __fastfail(3u);
                *v122 = v121;
                *(_DWORD *)(v121 + 4) = v122;
              }
              v123 = *v35;
              if ( *v35 )
              {
                v124 = (_DWORD *)v35[1];
                if ( *(_DWORD **)(v123 + 4) != v35 || (_DWORD *)*v124 != v35 )
                  __fastfail(3u);
                *v124 = v123;
                *(_DWORD *)(v123 + 4) = v124;
              }
              v125 = v35[2];
              v126 = (_DWORD *)v35[3];
              if ( *(_DWORD **)(v125 + 4) != v35 + 2 || (_DWORD *)*v126 != v35 + 2 )
                __fastfail(3u);
              *v126 = v125;
              *(_DWORD *)(v125 + 4) = v126;
              KfLowerIrql(v116);
              dword_632444 = 0;
              __dmb(0xBu);
              do
                v127 = __ldrex((unsigned int *)&CmpPostLock);
              while ( !v127 && __strex(1u, (unsigned int *)&CmpPostLock) );
              if ( v127 )
                ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v127);
              KeAbPostRelease((unsigned int)&CmpPostLock);
              CmpUnlockRegistry();
              if ( !v117 )
                goto LABEL_65;
              v37 = v118;
              goto LABEL_64;
            }
LABEL_290:
            v112 = v140;
LABEL_291:
            ObfDereferenceObject(v137);
            if ( !v112 )
              return v19;
            __pld(&CmpShutdownRundown);
            v30 = CmpShutdownRundown & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v31 = __ldrex((unsigned int *)&CmpShutdownRundown);
            while ( v31 == v30 && __strex(v30 - 2, (unsigned int *)&CmpShutdownRundown) );
            goto LABEL_295;
          }
          v86 = *(unsigned int **)(v146 + 1864);
          v86[1] = 0;
          __dmb(0xBu);
          do
            v87 = __ldrex(v86);
          while ( !v87 && __strex(1u, v86) );
          if ( v87 )
            ExpReleaseFastMutexContended(v86, v87);
          KeAbPostRelease((unsigned int)v86);
          v83 = *(_DWORD *)(v137 + 4);
        }
        v84 = *(unsigned int **)(*(_DWORD *)(v83 + 20) + 1864);
        v84[1] = 0;
        __dmb(0xBu);
        do
          v85 = __ldrex(v84);
        while ( !v85 && __strex(1u, v84) );
        goto LABEL_197;
      }
    }
    if ( v149 == 1 )
      CmpUnlockTwoKcbs(v43, *(_DWORD **)(v32 + 4));
    else
      CmpUnlockKcb(v43);
    CmpUnlockRegistry();
    if ( v41 )
      ObfDereferenceObject(v41);
    if ( v33 )
      CmpFreePostBlock(v143);
    CmpFreePostBlock(v35);
    v19 = -1073741444;
    goto LABEL_290;
  }
  __pld(&CmpShutdownRundown);
  v30 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v31 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v31 == v30 && __strex(v30 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_295:
  if ( v31 != v30 )
    v30 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v128 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v129 = *(_WORD *)(v128 + 0x134) + 1;
  *(_WORD *)(v128 + 308) = v129;
  if ( !v129 && *(_DWORD *)(v128 + 100) != v128 + 100 && !*(_WORD *)(v128 + 310) )
    KiCheckForKernelApcDelivery(v30);
  return v19;
}
