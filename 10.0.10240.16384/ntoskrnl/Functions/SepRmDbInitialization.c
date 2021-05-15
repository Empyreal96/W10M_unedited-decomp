// SepRmDbInitialization 
 
int SepRmDbInitialization()
{
  char *v0; // r4
  int v1; // r5
  _DWORD *v2; // r0
  _DWORD *v3; // r3
  _BYTE *v4; // r0
  int v5; // r1

  v0 = (char *)&SepRmDbLock;
  v1 = 4;
  do
  {
    ExInitializeResourceLite((int)v0);
    v0 += 56;
    --v1;
  }
  while ( v1 );
  ExInitializeResourceLite((int)&SepRmGlobalSaclLock);
  SepRmNotifyMutex = 1;
  dword_649EF8 = 0;
  *(_DWORD *)algn_649EFC = 0;
  byte_649F00 = 1;
  byte_649F01 = 0;
  byte_649F02 = 4;
  dword_649F04 = 0;
  dword_649F0C = (int)&dword_649F08;
  dword_649F08 = (int)&dword_649F08;
  v2 = (_DWORD *)ExAllocatePoolWithTag(1, 64, 1934386515);
  SepLogonSessions = (int)v2;
  if ( !v2 )
    return 0;
  v3 = v2 + 16;
  do
    *v2++ = 0;
  while ( v2 != v3 );
  if ( SepCreateLogonSessionTrack() < 0 )
    return 0;
  if ( SepCreateLogonSessionTrack() < 0 )
    return 0;
  SepRmAuditingEnabled = 0;
  v4 = memset(SeAuditingState, 0, 116);
  byte_61D422 = 1;
  SepRmCapTableLock = 0;
  __dmb(0xBu);
  SepRmEnforceCap = 0;
  if ( SepBuildDefaultCap((int)v4, v5, 0, (int)&SepRmEnforceCap) < 0 )
    return 0;
  dword_922BE8 = 1;
  return 1;
}
