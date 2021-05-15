// KiAllocateCpuSetData 
 
int __fastcall KiAllocateCpuSetData(int a1)
{
  _BYTE *v2; // r0
  int v3; // r5

  if ( KiMaximumGroups != 1 )
    a1 = 32 * (unsigned __int16)KiMaximumGroups;
  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 24 * a1, 538993995);
  v3 = (int)v2;
  if ( !v2 )
    return 0;
  memset(v2, 0, 24 * a1);
  KiCpuSetAffinitiesShadow = 4 * a1 + v3;
  KiCpuSetAffinities = v3;
  KiCpuSetData = KiCpuSetAffinitiesShadow + 4 * a1;
  KiCpuSetAffinitySize = 4 * a1;
  KiCreateCpuSetForProcessor((int)KiProcessorBlock);
  return 1;
}
