// PopRequestShutdownWait 
 
int __fastcall PopRequestShutdownWait(int a1)
{
  _DWORD *v2; // r6
  int v4; // r5
  int v5; // r8
  unsigned int v6; // r2
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  int v9; // r5
  unsigned __int8 v10; // r5
  unsigned int v11; // r1

  v2 = (_DWORD *)ExAllocatePoolWithTag(257, 8, 1280536400);
  if ( !v2 )
    return sub_8170C0();
  v2[1] = a1;
  ObfReferenceObject(a1);
  v4 = KeAbPreAcquire((unsigned int)&PopShutdownListMutex, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&PopShutdownListMutex);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PopShutdownListMutex) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopShutdownListMutex, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61F424 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F43C = v5;
  if ( PopShutdownListAvailable )
  {
    *v2 = PopShutdownThreadList;
    dword_61F424 = 0;
    v7 = dword_61F43C;
    PopShutdownThreadList = (int)v2;
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&PopShutdownListMutex);
    while ( !v8 && __strex(1u, (unsigned int *)&PopShutdownListMutex) );
    if ( v8 )
      ExpReleaseFastMutexContended((unsigned int *)&PopShutdownListMutex, v8);
    KfLowerIrql(v7);
    v9 = 0;
  }
  else
  {
    ObfDereferenceObject(a1);
    ExFreePoolWithTag((unsigned int)v2);
    dword_61F424 = 0;
    v10 = dword_61F43C;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&PopShutdownListMutex);
    while ( !v11 && __strex(1u, (unsigned int *)&PopShutdownListMutex) );
    if ( v11 )
      ExpReleaseFastMutexContended((unsigned int *)&PopShutdownListMutex, v11);
    KfLowerIrql(v10);
    v9 = -1073741823;
  }
  KeAbPostRelease((unsigned int)&PopShutdownListMutex);
  return v9;
}
