// KiCleanAllCachesTarget 
 
void __fastcall KiCleanAllCachesTarget(int a1, unsigned int *a2)
{
  unsigned int v2; // r6
  unsigned int i; // r4
  unsigned int v4; // r5
  unsigned int v5; // r0
  char v6; // r2
  unsigned int j; // r3
  char v8; // r7
  char v9; // r8
  int v10; // r5
  int v11; // r2
  unsigned int v12; // r2

  v2 = ((unsigned int)__mrc(15, 1, 0, 0, 1) >> 24) & 7;
  for ( i = 0; i < v2; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v4 = __mrc(15, 1, 0, 0, 0);
    v5 = ((v4 >> 3) & 0x3FF) + 1;
    v6 = 0;
    for ( j = v5 >> 1; j; j >>= 1 )
      ++v6;
    if ( ((v4 >> 3) & 0x3FF & (((v4 >> 3) & 0x3FF) + 1)) != 0 )
      ++v6;
    v8 = 32 - v6;
    v9 = (v4 & 7) + 4;
    v10 = (v4 >> 13) & 0x7FFF;
    do
    {
      --v5;
      v11 = v10 + 1;
      do
        __mcr(15, 0, (--v11 << v9) | (2 * i) | (v5 << v8), 7, 10, 2);
      while ( v11 );
    }
    while ( v5 );
  }
  __dsb(0xFu);
  do
    v12 = __ldrex(a2);
  while ( __strex(v12 - 1, a2) );
  __dmb(0xBu);
}
