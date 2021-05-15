// sub_519478 
 
void __fastcall sub_519478(int a1, int a2, int a3)
{
  int v3; // r3

  do
  {
    v3 = __mrc(14, 0, 1, 5, 4);
    __isb(0xFu);
  }
  while ( (v3 & a3) != 0 );
  JUMPOUT(0x4DF4F4);
}
