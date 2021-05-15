// KeAccumulateTicks 
 
int __fastcall KeAccumulateTicks(int a1, int a2, int a3, unsigned int a4, char a5)
{
  int result; // r0
  unsigned int v8; // r6
  unsigned int v9; // r8
  int v10; // r2
  char *v11; // r4
  int v12; // r1
  int v13; // r1
  unsigned __int16 *v14; // r2
  unsigned int v15; // lr
  unsigned __int64 v16; // kr10_8
  unsigned int v17; // r4
  unsigned __int64 v18; // kr18_8
  int v19; // r6
  int v20; // r2
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r2
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  int v28; // r2
  int v29; // r2
  int v30; // r2
  int v31; // r1
  int v32; // r3
  unsigned int v33; // r2
  unsigned int v34; // r3
  __int16 v35; // r2
  unsigned int v36; // r1
  unsigned int v37; // r2
  unsigned int v38; // r3
  int v39; // r3
  int v40; // r4
  int v41; // r3
  int v42; // r3
  __int16 v43; // r2
  int v44; // [sp+8h] [bp-58h]
  int v45; // [sp+8h] [bp-58h]
  int v47; // [sp+10h] [bp-50h]
  _DWORD v49[2]; // [sp+20h] [bp-40h] BYREF
  __int16 v50; // [sp+28h] [bp-38h]
  int v51[12]; // [sp+30h] [bp-30h] BYREF

  result = -28664;
  v8 = MEMORY[0xFFFF900C];
  __dmb(0xBu);
  v9 = MEMORY[0xFFFF9008];
  __dmb(0xBu);
  if ( v8 != MEMORY[0xFFFF9010] )
    return sub_541DFC(-28664, a2, -28660);
  if ( (*(_WORD *)(a1 + 1756) & 8) == 0 )
  {
    v10 = (v8 << 14) | (v9 >> 18);
    if ( KiSerializeTimerExpiration )
    {
      if ( !*(_BYTE *)(a1 + 17) )
        goto LABEL_18;
      v11 = (char *)KiProcessorBlock + 4096;
    }
    else
    {
      v11 = (char *)(a1 + 4096);
    }
    if ( v11 )
    {
      v12 = *(_DWORD *)(a1 + 1760);
      if ( (unsigned int)(v10 - v12) >= 0x100 )
        v10 = v12 + 255;
      result = 0;
      v13 = v12 - 1;
      while ( __PAIR64__(v8, v9) < *(_QWORD *)&v11[24 * (unsigned __int8)++v13 + 272] )
      {
        if ( v13 == v10 )
          goto LABEL_13;
      }
      result = 1;
LABEL_13:
      *(_DWORD *)(a1 + 1760) = v13;
      if ( result )
        goto LABEL_137;
      if ( *(_BYTE *)(a1 + 17) )
      {
        result = 0;
        do
          v18 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
        while ( !v18 && __strexd(0i64, (unsigned __int64 *)&KiNextTimer2DueTime) );
        if ( v18 <= __PAIR64__(v8, v9) )
        {
LABEL_137:
          __dmb(0xBu);
          v14 = (unsigned __int16 *)(a1 + 1756);
          do
            result = __ldrex(v14);
          while ( __strex(result | 8, v14) );
          __dmb(0xBu);
          if ( (result & 0x29) == 0 )
            result = HalRequestSoftwareInterrupt(2);
        }
      }
      goto LABEL_19;
    }
LABEL_18:
    *(_DWORD *)(a1 + 1760) = v10;
  }
LABEL_19:
  if ( !*(_BYTE *)(a1 + 17) )
    goto LABEL_26;
  v47 = 0;
  result = (__PAIR64__(v8, KeMaximumIncrement) + v9) >> 32;
  v15 = KeMaximumIncrement + v9;
  do
    v16 = __ldrexd(&KiTimer2Collections[5]);
  while ( !v16 && __strexd(0i64, &KiTimer2Collections[5]) );
  if ( KiClockIntervalIsSetForHighResolutionTimers && __PAIR64__(result, v15) <= v16 )
  {
    v45 = KfRaiseIrql(15);
    v39 = KiClockIntervalIsSetForHighResolutionTimers;
    __dmb(0xBu);
    if ( v39 )
    {
      KiResetClockInterval();
      __dmb(0xBu);
      KiClockIntervalIsSetForHighResolutionTimers = 0;
      v40 = 1;
      goto LABEL_107;
    }
  }
  else
  {
    if ( KiClockIntervalIsSetForHighResolutionTimers || v16 >= __PAIR64__(result, v15) )
      goto LABEL_26;
    v45 = KfRaiseIrql(15);
    v41 = KiClockIntervalIsSetForHighResolutionTimers;
    __dmb(0xBu);
    if ( !v41 )
    {
      KiSetClockInterval(KeMinimumIncrement, &KiHighResolutionTimerClockIntervalRequest);
      __dmb(0xBu);
      KiClockIntervalIsSetForHighResolutionTimers = 1;
      v40 = 1;
      v47 = KeMinimumIncrement;
      goto LABEL_107;
    }
  }
  v40 = 0;
LABEL_107:
  result = KfLowerIrql(v45);
  if ( v40 )
    result = PoTraceSystemTimerResolutionKernel(v47, 1834242632);
LABEL_26:
  if ( (dword_682608 & 0x40000) != 0 )
  {
    result = KeGetCurrentIrql(result);
    if ( result == 13 )
    {
      v42 = *(unsigned __int8 *)(a1 + 17);
      v43 = 0;
      v49[0] = v9;
      v49[1] = v8;
      v50 = 0;
      if ( v42 )
      {
        v43 = 1;
        v50 = 1;
      }
      if ( (*(_WORD *)(a1 + 1756) & 8) != 0 )
        v50 = v43 | 8;
      v51[0] = (int)v49;
      v51[1] = 0;
      v51[2] = 16;
      v51[3] = 0;
      result = EtwTraceKernelEvent(v51, 1, 1074003968, 3919, 4196866);
    }
  }
  *(_DWORD *)(a1 + 1764) = a3;
  v17 = a3 - a2;
  if ( a3 != a2 )
  {
    v19 = *(_DWORD *)(a1 + 4);
    if ( *(_BYTE *)(a1 + 17) )
    {
      if ( !--KiClockPollCycle )
      {
        KiClockPollCycle = KiClockKeepAliveCycle;
        v26 = (int)*(&KiProcessorBlock + (unsigned __int8)KiClockCheckSlot);
        v44 = (unsigned __int8)KiClockCheckSlot;
        v27 = (unsigned __int8)KiClockCheckSlot + 1;
        if ( v27 >= KeNumberProcessors_0 )
          LOBYTE(v27) = 0;
        v28 = *(_DWORD *)(v26 + 20);
        KiClockCheckSlot = v27;
        if ( (((unsigned int)dword_6162F8 >> v28) & 1) != 0 )
        {
          if ( (((unsigned int)dword_6162EC >> v28) & 1) != 0 )
          {
            dword_6162EC &= ~(1 << v28);
            dword_6162F8 &= ~(1 << v28);
            if ( !*(_DWORD *)(v26 + 1844) && KeEnableWatchdogTimeout && (KiBugCheckActive & 3) == 0 )
              KeBugCheck2(257, (unsigned __int8)KiClockKeepAliveCycle, 0, v26, v44, 0);
            *(_DWORD *)(v26 + 1844) = 0;
          }
          else
          {
            dword_6162EC |= 1 << v28;
          }
        }
      }
    }
    if ( a5 )
    {
      *(_DWORD *)(a1 + 2312) += v17;
      *(_DWORD *)(v19 + 448) += v17;
    }
    else
    {
      *(_DWORD *)(a1 + 2308) += v17;
      if ( *(_BYTE *)(a1 + 16) == 2 && *(_BYTE *)(a1 + 1754) )
      {
        v37 = *(_DWORD *)(a1 + 2336);
        *(_DWORD *)(a1 + 2316) += v17;
        v38 = *(_DWORD *)(a1 + 2332) + 1;
        *(_DWORD *)(a1 + 2332) = v38;
        if ( v38 > v37 && v37 )
        {
          if ( KeEnableWatchdogTimeout )
          {
            ReadTimeStampCounter();
            if ( !KdDebuggerEnabled )
              KeBugCheck2(307, 0, *(_DWORD *)(a1 + 2332), *(_DWORD *)(a1 + 2336), 0, 0);
            __assertfail();
          }
          *(_DWORD *)(a1 + 2332) = 0;
        }
      }
      else if ( *(unsigned __int8 *)(a1 + 16) > 1u )
      {
        *(_DWORD *)(a1 + 2320) += v17;
      }
      else
      {
        *(_DWORD *)(v19 + 404) += v17;
      }
      if ( a4 >= 2 )
      {
        v24 = *(_DWORD *)(a1 + 1852);
        v25 = *(_DWORD *)(a1 + 1856) + 1;
        *(_DWORD *)(a1 + 1856) = v25;
        if ( v25 < v24 || !v24 )
        {
LABEL_44:
          if ( v19 == *(_DWORD *)(a1 + 12) || *(unsigned __int8 *)(a1 + 16) > 1u )
          {
LABEL_45:
            if ( v17 >= 8 )
            {
              *(_DWORD *)(a1 + 1784) = 0;
            }
            else
            {
              *(_DWORD *)(a1 + 1784) += 15 * (*(_DWORD *)(a1 + 2304) - *(_DWORD *)(a1 + 1780));
              if ( v17 )
              {
                v20 = a3 - a2;
                do
                {
                  *(_DWORD *)(a1 + 1784) >>= 4;
                  --v20;
                }
                while ( v20 );
              }
            }
            v21 = *(_DWORD *)(a1 + 1740);
            v22 = *(_DWORD *)(a1 + 1748);
            *(_DWORD *)(a1 + 1780) = *(_DWORD *)(a1 + 2304);
            *(_DWORD *)(a1 + 1740) = (unsigned int)(v21 - v22 + *(_DWORD *)(a1 + 1696)) >> v17;
            *(_DWORD *)(a1 + 1748) = *(_DWORD *)(a1 + 1696);
            if ( !*(_DWORD *)(a1 + 1692) || (v35 = *(_WORD *)(a1 + 1756), (v35 & 3) != 0) )
            {
              v23 = *(_DWORD *)(a1 + 2324) - 1;
              *(_DWORD *)(a1 + 2324) = v23;
              if ( v23 )
                goto LABEL_51;
              v33 = *(_DWORD *)(a1 + 1736);
              *(_DWORD *)(a1 + 2324) = KiAdjustDpcThreshold;
              if ( v33 >= KiMaximumDpcQueueDepth )
                goto LABEL_51;
              v34 = v33 + 1;
            }
            else
            {
              *(_DWORD *)(a1 + 2324) = KiAdjustDpcThreshold;
              if ( (v35 & 0x2F) == 0 )
                HalRequestSoftwareInterrupt(2);
              v36 = *(_DWORD *)(a1 + 1736);
              if ( *(_DWORD *)(a1 + 1740) >= (unsigned int)KiIdealDpcRate || v36 <= 1 )
                goto LABEL_51;
              v34 = v36 - 1;
            }
            *(_DWORD *)(a1 + 1736) = v34;
LABEL_51:
            result = (unsigned __int8)KdEventLoggingEnabled;
            if ( (KdDebuggerEnabled || KdEventLoggingEnabled)
              && KiPollSlot == *(_DWORD *)(a1 + 20)
              && (!KdPitchDebugger && KdDebuggerEnabled || KdEventLoggingEnabled) )
            {
              result = KdPollBreakIn();
              if ( result )
                DbgBreakPointWithStatus();
            }
            return result;
          }
          if ( *(char *)(v19 + 123) < 16 )
          {
            if ( *(_DWORD *)(v19 + 68) )
            {
              v29 = *(_DWORD *)(v19 + 68);
              if ( v29 )
              {
                v30 = v29 + *(_DWORD *)(a1 + 2352);
                if ( v30 )
                {
                  if ( *(char *)(v19 + 123) < 16 && (*(_DWORD *)(v19 + 80) & 0x100) == 0 )
                  {
                    v31 = v30;
                    do
                    {
                      if ( (*(_BYTE *)(v31 + 92) & 2) != 0 )
                      {
                        v32 = -1;
                        goto LABEL_81;
                      }
                      v31 = *(_DWORD *)(v31 + 236);
                    }
                    while ( v31 );
                    while ( 1 )
                    {
                      v32 = *(_DWORD *)(v30 + 96);
                      if ( v32 )
                        goto LABEL_61;
                      v30 = *(_DWORD *)(v30 + 236);
                      if ( !v30 )
                        goto LABEL_81;
                    }
                  }
                  v32 = 0;
LABEL_81:
                  if ( v32 )
                  {
LABEL_61:
                    *(_DWORD *)(a1 + 2348) += v17;
                    goto LABEL_45;
                  }
                }
              }
            }
          }
          if ( *(char *)(v19 + 123) >= 8 )
            goto LABEL_45;
          goto LABEL_61;
        }
        if ( KeEnableWatchdogTimeout )
        {
          ReadTimeStampCounter();
          if ( !KdDebuggerEnabled )
            KeBugCheckEx(307, 1, *(_DWORD *)(a1 + 1852));
          __assertfail();
          JUMPOUT(0x541F12);
        }
      }
    }
    *(_DWORD *)(a1 + 1856) = 0;
    goto LABEL_44;
  }
  return result;
}
