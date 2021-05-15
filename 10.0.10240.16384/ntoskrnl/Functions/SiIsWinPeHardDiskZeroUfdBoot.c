// SiIsWinPeHardDiskZeroUfdBoot 
 
int __fastcall SiIsWinPeHardDiskZeroUfdBoot(int a1)
{
  int v1; // r4
  unsigned int v2; // r0
  int v3; // r0
  bool v4; // zf
  unsigned __int16 *v6; // [sp+8h] [bp-58h] BYREF
  int v7; // [sp+Ch] [bp-54h] BYREF
  unsigned __int16 *v8; // [sp+10h] [bp-50h] BYREF
  int v9; // [sp+14h] [bp-4Ch] BYREF
  int v10; // [sp+18h] [bp-48h] BYREF
  int v11; // [sp+20h] [bp-40h]
  int v12; // [sp+24h] [bp-3Ch]
  int v13; // [sp+28h] [bp-38h]
  int v14[10]; // [sp+30h] [bp-30h] BYREF

  if ( !SiIsWinPEBoot(a1) )
    return 0;
  v1 = 0;
  if ( SiGetFirmwareBootDeviceNameFromRegistry(&v6) >= 0 )
  {
    v2 = wcslen(v6);
    if ( snwscanf_s((int)v6, v2 + 1, (int)L"multi(%d)disk(%d)rdisk(%d)", &v10, &v9, &v7) == 3
      && !v10
      && !v9
      && !v7
      && SiTranslateSymbolicLink(L"\\ArcName\\multi(0)disk(0)rdisk(0)", &v8) >= 0 )
    {
      ExFreePoolWithTag((unsigned int)v6);
      v13 = 0;
      memset(v14, 0, sizeof(v14));
      v11 = 0;
      v12 = 0;
      v3 = SiIssueSynchronousIoctl(v8);
      if ( v3 >= 0 )
        v4 = v14[7] == 7;
      else
        v4 = v3 == -1073741766;
      if ( v4 )
        v1 = 1;
    }
  }
  return v1;
}
