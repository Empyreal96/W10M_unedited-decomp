// sub_50B9DC 
 
void __fastcall sub_50B9DC(int a1)
{
  int v1; // r5

  if ( !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x464868);
}
