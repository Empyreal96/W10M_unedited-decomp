// KeResumeClockTimerFromIdle 
 
void __fastcall KeResumeClockTimerFromIdle(_DWORD *a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  int v6; // r9
  int v7; // r1
  int v8; // r1
  unsigned int v9; // r5
  unsigned int v10; // r10
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  int v14; // r2
  unsigned int v15; // r3
  int v16; // [sp+8h] [bp-50h]
  char v17[8]; // [sp+10h] [bp-48h] BYREF
  unsigned __int64 v18; // [sp+18h] [bp-40h] BYREF
  int v19; // [sp+20h] [bp-38h]
  int v20; // [sp+24h] [bp-34h]
  int v21; // [sp+28h] [bp-30h] BYREF
  int v22; // [sp+2Ch] [bp-2Ch]
  int v23; // [sp+30h] [bp-28h]

  if ( (_BYTE)KiDynamicTickDisableReason )
    return;
  v16 = 0;
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( a1 )
    *a1 = -1;
  while ( 1 )
  {
    v3 = KiClockState;
    if ( KiClockState == 1 )
    {
      do
        v3 = __ldrex((unsigned int *)&KiClockState);
      while ( v3 == 1 && __strex(3u, (unsigned int *)&KiClockState) );
      __dmb(0xBu);
      if ( v3 == 1 )
        break;
    }
    if ( v3 != 3 )
      goto LABEL_51;
    KiPollFreezeExecution();
  }
  v4 = KiUpdateTimeAssist(0, &v18, &v21);
  v5 = HIDWORD(v18);
  v6 = v18;
  KiClockTimerOneShotEndTime = v18;
  if ( KiClockLatencyMeasurementEnabled )
  {
    if ( a1 )
    {
      if ( KiClockTimerOwner == *(_DWORD *)(v2 + 1428) && v18 >= KiClockTimerNextTickTime )
      {
        v4 = off_617AF4(v4);
        v5 = HIDWORD(v18);
        if ( v4 )
          *a1 = v6 - KiClockTimerNextTickTime;
      }
    }
    KiClockLatencyMeasurementEnabled = 0;
  }
  if ( a1
    && KiClockTimerOwner == *(_DWORD *)(v2 + 1428)
    && __PAIR64__(v5, v6) >= KiClockTimerNextTickTime
    && off_617AF4(v4) )
  {
    *a1 = v6 - KiClockTimerNextTickTime;
  }
  KiClockLatencyMeasurementEnabled = 0;
  if ( KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime < (unsigned __int64)qword_624FC8 )
    qword_624FC8 = KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime;
  v7 = qword_624FC0;
  if ( KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime > (unsigned __int64)qword_624FC0 )
    qword_624FC0 = KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime;
  if ( KiConsiderTimerRebasing )
  {
    KiAdjustTimersAfterDripsExit(v2 + 1408, v7);
    KiConsiderTimerRebasing = 0;
  }
  v8 = *(_DWORD *)(v2 + 1428);
  if ( !KiClockTimerPerCpu
    || (((unsigned int)dword_6217F8 >> v8) & 1) != 0
    || (!dword_6217F8 ? (v9 = -1) : (v9 = __clz(__rbit(dword_6217F8))), v9 == -1) )
  {
    v9 = *(_DWORD *)(v2 + 1428);
  }
  if ( v8 != v9 )
  {
    v16 = 1;
LABEL_37:
    v10 = 2;
    ++qword_624FB8;
    v11 = KiEventClockStateChange(2, 1, 0, 0);
    if ( v16 )
    {
      KiClockTimerOwner = v9;
      KiSendClockInterruptToClockOwner(v11);
    }
    v12 = HIDWORD(v18);
    goto LABEL_46;
  }
  v21 = KiClockTimerNextTickTime;
  if ( __PAIR64__(HIDWORD(v18), KiLastRequestedTimeIncrement) + (unsigned int)v6 > KiClockTimerNextTickTime )
    goto LABEL_37;
  if ( KiClockTimerPerCpu )
  {
    *(_BYTE *)(v2 + 1425) = 1;
    KiClockTimerOwner = v8;
    if ( !KiGetPendingTick() )
      off_617AE8();
  }
  v10 = 0;
  v21 = KiLastRequestedTimeIncrement;
  v22 = 0;
  off_617AF0(0);
  KiSetPendingTick(1);
  v12 = HIDWORD(v18);
  KiClockTimerNextTickTime = __PAIR64__(HIDWORD(v18), KeTimeIncrement) + (unsigned int)v6;
  KiEventClockStateChange(0, 1, v17, &v21);
LABEL_46:
  if ( (dword_682608 & 0x100000) != 0 )
  {
    LODWORD(v18) = &v21;
    HIDWORD(v18) = 0;
    v19 = 16;
    v20 = 0;
    v21 = v6;
    v22 = v12;
    v23 = KiClockTimerOwner;
    EtwTraceKernelEvent(&v18, 1, 1074790400, 3928, 1538);
  }
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&KiClockState);
  while ( __strex(v10, (unsigned int *)&KiClockState) );
  __dmb(0xBu);
LABEL_51:
  v14 = KiClockTimerOwner;
  if ( KiClockTimerOwner == *(_DWORD *)(v2 + 1428) && !*(_BYTE *)(v2 + 1425) )
    *(_BYTE *)(v2 + 1425) = 1;
  if ( *(_BYTE *)(v2 + 1425) )
  {
    v15 = KiClockTimerPerCpu ? ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 : *(&KiProcessorBlock + v14);
    if ( (*(_BYTE *)(v15 + 18) & 1) == 0 )
      off_617AE8();
  }
  if ( !*(_BYTE *)(v2 + 1425) && (*(_BYTE *)(v2 + 1426) & 1) != 0 )
  {
    ((void (__cdecl *)())off_617AEC)();
    KiSetPendingTick(0);
  }
}
