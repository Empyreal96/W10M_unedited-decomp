// ExUnsubscribeWnfStateChange 
 
int __fastcall ExUnsubscribeWnfStateChange(unsigned int a1)
{
  unsigned int v1; // r2
  int result; // r0
  unsigned int v3; // r1
  __int16 v4; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  result = ExpWnfDeleteSubscription(a1, PsInitialSystemProcess);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_WORD *)(v3 + 0x134) + 1;
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
