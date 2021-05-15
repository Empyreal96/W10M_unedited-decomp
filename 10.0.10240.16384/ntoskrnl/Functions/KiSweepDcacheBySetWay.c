// KiSweepDcacheBySetWay 
 
unsigned int __fastcall KiSweepDcacheBySetWay(unsigned int result, int a2)
{
  unsigned int i; // r4
  unsigned int v3; // r6
  unsigned int v4; // r5
  char v5; // r2
  unsigned int j; // r3
  char v7; // lr
  char v8; // r7
  int v9; // r6
  int v10; // r2
  int v11; // r3

  for ( i = 0; i < result; ++i )
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
      --v4;
      v10 = v9 + 1;
      do
      {
        v11 = (--v10 << v7) | (2 * i) | (v4 << v8);
        if ( a2 )
          __mcr(15, 0, v11, 7, 14, 2);
        else
          __mcr(15, 0, v11, 7, 10, 2);
      }
      while ( v10 );
    }
    while ( v4 );
  }
  return result;
}
