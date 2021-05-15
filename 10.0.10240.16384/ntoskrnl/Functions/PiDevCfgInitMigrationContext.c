// PiDevCfgInitMigrationContext 
 
int __fastcall PiDevCfgInitMigrationContext(int a1, int a2, int a3)
{
  int result; // r0
  int v7; // [sp+0h] [bp-48h] BYREF
  __int16 v8[2]; // [sp+8h] [bp-40h] BYREF
  const __int16 *v9; // [sp+Ch] [bp-3Ch]
  int v10; // [sp+10h] [bp-38h]
  int v11; // [sp+14h] [bp-34h]
  __int16 *v12; // [sp+18h] [bp-30h]
  int v13; // [sp+1Ch] [bp-2Ch]
  int v14; // [sp+20h] [bp-28h]
  int v15; // [sp+24h] [bp-24h]

  v7 = 0;
  memset((_BYTE *)a3, 0, 28);
  *(_DWORD *)(a3 + 20) = a1;
  *(_DWORD *)(a3 + 24) = a2;
  if ( PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v7) < 0 )
    JUMPOUT(0x7E3E68);
  v8[1] = 48;
  v8[0] = 46;
  v9 = L"Control\\DeviceMigration";
  v10 = 24;
  v11 = v7;
  v12 = v8;
  v13 = 576;
  v14 = 0;
  v15 = 0;
  *(_DWORD *)a3 = 0;
  if ( ZwOpenKey() == -1073741772 )
    result = 0;
  else
    result = sub_7E3D9C();
  return result;
}
