// sub_80FA60 
 
void __fastcall sub_80FA60(int a1)
{
  int v1; // r5

  if ( !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x79A96C);
}
