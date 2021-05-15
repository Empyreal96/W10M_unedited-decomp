// ExSessionDeleted 
 
int __fastcall ExSessionDeleted(int a1, int a2)
{
  int v2; // r2
  int v3; // r3
  int result; // r0
  unsigned int v5; // r1
  __int16 v6; // r3
  _DWORD v7[2]; // [sp+8h] [bp-8h] BYREF

  v7[0] = a1;
  v7[1] = a2;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  result = ExpWnfDeleteScopeById(1, (int)v7, v2, v3);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
