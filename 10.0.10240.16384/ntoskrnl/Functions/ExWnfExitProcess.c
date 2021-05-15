// ExWnfExitProcess 
 
int __fastcall ExWnfExitProcess(int a1, int a2)
{
  unsigned int v3; // r2
  int result; // r0
  unsigned int v5; // r1
  __int16 v6; // r3
  int vars8[2]; // [sp+10h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  result = *(_DWORD *)(a1 + 724);
  __dmb(0xBu);
  if ( result )
    result = ExpWnfDeleteProcessContext();
  if ( a2 )
    result = ExpWnfDeleteScopeById(3, vars8);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
