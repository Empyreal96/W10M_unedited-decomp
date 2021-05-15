// KiSweepCurrentIcache 
 
unsigned int KiSweepCurrentIcache()
{
  unsigned int result; // r0
  unsigned int v1; // lr
  unsigned int i; // r1
  unsigned int v3; // r0
  unsigned int v4; // r5
  char v5; // r2
  unsigned int j; // r3
  char v7; // r4
  char v8; // r6
  int v9; // r7
  int v10; // r2

  result = __mrc(15, 1, 0, 0, 1);
  v1 = (result >> 21) & 7;
  if ( (__mrc(15, 0, 0, 0, 0) & 0xFFF0) == 49296 )
    return sub_53FB84();
  for ( i = 0; i < v1; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v3 = __mrc(15, 1, 0, 0, 0);
    v4 = ((v3 >> 3) & 0x3FF) + 1;
    v5 = 0;
    for ( j = v4 >> 1; j; j >>= 1 )
      ++v5;
    if ( ((v3 >> 3) & 0x3FF & (((v3 >> 3) & 0x3FF) + 1)) != 0 )
      ++v5;
    v7 = (v3 & 7) + 4;
    v8 = 32 - v5;
    v9 = (v3 >> 13) & 0x7FFF;
    do
    {
      result = --v4 << v8;
      v10 = v9 + 1;
      do
        __mcr(15, 0, (--v10 << v7) | (2 * i) | result, 7, 10, 2);
      while ( v10 );
    }
    while ( v4 );
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 7, 5, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
