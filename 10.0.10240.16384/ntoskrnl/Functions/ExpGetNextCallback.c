// ExpGetNextCallback 
 
int *__fastcall ExpGetNextCallback(int a1)
{
  unsigned int v2; // r9
  int v3; // r10
  int *v4; // r8
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int *v8; // r4
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  __int16 v13; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = 0;
  v4 = 0;
  --*(_WORD *)(v2 + 310);
  v5 = KeAbPreAcquire((unsigned int)&ExpCallbackListLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned int *)&ExpCallbackListLock);
  while ( !v7 && __strex(0x11u, (unsigned int *)&ExpCallbackListLock) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(&ExpCallbackListLock, v5, (unsigned int)&ExpCallbackListLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( a1 )
    v8 = *(int **)(a1 + 20);
  else
    v8 = (int *)ExpCallbackListHead;
  while ( v8 != &ExpCallbackListHead )
  {
    v4 = v8 - 5;
    if ( ObReferenceObjectSafeWithTag((int)(v8 - 5)) )
    {
      v3 = 1;
      break;
    }
    v8 = (int *)*v8;
  }
  __pld(&ExpCallbackListLock);
  v9 = ExpCallbackListLock;
  v10 = ExpCallbackListLock - 16;
  if ( (ExpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (ExpCallbackListLock & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&ExpCallbackListLock);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&ExpCallbackListLock) );
  if ( v11 != v9 )
LABEL_23:
    ExfReleasePushLock(&ExpCallbackListLock, v9);
  v12 = KeAbPostRelease((unsigned int)&ExpCallbackListLock);
  v13 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v13;
  if ( !v13 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    KiCheckForKernelApcDelivery(v12);
  if ( a1 )
    ObfDereferenceObjectWithTag(a1);
  if ( !v3 )
    v4 = 0;
  return v4;
}
