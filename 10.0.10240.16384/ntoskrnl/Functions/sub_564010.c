// sub_564010 
 
unsigned int __fastcall sub_564010(unsigned int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r6
  unsigned int v5; // r5
  unsigned int v6; // r4

  v4 = a2;
  v5 = a1;
  v6 = 0;
  if ( a1 < a2 )
    v4 = a1;
  if ( v4 )
  {
    do
    {
      if ( !MiIsAddressValid(v5, 0, a3, a4) )
        break;
      ++v6;
      --v5;
    }
    while ( v6 < v4 );
  }
  return v6;
}
