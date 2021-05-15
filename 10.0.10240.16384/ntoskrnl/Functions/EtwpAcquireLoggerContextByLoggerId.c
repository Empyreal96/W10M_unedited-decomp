// EtwpAcquireLoggerContextByLoggerId 
 
int __fastcall EtwpAcquireLoggerContextByLoggerId(unsigned int a1, int a2)
{
  int v4; // r3
  int v5; // r4

  if ( a1 >= 0x40 )
    LOBYTE(v4) = 1;
  else
    v4 = WmipLoggerContext[a1];
  if ( (v4 & 1) != 0 || !ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[a1], 1) )
    return 0;
  if ( a1 >= 0x40 )
    v5 = 1;
  else
    v5 = WmipLoggerContext[a1];
  if ( (v5 & 1) == 0 && PsEqualCurrentServerSilo(*(_DWORD *)(v5 + 652)) )
  {
    if ( a2 )
      KeWaitForSingleObject(v5 + 472, 0, 0, 0, 0);
    if ( *(_DWORD *)(v5 + 248) )
      return v5;
    EtwpReleaseLoggerContext(v5, a2);
    return 0;
  }
  return sub_7C5A40();
}
