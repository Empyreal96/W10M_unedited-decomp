// MiProtectPool 
 
int __fastcall MiProtectPool(unsigned int a1, int a2, __int16 a3)
{
  unsigned int v5; // r0
  unsigned int v6; // r1
  unsigned int v7; // r7
  unsigned int v8; // r5
  unsigned int *v9; // r10
  int v10; // r2
  unsigned int v11; // r7
  int v12; // r8
  unsigned __int8 *v13; // r3
  unsigned int v14; // r0
  int v15; // r7
  unsigned int v16; // r4
  _DWORD *v17; // r6
  unsigned int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r7
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r4
  unsigned int v25; // r2
  int v26; // r6
  int v27; // r6
  unsigned int v28; // r2
  unsigned int v29; // r2
  unsigned int v30; // r3
  int v31; // r4
  unsigned int *v32; // r2
  unsigned int v33; // r0
  int v34; // r2
  int *v35; // r2
  int v36; // t1
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned int v39; // r4
  int v40; // r4
  unsigned __int8 *v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r1
  int v45; // r0
  unsigned int v46; // r2
  unsigned int v47; // r3
  bool v48; // cc
  int v49; // r0
  bool v50; // cc
  int v51; // r0
  int v52; // r0
  int v53; // r8
  int v54; // r7
  int v55; // r0
  unsigned __int8 *v56; // r3
  unsigned int v57; // r1
  unsigned __int8 *v58; // r1
  int v59; // r3
  unsigned int v60; // r2
  unsigned int v61; // r6
  int v62; // r0
  unsigned int v63; // r2
  unsigned int *v64; // r2
  unsigned int v65; // r0
  int v66; // r0
  unsigned int *v67; // r2
  unsigned int v68; // r4
  int v69; // r8
  unsigned int v70; // r3
  int v71; // r6
  int v72; // r0
  unsigned int v73; // r7
  int v74; // r7
  unsigned int *v75; // r2
  unsigned int v76; // r0
  unsigned int v77; // r3
  int v78; // r4
  int v79; // r0
  int v80; // r4
  unsigned __int8 *v81; // r3
  unsigned int v82; // r1
  unsigned __int8 *v83; // r1
  int v84; // r3
  unsigned int v85; // r2
  int v86; // r3
  unsigned int *v87; // r2
  unsigned int v88; // r0
  unsigned int v89; // r1
  unsigned int v90; // r3
  int v91; // r4
  int v92; // r0
  unsigned __int8 *v93; // r1
  int v94; // r3
  unsigned int v95; // r2
  unsigned __int8 *v96; // r3
  unsigned int v97; // r1
  unsigned int v98; // r0
  unsigned int v99; // r1
  char v100[4]; // [sp+8h] [bp-160h] BYREF
  int v101; // [sp+Ch] [bp-15Ch]
  int v102; // [sp+10h] [bp-158h]
  unsigned int v103; // [sp+14h] [bp-154h]
  int v104; // [sp+18h] [bp-150h]
  unsigned int v105; // [sp+1Ch] [bp-14Ch]
  int v106; // [sp+20h] [bp-148h]
  unsigned int v107; // [sp+24h] [bp-144h]
  int v108; // [sp+28h] [bp-140h] BYREF
  char v109; // [sp+2Ch] [bp-13Ch]
  char v110; // [sp+2Dh] [bp-13Bh]
  int v111; // [sp+30h] [bp-138h]
  int v112; // [sp+34h] [bp-134h]
  int v113; // [sp+38h] [bp-130h]
  int v114; // [sp+3Ch] [bp-12Ch]
  unsigned int v115[42]; // [sp+C0h] [bp-A8h] BYREF

  if ( (a3 & 0x10) != 0 )
    return sub_5494DC();
  v5 = MiMakeProtectionMask(a3);
  v101 = v5;
  if ( v5 >= 8 && v5 != 24 || (v5 & 5) == 5 )
    return 0;
  v7 = a1 + v6 - 1;
  v106 = 0;
  v8 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v105 = 1070596096;
  v9 = 0;
  v104 = 0;
  if ( a1 < dword_63389C )
    goto LABEL_76;
  v10 = *((unsigned __int8 *)&MiState[2423]
        + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  if ( v10 != 6 && v10 != 14 )
  {
    if ( v10 == 7 || v10 == 13 )
    {
      if ( ((a1 ^ v7) & 0xFFFFF000) == 0 )
      {
        if ( v10 != 7 )
          goto LABEL_8;
        goto LABEL_7;
      }
      return 0;
    }
LABEL_76:
    if ( MI_VA_IN_SESSION_SPECIAL_POOL(a1) )
    {
      if ( ((a1 ^ v7) & 0xFFFFF000) == 0 )
      {
        v106 = 2;
        v9 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
        goto LABEL_8;
      }
    }
    else if ( a1 >= dword_63389C )
    {
      v34 = (a1 >> 20) & 0xFFC;
      if ( *((_BYTE *)&MiState[2423] + ((int)(v34 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 5 )
      {
        v35 = (int *)(v34 - v105);
        v6 = ((v7 >> 20) & 0xFFC) - v105;
        if ( (unsigned int)v35 > v6 )
        {
LABEL_84:
          v104 = 1;
          goto LABEL_8;
        }
        while ( 1 )
        {
          v36 = *v35++;
          if ( (v36 & 0x400) != 0 )
            break;
          if ( (unsigned int)v35 > v6 )
            goto LABEL_84;
        }
      }
    }
    return 0;
  }
LABEL_7:
  v9 = (unsigned int *)&dword_634E80;
LABEL_8:
  v11 = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
  v112 = 0;
  v107 = v11;
  v108 = v106;
  v109 = 0;
  v110 = 0;
  v113 = 0;
  v111 = 33;
  v114 = 0;
  if ( v9 )
  {
    v105 = v9[23];
    v12 = KfRaiseIrql(2);
    v102 = v12;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
    }
    else
    {
      v13 = (unsigned __int8 *)v9 + 3;
      do
        v6 = __ldrex(v13);
      while ( __strex(v6 | 0x80, v13) );
      __dmb(0xBu);
      if ( v6 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v9);
      while ( 1 )
      {
        v14 = *v9;
        if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v14 & 0x40000000) == 0 )
        {
          do
            v6 = __ldrex(v9);
          while ( v6 == v14 && __strex(v14 | 0x40000000, v9) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  else
  {
    v12 = 17;
    v105 = 0;
    v102 = 17;
  }
  if ( v8 <= v11 )
  {
    v6 = 0x3FFFFF;
    v15 = v101;
    v103 = 0x3FFFFF;
    do
    {
      v16 = *(_DWORD *)v8;
      if ( v15 == 24 )
      {
        if ( !v9 )
        {
          if ( v104 == 1 )
          {
            v52 = MiLockNonPagedPoolPte(v8, v100);
            v16 = *(_DWORD *)v8;
            v53 = (unsigned __int8)v100[0];
            v54 = v52;
          }
          else
          {
            v54 = MmPfnDatabase + 24 * (v16 >> 12);
            v55 = KfRaiseIrql(2);
            v53 = v55;
            v56 = (unsigned __int8 *)(v54 + 15);
            do
              v57 = __ldrex(v56);
            while ( __strex(v57 | 0x80, v56) );
            __dmb(0xBu);
            if ( v57 >> 7 )
            {
              v58 = (unsigned __int8 *)(v54 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v59 = *(_DWORD *)(v54 + 12);
                  __dmb(0xBu);
                }
                while ( (v59 & 0x80000000) != 0 );
                do
                  v60 = __ldrex(v58);
                while ( __strex(v60 | 0x80, v58) );
                __dmb(0xBu);
              }
              while ( v60 >> 7 );
            }
            v100[0] = v55;
          }
          *(_DWORD *)(v54 + 8) = *(_DWORD *)(v54 + 8) & 0xFFFFFC1F | 0x300;
          v61 = v16 & 0xFFFFFB1C | 0xB00;
          if ( v104 == 1 )
          {
            while ( 1 )
            {
              __dmb(0xBu);
              do
                v63 = __ldrex((unsigned int *)v8);
              while ( v63 == v16 && __strex(v61, (unsigned int *)v8) );
              __dmb(0xBu);
              if ( v63 == v16 )
                break;
              v61 = v63 & 0xFFFFFB1C | 0xB00;
              v16 = v63;
            }
            if ( (v16 & 0x100) != 0 )
              *(_DWORD *)(v54 + 12) = *(_DWORD *)(v54 + 12) & 0xC0000000 | 0x10000;
          }
          else if ( v8 + 0x40000000 > v103 )
          {
            *(_DWORD *)v8 = v61;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v8 = v61;
            if ( v8 + 1070596096 <= 0xFFF )
            {
              v62 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v62, (_DWORD *)(v62 + 4 * (v8 & 0xFFF)), v61);
            }
          }
          __dmb(0xBu);
          v64 = (unsigned int *)(v54 + 12);
          do
            v65 = __ldrex(v64);
          while ( __strex(v65 & 0x7FFFFFFF, v64) );
          v66 = v53;
LABEL_158:
          KfLowerIrql(v66);
LABEL_159:
          MiInsertTbFlushEntry((int)&v108, v8 << 10, 1, 0);
          v15 = v101;
LABEL_160:
          v12 = v102;
          goto LABEL_37;
        }
        if ( (v16 & 2) != 0 )
        {
          v37 = (unsigned int *)(MmPfnDatabase + 24 * (v16 >> 12));
          if ( (v37[5] & 0x8000000) != 0 )
          {
            MiFlushTbList((unsigned int)&v108, v6);
            MiCopyOnWriteEx(v8 << 10, v8, -1, v12, 0);
          }
          else
          {
            v38 = MiLocateWsle(v8 << 10, (int)v9, *v37);
            v39 = v38;
            if ( dword_634484
              && (*(_DWORD *)v8 & 0x10) != 0
              && (*(_DWORD *)(*(_DWORD *)(v105 + 36) * v38 + *(_DWORD *)(v105 + 252)) & 0xE00) != 3584 )
            {
              MiLogPageAccess(v9, v8);
            }
            v115[0] = 1;
            v115[1] = v39;
            if ( v39 < *(_DWORD *)(v105 + 4) || MiFreeWsleList((int)v9, v115, 0) )
              goto LABEL_37;
          }
          goto LABEL_93;
        }
        if ( (v16 & 0x400) != 0 )
        {
          MiFlushTbList((unsigned int)&v108, v6);
          MiUnlockWorkingSetExclusive((int)v9, v12);
          MmAccessFault(0, v8 << 10, 0, 0);
          v40 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
            goto LABEL_91;
          v41 = (unsigned __int8 *)v9 + 3;
          do
            v42 = __ldrex(v41);
          while ( __strex(v42 | 0x80, v41) );
          __dmb(0xBu);
          if ( v42 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v9);
          while ( 1 )
          {
            v43 = *v9;
            if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v43 & 0x40000000) == 0 )
            {
              do
                v44 = __ldrex(v9);
              while ( v44 == v43 && __strex(v43 | 0x40000000, v9) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
LABEL_92:
          v12 = v40;
          v102 = v40;
LABEL_93:
          v8 -= 4;
          goto LABEL_37;
        }
        if ( (v16 & 0x800) != 0 )
        {
          v45 = MiLockTransitionLeafPage((unsigned int *)v8, 0);
          v27 = v45;
          if ( v45 )
          {
            v46 = *(_DWORD *)v8;
            *(_DWORD *)(v45 + 8) = *(_DWORD *)(v45 + 8) & 0xFFFFFC1F | 0x300;
            v29 = v46 & 0xFFFFFC1F | 0x300;
            if ( v8 + 0x40000000 <= v103 )
            {
              v47 = *(_DWORD *)v8;
              v31 = 0;
              __dmb(0xBu);
              *(_DWORD *)v8 = v29;
              if ( (v47 & 2) == 0 && (v29 & 2) != 0 )
                v31 = 1;
              v48 = v8 + 1070596096 > 0xFFF;
LABEL_123:
              if ( !v48 )
              {
                v49 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v49, (_DWORD *)(v49 + 4 * (v8 & 0xFFF)), v29);
              }
LABEL_58:
              if ( v31 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
LABEL_60:
              __dmb(0xBu);
              v32 = (unsigned int *)(v27 + 12);
              do
                v33 = __ldrex(v32);
              while ( __strex(v33 & 0x7FFFFFFF, v32) );
              goto LABEL_37;
            }
LABEL_66:
            *(_DWORD *)v8 = v29;
            goto LABEL_60;
          }
          goto LABEL_121;
        }
        v25 = v16 & 0xFFFFFC1F | 0x300;
        if ( v8 + 0x40000000 <= v6 )
        {
          v26 = 0;
          __dmb(0xBu);
          *(_DWORD *)v8 = v25;
          v50 = v8 + 1070596096 > 0xFFF;
LABEL_128:
          if ( !v50 )
          {
            v51 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v51, (_DWORD *)(v51 + 4 * (v8 & 0xFFF)), v25);
          }
LABEL_48:
          if ( v26 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
          goto LABEL_37;
        }
      }
      else
      {
        if ( !v9 )
        {
          while ( 1 )
          {
            v69 = MmPfnDatabase + 24 * (v16 >> 12);
            if ( v106 )
              v70 = (MmProtectToPteMask[v15] ^ v16) & 0xFED ^ v16 | MiDetermineUserGlobalPteMask(v8);
            else
              v70 = ((MmProtectToPteMask[v15] ^ v16) & 0x3ED ^ v16 | MiDetermineUserGlobalPteMask(v8)) & 0xFFFFF3FF;
            v71 = v70 | 0x12;
            if ( (v15 & 4) != 0 )
              v71 &= 0xFFFFFDFF;
            if ( (v16 & 2) == 0 )
            {
              if ( (*(_DWORD *)(v69 + 12) & 0x3FFFFFFF) != 1 )
              {
                v80 = KfRaiseIrql(2);
                v81 = (unsigned __int8 *)(v69 + 15);
                do
                  v82 = __ldrex(v81);
                while ( __strex(v82 | 0x80, v81) );
                __dmb(0xBu);
                if ( v82 >> 7 )
                {
                  v83 = (unsigned __int8 *)(v69 + 15);
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v84 = *(_DWORD *)(v69 + 12);
                      __dmb(0xBu);
                    }
                    while ( (v84 & 0x80000000) != 0 );
                    do
                      v85 = __ldrex(v83);
                    while ( __strex(v85 | 0x80, v83) );
                    __dmb(0xBu);
                  }
                  while ( v85 >> 7 );
                }
                v86 = *(_DWORD *)(v69 + 12);
                v100[0] = v80;
                *(_DWORD *)(v69 + 12) = v86 & 0xC0000000 | 1;
                __dmb(0xBu);
                v87 = (unsigned int *)(v69 + 12);
                do
                  v88 = __ldrex(v87);
                while ( __strex(v88 & 0x7FFFFFFF, v87) );
                KfLowerIrql(v80);
                v71 |= 0x100u;
              }
              v89 = v103;
              *(_DWORD *)(v69 + 8) ^= ((unsigned __int16)*(_DWORD *)(v69 + 8) ^ (unsigned __int16)(32 * v15)) & 0x3E0;
              if ( v8 + 0x40000000 > v89 )
              {
                *(_DWORD *)v8 = v71;
              }
              else
              {
                v90 = *(_DWORD *)v8;
                v91 = 0;
                __dmb(0xBu);
                *(_DWORD *)v8 = v71;
                if ( (v90 & 2) == 0 )
                  v91 = 1;
                if ( v8 + 1070596096 <= 0xFFF )
                {
                  v92 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v92, (_DWORD *)(v92 + 4 * (v8 & 0xFFF)), v71);
                }
                if ( v91 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              goto LABEL_160;
            }
            if ( v104 != 1 )
              break;
            v72 = MiLockNonPagedPoolPte(v8, v100);
            v73 = *(_DWORD *)v8;
            v69 = v72;
            if ( *(_DWORD *)v8 == v16 )
            {
              if ( (v16 & 0x100) != 0 )
                v71 |= 0x100u;
              __dmb(0xBu);
              do
                v73 = __ldrex((unsigned int *)v8);
              while ( v73 == v16 && __strex(v71, (unsigned int *)v8) );
              __dmb(0xBu);
              if ( v73 == v16 )
              {
                v74 = (unsigned __int8)v100[0];
                goto LABEL_187;
              }
            }
            __dmb(0xBu);
            v75 = (unsigned int *)(v72 + 12);
            do
              v76 = __ldrex(v75);
            while ( __strex(v76 & 0x7FFFFFFF, v75) );
            KfLowerIrql((unsigned __int8)v100[0]);
            v16 = v73;
            v15 = v101;
          }
          v74 = 17;
          v100[0] = 17;
          if ( v8 + 0x40000000 > v103 )
          {
            *(_DWORD *)v8 = v71;
          }
          else
          {
            v77 = *(_DWORD *)v8;
            v78 = 0;
            __dmb(0xBu);
            *(_DWORD *)v8 = v71;
            if ( (v77 & 2) == 0 )
              v78 = 1;
            if ( v8 + 1070596096 <= 0xFFF )
            {
              v79 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v79, (_DWORD *)(v79 + 4 * (v8 & 0xFFF)), v71);
            }
            if ( v78 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
LABEL_187:
          *(_DWORD *)(v69 + 8) ^= ((unsigned __int16)*(_DWORD *)(v69 + 8) ^ (unsigned __int16)(32 * v101)) & 0x3E0;
          if ( v104 != 1 )
            goto LABEL_159;
          __dmb(0xBu);
          v67 = (unsigned int *)(v69 + 12);
          do
            v68 = __ldrex(v67);
          while ( __strex(v68 & 0x7FFFFFFF, v67) );
          v66 = v74;
          goto LABEL_158;
        }
        if ( (v16 & 2) != 0 )
        {
          v17 = (_DWORD *)(MmPfnDatabase + 24 * (v16 >> 12));
          if ( (v17[5] & 0x8000000) != 0 )
          {
            MiFlushTbList((unsigned int)&v108, v6);
            MiCopyOnWriteEx(v8 << 10, v8, -1, v12, 0);
          }
          else
          {
            if ( v106 )
              v18 = (MmProtectToPteMask[v15] ^ v16) & 0xFED ^ v16 | MiDetermineUserGlobalPteMask(v8);
            else
              v18 = ((MmProtectToPteMask[v15] ^ v16) & 0x3ED ^ v16 | MiDetermineUserGlobalPteMask(v8)) & 0xFFFFF3FF;
            __dmb(0xBu);
            do
              v19 = __ldrex((unsigned int *)v8);
            while ( v19 == v16 && __strex(v18 | 0x12, (unsigned int *)v8) );
            __dmb(0xBu);
            if ( v19 == v16 )
            {
              MiInsertTbFlushEntry((int)&v108, v8 << 10, 1, 0);
              v20 = 0;
              v21 = (unsigned __int8 *)v17 + 15;
              do
                v22 = __ldrex(v21);
              while ( __strex(v22 | 0x80, v21) );
              __dmb(0xBu);
              if ( v22 >> 7 )
              {
                v93 = (unsigned __int8 *)v17 + 15;
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                    v94 = v17[3];
                    __dmb(0xBu);
                  }
                  while ( (v94 & 0x80000000) != 0 );
                  do
                    v95 = __ldrex(v93);
                  while ( __strex(v95 | 0x80, v93) );
                  __dmb(0xBu);
                }
                while ( v95 >> 7 );
              }
              v17[2] ^= ((unsigned __int16)v17[2] ^ (unsigned __int16)(32 * v101)) & 0x3E0;
              if ( (v16 & 0x200) == 0 )
                v20 = MiCaptureDirtyBitToPfn((int)v17);
              __dmb(0xBu);
              v23 = v17 + 3;
              do
                v24 = __ldrex(v23);
              while ( __strex(v24 & 0x7FFFFFFF, v23) );
              if ( v20 )
                MiReleasePageFileInfo((int)MiSystemPartition, v20, 1, 0);
              v15 = v101;
              goto LABEL_37;
            }
          }
LABEL_121:
          v8 -= 4;
          goto LABEL_37;
        }
        if ( (v16 & 0x400) != 0 )
        {
          MiFlushTbList((unsigned int)&v108, v6);
          MiUnlockWorkingSetExclusive((int)v9, v12);
          MmAccessFault(0, v8 << 10, 0, 0);
          v40 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) == 0 )
          {
            v96 = (unsigned __int8 *)v9 + 3;
            do
              v97 = __ldrex(v96);
            while ( __strex(v97 | 0x80, v96) );
            __dmb(0xBu);
            if ( v97 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v9);
            while ( 1 )
            {
              v98 = *v9;
              if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v98 & 0x40000000) == 0 )
              {
                do
                  v99 = __ldrex(v9);
                while ( v99 == v98 && __strex(v98 | 0x40000000, v9) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
            goto LABEL_92;
          }
LABEL_91:
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
          goto LABEL_92;
        }
        if ( (v16 & 0x800) != 0 )
        {
          v27 = MiLockTransitionLeafPage((unsigned int *)v8, 0);
          if ( v27 )
          {
            v28 = *(_DWORD *)v8;
            *(_DWORD *)(v27 + 8) = *(_DWORD *)(v27 + 8) & 0xFFFFFC1F | (32 * (v15 & 0x1F));
            v29 = v28 & 0xFFFFFC1F | (32 * (v15 & 0x1F));
            if ( v8 + 0x40000000 <= v103 )
            {
              v30 = *(_DWORD *)v8;
              v31 = 0;
              __dmb(0xBu);
              *(_DWORD *)v8 = v29;
              if ( (v30 & 2) == 0 && (v29 & 2) != 0 )
                v31 = 1;
              if ( v8 >= 0xC0300000 )
              {
                v48 = v8 > 0xC0300FFF;
                goto LABEL_123;
              }
              goto LABEL_58;
            }
            goto LABEL_66;
          }
          goto LABEL_121;
        }
        v25 = (v16 ^ (32 * v15)) & 0x3E0 ^ v16;
        if ( v8 + 0x40000000 <= v6 )
        {
          v26 = 0;
          __dmb(0xBu);
          *(_DWORD *)v8 = v25;
          if ( (v16 & 2) == 0 && (v25 & 2) != 0 )
            v26 = 1;
          if ( v8 >= 0xC0300000 )
          {
            v50 = v8 > 0xC0300FFF;
            goto LABEL_128;
          }
          goto LABEL_48;
        }
      }
      *(_DWORD *)v8 = v25;
LABEL_37:
      v8 += 4;
      v6 = v103;
    }
    while ( v8 <= v107 );
  }
  MiFlushTbList((unsigned int)&v108, v6);
  if ( v9 )
    MiUnlockWorkingSetExclusive((int)v9, v12);
  return 1;
}
