// PiDevCfgQueryDriverConfiguration 
 
int __fastcall PiDevCfgQueryDriverConfiguration(_DWORD *a1)
{
  int v2; // r4
  unsigned __int16 *v4; // r7
  int v5; // r0
  unsigned __int16 *v6; // r5
  unsigned __int16 *v7; // r5
  int v8; // r1
  int v9; // r3
  int v10; // r3
  int v11; // [sp+0h] [bp-158h]
  char v12[8]; // [sp+8h] [bp-150h] BYREF
  int v13[18]; // [sp+10h] [bp-148h] BYREF
  _DWORD v14[64]; // [sp+58h] [bp-100h] BYREF

  v12[1] = 0;
  v12[0] = 0;
  if ( (a1[25] & 0x20) == 0 )
  {
    v2 = PiDevCfgBuildDriverConfigurationId(a1, a1 + 56);
    if ( v2 < 0 )
      return v2;
    if ( !a1[3] )
      return sub_7E15C8();
  }
  v4 = (unsigned __int16 *)a1[4];
  if ( !v4 )
    return sub_7E15C8();
  memset(v14, 0, 224);
  v14[1] = 288;
  v14[2] = L"Service";
  v14[3] = a1 + 42;
  v14[4] = 0x1000000;
  v14[8] = 304;
  v14[9] = L"LowerFilters";
  v14[15] = 304;
  v14[16] = L"UpperFilters";
  v14[25] = 0x4000000;
  v14[23] = L"ConfigFlags";
  v14[24] = a1 + 54;
  v14[22] = 292;
  v14[29] = 304;
  v14[30] = L"IncludedInfs";
  v14[36] = 304;
  v14[37] = L"IncludedConfigs";
  v14[38] = a1 + 50;
  v14[39] = 117440512;
  v14[46] = 0x4000000;
  v14[43] = 288;
  v14[44] = L"Reboot";
  v14[45] = a1 + 55;
  v14[10] = a1 + 44;
  v14[11] = 117440512;
  v14[17] = a1 + 46;
  v14[18] = 117440512;
  v14[31] = a1 + 48;
  v14[32] = 117440512;
  v5 = RtlpQueryRegistryValues(-1073741824, v4, v14, 0, v11, 1u);
  v2 = v5;
  if ( v5 == -1073741772 )
    return sub_7E15C8();
  if ( v5 >= 0 )
  {
    if ( *((unsigned __int16 *)a1 + 88) <= 2u && a1[45] )
      RtlFreeAnsiString(a1 + 44);
    if ( *((unsigned __int16 *)a1 + 92) <= 2u && a1[47] )
      RtlFreeAnsiString(a1 + 46);
    if ( *((unsigned __int16 *)a1 + 96) <= 2u && a1[49] )
      RtlFreeAnsiString(a1 + 48);
    if ( *((unsigned __int16 *)a1 + 100) <= 2u && a1[51] )
      RtlFreeAnsiString(a1 + 50);
    if ( (a1[25] & 0x20) != 0 )
    {
      if ( (a1[13] & 4) == 0 && a1[43] )
        RtlFreeAnsiString(a1 + 42);
      if ( (a1[13] & 2) == 0 )
      {
        if ( a1[45] )
          RtlFreeAnsiString(a1 + 44);
        if ( a1[47] )
          RtlFreeAnsiString(a1 + 46);
      }
    }
    if ( a1[43] )
    {
      if ( *((_WORD *)a1 + 84) )
      {
        v2 = ((int (*)(void))PiDevCfgVerifyService)();
        if ( v2 < 0 )
          return sub_7E15C8();
      }
    }
    v6 = (unsigned __int16 *)a1[45];
    if ( !v6 )
      goto LABEL_65;
    while ( *v6 )
    {
      v2 = PiDevCfgVerifyService(v6, 0, 0);
      if ( v2 < 0 )
      {
        v2 = -1073741637;
        break;
      }
      v6 += wcslen(v6) + 1;
    }
    if ( v2 >= 0 )
    {
LABEL_65:
      v7 = (unsigned __int16 *)a1[47];
      if ( !v7 )
        goto LABEL_26;
      while ( *v7 )
      {
        v2 = PiDevCfgVerifyService(v7, 0, 0);
        if ( v2 < 0 )
        {
          v2 = -1073741637;
          break;
        }
        v7 += wcslen(v7) + 1;
      }
      if ( v2 >= 0 )
      {
LABEL_26:
        if ( (a1[25] & 0x20) != 0 )
        {
LABEL_37:
          a1[25] |= 1u;
          return v2;
        }
        memset(v13, 0, sizeof(v13));
        v8 = a1[8];
        v13[0] = (int)DEVPKEY_DriverPackage_ClassGuid;
        v13[1] = 13;
        v13[3] = 16;
        v13[6] = (int)DEVPKEY_DriverPackage_ProviderName;
        v13[7] = 18;
        v13[10] = 6;
        v13[12] = (int)DEVPKEY_DriverPackage_NeedsReconfig;
        v13[13] = 17;
        v13[14] = (int)v12;
        v13[15] = 1;
        v9 = a1[2];
        v13[2] = (int)(a1 + 34);
        v13[8] = (int)(a1 + 40);
        v2 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v8, 7, v9, v13, 3);
        if ( v2 >= 0 )
        {
          if ( v13[5] < 0 )
          {
            a1[34] = 0;
            a1[35] = 0;
            a1[36] = 0;
            a1[37] = 0;
LABEL_30:
            if ( v13[11] < 0 )
              RtlInitUnicodeString((unsigned int)(a1 + 40), 0);
            if ( v13[17] >= 0 )
            {
              v10 = v12[0];
            }
            else
            {
              v10 = 0;
              v12[0] = 0;
            }
            if ( v10 == -1 )
              a1[25] |= 0x40u;
            v2 = PiDevCfgQueryIncludedDriverConfigurations(a1);
            if ( v2 < 0 )
              return v2;
            goto LABEL_37;
          }
          v2 = RtlStringFromGUIDEx((int)(a1 + 34), (int)(a1 + 38), 1);
          if ( v2 >= 0 )
            goto LABEL_30;
        }
      }
    }
  }
  return v2;
}
