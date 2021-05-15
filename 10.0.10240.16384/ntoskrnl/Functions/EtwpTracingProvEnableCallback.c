// EtwpTracingProvEnableCallback 
 
void __fastcall EtwpTracingProvEnableCallback(int a1, int a2)
{
  unsigned int i; // r4
  int v3; // r0
  _DWORD *v4; // r5

  if ( a2 == 2 )
  {
    for ( i = 0; i < 0x40; ++i )
    {
      v3 = EtwpAcquireLoggerContextByLoggerId(i, 0);
      v4 = (_DWORD *)v3;
      if ( v3 )
      {
        EtwpEventWriteTemplateSession(EtwpEventTracingProvRegHandle, dword_61ADA4, ETW_EVENT_SESSION_INFO, v3);
        EtwpReleaseLoggerContext(v4, 0);
      }
    }
  }
}
