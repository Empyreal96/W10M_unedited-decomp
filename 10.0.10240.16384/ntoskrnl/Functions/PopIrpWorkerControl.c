// PopIrpWorkerControl 
 
int PopIrpWorkerControl()
{
  int v0; // r7
  int v1; // r5
  int v2; // r0
  unsigned __int8 v3; // r8
  unsigned int v4; // r2
  unsigned int v6; // r1

  while ( 1 )
  {
    v0 = 0;
    KeWaitForSingleObject((unsigned int)&PopIrpWorkerControlEvent, 0, 0, 0, 0);
    v1 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
    v2 = KfRaiseIrql(1);
    v3 = v2;
    do
      v4 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
    while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
    __dmb(0xBu);
    if ( (v4 & 1) == 0 )
      break;
    if ( v1 )
      *(_BYTE *)(v1 + 14) |= 1u;
    __mrc(15, 0, 13, 0, 3);
    PopIrpWorkerRequested = 0;
    dword_61DFDC = v2;
    if ( PopCreateIrpWorkerAllowed )
    {
      v0 = 1;
      ++PopIrpWorkerPendingCount;
    }
    dword_61DFC4 = 0;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
    while ( !v6 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
    if ( v6 )
      ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v6);
    KfLowerIrql(v3);
    KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
    if ( v0 )
      PopCreateDynamicIrpWorker(0);
  }
  return sub_553634();
}
