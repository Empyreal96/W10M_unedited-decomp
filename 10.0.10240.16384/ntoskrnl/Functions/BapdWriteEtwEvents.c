// BapdWriteEtwEvents 
 
int __fastcall BapdWriteEtwEvents(unsigned int a1, int a2)
{
  unsigned int v2; // r4
  int v3; // r7
  int v4; // r8
  unsigned int v6; // r6
  int v7; // r5
  int v8; // r9
  int v9; // r10
  int v10; // r6
  int v11; // r3
  int v12; // r3
  __int16 *v13; // r1
  BOOL v14; // r6
  int v15; // r3
  int *v16; // [sp+4h] [bp-94h]
  int v17; // [sp+8h] [bp-90h]
  int v18; // [sp+10h] [bp-88h] BYREF
  int v19; // [sp+14h] [bp-84h]
  int v20; // [sp+18h] [bp-80h]
  int v21; // [sp+1Ch] [bp-7Ch]
  int v22; // [sp+20h] [bp-78h]
  int v23; // [sp+24h] [bp-74h]
  unsigned int v24; // [sp+28h] [bp-70h]
  unsigned int v25; // [sp+2Ch] [bp-6Ch]
  unsigned __int64 v26; // [sp+30h] [bp-68h]
  unsigned int v27; // [sp+38h] [bp-60h]
  GUID *v28; // [sp+3Ch] [bp-5Ch]
  char v29[8]; // [sp+40h] [bp-58h] BYREF
  int v30[2]; // [sp+48h] [bp-50h] BYREF
  int v31; // [sp+50h] [bp-48h]

  v2 = a1;
  v24 = 0;
  v25 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v27 = a1 + a2;
  v3 = 0;
  v28 = &NullGuid;
  v22 = 0;
  v23 = 0;
  v4 = 0;
  if ( EtwRegister(BOOTENV_ETW_PROVIDER, 0, 0) < 0 )
    return sub_5522EC();
  v6 = v24;
  v26 = __PAIR64__(v24, v25);
  EtwSetInformation(
    v24,
    v25,
    2,
    &`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits,
    (unsigned __int16)`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits);
  v24 = 0;
  v7 = EtwRegister(BOOT_PROVIDER_GUID, 0, 0);
  if ( v7 < 0 )
  {
    v8 = 0;
    v9 = 0;
  }
  else
  {
    v8 = v18;
    v9 = v19;
    v7 = 0;
  }
  if ( v7 >= 0 && v2 < v27 )
  {
    do
    {
      if ( *(_DWORD *)(v2 + 8) == 6 )
      {
        BapdpParseEventParts(v2 + 48, v2 + 68, *(_DWORD *)(v2 + 64), v30, &v18, v16, v17);
        if ( !memcmp((unsigned int)BOOTENV_ETW_PROVIDER, v2 + 32, 16) )
        {
          v20 = v26;
          v21 = v6;
        }
        else if ( !memcmp((unsigned int)BOOT_PROVIDER_GUID, v2 + 32, 16) )
        {
          v20 = v9;
          v21 = v8;
          if ( !v24 && *(_BYTE *)(v2 + 51) == 11 )
          {
            EtwSetInformation(v8, v9, 2, v30[0], v31);
            v24 = 1;
          }
        }
        else if ( memcmp((unsigned int)v28, v2 + 32, 16) )
        {
          if ( v3 | v4 )
          {
            EtwUnregister(v3, v4);
            v22 = 0;
            v23 = 0;
          }
          v14 = *(unsigned __int8 *)(v2 + 51) != 11;
          v7 = EtwRegister(v2 + 32, 0, 0);
          if ( v7 >= 0 )
          {
            v3 = v22;
            v4 = v23;
            if ( v14 )
              EtwSetInformation(
                v22,
                v23,
                2,
                &`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits,
                (unsigned __int16)`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits);
            v7 = 0;
          }
          else
          {
            v3 = 0;
            v22 = 0;
            v23 = 0;
            v4 = 0;
          }
          if ( v7 < 0 )
            break;
          v28 = (GUID *)(v2 + 32);
          v15 = *(unsigned __int8 *)(v2 + 51);
          v20 = v4;
          v21 = v3;
          if ( v15 == 11 )
            EtwSetInformation(v3, v4, 2, v30[0], v31);
        }
        v10 = v21;
        if ( EtwEventEnabled(v21, v20, v2 + 48) )
        {
          v12 = *(_BYTE *)(v2 + 15) ? v2 + 16 : 0;
          v16 = v30;
          v7 = EtwWrite(v10, v20, v2 + 48, v12);
          if ( v7 < 0 )
            break;
        }
        if ( !memcmp((unsigned int)BOOTENV_ETW_PROVIDER, v2 + 32, 16) )
        {
          v11 = *(unsigned __int16 *)(v2 + 48);
          switch ( v11 )
          {
            case 11:
              v13 = L"POSTTime";
              break;
            case 20:
              if ( !*(_DWORD *)(v2 + 68) )
              {
                v17 = 0;
                v16 = 0;
                ZwUpdateWnfStateData();
              }
              goto LABEL_8;
            case 16:
            case 29:
              ExBootAppFailureStatus = *(_DWORD *)(v2 + 68);
              goto LABEL_8;
            case 32:
              v13 = L"BootmgrUserInputTime";
              break;
            default:
              goto LABEL_8;
          }
          RtlInitUnicodeString((unsigned int)v29, (unsigned __int16 *)v13);
          BapdpWriteEventDataToRegistry(v2 + 68);
        }
      }
LABEL_8:
      v6 = HIDWORD(v26);
      v2 = (*(_DWORD *)(v2 + 4) + v2 + 7) & 0xFFFFFFF8;
    }
    while ( v2 < v27 );
  }
  if ( v26 )
    EtwUnregister(HIDWORD(v26), v26);
  if ( v8 | v9 )
    EtwUnregister(v8, v9);
  if ( v3 | v4 )
    EtwUnregister(v3, v4);
  return v7;
}
