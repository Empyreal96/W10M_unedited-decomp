// RtlpFreeHandleForAtom 
 
int __fastcall RtlpFreeHandleForAtom(int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r2
  int result; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  v2 = *(unsigned __int16 *)(a2 + 4);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  result = ExMapHandleToPointer(*(_DWORD *)(a1 + 12), 4 * v2);
  if ( result )
    result = ExDestroyHandle(*(_DWORD *)(a1 + 12), 4 * v2);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
