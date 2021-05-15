// KeFreezeExecution 
 
int __fastcall KeFreezeExecution(int a1, int a2)
{
  int v2; // r4
  int v3; // r0
  int v4; // r5
  unsigned int v6; // r2
  BOOL v7; // r4
  unsigned int v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r7
  int v15; // r8
  __int64 v16; // r0
  unsigned __int64 *v17; // r6
  __int64 v18; // kr10_8
  unsigned __int64 v19; // kr18_8
  unsigned __int64 v20; // kr20_8
  __int64 v21; // r2
  char v22; // r5
  int v23; // r4
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr28_8
  unsigned __int64 v26; // kr30_8
  __int64 v27; // r0
  int v28; // r9
  __int64 v29; // kr38_8
  int v30; // r10
  unsigned __int64 *v31; // r3
  unsigned __int64 v32; // kr40_8
  __int64 v33; // kr48_8
  unsigned __int64 *v34; // r5
  unsigned __int64 v35; // kr50_8
  unsigned __int64 v36; // kr58_8
  int v37; // r0
  int v38; // r5
  unsigned int v39; // r4
  unsigned int v40; // r2
  int v41; // r6
  unsigned __int64 v42; // r2
  __int64 v43; // kr60_8
  int v44; // r4
  int v45; // r0
  int v46; // r1
  __int64 v47; // kr68_8
  int v49; // r0
  unsigned int v50; // r2
  unsigned int v51; // r1
  unsigned int v52; // r4
  unsigned int v53; // r3
  bool v54; // cf
  unsigned int v55; // r1
  int v56; // r3
  int v57; // r0
  int v58; // r2
  int v59; // r1
  int i; // r1
  int v62; // [sp+4h] [bp-54h]
  __int64 v63; // [sp+8h] [bp-50h] BYREF
  int v64; // [sp+10h] [bp-48h]
  int v65; // [sp+14h] [bp-44h]
  unsigned int v66; // [sp+18h] [bp-40h]
  unsigned int v67; // [sp+20h] [bp-38h] BYREF
  _DWORD v68[2]; // [sp+28h] [bp-30h] BYREF
  int v69; // [sp+30h] [bp-28h]

  v64 = a1;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v2 = 0;
  }
  else
  {
    __disable_irq();
    v2 = 1;
  }
  v62 = v2;
  v3 = KfRaiseIrql(15);
  LODWORD(v63) = v3;
  KiFreezeFlag = 4;
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC08) & 0xF) != 4 )
  {
LABEL_4:
    v4 = 500000;
    do
    {
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_51BCC0(v3, 1);
      do
        v6 = __ldrex((unsigned int *)&KdDebuggerLock);
      while ( __strex(1u, (unsigned int *)&KdDebuggerLock) );
      __dmb(0xBu);
      v7 = v6 == 0;
      if ( !v6 )
        break;
      __dmb(0xAu);
      __yield();
      if ( KiFreezeExecutionLock )
      {
        v3 = KiIpiProcessRequests(v64, a2);
        if ( v3 )
          goto LABEL_4;
      }
      v3 = KeStallExecutionProcessor(4);
      --v4;
    }
    while ( v4 );
    v8 = 4 * (500000 - v4);
    if ( !v7 )
      v8 = 0;
LABEL_11:
    v9 = 300000;
    while ( 1 )
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v11 = KiTryToAcquireSpinLockInstrumented(&KiFreezeExecutionLock, 1);
      }
      else
      {
        do
          v10 = __ldrex((unsigned int *)&KiFreezeExecutionLock);
        while ( __strex(1u, (unsigned int *)&KiFreezeExecutionLock) );
        __dmb(0xBu);
        v11 = v10 == 0;
        if ( v10 )
        {
          __dmb(0xAu);
          __yield();
        }
      }
      if ( v11 )
      {
        v12 = KiFreezeFlag;
        goto LABEL_18;
      }
      if ( KiIpiProcessRequests(v64, a2) )
        goto LABEL_11;
      KeStallExecutionProcessor(10);
      if ( v9-- == 0 )
      {
        v9 = 300000;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          v49 = KiTryToAcquireSpinLockInstrumented(&KiFreezeLockBackup, 1);
        }
        else
        {
          do
            v50 = __ldrex((unsigned int *)&KiFreezeLockBackup);
          while ( __strex(1u, (unsigned int *)&KiFreezeLockBackup) );
          __dmb(0xBu);
          v49 = v50 == 0;
          if ( v50 )
          {
            __dmb(0xAu);
            __yield();
          }
        }
        if ( v49 == 1 )
          break;
      }
    }
    v12 = KiFreezeFlag | 1;
    KiFreezeFlag |= 1u;
