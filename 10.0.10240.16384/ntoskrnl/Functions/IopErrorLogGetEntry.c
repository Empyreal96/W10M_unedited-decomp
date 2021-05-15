// IopErrorLogGetEntry 
 
int IopErrorLogGetEntry()
{
  int v0; // r7
  unsigned int v1; // r2
  int v2; // r5
  __int64 v3; // kr00_8
  int vars4; // [sp+14h] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&IopErrorLogLock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&IopErrorLogLock);
    while ( __strex(1u, (unsigned int *)&IopErrorLogLock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&IopErrorLogLock);
  }
  v2 = IopErrorLogListHead;
  if ( (int *)IopErrorLogListHead == &IopErrorLogListHead )
  {
    v2 = 0;
    IopErrorLogSessionPending = 0;
  }
  else
  {
    v3 = *(_QWORD *)IopErrorLogListHead;
    if ( *(int **)(IopErrorLogListHead + 4) != &IopErrorLogListHead || *(_DWORD *)(v3 + 4) != IopErrorLogListHead )
      __fastfail(3u);
    IopErrorLogListHead = *(_DWORD *)IopErrorLogListHead;
    *(_DWORD *)(v3 + 4) = &IopErrorLogListHead;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&IopErrorLogLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    IopErrorLogLock = 0;
  }
  KfLowerIrql(v0);
  return v2;
}
