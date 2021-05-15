// IopCompleteRequest 
 
int __fastcall IopCompleteRequest(int a1, int a2, _DWORD *a3, _DWORD **a4, _DWORD *a5)
{
  int v5; // r6
  int v6; // r8
  _DWORD *v7; // r9
  int v8; // r3
  int result; // r0
  int v10; // r2
  _DWORD *v11; // r0
  _DWORD *v12; // r4
  int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r0
  int v16; // r0
  int *v17; // r3
  _DWORD *v18; // r2
  int v19; // r3
  int v20; // r4
  int v21; // r10
  unsigned int v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r2
  int v25; // r3
  unsigned int *v26; // r3
  unsigned int *v27; // r1
  unsigned int *v28; // lr
  unsigned int **v29; // r2
  int v30; // r3
  int v31; // r3
  unsigned int v32; // r3
  int v33; // lr
  BOOL v34; // r2
  unsigned int *v35; // r0
  unsigned int v36; // r2
  unsigned int v37; // r2
  int v38; // r3
  unsigned int **v39; // lr
  unsigned int v40; // r1
  int v41; // r3
  unsigned int *v42; // r5
  unsigned int *v43; // r1
  int v44; // r3
  int v45; // r2
  int v46; // lr
  BOOL v47; // r2
  unsigned int *v48; // r0
  unsigned int v49; // r2
  unsigned int v50; // r2
  int v51; // r3
  unsigned int **v52; // lr
  unsigned int v53; // r1
  unsigned int v54; // r1
  int v55; // r3
  int v56; // r5
  unsigned int *v57; // r1
  unsigned int v58; // r2
  __int64 v59; // r0
  unsigned __int64 *v60; // r5
  __int64 v61; // t1
  unsigned __int64 v62; // kr10_8
  unsigned __int64 v63; // kr18_8
  int v64; // r4
  __int64 v65; // r2
  int v66; // r5
  char v67; // lr
  int v68; // r4
  unsigned __int64 *v69; // r4
  __int64 v70; // r2
  unsigned __int64 v71; // kr30_8
  unsigned __int64 v72; // kr38_8
  int v73; // r1
  int v74; // r1
  unsigned int v75; // r0
  unsigned int v76; // lr
  int v77; // r0
  void (__fastcall **v78)(int); // r3
  int v79; // r2
  unsigned int v80; // r1
  int v81; // r5
  unsigned __int64 *v82; // r3
  unsigned __int64 v83; // kr50_8
  unsigned __int64 *v84; // r2
  unsigned __int64 v85; // r0
  unsigned __int64 *v86; // r3
  unsigned __int64 v87; // kr58_8
  unsigned __int64 *v88; // r2
  unsigned __int64 v89; // r0
  unsigned __int64 *v90; // r3
  unsigned __int64 v91; // kr60_8
  unsigned __int64 *v92; // r2
  unsigned __int64 v93; // r0
  int v94; // r4
  unsigned int *v95; // r5
  unsigned int v96; // r2
  _DWORD *v97; // r2
  int v98; // r0
  _DWORD *v99; // r1
  int v100; // r2
  int v101; // r1
  int v102; // r2
  int v103; // r3
  _DWORD *v104; // r4
  int v105; // lr
  unsigned int v106; // r3
  int v107; // r6
  int v108; // r1
  BOOL v109; // r2
  int v110; // r0
  unsigned int v111; // r2
  unsigned int v112; // r2
  int v113; // r3
  _DWORD *v114; // r1
  unsigned int v115; // r4
  unsigned int *v116; // r4
  unsigned int v117; // r2
  signed int v118; // r2
  unsigned int v119; // [sp+14h] [bp-54h]
  char v120; // [sp+14h] [bp-54h]
  unsigned int *v121; // [sp+18h] [bp-50h]
  unsigned int *v122; // [sp+18h] [bp-50h]
  __int64 v123; // [sp+18h] [bp-50h]
  unsigned int v124; // [sp+20h] [bp-48h]
  BOOL v125; // [sp+24h] [bp-44h]
  int v126; // [sp+24h] [bp-44h]
  int v127; // [sp+2Ch] [bp-3Ch]
  int v128; // [sp+2Ch] [bp-3Ch]
  int v129; // [sp+2Ch] [bp-3Ch]
  int v130; // [sp+30h] [bp-38h]
  int v131; // [sp+34h] [bp-34h]
  unsigned int *v132; // [sp+38h] [bp-30h]
  int v133; // [sp+38h] [bp-30h]
  int v134; // [sp+38h] [bp-30h]
  int v135; // [sp+3Ch] [bp-2Ch]
  int v136; // [sp+3Ch] [bp-2Ch]
  unsigned int *v137; // [sp+40h] [bp-28h]
  int v138; // [sp+40h] [bp-28h]

  v5 = a1 - 64;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *a4;
  v125 = a3 && *a3 == 1;
  v8 = *(_DWORD *)(a1 - 56);
  if ( (v8 & 0x80) != 0 )
  {
    v7[7] = *(_DWORD *)(a1 - 40);
    *(_DWORD *)(a1 + 20) = *a5;
    return KeSetEvent(v7 + 23, 0, 0);
  }
  if ( (v8 & 0x10) != 0 )
  {
    if ( (v8 & 0x40) != 0 )
    {
      v10 = *(_DWORD *)(a1 - 40);
      if ( v10 != -2147483626 && (v10 & 0xC0000000) != -1073741824 )
        memmove(*(_DWORD *)(a1 - 4), *(_DWORD *)(a1 - 52), *(_DWORD *)(a1 - 36));
    }
    if ( (*(_DWORD *)(v5 + 8) & 0x20) != 0 )
      ExFreePoolWithTag(*(_DWORD *)(v5 + 12), 0);
  }
  *(_DWORD *)(v5 + 8) &= 0xFFFFFFCF;
  v11 = *(_DWORD **)(v5 + 4);
  if ( v11 )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      IoFreeMdl((int)v11);
      v11 = v12;
    }
    while ( v12 );
  }
  *(_DWORD *)(v5 + 4) = 0;
  v13 = *(_DWORD *)(v5 + 24);
  if ( (v13 & 0xC0000000) != -1073741824
    || *(_BYTE *)(v5 + 33) && (*(_DWORD *)(v5 + 8) & 4) == 0 && (!v7 || (v7[11] & 2) == 0) )
  {
    v130 = 0;
    v131 = 0;
    if ( v7 )
    {
      v17 = (int *)v7[27];
      if ( v17 )
      {
        v130 = *v17;
        v131 = v17[1];
      }
    }
    v18 = *(_DWORD **)(v5 + 40);
    v18[1] = *(_DWORD *)(v5 + 28);
    v19 = *(_DWORD *)(v5 + 24);
    __dmb(0xBu);
    *v18 = v19;
    v20 = *(_DWORD *)(v5 + 44);
    if ( !v20 )
    {
      if ( v7 )
      {
        if ( (v7[11] & 0x4000000) == 0 )
          KeSetEvent(v7 + 23, 0, 0);
        v7[7] = *(_DWORD *)(v5 + 24);
      }
      goto LABEL_187;
    }
    if ( (*(_BYTE *)v20 & 0x7F) != 0 )
    {
      v21 = 0;
    }
    else
    {
      if ( *(_DWORD *)(v20 + 4) == 1 )
        goto LABEL_177;
      v21 = 1;
    }
    v124 = KfRaiseIrql(2);
    v22 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v119 = v22;
    do
      v23 = __ldrex((unsigned __int8 *)v20);
    while ( __strex(v23 | 0x80, (unsigned __int8 *)v20) );
    __dmb(0xBu);
    if ( v23 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v20 & 0x80) != 0 );
        do
          v24 = __ldrex((unsigned __int8 *)v20);
        while ( __strex(v24 | 0x80, (unsigned __int8 *)v20) );
        __dmb(0xBu);
      }
      while ( v24 >> 7 );
    }
    v25 = *(_DWORD *)(v20 + 4);
    *(_DWORD *)(v20 + 4) = 1;
    if ( !v25 )
    {
      v26 = *(unsigned int **)(v20 + 8);
      if ( !v21 )
      {
        if ( v26 != (unsigned int *)(v20 + 8) )
        {
          while ( 1 )
          {
            v27 = v26;
            v121 = v26;
            v137 = (unsigned int *)*v26;
            v28 = (unsigned int *)*v26;
            v29 = (unsigned int **)v26[1];
            if ( *(unsigned int **)(*v26 + 4) != v26 || *v29 != v26 )
              __fastfail(3u);
            *v29 = v28;
            v28[1] = (unsigned int)v29;
            v30 = *((unsigned __int8 *)v26 + 8);
            if ( v30 == 1 )
            {
              if ( KiTryUnwaitThread(v22, v27, *((unsigned __int16 *)v27 + 5), 0) )
              {
                v31 = *(_DWORD *)(v20 + 4) - 1;
                *(_DWORD *)(v20 + 4) = v31;
                if ( !v31 )
                  goto LABEL_130;
              }
            }
            else if ( v30 == 2 )
            {
              *((_BYTE *)v27 + 9) = 5;
              v127 = v27[3];
              *v27 = 0;
              KfRaiseIrql(2);
              v32 = (unsigned int)KeGetPcr();
              v135 = (v32 & 0xFFFFF000) + 1408;
              v33 = *(_DWORD *)((v32 & 0xFFFFF000) + 0x584);
              if ( (dword_682604 & 0x1000000) != 0 )
              {
                v34 = *(_BYTE *)(v33 + 132) == 2
                   && *(_DWORD *)(v33 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
                EtwTraceEnqueueWork(v33, v121, v34);
              }
              v35 = (unsigned int *)v127;
              do
                v36 = __ldrex((unsigned __int8 *)v127);
              while ( __strex(v36 | 0x80, (unsigned __int8 *)v127) );
              __dmb(0xBu);
              if ( v36 >> 7 )
              {
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                  }
                  while ( (*(_DWORD *)v127 & 0x80) != 0 );
                  do
                    v37 = __ldrex((unsigned __int8 *)v127);
                  while ( __strex(v37 | 0x80, (unsigned __int8 *)v127) );
                  __dmb(0xBu);
                }
                while ( v37 >> 7 );
              }
              if ( *(_DWORD *)(v127 + 12) == v127 + 8
                || *(_DWORD *)(v127 + 24) >= *(_DWORD *)(v127 + 28)
                || *(_DWORD *)(v33 + 152) == v127 && *(_BYTE *)(v33 + 395) == 15 )
              {
                v38 = 0;
              }
              else
              {
                v38 = KiWakeQueueWaiter(v135, v127, (int)v121);
                v35 = (unsigned int *)v127;
              }
              if ( !v38 )
              {
                ++v35[1];
                v39 = (unsigned int **)v35[5];
                *v121 = (unsigned int)(v35 + 4);
                v121[1] = (unsigned int)v39;
                if ( *v39 != v35 + 4 )
                  __fastfail(3u);
                *v39 = v121;
                v35[5] = (unsigned int)v121;
              }
              __dmb(0xBu);
              do
                v40 = __ldrex(v35);
              while ( __strex(v40 & 0xFFFFFF7F, v35) );
              v41 = *(_DWORD *)(v20 + 4) - 1;
              *(_DWORD *)(v20 + 4) = v41;
              if ( !v41 )
                goto LABEL_130;
            }
            else
            {
              KiTryUnwaitThread(v22, v27, 256, 0);
            }
            v26 = v137;
            if ( v137 == (unsigned int *)(v20 + 8) )
              goto LABEL_130;
            v22 = v119;
          }
        }
        goto LABEL_130;
      }
      v42 = (unsigned int *)(v20 + 8);
      if ( v26 != (unsigned int *)(v20 + 8) )
      {
        while ( 1 )
        {
          v43 = v26;
          v122 = v26;
          v132 = (unsigned int *)*v26;
          v44 = *((unsigned __int8 *)v26 + 8);
          if ( v44 == 1 )
            break;
          if ( v44 != 2 )
          {
            v45 = 256;
            goto LABEL_125;
          }
          *((_BYTE *)v43 + 9) = 5;
          v128 = v43[3];
          *v43 = 0;
          KfRaiseIrql(2);
          v136 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
          v46 = *(_DWORD *)(v136 + 4);
          if ( (dword_682604 & 0x1000000) != 0 )
          {
            v47 = *(_BYTE *)(v46 + 132) == 2
               && *(_DWORD *)(v46 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            EtwTraceEnqueueWork(v46, v122, v47);
          }
          v48 = (unsigned int *)v128;
          do
            v49 = __ldrex((unsigned __int8 *)v128);
          while ( __strex(v49 | 0x80, (unsigned __int8 *)v128) );
          __dmb(0xBu);
          if ( v49 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( (*(_DWORD *)v128 & 0x80) != 0 );
              do
                v50 = __ldrex((unsigned __int8 *)v128);
              while ( __strex(v50 | 0x80, (unsigned __int8 *)v128) );
              __dmb(0xBu);
            }
            while ( v50 >> 7 );
          }
          if ( *(_DWORD *)(v128 + 12) == v128 + 8
            || *(_DWORD *)(v128 + 24) >= *(_DWORD *)(v128 + 28)
            || *(_DWORD *)(v46 + 152) == v128 && *(_BYTE *)(v46 + 395) == 15 )
          {
            v51 = 0;
          }
          else
          {
            v51 = KiWakeQueueWaiter(v136, v128, (int)v122);
            v48 = (unsigned int *)v128;
          }
          if ( !v51 )
          {
            ++v48[1];
            v52 = (unsigned int **)v48[5];
            *v122 = (unsigned int)(v48 + 4);
            v122[1] = (unsigned int)v52;
            if ( *v52 != v48 + 4 )
              __fastfail(3u);
            *v52 = v122;
            v48[5] = (unsigned int)v122;
          }
          __dmb(0xBu);
          do
            v53 = __ldrex(v48);
          while ( __strex(v53 & 0xFFFFFF7F, v48) );
LABEL_126:
          v26 = v132;
          if ( v132 == v42 )
            goto LABEL_129;
          v22 = v119;
        }
        v45 = *((unsigned __int16 *)v43 + 5);
LABEL_125:
        KiTryUnwaitThread(v22, v43, v45, 0);
        goto LABEL_126;
      }
