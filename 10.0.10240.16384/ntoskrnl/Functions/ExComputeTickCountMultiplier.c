// ExComputeTickCountMultiplier 
 
int __fastcall ExComputeTickCountMultiplier(unsigned int a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r0

  v1 = a1 / 0x2710;
  v2 = a1 % 0x2710;
  v3 = 0;
  v4 = 24;
  do
  {
    v2 *= 2;
    v3 *= 2;
    if ( v2 >= 0x2710 )
    {
      v2 -= 10000;
      v3 |= 1u;
    }
    --v4;
  }
  while ( v4 );
  return v3 | (v1 << 24);
}
