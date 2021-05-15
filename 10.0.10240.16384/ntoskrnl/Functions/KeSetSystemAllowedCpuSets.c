// KeSetSystemAllowedCpuSets 
 
int __fastcall KeSetSystemAllowedCpuSets(int a1, int *a2)
{
  int result; // r0
  int v5; // r8
  BOOL v6; // r4
  int v7; // r6
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r3

  result = KiValidateCpuSetMasks(a2, a1);
  if ( result >= 0 )
  {
    v5 = KfRaiseIrql(2);
    v6 = a1 != 0;
    v7 = 0;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&KiCpuSetLock);
    }
    else
    {
      v8 = 1;
      do
        v9 = __ldrex((unsigned int *)&KiCpuSetLock);
      while ( __strex(1u, (unsigned int *)&KiCpuSetLock) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire(&KiCpuSetLock);
    }
    RtlWriteAcquireTickLock(&KiCpuSetSequence, v8);
    if ( v6 )
      v10 = *a2;
    else
      v10 = dword_681D78[0];
    KiSystemAllowedCpuSets = v10;
    if ( (v10 & dword_681D78[0]) != dword_681D78[0] )
      v7 = 1;
    KiRestrictedSystemCpuSetsActive = v7;
    RtlWriteReleaseTickLock(&KiCpuSetSequence);
    KeCpuSetReportParkedProcessors(0, v5);
    result = 0;
  }
  return result;
}
