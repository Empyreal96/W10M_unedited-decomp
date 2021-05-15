// MiCommitExistingVad 
 
int __fastcall MiCommitExistingVad(_DWORD *a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5)
{
  unsigned int v5; // r6
  _DWORD *v6; // r7
  __int16 v7; // r4
  int result; // r0
  int v10; // r2
  int *v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r4
  int v18; // r3
  unsigned int v19; // r9
  unsigned int v20; // r10
  int v21; // r5
  int v22; // r2
  int v23; // r0
  unsigned __int8 *v24; // r7
  unsigned int v25; // r6
  int v26; // r2
  int v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r1
  int v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r4
  int v33; // r3
  int v34; // r3
  unsigned int v35; // r1
  unsigned int v36; // r10
  int v37; // r5
  int v38; // r4
  int v39; // r6
  _WORD *v40; // r8
  int v41; // r7
  unsigned __int8 *v42; // r3
  unsigned int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r7
  unsigned int v46; // r10
  int v47; // r2
  unsigned int v48; // r4
  int v49; // r5
  int v50; // r10
  unsigned int v51; // r2
  char *v52; // r1
  int *v53; // t1
  int v54; // r3
  int v55; // r4
  _DWORD *v56; // r5
  int v57; // r3
  unsigned int *v58; // r4
  unsigned int v59; // r1
  int v60; // r3
  int v61; // r3
  unsigned int *v62; // r5
  int v63; // r4
  unsigned __int8 *v64; // r3
  unsigned int v65; // r1
  unsigned int v66; // r0
  unsigned int v67; // r1
  unsigned __int8 *v68; // r4
  char v69; // r5
  unsigned int v70; // r3
  char v71; // r2
  unsigned int v72; // r1
  unsigned int *v73; // r5
  int v74; // r6
  unsigned __int8 *v75; // r3
  unsigned int v76; // r1
  unsigned int v77; // r0
  unsigned int v78; // r1
  int v79; // r4
  int v80; // r1
  unsigned __int8 *v81; // r3
  unsigned int v82; // r2
  int v83; // r1
  int v84; // r2
  unsigned int v85; // r3
  int v86; // r0
  int v87; // r0
  int v88; // r2
  int v89; // [sp+8h] [bp-78h]
  int v90; // [sp+Ch] [bp-74h]
  unsigned int v91; // [sp+10h] [bp-70h]
  unsigned int v92; // [sp+14h] [bp-6Ch]
  int v93; // [sp+18h] [bp-68h]
  int v94; // [sp+1Ch] [bp-64h]
  int v96; // [sp+24h] [bp-5Ch]
  int v97; // [sp+28h] [bp-58h]
  int v98; // [sp+2Ch] [bp-54h]
  int v99; // [sp+34h] [bp-4Ch]
  int v100; // [sp+38h] [bp-48h]
  unsigned int v101; // [sp+3Ch] [bp-44h]
  int v102; // [sp+40h] [bp-40h]
  unsigned int v103; // [sp+48h] [bp-38h]
  unsigned int v104; // [sp+50h] [bp-30h]
  _DWORD v105[2]; // [sp+58h] [bp-28h]
  char v106; // [sp+60h] [bp-20h] BYREF

  v5 = a2;
  v6 = a1;
  v91 = a2;
  v7 = a4;
  if ( a4 >= 0x800 )
    return sub_530ADC(1024, 256);
  v10 = a4 & 0xF;
  if ( (a4 & 0xF) != 0 )
  {
    if ( (a4 & 0xF0) != 0 )
    {
      v12 = -1;
      goto LABEL_8;
    }
    v11 = MmUserProtectionToMask1;
  }
  else
  {
    v10 = (unsigned __int8)a4 >> 4;
    if ( !((unsigned __int8)a4 >> 4) )
    {
      v12 = -1;
      goto LABEL_8;
    }
    v11 = MmUserProtectionToMask2;
  }
  v12 = *((char *)v11 + v10);
  if ( v12 == -1 )
    goto LABEL_171;
  if ( (v7 & 0x700) == 0 )
  {
LABEL_8:
    v89 = v12;
    goto LABEL_9;
  }
  if ( (v7 & 0x100) != 0 )
  {
    if ( v12 == 24 || (v7 & 0x600) != 0 )
      goto LABEL_171;
    v12 |= 0x10u;
  }
  if ( (v7 & 0x200) != 0 )
  {
    if ( v12 != 24 && (v7 & 0x400) == 0 )
    {
      v12 |= 8u;
      goto LABEL_117;
    }
LABEL_171:
    v89 = -1;
    goto LABEL_9;
  }
LABEL_117:
  if ( (v7 & 0x400) == 0 )
    goto LABEL_8;
  if ( v12 == 24 )
  {
    v89 = -1;
  }
  else
  {
    if ( (v12 & 2) == 0 )
    {
      v12 |= 0x18u;
      goto LABEL_8;
    }
    v89 = -1;
  }
LABEL_9:
  v13 = a1[7];
  v14 = (unsigned __int8)v13 >> 3;
  if ( v89 == 24 )
  {
    v15 = 24;
  }
  else
  {
    if ( v14 == 24 )
    {
      if ( (v13 & 0x8000) == 0 )
        v14 = (*(unsigned __int16 *)(a1[11] + 16) >> 1) & 0x1F;
      if ( v14 == 24 )
        LOBYTE(v14) = 0;
    }
    LOBYTE(v15) = v89;
    v16 = v14 & 0x18;
    if ( v16 )
    {
      switch ( v16 )
      {
        case 16:
LABEL_180:
          v15 = v89 & 0xFFFFFFF7;
          break;
        case 8:
          v15 = v89 & 0xFFFFFFE7 | 8;
          break;
        case 24:
          v15 = v89 | 0x18;
          break;
        default:
          goto LABEL_14;
      }
    }
    else
    {
      if ( (v89 & 0x18) != 24 )
      {
        if ( (v89 & 0x18) != 8 )
          goto LABEL_14;
        goto LABEL_180;
      }
      v15 = v89 & 0xFFFFFFE7;
    }
  }
  v89 = v15;
LABEL_14:
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v90 = *(_DWORD *)(v17 + 0x74);
  v94 = v17;
  if ( (int)a1[8] < 0 )
    v18 = 4 * ((a1[4] & 0xFFFFF) - 0x10000000);
  else
    v18 = 0;
  v103 = v18;
  v96 = 32 * (v15 & 0x1F);
  v19 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v20 = (a2 + a3 - 1) | 0xFFF;
  v104 = ((v20 >> 10) & 0x3FFFFC) - 0x40000000;
  v102 = ((int)(v104 - v19) >> 2) + 1;
  if ( ((int (*)(void))MiChargeFullProcessCommitment)() < 0 )
  {
    v100 = 0;
    v73 = (unsigned int *)(v90 + 492);
    v74 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v73);
    }
    else
    {
      v75 = (unsigned __int8 *)(v90 + 495);
      do
        v76 = __ldrex(v75);
      while ( __strex(v76 | 0x80, v75) );
      __dmb(0xBu);
      if ( v76 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v73);
      while ( 1 )
      {
        v77 = *v73;
        if ( (*v73 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v77 & 0x40000000) == 0 )
        {
          do
            v78 = __ldrex(v73);
          while ( v78 == v77 && __strex(v77 | 0x40000000, v73) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = a1;
    }
    v79 = MiComputePageCommitment(v91 & 0xFFFFF000, v20, v6, v74, 0);
    MiUnlockWorkingSetExclusive(v73, v74);
    v21 = v90;
    v98 = v102 - v79;
    if ( v102 != v79 )
    {
      result = MiChargeFullProcessCommitment(v90, v102 - v79);
      if ( result < 0 )
        return result;
    }
    v17 = v94;
    v5 = v91;
  }
  else
  {
    v98 = ((int)(v104 - v19) >> 2) + 1;
    v21 = v90;
    v100 = 1;
  }
  v22 = v6[7];
  v99 = 0;
  v23 = 4096;
  if ( (v22 & 0x8000) != 0 )
  {
    if ( (v6[8] & 0x80000000) == 0 && (v22 & 7) == 0 )
      goto LABEL_21;
  }
  else if ( (unsigned __int8)v22 >> 3 == 24 )
  {
    v80 = v6[11];
    if ( v80 )
    {
      if ( (v6[7] & 7) != 1 && !*(_DWORD *)(*(_DWORD *)v80 + 32) && (*(_DWORD *)(*(_DWORD *)v80 + 28) & 0x1000) != 0 )
      {
LABEL_21:
        v99 = 1;
        --*(_WORD *)(v17 + 310);
        v24 = (unsigned __int8 *)(v21 + 256);
        if ( !KiAbEnabled || ((unsigned int)v24 & 0x7FFFFFFC) == 0 )
        {
          v32 = 0;
          goto LABEL_37;
        }
        v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v26 = 0;
        }
        else
        {
          __disable_irq();
          v26 = 1;
        }
        v27 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
        if ( v26 )
          __enable_irq();
        if ( (v27 & 0x10001) != 0 )
        {
          KeGetCurrentIrql(4096);
          KeBugCheckEx(402, v25, v21 + 256);
        }
        --*(_WORD *)(v25 + 310);
        if ( !*(_BYTE *)(v25 + 484) )
        {
          if ( !*(_BYTE *)(v25 + 810) )
          {
            v32 = 0;
            if ( (dword_682604 & 0x200) != 0 )
              v23 = EtwTraceAutoBoostEntryExhaustion(v25, v21 + 256);
            goto LABEL_207;
          }
          v68 = (unsigned __int8 *)(v25 + 810);
          v69 = *(_BYTE *)(v25 + 810);
          __dmb(0xBu);
          do
            v70 = __ldrex(v68);
          while ( __strex(v70 & ~v69, v68) );
          __dmb(0xBu);
          v71 = *(_BYTE *)(v25 + 484) | v69;
          v21 = v90;
          *(_BYTE *)(v25 + 484) = v71;
        }
        v28 = *(unsigned __int8 *)(v25 + 484);
        v23 = 1;
        v29 = __clz(__rbit(v28));
        v30 = v28 & ~(1 << v29);
        v31 = v25 + 48 * v29;
        v32 = v31 + 488;
        *(_BYTE *)(v25 + 484) = v30;
        if ( v31 != -488 )
        {
          if ( (unsigned int)v24 >= dword_63389C
            && ((v33 = *((unsigned __int8 *)&MiState[2423]
                       + ((int)((((unsigned int)v24 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                 v33 == 1)
             || v33 == 11) )
          {
            v23 = MmGetSessionIdEx(*(_DWORD *)(v25 + 116));
          }
          else
          {
            v23 = -1;
          }
          *(_DWORD *)(v32 + 20) = v23;
          *(_DWORD *)(v32 + 16) = (unsigned int)v24 & 0x7FFFFFFC;
          goto LABEL_35;
        }
LABEL_207:
        v81 = (unsigned __int8 *)(v25 + 81);
        do
          v82 = __ldrex(v81);
        while ( __strex(v82 | 0x80, v81) );
LABEL_35:
        v34 = (__int16)(*(_WORD *)(v25 + 310) + 1);
        *(_WORD *)(v25 + 310) = v34;
        if ( !v34 && *(_DWORD *)(v25 + 100) != v25 + 100 )
          KiCheckForKernelApcDelivery(v23);
        v5 = v91;
        do
LABEL_37:
          v35 = __ldrex(v24);
        while ( __strex(v35 | 1, v24) );
        __dmb(0xBu);
        if ( (v35 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v24, v32, v24);
        if ( v32 )
          *(_BYTE *)(v32 + 14) |= 1u;
        if ( MiCommitPageTablesForVad(a1, v5, v20) < 0 )
        {
          UNLOCK_PAGE_TABLE_COMMITMENT(v94, v21);
          if ( v98 )
            MiReturnFullProcessCommitment(v21, v98);
          return -1073741523;
        }
        goto LABEL_43;
      }
    }
  }
LABEL_43:
  v36 = 0;
  v37 = 0;
  v38 = v90 + 492;
  v39 = 0;
  v92 = 0;
  v93 = 0;
  v40 = 0;
  v41 = KfRaiseIrql(2);
  v97 = v41;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v38);
  }
  else
  {
    v42 = (unsigned __int8 *)(v90 + 495);
    do
      v43 = __ldrex(v42);
    while ( __strex(v43 | 0x80, v42) );
    __dmb(0xBu);
    if ( v43 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v38);
    while ( 1 )
    {
      v44 = *(_DWORD *)v38;
      if ( (*(_DWORD *)v38 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v44 & 0x40000000) == 0 )
      {
        do
          v67 = __ldrex((unsigned int *)v38);
        while ( v67 == v44 && __strex(v44 | 0x40000000, (unsigned int *)v38) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v36 = 0;
  }
  if ( v19 <= v104 )
  {
    v45 = v19 + 0x40000000;
    v101 = v19 + 0x40000000;
    do
    {
      if ( v39 && (v19 & 0xFFF) != 0 )
      {
        v46 = v91;
      }
      else
      {
        if ( v36 )
        {
          MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(v40, v36);
          v92 = 0;
        }
        v50 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        while ( 1 )
        {
          v51 = 2;
          v52 = &v106;
          v105[0] = ((v19 >> 10) & 0x3FFFFC) - 0x40000000;
          v105[1] = ((v105[0] >> 10) & 0x3FFFFC) - 0x40000000;
          while ( 1 )
          {
            v53 = (int *)*((_DWORD *)v52 - 1);
            v52 -= 4;
            --v51;
            v54 = *v53;
            if ( (*v53 & 2) == 0 )
              goto LABEL_151;
            if ( v51 <= 1 && (v54 & 0x400) != 0 )
              break;
            if ( !v51 )
              goto LABEL_76;
          }
          if ( !v51 )
          {
LABEL_151:
            v57 = 0;
            goto LABEL_82;
          }
LABEL_76:
          v55 = 2;
          do
          {
            while ( 1 )
            {
              v56 = (_DWORD *)v105[--v55];
              if ( (*v56 & 0x10) == 0 )
              {
                MI_WRITE_VALID_PTE_VOLATILE((unsigned int *)v105[v55], 1);
                KeFlushSingleCurrentTb((_DWORD)v56 << 10, v83, v84, v85);
              }
              if ( v55 == 1 )
                break;
              if ( !v55 )
                goto LABEL_81;
            }
          }
          while ( (*v56 & 0x400) == 0 );
LABEL_81:
          v57 = 1;
LABEL_82:
          if ( v57 )
            break;
          v62 = (unsigned int *)(v50 + 492);
          MiUnlockWorkingSetExclusive(v50 + 492, v97);
          v63 = MmAccessFault(-2147483647, v19, 0, 0);
          if ( v63 < 0 )
          {
            MmFlushAllFilesystemPages(1);
            KeBugCheckEx(122, 1, v63);
          }
          KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v50 + 492);
          }
          else
          {
            v64 = (unsigned __int8 *)(v50 + 495);
            do
              v65 = __ldrex(v64);
            while ( __strex(v65 | 0x80, v64) );
            __dmb(0xBu);
            if ( v65 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v50 + 492));
            while ( 1 )
            {
              v66 = *v62;
              if ( (*v62 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v66 & 0x40000000) == 0 )
              {
                do
                  v72 = __ldrex(v62);
                while ( v72 == v66 && __strex(v66 | 0x40000000, v62) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
        }
        v46 = v91;
        v45 = v101;
        v37 = v93;
        v40 = (_WORD *)(2 * ((v91 >> 22) - 534769440));
        v39 = 1;
      }
      v47 = *(_DWORD *)v19;
      if ( *(_DWORD *)v19 )
      {
        if ( (*(_DWORD *)v19 & 0x3E0) != 512 || (v47 & 2) != 0 || (v47 & 0x400) != 0 && (v47 & 0xFFFFE000) != -8192 )
        {
          v93 = v37 + 1;
          if ( !*a5 )
          {
            if ( (v47 & 3) == 0 && (v47 & 0x400) != 0 && (v47 & 0xFFFFE000) != -8192 )
            {
              v39 = 0;
              if ( v92 )
              {
                MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(v40, v92);
                v92 = 0;
              }
            }
            if ( v89 != MiGetPageProtection(a1, v19, v97, 1) )
              *a5 = 1;
          }
        }
        else
        {
          v48 = v47 & 0xFFFFFC1F | v96;
          if ( v45 > 0x3FFFFF )
          {
            *(_DWORD *)v19 = v48;
          }
          else
          {
            v49 = 0;
            __dmb(0xBu);
            *(_DWORD *)v19 = v48;
            if ( (v47 & 2) == 0 && (v48 & 2) != 0 )
              v49 = 1;
            if ( v19 >= 0xC0300000 && v19 <= 0xC0300FFF )
            {
              v87 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v87, v87 + 4 * (v19 & 0xFFF), v48);
            }
            if ( v49 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
      }
      else
      {
        if ( v19 <= v103 )
          v93 = v37 + 1;
        v92 = (unsigned __int16)(v92 + 1);
        if ( v45 > 0x3FFFFF )
        {
          *(_DWORD *)v19 = v96;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v19 = v96;
          if ( v19 >= 0xC0300000 && v19 <= 0xC0300FFF )
          {
            v86 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v86, v86 + 4 * (v19 & 0xFFF), v96);
          }
        }
      }
      v19 += 4;
      v45 += 4;
      v37 = v93;
      v91 = v46 + 4096;
      v36 = v92;
      v101 = v45;
    }
    while ( v19 <= v104 );
    v38 = v90 + 492;
    v41 = v97;
  }
  if ( v36 )
  {
    *v40 += v36;
    if ( v36 <= 1 && (unsigned int)(v40 + 534769440) <= 0x5FF )
      MiIsAddressValid((((int)(v40 + 534769440) >> 1) - 0x40000) << 12, 0);
  }
  if ( (*(_BYTE *)(v38 + 115) & 0x10) != 0 )
  {
    *(_BYTE *)(v38 + 115) &= 0xEFu;
    MiAgeWorkingSet(v38, v41, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
  }
  if ( (*(_BYTE *)(v38 + 115) & 0x20) != 0 )
  {
    v88 = *(_DWORD *)(v38 + 68);
    *(_BYTE *)(v38 + 115) &= 0xDFu;
    MiReduceWs(v38, v41, v88);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v38);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v38 = 0;
  }
  KfLowerIrql(v41);
  if ( v99 == 1 )
  {
    v58 = (unsigned int *)(v90 + 256);
    __dmb(0xBu);
    do
      v59 = __ldrex(v58);
    while ( __strex(v59 - 1, v58) );
    if ( (v59 & 2) != 0 && (v59 & 4) == 0 )
      ExfTryToWakePushLock(v90 + 256);
    KeAbPostRelease(v90 + 256);
    v60 = (__int16)(*(_WORD *)(v94 + 310) + 1);
    *(_WORD *)(v94 + 310) = v60;
    if ( !v60 && *(_DWORD *)(v94 + 100) != v94 + 100 )
      KiCheckForKernelApcDelivery(v94);
  }
  if ( v100 == 1 )
  {
    if ( v37 )
      MiReturnFullProcessCommitment(v90, v37);
    v61 = v102 - v37;
  }
  else
  {
    v61 = v98;
  }
  a1[8] = a1[8] & 0x80000000 | (v61 + a1[8]) & 0x7FFFFFFF;
  return 0;
}
