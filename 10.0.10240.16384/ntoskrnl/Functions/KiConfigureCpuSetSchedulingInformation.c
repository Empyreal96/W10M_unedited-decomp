// KiConfigureCpuSetSchedulingInformation 
 
int __fastcall KiConfigureCpuSetSchedulingInformation(int a1)
{
  int v2; // r8
  unsigned int v4; // r2
  unsigned __int64 *v5; // r0
  _BYTE *v6; // r0
  int v7; // r1
  unsigned int v8; // r3
  int v9; // r5
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_6942AC();
  do
    v4 = __ldrex((unsigned int *)&KiCpuSetLock);
  while ( __strex(1u, (unsigned int *)&KiCpuSetLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KiCpuSetLock);
  v5 = RtlWriteAcquireTickLock((unsigned __int64 *)&KiCpuSetSequence);
  v6 = (_BYTE *)KiGetCpuSetData((int)v5, *(unsigned __int8 *)(a1 + 1053));
  v7 = a1;
  *v6 = *(_BYTE *)(a1 + 1052);
  v6[1] = *(_BYTE *)(a1 + 1053);
  v6[2] = __clz(__rbit(*(_DWORD *)(a1 + 3468)));
  v8 = 0;
  v9 = 5;
  do
  {
    if ( *(_DWORD *)(v7 + 3480) )
      v8 = *(_DWORD *)(v7 + 3480);
    v7 += 4;
    --v9;
  }
  while ( v9 );
  if ( v8 )
    v6[3] = __clz(__rbit(v8));
  v6[4] = __clz(__rbit(*(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260)));
  v6[5] = *(_BYTE *)(a1 + 2986);
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
  return KfLowerIrql(v2);
}
