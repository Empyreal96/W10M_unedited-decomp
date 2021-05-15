// ExReleaseResourceAndLeaveCriticalRegion 
 
unsigned int __fastcall ExReleaseResourceAndLeaveCriticalRegion(int a1)
{
  unsigned int result; // r0
  __int16 v2; // r2

  ExpReleaseResourceForThreadLite(a1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(result + 0x134);
  *(_WORD *)(result + 308) = v2 + 1;
  if ( v2 == -1 && *(_DWORD *)(result + 100) != result + 100 && !*(_WORD *)(result + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
