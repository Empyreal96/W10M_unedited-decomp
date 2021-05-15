// sub_54B834 
 
void sub_54B834()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  unsigned int *v3; // r4
  unsigned int v4; // r0
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1

  if ( (v0 & v2) != 0 )
  {
    v3 = (unsigned int *)(v0 & ~v2);
    __dmb(0xBu);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 - v1, v3) );
    __dmb(0xBu);
    if ( v4 == v1 )
    {
      __dmb(0xBu);
      v5 = (unsigned __int8 *)(v3 + 5);
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 & 0xFE, v5) );
      __dmb(0xBu);
      if ( (v6 & v2) == 0 )
        KeSetEvent((int)(v3 + 1), 0, 0);
    }
    JUMPOUT(0x4D3FB0);
  }
  JUMPOUT(0x4D3F8E);
}
