// UnlockRMLog 
 
int __fastcall UnlockRMLog(int a1)
{
  int result; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  result = ExReleaseResourceLite(*(_DWORD *)(a1 + 80));
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
