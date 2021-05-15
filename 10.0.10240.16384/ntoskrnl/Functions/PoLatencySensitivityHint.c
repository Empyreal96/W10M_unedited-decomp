// PoLatencySensitivityHint 
 
void PoLatencySensitivityHint()
{
  int v0; // r2
  int v1; // r0
  __int64 v2; // r0
  __int64 v3; // kr08_8
  unsigned __int64 v4; // kr10_8
  __int64 v5; // kr18_8
  unsigned __int64 v6; // r2
  int *v7; // r2
  int v8; // r0
  unsigned int v9; // r1

  v0 = 0;
  while ( !*((_BYTE *)&PpmCurrentProfile[44 * dword_61EC0C + 24] + v0 + 1) )
  {
    if ( (unsigned int)++v0 >= 2 )
      return;
  }
  v1 = PpmEventTraceLatencySensitivityHint();
  v2 = KeQueryInterruptTime(v1);
  v3 = PpmPerfLatencyBoostExpiration;
  v4 = v2 + PpmCheckPeriod;
  if ( PpmPerfLatencyBoostExpiration < (unsigned __int64)(v2 + PpmCheckPeriod) )
  {
    v5 = PpmPerfLatencyBoostExpiration;
    do
      v6 = __ldrexd((unsigned __int64 *)&PpmPerfLatencyBoostExpiration);
    while ( v6 == v3 && __strexd(v4, (unsigned __int64 *)&PpmPerfLatencyBoostExpiration) );
    if ( v5 == v6 )
    {
      __dmb(0xFu);
      if ( v6 <= PpmCheckLastExecutionTime )
      {
        if ( PpmTryAcquireLock() )
        {
          v7 = (int *)PpmPerfDomainHead;
          if ( (int *)PpmPerfDomainHead != &PpmPerfDomainHead )
          {
            v8 = dword_61749C;
            do
            {
              v8 |= 1 << *(_DWORD *)(v7[2] + 20);
              dword_61749C = v8;
              v7 = (int *)*v7;
            }
            while ( v7 != &PpmPerfDomainHead );
          }
          PpmCheckCustomRun(3);
        }
        else
        {
          do
            v9 = __ldrex((unsigned int *)&PpmPerfLatencyBoostQueued);
          while ( __strex(1u, (unsigned int *)&PpmPerfLatencyBoostQueued) );
          if ( !v9 )
            ExQueueWorkItem(&PpmPerfLatencyBoostWorkItem, 59);
        }
      }
    }
    else
    {
      sub_525ABC();
    }
  }
}
