// sub_7D3CF8 
 
void __fastcall sub_7D3CF8(int a1)
{
  int v1; // r4

  if ( !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6D4366);
}
