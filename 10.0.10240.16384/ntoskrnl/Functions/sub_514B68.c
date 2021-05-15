// sub_514B68 
 
void sub_514B68()
{
  int v0; // r6
  unsigned int v1; // r7
  unsigned int v2; // r3
  int v3; // r7
  unsigned int *v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r0
  unsigned int v7; // r0
  unsigned int v8; // r3
  int v9; // r2
  unsigned int v10; // r0

  v2 = v1 >> 5;
  v3 = v1 & 0x1F;
  v4 = (unsigned int *)(v0 + 4 * v2);
  LOBYTE(v5) = 1;
  if ( (unsigned int)(v3 + 1) > 0x20 )
  {
    if ( v3 )
    {
      __dmb(0xBu);
      do
        v7 = __ldrex(v4);
      while ( __strex(v7 & ~(((1 << (32 - v3)) - 1) << v3), v4) );
      __dmb(0xBu);
      v5 = v3 - 31;
      ++v4;
      if ( (unsigned int)(v3 - 31) >= 0x20 )
      {
        v8 = v5 >> 5;
        do
        {
          v5 -= 32;
          *v4++ = 0;
          --v8;
        }
        while ( v8 );
      }
      if ( !v5 )
LABEL_15:
        JUMPOUT(0x431CB6);
    }
    __dmb(0xBu);
    v9 = ~((1 << v5) - 1);
    do
      v10 = __ldrex(v4);
    while ( __strex(v10 & v9, v4) );
  }
  else
  {
    __dmb(0xBu);
    do
      v6 = __ldrex(v4);
    while ( __strex(v6 & ~(1 << v3), v4) );
  }
  __dmb(0xBu);
  goto LABEL_15;
}
