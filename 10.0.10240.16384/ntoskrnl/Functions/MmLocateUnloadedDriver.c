// MmLocateUnloadedDriver 
 
_DWORD *__fastcall MmLocateUnloadedDriver(unsigned int a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r1
  _DWORD *result; // r0

  if ( !dword_634F88 )
    return 0;
  v2 = dword_634F84 - 1;
  v3 = 0;
  while ( 1 )
  {
    if ( v2 >= 0x32 )
      v2 = 49;
    result = (_DWORD *)(dword_634F88 + 24 * v2);
    if ( result[1] )
    {
      if ( a1 >= result[2] && a1 < result[3] )
        break;
    }
    ++v3;
    --v2;
    if ( v3 >= 0x32 )
      return 0;
  }
  return result;
}
