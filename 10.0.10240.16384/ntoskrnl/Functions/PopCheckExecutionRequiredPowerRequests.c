// PopCheckExecutionRequiredPowerRequests 
 
int PopCheckExecutionRequiredPowerRequests()
{
  unsigned int v0; // r1
  __int64 v1; // r0
  unsigned __int64 v2; // kr00_8

  __dmb(0xBu);
  do
    v0 = __ldrex(PopExecutionRequiredWorkRequested);
  while ( __strex(0, PopExecutionRequiredWorkRequested) );
  __dmb(0xBu);
  LODWORD(v1) = PopAcquirePowerRequestPushLock(1);
  if ( byte_61EA54 )
  {
    if ( PopLastCsEnterTime )
    {
      if ( !PopExecutionTimeoutProcessed && PopExecutionRequiredTimeout != -1 )
      {
        v2 = (unsigned int)PopExecutionRequiredTimeout * (unsigned __int64)(unsigned int)dword_989680;
        LODWORD(v1) = KeQueryInterruptTime();
        if ( v1 - PopLastCsEnterTime >= v2 )
        {
          PopExecutionTimeoutProcessed = 1;
          LODWORD(v1) = PopEnableExecutionRequiredPowerRequests(0);
        }
      }
    }
  }
  return sub_7BF2CC(v1);
}
