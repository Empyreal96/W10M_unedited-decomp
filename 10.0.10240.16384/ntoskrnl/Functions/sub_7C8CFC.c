// sub_7C8CFC 
 
void __fastcall sub_7C8CFC(int a1)
{
  if ( !*(_WORD *)(a1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x767676);
}
