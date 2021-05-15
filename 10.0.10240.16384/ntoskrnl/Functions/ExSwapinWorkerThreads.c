// ExSwapinWorkerThreads 
 
unsigned int __fastcall ExSwapinWorkerThreads(int a1, int a2)
{
  unsigned int v2; // r8
  int v3; // r6
  int v4; // r5
  int v5; // r7
  unsigned int v6; // r2
  _DWORD *i; // r5
  unsigned __int8 v8; // r5
  unsigned int v9; // r1
  char v11[16]; // [sp+10h] [bp-58h] BYREF
  char var48[76]; // [sp+20h] [bp-48h] BYREF
  _DWORD vars8[2]; // [sp+70h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeInitializeEvent((int)v11, 0, 0);
  v3 = PsInitialSystemProcess;
  v4 = KeAbPreAcquire((unsigned int)&ExpWorkerSwapinMutex, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&ExpWorkerSwapinMutex);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&ExpWorkerSwapinMutex) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpWorkerSwapinMutex, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_619F84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_619F9C = v5;
  ExpWorkersCanSwap = vars8[0];
  __dmb(0xFu);
  for ( i = PsGetNextProcessThread(v3, 0); i; i = PsGetNextProcessThread(v3, (int)i) )
  {
    if ( (i[241] & 1) != 0 )
    {
      if ( i == (_DWORD *)v2 )
      {
        KeSetKernelStackSwapEnable(LOBYTE(vars8[0]));
      }
      else
      {
        KeInitializeApc((int)var48, (int)i, 0, (int)ExpSetSwappingKernelApc, 0, 0, 0, (int)vars8);
        if ( KeInsertQueueApc((int)var48, (int)v11, 0, 3) )
        {
          KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
          KeResetEvent((int)v11);
        }
      }
    }
  }
  dword_619F84 = 0;
  v8 = dword_619F9C;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&ExpWorkerSwapinMutex);
  while ( !v9 && __strex(1u, (unsigned int *)&ExpWorkerSwapinMutex) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpWorkerSwapinMutex, v9);
  KfLowerIrql(v8);
  return KeAbPostRelease((unsigned int)&ExpWorkerSwapinMutex);
}
