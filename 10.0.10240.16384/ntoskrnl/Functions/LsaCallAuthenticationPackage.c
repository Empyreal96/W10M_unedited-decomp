// LsaCallAuthenticationPackage 
 
int __fastcall LsaCallAuthenticationPackage(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r4
  int (__fastcall **v12)(int, int, int, int, int, int, int); // r6

  v8 = -1073741822;
  v12 = (int (__fastcall **)(int, int, int, int, int, int, int))ExGetExtensionTable(SepAuthExtensionHost);
  if ( v12 )
  {
    v8 = (*v12)(a1, a2, a3, a4, a5, a6, a7);
    ExReleaseExtensionTable(SepAuthExtensionHost);
  }
  return v8;
}
