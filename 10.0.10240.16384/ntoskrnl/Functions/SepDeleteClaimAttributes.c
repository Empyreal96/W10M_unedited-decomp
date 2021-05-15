// SepDeleteClaimAttributes 
 
unsigned int __fastcall SepDeleteClaimAttributes(unsigned int result)
{
  _DWORD *v1; // r4
  int v2; // r0
  int v3; // r0
  unsigned int v4; // r0

  v1 = (_DWORD *)result;
  if ( result )
  {
    v2 = *(_DWORD *)(result + 288);
    if ( v2 )
    {
      AuthzBasepFreeSecurityAttributesList(v2);
      ExFreePoolWithTag(v1[72]);
      v1[72] = 0;
    }
    v3 = v1[73];
    if ( v3 )
    {
      AuthzBasepFreeSecurityAttributesList(v3);
      ExFreePoolWithTag(v1[73]);
      v1[73] = 0;
    }
    v4 = v1[1];
    if ( v4 )
    {
      ExFreePoolWithTag(v4);
      v1[1] = 0;
    }
    result = ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
