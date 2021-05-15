// KeClockInterruptNotify 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeClockInterruptNotify(int a1, int a2)
{
  int v2; // r3
  BOOL v3; // r0
  char *v4; // r6
  int v5; // r2 OVERLAPPED
  int v6; // r1 OVERLAPPED
  int v7; // r8
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r6
  int v11; // r0
  unsigned int v12; // r6
  bool v13; // cf
  unsigned int v14; // r2
  int v15; // r5
  int v16; // r1
  unsigned int v17; // lr
  unsigned int v18; // r9
  int v19; // r1
  int v20; // r2
  void **v21; // r0
  int v22; // t1
  int v23; // r6
  int v24; // r3
  int v25; // r0
  int v26; // r5
  unsigned __int16 v27; // lr
  int *v28; // r3
  int v29; // r1
  unsigned int v30; // r5
  int v31; // lr
  int *v32; // r1
  unsigned int v33; // r0
  int v34; // r1
  int v35; // r4
  unsigned int v36; // r3
  int v37; // r4
  int v38; // r3
  int v39; // r8
  int v40; // r6
  int v41; // r3
  unsigned __int64 *v42; // r5
  __int64 v43; // r0 OVERLAPPED
  __int64 v44; // r2 OVERLAPPED
  unsigned __int64 v45; // kr00_8
  unsigned __int64 v46; // kr08_8
  int v47; // r0
  _DWORD *v48; // r5
  int v49; // r2
  int v50; // r1
  int v51; // r1
  int i; // r1
  unsigned int v53; // r3
  unsigned int v54; // r5
  int v55; // r6
  unsigned int v56; // r2
  __int64 v57; // r0
  int v58; // r3
  int v59; // r4
  int v60; // r3
  int v61; // r8
  int v62; // r7
  int v63; // r3
  unsigned __int64 *v64; // r6
  __int64 v65; // r0 OVERLAPPED
  __int64 v66; // r2 OVERLAPPED
  unsigned __int64 v67; // kr28_8
  unsigned __int64 v68; // kr30_8
  int v69; // r0
  _DWORD *v70; // r6
  int v71; // r2
  int v72; // r1
  unsigned int v73; // r3
  unsigned int v74; // r5
  int v76[2]; // [sp+8h] [bp-60h] BYREF
  unsigned int v77; // [sp+10h] [bp-58h] BYREF
  int v78; // [sp+14h] [bp-54h]
  int v79[2]; // [sp+18h] [bp-50h] BYREF
  BOOL v80; // [sp+20h] [bp-48h]
  unsigned int v81; // [sp+24h] [bp-44h]
  __int64 v82; // [sp+28h] [bp-40h] BYREF
  char v83[8]; // [sp+30h] [bp-38h] BYREF
  int v84; // [sp+38h] [bp-30h] BYREF
  int v85; // [sp+3Ch] [bp-2Ch]
  int v86; // [sp+40h] [bp-28h]

  v76[0] = a2;
  v2 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x591);
  v3 = (*(_DWORD *)(a1 + 132) & 0x1F) != 19;
  v80 = v3;
  if ( v2 )
  {
    v4 = (char *)&KiClockTickTraces + 24 * KiClockTickTraceIndex;
    KiClockTickTraceIndex = ((_BYTE)KiClockTickTraceIndex + 1) & 0xF;
    v79[0] = (int)v4;
    v5 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v6 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    while ( v5 != MEMORY[0xFFFF9010] )
    {
      __dmb(0xAu);
      __yield();
      v5 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v6 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
    }
    *((_QWORD *)v4 + 1) = *(_QWORD *)&v6;
    v7 = 0;
    v8 = dword_690384;
    v81 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    __dmb(0xBu);
    v9 = KeTickCount;
    __dmb(0xBu);
    while ( v8 != dword_690388 )
    {
      __dmb(0xAu);
      __yield();
      v8 = dword_690384;
      __dmb(0xBu);
      v9 = KeTickCount;
      __dmb(0xBu);
    }
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v10 = 0;
    }
    else
    {
      __disable_irq();
      v10 = 1;
    }
    v11 = KiUpdateTimeAssist(0, &v82, &v77);
    if ( v10 )
      __enable_irq();
    v12 = v77;
    v13 = v77 >= v9;
    v14 = v77 - v9;
    v15 = v78;
    v16 = 0;
    if ( (v78 != v8 + !v13 || v14) && !--KiBalanceSetManagerCount )
    {
      KiBalanceSetManagerCount = KiBalanceSetManagerPeriod;
      v11 = KiInsertQueueDpc((int)&KiBalanceSetManagerPeriodicDpc, 0, 0, 0, 0);
    }
    PoExecutePerfCheck(v11, v16);
    v17 = v82 >> 18;
    HIDWORD(v82) >>= 18;
    v77 = v17;
    if ( KiGroupSchedulingEnabled && __PAIR64__(v15, v12) > KiGenerationEndTick )
    {
      v7 = 1;
      KiGenerationEndTick += (unsigned int)KiGenerationTicks;
    }
    v18 = KeNumberProcessors_0;
    LODWORD(v82) = KeNumberProcessors_0;
    if ( (unsigned int)KeNumberProcessors_0 <= 1 )
      goto LABEL_44;
    if ( PoDisableSkipTick )
      goto LABEL_35;
    v19 = (unsigned __int16)KeNumberNodes;
    v20 = 0;
    if ( !KeNumberNodes )
      goto LABEL_35;
    v21 = &KeNodeBlock;
    do
    {
      v22 = (int)*v21++;
      v20 |= *(_DWORD *)(v22 + 128);
      --v19;
    }
    while ( v19 );
    if ( !v20 )
      goto LABEL_35;
    v84 = 65537;
    v23 = dword_681D78[0] & ~v20;
    v85 = 0;
    v86 = v23;
    if ( v7 )
    {
      v23 |= dword_6162DC;
      v84 = 65537;
      v85 = 0;
      v86 = v23;
    }
    if ( !KiSerializeTimerExpiration )
    {
      v24 = 0;
      v25 = 0;
      v26 = (unsigned __int8)v17;
      v27 = 0;
      do
      {
        v28 = &KiPendingTimerBitmaps[2 * v24];
        LOBYTE(v29) = KiLastForwardedHand - 1;
        do
        {
          v29 = (unsigned __int8)(v29 + 1);
          v25 |= *(_DWORD *)((v29 << 7) + v28[1]);
        }
        while ( v29 != v26 );
        v24 = ++v27;
      }
      while ( v27 < (unsigned int)(unsigned __int16)KiActiveGroups );
      v84 = 65537;
      v23 |= v25;
      v18 = v82;
      v85 = 0;
      v86 = v23;
    }
    if ( v23 == dword_681D78[0] )
    {
LABEL_35:
      v32 = 0;
      v31 = 1;
      v84 = *(_DWORD *)&KeActiveProcessors;
      v85 = dword_681D74;
      v86 = dword_681D78[0];
      v30 = v81;
    }
    else
    {
      v30 = v81;
      v31 = 0;
      v32 = &v84;
      v33 = v23 & ~(1 << *(_DWORD *)(v81 + 20));
      v86 = v33;
      if ( !v33 )
      {
LABEL_37:
        if ( KdDebuggerEnabled )
        {
          v34 = KiPollSlotNext;
          KiPollSlot = KiPollSlotNext++;
          if ( KiPollSlotNext >= v18 )
            KiPollSlotNext = 0;
          if ( v34 != *(_DWORD *)(v30 + 20) && ((v33 >> v34) & 1) == 0 )
            KiPollSlot = *(_DWORD *)(v30 + 20);
        }
        word_6162F2 = 1;
        KiClockCheckPending = 1;
        *(_DWORD *)algn_6162F4 = 0;
        dword_6162F8 |= v33;
LABEL_44:
        v35 = *((_DWORD *)KiProcessorBlock + 258);
        if ( v35 )
        {
          *((_DWORD *)KiProcessorBlock + 258) = 0;
          __dmb(0xFu);
          KeQuerySystemTime(&v77);
          KiInsertQueueDpc(v35, v77, v78, 0, 0);
        }
        v36 = (unsigned int)KeGetPcr();
        v37 = (v36 & 0xFFFFF000) + 1408;
        ++*(_DWORD *)(v37 + 1768);
        *(_DWORD *)(v37 + 1780) = *(_DWORD *)((v36 & 0xFFFFF000) + 0xC74) + 1;
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v38 = 0;
        }
        else
        {
          __disable_irq();
          v38 = 1;
        }
        v39 = KeTickCount;
        if ( v38 )
          __enable_irq();
        KeAccumulateTicks(v37, *(_DWORD *)(v37 + 1764), KeTickCount, v76[0], v80);
        v40 = *(_DWORD *)(v37 + 4);
        v41 = *(_DWORD *)(v37 + 12);
        *(_DWORD *)(v37 + 1844) = 1;
        if ( v40 != v41 )
        {
          v42 = (unsigned __int64 *)(v40 + 48);
          *(__int64 *)((char *)&v43 + 4) = *(_QWORD *)(v40 + 48);
          do
          {
            v45 = __ldrexd(v42);
            LODWORD(v43) = HIDWORD(v45);
            HIDWORD(v44) = v45;
          }
          while ( v44 == v43 && __strexd(__PAIR64__(v44, HIDWORD(v43)), v42) );
          while ( v43 != v44 )
          {
            __dmb(0xAu);
            __yield();
            *(__int64 *)((char *)&v43 + 4) = *v42;
            do
            {
              v46 = __ldrexd(v42);
              LODWORD(v43) = HIDWORD(v46);
              HIDWORD(v44) = v46;
            }
            while ( v44 == v43 && __strexd(__PAIR64__(v44, HIDWORD(v43)), v42) );
          }
          if ( __PAIR64__(v44, HIDWORD(v43)) >= *(_QWORD *)(v40 + 24) )
            goto LABEL_81;
          if ( *(_BYTE *)(v40 + 85) )
          {
            v47 = KiGetHeteroCpuPolicyThread(v40, v37);
            v48 = *(_DWORD **)(v37 + 2360);
            KiGenerateHeteroSets(v48, *(_DWORD *)(v40 + 356), v47, v76, &v77);
            if ( (*(_DWORD *)(v37 + 1048) & v76[0]) == 0 && (v76[0] & *v48) != 0 )
              goto LABEL_81;
          }
        }
        v49 = dword_690384;
        __dmb(0xBu);
        v50 = KeTickCount;
        __dmb(0xBu);
        while ( v49 != dword_690388 )
        {
          __dmb(0xAu);
          __yield();
          v49 = dword_690384;
          __dmb(0xBu);
          v50 = KeTickCount;
          __dmb(0xBu);
        }
        if ( __PAIR64__(v49, v50) > *(_QWORD *)(v37 + 2408) )
        {
LABEL_81:
          *(_BYTE *)(v37 + 1753) = 1;
          HalRequestSoftwareInterrupt(2);
        }
        else
        {
          v51 = *(_DWORD *)(v40 + 68);
          if ( v51 )
          {
            for ( i = v51 + *(_DWORD *)(v37 + 2352); i; i = *(_DWORD *)(i + 236) )
            {
              if ( (*(_BYTE *)(i + 92) & 4) != 0 )
              {
                if ( (*(_BYTE *)(i + 92) & 0x10) == 0 && *(_QWORD *)i > *(_QWORD *)(i + 16) )
                  goto LABEL_81;
                v53 = *(_DWORD *)(i + 28);
                v54 = *(_DWORD *)(i + 24);
              }
              else
              {
                v53 = *(_DWORD *)(i + 12);
                v54 = *(_DWORD *)(i + 8);
              }
              if ( *(_QWORD *)i > __PAIR64__(v53, v54) )
                goto LABEL_81;
            }
          }
          if ( *(_DWORD *)(v37 + 1772) - v39 < 0
            && (!KiShouldScanSharedReadyQueue(v37) || (*(_DWORD *)(*(_DWORD *)(v37 + 3460) + 4) & 0x7FFE) == 0)
            && (*(_DWORD *)(v37 + 1932) & 0x7FFE) == 0 )
          {
            *(_DWORD *)(v37 + 1772) = v39 + 75;
          }
        }
        v55 = v79[0];
        *(_DWORD *)v79[0] = MEMORY[0xFFFF9350];
        *(_DWORD *)(v55 + 4) = MEMORY[0xFFFF9354];
        if ( KiClockState == 2 )
        {
          v79[0] = KiLastRequestedTimeIncrement;
          v79[1] = 0;
          off_617AF0(0);
          KiSetPendingTick(1);
          __dmb(0xBu);
          do
            v56 = __ldrex((unsigned int *)&KiClockState);
          while ( __strex(0, (unsigned int *)&KiClockState) );
          __dmb(0xBu);
          KiEventClockStateChange(0, 2, v83, v79);
        }
        HIDWORD(v57) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v57) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        while ( HIDWORD(v57) != MEMORY[0xFFFF9010] )
        {
          __dmb(0xAu);
          __yield();
          HIDWORD(v57) = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          LODWORD(v57) = MEMORY[0xFFFF9008];
          __dmb(0xBu);
        }
        v58 = KeTimeIncrement;
        *(_QWORD *)(v55 + 16) = v57;
        KiClockTimerNextTickTime = v57 + (unsigned int)v58;
        return v57;
      }
    }
    HalRequestClockInterrupt(v31, v32);
    v33 = v86;
    KiLastForwardedHand = v77;
    goto LABEL_37;
  }
  v59 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  ++*(_DWORD *)(v59 + 1768);
  ++*(_DWORD *)(v59 + 1780);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v60 = 0;
  }
  else
  {
    __disable_irq();
    v60 = 1;
  }
  v61 = KeTickCount;
  if ( v60 )
    __enable_irq();
  KeAccumulateTicks(v59, *(_DWORD *)(v59 + 1764), KeTickCount, a2, v3);
  v62 = *(_DWORD *)(v59 + 4);
  v63 = *(_DWORD *)(v59 + 12);
  *(_DWORD *)(v59 + 1844) = 1;
  if ( v62 != v63 )
  {
    v64 = (unsigned __int64 *)(v62 + 48);
    *(__int64 *)((char *)&v65 + 4) = *(_QWORD *)(v62 + 48);
    do
    {
      v67 = __ldrexd(v64);
      LODWORD(v65) = HIDWORD(v67);
      HIDWORD(v66) = v67;
    }
    while ( v66 == v65 && __strexd(__PAIR64__(v66, HIDWORD(v65)), v64) );
    while ( v65 != v66 )
    {
      __dmb(0xAu);
      __yield();
      *(__int64 *)((char *)&v65 + 4) = *v64;
      do
      {
        v68 = __ldrexd(v64);
        LODWORD(v65) = HIDWORD(v68);
        HIDWORD(v66) = v68;
      }
      while ( v66 == v65 && __strexd(__PAIR64__(v66, HIDWORD(v65)), v64) );
    }
    if ( __PAIR64__(v66, HIDWORD(v65)) >= *(_QWORD *)(v62 + 24) )
      goto LABEL_124;
    if ( *(_BYTE *)(v62 + 85) )
    {
      v69 = KiGetHeteroCpuPolicyThread(v62, v59);
      v70 = *(_DWORD **)(v59 + 2360);
      KiGenerateHeteroSets(v70, *(_DWORD *)(v62 + 356), v69, v79, v76);
      if ( (v79[0] & *(_DWORD *)(v59 + 1048)) == 0 && (v79[0] & *v70) != 0 )
        goto LABEL_124;
    }
  }
  v71 = dword_690384;
  __dmb(0xBu);
  HIDWORD(v57) = KeTickCount;
  __dmb(0xBu);
  while ( v71 != dword_690388 )
  {
    __dmb(0xAu);
    __yield();
    v71 = dword_690384;
    __dmb(0xBu);
    HIDWORD(v57) = KeTickCount;
    __dmb(0xBu);
  }
  LODWORD(v57) = *(_DWORD *)(v59 + 2408);
  if ( __PAIR64__(v71, HIDWORD(v57)) > *(_QWORD *)(v59 + 2408) )
  {
LABEL_124:
    *(_BYTE *)(v59 + 1753) = 1;
    LODWORD(v57) = HalRequestSoftwareInterrupt(2);
  }
  else
  {
    v72 = *(_DWORD *)(v62 + 68);
    if ( v72 )
    {
      for ( HIDWORD(v57) = v72 + *(_DWORD *)(v59 + 2352); HIDWORD(v57); HIDWORD(v57) = *(_DWORD *)(HIDWORD(v57) + 236) )
      {
        if ( (*(_BYTE *)(HIDWORD(v57) + 92) & 4) != 0 )
        {
          if ( (*(_BYTE *)(HIDWORD(v57) + 92) & 0x10) == 0 && *(_QWORD *)HIDWORD(v57) > *(_QWORD *)(HIDWORD(v57) + 16) )
            goto LABEL_124;
          v73 = *(_DWORD *)(HIDWORD(v57) + 28);
          v74 = *(_DWORD *)(HIDWORD(v57) + 24);
        }
        else
        {
          v73 = *(_DWORD *)(HIDWORD(v57) + 12);
          v74 = *(_DWORD *)(HIDWORD(v57) + 8);
        }
        LODWORD(v57) = *(_DWORD *)HIDWORD(v57);
        if ( *(_QWORD *)HIDWORD(v57) > __PAIR64__(v73, v74) )
          goto LABEL_124;
      }
    }
    if ( *(_DWORD *)(v59 + 1772) - v61 < 0 )
    {
      LODWORD(v57) = KiShouldScanSharedReadyQueue(v59);
      if ( (!(_DWORD)v57 || (*(_DWORD *)(*(_DWORD *)(v59 + 3460) + 4) & 0x7FFE) == 0)
        && (*(_DWORD *)(v59 + 1932) & 0x7FFE) == 0 )
      {
        *(_DWORD *)(v59 + 1772) = v61 + 75;
      }
    }
  }
  return v57;
}
