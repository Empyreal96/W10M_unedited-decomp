// AuthzBasepAllocateSecurityAttributeValue 
 
_BYTE *__fastcall AuthzBasepAllocateSecurityAttributeValue(int a1)
{
  _BYTE *v1; // r0
  _BYTE *v2; // r4

  v1 = (_BYTE *)AuthzBasepMemAlloc(a1 + 40);
  v2 = v1;
  if ( v1 )
    memset(v1, 0, 40);
  return v2;
}
