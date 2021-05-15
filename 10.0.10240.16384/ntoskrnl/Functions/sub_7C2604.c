// sub_7C2604 
 
void __fastcall sub_7C2604(int a1)
{
  int v1; // r5

  if ( *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6AD43C);
}
