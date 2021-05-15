// RtlAllocateHeap 
 
int __fastcall RtlAllocateHeap(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 8) == -571548178 )
    result = RtlpHpAllocWithExceptionProtection();
  else
    result = RtlpAllocateHeapInternal();
  return result;
}
