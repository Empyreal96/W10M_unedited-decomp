// AlpcpDestroyPort 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall AlpcpDestroyPort(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  unsigned int v7; // r1
  _DWORD *v8; // r1

  v1 = result;
  if ( *result )
  {
    v2 = KeAbPreAcquire((unsigned int)&AlpcpPortListLock, 0, 0);
    v3 = v2;
    do
      v4 = __ldrex((unsigned __int8 *)&AlpcpPortListLock);
    while ( __strex(v4 | 1, (unsigned __int8 *)&AlpcpPortListLock) );
    __dmb(0xBu);
    if ( (v4 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&AlpcpPortListLock, v2, (unsigned int)&AlpcpPortListLock);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    *(_QWORD *)&v5 = *(_QWORD *)v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v6 != v1 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&AlpcpPortListLock);
    while ( __strex(v7 - 1, (unsigned int *)&AlpcpPortListLock) );
    if ( (v7 & 2) != 0 )
      return (_DWORD *)sub_806D8C();
    result = (_DWORD *)KeAbPostRelease((unsigned int)&AlpcpPortListLock);
  }
  if ( (v1[61] & 0x200) != 0 )
  {
    v8 = (_DWORD *)v1[37];
    if ( v8 )
      result = (_DWORD *)ExFreeToNPagedLookasideList((int)&AlpcpNPLookasides, v8);
  }
  return result;
}
