// PipSetDevNodeState 
 
int __fastcall PipSetDevNodeState(_DWORD *a1, int a2)
{
  int v2; // r8
  int v3; // r10
  int result; // r0
  unsigned int v7; // r2
  int v8; // r6
  BOOL v9; // r0
  int v10; // r3
  int v11; // r5
  int v12; // [sp+0h] [bp-28h]
  int v13; // [sp+4h] [bp-24h]

  v12 = 0;
  v2 = 0;
  v3 = 0;
  v13 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5189C0();
  do
    v7 = __ldrex((unsigned int *)&PnpSpinLock);
  while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
  __dmb(0xBu);
  if ( v7 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  v8 = a1[43];
  if ( v8 != a2 )
  {
    v12 = PipAreDriversLoadedWorker(a1[43], a1[44]);
    v9 = PipIsDevNodeDNStarted((int)a1);
    v10 = a1[65];
    a1[43] = a2;
    a1[44] = v8;
    v2 = v9;
    a1[v10 + 45] = v8;
    a1[65] = (a1[65] + 1) % 0x14u;
    v3 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  result = KfLowerIrql(v13);
  if ( v3 )
  {
    v11 = a1[6];
    if ( v11 )
    {
      if ( PipAreDriversLoadedWorker(a1[43], a1[44]) != v12 || (result = PipIsDevNodeDNStarted((int)a1), result != v2) )
      {
        PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v11, 11);
        result = PipIsDevNodeDNStarted((int)a1);
        if ( result != v2 )
          result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, a1[6], 26);
      }
    }
  }
  if ( a2 == 788 )
    result = PnpRemoveDeviceActionRequests(a1[4]);
  return result;
}
