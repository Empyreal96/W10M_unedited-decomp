// sub_555630 
 
void __fastcall sub_555630(unsigned int *a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r6
  unsigned int v3; // r7
  unsigned int v4; // lr
  unsigned int v5; // r3

  while ( 1 )
  {
    v5 = a1[1];
    if ( v2 < v5 && v1 > *a1 )
    {
      if ( v2 < *a1 )
      {
        if ( v1 <= v5 )
          v1 = *a1;
      }
      else
      {
        if ( v1 <= v5 )
          JUMPOUT(0x4F812E);
        v2 = a1[1];
      }
    }
    ++v3;
    a1 += 2;
    if ( v3 >= v4 )
      JUMPOUT(0x4F8110);
  }
}
