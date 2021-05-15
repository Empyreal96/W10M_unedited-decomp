// MiLocateExclusiveSecure 
 
_DWORD *__fastcall MiLocateExclusiveSecure(int a1)
{
  _DWORD *result; // r0

  for ( result = *(_DWORD **)(a1 + 36); result; result = (_DWORD *)*result )
  {
    if ( result[1] == 2 )
    {
      if ( (result[2] & 0x20) != 0 )
        return result;
      return 0;
    }
  }
  return 0;
}
