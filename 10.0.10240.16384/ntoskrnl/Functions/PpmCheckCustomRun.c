// PpmCheckCustomRun 
 
int __fastcall PpmCheckCustomRun(int a1)
{
  int v2; // r4
  int result; // r0
  unsigned int v4; // r1
  __int16 v5; // r3

  PpmPerfPolicyLock = 0;
  v2 = KfRaiseIrql(2);
  PpmCheckStart(a1);
  result = KfLowerIrql(v2);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x136) + 1;
  *(_WORD *)(v4 + 310) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
