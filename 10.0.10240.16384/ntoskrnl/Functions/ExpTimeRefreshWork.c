// ExpTimeRefreshWork 
 
int ExpTimeRefreshWork()
{
  int v0; // r0
  int v1; // r9
  unsigned __int64 v2; // kr08_8
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  int v7; // r6
  int v8; // r5
  __int64 *v9; // r1
  int v10; // r0
  int v11; // t1
  int v12; // r4
  int v13; // r3
  int *v14; // r3
  int v15; // r2
  int *v16; // r1
  int v17; // r0
  int v18; // t1
  unsigned int v19; // r0
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r1
  int v27; // r5
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r1
  unsigned int v31; // r0
  int v32; // r1
  unsigned __int8 *v33; // r6
  int v34; // r5
  int i; // r4
  int v36; // t1
  int v37; // r1
  char *j; // r0
  int v39; // t1
  int v40; // r6
  int v41; // r0
  int v42; // r1
  char *v43; // r0
  int v44; // r1
  int v45; // r4
  unsigned int v46; // r1
  int v47; // r0
  unsigned int v48; // r1
  __int16 v49; // r3
  unsigned int v50; // r2
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r1
  int v54; // r3
  int v55; // r6
  unsigned __int64 v56; // r6
  int v57; // r4
  int v58; // r5
  unsigned int v59; // r1
  int v60; // r0
  unsigned int v61; // r1
  __int16 v62; // r3
  int v63; // r0
  int v64; // r0
  unsigned int v65; // r2
  unsigned int v66; // r2
  int v67; // r3
  unsigned int v68; // r2
  int v69; // r0
  int v70; // r4
  unsigned int v71; // r1
  int v72; // r0
  int v73; // r3
  int *v74; // r2
  unsigned int v75; // r0
  int v76; // r0
  unsigned int v77; // r1
  __int16 v78; // r3
  int v79; // r1
  unsigned __int8 *v80; // r4
  int v81; // r6
  int k; // r5
  int v83; // t1
  int v84; // r1
  char *l; // r0
  int v86; // t1
  int v87; // [sp+Ch] [bp-2C4h]
  int v88; // [sp+10h] [bp-2C0h] BYREF
  int v89; // [sp+14h] [bp-2BCh]
  __int64 v90; // [sp+18h] [bp-2B8h]
  int v91; // [sp+20h] [bp-2B0h]
  int v92; // [sp+24h] [bp-2ACh] BYREF
  int v93; // [sp+28h] [bp-2A8h] BYREF
  int v94; // [sp+2Ch] [bp-2A4h] BYREF
  _DWORD v95[4]; // [sp+30h] [bp-2A0h] BYREF
  __int64 v96; // [sp+40h] [bp-290h] BYREF
  __int64 v97; // [sp+48h] [bp-288h] BYREF
  __int64 v98; // [sp+50h] [bp-280h] BYREF
  int v99; // [sp+58h] [bp-278h] BYREF
  int v100; // [sp+5Ch] [bp-274h]
  int v101; // [sp+60h] [bp-270h]
  int v102; // [sp+68h] [bp-268h]
  int v103; // [sp+6Ch] [bp-264h]
  int v104; // [sp+70h] [bp-260h]
  int v105; // [sp+74h] [bp-25Ch]
  int v106; // [sp+78h] [bp-258h]
  int v107; // [sp+7Ch] [bp-254h]
  char v108; // [sp+80h] [bp-250h]
  int v109; // [sp+88h] [bp-248h] BYREF
  int v110; // [sp+8Ch] [bp-244h]
  int v111; // [sp+90h] [bp-240h]
  int v112; // [sp+98h] [bp-238h]
  int v113; // [sp+9Ch] [bp-234h]
  int v114; // [sp+A0h] [bp-230h]
  int v115; // [sp+A4h] [bp-22Ch]
  int v116; // [sp+A8h] [bp-228h]
  int v117; // [sp+ACh] [bp-224h]
  char v118; // [sp+B0h] [bp-220h]
  char v119[8]; // [sp+B8h] [bp-218h] BYREF
  int v120; // [sp+C0h] [bp-210h]
  int v121; // [sp+C8h] [bp-208h]
  int v122; // [sp+CCh] [bp-204h]
  char v123[24]; // [sp+E8h] [bp-1E8h] BYREF
  unsigned __int64 v124; // [sp+100h] [bp-1D0h]
  char v125[8]; // [sp+118h] [bp-1B8h] BYREF
  int v126; // [sp+120h] [bp-1B0h]
  char v127[48]; // [sp+148h] [bp-188h] BYREF
  char v128; // [sp+178h] [bp-158h] BYREF
  int v129; // [sp+180h] [bp-150h]
  char v130[8]; // [sp+1A8h] [bp-128h] BYREF
  int v131; // [sp+1B0h] [bp-120h]
  char v132[24]; // [sp+1D8h] [bp-F8h] BYREF
  int v133; // [sp+1F0h] [bp-E0h]
  int v134; // [sp+1F4h] [bp-DCh]
  char v135[32]; // [sp+208h] [bp-C8h] BYREF
  int v136; // [sp+228h] [bp-A8h]
  int v137; // [sp+22Ch] [bp-A4h]
  _DWORD v138[12]; // [sp+238h] [bp-98h] BYREF
  char v139[48]; // [sp+268h] [bp-68h] BYREF
  __int64 v140; // [sp+298h] [bp-38h] BYREF
  int v141; // [sp+2A0h] [bp-30h]
  int v142; // [sp+2A4h] [bp-2Ch]
  int v143; // [sp+2A8h] [bp-28h]
  int v144; // [sp+2ACh] [bp-24h]

  do
  {
    v0 = ExAcquireTimeRefreshLock(1);
    if ( KeTimeSynchronization )
      v0 = ExUpdateSystemTimeFromCmos(0, 0);
    ExReleaseTimeRefreshLock(v0);
    v1 = 1;
    v91 = 1;
    __dmb(0xBu);
    do
      v2 = __ldrexd((unsigned __int64 *)&dword_922C10);
    while ( __strexd(v2 + 1, (unsigned __int64 *)&dword_922C10) );
    __dmb(0xBu);
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v3 + 308);
    v4 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
    do
      v5 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
    while ( __strex(v5 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
      return sub_694460(v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    if ( dword_922C18 || sub_7B5F04(&dword_8C8214, &dword_922C18) >= 0 )
    {
      v7 = 0;
      v8 = 0;
      v9 = &v96;
      v90 = *(_QWORD *)&dword_922C10;
      v96 = *(_QWORD *)&dword_922C10;
      v10 = 8;
      do
      {
        v11 = *(unsigned __int8 *)v9;
        v9 = (__int64 *)((char *)v9 + 1);
        v8 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v11 - 23737705 + v8), 21), 21), 21);
        v7 += v11 - 23737705 + v8;
        --v10;
      }
      while ( v10 );
      v12 = 0;
      while ( 1 )
      {
        v13 = ExpFastCacheReArmed;
        __dmb(0xBu);
        if ( v13 )
        {
          v67 = 0;
          v88 = 0;
        }
        else
        {
          v14 = &dword_920288[10 * v12];
          v15 = v14[1];
          if ( !v15 || v14[5] )
          {
            v88 = 0;
            v89 = 0;
            goto LABEL_18;
          }
          v88 = *(_DWORD *)(v15 + 16);
          v67 = *(_DWORD *)(v15 + 20);
        }
        v89 = v67;
LABEL_18:
        v16 = &v88;
        v17 = 8;
        do
        {
          v18 = *(unsigned __int8 *)v16;
          v16 = (int *)((char *)v16 + 1);
          v8 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v18 - 23737705 + v8), 21), 21), 21);
          v7 += v18 - 23737705 + v8;
          --v17;
        }
        while ( v17 );
        if ( (unsigned int)++v12 >= 5 )
        {
          v1 = v91;
          v143 = 0;
          v144 = 0;
          v141 = v7;
          v140 = v90;
          v142 = v8;
          CmSetValueKey(dword_922C18, &dword_8C81C4, 3, &v140, 24, 0, 0, v87, v88, v89);
          break;
        }
      }
    }
    __dmb(0xBu);
    do
      v19 = __ldrex(&ExpFastCacheUpdateLock);
    while ( __strex(v19 - 1, &ExpFastCacheUpdateLock) );
    if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
      ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
    v20 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(v20);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v23 + 308);
    v24 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v25 = v24;
    do
      v26 = __ldrex((unsigned int *)&dword_922C40);
    while ( !v26 && __strex(0x11u, (unsigned int *)&dword_922C40) );
    __dmb(0xBu);
    if ( v26 )
      ExfAcquirePushLockSharedEx(&dword_922C40, v24, (unsigned int)&dword_922C40);
    if ( v25 )
      *(_BYTE *)(v25 + 14) |= 1u;
    v27 = 0;
    if ( !off_920350 && dword_922C44 )
    {
      v28 = KeAbPreAcquire((unsigned int)&dword_922C04, 0, 0);
      v29 = v28;
      do
        v30 = __ldrex((unsigned __int8 *)&dword_922C04);
      while ( __strex(v30 | 1, (unsigned __int8 *)&dword_922C04) );
      __dmb(0xBu);
      if ( (v30 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&dword_922C04, v28, (unsigned int)&dword_922C04);
      if ( v29 )
        *(_BYTE *)(v29 + 14) |= 1u;
      if ( !dword_922BEC )
        v27 = 1;
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned int *)&dword_922C04);
      while ( __strex(v31 - 1, (unsigned int *)&dword_922C04) );
      if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&dword_922C04);
      KeAbPostRelease((unsigned int)&dword_922C04);
      if ( v27 )
      {
        v43 = &v128;
        dword_920284 = 5;
        v129 = 5;
        v44 = 2;
LABEL_62:
        sub_6E34A4(v43, v44, 0);
        goto LABEL_63;
      }
      if ( !dword_922C44 )
        goto LABEL_63;
      v102 = 0;
      v103 = 0;
      v101 = 4;
      v104 = 0;
      v105 = 0;
      v106 = 0;
      v107 = 0;
      v32 = *(_DWORD *)(dword_922C44 + 4);
      v108 = 1;
      v33 = (unsigned __int8 *)(dword_922C44 + 20);
      if ( dword_922C44 == -20 )
        goto LABEL_141;
      v34 = 0;
      for ( i = 0; v32; --v32 )
      {
        v36 = *v33++;
        i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v36 - 23737705 + i), 21), 21), 21);
        v34 += v36 - 23737705 + i;
      }
      v99 = v34;
      v100 = i;
      if ( !dword_922C3C )
        goto LABEL_57;
      if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned int)dword_922C3C >> 29, &v93) )
      {
LABEL_141:
        v34 = 0;
        i = 0;
        v101 = 4;
      }
      else
      {
        v37 = v93;
        for ( j = &byte_922C48; v37; --v37 )
        {
          v39 = (unsigned __int8)*j++;
          i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v39 - 23737705 + i), 21), 21), 21);
          v34 += v39 - 23737705 + i;
        }
      }
      v99 = v34;
      v100 = i;
