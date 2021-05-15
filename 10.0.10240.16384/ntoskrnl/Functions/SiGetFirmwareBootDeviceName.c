// SiGetFirmwareBootDeviceName 
 
int __fastcall SiGetFirmwareBootDeviceName(int a1, _DWORD *a2)
{
  int v2; // r4
  unsigned __int16 *v3; // r8
  unsigned int v4; // r4
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r6
  unsigned int v8; // r5
  unsigned int v10; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 *v11; // [sp+14h] [bp-34h] BYREF
  int v12; // [sp+18h] [bp-30h] BYREF
  int v13; // [sp+1Ch] [bp-2Ch] BYREF
  char v14; // [sp+20h] [bp-28h] BYREF
  char v15; // [sp+24h] [bp-24h] BYREF

  v10 = 0;
  v11 = 0;
  *a2 = 0;
  v2 = SiGetFirmwareBootDeviceNameFromRegistry(&v11);
  v3 = v11;
  if ( v2 >= 0 )
  {
    v4 = wcslen(v11);
    if ( snwscanf_s((int)v3, v4 + 1, (int)L"multi(%d)disk(%d)rdisk(%d)partition(%d)", &v12, &v13, &v15, &v14) == 4 )
    {
      if ( v12 || v13 )
        JUMPOUT(0x815804);
      v5 = v4 + 11;
      v6 = ExAllocatePoolWithTag(1, 2 * v5, 1263556947);
      v7 = v6;
      if ( v6 )
      {
        swprintf_s(v6, v5, (int)L"%s%s", L"\\ArcName\\", v3);
        v2 = SiTranslateSymbolicLink(v7, &v10);
        if ( v2 < 0 )
        {
          v8 = v10;
        }
        else
        {
          v8 = v10;
          v2 = SiValidateSystemPartition(v10);
          if ( v2 >= 0 )
            return sub_8157A8();
        }
        if ( v8 )
          ExFreePoolWithTag(v8);
        if ( v7 )
          ExFreePoolWithTag(v7);
      }
      else
      {
        v2 = -1073741670;
      }
    }
    else
    {
      v2 = -1073741823;
    }
  }
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v2;
}
