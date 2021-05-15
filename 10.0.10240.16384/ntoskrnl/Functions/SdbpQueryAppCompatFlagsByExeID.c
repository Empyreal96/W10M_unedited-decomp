// SdbpQueryAppCompatFlagsByExeID 
 
int __fastcall SdbpQueryAppCompatFlagsByExeID(int a1, int a2, int a3, int *a4)
{
  int v5; // r5
  int v7; // r0
  int v8; // r4
  int v9; // r6
  int v10; // r0
  int v12; // [sp+8h] [bp-20h] BYREF
  int v13[7]; // [sp+Ch] [bp-1Ch] BYREF

  v5 = 0;
  v12 = 0;
  v13[0] = 0;
  v7 = AslRegistryGetKey(v13);
  v8 = v7;
  v9 = v13[0];
  if ( v7 >= 0 )
  {
    v10 = AslRegistryGetUInt32(&v12, v13[0], a2);
    v8 = v10;
    if ( v10 >= 0 )
    {
      v8 = 0;
    }
    else if ( v10 != -1073741772 )
    {
      AslLogCallPrintf(
        1,
        (int)"SdbpQueryAppCompatFlagsByExeID",
        75,
        "AslRegistryGetUInt32 failed for key: '%ws' [%x]",
        L"\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags",
        v10);
    }
    v5 = v12;
  }
  else if ( v7 != -1073741772 )
  {
    AslLogCallPrintf(1, (int)"SdbpQueryAppCompatFlagsByExeID", 64, "AslRegistryGetKey failed [%x]", v7);
  }
  *a4 = v5;
  if ( v9 )
    ZwClose();
  return v8;
}
