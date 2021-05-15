// sub_513D9C 
 
void __fastcall sub_513D9C(unsigned int *a1, int a2, unsigned int a3)
{
  if ( a3 >= *a1 && a3 <= a1[1] )
  {
    if ( a3 + a2 - 1 > a1[1] )
      JUMPOUT(0x430072);
    JUMPOUT(0x430074);
  }
  JUMPOUT(0x43006C);
}
