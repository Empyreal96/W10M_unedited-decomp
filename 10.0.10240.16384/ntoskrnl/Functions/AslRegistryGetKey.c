// AslRegistryGetKey 
 
int __fastcall AslRegistryGetKey(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v8; // [sp+10h] [bp-30h] BYREF
  unsigned int v9; // [sp+14h] [bp-2Ch]
  int v10; // [sp+18h] [bp-28h]
  int v11; // [sp+1Ch] [bp-24h]
  int *v12; // [sp+20h] [bp-20h]
  int v13; // [sp+24h] [bp-1Ch]
  int v14; // [sp+28h] [bp-18h]
  int v15; // [sp+2Ch] [bp-14h]

  v8 = 0;
  v9 = 0;
  *a1 = 0;
  if ( a4 )
  {
    v5 = AslRegistryBuildMachinePath((int)&v8, L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags");
    if ( v5 < 0 )
    {
      AslLogCallPrintf(
        1,
        (int)"AslRegistryGetKey",
        1325,
        "AslRegistryBuildMachinePath failed for %ws [%x]",
        L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags",
        v5);
      goto LABEL_11;
    }
  }
  else
  {
    v5 = AslRegistryBuildUserPath((int)&v8, L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags");
    if ( v5 < 0 )
    {
      AslLogCallPrintf(
        1,
        (int)"AslRegistryGetKey",
        1332,
        "AslRegistryBuildUserPath failed for %ws [%x]",
        L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags",
        v5);
      goto LABEL_11;
    }
  }
  v10 = 24;
  v11 = 0;
  v13 = 576;
  v12 = &v8;
  v14 = 0;
  v15 = 0;
  v6 = ZwOpenKey();
  v5 = v6;
  if ( v6 >= 0 )
  {
    v5 = 0;
    *a1 = 0;
  }
  else if ( v6 != -1073741772 )
  {
    AslLogCallPrintf(
      1,
      (int)"AslRegistryGetKey",
      1368,
      "NtOpenKey failed for %ws [%x]",
      L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags",
      v6);
  }
LABEL_11:
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v5;
}
