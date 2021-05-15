// PipRestoreDevNodeState 
 
int __fastcall PipRestoreDevNodeState(_DWORD *a1)
{
  int v2; // r10
  int result; // r0
  unsigned int v4; // r2
  __int64 v5; // kr08_8
  BOOL v6; // r0
  int v7; // r3
  int v8; // r8
  int v9; // r4
  int v10; // [sp+0h] [bp-20h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_55481C();
  do
    v4 = __ldrex((unsigned int *)&PnpSpinLock);
  while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  v5 = *(_QWORD *)(a1 + 43);
  v10 = PipAreDriversLoadedWorker(a1[43], a1[44]);
  v6 = PipIsDevNodeDNStarted((int)a1);
  v7 = a1[65];
  a1[43] = HIDWORD(v5);
  v8 = v6;
  a1[v7 + 45] = v5;
  a1[65] = (a1[65] + 1) % 0x14u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  result = KfLowerIrql(v2);
  v9 = a1[6];
  if ( v9 )
  {
    if ( PipAreDriversLoadedWorker(a1[43], a1[44]) != v10 || (result = PipIsDevNodeDNStarted((int)a1), result != v8) )
    {
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v9, 11);
      result = PipIsDevNodeDNStarted((int)a1);
      if ( result != v8 )
        result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, a1[6], 26);
    }
  }
  return result;
}