LABEL_129:
      *(_DWORD *)(v20 + 12) = v20 + 8;
      *v42 = (unsigned int)v42;
    }
LABEL_130:
    __dmb(0xBu);
    do
      v54 = __ldrex((unsigned int *)v20);
    while ( __strex(v54 & 0xFFFFFF7F, (unsigned int *)v20) );
    if ( *(_DWORD *)(v119 + 1540) )
      KiProcessThreadWaitList(v119, 1, 0, 0);
    v55 = *(_DWORD *)(v119 + 8);
    if ( v124 < 2 )
    {
      v56 = *(_DWORD *)(v119 + 4);
      v129 = v56;
      if ( v55 )
      {
        KiAbProcessContextSwitch(v56, 0);
        v57 = (unsigned int *)(v119 + 24);
        while ( 1 )
        {
          do
            v58 = __ldrex(v57);
          while ( __strex(1u, v57) );
          __dmb(0xBu);
          if ( !v58 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v57 );
        }
        v133 = *(_DWORD *)(v119 + 8);
        *(_DWORD *)(v119 + 8) = 0;
        __disable_irq();
        *(_BYTE *)(v119 + 16) = 1;
        LODWORD(v59) = ReadTimeStampCounter();
        v123 = v59 - *(_QWORD *)(v119 + 2376);
        v61 = *(_QWORD *)(v56 + 48);
        v60 = (unsigned __int64 *)(v56 + 48);
        v62 = v123 + v61;
        __dmb(0xBu);
        do
          v63 = __ldrexd(v60);
        while ( __strexd(v62, v60) );
        __dmb(0xBu);
        v64 = v129;
        v65 = v123 + *(unsigned int *)(v129 + 56);
        if ( HIDWORD(v65) )
          LODWORD(v65) = -1;
        v66 = v119;
        *(_QWORD *)(v119 + 2376) = v59;
        *(_DWORD *)(v129 + 56) = v65;
        v67 = *(_BYTE *)(v129 + 2);
        v120 = v67;
        if ( (v67 & 0x3E) != 0 )
        {
          if ( (*(_BYTE *)(v129 + 2) & 0x10) != 0 )
          {
            v68 = v66 + 8 * *(unsigned __int8 *)(v129 + 84);
            *(_QWORD *)(v68 + 2392) += *(_QWORD *)(v66 + 2376) - *(_QWORD *)(v66 + 2384);
            *(_DWORD *)(v66 + 2384) = 0;
            *(_DWORD *)(v66 + 2388) = 0;
            v67 &= 0xEFu;
            v120 = v67;
            v64 = v129;
          }
          if ( (v67 & 0x3E) != 0 )
          {
            if ( (v67 & 0x20) != 0 )
            {
              v138 = *(_DWORD *)(v64 + 1084);
              if ( v138 )
              {
                v69 = (unsigned __int64 *)(v138 + 8 * (*(unsigned __int8 *)(v66 + 2986) + 2 * PoGetFrequencyBucket(v66)));
                HIDWORD(v70) = *((_DWORD *)v69 + 1);
                LODWORD(v70) = v123;
                v71 = __PAIR64__(HIDWORD(v123), *(_DWORD *)v69) + v70;
                __dmb(0xBu);
                do
                  v72 = __ldrexd(v69);
                while ( __strexd(v71, v69) );
                __dmb(0xBu);
                v64 = v129;
                v67 = v120;
              }
              v67 &= 0xDFu;
            }
            if ( (v67 & 0x3E) != 0 )
            {
              v73 = *(_DWORD *)(v64 + 68);
              if ( v73 && (v74 = v73 + *(_DWORD *)(v66 + 2352)) != 0 )
              {
                v76 = HIDWORD(v123);
                v75 = v123;
                do
                {
                  *(_QWORD *)v74 += v123;
                  v74 = *(_DWORD *)(v74 + 236);
                }
                while ( v74 );
              }
              else
              {
                v76 = HIDWORD(v123);
                v75 = v123;
              }
              if ( (*(_BYTE *)(v64 + 2) & 8) != 0
                && (*(_DWORD *)(v64 + 356) & *(_DWORD *)(*(_DWORD *)(v66 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v66 + 2360) + 260) )
              {
                *(_QWORD *)(v66 + 2368) += __PAIR64__(v76, v75);
              }
              if ( *(_DWORD *)(v64 + 236) )
                KiEndCounterAccumulation(v64);
            }
          }
        }
        __enable_irq();
        *(_DWORD *)(v66 + 4) = v133;
        *(_BYTE *)(v133 + 132) = 2;
        *(_BYTE *)(v64 + 395) = 32;
        *(_BYTE *)(v64 + 134) = v124;
        KiQueueReadyThread(v66, v64);
        if ( !KiSwapContext(v64, v133, v124) )
          goto LABEL_172;
        KfLowerIrql(1);
        *(_DWORD *)(v64 + 76) &= 0xFFFFFFBF;
      }
      else
      {
        if ( (*(_DWORD *)(v56 + 76) & 0x40) == 0 )
        {
LABEL_172:
          v77 = v124;
          v78 = (void (__fastcall **)(int))&KfLowerIrql;
LABEL_176:
          (*v78)(v77);
          goto LABEL_177;
        }
        KfLowerIrql(1);
        *(_DWORD *)(v56 + 76) &= 0xFFFFFFBF;
      }
      KiDeliverApc(0, 0, 0);
      goto LABEL_172;
    }
    if ( v55 && !*(_BYTE *)(v119 + 1754) )
    {
      v77 = 2;
      v78 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
      goto LABEL_176;
    }
LABEL_177:
    if ( v7 )
    {
      if ( (*(_DWORD *)(v5 + 8) & 4) == 0 )
        ObfDereferenceObjectWithTag(*(_DWORD *)(v5 + 44));
      if ( (v7[11] & 2) != 0 && (*(_DWORD *)(v5 + 8) & 0x1000) == 0 )
      {
        KeSetEvent(v7 + 23, 0, 0);
        v7[7] = *(_DWORD *)(v5 + 24);
      }
    }
LABEL_187:
    v79 = *(_DWORD *)(v5 + 8);
    if ( (v79 & 0x2000) != 0 )
      v80 = *(_DWORD *)(v5 + 48) & 0xFFFFFFFC;
    else
      v80 = 0;
    v81 = *(_DWORD *)(v5 + 28);
    if ( (v79 & 0x100) != 0 )
    {
      if ( IoCountOperations == 1 )
      {
        if ( !v80 )
          v80 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150);
        v82 = (unsigned __int64 *)(v80 + 456);
        do
          v83 = __ldrexd(v82);
        while ( __strexd(v83 + (unsigned int)v81, v82) );
        v84 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3040);
        do
          v85 = __ldrexd(v84);
        while ( __strexd(v85 + (unsigned int)v81, v84) );
      }
    }
    else if ( (v79 & 0x200) != 0 )
    {
      if ( IoCountOperations == 1 )
      {
        if ( !v80 )
          v80 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150);
        v86 = (unsigned __int64 *)(v80 + 464);
        do
          v87 = __ldrexd(v86);
        while ( __strexd(v87 + (unsigned int)v81, v86) );
        v88 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3048);
        do
          v89 = __ldrexd(v88);
        while ( __strexd(v89 + (unsigned int)v81, v88) );
      }
    }
    else if ( v81 >= 0 && IoCountOperations == 1 )
    {
      if ( !v80 )
        v80 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150);
      v90 = (unsigned __int64 *)(v80 + 472);
      do
        v91 = __ldrexd(v90);
      while ( __strexd(v91 + (unsigned int)v81, v90) );
      v92 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3056);
      do
        v93 = __ldrexd(v92);
      while ( __strexd(v93 + (unsigned int)v81, v92) );
    }
    if ( (*(_DWORD *)(v5 + 8) & 0x2000) != 0 )
    {
      IopDequeueIrpFromFileObject((_DWORD *)v5, (int)v7);
    }
    else
    {
      *(_DWORD *)(v5 + 80) = v6;
      v94 = 0;
      if ( v6 )
      {
        v95 = (unsigned int *)(v6 + 1024);
        v94 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v6 + 1024);
        }
        else
        {
          do
            v96 = __ldrex(v95);
          while ( __strex(1u, v95) );
          __dmb(0xBu);
          if ( v96 )
            KxWaitForSpinLockAndAcquire(v6 + 1024);
        }
      }
      v97 = (_DWORD *)(v5 + 16);
      v98 = *(_DWORD *)(v5 + 16);
      v99 = *(_DWORD **)(v5 + 20);
      if ( *(_DWORD *)(v98 + 4) != v5 + 16 || (_DWORD *)*v99 != v97 )
        __fastfail(3u);
      *v99 = v98;
      *(_DWORD *)(v98 + 4) = v99;
      *(_DWORD *)(v5 + 20) = v5 + 16;
      *v97 = v97;
      if ( v6 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v6 + 1024);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)(v6 + 1024) = 0;
        }
        KfLowerIrql(v94);
      }
    }
    v100 = *(_DWORD *)(v5 + 8) & 0x8000;
    if ( v100 || (v101 = *(_DWORD *)(v5 + 48)) == 0 )
    {
      if ( v130
        && *(_DWORD *)(v5 + 52)
        && ((v7[11] & 0x2000000) == 0 || *(_BYTE *)(v5 + 33) || (*(_DWORD *)(v5 + 24) & 0xC0000000) == 0x80000000) )
      {
        v126 = 0;
        v103 = *(_DWORD *)(v7[1] + 44);
        if ( v103 == 8 || v103 == 20 )
          v126 = 1;
        *(_DWORD *)(v5 + 64) = v131;
        *(_DWORD *)(v5 + 96) = 0;
        v104 = (_DWORD *)(v5 + 88);
        v105 = KfRaiseIrql(2);
        v106 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v107 = v106 + 1408;
        v108 = *(_DWORD *)(v106 + 1412);
        v134 = v108;
        if ( (dword_682604 & 0x1000000) != 0 )
        {
          v109 = *(_BYTE *)(v108 + 132) == 2
              && *(_DWORD *)(v108 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
          EtwTraceEnqueueWork(v108, v104, v109);
          v108 = v134;
        }
        v110 = v126;
        if ( v126 && (*(_BYTE *)(v130 + 1) & 2) != 0 )
        {
          v110 = 0;
          v126 = 0;
        }
        do
          v111 = __ldrex((unsigned __int8 *)v130);
        while ( __strex(v111 | 0x80, (unsigned __int8 *)v130) );
        __dmb(0xBu);
        if ( v111 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v130 & 0x80) != 0 );
            do
              v112 = __ldrex((unsigned __int8 *)v130);
            while ( __strex(v112 | 0x80, (unsigned __int8 *)v130) );
            __dmb(0xBu);
          }
          while ( v112 >> 7 );
        }
        if ( *(_DWORD *)(v130 + 12) == v130 + 8
          || *(_DWORD *)(v130 + 24) >= *(_DWORD *)(v130 + 28)
          || *(_DWORD *)(v108 + 152) == v130 && *(_BYTE *)(v108 + 395) == 15 )
        {
          v113 = 0;
        }
        else
        {
          v113 = KiWakeQueueWaiter(v107, v130, (int)v104);
          v110 = v126;
        }
        if ( !v113 )
        {
          ++*(_DWORD *)(v130 + 4);
          v114 = *(_DWORD **)(v130 + 20);
          *v104 = v130 + 16;
          v104[1] = v114;
          if ( *v114 != v130 + 16 )
            __fastfail(3u);
          *v114 = v104;
          *(_DWORD *)(v130 + 20) = v104;
        }
        __dmb(0xBu);
        do
          v115 = __ldrex((unsigned int *)v130);
        while ( __strex(v115 & 0xFFFFFF7F, (unsigned int *)v130) );
        result = KiExitDispatcher(v107, 0, 1, v110, v105);
      }
      else if ( !v100 || (result = sub_456A04((unsigned int *)(v5 + 48), -1)) == 0 )
      {
        result = pIoFreeIrp(v5);
      }
    }
    else
    {
      if ( v125 )
        v102 = *(char *)(v5 + 38);
      else
        v102 = 2;
      KeInitializeApc(
        v5 + 64,
        v6,
        v102,
        (int)IopUserRundown,
        (int)IopUserRundown,
        v101,
        *(_BYTE *)(v5 + 32),
        *(_DWORD *)(v5 + 52));
      result = KeInsertQueueApc(v5 + 64, *(_DWORD *)(v5 + 40), 0, 2);
    }
    if ( v7 )
    {
      v116 = v7 - 6;
      if ( ObpTraceFlags )
        result = ObpPushStackInfo(v7 - 6, 0, 1, 1953261124);
      __dmb(0xBu);
      do
      {
        v117 = __ldrex(v116);
        v118 = v117 - 1;
      }
      while ( __strex(v118, v116) );
      if ( v118 <= 0 )
      {
        if ( *(v7 - 5) )
          KeBugCheckEx(
            24,
            ObTypeIndexTable[(unsigned __int8)((unsigned __int16)((_WORD)v7 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *((unsigned __int8 *)v7 - 12)],
            v7);
        if ( v118 < 0 )
          KeBugCheckEx(24, 0, v7);
        result = ObpDeferObjectDeletion((unsigned int)(v7 - 6));
      }
    }
    return result;
  }
  if ( !*(_BYTE *)(v5 + 33) || !v7 )
    goto LABEL_29;
  if ( (*(_DWORD *)(v5 + 8) & 4) == 0 )
  {
    v7[7] = v13;
LABEL_27:
    v15 = v7 + 23;
    goto LABEL_28;
  }
  v14 = *(_DWORD **)(v5 + 40);
  *v14 = *(_DWORD *)(v5 + 24);
  v14[1] = *(_DWORD *)(v5 + 28);
  v15 = *(_DWORD **)(v5 + 44);
  if ( !v15 )
    goto LABEL_27;
LABEL_28:
  KeSetEvent(v15, 0, 0);
LABEL_29:
  if ( (*(_DWORD *)(v5 + 8) & 0x2000) != 0 )
    IopDequeueIrpFromFileObject((_DWORD *)v5, (int)v7);
  if ( v7 )
    ObDereferenceObjectDeferDeleteWithTag((unsigned int)v7);
  v16 = *(_DWORD *)(v5 + 44);
  if ( v16 && v7 && (*(_DWORD *)(v5 + 8) & 4) == 0 )
    ObfDereferenceObjectWithTag(v16);
  if ( (*(_DWORD *)(v5 + 8) & 0x8000) != 0 )
  {
    result = sub_456A04((unsigned int *)(v5 + 48), -1);
    if ( result )
      return result;
  }
  else
  {
    *(_DWORD *)(v5 + 80) = v6;
    IopDequeueIrpFromThread((_DWORD *)v5);
  }
  return pIoFreeIrp(v5);
}
