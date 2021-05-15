// PopCsStateChanged 
 
int __fastcall PopCsStateChanged(int a1)
{
  __int64 v2; // r0
  int v3; // r1
  unsigned int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  unsigned int v7; // r1
  __int16 v8; // r3

  PopAcquirePowerRequestPushLock(1);
  if ( a1 )
  {
    if ( PopExecutionRequiredTimeout )
    {
      LODWORD(v2) = KeQueryInterruptTime();
      *(_QWORD *)&PopLastCsEnterTime = v2;
      KiSetTimerEx(
        (int)&PopExecutionRequiredTimer,
        0,
        -(__int64)((unsigned int)PopExecutionRequiredTimeout * (unsigned __int64)(unsigned int)dword_989680),
        0,
        0,
        (int)&PopExecutionRequiredTimeoutDpc);
    }
  }
  else
  {
    PopLastCsEnterTime = 0;
    dword_61F824 = 0;
    PopExecutionTimeoutProcessed = 0;
    PopEnableExecutionRequiredPowerRequests(1);
  }
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v3 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) > 0x10 )
    v4 = PopPowerRequestLock - 16;
  else
    v4 = 0;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_18;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v5 == v3 && __strex(v4, (unsigned int *)&PopPowerRequestLock) );
  if ( v5 != v3 )
LABEL_18:
    ExfReleasePushLock(&PopPowerRequestLock, v3);
  result = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
