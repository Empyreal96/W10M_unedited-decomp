// sub_96A790 
 
void __fastcall sub_96A790(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r6
  int v17; // r3

  v17 = (__int16)(*(_WORD *)(v16 + 310) + 1);
  *(_WORD *)(v16 + 310) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 )
    KiCheckForKernelApcDelivery(a1);
  __asm { POP.W           {R0-R9,R11,PC} }
}
