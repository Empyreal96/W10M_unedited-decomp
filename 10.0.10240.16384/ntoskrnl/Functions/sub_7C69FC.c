// sub_7C69FC 
 
void __fastcall sub_7C69FC(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6C8F30);
}
