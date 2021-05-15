// AlpcpFreeBitmap 
 
int __fastcall AlpcpFreeBitmap(int result, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int *v4; // r6
  int v5; // r1
  unsigned int v7; // r3
  int v8; // r1
  unsigned int v9; // r4
  unsigned int v10; // r1

  v4 = (unsigned int *)(result + 4 * (a3 >> 5));
  v5 = a3 & 0x1F;
  if ( (a3 & 0x1F) != 0 )
  {
    v7 = 32 - v5;
    if ( a4 < 32 - v5 )
      v7 = a4;
    __dmb(0xBu);
    v8 = ~(((1 << v7) - 1) << v5);
    do
    {
      v9 = __ldrex(v4);
      result = v9 & v8;
    }
    while ( __strex(v9 & v8, v4) );
    __dmb(0xBu);
    a4 -= v7;
    ++v4;
  }
  if ( a4 >= 0x20 )
  {
    result = a4 >> 5;
    do
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(v4);
      while ( __strex(0, v4) );
      __dmb(0xBu);
      a4 -= 32;
      ++v4;
      --result;
    }
    while ( result );
  }
  if ( a4 )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v4);
    while ( __strex(result & ~((1 << a4) - 1), v4) );
    __dmb(0xBu);
  }
  return result;
}
