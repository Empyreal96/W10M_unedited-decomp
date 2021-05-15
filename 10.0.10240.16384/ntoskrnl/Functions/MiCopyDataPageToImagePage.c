// MiCopyDataPageToImagePage 
 
int __fastcall MiCopyDataPageToImagePage(int a1, unsigned int **a2, int *a3, int a4, int a5, int a6)
{
  unsigned int *v7; // r7
  unsigned int v8; // r0
  __int16 v10; // r5
  int v11; // r0
  unsigned int v12; // r1
  unsigned int *v13; // r8
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r4
  unsigned int v20; // r3
  unsigned int v21; // r9
  int v22; // lr
  int v23; // r2
  unsigned __int64 v24; // r0
  unsigned int v25; // lr
  unsigned int v26; // r1
  int *v27; // r2
  unsigned int v28; // r3
  int v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v32; // r2
  int v33; // r9
  unsigned int *v34; // r0
  unsigned int v35; // r2
  int v36; // r4
  unsigned __int8 *v37; // r3
  unsigned int v38; // r0
  int *v39; // r4
  int v40; // lr
  char v41; // r3
  unsigned int *v42; // r1
  unsigned int v43; // r0
  int v44; // r3
  _DWORD *v45; // lr
  unsigned int *v46; // r0
  unsigned int v47; // r1
  unsigned int v48; // r3
  int v49; // r4
  int v50; // r0
  unsigned int v51; // r4
  unsigned int v52; // lr
  unsigned int v53; // r2
  int v54; // r3
  int v55; // r0
  unsigned int v56; // r2
  unsigned int v57; // lr
  unsigned int v58; // r1
  int v59; // r3
  __int16 v60; // r3
  unsigned int *v61; // r1
  unsigned int v62; // r0
  int v63; // r3
  int v64; // r7
  int v65; // r4
  unsigned __int8 *v66; // r1
  unsigned int v67; // r2
  int v68; // r1
  int v69; // r2
  int v70; // r3
  int v71; // r1
  unsigned int *v72; // r0
  unsigned int *v73; // r2
  unsigned int v74; // r0
  unsigned int v75; // lr
  unsigned int v76; // r0
  unsigned int v77; // r2
  int v78; // r3
  int v79; // r4
  unsigned __int8 *v80; // r1
  unsigned int v81; // r2
  unsigned int *v82; // r2
  unsigned int v83; // r4
  unsigned int *v84; // r0
  unsigned int v85; // r1
  int v86; // r4
  unsigned int v87; // r1
  unsigned int v88; // r0
  int v89; // r0
  unsigned __int8 *v90; // r1
  int v91; // r3
  unsigned int v92; // r2
  int v93; // r0
  int v94; // r0
  int v95; // r3
  int *v96; // r6
  int v97; // r3
  unsigned int v98; // r2
  int v99; // r3
  unsigned int v100; // r2
  unsigned int *v101; // r2
  unsigned int v102; // r0
  unsigned int *v103; // r2
  unsigned int v104; // r4
  int v105; // [sp+0h] [bp-80h]
  int v106; // [sp+4h] [bp-7Ch]
  char v107[4]; // [sp+8h] [bp-78h] BYREF
  int v108; // [sp+Ch] [bp-74h]
  unsigned int v109; // [sp+10h] [bp-70h]
  unsigned int v110; // [sp+14h] [bp-6Ch]
  unsigned int v111; // [sp+18h] [bp-68h]
  unsigned int v112; // [sp+1Ch] [bp-64h]
  int v113; // [sp+20h] [bp-60h] BYREF
  int *v114; // [sp+24h] [bp-5Ch]
  unsigned int v115; // [sp+28h] [bp-58h]
  int v116; // [sp+2Ch] [bp-54h] BYREF
  int *i; // [sp+30h] [bp-50h]
  int v118; // [sp+34h] [bp-4Ch]
  unsigned int *v119; // [sp+38h] [bp-48h]
  unsigned int v120; // [sp+3Ch] [bp-44h]
  unsigned int v121; // [sp+40h] [bp-40h]
  unsigned int v122; // [sp+44h] [bp-3Ch]
  BOOL v123; // [sp+48h] [bp-38h]
  unsigned int v124; // [sp+4Ch] [bp-34h]
  int v125; // [sp+50h] [bp-30h]
  int v126; // [sp+54h] [bp-2Ch]
  int v127; // [sp+58h] [bp-28h]
  unsigned int v128; // [sp+5Ch] [bp-24h]

  v7 = *a2;
  v125 = a1;
  v8 = *(_DWORD *)(a1 + 128);
  v119 = v7;
  v120 = a4;
  v108 = 0;
  v109 = (unsigned int)a3;
  v112 = (unsigned int)a2;
  v105 = 0;
  v106 = 0;
  v116 = 0;
  v118 = 0;
  LOBYTE(v10) = 16;
  MiGetSessionIdForVa(v8);
  v11 = MiStartingOffset(a2, (unsigned int)a3);
  v121 = v12;
  v115 = v11;
  v13 = v7 + 9;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5456F8();
  v15 = (unsigned __int8 *)v7 + 39;
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 | 0x80, v15) );
  __dmb(0xBu);
  if ( v16 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v7 + 9);
  while ( 1 )
  {
    v17 = *v13;
    if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v17 & 0x40000000) == 0 )
    {
      do
        v87 = __ldrex(v13);
      while ( v87 == v17 && __strex(v17 | 0x40000000, v13) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v111 = v7[8] & 0xFFFFFFF8;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632E00);
  }
  else
  {
    do
      v18 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v18 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v18 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v19 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        do
          v88 = __ldrex((unsigned int *)&dword_632E00);
        while ( v88 == v19 && __strex(v19 | 0x40000000, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v20 = **(_DWORD **)(v111 + 20);
  v110 = v20;
  if ( !v20 || !ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)(v20 + 36)) )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      v21 = v110;
      goto LABEL_153;
    }
    __dmb(0xBu);
    dword_632E00 = 0;
    v21 = v110;
