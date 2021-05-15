// MiSystemFault 
 
int __fastcall MiSystemFault(int a1, unsigned int a2, int a3, unsigned int a4, int a5, int **a6)
{
  unsigned int v6; // r7
  int **v8; // r1
  unsigned int v9; // lr
  int v10; // r8
  unsigned int v11; // r6
  int *v12; // r5
  int v13; // r10
  int (*v14)(); // r2
  int v15; // r5
  int v16; // r1
  int **v17; // r0
  int *v18; // t1
  int v19; // r2
  unsigned int v20; // r0
  int v21; // r4
  unsigned int v22; // r1
  int v23; // r3
  unsigned int v24; // r8
  int *v25; // r7
  int v26; // r9
  unsigned __int8 *v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r0
  int v30; // r3
  BOOL v31; // r2
  int **v32; // r4
  int v33; // r1
  int *v34; // t1
  int v35; // r2
  unsigned int v36; // lr
  int v37; // r4
  int v38; // r1
  unsigned int v39; // r5
  int v40; // r4
  int v41; // r0
  int result; // r0
  unsigned __int8 *v43; // r3
  unsigned int v44; // r1
  unsigned int v45; // r0
  int **v46; // r4
  int v47; // r1
  int *v48; // t1
  int v49; // r2
  int v50; // r1
  unsigned int v51; // r4
  int v52; // r5
  int v53; // r6
  int v54; // r1
  unsigned int v55; // r6
  int **v56; // r3
  int v57; // r3
  unsigned int v58; // r0
  unsigned int v59; // r1
  int v60; // r2
  int v61; // r4
  unsigned int v62; // r2
  int v63; // r4
  unsigned int v64; // r2
  unsigned int v65; // r0
  unsigned int v66; // r1
  int v67; // r4
  unsigned int v68; // r2
  int v69; // r2
  int v70; // r1
  int v71; // r3
  int v72; // r4
  unsigned int v73; // r2
  unsigned int v74; // r0
  unsigned int v75; // r1
  unsigned int v76; // r3
  int v77; // r3
  int v78; // r0
  int v79; // r4
  int v80; // r7
  int *v81; // lr
  int v82; // r4
  unsigned int v83; // r2
  _DWORD *v84; // r4
  int v85; // r0
  unsigned int *v86; // r2
  unsigned int v87; // r0
  unsigned int *v88; // r2
  unsigned int v89; // r1
  unsigned int v90; // r1
  unsigned int v91; // r1
  unsigned int v92; // r0
  unsigned int v93; // r1
  unsigned int v94; // r4
  unsigned int v95; // r4
  unsigned int v96; // r1
  unsigned int v97; // r0
  int v98; // r0
  unsigned int v99; // r3
  int v100; // r2
  int v101; // r8
  unsigned int v102; // lr
  void **v103; // r4
  int v104; // r2
  int v105; // r1
  int v106; // t1
  int v107; // r2
  int v108; // r4
  int v109; // r2
  unsigned int v110; // r0
  int v111; // r0
  unsigned int v112; // r0
  unsigned int v113; // r0
  unsigned int v114; // r1
  int v115; // [sp+10h] [bp-58h]
  unsigned int v118; // [sp+20h] [bp-48h] BYREF
  unsigned int v119; // [sp+24h] [bp-44h]
  unsigned int v120; // [sp+28h] [bp-40h]
  int *v121; // [sp+2Ch] [bp-3Ch] BYREF
  int **v122; // [sp+30h] [bp-38h] BYREF
  int **v123; // [sp+34h] [bp-34h]
  int v124; // [sp+38h] [bp-30h]
  int v125; // [sp+3Ch] [bp-2Ch]
  int v126; // [sp+40h] [bp-28h]

  v6 = a2;
  v115 = a3;
  v8 = a6;
  v122 = (int **)a5;
  v123 = a6;
  v9 = a4;
  v119 = a4;
  v10 = 0;
  if ( a1 < 0 )
  {
    if ( v6 + 0x40000000 > 0x3FFFFF )
      return -805306362;
    if ( a4 > MmHighestUserAddress )
      return sub_534D20();
    return 192;
  }
  if ( v6 >= 0xC0400000 && v6 < 0xC0402000 )
    return 192;
  v11 = v6 & 0xFFFFF000;
  if ( (v6 & 0xFFFFF000) == -1069539328 )
    return 192;
  v120 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = MiState;
  if ( !dword_634304 )
    goto LABEL_5;
  v80 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_634300);
