// sub_7DF048 
 
void __fastcall sub_7DF048(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6EE142);
}
