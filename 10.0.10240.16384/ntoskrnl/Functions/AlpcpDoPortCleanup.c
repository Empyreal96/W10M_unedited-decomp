// AlpcpDoPortCleanup 
 
unsigned int __fastcall AlpcpDoPortCleanup(_DWORD *a1)
{
  unsigned __int8 *v2; // r5
  int v3; // r0
  int v4; // r6
  unsigned int v5; // r2
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned __int8 *v13; // r6
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  int v17; // r1
  __int64 *v18; // r2
  __int64 v19; // kr00_8
  int v20; // r3
  unsigned int v21; // r1

  AlpcpDisconnectPort(a1, 0);
  v2 = (unsigned __int8 *)(a1 + 52);
  v3 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v4 = v3;
  do
    v5 = __ldrex(v2);
  while ( __strex(v5 | 1, v2) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 52, v3, (unsigned int)(a1 + 52));
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1[53] )
    return sub_806E2C();
  v7 = a1[3];
  if ( (v7 & 1) == 0 && v7 )
  {
    ObfDereferenceObjectWithTag(v7);
    a1[3] |= 1u;
  }
  a1[61] |= 0x40u;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v2);
  while ( __strex(v8 - 1, (unsigned int *)v2) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 52);
  KeAbPostRelease((unsigned int)(a1 + 52));
  AlpcpFlushMessagesPort(a1);
  AlpcpFlushResourcesPort(a1);
  v9 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v2);
  while ( __strex(v11 | 1, v2) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 52, v9, (unsigned int)(a1 + 52));
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( (a1[61] & 0x200) != 0 )
  {
    KeReleaseSemaphore(a1[37], 1, 0x1000000);
  }
  else if ( (_DWORD *)a1[35] != a1 + 35 )
  {
    v13 = (unsigned __int8 *)(a1 + 34);
    v14 = KeAbPreAcquire((unsigned int)(a1 + 34), 0, 0);
    v15 = v14;
    do
      v16 = __ldrex(v13);
    while ( __strex(v16 | 1, v13) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 34, v14, (unsigned int)(a1 + 34));
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    while ( (_DWORD *)a1[35] != a1 + 35 )
    {
      v17 = a1[35] - 988;
      v18 = (__int64 *)a1[35];
      *((_DWORD *)v18 - 2) = 0;
      v19 = *v18;
      if ( *(__int64 **)(*(_DWORD *)v18 + 4) != v18 || (v20 = *(_DWORD *)HIDWORD(v19), *(__int64 **)HIDWORD(v19) != v18) )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      *(_DWORD *)(v17 + 988) = 0;
      KeReleaseSemaphoreEx(v17 + 884, 1, 1, v20, 2);
    }
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v13);
    while ( __strex(v21 - 1, (unsigned int *)v13) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 34);
    KeAbPostRelease((unsigned int)(a1 + 34));
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v2);
  while ( __strex(v12 - 1, (unsigned int *)v2) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 52);
  return KeAbPostRelease((unsigned int)(a1 + 52));
}
