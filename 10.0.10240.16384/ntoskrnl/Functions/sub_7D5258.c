// sub_7D5258 
 
void __fastcall sub_7D5258(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6D819C);
}
