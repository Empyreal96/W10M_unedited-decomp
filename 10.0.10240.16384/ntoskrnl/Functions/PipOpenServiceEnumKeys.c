// PipOpenServiceEnumKeys 
 
int __fastcall PipOpenServiceEnumKeys(int a1, int a2, _DWORD *a3, _DWORD *a4, char a5)
{
  int v9; // r4
  int v11; // r0
  int v12; // [sp+Ch] [bp-44h] BYREF
  int v13; // [sp+10h] [bp-40h] BYREF
  __int16 v14[2]; // [sp+18h] [bp-38h] BYREF
  const __int16 *v15; // [sp+1Ch] [bp-34h]
  int v16; // [sp+20h] [bp-30h]
  int v17; // [sp+24h] [bp-2Ch]
  __int16 *v18; // [sp+28h] [bp-28h]
  int v19; // [sp+2Ch] [bp-24h]
  int v20; // [sp+30h] [bp-20h]
  int v21; // [sp+34h] [bp-1Ch]

  v9 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 6, &v13);
  if ( v9 < 0 )
    return v9;
  v16 = 24;
  v17 = v13;
  v18 = (__int16 *)a1;
  v20 = 0;
  v21 = 0;
  v19 = 576;
  v9 = ZwOpenKey();
  if ( v9 < 0 )
    return v9;
  if ( !a4 && !a5 )
  {
LABEL_5:
    if ( a3 )
      *a3 = 0;
    else
      ZwClose();
    return 0;
  }
  v14[1] = 10;
  v14[0] = 8;
  v15 = L"Enum";
  if ( a5 )
  {
    v11 = IopCreateRegistryKeyEx(&v12, 0, v14, a2, 1, 0);
  }
  else
  {
    v12 = 0;
    v16 = 24;
    v17 = 0;
    v18 = v14;
    v19 = 576;
    v20 = 0;
    v21 = 0;
    v11 = ZwOpenKey();
  }
  v9 = v11;
  if ( v11 < 0 )
  {
    ZwClose();
    return v9;
  }
  if ( a4 )
  {
    *a4 = v12;
    goto LABEL_5;
  }
  return sub_7CB3A0();
}
