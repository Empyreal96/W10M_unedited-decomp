// CmpParseCacheClose 
 
int CmpParseCacheClose()
{
  int v0; // r0
  int v1; // r4
  unsigned int v2; // r2
  int v3; // r6
  int v4; // r8
  _DWORD *v5; // r0
  _DWORD *v6; // t1
  _DWORD *v7; // r4
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2

  v0 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
  v1 = v0;
  do
    v2 = __ldrex((unsigned __int8 *)&CmpParseCacheLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&CmpParseCacheLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpParseCacheLock, v0, (unsigned int)&CmpParseCacheLock);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v3 = 32;
  v4 = CmpParseCacheTable;
  do
  {
    v6 = *(_DWORD **)(v4 + 4);
    v4 += 4;
    v5 = v6;
    if ( v6 )
    {
      do
      {
        v7 = (_DWORD *)*v5;
        ExFreePoolWithTag((unsigned int)v5);
        v5 = v7;
      }
      while ( v7 );
    }
    --v3;
  }
  while ( v3 );
  __pld(&CmpParseCacheLock);
  CmpParseCacheTable = 0;
  v8 = CmpParseCacheLock;
  v9 = CmpParseCacheLock - 16;
  if ( (CmpParseCacheLock & 0xFFFFFFF0) <= 0x10 )
    v9 = 0;
  if ( (CmpParseCacheLock & 2) != 0 )
    goto LABEL_18;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&CmpParseCacheLock);
  while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpParseCacheLock) );
  if ( v10 != v8 )
LABEL_18:
    ExfReleasePushLock(&CmpParseCacheLock, v8);
  KeAbPostRelease((unsigned int)&CmpParseCacheLock);
  return 0;
}
