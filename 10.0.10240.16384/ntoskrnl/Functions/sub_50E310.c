// sub_50E310 
 
void __fastcall sub_50E310(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r10

  if ( (*(_DWORD *)(a2 + 16) & 0x2000) != 0 )
  {
    MiChangePageAttribute(v6, 1, 0);
    if ( a6 != 1 )
      JUMPOUT(0x4B3FEC);
  }
  JUMPOUT(0x4B3FEA);
}
