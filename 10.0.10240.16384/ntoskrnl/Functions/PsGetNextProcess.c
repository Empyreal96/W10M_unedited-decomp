// PsGetNextProcess 
 
int *__fastcall PsGetNextProcess(int a1)
{
  int *v2; // r8
  unsigned int v3; // r9
  int v4; // r10
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int *v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  __int16 v11; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = 0;
  --*(_WORD *)(v3 + 310);
  v5 = KeAbPreAcquire((unsigned int)&PspActiveProcessLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned int *)&PspActiveProcessLock);
  while ( !v7 && __strex(0x11u, (unsigned int *)&PspActiveProcessLock) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(&PspActiveProcessLock, v5, (unsigned int)&PspActiveProcessLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( a1 )
    v8 = *(int **)(a1 + 180);
  else
    v8 = (int *)PsActiveProcessHead;
  while ( v8 != &PsActiveProcessHead )
  {
    v2 = v8 - 45;
    if ( ObReferenceObjectSafeWithTag((int)(v8 - 45)) )
    {
      v4 = 1;
      break;
    }
    v8 = (int *)*v8;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PspActiveProcessLock);
  while ( v9 == 17 && __strex(0, (unsigned int *)&PspActiveProcessLock) );
  if ( v9 != 17 )
    ExfReleasePushLockShared(&PspActiveProcessLock);
  v10 = KeAbPostRelease((unsigned int)&PspActiveProcessLock);
  v11 = *(_WORD *)(v3 + 310) + 1;
  *(_WORD *)(v3 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v3 + 100) != v3 + 100 )
    KiCheckForKernelApcDelivery(v10);
  if ( a1 )
    ObfDereferenceObjectWithTag(a1);
  if ( !v4 )
    v2 = 0;
  return v2;
}
