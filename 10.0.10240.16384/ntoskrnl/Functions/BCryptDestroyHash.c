// BCryptDestroyHash 
 
int __fastcall BCryptDestroyHash(int a1)
{
  int v2; // r4
  int v3; // r0

  v2 = -1073741822;
  v3 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v3 )
  {
    v2 = (*(int (__fastcall **)(int))(v3 + 28))(a1);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v2;
}
