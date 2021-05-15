// WheapPfaReset 
 
// local variable allocation has failed, the output may be wrong!
unsigned int WheapPfaReset()
{
  int v0; // r0
  int v1; // r4
  unsigned int v2; // r2
  int *v3; // r4
  unsigned int v4; // r0
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  unsigned int v7; // r1

  v0 = KeAbPreAcquire((unsigned int)&WheapPfaLock, 0, 0);
  v1 = v0;
  do
    v2 = __ldrex((unsigned __int8 *)&WheapPfaLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&WheapPfaLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&WheapPfaLock, v0, (unsigned int)&WheapPfaLock);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  WheapApplyPolicyChanges();
  v3 = (int *)WheapPfaList;
  while ( v3 != &WheapPfaList )
  {
    v4 = (unsigned int)v3;
    *(_QWORD *)&v5 = *(_QWORD *)v3;
    v3 = (int *)*v3;
    if ( *(_DWORD *)(v5 + 4) != v4 || *v6 != v4 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    ExFreePoolWithTag(v4);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&WheapPfaLock);
  while ( __strex(v7 - 1, (unsigned int *)&WheapPfaLock) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&WheapPfaLock);
  return KeAbPostRelease((unsigned int)&WheapPfaLock);
}
