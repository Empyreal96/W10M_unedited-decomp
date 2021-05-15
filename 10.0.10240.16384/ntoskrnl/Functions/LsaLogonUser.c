// LsaLogonUser 
 
int __fastcall LsaLogonUser(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v15; // r4
  int v19; // r6

  v15 = -1073741822;
  v19 = ExGetExtensionTable(SepAuthExtensionHost);
  if ( v19 )
  {
    v15 = (*(int (__fastcall **)(int, int, int, int, int, int, int, int, int, int, int, int, int, int))(v19 + 12))(
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14);
    ExReleaseExtensionTable(SepAuthExtensionHost);
  }
  return v15;
}
