// MiStoreWriteModifiedPages 
 
int __fastcall MiStoreWriteModifiedPages(int a1)
{
  int v1; // r6
  int v2; // r3
  int v3; // r8
  unsigned int v4; // r3
  int v5; // r0
  int v6; // r4
  _DWORD *v7; // lr
  unsigned int v8; // r9
  __int16 v9; // r3
  int v10; // r7
  __int64 v11; // r0
  int v12; // r2
  int v13; // r5
  _DWORD *v14; // r9
  unsigned int v15; // r4
  unsigned int v16; // r10
  _DWORD *v17; // lr
  int v18; // r10
  int *v19; // r3
  int *v20; // r2
  int *v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r5
  unsigned int v24; // r0
  unsigned int v25; // r9
  int *v26; // r4
  int i; // r3
  unsigned int v28; // r2
  unsigned int v29; // r0
  int v30; // r5
  unsigned __int8 *v31; // r1
  unsigned int v32; // r2
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  int v36; // r0
  unsigned int *v37; // r10
  unsigned int v38; // r1
  _DWORD *v39; // lr
  unsigned int v40; // r4
  __int64 v41; // kr00_8
  unsigned int v42; // r1
  unsigned int v43; // r6
  unsigned int *v44; // r5
  unsigned int v45; // r2
  int v46; // r0
  unsigned int v47; // r2
  int v48; // r10
  int v49; // r3
  int v50; // r2
  unsigned int *v51; // r2
  unsigned int v52; // r0
  int v53; // r5
  unsigned __int8 *v54; // r1
  unsigned int v55; // r2
  unsigned __int8 *v56; // r1
  unsigned int v57; // r3
  unsigned int v58; // r2
  unsigned int v59; // r4
  unsigned int v60; // r1
  int v61; // r3
  int v62; // r0
  unsigned int v63; // r4
  int v64; // r3
  int *v65; // r1
  int *v66; // r2
  char v67; // r3
  int v68; // t1
  _BYTE *v69; // r0
  int v70; // r10
  int v71; // r2
  unsigned int v72; // r4
  int *v73; // r0
  int v74; // r7
  unsigned int v75; // lr
  __int64 v76; // kr08_8
  unsigned int v77; // r5
  unsigned int v78; // r1
  int j; // r3
  unsigned int v80; // r2
  unsigned int v81; // r1
  int v82; // r2
  int v83; // r5
  int v84; // r6
  unsigned __int8 *v85; // r3
  unsigned int v86; // r1
  unsigned __int8 *v87; // r1
  int v88; // r3
  unsigned int v89; // r2
  unsigned int *v90; // r2
  unsigned int v91; // r0
  int v92; // r4
  int v93; // r9
  __int16 v94; // r3
  int *v95; // r0
  _DWORD *v97; // [sp+10h] [bp-98h]
  unsigned int v98; // [sp+14h] [bp-94h]
  _DWORD *v99; // [sp+18h] [bp-90h]
  int v100; // [sp+1Ch] [bp-8Ch] BYREF
  int v101; // [sp+20h] [bp-88h]
  unsigned int v102; // [sp+24h] [bp-84h]
  int v103; // [sp+28h] [bp-80h]
  _DWORD *v104; // [sp+2Ch] [bp-7Ch]
  int v105; // [sp+30h] [bp-78h]
  unsigned int v106; // [sp+34h] [bp-74h]
  unsigned int v107; // [sp+38h] [bp-70h]
  int v108; // [sp+3Ch] [bp-6Ch] BYREF
  int v109; // [sp+40h] [bp-68h]
  int v110; // [sp+44h] [bp-64h]
  int v111; // [sp+48h] [bp-60h]
  unsigned int v112; // [sp+4Ch] [bp-5Ch]
  unsigned int v113; // [sp+50h] [bp-58h]
  int v114; // [sp+54h] [bp-54h] BYREF
  __int64 v115; // [sp+58h] [bp-50h] BYREF
  unsigned int v116; // [sp+60h] [bp-48h]
  int v117; // [sp+64h] [bp-44h]
  int *v118; // [sp+68h] [bp-40h] BYREF
  unsigned int v119; // [sp+6Ch] [bp-3Ch]
  int v120; // [sp+70h] [bp-38h]
  char v121[40]; // [sp+80h] [bp-28h] BYREF

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 84);
  v105 = a1;
  v3 = *(_DWORD *)(v2 + 128);
  v4 = *(_DWORD *)(a1 + 148);
  v5 = *(_DWORD *)(v3 + 684);
  v117 = v3;
  v107 = v4 >> 12;
  if ( v5 )
  {
    MiStoreLogWriteDisabled(v5);
    v6 = -1073741670;
    --*(_DWORD *)(v3 + 684);
    return v6;
  }
  v7 = *(_DWORD **)(v3 + 4 * *(_DWORD *)(v3 + 668) + 3600);
  v97 = v7;
  if ( !v7[3] )
  {
    MiStoreLogFullPagefile();
    return -1073741697;
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134);
  v111 = v8;
  *(_WORD *)(v8 + 308) = v9 - 1;
  *(_DWORD *)(v1 + 24) = 1;
  v118 = 0;
  v100 = 0;
  v104 = 0;
  v101 = 17;
  v10 = 0;
  v102 = v7[17];
  v106 = 0;
  v103 = 1;
  do
  {
    v11 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v12 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v13 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v12 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v11 != MEMORY[0xFFFF93B0] );
  v112 = v13 - v11;
  v116 = v13 - v11;
  v110 = v1 + 156;
  v14 = (_DWORD *)(v1 + 156);
  v15 = 0;
