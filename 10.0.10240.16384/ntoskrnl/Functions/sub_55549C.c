// sub_55549C 
 
void __fastcall sub_55549C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v10; // r6
  int v11; // r7
  unsigned int v12; // r2
  int **v13; // r0

  KeQuerySystemTime(v10 + 6);
  v11 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&IopErrorLogLock);
  }
  else
  {
    do
      v12 = __ldrex((unsigned int *)&IopErrorLogLock);
    while ( __strex(1u, (unsigned int *)&IopErrorLogLock) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&IopErrorLogLock);
  }
  v13 = (int **)dword_6318DC;
  v10[1] = &IopErrorLogListHead;
  v10[2] = v13;
  if ( *v13 != &IopErrorLogListHead )
    __fastfail(3u);
  *v13 = v10 + 1;
  dword_6318DC = (int)(v10 + 1);
  if ( !IopErrorLogSessionPending )
  {
    IopErrorLogSessionPending = 1;
    dword_630E28 = (int)IopErrorLogThread;
    dword_630E2C = 0;
    IopErrorLogWorkItem = 0;
    ExQueueWorkItem(&IopErrorLogWorkItem, 1);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&IopErrorLogLock, a10);
  }
  else
  {
    __dmb(0xBu);
    IopErrorLogLock = 0;
  }
  KfLowerIrql(v11);
  JUMPOUT(0x4F7DDE);
}
