// AuthzBasepDeleteAllSecurityAttributeValues 
 
_DWORD *__fastcall AuthzBasepDeleteAllSecurityAttributeValues(_DWORD *a1)
{
  _DWORD *result; // r0
  _DWORD *i; // r1
  int v4; // r3

  result = (_DWORD *)AuthzBasepFreeSecurityAttributeValues((int)a1, 1);
  for ( i = (_DWORD *)a1[11]; i != a1 + 11; i = (_DWORD *)*i )
  {
    v4 = i[4];
    if ( (v4 & 2) == 0 )
    {
      i[4] = v4 | 4;
      result = AuthzBasepAddSecurityAttributeValueToLists(a1, i, 0, 1);
    }
  }
  a1[10] = a1[9];
  return result;
}
