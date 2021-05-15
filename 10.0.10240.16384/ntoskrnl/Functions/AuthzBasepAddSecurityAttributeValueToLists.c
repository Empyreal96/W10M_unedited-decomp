// AuthzBasepAddSecurityAttributeValueToLists 
 
_DWORD *__fastcall AuthzBasepAddSecurityAttributeValueToLists(_DWORD *result, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r4
  _DWORD *v5; // r6
  _DWORD *v6; // r5

  v4 = result;
  if ( a4 && (a2[4] & 2) == 0 )
  {
    result += 14;
    v5 = (_DWORD *)result[1];
    v6 = a2 + 2;
    a2[2] = result;
    a2[3] = v5;
    if ( (_DWORD *)*v5 != result )
      sub_517DB4();
    *v5 = v6;
    result[1] = v6;
    a2[4] |= 2u;
    ++v4[13];
  }
  if ( a3 && (a2[4] & 1) == 0 )
  {
    result = (_DWORD *)v4[12];
    *a2 = v4 + 11;
    a2[1] = result;
    if ( (_DWORD *)*result != v4 + 11 )
      __fastfail(3u);
    *result = a2;
    v4[12] = a2;
    a2[4] |= 1u;
    ++v4[9];
  }
  return result;
}
