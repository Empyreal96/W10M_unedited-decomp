// LsaDeregisterLogonProcess 
 
int __fastcall LsaDeregisterLogonProcess(int a1)
{
  int v2; // r4
  int v3; // r0

  v2 = -1073741822;
  v3 = ExGetExtensionTable(SepAuthExtensionHost);
  if ( v3 )
  {
    v2 = (*(int (__fastcall **)(int))(v3 + 4))(a1);
    ExReleaseExtensionTable(SepAuthExtensionHost);
  }
  return v2;
}
