// sub_53D2DC 
 
void __fastcall sub_53D2DC(int a1, int a2, int a3)
{
  _DWORD *v3; // r5

  if ( MiDeleteTransitionPte(v3, 1, a3) != 1 )
    JUMPOUT(0x4A1D42);
  JUMPOUT(0x4A1C28);
}
