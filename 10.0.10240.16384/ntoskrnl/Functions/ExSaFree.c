// ExSaFree 
 
int __fastcall ExSaFree(unsigned int a1)
{
  int v1; // r2
  unsigned int v2; // r3
  int v4; // r1
  int v5; // r0
  unsigned int v6; // r2
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v1 = (a1 >> 13) & 0x3FFFF;
  v2 = __clz(v1);
  v4 = *(_DWORD *)(*(_DWORD *)(ExSaPageGroupDescriptorArray + 4 * (29 - v2)) + 4 * (v1 ^ (1 << (31 - v2))) + 4);
  v5 = *(_DWORD *)(v4 + 8);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 310);
  result = ExpSaAllocatorFree(v5, v4, a1, 2);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x136) + 1;
  *(_WORD *)(v8 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
