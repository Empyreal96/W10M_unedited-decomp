// sub_52759C 
 
void sub_52759C()
{
  unsigned int v0; // r5
  unsigned int v1; // r6
  int v2; // r8
  _QWORD *v3; // r9
  int v4; // r10
  unsigned int i; // r4

  while ( 1 )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( MiZeroPageWrite(v4, v3, 0x40000000u, v2) < 0 )
        JUMPOUT(0x4D8AC8);
      v1 = (__PAIR64__(v1, v0) - 0x40000000) >> 32;
      v0 -= 0x40000000;
    }
    if ( !v1 )
      JUMPOUT(0x4D8ABA);
  }
}
