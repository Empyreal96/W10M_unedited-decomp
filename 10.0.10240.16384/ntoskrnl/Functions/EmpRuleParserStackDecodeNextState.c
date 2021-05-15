// EmpRuleParserStackDecodeNextState 
 
int __fastcall EmpRuleParserStackDecodeNextState(int a1, int a2)
{
  unsigned int v2; // r5
  int v3; // r4
  unsigned int v4; // r6
  unsigned int i; // r1
  unsigned int v6; // r5
  unsigned int v7; // r4
  char v8; // r2
  unsigned int j; // r3
  char v10; // r7
  int v11; // r2

  if ( (__mrc(15, 0, 13, 0, 3) & 0x180) != 0 )
    *(_BYTE *)(a1 + 8) = *(_BYTE *)(a1 + 8);
  *(_DWORD *)a1 ^= a2;
  v2 = __mrc(15, 1, 0, 0, 1);
  v3 = __mrc(15, 0, 0, 0, 0);
  v4 = (v2 >> 21) & 7;
  if ( (v3 & 0xFFF0) == 49296 && (v3 & 0xFF000000) == 1090519040 && (v3 & 0xF00000u) < 0x100000 )
    v4 = (v2 >> 27) & 7;
  for ( i = 0; i < v4; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v6 = __mrc(15, 1, 0, 0, 0);
    v7 = ((v6 >> 3) & 0x3FF) + 1;
    v8 = 0;
    for ( j = v7 >> 1; j; j >>= 1 )
      ++v8;
    if ( ((v6 >> 3) & 0x3FF & (((v6 >> 3) & 0x3FF) + 1)) != 0 )
      ++v8;
    v10 = 32 - v8;
    do
    {
      --v7;
      v11 = ((v6 >> 13) & 0x7FFF) + 1;
      do
        __mcr(15, 0, (--v11 << ((v6 & 7) + 4)) | (2 * i) | (v7 << v10), 7, 10, 2);
      while ( v11 );
    }
    while ( v7 );
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 7, 5, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return a1 + 4;
}
