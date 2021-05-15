// AuthzBasepRestartOperandValueEnumeration 
 
_DWORD *__fastcall AuthzBasepRestartOperandValueEnumeration(_DWORD *result)
{
  int v1; // r3
  int v2; // r3
  __int64 v3; // kr00_8

  v1 = result[3];
  result[2] = 0;
  if ( v1 != 1 )
  {
    v2 = result[4];
    if ( v2 )
    {
      *(_DWORD *)(v2 + 28) = 0;
      *(_DWORD *)(result[4] + 32) = 0;
      v3 = *(_QWORD *)(result + 3);
      if ( (_DWORD)v3 == 6 )
        result = (_DWORD *)AuthzBasepQuerySystemSecurityAttributeAndValues(HIDWORD(v3));
      else
        result = (_DWORD *)AuthzBasepQuerySecurityAttributeAndValues((int *)HIDWORD(v3));
    }
  }
  return result;
}
