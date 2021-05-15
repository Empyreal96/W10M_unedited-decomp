// EtwpGetDisallowList 
 
int __fastcall EtwpGetDisallowList(unsigned __int16 *a1, _BYTE *a2, int *a3)
{
  unsigned int v4; // r9
  int v6; // r4
  int v7; // r5
  int v8; // r3
  int v9; // r6

  v4 = *a3;
  v6 = 0;
  v7 = EtwpAcquireLoggerContextByLoggerId(*a1, 0);
  if ( !v7 )
    return -1073741811;
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  memset(a2, 0, *a3);
  v8 = *(unsigned __int16 *)(v7 + 644);
  v9 = 16 * v8;
  if ( 16 * v8 > v4 )
    v6 = -1073741789;
  else
    memmove((int)a2, *(_DWORD *)(v7 + 648), 16 * v8);
  *a3 = v9;
  KeReleaseMutex((int)&EtwpNotificationMutex);
  EtwpReleaseLoggerContext((_DWORD *)v7, 0);
  return v6;
}
