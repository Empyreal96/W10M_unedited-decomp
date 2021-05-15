// IopErrorLogRequeueEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopErrorLogRequeueEntry(_QWORD *a1)
{
  int v2; // r6
  unsigned int v3; // r2
  int *v4; // r2
  int v5; // r1 OVERLAPPED
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&IopErrorLogLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&IopErrorLogLock);
    while ( __strex(1u, (unsigned int *)&IopErrorLogLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&IopErrorLogLock);
  }
  v4 = &IopErrorLogListHead;
  v5 = IopErrorLogListHead;
  *a1 = *(_QWORD *)&v5;
  if ( *(int **)(v5 + 4) != &IopErrorLogListHead )
    __fastfail(3u);
  *(_DWORD *)(v5 + 4) = a1;
  IopErrorLogListHead = (int)a1;
  ErrorLogSessionOpened = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&IopErrorLogLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    IopErrorLogLock = 0;
  }
  return KfLowerIrql(v2);
}
