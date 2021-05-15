// sub_511940 
 
void __fastcall sub_511940(unsigned int a1)
{
  int v1; // r3

  if ( a1 && ((a1 & 0x800) != 0 || (a1 & 0x3E0) != 0) )
  {
    v1 = (a1 >> 5) & 0x1F;
    if ( v1 != 24 && v1 != 31 )
      JUMPOUT(0x42A87C);
  }
  JUMPOUT(0x42A87E);
}
