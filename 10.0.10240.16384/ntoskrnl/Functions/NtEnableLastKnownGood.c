// NtEnableLastKnownGood 
 
int NtEnableLastKnownGood()
{
  int v0; // r4
  int v1; // r4
  _DWORD *v3; // [sp+Ch] [bp-6Ch] BYREF
  __int16 v4; // [sp+10h] [bp-68h] BYREF
  __int16 v5; // [sp+12h] [bp-66h]
  const __int16 *v6; // [sp+14h] [bp-64h]
  unsigned __int16 v7[4]; // [sp+18h] [bp-60h] BYREF
  unsigned __int16 v8[4]; // [sp+20h] [bp-58h] BYREF
  char v9[8]; // [sp+28h] [bp-50h] BYREF
  char v10[8]; // [sp+30h] [bp-48h] BYREF
  int v11; // [sp+38h] [bp-40h]
  int v12; // [sp+3Ch] [bp-3Ch]
  unsigned __int16 *v13; // [sp+40h] [bp-38h]
  int v14; // [sp+44h] [bp-34h]
  int v15; // [sp+48h] [bp-30h]
  int v16; // [sp+4Ch] [bp-2Ch]
  int v17; // [sp+50h] [bp-28h]
  _DWORD *v18; // [sp+54h] [bp-24h]
  __int16 *v19; // [sp+58h] [bp-20h]
  int v20; // [sp+5Ch] [bp-1Ch]
  int v21; // [sp+60h] [bp-18h]
  int v22; // [sp+64h] [bp-14h]

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    return -1073741790;
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, 1, (int)&SeTcbPrivilege) )
    return -1073741727;
  v0 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, (int *)&v3);
  if ( v0 >= 0 )
  {
    v5 = 24;
    v4 = 22;
    v6 = L"Control\\Pnp";
    v17 = 24;
    v18 = v3;
    v19 = &v4;
    v20 = 576;
    v21 = 0;
    v22 = 0;
    v0 = ZwOpenKey();
    if ( v0 >= 0 )
    {
      v1 = 0;
      if ( IopGetRegistryValue(0, L"DisableLKG", 0, (int *)&v3) < 0 )
        goto LABEL_18;
      if ( v3[1] == 4 && v3[3] == 4 )
        v1 = (unsigned __int8)*(_DWORD *)((char *)v3 + v3[2]);
      ExFreePoolWithTag((unsigned int)v3);
      if ( v1 )
      {
        v5 = 22;
        v4 = 20;
        v6 = L"DisableLKG";
        v0 = ZwDeleteValueKey();
        if ( v0 >= 0 )
        {
          RtlInitUnicodeString((unsigned int)v9, L"\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood");
          v11 = 24;
          v12 = 0;
          v13 = (unsigned __int16 *)v9;
          v14 = 576;
          v15 = 0;
          v16 = 0;
          if ( ZwOpenKey() >= 0 )
            ZwDeleteKey();
          RtlInitUnicodeString((unsigned int)v10, L"\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp");
          v11 = 24;
          v12 = 0;
          v13 = (unsigned __int16 *)v10;
          v14 = 576;
          v15 = 0;
          v16 = 0;
          if ( ZwOpenKey() >= 0 )
            ZwDeleteKey();
          RtlInitUnicodeString((unsigned int)v7, L"\\SystemRoot\\LastGood");
          IopFileUtilWalkDirectoryTreeBottomUp(v7);
          v11 = 24;
          v12 = 0;
          v14 = 64;
          v13 = v7;
          v15 = 0;
          v16 = 0;
          ZwDeleteFile();
          RtlInitUnicodeString((unsigned int)v8, L"\\SystemRoot\\LastGood.Tmp");
          IopFileUtilWalkDirectoryTreeBottomUp(v8);
          v11 = 24;
          v12 = 0;
          v14 = 64;
          v13 = v8;
          v15 = 0;
          v16 = 0;
          ZwDeleteFile();
          v0 = 0;
        }
      }
      else
      {
LABEL_18:
        v0 = -1073741823;
      }
    }
  }
  return v0;
}
