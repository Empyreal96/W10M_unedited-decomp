// PspUnlockJobChain 
 
int __fastcall PspUnlockJobChain(int a1, int a2)
{
  int result; // r0
  __int16 v5; // r3

  result = ExReleaseResourceLite(a1 + 32);
  if ( *(_DWORD *)(a1 + 588) )
  {
    result = ExReleaseResourceLite(*(_DWORD *)(a1 + 572) + 32);
    if ( *(_DWORD *)(a1 + 588) > 1u )
      return sub_7C2D48(result);
  }
  if ( a2 )
  {
    v5 = *(_WORD *)(a2 + 310) + 1;
    *(_WORD *)(a2 + 310) = v5;
    if ( !v5 && *(_DWORD *)(a2 + 100) != a2 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
