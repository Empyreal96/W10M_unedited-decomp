// BCryptFinishHash 
 
int __fastcall BCryptFinishHash(int a1, int a2)
{
  int v3; // r4
  int v5; // r0

  v3 = -1073741822;
  v5 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v5 )
  {
    v3 = (*(int (__fastcall **)(int, int, int, _DWORD))(v5 + 60))(a1, a2, 20, 0);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v3;
}