LABEL_18:
    if ( v7 || (v12 & 1) == 0 )
      KdPortLocked = v7;
    else
      KiFreezeFlag = v12 | 8;
    if ( v8 > KdDebuggerLockMaxWaitTime )
      KdDebuggerLockMaxWaitTime = v8;
    v13 = (unsigned int)KeGetPcr();
    v14 = (v13 & 0xFFFFF000) + 1408;
    if ( !*(_BYTE *)((v13 & 0xFFFFF000) + 0x590) && !PoAllProcIntrDisabled )
    {
      v15 = *(_DWORD *)((v13 & 0xFFFFF000) + 0x584);
      *(_BYTE *)((v13 & 0xFFFFF000) + 0x590) = 1;
      LODWORD(v16) = ReadTimeStampCounter();
      v17 = (unsigned __int64 *)(v15 + 48);
      v18 = v16 - *(_QWORD *)(v14 + 2376);
      v19 = v18 + *(_QWORD *)(v15 + 48);
      __dmb(0xBu);
      do
        v20 = __ldrexd(v17);
      while ( __strexd(v19, v17) );
      __dmb(0xBu);
      v21 = v18 + *(unsigned int *)(v15 + 56);
      if ( HIDWORD(v21) )
      {
        v65 = 0;
        LODWORD(v21) = -1;
      }
      *(_QWORD *)(v14 + 2376) = v16;
      v22 = *(_BYTE *)(v15 + 2);
      *(_DWORD *)(v15 + 56) = v21;
      if ( (v22 & 0x3E) != 0 )
      {
        if ( (v22 & 0x10) != 0 )
        {
          v51 = *(_DWORD *)(v14 + 2376);
          v52 = v14 + 8 * *(unsigned __int8 *)(v15 + 84);
          v53 = *(_DWORD *)(v14 + 2384);
          v22 &= 0xEFu;
          v54 = v51 >= v53;
          v55 = v51 - v53;
          v56 = *(_DWORD *)(v52 + 2392);
          v57 = *(_DWORD *)(v14 + 2380) - (*(_DWORD *)(v14 + 2388) + !v54);
          v58 = *(_DWORD *)(v52 + 2396);
          *(_DWORD *)(v52 + 2392) = v56 + v55;
          *(_DWORD *)(v52 + 2396) = v57 + __CFADD__(v56, v55) + v58;
          *(_DWORD *)(v14 + 2384) = 0;
          *(_DWORD *)(v14 + 2388) = 0;
        }
        if ( (v22 & 0x3E) != 0 )
        {
          if ( (v22 & 0x20) != 0 )
          {
            v23 = *(_DWORD *)(v15 + 1084);
            if ( v23 )
            {
              v24 = (unsigned __int64 *)(v23 + 8 * (*(unsigned __int8 *)(v14 + 2986) + 2 * PoGetFrequencyBucket(v14)));
              v25 = v18 + *v24;
              __dmb(0xBu);
              do
                v26 = __ldrexd(v24);
              while ( __strexd(v25, v24) );
              __dmb(0xBu);
            }
            v22 &= 0xDFu;
          }
          if ( (v22 & 0x3E) != 0 )
          {
            v59 = *(_DWORD *)(v15 + 68);
            if ( v59 )
            {
              for ( i = v59 + *(_DWORD *)(v14 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += v18;
            }
            if ( (*(_BYTE *)(v15 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v14 + 2360) + 260) & *(_DWORD *)(v15 + 356)) != *(_DWORD *)(*(_DWORD *)(v14 + 2360) + 260) )
            {
              *(_QWORD *)(v14 + 2368) += v18;
            }
            if ( *(_DWORD *)(v15 + 236) )
              KiEndCounterAccumulation(v15);
          }
        }
      }
      LODWORD(v27) = ReadTimeStampCounter();
      v28 = HIDWORD(v27);
      v29 = v27 - *(_QWORD *)(v14 + 2376);
      v30 = v27;
      __dmb(0xBu);
      v31 = (unsigned __int64 *)(v14 + 2744);
      do
        v32 = __ldrexd(v31);
      while ( __strexd(v32 + v29, v31) );
      __dmb(0xBu);
      if ( (*(_BYTE *)(v15 + 2) & 0x20) != 0 )
      {
        v33 = v27 - *(_QWORD *)(v14 + 2376);
        v34 = (unsigned __int64 *)(v14 + 8 * (*(unsigned __int8 *)(v14 + 2986) + 2 * (PoGetFrequencyBucket(v14) + 1144)));
        v35 = *v34 + v33;
        __dmb(0xBu);
        do
          v36 = __ldrexd(v34);
        while ( __strexd(v35, v34) );
        __dmb(0xBu);
      }
      *(_DWORD *)(v14 + 2376) = v30;
      *(_DWORD *)(v14 + 2380) = v28;
      if ( (*(_BYTE *)(v15 + 2) & 0x10) != 0 )
      {
        *(_DWORD *)(v14 + 2384) = v30;
        *(_DWORD *)(v14 + 2388) = v28;
      }
      if ( (*(_BYTE *)(v15 + 2) & 2) != 0 )
        KiBeginCounterAccumulation(v15, 0);
      *(_BYTE *)(v14 + 16) = 0;
    }
    v37 = off_617A44(1, 0);
    KiClockLatencyMeasurementEnabled = 0;
    if ( (unsigned int)KeNumberProcessors_0 > 1 && !PoAllProcIntrDisabled )
    {
      KiFreezeOwner = v14;
      *(_DWORD *)(v14 + 1672) = 4;
      KiSetDebuggerOwner(v14);
      if ( PpmNonInterruptibleCount || !KiFreezeTimeout )
        v38 = 20000;
      else
        v38 = 20000 * KiFreezeTimeout;
      *(_DWORD *)(v14 + 1844) = 1;
      v68[0] = *(_DWORD *)&KeActiveProcessors;
      v68[1] = dword_681D74;
      v69 = dword_681D78[0];
      v69 = dword_681D78[0] & ~(1 << *(_DWORD *)(v14 + 20));
      KiSendFreeze(v68, (KiBugCheckActive & 3) != 3);
      v39 = v69;
LABEL_56:
      while ( v39 )
      {
        v40 = __clz(__rbit(v39));
        v39 &= ~(1 << v40);
        v66 = v40;
        v41 = (int)*(&KiProcessorBlock + v40);
        while ( *(_DWORD *)(v41 + 1672) != 2 )
        {
          if ( !v38 )
          {
            KiFreezeFlag |= 2u;
            goto LABEL_56;
          }
          KeStallExecutionProcessor(50);
          --v38;
        }
      }
      v37 = KiSetSafeToPowerDownFrozenProcessors(1);
    }
    KiOldIrql = v63;
    if ( RtlWriteTryAcquireTickLock(v37) )
    {
      KeQueryPerformanceCounter(&v63, &v67);
      if ( !v67 )
        __brkdiv0();
      v43 = (unsigned int)_rt_udiv64(v67, (v63 - MEMORY[0xFFFF9350]) * (unsigned int)dword_989680) + MEMORY[0xFFFF9008];
      HIDWORD(v42) = HIDWORD(v43);
      MEMORY[0xFFFF9010] = HIDWORD(v43);
      __dmb(0xBu);
      MEMORY[0xFFFF9008] = v43;
      __dmb(0xBu);
      MEMORY[0xFFFF900C] = HIDWORD(v43);
      v44 = KeMaximumIncrement;
      if ( KeMaximumIncrement )
      {
        LODWORD(v42) = v43;
        if ( !KeMaximumIncrement )
          __brkdiv0();
        v45 = _rt_udiv64((unsigned int)KeMaximumIncrement, v42);
        KiTickOffset = (v45 + 1) * v44 - v43;
        dword_690388 = v46;
        __dmb(0xBu);
        KeTickCount = v45;
        __dmb(0xBu);
        dword_690384 = v46;
        MEMORY[0xFFFF9328] = v46;
        __dmb(0xBu);
        MEMORY[0xFFFF9320] = v45;
        __dmb(0xBu);
        MEMORY[0xFFFF9324] = v46;
      }
      v47 = MEMORY[0xFFFF9340];
      __dmb(0xBu);
      MEMORY[0xFFFF9340] = v47 + 1;
    }
    v2 = v62;
  }
  return v2;
}
