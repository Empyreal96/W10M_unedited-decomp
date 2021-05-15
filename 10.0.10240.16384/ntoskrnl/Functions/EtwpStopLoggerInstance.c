// EtwpStopLoggerInstance 
 
int __fastcall EtwpStopLoggerInstance(unsigned int a1)
{
  int v2; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  BOOL v6; // r0
  unsigned int v7; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1

  *(_DWORD *)(a1 + 608) |= 0x40u;
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v2 = KeReleaseMutex((int)&EtwpNotificationMutex);
  if ( (*(_DWORD *)(a1 + 12) & 0x2000000) != 0 )
    return sub_7EE1BC(v2);
  if ( (*(_DWORD *)(a1 + 608) & 0x20) == 0 )
    EtwpDisableTraceProviders(*(_DWORD *)a1);
  if ( (*(_DWORD *)(a1 + 12) & 0x400) == 0 )
  {
    if ( (*(_DWORD *)(a1 + 608) & 0x800) != 0 )
      EtwpLogPmcCounterRundown(a1, *(_DWORD *)a1);
    if ( (*(_DWORD *)(a1 + 608) & 0x1000000) != 0 )
      EtwpStackRundown(*(_DWORD *)(a1 + 624), *(_DWORD *)a1);
  }
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 248);
  do
    v5 = __ldrex(v4);
  while ( __strex(0, v4) );
  __dmb(0xBu);
  if ( !v5 )
    return -2147483611;
  WmipLoggerContext[*(_DWORD *)a1] = a1 | 1;
  v6 = KeAreInterruptsEnabled();
  if ( v6 )
    v7 = KeGetCurrentIrql(v6);
  else
    v7 = 15;
  if ( v7 > 2 )
  {
    __dmb(0xBu);
    v8 = (unsigned __int8 *)(a1 + 613);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 1, v8) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
    {
      *(_WORD *)(a1 + 442) = KiClockTimerOwner + 32;
      KeInsertQueueDpc(a1 + 440);
    }
  }
  else
  {
    KeSetEvent(a1 + 372, 0, 0);
  }
  EtwpSendSessionNotification((_DWORD *)a1, 2, 0);
  return 0;
}
