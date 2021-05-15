// IopInitCrashDumpDuringSysInit 
 
int __fastcall IopInitCrashDumpDuringSysInit(int a1)
{
  int v2; // r0
  char v4; // [sp+8h] [bp-50h] BYREF
  __int16 v5; // [sp+10h] [bp-48h]
  int v6; // [sp+12h] [bp-46h]
  __int16 v7; // [sp+16h] [bp-42h]
  int v8[16]; // [sp+18h] [bp-40h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  IopReportBugCheckProgress = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))HalSetEnvironmentVariableEx;
  IopBuildSpecialMemoryTable();
  memset(v8, 0, 56);
  v8[0] = (int)IopInitCrashDumpRegCallback;
  v8[1] = 4;
  v8[2] = (int)L"ExistingPageFiles";
  v8[3] = (int)&v4;
  v8[4] = 0;
  v2 = RtlQueryRegistryValuesEx(2, (int)L"Session Manager\\Memory Management", (int)v8, a1);
  if ( !v4 )
    return sub_9695A0(v2);
  IopInitializeOfflineCrashDump(*(_DWORD **)(a1 + 132));
  return 0;
}
