// KeInitializeClock 
 
void __fastcall KeInitializeClock(int a1, int a2)
{
  int v2; // r8
  _DWORD *v3; // r1
  int v4; // r2
  _BYTE *v5; // r0
  _DWORD *v6; // r3
  __int64 v7; // [sp+8h] [bp-50h] BYREF
  int v8; // [sp+10h] [bp-48h]
  char v9[8]; // [sp+18h] [bp-40h] BYREF
  char v10[16]; // [sp+20h] [bp-38h] BYREF
  unsigned __int64 v11; // [sp+30h] [bp-28h]
  unsigned int v12; // [sp+38h] [bp-20h]

  if ( !a1 )
  {
    v5 = *(_BYTE **)(a2 + 120);
    qword_624FC8 = -1i64;
    qword_624FE8 = -1i64;
    if ( v5 && strstr(v5, "DISABLEDYNAMICTICK") )
      KiDynamicTickDisableReason = 1;
    off_617AE0(v10);
    if ( (v10[0] & 4) != 0 )
      KiClockTimerPerCpu = 1;
    if ( (v10[0] & 2) != 0 )
      KiClockTimerHighLatency = 1;
    if ( (v10[0] & 1) != 0 )
      KiClockTimerAlwaysOnPresent = 1;
    if ( !(_BYTE)KiDynamicTickDisableReason && (v10[0] & 8) == 0 )
      KiDynamicTickDisableReason = 2;
    KiSetupTimeIncrement(v11, v12);
    return;
  }
  if ( a1 != 1 )
  {
    if ( a1 != 2 )
      sub_96D718();
    if ( (_BYTE)KiDynamicTickDisableReason )
      PoTraceDynamicTickDisabled();
    return;
  }
  KeQueryPerformanceCounter(v9, &v7);
  KiClockStateUpdateTimeout = 5 * v7;
  *((_BYTE *)*(&KiProcessorBlock + KiClockTimerOwner) + 17) = 1;
  v2 = KfRaiseIrql(13);
  KiClockActive = 1;
  KiClockState = 0;
  off_617AEC();
  KiSetPendingTick(0);
  off_617AE8();
  ((void (__cdecl *)())off_617AE4)();
  ((void (__cdecl *)())off_617AF0)();
  KiSetPendingTick(1);
  v3 = (_DWORD *)KiClockIntervalRequests;
  v4 = 0;
  KeTimeIncrement = v8;
  KiLastRequestedTimeIncrement = KeMaximumIncrement;
  dword_625030 = KeMaximumIncrement;
  if ( !KiClockIntervalRequests )
    goto LABEL_23;
  while ( (unsigned int)KeMaximumIncrement >= v3[4] )
  {
    v6 = (_DWORD *)v3[1];
    if ( !v6 )
    {
      v4 = 1;
      goto LABEL_23;
    }
LABEL_25:
    v3 = v6;
  }
  v6 = (_DWORD *)*v3;
  if ( *v3 )
    goto LABEL_25;
  v4 = 0;
LABEL_23:
  RtlRbInsertNodeEx((unsigned int)&KiClockIntervalRequests, (unsigned int)v3, v4, KiDefaultClockIntervalRequest);
  byte_62502C = 1;
  KfLowerIrql(v2);
  dword_624FD0 = KeTimeIncrement;
  dword_624FD4 = KeTimeIncrement;
  dword_624FD8 = KiLastRequestedTimeIncrement;
  dword_624FDC = KiLastRequestedTimeIncrement;
}
