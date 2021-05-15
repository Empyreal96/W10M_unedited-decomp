// KiUnlockKobjectArray 
 
unsigned int *__fastcall KiUnlockKobjectArray(unsigned int *result, unsigned int a2)
{
  unsigned int *v2; // r6
  unsigned int v3; // r4
  unsigned int **v4; // r5
  unsigned int v5; // r4
  unsigned int *v6; // t1
  unsigned int v7; // r1

  v2 = (unsigned int *)*result;
  __dmb(0xBu);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0xFFFFFF7F, v2) );
  if ( a2 > 1 )
  {
    v4 = (unsigned int **)(result + 1);
    v5 = a2 - 1;
    do
    {
      v6 = *v4++;
      result = v6;
      if ( v6 != v2 )
      {
        v2 = result;
        __dmb(0xBu);
        do
          v7 = __ldrex(result);
        while ( __strex(v7 & 0xFFFFFF7F, result) );
      }
      --v5;
    }
    while ( v5 );
  }
  return result;
}
