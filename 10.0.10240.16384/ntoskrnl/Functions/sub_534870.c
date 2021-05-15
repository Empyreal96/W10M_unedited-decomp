// sub_534870 
 
void __fastcall sub_534870(int a1, unsigned int a2, int a3, unsigned int a4)
{
  do
  {
    if ( a4 > 0xC03FFFFF )
      break;
    a4 <<= 10;
  }
  while ( a4 >= a2 );
  JUMPOUT(0x48EBB2);
}
