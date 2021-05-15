// AuthzBasepQueryInternalSecurityAttributesToken 
 
int __fastcall AuthzBasepQueryInternalSecurityAttributesToken(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  int result; // r0
  unsigned int v9; // r4
  unsigned int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = 0;
  if ( !a1 || !a4 || a3 && !a2 )
    return -1073741811;
  *a4 = 0;
  result = AuthzBasepGetInternalSecurityAttributesCopyoutBufferSize(a1, v10);
  if ( result >= 0 )
  {
    v9 = v10[0];
    if ( a3 >= v10[0] )
    {
      result = AuthzBasepCopyoutInternalSecurityAttributes(a1, a2, a3);
      *a4 = v9;
    }
    else
    {
      result = -1073741789;
      *a4 = v10[0];
    }
  }
  return result;
}
