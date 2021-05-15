// PcwAddInstance 
 
int __fastcall PcwAddInstance(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  int v10; // r4

  v8 = ExGetExtensionTable(ExpPcwExtensionHost);
  if ( !v8 )
    return sub_7E98F8();
  v10 = (*(int (__fastcall **)(int, int, int, int))(v8 + 16))(a1, a2, a3, a4);
  ExReleaseExtensionTable(ExpPcwExtensionHost);
  return v10;
}
