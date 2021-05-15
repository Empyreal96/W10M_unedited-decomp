// sub_96A86C 
 
void __fastcall sub_96A86C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  int v11; // r0
  int v12; // r3

  v11 = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v12 = (__int16)(*(_WORD *)(v10 + 308) + 1);
  *(_WORD *)(v10 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v11);
  __asm { POP.W           {R4-R7,R11,PC} }
}
