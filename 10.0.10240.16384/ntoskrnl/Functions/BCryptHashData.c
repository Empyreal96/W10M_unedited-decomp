// BCryptHashData 
 
int __fastcall BCryptHashData(int a1, int a2, int a3)
{
  int v4; // r4
  int v7; // r0

  v4 = -1073741822;
  v7 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v7 )
  {
    v4 = (*(int (__fastcall **)(int, int, int, _DWORD))(v7 + 88))(a1, a2, a3, 0);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v4;
}
