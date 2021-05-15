// sub_814688 
 
void __fastcall sub_814688(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r2

  if ( a3 != 2 || (v4 = (a4 >> 20) & 0xF) != 0 && (v4 != 2 || (a4 & 0xFFFFF) != 0) )
    JUMPOUT(0x7A79F4);
  JUMPOUT(0x7A79FA);
}
