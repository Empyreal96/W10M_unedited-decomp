// RtlFreeHeap 
 
int __fastcall RtlFreeHeap(int a1, int a2, int a3)
{
  if ( !a3 )
    return 1;
  if ( *(_DWORD *)(a1 + 8) == -571548178 )
    return RtlpHpFreeWithExceptionProtection(a1, a3, a2);
  return RtlpFreeHeapInternal(a1, a3, a2, (unsigned __int8)RtlpHpHeapFeatures);
}
