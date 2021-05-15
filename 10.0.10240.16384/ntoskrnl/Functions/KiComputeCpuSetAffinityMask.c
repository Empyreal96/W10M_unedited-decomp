// KiComputeCpuSetAffinityMask 
 
int __fastcall KiComputeCpuSetAffinityMask(int a1, int *a2, int a3, unsigned int a4)
{
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r6
  int v10; // r4
  unsigned int i; // r0
  unsigned int v12; // r2

  do
  {
    v7 = RtlBeginReadTickLock(&KiCpuSetSequence);
    v9 = v7;
    if ( a1 && *a2 == v7 )
      return *(_DWORD *)a1;
    v10 = 0;
    for ( i = a4; i; i &= ~(1 << v12) )
    {
      v12 = __clz(__rbit(i));
      v10 |= *(_DWORD *)(KiCpuSetAffinities + 4 * v12);
    }
  }
  while ( !RtlTryEndReadTickLock(&KiCpuSetSequence, __SPAIR64__(v8, v9)) );
  *a2 = v9;
  if ( a1 )
    *(_DWORD *)a1 = v10;
  return v10;
}
