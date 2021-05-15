// ExReleaseResourceAndLeavePriorityRegion 
 
int __fastcall ExReleaseResourceAndLeavePriorityRegion(int a1)
{
  unsigned int v1; // r4
  int result; // r0
  __int16 v3; // r3

  ExpReleaseResourceForThreadLite(a1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = PsBoostThreadIoEx(v1, 1, 0);
  v3 = *(_WORD *)(v1 + 308) + 1;
  *(_WORD *)(v1 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
