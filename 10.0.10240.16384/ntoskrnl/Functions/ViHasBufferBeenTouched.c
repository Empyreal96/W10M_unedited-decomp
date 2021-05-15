// ViHasBufferBeenTouched 
 
_BYTE *__fastcall ViHasBufferBeenTouched(_BYTE *result, unsigned int a2)
{
  int v2; // r4
  unsigned int i; // r2
  int v4; // r3
  int v5; // t1
  int v6; // t1

  v2 = 15;
  for ( i = 1; i < 4; i *= 2 )
  {
    v4 = v2 << (8 * i);
    v2 |= v4;
  }
  while ( ((unsigned __int8)result & 3) != 0 && a2 )
  {
    if ( *result != 15 )
      return result;
    ++result;
    --a2;
  }
  while ( a2 >= 4 )
  {
    v5 = *(_DWORD *)result;
    result += 4;
    if ( v5 != v2 )
    {
      result -= 4;
      return result;
    }
    a2 -= 4;
  }
  if ( !a2 )
    return 0;
  while ( 1 )
  {
    v6 = (unsigned __int8)*result++;
    if ( v6 != 15 )
      break;
    if ( !--a2 )
      return 0;
  }
  --result;
  return result;
}
