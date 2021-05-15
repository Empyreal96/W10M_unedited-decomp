// BapdRecordFirmwareBootStats 
 
int BapdRecordFirmwareBootStats()
{
  int result; // r0
  int v1; // r5
  int v2; // r6
  unsigned __int64 *v3; // r7
  int v4; // r1
  int v5; // r1
  int v6; // r1
  int v7; // r1
  int v8; // r1
  int v9[2]; // [sp+8h] [bp-A8h] BYREF
  _DWORD v10[2]; // [sp+10h] [bp-A0h] BYREF
  _DWORD v11[2]; // [sp+18h] [bp-98h] BYREF
  _DWORD v12[2]; // [sp+20h] [bp-90h] BYREF
  _DWORD v13[2]; // [sp+28h] [bp-88h] BYREF
  int v14; // [sp+30h] [bp-80h]
  int v15; // [sp+34h] [bp-7Ch]
  _DWORD v16[2]; // [sp+38h] [bp-78h] BYREF
  char v17[8]; // [sp+40h] [bp-70h] BYREF
  _DWORD *v18; // [sp+48h] [bp-68h]
  int v19; // [sp+4Ch] [bp-64h]
  int v20; // [sp+50h] [bp-60h]
  int v21; // [sp+54h] [bp-5Ch]
  _DWORD *v22; // [sp+58h] [bp-58h]
  int v23; // [sp+5Ch] [bp-54h]
  int v24; // [sp+60h] [bp-50h]
  int v25; // [sp+64h] [bp-4Ch]
  _DWORD *v26; // [sp+68h] [bp-48h]
  int v27; // [sp+6Ch] [bp-44h]
  int v28; // [sp+70h] [bp-40h]
  int v29; // [sp+74h] [bp-3Ch]
  _DWORD *v30; // [sp+78h] [bp-38h]
  int v31; // [sp+7Ch] [bp-34h]
  int v32; // [sp+80h] [bp-30h]
  int v33; // [sp+84h] [bp-2Ch]
  _DWORD *v34; // [sp+88h] [bp-28h]
  int v35; // [sp+8Ch] [bp-24h]
  int v36; // [sp+90h] [bp-20h]
  int v37; // [sp+94h] [bp-1Ch]

  v9[0] = 0;
  if ( EtwRegister(BOOTENV_ETW_PROVIDER, 0, 0) < 0 )
    return sub_6947F8();
  v1 = v14;
  v2 = v15;
  EtwSetInformation(
    v14,
    v15,
    2,
    &`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits,
    (unsigned __int16)`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits);
  result = off_617B54(34, 0, 0, v9);
  if ( result == -1073741820 )
  {
    if ( v9[0] )
    {
      result = ExAllocatePoolWithTag(1, v9[0], 1935832902);
      v3 = (unsigned __int64 *)result;
      if ( result )
      {
        if ( off_617B54(34, v9[0], result, v9) >= 0 )
        {
          v16[0] = _rt_udiv64(1000000i64, v3[2]);
          v16[1] = v4;
          v11[0] = _rt_udiv64(1000000i64, v3[3]);
          v11[1] = v5;
          v10[0] = _rt_udiv64(1000000i64, v3[4]);
          v10[1] = v6;
          v12[0] = _rt_udiv64(1000000i64, v3[5]);
          v12[1] = v7;
          v13[0] = _rt_udiv64(1000000i64, v3[6]);
          v13[1] = v8;
          RtlInitUnicodeString((unsigned int)v17, L"FwPOSTTime");
          BapdpWriteEventDataToRegistry(v10);
          v18 = v16;
          v19 = 0;
          v20 = 8;
          v21 = 0;
          v22 = v11;
          v23 = 0;
          v24 = 8;
          v25 = 0;
          v26 = v10;
          v27 = 0;
          v28 = 8;
          v29 = 0;
          v30 = v12;
          v31 = 0;
          v32 = 8;
          v33 = 0;
          v34 = v13;
          v35 = 0;
          v36 = 8;
          v37 = 0;
          EtwWrite(v1, v2, (int)BOOT_FW_BOOT_PERF_DATA, 0);
        }
        result = ExFreePoolWithTag((unsigned int)v3);
      }
    }
  }
  if ( v1 | v2 )
    result = EtwUnregister(v1, v2);
  return result;
}
