// PipHardwareConfigInit 
 
int __fastcall PipHardwareConfigInit(int a1)
{
  int v2; // r9
  int v3; // r5
  int v5; // r6
  int v6; // r4
  int v7; // r8
  int v8; // r10
  int v9; // r7
  BOOL v10; // r7
  int v11; // r10
  int v12; // r0
  int v13; // r1
  int v14[2]; // [sp+8h] [bp-268h] BYREF
  __int16 v15; // [sp+10h] [bp-260h] BYREF
  __int16 v16; // [sp+12h] [bp-25Eh]
  const __int16 *v17; // [sp+14h] [bp-25Ch]
  int v18; // [sp+18h] [bp-258h]
  __int16 v19; // [sp+20h] [bp-250h] BYREF
  __int16 v20; // [sp+22h] [bp-24Eh]
  const __int16 *v21; // [sp+24h] [bp-24Ch]
  int v22; // [sp+28h] [bp-248h] BYREF
  int v23; // [sp+2Ch] [bp-244h] BYREF
  __int64 v24; // [sp+30h] [bp-240h] BYREF
  __int64 v25; // [sp+38h] [bp-238h] BYREF
  int v26; // [sp+40h] [bp-230h] BYREF
  char v27; // [sp+48h] [bp-228h] BYREF

  v18 = -1;
  v22 = 0;
  v14[0] = 0;
  v20 = 62;
  v19 = 60;
  v2 = 0;
  v21 = L"\\Registry\\Machine\\System\\Setup";
  v3 = 0;
  v23 = 0;
  LODWORD(v24) = 0;
  if ( IopCreateRegistryKeyEx(v14, 0, (int)&v19, 983103, 0, 0) < 0 )
    return sub_96E9C8();
  v5 = v14[0];
  if ( v14[0] )
  {
    v20 = 26;
    v19 = 24;
    v21 = L"Respecialize";
    ZwDeleteValueKey();
  }
  v20 = 80;
  v19 = 78;
  v21 = L"\\Registry\\Machine\\System\\HardwareConfig";
  v6 = IopCreateRegistryKeyEx(&v22, 0, (int)&v19, 983103, 0, 0);
  v7 = v22;
  if ( v6 >= 0 )
  {
    v6 = RtlStringFromGUID(a1, (int)&PnpCurrentHardwareConfigurationGuidString);
    if ( v6 >= 0 )
    {
      v16 = 22;
      v15 = 20;
      v17 = L"LastConfig";
      v6 = ZwSetValueKey();
      if ( v6 >= 0 )
      {
        v6 = IopCreateRegistryKeyEx(&v24, v7, (int)&PnpCurrentHardwareConfigurationGuidString, 983103, 0, &v22);
        v3 = v24;
        if ( v6 >= 0 )
        {
          v6 = -1073741823;
          v8 = IopGetRegistryValue(v24, L"Id", 0, v14);
          if ( v8 >= 0 )
          {
            if ( *(_DWORD *)(v14[0] + 4) == 4 && *(_DWORD *)(v14[0] + 12) == 4 )
              v18 = *(_DWORD *)(*(_DWORD *)(v14[0] + 8) + v14[0]);
            else
              v8 = -1073741823;
            ExFreePoolWithTag(v14[0]);
            if ( v8 >= 0 )
              goto LABEL_14;
          }
          v18 = 0;
          if ( IopGetRegistryValue(v7, L"LastId", 0, v14) >= 0 )
          {
            if ( *(_DWORD *)(v14[0] + 4) == 4 && *(_DWORD *)(v14[0] + 12) == 4 )
              v18 = *(_DWORD *)(*(_DWORD *)(v14[0] + 8) + v14[0]) + 1;
            ExFreePoolWithTag(v14[0]);
          }
          v11 = v18 - 1;
          if ( v18 != v18 - 1 )
          {
            do
            {
              v12 = PipHardwareConfigExists(v7);
              v13 = v18;
              if ( !v12 )
                break;
              v13 = v18 + 1;
              v18 = v13;
            }
            while ( v13 != v11 );
            if ( v13 != v11 )
            {
              v16 = 14;
              v15 = 12;
              v17 = L"LastId";
              ZwSetValueKey();
              v16 = 6;
              v15 = 4;
              v17 = L"Id";
              v6 = ZwSetValueKey();
              if ( v6 >= 0 )
              {
LABEL_14:
                PnpCurrentHardwareConfigurationIndex = v18;
                KeQueryBootTimeValues(&v26, &v25, &v24);
                v25 -= v24;
                v16 = 16;
                v15 = 14;
                v17 = L"LastUse";
                ZwSetValueKey();
                v16 = 16;
                v15 = 14;
                v17 = L"Current";
                v6 = IopCreateRegistryKeyEx(&v23, v7, (int)&v15, 983103, 3, 0);
                if ( v6 < 0
                  || (v17 = (const __int16 *)&v27,
                      v16 = 520,
                      v15 = 0,
                      v6 = RtlUnicodeStringPrintf(
                             &v15,
                             (int)L"\\Registry\\Machine\\System\\HardwareConfig\\%wZ",
                             (int)&PnpCurrentHardwareConfigurationGuidString,
                             0),
                      v6 < 0) )
                {
                  v2 = v23;
                }
                else
                {
                  v2 = v23;
                  v6 = ZwSetValueKey();
                  if ( v6 >= 0 )
                  {
                    if ( InitSafeBootMode
                      || (IopGetRegistryValue(v3, L"Reset", 0, v14) >= 0 ? (*(_DWORD *)(v14[0] + 4) != 4
                                                                         || *(_DWORD *)(v14[0] + 12) != 4 ? (v9 = 0) : (v9 = *(_DWORD *)(*(_DWORD *)(v14[0] + 8) + v14[0])),
                                                                            ExFreePoolWithTag(v14[0])) : (v9 = 0),
                          v9) )
                    {
                      if ( PipHardwareConfigClearStartOverrides() >= 0 )
                      {
                        v20 = 12;
                        v19 = 10;
                        v21 = L"Reset";
                        ZwDeleteValueKey();
                      }
                    }
                    if ( v5 )
                    {
                      v10 = v22 == 1;
                      if ( v22 == 1 )
                        goto LABEL_58;
                      if ( IopGetRegistryValue(v5, L"RespecializeStarted", 0, v14) >= 0 )
                      {
                        if ( *(_DWORD *)(v14[0] + 4) == 4 && *(_DWORD *)(v14[0] + 12) == 4 )
                          v10 = *(_DWORD *)(*(_DWORD *)(v14[0] + 8) + v14[0]) == 1;
                        ExFreePoolWithTag(v14[0]);
                        if ( v10 )
                          goto LABEL_58;
                      }
                      if ( IopGetRegistryValue(v3, L"Respecialize", 0, v14) >= 0 )
                      {
                        if ( *(_DWORD *)(v14[0] + 4) == 4 && *(_DWORD *)(v14[0] + 12) == 4 )
                          v10 = *(_DWORD *)(*(_DWORD *)(v14[0] + 8) + v14[0]) == 1;
                        ExFreePoolWithTag(v14[0]);
                        if ( v10 )
                        {
LABEL_58:
                          if ( PipHardwareConfigTriggerRespecialize(v5) >= 0 )
                          {
                            v20 = 26;
                            v19 = 24;
                            v21 = L"Respecialize";
                            ZwDeleteValueKey();
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v7 )
    ZwClose();
  if ( v3 )
    ZwClose();
  if ( v2 )
    ZwClose();
  if ( v5 )
    ZwClose();
  return v6;
}
