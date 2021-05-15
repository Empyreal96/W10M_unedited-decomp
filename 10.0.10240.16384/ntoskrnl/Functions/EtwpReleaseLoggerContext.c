// EtwpReleaseLoggerContext 
 
int __fastcall EtwpReleaseLoggerContext(_DWORD *a1, int a2)
{
  if ( a2 )
    KeReleaseMutex((int)(a1 + 118));
  return ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[*a1], 1);
}