LABEL_271:
    v81 = MiState;
    goto LABEL_236;
  }
  v81 = MiState;
  v82 = dword_634300 & 0x7FFFFFFF;
  do
    v83 = __ldrex((unsigned int *)&dword_634300);
  while ( v83 == v82 && __strex(v82 + 1, (unsigned int *)&dword_634300) );
  __dmb(0xBu);
  if ( v83 != v82 )
  {
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_634300);
    goto LABEL_271;
  }
LABEL_236:
  v84 = (_DWORD *)v81[1570];
  if ( !v84 )
    goto LABEL_241;
  while ( 1 )
  {
    v85 = MiCombineCompareThread(v120, v84);
    if ( v85 >= 0 )
      break;
    v84 = (_DWORD *)*v84;
LABEL_239:
    if ( !v84 )
      goto LABEL_240;
  }
  if ( v85 > 0 )
  {
    v84 = (_DWORD *)v84[1];
    goto LABEL_239;
  }
LABEL_240:
  v81 = MiState;
  if ( v84 && v84[5] != ((a2 >> 10) & 0x3FFFFC) - 0x40000000 )
    v84 = 0;
LABEL_241:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v81 + 1568);
  }
  else
  {
    __dmb(0xBu);
    v86 = (unsigned int *)(v81 + 1568);
    do
      v87 = __ldrex(v86);
    while ( __strex(v87 & 0xBFFFFFFF, v86) );
    __dmb(0xBu);
    v88 = (unsigned int *)(v81 + 1568);
    do
      v89 = __ldrex(v88);
    while ( __strex(v89 - 1, v88) );
  }
  KfLowerIrql(v80);
  if ( v84 )
    return -1073741819;
  v6 = a2;
  v8 = v123;
  v12 = MiState;
  v9 = v119;
LABEL_5:
  v13 = a3 & 1;
  if ( (a3 & 1) != 0 && *(_BYTE *)(a3 & 0xFFFFFFFE) == 1 )
  {
LABEL_144:
    v60 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v60 == PsInitialSystemProcess
      && *(int (**)())((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x39C) != KeBalanceSetManager )
    {
      v76 = v12[903];
      if ( v9 >= v76 )
      {
        v77 = *((unsigned __int8 *)v12 + ((int)(((v9 >> 20) & 0xFFC) - ((v76 >> 20) & 0xFFC)) >> 2) + 9692);
        if ( v77 == 1 || v77 == 11 )
          return -1073741819;
      }
    }
    *((_BYTE *)v8 + 9) = 1;
    v10 = 32;
  }
  else if ( (a3 & 1) != 0 )
  {
    if ( *(_BYTE *)(a3 & 0xFFFFFFFE) == 3 )
      goto LABEL_144;
  }
  else if ( a3 )
  {
    v14 = (*(_DWORD *)(a3 + 132) & 0x1F) == 19 ? ExpInterlockedPopEntrySListFault : KeUserPopEntrySListFault;
    if ( *(int (**)())(a3 + 128) == v14 )
      goto LABEL_144;
  }
  if ( (a3 & 1) == 0 || *(_BYTE *)(a3 & 0xFFFFFFFE) != 1 )
  {
    if ( (v10 & 0x20) != 0 )
    {
      v15 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
      }
      else
      {
        v61 = dword_6342C0 & 0x7FFFFFFF;
        do
          v62 = __ldrex((unsigned int *)&dword_6342C0);
        while ( v62 == v61 && __strex(v61 + 1, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        if ( v62 != v61 )
          ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
      }
      v118 = v15;
    }
    else
    {
      v15 = 17;
      v118 = 17;
    }
    goto LABEL_14;
  }
  if ( v9 < v12[903] )
    return 192;
  v15 = KfRaiseIrql(2);
  v118 = v15;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    v67 = dword_6342C0 & 0x7FFFFFFF;
    do
      v68 = __ldrex((unsigned int *)&dword_6342C0);
    while ( v68 == v67 && __strex(v67 + 1, (unsigned int *)&dword_6342C0) );
    __dmb(0xBu);
    if ( v68 != v67 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
  }
LABEL_14:
  v16 = 0;
  v17 = v122;
  do
  {
    v18 = *v17++;
    v19 = *v18;
    if ( (*v18 & 2) == 0 )
    {
      if ( v15 == 17 )
        KeBugCheckEx(80, v6, a1);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
      }
      else
      {
        __dmb(0xBu);
        do
          v113 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v113 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        do
          v114 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v114 - 1, (unsigned int *)&dword_6342C0) );
      }
      KfLowerIrql(v15);
      return -1073741819;
    }
    ++v16;
  }
  while ( !v16 );
  if ( (v19 & 0x400) != 0 )
  {
    if ( (a1 & 1) != 0 && (v19 & 0x80) == 0 )
      KeBugCheckEx(190, v6, v19);
    MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, v6, a3, v19);
    if ( v15 != 17 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
      }
      else
      {
        __dmb(0xBu);
        do
          v92 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v92 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        do
          v93 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v93 - 1, (unsigned int *)&dword_6342C0) );
      }
      v41 = v15;
