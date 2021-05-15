// sub_510900 
 
void sub_510900()
{
  int v0; // r5
  int v1; // r7
  unsigned int v2; // r2
  unsigned int v3; // r1

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
  --PopIrpWorkerPendingCount;
  dword_61DFC4 = 0;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
  while ( !v3 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
  if ( v3 )
    ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v3);
  KfLowerIrql((unsigned __int8)v1);
  KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
  JUMPOUT(0x428674);
}
