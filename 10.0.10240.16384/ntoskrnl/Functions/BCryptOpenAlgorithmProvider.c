// BCryptOpenAlgorithmProvider 
 
int __fastcall BCryptOpenAlgorithmProvider(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v9; // r0

  v5 = -1073741822;
  v9 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v9 )
  {
    v5 = (*(int (__fastcall **)(int, int, int, int))(v9 + 100))(a1, a2, a3, a4);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v5;
}