LABEL_16:
    v22 = 0;
    v23 = 0;
    goto LABEL_17;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
  }
  else
  {
    __dmb(0xBu);
    dword_632E00 = 0;
  }
  v21 = v110;
  LOBYTE(v10) = 24;
  if ( !*(_DWORD *)(v110 + 16) || (*(_DWORD *)(v110 + 28) & 3) != 0 )
    goto LABEL_16;
  v24 = MiEndingOffset(v112);
  v25 = HIDWORD(v24);
  v128 = HIDWORD(v24);
  v26 = (v121 << 20) | (v115 >> 12);
  v111 = v24;
  v124 = v26;
  v123 = v26 == ((unsigned int)(((v24 | 0xFFFFFFFF00000000ui64) + __PAIR64__(v25, -1)) >> 32 << 20) | ((unsigned int)(v24 - 1) >> 12));
  v27 = (int *)(v110 + 80);
  v28 = *(_DWORD *)(v110 + 108);
  for ( i = (int *)(v110 + 80); v26 >= v28; v28 = v27[7] )
  {
    v27 = (int *)v27[2];
    v26 -= v28;
    v124 = v26;
    i = v27;
    if ( !v27 )
      goto LABEL_153;
  }
  if ( !v27[16] || (v29 = v27[1]) == 0 )
  {
LABEL_153:
    v23 = 0;
    v22 = 0;
    goto LABEL_17;
  }
  v106 = 0;
  v113 = 0;
  v108 = 0;
  v30 = v29 + 4 * v26;
  v110 = 2;
  v112 = 0;
  v126 = 4194300;
  v122 = ((v30 >> 10) & 0x3FFFFC) - 0x40000000;
  v114 = (int *)v30;
  if ( v122 == ((v109 >> 10) & 0x3FFFFC) - 0x40000000 )
  {
    v22 = MiTryLockLeafPage((unsigned int *)v30, 0);
    v116 = v22;
    goto LABEL_42;
  }
  v31 = MiTryLockLeafAndContainingPagesAtDpc(v30, &v116, 0);
  v22 = v116;
  v118 = v31;
  if ( v31 )
  {
LABEL_42:
    v105 = v22;
    if ( v22 )
    {
      v10 = 26;
      if ( (*(_BYTE *)(v22 + 18) & 0x20) == 0
        && (*(_BYTE *)(v22 + 19) & 0x40) == 0
        && *(unsigned __int16 *)(v22 + 16) < 0x7FFFu )
      {
        v127 = *v114;
        if ( (v115 & 0xFFF) == 0 || v123 )
          goto LABEL_51;
        if ( v124 + 1 < i[7] )
        {
          v72 = (unsigned int *)(v114 + 1);
          if ( v122 == (v126 & ((unsigned int)(v114 + 1) >> 10)) - 0x40000000 )
          {
            v23 = MiTryLockLeafPage(v72, 1);
            v113 = v23;
          }
          else
          {
            v89 = MiTryLockLeafAndContainingPagesAtDpc((int)v72, &v113, 1);
            v23 = v113;
            v108 = v89;
            if ( !v89 )
            {
              v106 = v113;
              goto LABEL_17;
            }
          }
          v106 = v23;
          if ( !v23 )
            goto LABEL_17;
          v10 = 30;
          if ( (*(_BYTE *)(v23 + 18) & 0x20) != 0 || (*(_BYTE *)(v23 + 19) & 0x40) != 0 )
            goto LABEL_17;
          if ( *(unsigned __int16 *)(v22 + 16) >= 0x7FFFu )
            goto LABEL_179;
          v112 = v114[1];
          v110 = 3;
LABEL_51:
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v21 + 36);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)(v21 + 36) = 0;
          }
          ++v119[4];
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
          }
          else
          {
            __dmb(0xBu);
            *v13 = 0;
          }
          v10 = v10 & 0xFEE7 | 0x20;
          v122 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          if ( (v127 & 2) != 0 || *(_WORD *)(v22 + 16) )
          {
LABEL_59:
            if ( MiAddLockedPageCharge(v22, 0) )
            {
              v32 = v106;
              v10 = v10 & 0xFEFF | 1;
              if ( !v106 )
                goto LABEL_61;
              if ( (v112 & 2) == 0 && !*(_WORD *)(v106 + 16) )
              {
                v10 ^= ((unsigned __int8)v10 ^ (unsigned __int8)(16 * *(_BYTE *)(v106 + 19))) & 0x80;
                if ( !MiUnlinkPageFromList(v106, 0) )
                {
                  MiDiscardTransitionPte(v106);
                  v23 = v106;
                  goto LABEL_17;
                }
                v32 = v106;
                v10 |= 0x100u;
                *(_DWORD *)(v106 + 12) &= 0xC0000000;
              }
              if ( MiAddLockedPageCharge(v32, 0) )
              {
                __dmb(0xBu);
                v73 = (unsigned int *)(v106 + 12);
                do
                  v74 = __ldrex(v73);
                while ( __strex(v74 & 0x7FFFFFFF, v73) );
                if ( v108 )
                  MiUnlockNestedProtoPoolPage();
LABEL_61:
                v33 = v125;
                *(_BYTE *)(v125 + 113) |= 0x10u;
                __dmb(0xBu);
                v34 = (unsigned int *)(v22 + 12);
                i = (int *)(v22 + 12);
                do
                  v35 = __ldrex(v34);
                while ( __strex(v35 & 0x7FFFFFFF, v34) );
                if ( v118 )
                  MiUnlockProtoPoolPage(v118, 2);
                v36 = MmPfnDatabase + 24 * a5;
                v108 = v36;
                v37 = (unsigned __int8 *)(v36 + 15);
                do
                  v38 = __ldrex(v37);
                while ( __strex(v38 | 0x80, v37) );
                __dmb(0xBu);
                if ( v38 >> 7 )
                {
                  v90 = (unsigned __int8 *)(v36 + 15);
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v91 = *(_DWORD *)(v36 + 12);
                      __dmb(0xBu);
                    }
                    while ( (v91 & 0x80000000) != 0 );
                    do
                      v92 = __ldrex(v90);
                    while ( __strex(v92 | 0x80, v90) );
                    __dmb(0xBu);
                  }
                  while ( v92 >> 7 );
                }
                v39 = (int *)v109;
                MiInitializeTransitionPfn(a5, (int *)v109);
                v40 = v108;
                v41 = *(_BYTE *)(v108 + 18);
                *(_WORD *)(v108 + 16) = 1;
                *(_BYTE *)(v40 + 18) = v41 & 0xD8 | 0x22;
                *(_DWORD *)v40 = v33 + 16;
                if ( (v120 & 1) != 0 && *(_BYTE *)(v120 & 0xFFFFFFFE) == 1 )
                {
                  MiAdvanceFaultList((_DWORD *)(v120 & 0xFFFFFFFE));
                  v40 = v108;
                  *(_BYTE *)(v33 + 113) |= 4u;
                }
                *(_BYTE *)(v40 + 19) ^= (*(_BYTE *)(v33 + 114) & 7 ^ *(_BYTE *)(v40 + 19)) & 7;
                __dmb(0xBu);
                v42 = (unsigned int *)(v40 + 12);
                do
                  v43 = __ldrex(v42);
                while ( __strex(v43 & 0x7FFFFFFF, v42) );
                v44 = *v39;
                v45 = (_DWORD *)v122;
                *(_DWORD *)(v33 + 132) = v39;
                *(_DWORD *)(v33 + 96) = v44;
                if ( ((*(_DWORD *)(v45[84] + 192) & 0x100000) != 0 || ((v45[240] >> 9) & 7u) < 2)
                  && (v45 != (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !v45[250]) )
                {
                  *(_BYTE *)(v33 + 113) |= 0x40u;
                }
                *(_DWORD *)(v33 + 152) = 0;
                *(_WORD *)(v33 + 158) = 0;
                *(_DWORD *)(v33 + 168) = 0;
                *(_DWORD *)(v33 + 176) = 0;
                *(_DWORD *)(v33 + 172) = 4096;
                *(_DWORD *)(v33 + 180) = a5;
                *(_WORD *)(v33 + 156) = 32;
                MiObtainProtoReference(a6, 0);
                MiUnlockProtoPoolPage(a6, 2);
                v46 = v119;
                v47 = v110;
                v48 = v115;
                *(_WORD *)(v33 + 158) |= 0x42u;
                *(_DWORD *)(v33 + 136) = v39;
                *(_DWORD *)(v33 + 56) = v48;
                v49 = v108;
                *(_DWORD *)(v33 + 60) = v121;
                *(_DWORD *)(v33 + 116) = 0;
                *(_DWORD *)(v33 + 120) = v46;
                *(_DWORD *)(v33 + 140) = v49;
                *(_DWORD *)(v33 + 92) = a6;
                v50 = MiReservePtes(&dword_634D58, v47);
                v51 = v50;
                v108 = v50;
                if ( !v50 )
                {
                  v63 = -1073741670;
LABEL_94:
                  v64 = 0;
                  *(_DWORD *)(v33 + 48) = v63;
                  if ( (v10 & 0xC0) != 0 )
                    v64 = MiCreateDecayPfn(4);
                  v65 = KfRaiseIrql(2);
                  v66 = (unsigned __int8 *)(v105 + 15);
                  do
                    v67 = __ldrex(v66);
                  while ( __strex(v67 | 0x80, v66) );
                  __dmb(0xBu);
                  if ( v67 >> 7 )
                  {
                    v96 = i;
                    do
                    {
                      do
                      {
                        __dmb(0xAu);
                        __yield();
                        v97 = *v96;
                        __dmb(0xBu);
                      }
                      while ( (v97 & 0x80000000) != 0 );
                      do
                        v98 = __ldrex(v66);
                      while ( __strex(v98 | 0x80, v66) );
                      __dmb(0xBu);
                    }
                    while ( v98 >> 7 );
                  }
                  v107[0] = v65;
                  if ( MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(v105) )
                  {
                    if ( v64 && (v10 & 0x40) != 0 && (*(_DWORD *)(v105 + 12) & 0x40000000) == 0 )
                    {
                      MiInsertAndUnlockStandbyPages(v64, &v116, 1u, v65);
                      v65 = 17;
                      v107[0] = 17;
                    }
                    else
                    {
                      MiPfnReferenceCountIsZero(v105, (v105 - MmPfnDatabase) / 24);
                    }
                  }
                  if ( v65 != 17 )
                  {
                    __dmb(0xBu);
                    v84 = (unsigned int *)i;
                    do
                      v85 = __ldrex(v84);
                    while ( __strex(v85 & 0x7FFFFFFF, v84) );
                    KfLowerIrql(v65);
                  }
                  v70 = v106;
                  if ( v106 )
                  {
                    v79 = KfRaiseIrql(2);
                    v111 = v79;
                    v80 = (unsigned __int8 *)(v106 + 15);
                    do
                      v81 = __ldrex(v80);
                    while ( __strex(v81 | 0x80, v80) );
                    __dmb(0xBu);
                    if ( v81 >> 7 )
                    {
                      do
                      {
                        do
                        {
                          __dmb(0xAu);
                          __yield();
                          v99 = *(_DWORD *)(v106 + 12);
                          __dmb(0xBu);
                        }
                        while ( (v99 & 0x80000000) != 0 );
                        do
                          v100 = __ldrex(v80);
                        while ( __strex(v100 | 0x80, v80) );
                        __dmb(0xBu);
                      }
                      while ( v100 >> 7 );
                    }
                    v107[0] = v79;
                    if ( MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(v106) )
                    {
                      if ( v64 && (v10 & 0x80) != 0 && (*(_DWORD *)(v106 + 12) & 0x40000000) == 0 )
                      {
                        MiInsertAndUnlockStandbyPages(v64, &v113, 1u, v79);
                        v79 = 17;
                        v111 = 17;
                        v107[0] = 17;
                      }
                      else
                      {
                        MiPfnReferenceCountIsZero(v106, (v106 - MmPfnDatabase) / 24);
                      }
                    }
                    if ( v79 != 17 )
                    {
                      __dmb(0xBu);
                      v82 = (unsigned int *)(v106 + 12);
                      do
                        v83 = __ldrex(v82);
                      while ( __strex(v83 & 0x7FFFFFFF, v82) );
                      KfLowerIrql(v111);
                    }
                  }
                  if ( v64 )
                    MiDecayPfnFullyInitialized(v64, v68, v69, v70);
                  MiRelockProtoPoolPage(a6, v107);
                  v71 = (unsigned __int8)v107[0];
                  *(_BYTE *)(v33 + 113) &= 0xEFu;
                  MiUnlockProtoPoolPage(a6, v71);
                  *(_DWORD *)(v33 + 52) = 4096;
                  KeSetEvent(v33 + 16, 0, 0);
                  return 1;
                }
                v114 = (int *)((v115 & 0xFFF) + (v50 << 10));
                v52 = (dword_681120 & 0x1EC | (a5 << 12) | MiDetermineUserGlobalPteMask(v50)) & 0xFFFFF1FF | 0x13;
                v112 = 0x3FFFFF;
                if ( v51 + 0x40000000 > 0x3FFFFF )
                {
                  *(_DWORD *)v51 = v52;
                }
                else
                {
                  v53 = 0;
                  v54 = *(_DWORD *)v51;
                  v109 = 0;
                  __dmb(0xBu);
                  *(_DWORD *)v51 = v52;
                  if ( (v54 & 2) == 0 )
                  {
                    v53 = 1;
                    v109 = 1;
                  }
                  if ( v51 >= 0xC0300000 && v51 <= 0xC0300FFF )
                  {
                    v93 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v93, (_DWORD *)(v93 + 4 * (v51 & 0xFFF)), v52);
                    v53 = v109;
                  }
                  if ( v53 == 1 )
                  {
                    __dsb(0xFu);
                    __isb(0xFu);
                  }
                }
                v55 = MiDetermineUserGlobalPteMask(v51 + 4);
                v56 = v51 + 4;
                v57 = (v55 | dword_681114 & 0x3EC | (((v105 - MmPfnDatabase) / 24) << 12)) & 0xFFFFF3FF | 0x13;
                if ( v51 + 1073741828 > v112 )
                {
                  *(_DWORD *)v56 = v57;
                }
                else
                {
                  v58 = 0;
                  v59 = *(_DWORD *)v56;
                  v109 = 0;
                  __dmb(0xBu);
                  *(_DWORD *)v56 = v57;
                  if ( (v59 & 2) == 0 )
                  {
                    v58 = 1;
                    v109 = 1;
                  }
                  if ( v56 >= 0xC0300000 && v56 <= 0xC0300FFF )
                  {
                    v94 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v94, (_DWORD *)(v94 + 4 * (v56 & 0xFFF)), v57);
                    v58 = v109;
                  }
                  if ( v58 == 1 )
                  {
                    __dsb(0xFu);
                    __isb(0xFu);
                  }
                }
                if ( v106 )
                {
                  v75 = v51 + 8;
                  v76 = (MiDetermineUserGlobalPteMask(v51 + 8) | dword_681114 & 0x3ED | (((v106 - MmPfnDatabase) / 24) << 12)) & 0xFFFFF3FF | 0x12;
                  v120 = v76;
                  if ( v51 + 1073741832 > v112 )
                  {
                    *(_DWORD *)v75 = v76;
                  }
                  else
                  {
                    v77 = 0;
                    v78 = *(_DWORD *)v75;
                    v109 = 0;
                    __dmb(0xBu);
                    *(_DWORD *)v75 = v76;
                    if ( (v78 & 2) == 0 )
                    {
                      v77 = 1;
                      v109 = 1;
                    }
                    if ( v75 >= 0xC0300000 && v75 <= 0xC0300FFF )
                    {
                      v95 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
                      MiArmWriteConvertedHardwarePde(
                        *(_DWORD *)(v95 + 32),
                        (_DWORD *)(*(_DWORD *)(v95 + 32) + 4 * (v75 & 0xFFF)),
                        v120);
                      v77 = v109;
                    }
                    if ( v77 == 1 )
                    {
                      __dsb(0xFu);
                      __isb(0xFu);
                    }
                  }
                }
                if ( (__PAIR64__(v121, v115) + 4096) >> 32 > v128 )
                {
                  v60 = v111;
                }
                else if ( (__PAIR64__(v121, v115) + 4096) >> 32 < v128 || (v60 = v111, v115 + 4096 <= v111) )
                {
                  memmove(v51 << 10, (int)(v114 + 1024), 0x1000u);
                  goto LABEL_91;
                }
                v86 = (v60 - (_WORD)v115) & 0xFFF;
                memmove(v108 << 10, (int)(v114 + 1024), v86);
                memset((_BYTE *)(v86 + (v108 << 10)), 0, 4096 - v86);
                v51 = v108;
