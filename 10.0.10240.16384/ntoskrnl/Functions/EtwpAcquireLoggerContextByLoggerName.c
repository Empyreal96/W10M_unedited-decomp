// EtwpAcquireLoggerContextByLoggerName 
 
_DWORD *__fastcall EtwpAcquireLoggerContextByLoggerName(unsigned __int16 *a1, int a2)
{
  unsigned int i; // r5
  int v5; // r0
  _DWORD *v6; // r4
  int v7; // r1

  if ( a1 )
  {
    for ( i = 0; i < 0x40; ++i )
    {
      v5 = EtwpAcquireLoggerContextByLoggerId(i, 0);
      v6 = (_DWORD *)v5;
      if ( v5 )
      {
        if ( RtlEqualUnicodeString((unsigned __int16 *)(v5 + 92), a1, 1) )
        {
          if ( a2 == 1 )
            KeWaitForSingleObject((unsigned int)(v6 + 118), 0, 0, 0, 0);
          if ( v6[62] )
            return v6;
          v7 = a2;
        }
        else
        {
          v7 = 0;
        }
        EtwpReleaseLoggerContext(v6, v7);
      }
    }
  }
  return 0;
}
