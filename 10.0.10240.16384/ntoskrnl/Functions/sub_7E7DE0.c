// sub_7E7DE0 
 
void sub_7E7DE0()
{
  int v0; // r4
  int v1; // r8
  _DWORD *v2; // r0

  v2 = AuthzBasepFindSecurityAttribute(v1, v0 + 16);
  if ( v2 )
  {
    if ( AuthzBasepCompareSecurityAttribute(v0, v2) )
      JUMPOUT(0x6F9A18);
  }
  JUMPOUT(0x6F9A04);
}