LABEL_91:
                KeSweepIcacheRange(1, v51 << 10, 0x1000u);
                MiReleasePtes(&dword_634D58, v51, v110);
                v61 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2960);
                do
                  v62 = __ldrex(v61);
                while ( __strex(v62 + 1, v61) );
                v63 = 0;
                goto LABEL_94;
              }
              if ( (v10 & 0x100) != 0 )
              {
                MiPfnReferenceCountIsZero(v106, (v106 - MmPfnDatabase) / 24);
                v23 = v106;
                goto LABEL_17;
              }
            }
            else if ( (v10 & 0x100) != 0 )
            {
              MiPfnReferenceCountIsZero(v22, (v22 - MmPfnDatabase) / 24);
              v23 = v106;
              goto LABEL_17;
            }
            goto LABEL_179;
          }
          v10 ^= (v10 ^ (8 * *(unsigned __int8 *)(v22 + 19))) & 0x40;
          if ( MiUnlinkPageFromList(v22, 0) )
          {
            v10 |= 0x100u;
            *(_DWORD *)(v22 + 12) &= 0xC0000000;
            goto LABEL_59;
          }
          MiDiscardTransitionPte(v22);
LABEL_179:
          v23 = v106;
          goto LABEL_17;
        }
      }
    }
    v23 = 0;
    goto LABEL_17;
  }
  v23 = 0;
  v105 = v116;
