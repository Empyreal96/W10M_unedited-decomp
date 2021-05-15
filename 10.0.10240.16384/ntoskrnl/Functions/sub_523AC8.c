// sub_523AC8 
 
void __fastcall sub_523AC8(int a1, int a2, int a3)
{
  unsigned int v3; // r4

  if ( MmIsSpecialPoolAddress(v3, a2, a3) )
    JUMPOUT(0x45C31C);
  JUMPOUT(0x45C2B4);
}
