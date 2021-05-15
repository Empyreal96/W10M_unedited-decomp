// sub_95CCA0 
 
int *sub_95CCA0()
{
  int v0; // r10
  int *result; // r0
  int v2; // r0
  unsigned __int64 v3; // r0
  unsigned __int64 v4; // r2
  unsigned __int64 v5; // kr00_8
  int v6; // r7
  __int64 *v7; // r1
  int v8; // r0
  int v9; // r8
  int v10; // t1
  int v11; // r2
  int v12; // r3
  __int16 v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r8
  int v17; // r4
  int v18; // r3
  unsigned int v19; // r7
  int v20; // r5
  __int16 v21; // r3
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r8
  unsigned int v25; // r1
  int v26; // r3
  int *v27; // r10
  unsigned int v28; // r2
  int v29; // r2
  int v30; // r1
  unsigned int v31; // r2
  int *v32; // r0
  unsigned int v33; // lr
  int v34; // r7
  int v35; // r2
  int v36; // r3
  char v37; // r5
  unsigned __int8 *v38; // r4
  unsigned int v39; // r0
  unsigned int v40; // r2
  unsigned int v41; // r1
  unsigned int v42; // r3
  int v43; // r4
  int v44; // r3
  int v45; // r2
  int v46; // r1
  unsigned int v47; // r7
  int *v48; // r5
  int v49; // r0
  int v50; // r0
  int v51; // r2
  int v52; // lr
  int *v53; // r1
  int v54; // r0
  int v55; // t1
  int v56; // r1
  int v57; // r4
  int v58; // r2
  int v59; // lr
  int *v60; // r1
  int v61; // r0
  int v62; // t1
  unsigned int v63; // r1
  int v64; // r0
  unsigned int v65; // r1
  int v66; // r3
  unsigned __int64 v67; // r2
  unsigned __int64 v68; // r2
  int v69; // r3
  int v70; // r0
  int v71; // r7
  int v72; // r2
  int v73; // r3
  int v74; // r0
  unsigned __int8 *v75; // r4
  char v76; // r5
  unsigned int v77; // r0
  unsigned int v78; // r2
  unsigned int v79; // r1
  unsigned int v80; // r3
  int v81; // r4
  int v82; // r3
  int v83; // r3
  int v84; // r3
  unsigned __int8 *v85; // r3
  unsigned int v86; // r2
  int v87; // r2
  int v88; // r1
  int v89; // r8
  int v90; // r4
  int v91; // r3
  int v92; // r2
  int v93; // r1
  int v94; // r7
  int v95; // r5
  int v96; // r3
  __int16 v97; // r3
  unsigned int *v98; // r2
  unsigned int v99; // r1
  int v100; // r3
  unsigned __int8 *v101; // r2
  unsigned int v102; // r4
  unsigned int *v103; // r2
  unsigned int v104; // r1
  unsigned int *v105; // r2
  unsigned int v106; // r1
  unsigned __int8 *v107; // r3
  unsigned int v108; // r2
  unsigned int *v109; // r2
  unsigned int v110; // r1
  unsigned __int8 *v111; // r2
  unsigned int v112; // r4
  unsigned int v113; // r0
  int *v114; // r4
  int v115; // r5
  int v116; // r0
  unsigned int v117; // r0
  unsigned int v118; // r0
  int v119; // [sp+8h] [bp-A8h]
  unsigned int v120; // [sp+Ch] [bp-A4h] BYREF
  unsigned int v121; // [sp+10h] [bp-A0h]
  int v122; // [sp+14h] [bp-9Ch]
  int v123; // [sp+18h] [bp-98h]
  int v124; // [sp+1Ch] [bp-94h]
  int v125; // [sp+20h] [bp-90h]
  int v126; // [sp+24h] [bp-8Ch]
  int v127; // [sp+28h] [bp-88h]
  int v128; // [sp+2Ch] [bp-84h]
  int v129; // [sp+30h] [bp-80h]
  int v130[2]; // [sp+38h] [bp-78h] BYREF
  int v131; // [sp+40h] [bp-70h]
  int v132; // [sp+44h] [bp-6Ch]
  int *v133; // [sp+48h] [bp-68h]
  int v134; // [sp+4Ch] [bp-64h]
  int v135; // [sp+50h] [bp-60h]
  int v136; // [sp+54h] [bp-5Ch]
  __int64 v137; // [sp+58h] [bp-58h] BYREF
  unsigned int v138; // [sp+60h] [bp-50h]
  char v139[4]; // [sp+68h] [bp-48h] BYREF
  int v140; // [sp+6Ch] [bp-44h]
  int v141; // [sp+70h] [bp-40h]
  __int64 v142; // [sp+74h] [bp-3Ch]
  int v143; // [sp+7Ch] [bp-34h]
  int v144; // [sp+80h] [bp-30h]
  int v145; // [sp+84h] [bp-2Ch]
  int v146; // [sp+88h] [bp-28h]

  v0 = 1;
  v125 = 1;
  ExpFastCacheUpdateLock = 0;
  ExpFastCacheLock = 0;
  if ( NtOpenKey() >= 0 )
    return (int *)sub_96CAC4();
  if ( NtOpenKey() >= 0 )
  {
    if ( NtQueryValueKey(v119, &dword_9788F8, 2, (int)v139, 40, (unsigned int)&v120) >= 0 && v140 == 4 && v141 == 4 )
    {
      dword_920280 = v142;
      if ( (unsigned int)v142 > 0xA8 )
        dword_920280 = 168;
    }
    NtClose();
  }
  v2 = NtOpenKey();
  v126 = 0;
  v127 = 0;
  v128 = 0;
  v129 = 0;
  v122 = 0;
  v123 = 0;
  if ( v2 < 0 )
    goto LABEL_140;
  if ( NtQueryValueKey(v119, &dword_8C81C4, 2, (int)v139, 40, (unsigned int)&v120) >= 0 && v140 == 3 && v141 == 24 )
  {
    v3 = v142;
    v0 = 0;
    v125 = 0;
    v126 = v143;
    v137 = v142;
    v128 = v144;
    v129 = v145;
    v127 = v146;
    __dmb(0xBu);
    do
      v4 = __ldrexd((unsigned __int64 *)&qword_922C10);
    while ( __strexd(v3, (unsigned __int64 *)&qword_922C10) );
    __dmb(0xBu);
    do
      v5 = __ldrexd((unsigned __int64 *)&qword_922C10);
    while ( !v5 && __strexd(0i64, (unsigned __int64 *)&qword_922C10) );
    __dmb(0xBu);
    if ( HIDWORD(v5) >= 0x7FFFFFFF && HIDWORD(v5) > 0x7FFFFFFF )
    {
      __dmb(0xBu);
      do
        v67 = __ldrexd((unsigned __int64 *)&qword_922C10);
      while ( __strexd(0i64, (unsigned __int64 *)&qword_922C10) );
      __dmb(0xBu);
    }
    v6 = 0;
    v7 = &v137;
    v8 = 8;
    v9 = 0;
    do
    {
      v10 = *(unsigned __int8 *)v7;
      v7 = (__int64 *)((char *)v7 + 1);
      v11 = v10 - 23737705 + v9;
      --v8;
      v6 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v10 - 23737705 + v6), 21), 21), 21);
      v9 = v6 + v11;
    }
    while ( v8 );
    v122 = v6;
    v123 = v6 + v11;
  }
  NtClose();
  if ( v0 )
  {
LABEL_140:
    __dmb(0xBu);
    do
      v68 = __ldrexd((unsigned __int64 *)&qword_922C10);
    while ( __strexd(0i64, (unsigned __int64 *)&qword_922C10) );
    __dmb(0xBu);
  }
  v69 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v69 & 0xFFFFFFC0) + 0x134);
  v70 = 4092;
  v124 = 2147483644;
  if ( !KiAbEnabled || ((unsigned int)&ExpFastCacheUpdateLock & 0x7FFFFFFC) == 0 )
  {
    v81 = 0;
    goto LABEL_115;
  }
  v71 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v72 = 0;
  }
  else
  {
    __disable_irq();
    v72 = 1;
  }
  v73 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v72 )
    __enable_irq();
  if ( (v73 & 0x10001) != 0 )
  {
    v74 = KeGetCurrentIrql(4092);
    KeBugCheckEx(402, v71, (int)&ExpFastCacheUpdateLock, v74, 0);
  }
  --*(_WORD *)(v71 + 310);
  if ( !*(_BYTE *)(v71 + 484) )
  {
    if ( !*(_BYTE *)(v71 + 810) )
    {
      v81 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        v70 = (int)EtwTraceAutoBoostEntryExhaustion(v71, (int)&ExpFastCacheUpdateLock);
      goto LABEL_168;
    }
    v75 = (unsigned __int8 *)(v71 + 810);
    v76 = *(_BYTE *)(v71 + 810);
    __dmb(0xBu);
    do
      v77 = __ldrex(v75);
    while ( __strex(v77 & ~v76, v75) );
    __dmb(0xBu);
    v70 = 4092;
    *(_BYTE *)(v71 + 484) |= v76;
  }
  v78 = *(unsigned __int8 *)(v71 + 484);
  v79 = __clz(__rbit(v78));
  v121 = v79;
  *(_BYTE *)(v71 + 484) = v78 & ~(unsigned __int8)(1 << v79);
  v80 = v71 + 48 * v79;
  v81 = v80 + 488;
  if ( v80 == -488 )
  {
LABEL_168:
    v85 = (unsigned __int8 *)(v71 + 81);
    do
      v86 = __ldrex(v85);
    while ( __strex(v86 | 0x80, v85) );
    goto LABEL_163;
  }
  if ( (unsigned int)&ExpFastCacheUpdateLock >= dword_63389C
    && ((v82 = *((unsigned __int8 *)&MiState[2423]
               + ((int)((((unsigned int)&ExpFastCacheUpdateLock >> 20) & 0xFFC)
                      - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v82 == 1)
     || v82 == 11)
    && (v87 = *(_DWORD *)(v71 + 116), (v88 = *(_DWORD *)(v87 + 324)) != 0)
    && v87 != PsInitialSystemProcess )
  {
    v83 = *(_DWORD *)(v88 + 8);
  }
  else
  {
    v83 = -1;
  }
  *(_DWORD *)(v81 + 20) = v83;
  *(_DWORD *)(v81 + 16) = (unsigned int)&ExpFastCacheUpdateLock & 0x7FFFFFFC;
LABEL_163:
  v84 = (__int16)(*(_WORD *)(v71 + 310) + 1);
  *(_WORD *)(v71 + 310) = v84;
  if ( !v84 && *(_DWORD *)(v71 + 100) != v71 + 100 )
    KiCheckForKernelApcDelivery(v70);
  do
LABEL_115:
    v63 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
  while ( __strex(v63 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
  __dmb(0xBu);
  if ( (v63 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpFastCacheUpdateLock, v81, (unsigned int)&ExpFastCacheUpdateLock);
  if ( v81 )
    *(_BYTE *)(v81 + 14) |= 1u;
  sub_7B5F04((int)&dword_8C8214, &dword_922C18);
  __dmb(0xBu);
  do
    v64 = __ldrex(&ExpFastCacheUpdateLock);
  while ( __strex(v64 - 1, &ExpFastCacheUpdateLock) );
  if ( (v64 & 2) != 0 && (v64 & 4) == 0 )
    v64 = (int)ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
  if ( !KiAbEnabled || ((unsigned int)&ExpFastCacheUpdateLock & 0x7FFFFFFC) == 0 )
    goto LABEL_125;
  v89 = 0;
  v90 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (unsigned int)&ExpFastCacheUpdateLock >= dword_63389C
    && ((v91 = *((unsigned __int8 *)&MiState[2423]
               + ((int)((((unsigned int)&ExpFastCacheUpdateLock >> 20) & 0xFFC)
                      - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v91 == 1)
     || v91 == 11)
    && (v92 = *(_DWORD *)(v90 + 116), (v93 = *(_DWORD *)(v92 + 324)) != 0)
    && v92 != PsInitialSystemProcess )
  {
    v94 = *(_DWORD *)(v93 + 8);
  }
  else
  {
    v94 = -1;
  }
  if ( (unsigned int)KeGetCurrentIrql(v64) <= 1 )
  {
    v89 = 1;
    --*(_WORD *)(v90 + 310);
  }
  v64 = KiAbThreadClearAcquiredLockEntry(v90, (int)&ExpFastCacheUpdateLock, v94);
  v95 = v64;
  if ( !v64 )
  {
    if ( (*(_DWORD *)(v90 + 80) & 0x8000) == 0 )
      KeBugCheckEx(354, v90, (int)&ExpFastCacheUpdateLock, v94, 0);
    if ( !v89 )
      goto LABEL_125;
    goto LABEL_192;
  }
  *(_BYTE *)(v64 + 16) |= 2u;
  if ( *(int *)(v64 + 16) < 0 )
    v64 = KiAbEntryRemoveFromTree(v64);
  v97 = *(_WORD *)(v95 + 44);
  if ( v97 )
  {
    if ( (v97 & 1) != 0 )
    {
      __dmb(0xBu);
      v98 = (unsigned int *)(v90 + 804);
      do
        v99 = __ldrex(v98);
      while ( __strex(v99 - 1, v98) );
      __dmb(0xBu);
      v64 = PsBoostThreadIoEx(v90, 1, 0);
    }
    if ( (*(_WORD *)(v95 + 44) & 0xFFFE) != 0 )
      v64 = KiAbThreadUnboostCpuPriority(v90, v95, 1, *(_WORD *)(v95 + 44) & 0xFFFE);
    if ( (dword_682604 & 0x200) != 0 )
      v64 = (int)EtwTraceAutoBoostClearFloor(v90, *(_DWORD *)(v95 + 16) & v124 | 0x80000000, *(_WORD *)(v95 + 44));
    *(_WORD *)(v95 + 44) = 0;
  }
  *(_BYTE *)(v95 + 13) &= 0xFEu;
  *(_DWORD *)(v95 + 16) = 0;
  v100 = (v95 - v90 - 488) / 48;
  if ( v89 )
  {
    *(_BYTE *)(v90 + 484) |= 1 << v100;
LABEL_192:
    v96 = (__int16)(*(_WORD *)(v90 + 310) + 1);
    *(_WORD *)(v90 + 310) = v96;
    if ( !v96 && *(_DWORD *)(v90 + 100) != v90 + 100 )
      v64 = KiCheckForKernelApcDelivery(v64);
    goto LABEL_125;
  }
  __dmb(0xBu);
  v64 = (char)(1 << v100);
  v101 = (unsigned __int8 *)(v90 + 810);
  do
    v102 = __ldrex(v101);
  while ( __strex(v102 | v64, v101) );
  __dmb(0xBu);
LABEL_125:
  v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v66 = (__int16)(*(_WORD *)(v65 + 0x134) + 1);
  *(_WORD *)(v65 + 308) = v66;
  if ( !v66 && *(_DWORD *)(v65 + 100) != v65 + 100 && !*(_WORD *)(v65 + 310) )
    KiCheckForKernelApcDelivery(v64);
  v47 = 0;
  v48 = (int *)&unk_9202A0;
  do
  {
    v130[1] = 0;
    v131 = 24;
    v132 = 0;
    v133 = v48;
    v130[0] = 0;
    v134 = 576;
    v135 = 0;
    v136 = 0;
    v49 = NtOpenKey();
    if ( v49 < 0 )
    {
      if ( v49 == -1073741772 )
      {
        __dmb(0xBu);
        v105 = (unsigned int *)(v48 - 1);
        do
          v106 = __ldrex(v105);
        while ( __strex(0, v105) );
        __dmb(0xBu);
      }
    }
    else
    {
      v50 = NtQueryValueKey(v119, &dword_8C8224, 2, 0, 0, (unsigned int)&v120);
      if ( v50 != -1073741789 )
      {
        if ( v50 == -1073741772 )
        {
          v52 = v122;
          v51 = v123;
          v53 = v130;
          v54 = 8;
          do
          {
            v55 = *(unsigned __int8 *)v53;
            v53 = (int *)((char *)v53 + 1);
            --v54;
            v52 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v55 - 23737705 + v52), 21), 21), 21);
            v51 += v55 - 23737705 + v52;
          }
          while ( v54 );
          v122 = v52;
          v123 = v51;
          __dmb(0xBu);
          v103 = (unsigned int *)(v48 - 1);
          do
            v104 = __ldrex(v103);
          while ( __strex(0, v103) );
          __dmb(0xBu);
        }
        goto LABEL_214;
      }
      if ( v125 )
      {
        NtDeleteValueKey(v119, (unsigned int *)&dword_8C8224);
        goto LABEL_214;
      }
      v56 = v120 + 4;
      if ( v120 + 4 < v120 )
      {
        v120 = -1;
LABEL_214:
        NtClose();
        goto LABEL_113;
      }
      v120 += 4;
      v57 = ExAllocatePoolWithTag(1, v56, 542329939);
      if ( !v57 )
        goto LABEL_214;
      if ( NtQueryValueKey(v119, &dword_8C8224, 2, v57 + 4, v120 - 4, (unsigned int)&v120) >= 0
        && *(_DWORD *)(v57 + 8) == 3 )
      {
        NtClose();
        sub_95D404(v47, *(_DWORD *)(v57 + 12), v57 + 16, v130);
      }
      else
      {
        NtClose();
      }
      ExFreePoolWithTag(v57);
    }
    v59 = v122;
    v58 = v123;
    v60 = v130;
    v61 = 8;
    do
    {
      v62 = *(unsigned __int8 *)v60;
      v60 = (int *)((char *)v60 + 1);
      --v61;
      v59 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v62 - 23737705 + v59), 21), 21), 21);
      v58 += v62 - 23737705 + v59;
    }
    while ( v61 );
    v122 = v59;
    v123 = v58;
LABEL_113:
    ++v47;
    v48 += 10;
  }
  while ( v47 < 5 );
  v24 = 0;
  v27 = dword_920288;
  v121 = 0;
  do
  {
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v31 + 0x134);
    v32 = &KiAbEnabled;
    if ( !KiAbEnabled
      || (v33 = (unsigned int)&ExpFastCacheUpdateLock & v124, ((unsigned int)&ExpFastCacheUpdateLock & v124) == 0) )
    {
      v43 = 0;
      goto LABEL_24;
    }
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v35 = 0;
    }
    else
    {
      __disable_irq();
      v35 = 1;
    }
    v36 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v35 )
      __enable_irq();
    if ( (v36 & 0x10001) != 0 )
    {
      v113 = KeGetCurrentIrql(&KiAbEnabled);
      KeBugCheck2(402, v34, (unsigned int)&ExpFastCacheUpdateLock, v113, 0, 0);
    }
    --*(_WORD *)(v34 + 310);
    if ( !*(_BYTE *)(v34 + 484) )
    {
      if ( !*(_BYTE *)(v34 + 810) )
      {
        v43 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v32 = EtwTraceAutoBoostEntryExhaustion(v34, (int)&ExpFastCacheUpdateLock);
LABEL_224:
        v107 = (unsigned __int8 *)(v34 + 81);
        do
          v108 = __ldrex(v107);
        while ( __strex(v108 | 0x80, v107) );
        goto LABEL_21;
      }
      v37 = *(_BYTE *)(v34 + 810);
      v38 = (unsigned __int8 *)(v34 + 810);
      __dmb(0xBu);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 & ~v37, v38) );
      __dmb(0xBu);
      v32 = &KiAbEnabled;
      *(_BYTE *)(v34 + 484) |= v37;
    }
    v40 = *(unsigned __int8 *)(v34 + 484);
    v41 = __clz(__rbit(v40));
    v138 = v41;
    *(_BYTE *)(v34 + 484) = v40 & ~(unsigned __int8)(1 << v41);
    v42 = v34 + 48 * v41;
    v43 = v42 + 488;
    if ( v42 == -488 )
      goto LABEL_224;
    if ( (unsigned int)&ExpFastCacheUpdateLock >= dword_63389C
      && ((v44 = *((unsigned __int8 *)&MiState[2423]
                 + ((int)((((unsigned int)&ExpFastCacheUpdateLock >> 20) & 0xFFC)
                        - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v44 == 1)
       || v44 == 11)
      && (v45 = *(_DWORD *)(v34 + 116), (v46 = *(_DWORD *)(v45 + 324)) != 0)
      && v45 != PsInitialSystemProcess )
    {
      v12 = *(_DWORD *)(v46 + 8);
    }
    else
    {
      v12 = -1;
    }
    *(_DWORD *)(v43 + 20) = v12;
    *(_DWORD *)(v43 + 16) = v33;
LABEL_21:
    v13 = *(_WORD *)(v34 + 310) + 1;
    *(_WORD *)(v34 + 310) = v13;
    if ( !v13 && *(_DWORD *)(v34 + 100) != v34 + 100 )
      KiCheckForKernelApcDelivery((int)v32);
    do
LABEL_24:
      v14 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
    while ( __strex(v14 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ExpFastCacheUpdateLock, v43, (unsigned int)&ExpFastCacheUpdateLock);
    if ( v43 )
      *(_BYTE *)(v43 + 14) |= 1u;
    if ( !v27[8] )
      sub_7B5F04((int)(v27 + 6), v27 + 8);
    __dmb(0xBu);
    do
      v15 = __ldrex(&ExpFastCacheUpdateLock);
    while ( __strex(v15 - 1, &ExpFastCacheUpdateLock) );
    if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
      ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
    result = &KiAbEnabled;
    if ( KiAbEnabled && ((unsigned int)&ExpFastCacheUpdateLock & v124) != 0 )
    {
      v16 = 0;
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (unsigned int)&ExpFastCacheUpdateLock >= dword_63389C
        && ((v18 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)((((unsigned int)&ExpFastCacheUpdateLock >> 20) & 0xFFC)
                          - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v18 == 1)
         || v18 == 11)
        && (v29 = *(_DWORD *)(v17 + 116), (v30 = *(_DWORD *)(v29 + 324)) != 0)
        && v29 != PsInitialSystemProcess )
      {
        v19 = *(_DWORD *)(v30 + 8);
      }
      else
      {
        v19 = -1;
      }
      if ( (unsigned int)KeGetCurrentIrql(&KiAbEnabled) <= 1 )
      {
        v16 = 1;
        --*(_WORD *)(v17 + 310);
      }
      result = (int *)KiAbThreadClearAcquiredLockEntry(v17, (int)&ExpFastCacheUpdateLock, v19);
      v20 = (int)result;
      if ( result )
      {
        *((_BYTE *)result + 16) |= 2u;
        if ( result[4] < 0 )
          result = (int *)KiAbEntryRemoveFromTree((int)result);
        v21 = *(_WORD *)(v20 + 44);
        if ( v21 )
        {
          if ( (v21 & 1) != 0 )
          {
            __dmb(0xBu);
            v109 = (unsigned int *)(v17 + 804);
            do
              v110 = __ldrex(v109);
            while ( __strex(v110 - 1, v109) );
            __dmb(0xBu);
            result = (int *)PsBoostThreadIoEx(v17, 1, 0);
          }
          if ( (*(_WORD *)(v20 + 44) & 0xFFFE) != 0 )
            result = (int *)KiAbThreadUnboostCpuPriority(v17, v20, 1, *(_WORD *)(v20 + 44) & 0xFFFE);
          if ( (dword_682604 & 0x200) != 0 )
            result = EtwTraceAutoBoostClearFloor(
                       v17,
                       *(_DWORD *)(v20 + 16) & 0xFFFFFFFC | 0x80000000,
                       *(_WORD *)(v20 + 44));
          *(_WORD *)(v20 + 44) = 0;
        }
        *(_BYTE *)(v20 + 13) &= 0xFEu;
        *(_DWORD *)(v20 + 16) = 0;
        v22 = (v20 - v17 - 488) / 48;
        if ( v16 )
        {
          *(_BYTE *)(v17 + 484) |= 1 << v22;
          goto LABEL_48;
        }
        __dmb(0xBu);
        result = (int *)(char)(1 << v22);
        v111 = (unsigned __int8 *)(v17 + 810);
        do
          v112 = __ldrex(v111);
        while ( __strex(v112 | (unsigned __int8)result, v111) );
        __dmb(0xBu);
      }
      else
      {
        if ( (*(_DWORD *)(v17 + 80) & 0x8000) == 0 )
          KeBugCheck2(354, v17, (unsigned int)&ExpFastCacheUpdateLock, v19, 0, 0);
        if ( v16 )
        {
LABEL_48:
          v23 = (__int16)(*(_WORD *)(v17 + 310) + 1);
          *(_WORD *)(v17 + 310) = v23;
          if ( !v23 && *(_DWORD *)(v17 + 100) != v17 + 100 )
            result = (int *)KiCheckForKernelApcDelivery((int)result);
        }
      }
      v24 = v121;
    }
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
    *(_WORD *)(v25 + 308) = v26;
    if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
      result = (int *)KiCheckForKernelApcDelivery((int)result);
    v121 = ++v24;
    v27 += 10;
  }
  while ( v24 < 5 );
  if ( !v125 && (v126 != v123 || v128 != v122) && (v129 != v123 || v127 != v122) )
  {
    sub_76601C(8507, v129);
    v114 = dword_920288;
    v115 = 5;
    do
    {
      v116 = *v114;
      v114[5] = 1;
      if ( v116 )
      {
        ObfDereferenceObject(v116);
        *v114 = 0;
      }
      v117 = v114[1];
      if ( v117 )
      {
        MmUnmapViewInSystemSpace(v117);
        v114[1] = 0;
      }
      v118 = v114[2];
      if ( v118 )
      {
        ExFreePoolWithTag(v118);
        v114[2] = 0;
      }
      v131 = 24;
      v132 = 0;
      v133 = v114 + 6;
      v134 = 576;
      v135 = 0;
      v136 = 0;
      v114[3] = 0;
      result = (int *)NtOpenKey();
      if ( (int)result >= 0 )
      {
        NtDeleteValueKey(v119, (unsigned int *)&dword_8C8224);
        result = (int *)NtClose();
      }
      v114 += 10;
      --v115;
    }
    while ( v115 );
  }
  if ( dword_92029C == 1 || dword_9202C4 == 1 || dword_9202EC == 1 || dword_920314 == 1 )
    result = (int *)ExpTriggerFastCacheReeval();
  __dmb(0xBu);
  do
    v28 = __ldrex(&ExpFastCacheFromRegistryPushed);
  while ( __strex(1u, &ExpFastCacheFromRegistryPushed) );
  __dmb(0xBu);
  return result;
}
