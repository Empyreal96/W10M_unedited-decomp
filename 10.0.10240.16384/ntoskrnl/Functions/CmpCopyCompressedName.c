// CmpCopyCompressedName 
 
_WORD *__fastcall CmpCopyCompressedName(_WORD *result, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r1
  unsigned int i; // r2
  __int16 v7; // r3

  v4 = a2 >> 1;
  if ( v4 >= a4 )
    v4 = a4;
  for ( i = 0; i < v4; ++result )
  {
    v7 = *(unsigned __int8 *)(i + a3);
    ++i;
    *result = v7;
  }
  return result;
}
