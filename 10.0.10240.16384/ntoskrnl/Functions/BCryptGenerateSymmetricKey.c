// BCryptGenerateSymmetricKey 
 
int __fastcall BCryptGenerateSymmetricKey(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r4
  int v11; // r0

  v7 = -1073741822;
  v11 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v11 )
  {
    v7 = (*(int (__fastcall **)(int, int, int, int, int, int, _DWORD))(v11 + 76))(a1, a2, a3, a4, a5, a6, 0);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v7;
}
