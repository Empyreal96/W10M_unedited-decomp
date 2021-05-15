// PspGetNextJob 
 
int __fastcall PspGetNextJob(int a1)
{
  unsigned int v2; // r7
  void **v3; // r8
  int v4; // r0
  unsigned int v5; // r2
  void **v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  __int16 v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = 0;
  --*(_WORD *)(v2 + 310);
  v4 = KeAbPreAcquire((unsigned int)&PspJobListLock, 0, 0);
  do
    v5 = __ldrex((unsigned int *)&PspJobListLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&PspJobListLock) );
  __dmb(0xBu);
  if ( v5 )
    return sub_7C27D8(v4, 17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1 )
    v6 = *(void ***)(a1 + 16);
  else
    v6 = (void **)PspJobList;
  while ( v6 != &PspJobList )
  {
    if ( ObReferenceObjectSafeWithTag((int)(v6 - 4)) )
    {
      v3 = v6 - 4;
      break;
    }
    v6 = (void **)*v6;
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PspJobListLock);
  while ( v7 == 17 && __strex(0, (unsigned int *)&PspJobListLock) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(&PspJobListLock);
  v8 = KeAbPostRelease((unsigned int)&PspJobListLock);
  v9 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    KiCheckForKernelApcDelivery(v8);
  if ( a1 )
    ObfDereferenceObjectWithTag(a1);
  return (int)v3;
}
