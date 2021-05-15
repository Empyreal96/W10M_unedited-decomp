// PcwRegister 
 
int __fastcall PcwRegister(int a1, int a2)
{
  int (__fastcall **v4)(int, int); // r0
  int v6; // r4

  v4 = (int (__fastcall **)(int, int))ExGetExtensionTable(ExpPcwExtensionHost);
  if ( !v4 )
    return sub_811454();
  v6 = (*v4)(a1, a2);
  ExReleaseExtensionTable(ExpPcwExtensionHost);
  return v6;
}
