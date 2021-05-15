// LsaLookupAuthenticationPackage 
 
int __fastcall LsaLookupAuthenticationPackage(int a1, int a2, int a3)
{
  int v4; // r4
  int v7; // r0

  v4 = -1073741822;
  v7 = ExGetExtensionTable(SepAuthExtensionHost);
  if ( v7 )
  {
    v4 = (*(int (__fastcall **)(int, int, int))(v7 + 16))(a1, a2, a3);
    ExReleaseExtensionTable(SepAuthExtensionHost);
  }
  return v4;
}
