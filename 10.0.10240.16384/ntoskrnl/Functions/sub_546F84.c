// sub_546F84 
 
void __fastcall sub_546F84(int a1)
{
  int v1; // r4

  if ( *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x4C3796);
}
