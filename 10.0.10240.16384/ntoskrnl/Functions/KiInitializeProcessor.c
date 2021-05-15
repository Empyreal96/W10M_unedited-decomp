// KiInitializeProcessor 
 
int __fastcall KiInitializeProcessor(int a1, int a2)
{
  int v4; // r7
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0
  __int64 v8; // r0
  int v9; // r0
  int v10; // r1
  unsigned int v11; // [sp+0h] [bp-38h]

  if ( KeThreadDpcEnable )
    return sub_6940D4(a1, a2, 0);
  if ( KeDpcWatchdogPeriod )
  {
    KeInitializeThreadedDpc(a1 + 3284, (int)KiDpcWatchdog, *(_DWORD *)(a1 + 20));
    *(_BYTE *)(a1 + 3285) = 2;
    *(_WORD *)(a1 + 3286) = *(_DWORD *)(a1 + 20) + 32;
    KeInitializeTimerEx((_DWORD *)(a1 + 3320), 0);
    v4 = KeMaximumIncrement;
    if ( !KeMaximumIncrement )
      __brkdiv0();
    LODWORD(v5) = _rt_udiv64(
                    (unsigned int)KeMaximumIncrement,
                    10000i64 * (unsigned int)KeDpcWatchdogPeriod + (unsigned int)KeMaximumIncrement - 1);
    if ( HIDWORD(v5) )
      v5 = 0xFFFFFFFFi64;
    *(_DWORD *)(a1 + 1856) = 0;
    *(_DWORD *)(a1 + 1852) = v5;
    LODWORD(v6) = _rt_udiv64(10000i64, v5 * (unsigned int)v4);
    v7 = v6 >> 1;
    if ( HIDWORD(v6) >> 1 )
      v7 = -1;
    HIDWORD(v8) = 250;
    v11 = v7;
    LODWORD(v8) = a1 + 3320;
    KeSetCoalescableTimer(v8, (unsigned int)-v4, v11, 0xFAu, a1 + 3284);
  }
  if ( KiDPCTimeout )
  {
    if ( !KeMaximumIncrement )
      __brkdiv0();
    v9 = _rt_udiv64(
           (unsigned int)KeMaximumIncrement,
           10000i64 * (unsigned int)KiDPCTimeout + (unsigned int)KeMaximumIncrement - 1);
    if ( v10 )
      v9 = -1;
    *(_DWORD *)(a1 + 2336) = v9;
  }
  return 0;
}
