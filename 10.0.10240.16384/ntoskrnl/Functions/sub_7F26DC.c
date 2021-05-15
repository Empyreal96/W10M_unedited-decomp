// sub_7F26DC 
 
void __fastcall sub_7F26DC(int a1)
{
  int v1; // r6

  if ( !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x708F3C);
}
