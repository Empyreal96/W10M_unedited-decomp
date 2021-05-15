// AuthzBasepAllocateSecurityAttributesList 
 
_DWORD *__fastcall AuthzBasepAllocateSecurityAttributesList(int a1, int a2)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4

  v2 = (_BYTE *)AuthzBasepMemAlloc(24, a2, 1950442835);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 24);
    v3[1] = v3 + 1;
    v3[2] = v3 + 1;
    *v3 = 0;
    v3[4] = v3 + 4;
    v3[5] = v3 + 4;
    v3[3] = 0;
  }
  return v3;
}
