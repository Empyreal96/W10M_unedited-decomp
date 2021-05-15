// AlpciDestroyDeferredMessageContext 
 
int __fastcall AlpciDestroyDeferredMessageContext(int *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int result; // r0
  unsigned int v5; // r1
  __int16 v6; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = *a1;
  if ( v3 )
  {
    ObfDereferenceObject(v3);
    *a1 = 0;
  }
  result = a1[1];
  if ( result )
  {
    result = ObfDereferenceObject(result);
    a1[1] = 0;
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
