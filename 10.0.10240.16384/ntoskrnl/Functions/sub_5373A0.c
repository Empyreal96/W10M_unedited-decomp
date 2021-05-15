// sub_5373A0 
 
void sub_5373A0()
{
  unsigned int v0; // r4
  int v1; // r6
  int v2; // lr

  do
  {
    if ( !v1 )
      break;
    v0 = (v2 & (v0 >> 10)) - 0x40000000;
    --v1;
  }
  while ( (v0 & 0xFFF) == 0 );
  JUMPOUT(0x4947EA);
}
