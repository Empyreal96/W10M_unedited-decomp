// KiSetSafeToPowerDownFrozenProcessor 
 
unsigned int __fastcall KiSetSafeToPowerDownFrozenProcessor(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int result; // r0
  unsigned int *v4; // r2

  __dmb(0xBu);
  if ( a2 )
  {
    v2 = (unsigned int *)(a1 + 18240);
    do
      result = __ldrex(v2);
    while ( __strex(result | 2, v2) );
  }
  else
  {
    v4 = (unsigned int *)(a1 + 18240);
    do
      result = __ldrex(v4);
    while ( __strex(result & 0xFFFFFFFD, v4) );
  }
  __dmb(0xBu);
  return result;
}
