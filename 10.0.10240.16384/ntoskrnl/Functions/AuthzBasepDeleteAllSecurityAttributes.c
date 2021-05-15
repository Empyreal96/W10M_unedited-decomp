// AuthzBasepDeleteAllSecurityAttributes 
 
_DWORD *__fastcall AuthzBasepDeleteAllSecurityAttributes(_DWORD *result)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r5
  _DWORD *v3; // r6

  v1 = result;
  v2 = (_DWORD *)result[1];
  v3 = result + 1;
  while ( v2 != v3 )
  {
    v2[8] |= 4u;
    AuthzBasepAddSecurityAttributeToLists(v1, v2, 0, 1);
    result = AuthzBasepDeleteAllSecurityAttributeValues(v2);
    v2 = (_DWORD *)*v2;
  }
  return result;
}
