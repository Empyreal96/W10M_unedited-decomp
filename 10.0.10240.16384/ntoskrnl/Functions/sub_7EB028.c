// sub_7EB028 
 
void __fastcall sub_7EB028(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x70790E);
}
