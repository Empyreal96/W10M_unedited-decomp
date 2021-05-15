// AuthzBasepAddSecurityAttributeToLists 
 
_DWORD *__fastcall AuthzBasepAddSecurityAttributeToLists(_DWORD *result, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r4
  _DWORD *v5; // r6
  _DWORD *v6; // r5

  v4 = result;
  if ( a4 && (a2[8] & 2) == 0 )
  {
    result += 4;
    v5 = (_DWORD *)result[1];
    v6 = a2 + 2;
    a2[2] = result;
    a2[3] = v5;
    if ( (_DWORD *)*v5 != result )
      sub_52ADBC();
    *v5 = v6;
    result[1] = v6;
    a2[8] |= 2u;
    ++v4[3];
  }
  if ( a3 && (a2[8] & 1) == 0 )
  {
    result = (_DWORD *)v4[2];
    *a2 = v4 + 1;
    a2[1] = result;
    if ( (_DWORD *)*result != v4 + 1 )
      __fastfail(3u);
    *result = a2;
    v4[2] = a2;
    a2[8] |= 1u;
    ++*v4;
  }
  return result;
}
