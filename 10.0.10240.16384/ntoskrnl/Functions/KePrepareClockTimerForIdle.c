// KePrepareClockTimerForIdle 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall KePrepareClockTimerForIdle(int *result, unsigned __int64 a2, char a3)
{
  unsigned int v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // lr
  unsigned int v11; // r2
  __int64 v12; // r0
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // lr
  int v16; // r1
  unsigned __int64 v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r2
  char *v20; // kr08_4
  int v21; // r8
  int v22; // r0
  int v23; // r9 OVERLAPPED
  unsigned int v24; // r10 OVERLAPPED
  unsigned int v25; // r7
  int v26; // r3
  unsigned int v27; // r2
  int v28; // r3
  unsigned int v29; // r2
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r0
  unsigned int v33; // [sp+10h] [bp-58h] BYREF
  unsigned int v34; // [sp+14h] [bp-54h]
  unsigned int v35; // [sp+18h] [bp-50h]
  int v36; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v37; // [sp+20h] [bp-48h]
  int *v38; // [sp+24h] [bp-44h]
  unsigned __int64 v39; // [sp+28h] [bp-40h] BYREF
  __int64 v40; // [sp+30h] [bp-38h] BYREF
  unsigned __int64 v41; // [sp+38h] [bp-30h] BYREF
  int v42; // [sp+40h] [bp-28h]
  int v43; // [sp+44h] [bp-24h]

  v40 = 0i64;
  v38 = result;
  v5 = 0;
  v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (_BYTE)KiDynamicTickDisableReason )
    return result;
  if ( a2 <= (unsigned int)KiLastRequestedTimeIncrement )
  {
    v5 = 2;
LABEL_4:
    v33 = v5;
    if ( (dword_682608 & 0x100000) != 0 )
    {
      v41 = (unsigned int)&v33;
      v42 = 1;
      v43 = 0;
      result = (int *)EtwTraceKernelEvent(&v41, 1, 1074790400, 3929, 1538);
    }
    return result;
  }
  if ( a2 > KiMaxDynamicTickDuration )
    return (int *)sub_542318(result, HIDWORD(KiMaxDynamicTickDuration), &KiClockStats, KiMaxDynamicTickDuration);
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&KiClockState);
  while ( __strex(3u, (unsigned int *)&KiClockState) );
  v34 = v7;
  __dmb(0xBu);
  result = (int *)PoAllProcessorsDeepIdle(3, &KiClockState);
  if ( !result )
  {
    v5 = 1;
    goto LABEL_60;
  }
  v8 = KeQueryInterruptTime();
  v10 = v9;
  v35 = v9;
  v33 = v8;
  v11 = v8;
  HIDWORD(v12) = 1;
  LODWORD(v12) = v6 + 1408;
  KiGetNextTimerExpirationDueTime(v12, v11, v10, (unsigned __int8)v38, (unsigned int *)&v39, &v36);
  result = (int *)HIDWORD(v39);
  if ( a3 )
  {
    v30 = RtlGetInterruptTimePrecise(&v41);
    v15 = v31;
    v35 = v31;
    v16 = v30;
    v36 = v30;
    goto LABEL_40;
  }
  if ( v39 <= __PAIR64__(v35, v33) + (unsigned int)KiLastRequestedTimeIncrement )
  {
    v5 = 2;
    goto LABEL_60;
  }
  if ( !v38 && KiClockTimerHighLatency )
  {
    v28 = KiClockTimerOneShotEndTime;
    v36 = KiClockTimerOneShotEndTime;
    if ( KiClockTimerOneShotStartTime )
    {
      if ( (unsigned __int64)(KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime) >= 0x2710 )
        v29 = KiDynamicTickCancellations;
      else
        v29 = ++KiDynamicTickCancellations;
      KiClockTimerOneShotStartTime = 0i64;
      v28 = v36;
    }
    else
    {
      v29 = KiDynamicTickCancellations;
    }
    result = (int *)(v33 - v28);
    if ( __PAIR64__(v35, v33) - __PAIR64__(HIDWORD(KiClockTimerOneShotEndTime), v28) >= (unsigned int)KeMaximumIncrement )
    {
      KiDynamicTickCancellations = 0;
      goto LABEL_17;
    }
    if ( v29 <= 3 )
      goto LABEL_17;
    v5 = 3;
LABEL_60:
    v25 = v34;
    goto LABEL_34;
  }
