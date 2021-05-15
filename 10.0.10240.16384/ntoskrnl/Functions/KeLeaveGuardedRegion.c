// KeLeaveGuardedRegion 
 
int __fastcall KeLeaveGuardedRegion(int result)
{
  unsigned int v1; // r1
  __int16 v2; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(v1 + 0x136) + 1;
  *(_WORD *)(v1 + 310) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
