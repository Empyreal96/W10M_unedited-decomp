// sub_7DC04C 
 
void __fastcall sub_7DC04C(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6E70A4);
}
