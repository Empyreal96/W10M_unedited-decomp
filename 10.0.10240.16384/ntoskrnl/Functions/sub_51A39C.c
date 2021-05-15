// sub_51A39C 
 
void __fastcall sub_51A39C(int a1, int a2, int a3, int a4)
{
  if ( a4 != 14 )
  {
    if ( a4 == 1 || a4 == 11 )
    {
      __mrc(15, 0, 13, 0, 3);
      JUMPOUT(0x43FE78);
    }
    JUMPOUT(0x43FE62);
  }
  JUMPOUT(0x44006E);
}
