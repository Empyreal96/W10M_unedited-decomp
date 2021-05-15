// sub_54DC60 
 
void __fastcall sub_54DC60(int a1)
{
  int v1; // r4

  if ( *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x4E3F0C);
}