LABEL_17:
  if ( (v10 & 8) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v21 + 36);
      v22 = v105;
      v23 = v106;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v21 + 36) = 0;
    }
  }
  if ( (v10 & 0x10) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
      v22 = v105;
      v23 = v106;
    }
    else
    {
      __dmb(0xBu);
      *v13 = 0;
    }
  }
  if ( (v10 & 4) != 0 )
  {
    __dmb(0xBu);
    v101 = (unsigned int *)(v23 + 12);
    do
      v102 = __ldrex(v101);
    while ( __strex(v102 & 0x7FFFFFFF, v101) );
  }
  if ( v108 )
  {
    MiUnlockNestedProtoPoolPage();
    v22 = v105;
  }
  if ( (v10 & 1) != 0 )
  {
    MiRemoveLockedPageChargeAndDecRef(v22);
    v22 = v105;
  }
  if ( (v10 & 2) != 0 )
  {
    __dmb(0xBu);
    v103 = (unsigned int *)(v22 + 12);
    do
      v104 = __ldrex(v103);
    while ( __strex(v104 & 0x7FFFFFFF, v103) );
  }
  if ( v118 )
    MiUnlockProtoPoolPage(v118, 2);
  if ( (v10 & 0x20) != 0 )
    MiDereferenceControlAreaPfn(v119, 0, 3);
  return 0;
}
