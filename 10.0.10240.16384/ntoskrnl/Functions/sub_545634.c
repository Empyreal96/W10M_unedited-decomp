// sub_545634 
 
void __fastcall sub_545634(int a1)
{
  int v1; // r4

  if ( *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x4BE372);
}
