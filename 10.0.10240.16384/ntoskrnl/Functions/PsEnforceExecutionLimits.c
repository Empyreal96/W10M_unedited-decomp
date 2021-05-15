// PsEnforceExecutionLimits 
 
void PsEnforceExecutionLimits()
{
  unsigned int v0; // r0

  if ( PspJobTimeLimitsRequest )
  {
    if ( PspJobTimeLimitsCount )
    {
      if ( !--PspJobTimeLimitsCount )
      {
        __dmb(0xBu);
        do
          v0 = __ldrex(PspJobTimeLimitsWorkItemFlags);
        while ( __strex(v0 | 5, PspJobTimeLimitsWorkItemFlags) );
        __dmb(0xBu);
        if ( (v0 & 4) == 0 )
          ExQueueWorkItem(&PspJobTimeLimitsWorkItem, 1);
      }
    }
  }
}
