// PspRemoveCpuRateControl 
 
unsigned int __fastcall PspRemoveCpuRateControl(int a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4
  unsigned int result; // r0

  *(_DWORD *)(*(_DWORD *)(a1 + 532) + 24) = 0;
  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 744);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0xFFFFFFDF, v2) );
  __dmb(0xBu);
  KeRemoveSchedulingGroup((unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 128));
  result = PspFreeRateControl(*(_DWORD **)(a1 + 532), 2);
  *(_DWORD *)(a1 + 532) = 0;
  if ( PsCpuFairShareEnabled )
    result = sub_7C0AE8(result);
  return result;
}
