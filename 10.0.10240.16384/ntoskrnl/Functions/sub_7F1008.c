// sub_7F1008 
 
void __fastcall sub_7F1008(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5
  int v11; // r0
  __int16 v12; // r3

  v11 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v12 = *(_WORD *)(v10 + 308) + 1;
  *(_WORD *)(v10 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v11);
  __asm { POP.W           {R3-R6,R11,PC} }
}