LABEL_17:
  v13 = RtlGetInterruptTimePrecise(&v41);
  v15 = v14;
  v35 = v14;
  v16 = v13;
  result = (int *)HIDWORD(v39);
  v17 = __PAIR64__(v15, KiLastRequestedTimeIncrement) + (unsigned int)v16;
  v36 = v16;
  if ( HIDWORD(v39) > HIDWORD(v17) )
  {
LABEL_40:
    result = (int *)v39;
    goto LABEL_20;
  }
  if ( HIDWORD(v39) < HIDWORD(v17) )
    goto LABEL_59;
  result = (int *)v39;
  if ( (unsigned int)v39 <= (unsigned int)v17 )
    goto LABEL_59;
LABEL_20:
  if ( __PAIR64__(HIDWORD(v39), (unsigned int)result) <= __PAIR64__(v15, KiMinDynamicTickDuration) + (unsigned int)v16 )
  {
LABEL_59:
    v5 = 4;
    goto LABEL_60;
  }
  v37 = (unsigned int)result - v16;
  v20 = (char *)result - v16;
  v18 = (__PAIR64__(HIDWORD(v39), (unsigned int)result) - __PAIR64__(v15, v16)) >> 32;
  v19 = (unsigned int)v20;
  v33 = v18;
  v41 = __PAIR64__(v18, (unsigned int)v20);
  if ( __PAIR64__(v18, (unsigned int)v20) > a2 )
  {
    v18 = HIDWORD(a2);
    v33 = HIDWORD(a2);
    v19 = a2;
    v37 = a2;
    v41 = a2;
  }
  v21 = (int)v38;
  if ( a3 && !v38 && (v18 || v19 > KiClockLatencyMaxDynamicTickDuration) )
  {
    v37 = KiClockLatencyMaxDynamicTickDuration;
    v33 = 0;
    v41 = (unsigned int)KiClockLatencyMaxDynamicTickDuration;
  }
  if ( off_617AF0(1) < 0 )
  {
    off_617AF0(0);
    v32 = KiSetPendingTick(1);
    v5 = 5;
    KiDynamicTickDisableReason = 2;
    result = (int *)PoTraceDynamicTickDisabled(v32);
    v25 = v34;
    v24 = v35;
    v23 = v36;
  }
  else
  {
    v22 = KiSetPendingTick(1);
    v24 = v35;
    v23 = v36;
    KiClockTimerOneShotStartTime = *(_QWORD *)&v23;
    KiEventClockStateChange(v22, v34, &v40, &v41);
    if ( a3 )
      KiClockLatencyMeasurementEnabled = 1;
    result = &KiClockStats;
    v25 = 1;
    v26 = dword_624FB0;
    *(_BYTE *)(v6 + 1425) = 0;
    dword_624FB0 = v26 + 1;
    dword_624FB4 += __CFADD__(v26, 1);
    if ( __PAIR64__(v33, v37) < qword_624FE8 )
    {
      LODWORD(qword_624FE8) = v37;
      HIDWORD(qword_624FE8) = v33;
    }
    if ( __PAIR64__(v33, v37) > qword_624FE0 )
    {
      LODWORD(qword_624FE0) = v37;
      HIDWORD(qword_624FE0) = v33;
    }
    if ( v21 )
      KiConsiderTimerRebasing = 1;
  }
  KiClockTimerNextTickTime = v40 + __PAIR64__(v24, v23);
LABEL_34:
  if ( v25 != 4 )
  {
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&KiClockState);
    while ( __strex(v25, (unsigned int *)&KiClockState) );
    __dmb(0xBu);
  }
  if ( v5 )
    goto LABEL_4;
  return result;
}
