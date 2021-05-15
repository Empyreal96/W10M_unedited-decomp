// PcwCreateInstance 
 
int __fastcall PcwCreateInstance(_DWORD *a1, int a2, int a3, int a4)
{
  int v8; // r6
  int v9; // r4

  v8 = ExGetExtensionTable(ExpPcwExtensionHost);
  if ( v8 )
  {
    v9 = (*(int (__fastcall **)(_DWORD *, int, int, int))(v8 + 8))(a1, a2, a3, a4);
    ExReleaseExtensionTable(ExpPcwExtensionHost);
  }
  else
  {
    *a1 = 0;
    v9 = ExpPcwDisabledStatus();
  }
  return v9;
}