LABEL_11:
  v98 = v15;
  v99 = v14;
  while ( 1 )
  {
    v16 = v107;
    v17 = v97;
    if ( v15 >= v107 )
      break;
    v109 = 1;
    v18 = *v14;
    if ( *v14 == dword_6348F4 || !v97[3] )
      goto LABEL_80;
    v19 = (int *)v97[16];
    v20 = v118;
    if ( v118 != v19 )
    {
      if ( v118 )
      {
        v21 = MiDerefPageFileSpaceBitmaps((int)v97, &v118, 1, (int)v19);
        if ( v21 )
          ExFreePoolWithTag(v21);
        v17 = v97;
      }
      MiRefPageFileSpaceBitmaps(v17, &v118, (int)v20, (int)v19);
    }
    v22 = v102;
    if ( v102 < v119 )
      v23 = v102;
    else
      v23 = 0;
    v24 = v119 - 1;
    while ( 1 )
    {
      if ( v24 - v23 == -1 )
      {
        v25 = -1;
      }
      else
      {
        v26 = (int *)(v120 + 4 * (v23 >> 5));
        for ( i = *v26 | ((1 << (v23 & 0x1F)) - 1); i == -1; i = *v26 )
        {
          if ( (unsigned int)++v26 > v120 + 4 * (v24 >> 5) )
            goto LABEL_38;
        }
        v28 = __clz(__rbit(~i));
        v25 = v28 + 32 * (((int)v26 - v120) >> 2);
        v113 = v28;
        if ( v25 > v24 )
        {
LABEL_38:
          v25 = -1;
          goto LABEL_33;
        }
        if ( v25 != -1 )
          break;
LABEL_33:
        v22 = v102;
      }
      if ( !v23 )
        break;
      v29 = v22 + 1;
      if ( v22 + 1 > v119 )
        v29 = v119;
      v24 = v29 - 1;
      v23 = 0;
    }
    v10 = MmPfnDatabase + 24 * v18;
    v30 = KfRaiseIrql(2);
    v101 = v30;
    v31 = (unsigned __int8 *)(v10 + 15);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 | 0x80, v31) );
    __dmb(0xBu);
    if ( v32 >> 7 )
    {
      v33 = (unsigned __int8 *)(v10 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v34 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( (v34 & 0x80000000) != 0 );
        do
          v35 = __ldrex(v33);
        while ( __strex(v35 | 0x80, v33) );
        __dmb(0xBu);
      }
      while ( v35 >> 7 );
    }
    if ( (*(_DWORD *)(v10 + 12) & 0x40000000) != 0 )
      goto LABEL_49;
    v108 = 0;
    v36 = MiStoreCheckCandidatePage(v10, v25, (int)&v114, (unsigned int *)&v115, &v108);
    if ( v36 < 0 )
    {
      MiStoreLogNotCandidate(v36, v25);
      goto LABEL_49;
    }
    __dmb(0xBu);
    v37 = (unsigned int *)(v10 + 12);
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 & 0x7FFFFFFF, v37) );
    KfLowerIrql(v30);
    v39 = v104;
    v30 = 17;
    v101 = 17;
    if ( !v104 )
    {
      v39 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)(v3 + 728));
      v104 = v39;
      if ( !v39 )
      {
        v39 = (_DWORD *)ExAllocatePoolWithTag(512, 72);
        v104 = v39;
        if ( !v39 )
        {
          v100 = 1;
LABEL_49:
          v1 = v105;
LABEL_50:
          v15 = v98;
          v14 = v99;
LABEL_81:
          if ( v30 != 17 )
          {
            __dmb(0xBu);
            v51 = (unsigned int *)(v10 + 12);
            do
              v52 = __ldrex(v51);
            while ( __strex(v52 & 0x7FFFFFFF, v51) );
            KfLowerIrql(v30);
            v101 = 17;
          }
          if ( v109 )
            *(_BYTE *)((v15 >> 3) + *(_DWORD *)(*(_DWORD *)(v3 + 740) + 4)) |= 1 << (v15 & 7);
          ++v15;
          v106 = 0;
          ++v14;
          goto LABEL_11;
        }
      }
    }
    v40 = v97[3] - 1;
    if ( v40 >= 8 )
      v40 = 8;
    if ( v103 )
    {
      if ( *(_DWORD *)(v3 + 3712) >= 0x100u )
      {
        do
        {
          v41 = MEMORY[0xFFFF93B0];
          while ( 1 )
          {
            v42 = MEMORY[0xFFFF900C];
            __dmb(0xBu);
            v43 = MEMORY[0xFFFF9008];
            __dmb(0xBu);
            if ( v42 == MEMORY[0xFFFF9010] )
              break;
            __dmb(0xAu);
            __yield();
          }
        }
        while ( v41 != MEMORY[0xFFFF93B0] );
        v3 = v117;
        v39 = v104;
        v37 = (unsigned int *)(v10 + 12);
        if ( __PAIR64__(v42, v43) - v41 - __PAIR64__(v116, v112) >= 0x2FAF080 )
          v103 = 0;
      }
      else
      {
        v103 = 0;
        if ( v40 >= 3 )
          v40 = 3;
      }
    }
    __dmb(0xBu);
    v1 = v105;
    v44 = (unsigned int *)(v105 + 24);
    do
      v45 = __ldrex(v44);
    while ( __strex(v45 + 1, v44) );
    __dmb(0xBu);
    v46 = MiStoreWriteIssue((int)v39, v10, &v114, (int)&v115, (int)v39, v108, v105, v103);
    if ( v46 >= 0 )
    {
      v109 = 0;
      v104 = 0;
      KeAcquireInStackQueuedSpinLock(v97 + 29, (unsigned int)v121);
      *(_BYTE *)((v25 >> 3) + *(_DWORD *)(v97[16] + 8)) |= 1 << (v25 & 7);
      v102 = v25 + 1;
      v97[17] = v25 + 1;
      --v97[3];
      MiUpdatePagefilePeakUsage(v97);
      KeReleaseInStackQueuedSpinLock((int)v121);
      v53 = KfRaiseIrql(2);
      v54 = (unsigned __int8 *)(v10 + 15);
      do
        v55 = __ldrex(v54);
      while ( __strex(v55 | 0x80, v54) );
      __dmb(0xBu);
      if ( v55 >> 7 )
      {
        v56 = (unsigned __int8 *)(v10 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v57 = *v37;
            __dmb(0xBu);
          }
          while ( (v57 & 0x80000000) != 0 );
          do
            v58 = __ldrex(v56);
          while ( __strex(v58 | 0x80, v56) );
          __dmb(0xBu);
        }
        while ( v58 >> 7 );
      }
      v59 = *(_DWORD *)(v10 + 8);
      if ( (v59 & 0x10) != 0 )
      {
        *(_DWORD *)(v10 + 8) = v59 & 0xFFFFFFEF;
      }
      else if ( (v59 & 8) == 0 )
      {
        v59 = 0;
      }
      *(_DWORD *)(v10 + 8) &= 0xFFFFFFF7;
      MiUpdatePfnBackingStore(v10, (int)v97, v25, 1);
      __dmb(0xBu);
      do
        v60 = __ldrex(v37);
      while ( __strex(v60 & 0x7FFFFFFF, v37) );
      KfLowerIrql(v53);
      v30 = 17;
      v101 = 17;
      MiReleasePageFileInfo(v3, v59, 2, v61);
      goto LABEL_50;
    }
    __dmb(0xBu);
    do
      v47 = __ldrex(v44);
    while ( __strex(v47 - 1, v44) );
    __dmb(0xBu);
    v48 = v106;
    if ( v46 != -1073740682 )
    {
      if ( v46 == -1073741670 )
        v100 = 1;
LABEL_79:
      v49 = v103;
      v50 = *(_DWORD *)(v3 + 688) + 1;
      *(_DWORD *)(v3 + 688) = v50;
      MiStoreLogWriteIssueFailure(v46, (int *)&v115, v25, v48, v49, v50);
      v15 = v98;
      v14 = v99;
LABEL_80:
      v30 = v101;
      goto LABEL_81;
    }
    v102 = v25 + 1;
    if ( v106 >= v40 )
      goto LABEL_79;
    MiStoreLogWriteIssueRetry(&v115, v25, v106, v103, *(_DWORD *)(v3 + 688));
    v15 = v98;
    v14 = v99;
    ++v106;
  }
  if ( v100 )
    *(_DWORD *)(v3 + 684) = 32;
  v62 = *(_DWORD *)(v3 + 740);
  v63 = v16 - 1;
  if ( v16 - 1 >= *(_DWORD *)v62 )
    goto LABEL_118;
  if ( v16 <= 1 )
  {
    if ( v16 == 1 )
    {
      v64 = **(_BYTE **)(v62 + 4) & 1;
      goto LABEL_116;
    }
LABEL_118:
    v70 = *(__int64 *)(v1 + 104) >> 12;
    v71 = *(_DWORD *)(v1 + 84);
    v100 = 0;
    v72 = -1;
    v73 = MI_SET_PAGING_FILE_INFO(&v100, &v100, v71, v70, 1);
    LOWORD(v74) = v100;
LABEL_119:
    v75 = v72 + 1;
    v76 = *(_QWORD *)*(_DWORD *)(v3 + 740);
    if ( v72 + 1 < (unsigned int)v76 )
      v77 = v72 + 1;
    else
      v77 = 0;
    v78 = v76 - 1;
    while ( 1 )
    {
      if ( v78 - v77 != -1 )
      {
        v73 = (int *)(HIDWORD(v76) + 4 * (v77 >> 5));
        for ( j = ~*v73 | ((1 << (v77 & 0x1F)) - 1); j == -1; j = ~*v73 )
        {
          if ( (unsigned int)++v73 > HIDWORD(v76) + 4 * (v78 >> 5) )
            goto LABEL_131;
        }
        v80 = __clz(__rbit(~j));
        v72 = v80 + 32 * (((int)v73 - HIDWORD(v76)) >> 2);
        v113 = v80;
        if ( v72 <= v78 && v72 != -1 )
        {
          *(_BYTE *)((v72 >> 3) + *(_DWORD *)(*(_DWORD *)(v3 + 740) + 4)) &= ~(unsigned __int8)(1 << (v72 & 7));
          v82 = *(_DWORD *)(v110 + 4 * v72);
          if ( v82 == dword_6348F4 )
          {
            v74 = v74 & 0x1FFF ^ ((v72 + v70) << 13);
            v73 = (int *)MiReleasePageFileInfo(v3, v74, 2, v72 + v70);
          }
          else
          {
            v83 = MmPfnDatabase + 24 * v82;
            v84 = KfRaiseIrql(2);
            v85 = (unsigned __int8 *)(v83 + 15);
            do
              v86 = __ldrex(v85);
            while ( __strex(v86 | 0x80, v85) );
            __dmb(0xBu);
            if ( v86 >> 7 )
            {
              v87 = (unsigned __int8 *)(v83 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v88 = *(_DWORD *)(v83 + 12);
                  __dmb(0xBu);
                }
                while ( (v88 & 0x80000000) != 0 );
                do
                  v89 = __ldrex(v87);
                while ( __strex(v89 | 0x80, v87) );
                __dmb(0xBu);
              }
              while ( v89 >> 7 );
            }
            *(_BYTE *)(v83 + 18) |= 0x10u;
            __dmb(0xBu);
            v90 = (unsigned int *)(v83 + 12);
            do
              v91 = __ldrex(v90);
            while ( __strex(v91 & 0x7FFFFFFF, v90) );
            v73 = (int *)KfLowerIrql(v84);
          }
          goto LABEL_119;
        }
      }
LABEL_131:
      if ( !v77 )
        break;
      v81 = v75 + 1;
      if ( v75 + 1 > (unsigned int)v76 )
        v81 = v76;
      v78 = v81 - 1;
      v77 = 0;
    }
    v92 = v105;
    MiStoreUpdatePagefileHash((int)v73, v78, v105 + 128, v107);
    *(_DWORD *)(v92 + 20) |= 0x20u;
    v69 = (_BYTE *)MiStoreModifiedWriteDereference(v92);
    v6 = 259;
    goto LABEL_148;
  }
  v65 = *(int **)(v62 + 4);
  v66 = &v65[v63 >> 5];
  if ( v65 == v66 )
  {
    v67 = 32 - v16;
  }
  else
  {
    if ( *v65 != -1 )
      goto LABEL_118;
    ++v65;
    while ( v65 != v66 )
    {
      v68 = *v65++;
      if ( v68 != -1 )
        goto LABEL_118;
    }
    v67 = 31 - (v63 & 0x1F);
  }
  v64 = (*v65 & (0xFFFFFFFF >> v67)) == 0xFFFFFFFF >> v67;
LABEL_116:
  if ( !v64 )
    goto LABEL_118;
  v69 = RtlClearBits((_BYTE *)v62, 0, v16);
  v6 = -1073740759;
  *(_DWORD *)(v1 + 24) = 0;
LABEL_148:
  v93 = v111;
  v94 = *(_WORD *)(v111 + 308) + 1;
  *(_WORD *)(v111 + 308) = v94;
  if ( !v94 && *(_DWORD *)(v93 + 100) != v93 + 100 && !*(_WORD *)(v93 + 310) )
    KiCheckForKernelApcDelivery((int)v69);
  if ( v104 )
    MiStoreFreeWriteSupport(v104, v3);
  if ( v118 )
  {
    v95 = MiDerefPageFileSpaceBitmaps((int)v97, &v118, 0, (int)v118);
    if ( v95 )
      ExFreePoolWithTag(v95);
  }
  return v6;
}
