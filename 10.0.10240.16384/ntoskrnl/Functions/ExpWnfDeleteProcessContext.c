// ExpWnfDeleteProcessContext 
 
unsigned int __fastcall ExpWnfDeleteProcessContext(unsigned int a1, int a2)
{
  unsigned __int8 *v2; // r5
  int v4; // r0
  unsigned int v5; // r2
  int v6; // r8
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned __int8 *v15; // r5
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  unsigned int v19; // r1
  unsigned int result; // r0
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  __int64 v24; // r0
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r8
  unsigned int *v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int v31; // r1
  int v32; // r0
  int v33; // r4
  unsigned int v34; // r2

  v2 = (unsigned __int8 *)(a1 + 40);
  v4 = KeAbPreAcquire(a1 + 40, 0, 0);
  do
    v5 = __ldrex(v2);
  while ( __strex(v5 | 1, v2) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7C059C(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  while ( *(_DWORD *)(a1 + 44) != a1 + 44 )
  {
    v6 = *(_DWORD *)(a1 + 44);
    v7 = (unsigned int *)(v6 - 12);
    __pld((void *)(v6 - 12));
    v8 = *(_DWORD *)(v6 - 12) & 0xFFFFFFFE;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 2, v7) );
    __dmb(0xBu);
    if ( v9 != v8 )
      ExfAcquireRundownProtection(v7);
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)v2);
    while ( __strex(v10 - 1, (unsigned int *)v2) );
    if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v2);
    KeAbPostRelease((unsigned int)v2);
    ExpWnfDeleteSubscription(v6 - 16, *(_DWORD *)(a1 + 4));
    v11 = KeAbPreAcquire((unsigned int)v2, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v2);
    while ( __strex(v13 | 1, v2) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v2, v11, (unsigned int)v2);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
  }
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v2);
  while ( __strex(v14 - 1, (unsigned int *)v2) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v2);
  KeAbPostRelease((unsigned int)v2);
  v15 = (unsigned __int8 *)(a1 + 28);
  v16 = KeAbPreAcquire(a1 + 28, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex(v15);
  while ( __strex(v18 | 1, v15) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 28), v16, a1 + 28);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  while ( *(_DWORD *)(a1 + 32) != a1 + 32 )
  {
    v27 = *(_DWORD *)(a1 + 32);
    v28 = (unsigned int *)(v27 - 72);
    __pld((void *)(v27 - 72));
    v29 = *(_DWORD *)(v27 - 72) & 0xFFFFFFFE;
    do
      v30 = __ldrex(v28);
    while ( v30 == v29 && __strex(v29 + 2, v28) );
    __dmb(0xBu);
    if ( v30 != v29 )
      ExfAcquireRundownProtection(v28);
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)v15);
    while ( __strex(v31 - 1, (unsigned int *)v15) );
    if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 28));
    KeAbPostRelease(a1 + 28);
    ExpWnfNotifyNameSubscribers(v27 - 76, 16, 0, 0);
    ExpWnfDeleteNameInstance(*(_DWORD *)(v27 - 44), v27 - 76, 1);
    v32 = KeAbPreAcquire(a1 + 28, 0, 0);
    v33 = v32;
    do
      v34 = __ldrex(v15);
    while ( __strex(v34 | 1, v15) );
    __dmb(0xBu);
    if ( (v34 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 28), v32, a1 + 28);
    if ( v33 )
      *(_BYTE *)(v33 + 14) |= 1u;
  }
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)v15);
  while ( __strex(v19 - 1, (unsigned int *)v15) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 28));
  result = KeAbPostRelease(a1 + 28);
  if ( a2 )
  {
    v21 = KeAbPreAcquire((unsigned int)&ExpWnfProcessesListLock, 0, 0);
    v22 = v21;
    do
      v23 = __ldrex((unsigned __int8 *)&ExpWnfProcessesListLock);
    while ( __strex(v23 | 1, (unsigned __int8 *)&ExpWnfProcessesListLock) );
    __dmb(0xBu);
    if ( (v23 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ExpWnfProcessesListLock, v21, (unsigned int)&ExpWnfProcessesListLock);
    if ( v22 )
      *(_BYTE *)(v22 + 14) |= 1u;
    v24 = *(_QWORD *)(a1 + 8);
    if ( *(_DWORD *)(v24 + 4) != a1 + 8 || *(_DWORD *)HIDWORD(v24) != a1 + 8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v24) = v24;
    *(_DWORD *)(v24 + 4) = HIDWORD(v24);
    __dmb(0xBu);
    do
      v25 = __ldrex(&ExpWnfProcessesListLock);
    while ( __strex(v25 - 1, &ExpWnfProcessesListLock) );
    if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
      ExfTryToWakePushLock(&ExpWnfProcessesListLock);
    KeAbPostRelease((unsigned int)&ExpWnfProcessesListLock);
    v26 = *(_DWORD *)(a1 + 64);
    if ( v26 )
      ObfDereferenceObject(v26);
    result = ExFreePoolWithTag(a1);
  }
  return result;
}