LABEL_77:
      KfLowerIrql(v41);
    }
    return 0;
  }
  v20 = v119;
  v21 = *v122[1];
  v121 = v122[1];
  v22 = MmHighestUserAddress;
  if ( v119 <= MmHighestUserAddress )
  {
    v24 = v10 | 1;
  }
  else
  {
    if ( v119 < dword_63389C )
      goto LABEL_107;
    v23 = *((unsigned __int8 *)&MiState[2423]
          + ((int)(((v119 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    switch ( v23 )
    {
      case 11:
      case 1:
        v24 = v10 | 2;
        break;
      case 8:
        v24 = v10 | 8;
        break;
      case 6:
      case 14:
      case 7:
        v24 = v10 | 4;
        break;
      default:
LABEL_107:
        v24 = v10 | 0x10;
        break;
    }
  }
  if ( v15 != 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v58 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v58 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v59 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v59 - 1, (unsigned int *)&dword_6342C0) );
    }
    KfLowerIrql(v15);
    v20 = v119;
    v22 = MmHighestUserAddress;
  }
  if ( (v21 & 2) != 0 )
  {
    if ( (a3 & 1) != 0 && *(_BYTE *)(a3 & 0xFFFFFFFE) == 1 )
    {
      MiUpdatePfnPriorityByPte(v21, *(_DWORD *)((a3 & 0xFFFFFFFE) + 40) & 7);
      return 0;
    }
    if ( (v24 & 1) != 0 )
    {
      v25 = (int *)(*(_DWORD *)(v120 + 116) + 492);
      goto LABEL_33;
    }
    if ( (v24 & 2) == 0 )
    {
      if ( (v24 & 8) != 0 )
      {
        v25 = &dword_634E00;
      }
      else if ( (v24 & 4) != 0 )
      {
        v25 = &dword_634E80;
      }
      else
      {
        v25 = &dword_634F00;
      }
LABEL_33:
      v26 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v25);
      }
      else
      {
        v27 = (unsigned __int8 *)v25 + 3;
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 | 0x80, v27) );
        __dmb(0xBu);
        if ( v28 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v25);
        while ( 1 )
        {
          v29 = *v25;
          if ( (*v25 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v29 & 0x40000000) == 0 )
          {
            do
              v90 = __ldrex((unsigned int *)v25);
            while ( v90 == v29 && __strex(v29 | 0x40000000, (unsigned int *)v25) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( (v24 & 1) == 0 && v118 != 17 )
      {
        v24 |= 0x40u;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
        }
        else
        {
          v63 = dword_6342C0 & 0x7FFFFFFF;
          do
            v64 = __ldrex((unsigned int *)&dword_6342C0);
          while ( v64 == v63 && __strex(v63 + 1, (unsigned int *)&dword_6342C0) );
          __dmb(0xBu);
          if ( v64 != v63 )
            ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
        }
      }
      v31 = 0;
      if ( v119 >= dword_63389C )
      {
        v30 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((v119 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v30 == 11 || v30 == 1 )
          v31 = 1;
      }
      if ( ((v24 >> 1) & 1) != 0 )
      {
        if ( v31 )
        {
LABEL_47:
          v32 = v122;
          v33 = 0;
          do
          {
            v34 = *v32++;
            v35 = *v34;
            if ( (*v34 & 2) == 0 )
            {
              if ( (v24 & 0x40) == 0 )
                goto LABEL_135;
              if ( (dword_682604 & 0x10000) == 0 )
              {
                __dmb(0xBu);
                do
                  v110 = __ldrex((unsigned int *)&dword_6342C0);
                while ( __strex(v110 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
                goto LABEL_302;
              }
              goto LABEL_391;
            }
            ++v33;
          }
          while ( !v33 );
          if ( (v35 & 0x400) != 0 )
          {
            if ( (a1 & 1) != 0 && (v35 & 0x80) == 0 )
              KeBugCheckEx(190, a2, v35);
            MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, v115, v35);
            if ( (v24 & 0x40) == 0 )
              goto LABEL_135;
            if ( (dword_682604 & 0x10000) != 0 )
              goto LABEL_391;
            __dmb(0xBu);
            do
              v97 = __ldrex((unsigned int *)&dword_6342C0);
            while ( __strex(v97 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
            goto LABEL_302;
          }
          v36 = (unsigned int)v121;
          v37 = *v121;
          if ( (v24 & 0x40) != 0 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
              v36 = (unsigned int)v121;
            }
            else
            {
              __dmb(0xBu);
              do
                v65 = __ldrex((unsigned int *)&dword_6342C0);
              while ( __strex(v65 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
              __dmb(0xBu);
              do
                v66 = __ldrex((unsigned int *)&dword_6342C0);
              while ( __strex(v66 - 1, (unsigned int *)&dword_6342C0) );
            }
          }
          if ( (v37 & 2) != 0 )
          {
            if ( (a1 & 1) == 0 )
            {
              if ( (a1 & 8) != 0 )
              {
                if ( (KeFeatureBits & 2) != 0 && (v37 & 0x20) != 0 )
                  KeBugCheckEx(252, a2, v37);
                if ( (v37 & 1) != 0 )
                  KeBugCheckEx(252, a2, v37);
              }
LABEL_55:
              v38 = *(_DWORD *)v36;
              if ( (a1 & 1) != 0 && (v38 & 0x200) != 0 )
              {
                v39 = v38 & 0xFFFFFDFF | 0x10;
                goto LABEL_58;
              }
              if ( (v38 & 0x10) == 0 )
              {
                v39 = v38 | 0x10;
LABEL_58:
                if ( v36 + 0x40000000 > 0x3FFFFF )
                {
                  *(_DWORD *)v36 = v39;
                }
                else
                {
                  v40 = 0;
                  __dmb(0xBu);
                  *(_DWORD *)v36 = v39;
                  if ( (v38 & 2) == 0 && (v39 & 2) != 0 )
                    v40 = 1;
                  if ( v36 >= 0xC0300000 && v36 <= 0xC0300FFF )
                  {
                    v98 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v98, v98 + 4 * (v36 & 0xFFF), v39);
                  }
                  if ( v40 == 1 )
                  {
                    __dsb(0xFu);
                    __isb(0xFu);
                  }
                }
              }
              if ( (MiFlags & 0x300) == 0 )
              {
                __dsb(0xFu);
                __mcr(15, 0, v11, 8, 3, 3);
                if ( v11 >= 0xC0000000 && v11 <= 0xC03FFFFF )
                {
                  v99 = (v11 & 0xFFFFF000) << 10;
                  v100 = 4;
                  do
                  {
                    __mcr(15, 0, v99, 8, 3, 3);
                    v99 += 0x100000;
                    --v100;
                  }
                  while ( v100 );
                }
                __dsb(0xFu);
                __isb(0xFu);
                if ( KiTbSendIpiForBroadcastFlushes )
                {
                  __mcr(15, 0, 0, 8, 3, 1);
                  __dsb(0xFu);
                  v101 = KfRaiseIrql(12);
                  v102 = (unsigned int)KeGetPcr() & 0xFFFFF000;
                  v124 = *(_DWORD *)&KeActiveProcessors;
                  v125 = dword_681D74;
                  v126 = dword_681D78[0];
                  v103 = &KeNodeBlock;
                  if ( KeNodeBlock )
                  {
                    v104 = (unsigned __int16)KeNumberNodes;
                    v105 = 0;
                    if ( KeNumberNodes )
                    {
                      do
                      {
                        v106 = (int)*v103++;
                        v105 |= *(_DWORD *)(v106 + 128);
                        --v104;
                      }
                      while ( v104 );
                    }
                    v107 = v126 & ~v105;
                    v124 = 65537;
                    v125 = 0;
                    if ( !v107 )
                      goto LABEL_66;
                  }
                  else
                  {
                    v107 = v126;
                  }
                  v126 = v107 & ~(1 << *(_DWORD *)(v102 + 1428));
                  KiIpiSendRequestEx(v102 + 1408);
                  KfLowerIrql(v101);
                }
LABEL_66:
                if ( VmTbFlushEnabled )
                {
                  v118 = a2 & 0xFFFFF000 | 1;
                  VmFlushTb(1, &v118);
                }
                if ( ExTbFlushActive )
                {
                  v118 = a2 & 0xFFFFF000 | 1;
                  v108 = KfRaiseIrql(15);
                  ExFlushTb(1, &v118, 0);
                  KfLowerIrql(v108);
                }
              }
              if ( (*((_BYTE *)v25 + 115) & 0x10) != 0 )
              {
                *((_BYTE *)v25 + 115) &= 0xEFu;
                MiAgeWorkingSet(v25, v26, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
              }
              if ( (*((_BYTE *)v25 + 115) & 0x20) != 0 )
              {
                v109 = v25[17];
                *((_BYTE *)v25 + 115) &= 0xDFu;
                MiReduceWs(v25, v26, v109);
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v25);
              }
              else
              {
                __dmb(0xBu);
                *v25 = 0;
              }
              v41 = v26;
              goto LABEL_77;
            }
            if ( (v37 & 0x80) != 0 )
              goto LABEL_55;
            if ( (v37 & 0x100) == 0 )
              KeBugCheckEx(190, a2, v37);
            MiCopyOnWriteEx(a2, v36, -1, v26, 0);
          }
          goto LABEL_135;
        }
      }
      else if ( !v31 )
      {
        goto LABEL_47;
      }
      if ( (v24 & 0x40) != 0 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
          goto LABEL_391;
        __dmb(0xBu);
        do
          v94 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v94 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
        goto LABEL_302;
      }
      goto LABEL_135;
    }
    v69 = *(_DWORD *)(v120 + 116);
    v70 = *(_DWORD *)(v69 + 324);
    if ( v70 && v69 != PsInitialSystemProcess )
    {
      v25 = (int *)(v70 + 3248);
      goto LABEL_33;
    }
    if ( (v24 & 0x20) != 0 )
      return -1073741819;
    return -805306362;
  }
  if ( v6 >= 0xC0000000 && v6 <= 0xC03FFFFF )
  {
    if ( (v24 & 0x20) != 0 )
      return -1073741819;
    if ( v20 > v22 )
    {
      if ( (a3 & 1) == 0 || *(_BYTE *)(a3 & 0xFFFFFFFE) != 1 )
        KeBugCheckEx(80, v6, a1);
      return 0;
    }
    return 192;
  }
  if ( (v24 & 2) != 0 )
  {
    v78 = *(_DWORD *)(v120 + 116);
    v79 = *(_DWORD *)(v78 + 324);
    if ( !v79 || PsIsSystemProcess(v78) )
    {
      if ( (v24 & 0x20) != 0 )
        return -1073741819;
      if ( (a3 & 1) == 0 || *(_BYTE *)(a3 & 0xFFFFFFFE) != 1 )
        KeBugCheckEx(80, v6, a1);
      return 0;
    }
    v25 = (int *)(v79 + 3248);
  }
  else if ( (v24 & 8) != 0 )
  {
    v25 = &dword_634E00;
  }
  else if ( (v24 & 4) != 0 )
  {
    v25 = &dword_634E80;
  }
  else
  {
    v25 = &dword_634F00;
  }
  v26 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v25);
  }
  else
  {
    v43 = (unsigned __int8 *)v25 + 3;
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 | 0x80, v43) );
    __dmb(0xBu);
    if ( v44 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v25);
    while ( 1 )
    {
      v45 = *v25;
      if ( (*v25 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v45 & 0x40000000) == 0 )
      {
        do
          v91 = __ldrex((unsigned int *)v25);
        while ( v91 == v45 && __strex(v45 | 0x40000000, (unsigned int *)v25) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v118 != 17 )
  {
    v24 |= 0x40u;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      v72 = dword_6342C0 & 0x7FFFFFFF;
      do
        v73 = __ldrex((unsigned int *)&dword_6342C0);
      while ( v73 == v72 && __strex(v72 + 1, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      if ( v73 != v72 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
    }
  }
  v46 = v122;
  v47 = 0;
  while ( 2 )
  {
    v48 = *v46++;
    v49 = *v48;
    if ( (*v48 & 2) == 0 )
    {
      if ( (v24 & 0x40) == 0 )
        goto LABEL_135;
      goto LABEL_390;
    }
    if ( !++v47 )
      continue;
    break;
  }
  if ( (v49 & 0x400) != 0 )
  {
    if ( (a1 & 1) != 0 && (v49 & 0x80) == 0 )
      KeBugCheckEx(190, a2, v49);
    MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, v115, v49);
    if ( (v24 & 0x40) != 0 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
        goto LABEL_391;
      __dmb(0xBu);
      do
        v95 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v95 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      goto LABEL_302;
    }
LABEL_135:
    MiUnlockWorkingSetExclusive(v25, v26);
    return 0;
  }
  v50 = (v24 >> 6) & 1;
  if ( !v50 )
    goto LABEL_96;
  if ( v119 < dword_63389C )
  {
LABEL_227:
    if ( (v24 & 0x10) != 0 )
      goto LABEL_96;
LABEL_390:
    if ( (dword_682604 & 0x10000) != 0 )
      goto LABEL_391;
    goto LABEL_392;
  }
  v71 = *((unsigned __int8 *)&MiState[2423]
        + ((int)(((v119 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  switch ( v71 )
  {
    case 1:
    case 11:
      if ( (v24 & 2) == 0 )
      {
        if ( (dword_682604 & 0x10000) == 0 )
          goto LABEL_392;
LABEL_391:
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
        goto LABEL_135;
      }
      break;
    case 8:
      if ( (v24 & 8) == 0 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
          goto LABEL_391;
        goto LABEL_392;
      }
      break;
    case 6:
    case 14:
    case 7:
      if ( (v24 & 4) == 0 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
          goto LABEL_391;
LABEL_392:
        __dmb(0xBu);
        do
          v112 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v112 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
LABEL_302:
        __dmb(0xBu);
        do
          v96 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v96 - 1, (unsigned int *)&dword_6342C0) );
        goto LABEL_135;
      }
      break;
    default:
      goto LABEL_227;
  }
LABEL_96:
  v51 = *v121;
  if ( v50 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v74 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v74 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v75 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v75 - 1, (unsigned int *)&dword_6342C0) );
    }
  }
  if ( (v51 & 2) != 0 )
    goto LABEL_135;
  v52 = 0;
  if ( (v51 & 0x400) != 0 )
  {
    v55 = a2;
    v52 = (v51 & 0x1FC | (v51 >> 2) & 0x3FFFFE00) - 0x40000000;
    if ( (v24 & 2) != 0 )
    {
      if ( (v51 & 0xFFFFE000) == -8192 )
      {
        v52 = MiCheckVirtualAddress(a2, &v122, &v121);
        if ( !v52 )
        {
          if ( v13 && *(_BYTE *)(v115 & 0xFFFFFFFE) == 1 )
            goto LABEL_360;
          if ( v13 )
          {
            if ( *(_BYTE *)(v115 & 0xFFFFFFFE) == 3 )
              goto LABEL_360;
          }
          else if ( KeInvalidAccessAllowed(v115) == 1 )
          {
            goto LABEL_360;
          }
          MiUnlockWorkingSetExclusive(v25, v26);
          return -805306362;
        }
      }
      v54 = v115;
    }
    else
    {
      v54 = v115;
    }
LABEL_103:
    if ( (a1 & 1) != 0 && !v52 && (v24 & 2) == 0 )
    {
      v57 = (v51 >> 5) & 0x1F;
      if ( (v51 & 0x800) != 0 )
        v57 = (v51 >> 5) & 0x1F;
      if ( (v57 & 4) == 0 )
      {
        if ( v13 )
        {
          if ( *(_BYTE *)(v54 & 0xFFFFFFFE) == 1 || *(_BYTE *)(v54 & 0xFFFFFFFE) == 3 )
            goto LABEL_360;
        }
        else if ( KeInvalidAccessAllowed(v54) == 1 )
        {
          goto LABEL_360;
        }
        KeBugCheckEx(190, v55, v51);
      }
    }
    v56 = v123;
    result = -1073741802;
    *v123 = v25;
    v56[1] = (int *)v52;
    *((_BYTE *)v56 + 8) = v26;
    return result;
  }
  if ( (v51 & 0x800) != 0 || (v51 & 0x3E0) != 0 )
  {
    v53 = (v51 >> 5) & 0x1F;
    v54 = v115;
    if ( v53 != 24 )
    {
      if ( v53 != 31 )
      {
LABEL_102:
        v55 = a2;
        goto LABEL_103;
      }
      if ( !v13 )
        goto LABEL_377;
      if ( *(_BYTE *)(v115 & 0xFFFFFFFE) == 4 )
        goto LABEL_102;
    }
    if ( v13 )
    {
      if ( *(_BYTE *)(v115 & 0xFFFFFFFE) != 1 && *(_BYTE *)(v115 & 0xFFFFFFFE) != 3 )
LABEL_388:
        KeBugCheckEx(80, a2, a1);
LABEL_378:
      if ( v53 == 24 || !v13 || *(_BYTE *)(v54 & 0xFFFFFFFE) != 1 )
        goto LABEL_360;
      goto LABEL_102;
    }
LABEL_377:
    v111 = KeInvalidAccessAllowed(v115);
    v54 = v115;
    if ( v111 != 1 )
      goto LABEL_388;
    goto LABEL_378;
  }
  if ( !v13 || *(_BYTE *)(v115 & 0xFFFFFFFE) != 1 )
  {
    if ( v13 )
    {
      if ( *(_BYTE *)(v115 & 0xFFFFFFFE) != 3 )
LABEL_372:
        KeBugCheckEx(80, a2, a1);
    }
    else if ( KeInvalidAccessAllowed(v115) != 1 )
    {
      goto LABEL_372;
    }
  }
LABEL_360:
  MiUnlockWorkingSetExclusive(v25, v26);
  return -1073741819;
}
