// AdtpBuildSecurityDescriptorChangeString 
 
int __fastcall AdtpBuildSecurityDescriptorChangeString(int a1, int a2, int a3, int a4, unsigned int *a5, _BYTE *a6, int a7, int a8, int a9, int a10, int a11)
{
  int v13; // r4

  v13 = AdtpBuildSecurityDescriptorUnicodeString(a1, a2, 0, a5, a10, a11, a6);
  if ( v13 >= 0 )
  {
    v13 = AdtpBuildSecurityDescriptorUnicodeString(a1, a3, 0, a8, a10, a11, a9);
    if ( v13 < 0 )
    {
      if ( *a6 )
      {
        *a6 = 0;
        ExFreePoolWithTag(*a5);
      }
    }
  }
  return v13;
}
