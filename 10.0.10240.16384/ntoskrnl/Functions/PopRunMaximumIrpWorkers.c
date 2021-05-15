// PopRunMaximumIrpWorkers 
 
int PopRunMaximumIrpWorkers()
{
  int v0; // r4
  int v1; // r7
  unsigned int v2; // r2
  int v3; // r6
  unsigned int v4; // r1
  int result; // r0
  int v6; // r4
  char v7[4]; // [sp+8h] [bp-28h] BYREF
  int v8; // [sp+Ch] [bp-24h]
  int v9[8]; // [sp+10h] [bp-20h] BYREF

  v0 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
  v1 = KfRaiseIrql(1);
  do
    v2 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopIrpWorkerMutex, v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  __mrc(15, 0, 13, 0, 3);
  dword_61DFDC = v1;
  v3 = 15 - PopIrpWorkerPendingCount - PopIrpWorkerCount;
  PopIrpWorkerPendingCount += v3;
  PopCreateIrpWorkerAllowed = 0;
  dword_61DFC4 = 0;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
  while ( !v4 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
  if ( v4 )
    ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v4);
  KfLowerIrql((unsigned __int8)v1);
  result = KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
  v7[0] = 5;
  v7[2] = 5;
  v8 = 0;
  v9[1] = (int)v9;
  v9[2] = v3;
  v6 = 0;
  for ( v9[0] = (int)v9; v3; --v3 )
  {
    result = PopCreateDynamicIrpWorker((int)v7);
    if ( result >= 0 )
      ++v6;
  }
  for ( ; v6; --v6 )
    result = KeWaitForSingleObject((unsigned int)v7, 0, 0, 0, 0);
  return result;
}
