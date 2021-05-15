// PspNetRateControlDispatch 
 
int __fastcall PspNetRateControlDispatch(int a1)
{
  int (__fastcall **v2)(int); // r0
  int v3; // r4

  v2 = (int (__fastcall **)(int))ExGetExtensionTable(PspNetRateControlExtensionHost);
  if ( !v2 )
    return -1073741822;
  v3 = (*v2)(a1);
  ExReleaseExtensionTable(PspNetRateControlExtensionHost);
  return v3;
}
