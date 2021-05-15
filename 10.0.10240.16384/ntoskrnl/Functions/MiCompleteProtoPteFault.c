// MiCompleteProtoPteFault 
 
int __fastcall MiCompleteProtoPteFault(int a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, int a7)
{
  int v7; // r9
  unsigned int v8; // r6
  int v9; // r8
  unsigned int v10; // r7
  int v11; // r5
  unsigned __int8 *v12; // r4
  unsigned int v13; // r0
  unsigned int *v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  unsigned int v18; // r6
  int v19; // r5
  unsigned int v20; // r2
  unsigned int v21; // r10
  unsigned int v22; // r1
  int v23; // r4
  unsigned int v24; // r9
  unsigned int v25; // r3
  unsigned int v26; // r10
  int v27; // r9
  int v28; // r4
  unsigned int v29; // r0
  int v30; // r7
  int v31; // r8
  int v32; // r0
  char v33; // r7
  _DWORD *v34; // r8
  unsigned int v35; // r2
  unsigned int v37; // r8
  int v38; // r4
  unsigned int *v39; // r5
  int v40; // r1
  unsigned int v41; // r0
  int v42; // r10
  unsigned int v43; // r4
  unsigned int v44; // r2
  unsigned __int64 v45; // r0
  unsigned int v46; // r6
  int v47; // r10
  unsigned int *v48; // r5
  unsigned int v49; // r1
  unsigned int v50; // r0
  int *v51; // r4
  int v52; // r3
  unsigned int *v53; // r0
  unsigned int v54; // r4
  unsigned int v55; // r2
  unsigned int v56; // r1
  _DWORD *v57; // r6
  unsigned int v58; // r4
  unsigned int v59; // r5
  bool v60; // zf
  int v61; // r3
  unsigned int v62; // r8
  int v63; // r9
  unsigned __int8 *v64; // r1
  unsigned int v65; // r2
  int v66; // r3
  int v67; // r2
  unsigned int *v68; // r2
  unsigned int v69; // r4
  int v70; // r0
  unsigned int v71; // r3
  _DWORD *v72; // r8
  unsigned int v73; // r1
  unsigned int v74; // r0
  int v75; // r3
  int v76; // r2
  unsigned int v77; // r4
  int v78; // r0
  int v79; // r3
  unsigned int v80; // r1
  unsigned int v81; // r0
  unsigned int *v82; // r2
  unsigned int v83; // r1
  int v84; // r0
  unsigned int *v85; // r6
  int v86; // r8
  unsigned int v87; // r4
  unsigned int v88; // r1
  unsigned int v89; // r1
  unsigned int v90; // r2
  int v91; // r0
  int v92; // r2
  __int64 v93; // kr08_8
  int v94; // r2
  int v95; // r3
  int v96; // r0
  int v97; // r1
  unsigned int *v98; // r6
  unsigned int v99; // r1
  int v100; // r8
  int v101; // r9
  unsigned int v102; // r1
  unsigned int *v103; // lr
  unsigned int v104; // r0
  unsigned int v105; // r1
  int v106; // r3
  unsigned int v107; // r2
  int v108; // r0
  unsigned int v109; // r1
  unsigned int v110; // r0
  unsigned int *v111; // r0
  unsigned int v112; // r1
  unsigned __int8 *v113; // r3
  unsigned int v114; // r1
  int v115; // r0
  int v116; // r3
  unsigned int v117; // r2
  int v118; // r5
  int v119; // r0
  int v121; // [sp+14h] [bp-54h]
  _DWORD *v122; // [sp+18h] [bp-50h]
  char v123; // [sp+1Ch] [bp-4Ch]
  int v124; // [sp+20h] [bp-48h] BYREF
  int v125; // [sp+24h] [bp-44h]
  int v126; // [sp+28h] [bp-40h] BYREF
  unsigned __int64 v127; // [sp+2Ch] [bp-3Ch]
  int v128; // [sp+34h] [bp-34h] BYREF
  unsigned int v129; // [sp+38h] [bp-30h]
  int v130; // [sp+3Ch] [bp-2Ch]
  BOOL v131; // [sp+40h] [bp-28h]
  int v132; // [sp+44h] [bp-24h]
  int varg_r0; // [sp+70h] [bp+8h]
  int varg_r1; // [sp+74h] [bp+Ch]
  unsigned int varg_r2; // [sp+78h] [bp+10h]
  unsigned int varg_r3; // [sp+7Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v132 = a2;
  v7 = 4194300;
  v123 = 0;
  varg_r3 = a4;
  v8 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v129 = a4 >> 12;
  v130 = a1;
  v125 = 4194300;
  v9 = MmPfnDatabase + 24 * (a4 >> 12);
  v126 = 0x80000000;
  v10 = *(_DWORD *)(v9 + 8);
  v121 = v9;
  v122 = (_DWORD *)v8;
  if ( !PfSnNumActiveTraces || (v10 & 0x400) == 0 )
    goto LABEL_2;
  v37 = *(_DWORD *)(v9 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v9 + 8) & 0x3FC));
  v38 = *(_DWORD *)v37;
  v124 = v37;
  v39 = (unsigned int *)(v38 + 32);
  __pld((void *)(v38 + 32));
  v40 = *(_DWORD *)(v38 + 32);
  if ( (v40 & 7) == 0 )
    goto LABEL_40;
  do
    v41 = __ldrex(v39);
  while ( v41 == v40 && __strex(v40 - 1, v39) );
  __dmb(0xBu);
  if ( v41 == v40 )
  {
LABEL_40:
    v42 = v40 & 0xFFFFFFF8;
    v128 = v40 & 0xFFFFFFF8;
    if ( (v40 & 7u) <= 1 )
    {
      if ( (v40 & 7) == 0 )
      {
LABEL_140:
        v85 = (unsigned int *)(v38 + 36);
        v86 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v38 + 36);
        }
        else
        {
          v87 = *v85 & ~v126;
          do
            v88 = __ldrex(v85);
          while ( v88 == v87 && __strex(v87 + 1, v85) );
          __dmb(0xBu);
          if ( v88 != v87 )
            ExpWaitForSpinLockSharedAndAcquire(v85);
        }
        v128 = ObFastReferenceObjectLocked(v39);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v85);
        }
        else
        {
          __dmb(0xBu);
          do
            v89 = __ldrex(v85);
          while ( __strex(v89 & 0xBFFFFFFF, v85) );
          __dmb(0xBu);
          do
            v90 = __ldrex(v85);
          while ( __strex(v90 - 1, v85) );
        }
        KfLowerIrql(v86);
        v37 = v124;
