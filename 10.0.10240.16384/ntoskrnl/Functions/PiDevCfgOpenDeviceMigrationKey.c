// PiDevCfgOpenDeviceMigrationKey 
 
int PiDevCfgOpenDeviceMigrationKey()
{
  int v0; // r4
  int result; // r0
  int v2; // [sp+4h] [bp-3Ch] BYREF
  __int16 v3[2]; // [sp+8h] [bp-38h] BYREF
  const __int16 *v4; // [sp+Ch] [bp-34h]
  int v5; // [sp+10h] [bp-30h]
  int v6; // [sp+14h] [bp-2Ch]
  __int16 *v7; // [sp+18h] [bp-28h]
  int v8; // [sp+1Ch] [bp-24h]
  int v9; // [sp+20h] [bp-20h]
  int v10; // [sp+24h] [bp-1Ch]

  v2 = 0;
  v0 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v2);
  if ( v0 < 0 )
    goto LABEL_4;
  v3[1] = 64;
  v3[0] = 62;
  v4 = L"Control\\DeviceMigration\\Devices";
  v5 = 24;
  v8 = 576;
  v6 = v2;
  v7 = v3;
  v9 = 0;
  v10 = 0;
  v0 = ZwOpenKey();
  if ( v0 < 0 )
LABEL_4:
    result = v0;
  else
    result = sub_81B62C();
  return result;
}
