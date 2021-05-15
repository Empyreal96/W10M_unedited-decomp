// sub_81C550 
 
void sub_81C550()
{
  _BYTE *v0; // r4
  int v1; // r2
  int v2; // r3

  if ( SeIsSecureBootDebugPolicyPresent() )
  {
    if ( RtlCheckRegistryKey(2, (int)L"SecureBoot\\AllowSigningPolicyExtension", v1, v2) >= 0 )
      *v0 = 1;
  }
  JUMPOUT(0x7BC990);
}