LABEL_57:
      memmove((int)v119, (int)&v99, 0x30u);
      if ( sub_6E2570(v138) < 0 )
        goto LABEL_63;
      v40 = 4;
      if ( v138[0] != v34 || v138[1] != i )
      {
        v120 = 4;
        v40 = 6;
      }
      KeQueryTickCount((int *)&v98);
      v41 = KeQueryTimeIncrement();
      v121 = _rt_sdiv64(10000i64, v98 * (unsigned int)v41);
      v122 = v42;
      v43 = v119;
      v44 = v40;
      goto LABEL_62;
    }
LABEL_63:
    if ( off_920350 )
    {
      v45 = 0;
    }
    else if ( sub_6E2570(v139) < 0 )
    {
      v45 = 1;
    }
    else
    {
      v45 = (unsigned __int8)v139[40];
    }
    __dmb(0xBu);
    do
      v46 = __ldrex((unsigned int *)&dword_922C40);
    while ( v46 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
    if ( v46 != 17 )
      ExfReleasePushLockShared(&dword_922C40);
    v47 = KeAbPostRelease((unsigned int)&dword_922C40);
    v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v49 = *(_WORD *)(v48 + 0x134) + 1;
    *(_WORD *)(v48 + 308) = v49;
    if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
      KiCheckForKernelApcDelivery(v47);
    if ( v45 == 1 )
    {
      v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v50 + 308);
      v51 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
      v52 = v51;
      do
        v53 = __ldrex((unsigned int *)&dword_922C40);
      while ( !v53 && __strex(0x11u, (unsigned int *)&dword_922C40) );
      __dmb(0xBu);
      if ( v53 )
        ExfAcquirePushLockSharedEx(&dword_922C40, v51, (unsigned int)&dword_922C40);
      if ( v52 )
        *(_BYTE *)(v52 + 14) |= 1u;
      if ( sub_6E2570(v132) < 0 )
      {
        v55 = 0;
        v54 = 0;
      }
      else
      {
        v55 = v133;
        v54 = v134;
      }
      v56 = __PAIR64__(v54, v55) + 3600;
      v124 = v56;
      sub_6E34A4(v123, 8, 0);
      if ( off_920350 )
      {
        v58 = 10800;
      }
      else
      {
        if ( sub_6E2570(v135) >= 0 )
        {
          v58 = v136;
          v57 = v137;
LABEL_86:
          __dmb(0xBu);
          do
            v59 = __ldrex((unsigned int *)&dword_922C40);
          while ( v59 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
          if ( v59 != 17 )
            ExfReleasePushLockShared(&dword_922C40);
          v60 = KeAbPostRelease((unsigned int)&dword_922C40);
          v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v62 = *(_WORD *)(v61 + 0x134) + 1;
          *(_WORD *)(v61 + 308) = v62;
          if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
            v60 = KiCheckForKernelApcDelivery(v60);
          v63 = sub_6DEF2C(v60);
          if ( __PAIR64__(v57, v58) > v56 )
          {
            v1 = 0;
LABEL_95:
            if ( v1 )
              sub_8A1140(v63);
            goto LABEL_97;
          }
          v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v68 + 308);
          v69 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
          v70 = v69;
          do
            v71 = __ldrex((unsigned __int8 *)&dword_922C40);
          while ( __strex(v71 | 1, (unsigned __int8 *)&dword_922C40) );
          __dmb(0xBu);
          if ( (v71 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_922C40, v69, (unsigned int)&dword_922C40);
          if ( v70 )
            *(_BYTE *)(v70 + 14) |= 1u;
          if ( !dword_922C44 )
          {
            v73 = dword_920284;
            goto LABEL_118;
          }
          v72 = sub_6E2570(v130);
          if ( v72 >= 0 )
          {
            v73 = v131;
LABEL_118:
            if ( v73 )
              v1 = 0;
            dword_920284 = 2;
            v126 = 2;
            sub_6E34A4(v125, 2, 0);
            v74 = (int *)dword_922C44;
            if ( off_920350 )
              v74 = off_920350;
            if ( v74 )
              v74[3] |= 1u;
            v127[40] = 0;
            sub_6E34A4(v127, 32, 0);
            __dmb(0xBu);
            do
              v75 = __ldrex((unsigned int *)&dword_922C40);
            while ( __strex(v75 - 1, (unsigned int *)&dword_922C40) );
            if ( (v75 & 2) != 0 && (v75 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)&dword_922C40);
            v76 = KeAbPostRelease((unsigned int)&dword_922C40);
            v77 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v78 = *(_WORD *)(v77 + 0x134) + 1;
            *(_WORD *)(v77 + 308) = v78;
            if ( !v78 && *(_DWORD *)(v77 + 100) != v77 + 100 && !*(_WORD *)(v77 + 310) )
              v76 = KiCheckForKernelApcDelivery(v76);
            sub_7660C8(v76);
            sub_7663CC(KernelLicensingCacheExpired);
            v63 = sub_76601C(7190);
            goto LABEL_95;
          }
          if ( v72 == -1073741275 && dword_922C44 )
          {
            v112 = 0;
            v113 = 0;
            v111 = 4;
            v114 = 0;
            v115 = 0;
            v116 = 0;
            v117 = 0;
            v79 = *(_DWORD *)(dword_922C44 + 4);
            v118 = 1;
            v80 = (unsigned __int8 *)(dword_922C44 + 20);
            if ( dword_922C44 == -20 )
              goto LABEL_162;
            v81 = 0;
            for ( k = 0; v79; --v79 )
            {
              v83 = *v80++;
              k = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v83 - 23737705 + k), 21), 21), 21);
              v81 += v83 - 23737705 + k;
            }
            v109 = v81;
            v110 = k;
            if ( dword_922C3C )
            {
              if ( !RtlULongLongToULong(8 * dword_922C3C, (unsigned int)dword_922C3C >> 29, &v94) )
              {
                v84 = v94;
                for ( l = &byte_922C48; v84; --v84 )
                {
                  v86 = (unsigned __int8)*l++;
                  k = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v86 - 23737705 + k), 21), 21), 21);
                  v81 += v86 - 23737705 + k;
                }
                v109 = v81;
                v110 = k;
                goto LABEL_163;
              }
