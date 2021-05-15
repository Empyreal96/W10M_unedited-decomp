// PspFindPropertySetEntry 
 
_DWORD *__fastcall PspFindPropertySetEntry(_DWORD *a1, int a2)
{
  _DWORD *v3; // r2
  _DWORD *result; // r0

  v3 = (_DWORD *)*a1;
  result = 0;
  while ( v3 != a1 )
  {
    if ( v3[2] == a2 )
      return v3;
    v3 = (_DWORD *)*v3;
  }
  return result;
}
