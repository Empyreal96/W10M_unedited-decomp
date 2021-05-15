// sub_7C2D08 
 
void __fastcall sub_7C2D08(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r8
  unsigned int v6; // lr

  if ( v6 >= a2 && (v6 > a2 || v3 > a3) )
  {
    if ( ObReferenceObjectSafeWithTag(v4) )
      *(_DWORD *)(v5 + 12) = v4;
  }
  JUMPOUT(0x6B0514);
}