LABEL_42:
        v43 = *(_DWORD *)(v121 + 4) | v126;
        if ( a3 < dword_63389C
          || (v79 = *((unsigned __int8 *)&MiState[2423]
                    + ((int)(((a3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
              v79 == 11)
          || v79 == 1 )
        {
          __mrc(15, 0, 13, 0, 3);
        }
        if ( (*(_DWORD *)(*(_DWORD *)v37 + 28) & 0x20) != 0 )
        {
          v44 = *(_DWORD *)(v37 + 4);
          if ( v43 < v44 || v43 >= v44 + 4 * *(_DWORD *)(v37 + 28) )
          {
            if ( (*(_WORD *)(v37 + 18) & 2) != 0 )
              v108 = MiGetSharedProtos();
            else
              v108 = *(_DWORD *)(v37 + 12);
            v127 = __PAIR64__(*(_DWORD *)(v37 + 20) >> 23, *(_DWORD *)(v37 + 20) << 9)
                 + ((__int64)((int)(v43 - *(_DWORD *)(v108 + 16)) >> 2) << 12);
LABEL_49:
            v131 = (*(_DWORD *)(*(_DWORD *)v37 + 28) & 0x20) != 0;
            v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v47 = *(_DWORD *)(v46 + 0x74);
            v48 = (unsigned int *)(v47 + 420);
            __pld((void *)(v47 + 420));
            v49 = *(_DWORD *)(v47 + 420);
            if ( (v49 & 7) != 0 )
            {
              do
              {
                do
                  v50 = __ldrex(v48);
                while ( v50 == v49 && __strex(v49 - 1, v48) );
                __dmb(0xBu);
                if ( v50 == v49 )
                  break;
                v49 = v50;
              }
              while ( (v50 & 7) != 0 );
            }
            v51 = (int *)(v49 & 0xFFFFFFF8);
            if ( (v49 & 0xFFFFFFF8) == 0 )
              goto LABEL_67;
            if ( (v49 & 7) <= 1 )
            {
              if ( (v49 & 7) != 0 )
              {
                v72 = v51 + 67;
                if ( ExAcquireRundownProtectionEx(v51 + 67, 7) )
                {
                  __pld(v48);
                  v73 = *v48;
                  if ( (*v48 & 7) == 0 )
                  {
                    while ( v51 == (int *)(v73 & 0xFFFFFFF8) )
                    {
                      do
                        v74 = __ldrex(v48);
                      while ( v74 == v73 && __strex(v73 + 7, v48) );
                      __dmb(0xBu);
                      if ( v74 == v73 )
                        goto LABEL_117;
                      v73 = v74;
                      if ( (v74 & 7) != 0 )
                        break;
                    }
                  }
                  __pld(v72);
                  v109 = *v72;
                  if ( (*v72 & 1) != 0 )
                  {
LABEL_214:
                    v111 = (unsigned int *)(v109 & 0xFFFFFFFE);
                    __dmb(0xBu);
                    do
                      v112 = __ldrex(v111);
                    while ( __strex(v112 - 7, v111) );
                    __dmb(0xBu);
                    if ( v112 == 7 )
                    {
                      __dmb(0xBu);
                      v113 = (unsigned __int8 *)(v111 + 5);
                      do
                        v114 = __ldrex(v113);
                      while ( __strex(v114 & 0xFE, v113) );
                      __dmb(0xBu);
                      if ( (v114 & 1) == 0 )
                        KeSetEvent((int)(v111 + 1), 0, 0);
                    }
                  }
                  else
                  {
                    while ( 1 )
                    {
                      __dmb(0xBu);
                      do
                        v110 = __ldrex(v72);
                      while ( v110 == v109 && __strex(v109 - 14, v72) );
                      __dmb(0xBu);
                      if ( v110 == v109 )
                        break;
                      v109 = v110;
                      if ( (v110 & 1) != 0 )
                        goto LABEL_214;
                    }
                  }
                  v37 = v124;
                }
                else
                {
LABEL_117:
                  v37 = v124;
                }
              }
              else
              {
                v100 = 1;
                v101 = KfRaiseIrql(2);
                if ( (dword_682604 & 0x210000) != 0 )
                {
                  KiAcquireSpinLockInstrumented(&dword_637378);
                }
                else
                {
                  do
                    v102 = __ldrex((unsigned int *)&dword_637378);
                  while ( __strex(1u, (unsigned int *)&dword_637378) );
                  __dmb(0xBu);
                  if ( v102 )
                    KxWaitForSpinLockAndAcquire(&dword_637378);
                }
                v51 = (int *)(*(_DWORD *)(v47 + 420) & 0xFFFFFFF8);
                if ( v51 )
                {
                  __pld(v51 + 67);
                  v103 = (unsigned int *)(v51 + 67);
                  v104 = v51[67] & 0xFFFFFFFE;
                  do
                    v105 = __ldrex(v103);
                  while ( v105 == v104 && __strex(v104 + 2, v103) );
                  __dmb(0xBu);
                  if ( v105 == v104 )
                    v100 = 1;
                  else
                    v100 = ExfAcquireRundownProtection(v51 + 67);
                }
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  KiReleaseSpinLockInstrumented(&dword_637378);
                }
                else
                {
                  __dmb(0xBu);
                  dword_637378 = 0;
                }
                KfLowerIrql(v101);
                v60 = v100 == 0;
                v37 = v124;
                if ( v60 )
                  goto LABEL_66;
              }
            }
            if ( v51 )
            {
              if ( (*(_BYTE *)(v46 + 968) & 0x40) == 0 )
              {
                if ( (*(_DWORD *)(*(_DWORD *)(v46 + 336) + 192) & 0x100000) == 0
                  && ((*(_DWORD *)(v46 + 960) >> 9) & 7u) >= 2
                  || v46 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(v46 + 1000) )
                {
                  v52 = v51[77];
                  if ( !v52 || v52 == v46 && v51[78] == *(_DWORD *)(v46 + 880) )
                    PfSnLogPageFaultCommon(v51, v128, *(_DWORD *)(v128 + 12));
                }
                else
                {
                  v82 = (unsigned int *)(v51 + 63);
                  do
                    v83 = __ldrex(v82);
                  while ( __strex(v83 + 1, v82) );
                }
              }
              v53 = (unsigned int *)(v51 + 67);
              __pld(v51 + 67);
              v54 = v51[67] & 0xFFFFFFFE;
              __dmb(0xBu);
              v55 = v54 - 2;
              do
                v56 = __ldrex(v53);
              while ( v56 == v54 && __strex(v55, v53) );
              if ( v56 != v54 )
                ExfReleaseRundownProtection(v53, v56, v55);
            }
LABEL_66:
            v7 = v125;
LABEL_67:
            v57 = (_DWORD *)(*(_DWORD *)v37 + 32);
            __pld(v57);
            v58 = *v57;
            if ( (*v57 ^ (unsigned int)v128) >= 7 )
            {
LABEL_184:
              ObDereferenceObjectDeferDeleteWithTag(v128);
            }
            else
            {
              while ( 1 )
              {
                __dmb(0xBu);
                do
                  v59 = __ldrex(v57);
                while ( v59 == v58 && __strex(v58 + 1, v57) );
                if ( v59 == v58 )
                  break;
                v58 = v59;
                if ( (v59 ^ v128) >= 7 )
                  goto LABEL_184;
              }
            }
            v9 = v121;
            v8 = (unsigned int)v122;
LABEL_2:
            v11 = MmPfnDatabase + 24 * (*(_DWORD *)((v7 & (v8 >> 10)) - 0x40000000) >> 12);
            v131 = v11;
            v12 = (unsigned __int8 *)(v11 + 15);
            do
              v13 = __ldrex(v12);
            while ( __strex(v13 | 0x80, v12) );
            __dmb(0xBu);
            if ( v13 >> 7 )
            {
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v106 = *(_DWORD *)(v11 + 12);
                  __dmb(0xBu);
                }
                while ( (v106 & v126) != 0 );
                do
                  v107 = __ldrex(v12);
                while ( __strex(v107 | 0x80, v12) );
                __dmb(0xBu);
              }
              while ( v107 >> 7 );
            }
            *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | ((*(_DWORD *)(v11 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
            __dmb(0xBu);
            v14 = (unsigned int *)(v11 + 12);
            do
              v15 = __ldrex(v14);
            while ( __strex(v15 & 0x7FFFFFFF, v14) );
            v16 = *(_DWORD *)v8;
            if ( (*(_DWORD *)v8 & 0xFFFFE000) == -8192 )
            {
              v19 = a5;
              v18 = (v16 >> 1) & 0x1F0;
            }
            else
            {
              if ( (v10 & 0x400) != 0 )
                v17 = (*(unsigned __int16 *)((v10 & 0xFFFFF800 | (2 * (v10 & 0x3FC))) + 0x10) >> 1) & 0x1F;
              else
                v17 = (v10 >> 5) & 0x1F;
              v18 = 16 * (v17 & 0x1F);
              v123 = 1;
              if ( (v16 & 0x200) != 0 )
              {
                v18 = v18 & 0xFFFFFE0F | 0x10;
                v123 = 3;
              }
              v19 = a5;
              if ( a5 && (v18 & 0x40) == 0 )
                v19 = 0;
            }
            v20 = a3;
            v21 = BYTE2(MiFlags) & 3;
            v22 = dword_63389C;
            v124 = dword_63389C;
            if ( (MiFlags & 0x30000) != 0 && a3 >= dword_63389C && ((v18 >> 4) & 2) != 0 )
            {
              v115 = MiIsStrongCodeImagePage(v9, &v128, a3);
              v22 = v124;
              v20 = a3;
              if ( v115 )
              {
                v18 = v18 & 0xFFFFFE0F | 0x30;
                v19 = 0;
              }
              else if ( ((v18 >> 4) & 0x1F) == 2 )
              {
                v18 = v18 & 0xFFFFFE0F | 0x10;
              }
              else
              {
                v18 &= 0xFFFFFFDF;
              }
            }
            v23 = (v18 >> 4) & 7;
            v24 = *(unsigned __int8 *)(v121 + 18);
            v25 = v24 >> 6;
            if ( v24 >> 6 != 1 )
            {
              if ( v25 )
              {
                if ( v25 == 2 )
                  v23 |= 0x18u;
              }
              else
              {
                v23 |= 8u;
              }
            }
            if ( v20 >= v22 )
            {
              if ( (*(_BYTE *)(v130 + 112) & 7u) < 2 )
              {
                v84 = MiDetermineUserGlobalPteMask(v122);
                v71 = MmProtectToPteMask[v23] & 0xFED | (v129 << 12) | v84;
              }
              else
              {
                if ( v21 >= 3 && (*(_BYTE *)(v121 + 23) & 7) != 3 )
                  v23 &= 0xFFFFFFFD;
                v70 = MiDetermineUserGlobalPteMask(v122);
                v71 = (MmProtectToPteMask[v23] & 0x3ED | (v129 << 12) | v70) & 0xFFFFF3FF;
              }
              v22 = v124;
              v26 = v71 | 0x12;
            }
            else
            {
              v26 = (MmProtectToPteMask[v23] | (v129 << 12)) & 0xFFFFFBFF | 0x832;
            }
            if ( v19 && ((v18 >> 4) & 5) != 5 )
            {
              v60 = (v24 & 0x10) == 0;
              v27 = v121;
              v26 &= 0xFFFFFDFF;
              if ( !v60 || (v61 = *(_DWORD *)(v121 + 8), (v61 & 0x400) != 0) || (v61 & 0x10) == 0 )
              {
LABEL_19:
                v126 = 0;
                v124 = 0;
                v28 = 0;
                if ( a6 )
                  goto LABEL_26;
                if ( (v10 & 0x400) != 0 )
                {
                  v124 = *(_DWORD *)(v10 & 0xFFFFF800 | (2 * (v10 & 0x3FC)));
                  if ( (*(_DWORD *)(v124 + 28) & 0x20) == 0 )
                    goto LABEL_26;
                  v29 = a3;
                  if ( a3 < v22 )
                  {
                    v30 = 0;
                    v31 = 0;
                    if ( !MEMORY[0xC0402148] )
                    {
LABEL_24:
                      v32 = 0;
                      goto LABEL_25;
                    }
                    v91 = MiLocateAddress(a3);
                    if ( v91 )
                    {
                      v92 = *(_DWORD *)(v91 + 28);
                      if ( (v92 & 7) != 2 || (v92 & 0x20000) == 0 )
                        goto LABEL_24;
                      v93 = *(_QWORD *)(v91 + 44);
                      v94 = (a3 >> 12) + ((HIDWORD(v93) - *(_DWORD *)(*(_DWORD *)v93 + 84)) >> 2);
                      v95 = *(_DWORD *)(v91 + 12);
                      if ( ((*(char *)(((unsigned int)(v94 - v95) >> 3) + *(_DWORD *)(v91 + 84)) >> ((v94 - v95) & 7)) & 1) != 0 )
                      {
                        v32 = *(_DWORD *)(v91 + 76);
                        v30 = v94 - v95;
                        v31 = *(_DWORD *)v93;
                      }
                      else
                      {
                        v32 = 0;
                      }
                    }
                    else
                    {
                      v32 = 0;
                    }
LABEL_25:
                    if ( v32 )
                    {
                      v28 = MiPrivateFixup(v31, v30, v27, a3, v32, v130, v132);
                      MiLockAndDecrementShareCount(v27, 0);
                      if ( v28 == 297 || v28 == -1073741670 )
                      {
                        MiLockAndDecrementShareCount(v131, 0);
                        if ( v28 == 297 )
                          v28 = -1073740748;
                        return v28;
                      }
                      if ( v28 < 0 )
                        return v28;
                      v34 = v122;
                      v96 = MiDetermineUserGlobalPteMask(v122);
                      v97 = *v122;
                      v26 = (MmProtectToPteMask[(*v34 >> 5) & 0x1F] ^ *v34) & 0xFED ^ *v34 | v96 | 0x12;
                      v27 = MmPfnDatabase + 24 * (v26 >> 12);
                      if ( a3 >= dword_63389C && (*(_BYTE *)(v27 + 19) & 8) != 0 )
                      {
                        if ( (unsigned int)(v122 + 0x10000000) > 0x3FFFFF )
                        {
                          *v122 = v26;
                        }
                        else
                        {
                          v118 = 0;
                          __dmb(0xBu);
                          *v122 = v26;
                          if ( (v97 & 2) == 0 )
                            v118 = 1;
                          if ( (unsigned int)(v122 + 267649024) <= 0xFFF )
                          {
                            v119 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                            MiArmWriteConvertedHardwarePde(v119, v119 + 4 * ((unsigned __int16)v122 & 0xFFF), v26);
                          }
                          if ( v118 == 1 )
                          {
                            __dsb(0xFu);
                            __isb(0xFu);
                          }
                        }
                        return v28;
                      }
                      v18 = 0;
                      v33 = v123 & 0xFE | 4;
LABEL_27:
                      if ( (v33 & 1) != 0 )
                        v18 = 0;
                      if ( (a7 & 1) == 0 || (v35 = a7 & 0xFFFFFFFE, *(_BYTE *)(a7 & 0xFFFFFFFE) != 5) )
                        v35 = 0;
                      if ( MiAllocateWsle(v130, v34, v27, v18, v26, v35) )
                      {
                        if ( !v19
                          || (v26 & 0x80) != 0
                          || (v26 & 0x100) == 0
                          || *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 264)
                          || MiCopyOnWriteEx(a3, v34, -1, v132, 0) )
                        {
                          return v28;
                        }
                      }
                      else
                      {
                        MiLockAndDecrementShareCount(v27, 0);
                        if ( (v33 & 4) == 0 )
                          MiLockAndDecrementShareCount(v131, 0);
                      }
                      return -1073741801;
                    }
LABEL_26:
                    v34 = v122;
                    v33 = v123;
                    goto LABEL_27;
                  }
                }
                else
                {
                  if ( a3 < v22 )
                    goto LABEL_26;
                  v29 = a3;
                }
                v32 = MiSystemImageHasPrivateFixups(v29, &v124, (unsigned int *)&v126);
                v31 = v124;
                v30 = v126;
                goto LABEL_25;
              }
              v62 = 0;
              v63 = KfRaiseIrql(2);
              v64 = (unsigned __int8 *)(v121 + 15);
              do
                v65 = __ldrex(v64);
              while ( __strex(v65 | 0x80, v64) );
              __dmb(0xBu);
              if ( v65 >> 7 )
              {
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                    v116 = *(_DWORD *)(v121 + 12);
                    __dmb(0xBu);
                  }
                  while ( (v116 & v126) != 0 );
                  do
                    v117 = __ldrex(v64);
                  while ( __strex(v117 | 0x80, v64) );
                  __dmb(0xBu);
                }
                while ( v117 >> 7 );
              }
              if ( (*(_BYTE *)(v121 + 18) & 0x10) == 0 )
              {
                v66 = *(_DWORD *)(v121 + 8);
                if ( (v66 & 0x400) == 0 )
                {
                  if ( (*(_BYTE *)(v121 + 18) & 8) == 0 )
                  {
                    v67 = *(_DWORD *)(v121 + 8);
                    if ( (v66 & 0x10) != 0 )
                    {
                      *(_DWORD *)(v121 + 8) = v66 & 0xFFFFFFEF;
                      v62 = v67 & 0xFFFFFFF7;
                    }
                    else
                    {
                      v62 = 0;
                    }
                  }
                  *(_BYTE *)(v121 + 18) |= 0x10u;
                }
              }
              __dmb(0xBu);
              v68 = (unsigned int *)(v121 + 12);
              do
                v69 = __ldrex(v68);
              while ( __strex(v69 & 0x7FFFFFFF, v68) );
              if ( v62 )
                MiReleasePageFileInfo(MiSystemPartition, v62, 1);
              KfLowerIrql(v63);
              v22 = dword_63389C;
            }
            v27 = v121;
            goto LABEL_19;
          }
          v45 = ((unsigned __int64)*(unsigned int *)(v37 + 20) << 9)
              + __PAIR64__((unsigned int)((int)(v43 - v44) >> 2) >> 20, (int)(v43 - v44) >> 2 << 12);
        }
        else
        {
          v75 = *(_DWORD *)(v37 + 4);
          if ( v75 )
          {
            v76 = (int)(v43 - v75) >> 2;
            v77 = __SPAIR64__((int)(v43 - v75) >> 31, v76) >> 20;
            v78 = v76 << 12;
          }
          else
          {
            v78 = 0;
            v77 = 0;
          }
          v45 = __PAIR64__(v77, v78)
              + __PAIR64__(
                  (*(_DWORD *)(v37 + 20) >> 20) | (*(unsigned __int16 *)(v37 + 16) >> 6 << 12),
                  *(_DWORD *)(v37 + 20) << 12);
        }
        v127 = v45;
        goto LABEL_49;
      }
      ObReferenceObjectExWithTag(v42, 7);
      __pld(v39);
      v80 = *v39;
      if ( (*v39 & 7) == 0 )
      {
        while ( v42 == (v80 & 0xFFFFFFF8) )
        {
          do
            v81 = __ldrex(v39);
          while ( v81 == v80 && __strex(v80 + 7, v39) );
          __dmb(0xBu);
          if ( v81 == v80 )
            goto LABEL_41;
          v80 = v81;
          if ( (v81 & 7) != 0 )
            break;
        }
      }
      v98 = (unsigned int *)(v42 - 24);
      if ( ObpTraceFlags )
        ObpPushStackInfo(v42 - 24, 0, 7, 1953261124);
      __dmb(0xBu);
      do
        v99 = __ldrex(v98);
      while ( __strex(v99 - 7, v98) );
      if ( (int)(v99 - 7) <= 0 )
      {
        if ( v99 != 7 )
          KeBugCheckEx(24, 0, v42);
        ObpDeferObjectDeletion(v42 - 24);
      }
    }
LABEL_41:
    if ( v42 )
      goto LABEL_42;
    goto LABEL_140;
  }
  return sub_536124();
}
