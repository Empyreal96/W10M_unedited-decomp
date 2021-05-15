// KeSetTagCpuSets 
 
int __fastcall KeSetTagCpuSets(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r7
  unsigned int v5; // r6
  int result; // r0
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r0
  unsigned int i; // r1
  unsigned int v13; // t1
  unsigned int v14; // r2
  unsigned int v15; // r3
  int vars4; // [sp+24h] [bp+4h]

  v4 = (unsigned int *)a2;
  v5 = a1;
  result = KiValidateCpuSetMasks(a2, a1);
  if ( result >= 0 )
  {
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&KiCpuSetLock);
    }
    else
    {
      do
        v10 = __ldrex((unsigned int *)&KiCpuSetLock);
      while ( __strex(1u, (unsigned int *)&KiCpuSetLock) );
      __dmb(0xBu);
      if ( v10 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&KiCpuSetLock);
    }
    RtlWriteAcquireTickLock((unsigned __int64 *)&KiCpuSetSequence);
    if ( v5 )
    {
      v11 = KiCpuSetData;
      do
      {
        v13 = *v4;
        v4 += 2;
        for ( i = v13; i; *(_DWORD *)(v15 + 12) = a4 )
        {
          v14 = __clz(__rbit(i));
          i &= ~(1 << v14);
          v15 = v11 + 16 * v14;
          *(_DWORD *)(v15 + 8) = a3;
        }
        --v5;
      }
      while ( v5 );
    }
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
    KfLowerIrql(v9);
    result = 0;
  }
  return result;
}
