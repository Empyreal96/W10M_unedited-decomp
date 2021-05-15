// KiInvalidateCurrentCache 
 
unsigned int KiInvalidateCurrentCache()
{
  unsigned int v0; // lr
  unsigned int result; // r0
  unsigned int v2; // r1
  unsigned int v3; // r5
  char v4; // r2
  unsigned int i; // r3
  char v6; // r6
  int v7; // r2

  v0 = ((unsigned int)__mrc(15, 1, 0, 0, 1) >> 24) & 7;
  for ( result = 0; result < v0; ++result )
  {
    __mcr(15, 2, 2 * (result & 7), 0, 0, 0);
    __isb(0xFu);
    v2 = __mrc(15, 1, 0, 0, 0);
    v3 = ((v2 >> 3) & 0x3FF) + 1;
    v4 = 0;
    for ( i = v3 >> 1; i; i >>= 1 )
      ++v4;
    if ( ((v2 >> 3) & 0x3FF & (((v2 >> 3) & 0x3FF) + 1)) != 0 )
      ++v4;
    v6 = 32 - v4;
    do
    {
      --v3;
      v7 = ((v2 >> 13) & 0x7FFF) + 1;
      do
        __mcr(15, 0, (--v7 << ((v2 & 7) + 4)) | (2 * result) | (v3 << v6), 7, 14, 2);
      while ( v7 );
    }
    while ( v3 );
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 7, 5, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
