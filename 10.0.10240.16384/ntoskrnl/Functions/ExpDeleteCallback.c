// ExpDeleteCallback 
 
int __fastcall ExpDeleteCallback(int a1)
{
  unsigned int v2; // r6
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  __int64 v6; // r0
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  int result; // r0
  __int16 v11; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = KeAbPreAcquire((unsigned int)&ExpCallbackListLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&ExpCallbackListLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&ExpCallbackListLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpCallbackListLock, v3, (unsigned int)&ExpCallbackListLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = *(_QWORD *)(a1 + 20);
  if ( *(_DWORD *)(v6 + 4) != a1 + 20 || *(_DWORD *)HIDWORD(v6) != a1 + 20 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v6) = v6;
  *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  __pld(&ExpCallbackListLock);
  v7 = ExpCallbackListLock;
  v8 = ExpCallbackListLock - 16;
  if ( (ExpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  if ( (ExpCallbackListLock & 2) != 0 )
    goto LABEL_16;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&ExpCallbackListLock);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&ExpCallbackListLock) );
  if ( v9 != v7 )
LABEL_16:
    ExfReleasePushLock(&ExpCallbackListLock, v7);
  result = KeAbPostRelease((unsigned int)&ExpCallbackListLock);
  v11 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
