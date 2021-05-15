// CmpDestroyTemporaryHive 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall CmpDestroyTemporaryHive(_DWORD *result)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r6
  int v3; // r0
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2

  v1 = result;
  if ( result )
  {
    CmpDestroySecurityCache(result);
    v2 = v1 + 808;
    if ( (_DWORD *)v1[808] != v1 + 808 )
    {
      v3 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
      v4 = v3;
      do
        v5 = __ldrex((unsigned __int8 *)&CmpHiveListHeadLock);
      while ( __strex(v5 | 1, (unsigned __int8 *)&CmpHiveListHeadLock) );
      __dmb(0xBu);
      if ( (v5 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&CmpHiveListHeadLock, v3, (unsigned int)&CmpHiveListHeadLock);
      if ( v4 )
        *(_BYTE *)(v4 + 14) |= 1u;
      *(_QWORD *)&v6 = *(_QWORD *)v2;
      if ( *(_DWORD **)(*v2 + 4) != v2 || (_DWORD *)*v7 != v2 )
        __fastfail(3u);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      __pld(&CmpHiveListHeadLock);
      v8 = CmpHiveListHeadLock;
      v9 = CmpHiveListHeadLock - 16;
      if ( (CmpHiveListHeadLock & 0xFFFFFFF0) <= 0x10 )
        v9 = 0;
      if ( (CmpHiveListHeadLock & 2) != 0 )
        goto LABEL_18;
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
      while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpHiveListHeadLock) );
      if ( v10 != v8 )
LABEL_18:
        ExfReleasePushLock(&CmpHiveListHeadLock, v8);
      KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
    }
    if ( (v1[807] & 2) != 0 )
      CmpRemoveHiveFromMapping((int)v1);
    HvFreeHive((int)v1, 1);
    result = CmpDereferenceHive(v1);
  }
  return result;
}
