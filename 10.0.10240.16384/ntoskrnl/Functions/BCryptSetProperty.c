// BCryptSetProperty 
 
int __fastcall BCryptSetProperty(int a1, int a2, int a3)
{
  int v4; // r4
  int v6; // r0

  v4 = -1073741822;
  v6 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v6 )
  {
    v4 = (*(int (__fastcall **)(int, const __int16 *, int, int))(v6 + 116))(a1, L"ChainingMode", a3, 32);
    ExReleaseExtensionTable(SepBCryptExtensionHost);
  }
  return v4;
}