LABEL_162:
              v109 = 0;
              v110 = 0;
              v111 = 4;
            }
LABEL_163:
            memmove((int)v130, (int)&v109, 0x30u);
            v131 = 4;
            sub_6E34A4(v130, -1, 0);
          }
          v73 = 4;
          goto LABEL_118;
        }
        v58 = 0;
      }
      v57 = 0;
      goto LABEL_86;
    }
LABEL_97:
    if ( !ExpSystemSetupInProgress )
    {
      KeQuerySystemTime(&v97);
      v64 = ExGetExpirationDate(&ExpNtExpirationDate);
      if ( v64 < 0 )
      {
        ExpNtExpirationDate = 0;
        dword_927574 = 0;
      }
      MEMORY[0xFFFF92C8] = ExpNtExpirationDate;
      MEMORY[0xFFFF92CC] = dword_927574;
      if ( v64 >= 0 && *(_QWORD *)&ExpNtExpirationDate && v97 >= *(__int64 *)&ExpNtExpirationDate )
      {
        if ( ExpTrackFatalExpiration )
        {
          if ( ExpTrackFatalExpiration == 1 )
          {
            ExpTrackFatalExpiration = 2;
            if ( PsCreateSystemThread(&v92, 0x1FFFFF, 0, 0, 0, ExpExpirationThread, -1073741208) >= 0 )
              ZwClose();
          }
          else if ( ExpTrackFatalExpiration == 2 )
          {
            ExpTrackFatalExpiration = 0;
            PoShutdownBugCheck(0, 152, ExpNtExpirationDate, dword_927574, 0, 0);
          }
        }
        else
        {
          ++ExpTrackFatalExpiration;
        }
      }
      else
      {
        ExpTrackFatalExpiration = 0;
      }
    }
    __dmb(0xBu);
    do
    {
      v65 = __ldrex(&ExpOkToTimeRefresh);
      v66 = v65 - 1;
    }
    while ( __strex(v66, &ExpOkToTimeRefresh) );
    __dmb(0xBu);
  }
  while ( v66 );
  v95[0] = 0;
  v95[1] = 0;
  v95[2] = -1;
  v95[3] = -1;
  return KeSetTimer2(ExpTimeRefreshTimer, ExpTimeRefreshInterval, 0i64, (int)v95);
}
