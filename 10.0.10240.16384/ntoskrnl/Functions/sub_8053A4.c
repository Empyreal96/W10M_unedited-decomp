// sub_8053A4 
 
void sub_8053A4()
{
  unsigned __int16 *v0; // r5
  unsigned int v1; // r6
  int v2; // r7
  unsigned int v3; // r2
  int i; // r0
  unsigned int v5; // r3
  unsigned int v6; // r3
  unsigned int v7; // t1

  v3 = 0;
  for ( i = 0; ; i += 8 )
  {
    if ( v1 >> 1 <= 4 )
      v5 = v1 >> 1;
    else
      v5 = 4;
    if ( v3 >= v5 || (v7 = *v0, ++v0, v6 = v7, v7 > 0xFF) )
      JUMPOUT(0x74F9AA);
    v2 += v6 << i;
    ++v3;
  }
}
