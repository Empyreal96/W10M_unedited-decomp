// sub_7C768C 
 
void __fastcall sub_7C768C(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6CCD6E);
}
