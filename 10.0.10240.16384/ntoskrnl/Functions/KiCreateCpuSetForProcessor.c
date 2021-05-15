// KiCreateCpuSetForProcessor 
 
int __fastcall KiCreateCpuSetForProcessor(int result)
{
  int v1; // r6
  int v2; // r0
  int v3; // r8
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r1
  int v7; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = result;
  if ( KiCpuSetAffinities )
  {
    v2 = KfRaiseIrql(2);
    v3 = *(unsigned __int8 *)(v1 + 1052);
    v4 = v2;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_694434();
    }
    else
    {
      do
        v5 = __ldrex((unsigned int *)&KiCpuSetLock);
      while ( __strex(1u, (unsigned int *)&KiCpuSetLock) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&KiCpuSetLock);
      RtlWriteAcquireTickLock((unsigned __int64 *)&KiCpuSetSequence);
      v6 = *(unsigned __int8 *)(v1 + 1053);
      ++*((_BYTE *)&KiCpuSetCount + v3);
      ++KiTotalCpuSetCount;
      *(_DWORD *)(KiCpuSetAffinities + 4 * v6) = *(_DWORD *)(v1 + 1048);
      *(_DWORD *)(KiCpuSetAffinitiesShadow + 4 * v6) = *(_DWORD *)(v1 + 1048);
      v7 = 1 << v6;
      KiSystemAllowedCpuSets[v3] |= v7;
      KiNonParkedCpuSets[v3] |= v7;
      *(_DWORD *)(PsInitialSystemProcess + 880 + 4 * v3) |= v7;
      RtlWriteReleaseTickLock(&KiCpuSetSequence);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KiCpuSetLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        KiCpuSetLock = 0;
      }
      result = KfLowerIrql(v4);
    }
  }
  return result;
}
