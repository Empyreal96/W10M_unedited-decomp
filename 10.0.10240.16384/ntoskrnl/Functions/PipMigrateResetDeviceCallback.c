// PipMigrateResetDeviceCallback 
 
int __fastcall PipMigrateResetDeviceCallback(int a1, int a2)
{
  int v4; // r3
  int v6; // [sp+18h] [bp-18h] BYREF
  int v7; // [sp+1Ch] [bp-14h] BYREF
  int v8[4]; // [sp+20h] [bp-10h] BYREF

  v6 = 0;
  v7 = 0;
  v8[0] = 0;
  if ( wcsicmp(a2, L"HTREE\\ROOT\\0") )
  {
    v7 = 4;
    if ( CmGetDeviceRegProp(a1, a2, 0, 11, (int)v8, (int)&v6, (int)&v7) >= 0 && v8[0] == 4 && v7 == 4 )
    {
      v4 = v6;
    }
    else
    {
      v4 = 0;
      v6 = 0;
    }
    if ( (v4 & 0x20) != 0 || (v6 = v4 | 0x20, CmSetDeviceRegProp(a1, a2, 0, 11, 4, (int)&v6, 4, 0) >= 0) )
      PnpSetObjectProperty(a1, a2, 1, 0, 0, (int)DEVPKEY_Device_MigrationRank, 0, 0, 0, 0);
  }
  return 1;
}
