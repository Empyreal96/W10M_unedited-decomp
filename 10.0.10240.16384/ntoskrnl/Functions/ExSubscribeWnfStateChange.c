// ExSubscribeWnfStateChange 
 
int __fastcall ExSubscribeWnfStateChange(unsigned int *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r1
  __int16 v10; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = ExpWnfSubscribeWnfStateChange(0, a1, a2, a4, a5, a6, a3, 0);
  v8 = v7;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return v8;
}
