// sub_80DD30 
 
void __fastcall sub_80DD30(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x795410);
}
