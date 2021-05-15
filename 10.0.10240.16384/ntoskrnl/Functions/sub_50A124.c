// sub_50A124 
 
void __fastcall sub_50A124(unsigned int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r10
  unsigned int v5; // r3
  int v6; // r2

  if ( a4 <= a1 )
  {
    v5 = (a4 & 0xFFFFF000) << 10;
    v6 = 4;
    do
    {
      __mcr(15, 0, v5, 8, 7, 3);
      v5 += v4;
      --v6;
    }
    while ( v6 );
  }
  JUMPOUT(0x4316E8);
}
