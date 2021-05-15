// RtlInterlockedSetBitRun 
 
unsigned int __fastcall RtlInterlockedSetBitRun(unsigned int result, unsigned int a2, unsigned int a3)
{
  int v4; // r2
  unsigned int *v5; // r6
  int v6; // r2
  int v7; // r4
  int v8; // r2
  unsigned int v9; // r3

  v4 = a2 & 0x1F;
  v5 = (unsigned int *)(*(_DWORD *)(result + 4) + 4 * (a2 >> 5));
  if ( v4 + a3 <= 0x20 )
  {
    if ( a3 == 32 )
    {
      *v5 = -1;
      return result;
    }
    __dmb(0xBu);
    v6 = ((1 << a3) - 1) << v4;
    do
      result = __ldrex(v5);
    while ( __strex(result | v6, v5) );
    goto LABEL_17;
  }
  if ( (a2 & 0x1F) != 0 )
  {
    v7 = 32 - v4;
    __dmb(0xBu);
    v8 = ((1 << (32 - v4)) - 1) << v4;
    do
      result = __ldrex(v5);
    while ( __strex(result | v8, v5) );
    __dmb(0xBu);
    a3 -= v7;
    ++v5;
  }
  if ( a3 >= 0x20 )
  {
    v9 = a3 >> 5;
    do
    {
      a3 -= 32;
      --v9;
      *v5++ = -1;
    }
    while ( v9 );
  }
  if ( a3 )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v5);
    while ( __strex(result | ((1 << a3) - 1), v5) );
LABEL_17:
    __dmb(0xBu);
  }
  return result;
}
