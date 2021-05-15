// sub_819BF4 
 
void __fastcall sub_819BF4(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x7B613E);
}
