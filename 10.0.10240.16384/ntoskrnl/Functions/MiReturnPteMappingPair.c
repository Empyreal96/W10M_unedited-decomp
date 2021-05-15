// MiReturnPteMappingPair 
 
int __fastcall MiReturnPteMappingPair(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( v2 == 17 )
    result = MiReleasePtes(&dword_634D58, *(_DWORD *)(a1 + 12), 2);
  else
    result = KfLowerIrql(v2);
  return result;
}
