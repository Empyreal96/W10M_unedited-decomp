// EtwpUpdateDisallowList 
 
int __fastcall EtwpUpdateDisallowList(unsigned int a1, unsigned __int16 a2, int a3)
{
  _DWORD *v5; // r5
  int v6; // r4

  v5 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(a1, 0);
  if ( !v5 )
    return -1073741811;
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v6 = EtwpUpdateDisallowedGuids(v5 + 161, a2, a3);
  KeReleaseMutex((int)&EtwpNotificationMutex);
  EtwpReleaseLoggerContext(v5, 0);
  return v6;
}
