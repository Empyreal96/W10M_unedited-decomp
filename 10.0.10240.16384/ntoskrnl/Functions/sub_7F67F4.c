// sub_7F67F4 
 
void __fastcall sub_7F67F4(unsigned int a1)
{
  int v1; // r4
  int v2; // r7
  int v3; // r2

  SepDereferenceLowBoxNumberEntry(a1, *(_DWORD **)(v1 + 628));
  *(_DWORD *)(v1 + 628) = 0;
  *(_DWORD *)(v1 + 120) = v2;
  if ( SepSetTokenLowboxNumber(v1, *(_DWORD *)(v1 + 480), v3, 0) < 0 )
  {
    if ( v1 )
      ObfDereferenceObject(v1);
    JUMPOUT(0x71A06E);
  }
  JUMPOUT(0x719FD0);
}
