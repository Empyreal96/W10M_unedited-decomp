// KsepDbConvertInteger 
 
int __fastcall KsepDbConvertInteger(int a1, int a2)
{
  unsigned int v3; // r6
  int v4; // r4
  unsigned int v5; // r5
  unsigned int i; // r1
  unsigned int v7; // r4
  unsigned int v8; // r0
  char v9; // r2
  unsigned int j; // r3
  char v11; // r6
  int v12; // r2

  *(_DWORD *)a1 ^= a2;
  *(_BYTE *)(a1 + 9) = *(_BYTE *)(a1 + 9);
  v3 = __mrc(15, 1, 0, 0, 1);
  v4 = __mrc(15, 0, 0, 0, 0);
  v5 = (v3 >> 21) & 7;
  if ( (v4 & 0xFFF0) == 49296 && (v4 & 0xFF000000) == 1090519040 && (v4 & 0xF00000u) < 0x100000 )
    v5 = (v3 >> 27) & 7;
  for ( i = 0; i < v5; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v7 = __mrc(15, 1, 0, 0, 0);
    v8 = ((v7 >> 3) & 0x3FF) + 1;
    v9 = 0;
    for ( j = v8 >> 1; j; j >>= 1 )
      ++v9;
    if ( ((v7 >> 3) & 0x3FF & (((v7 >> 3) & 0x3FF) + 1)) != 0 )
      ++v9;
    v11 = 32 - v9;
    do
    {
      --v8;
      v12 = ((v7 >> 13) & 0x7FFF) + 1;
      do
        __mcr(15, 0, (--v12 << ((v7 & 7) + 4)) | (2 * i) | (v8 << v11), 7, 10, 2);
      while ( v12 );
    }
    while ( v8 );
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 7, 5, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return a1 + 4;
}
