// sub_7E2D10 
 
void __fastcall sub_7E2D10(int a1, int a2)
{
  if ( *(_DWORD *)(a2 + 100) != a2 + 100 && !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x77B40A);
}
