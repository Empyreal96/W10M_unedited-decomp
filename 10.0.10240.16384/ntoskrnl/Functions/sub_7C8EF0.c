// sub_7C8EF0 
 
void __fastcall sub_7C8EF0(int a1, int a2)
{
  if ( *(_DWORD *)(a2 + 100) != a2 + 100 && !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x767C8C);
}
