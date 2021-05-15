// SepFreePrimaryGroup 
 
_DWORD *__fastcall SepFreePrimaryGroup(_DWORD *result)
{
  int v1; // r1
  _DWORD *v2; // r4

  v1 = result[41];
  v2 = result;
  result[35] += 4 * (*(unsigned __int8 *)(result[39] + 1) + 2);
  if ( v1 )
  {
    result = (_DWORD *)result[40];
    if ( result != (_DWORD *)v1 )
    {
      result = (_DWORD *)memmove((int)result, v1, *(unsigned __int16 *)(v1 + 2));
      v2[41] = v2[40];
    }
  }
  return result;
}
