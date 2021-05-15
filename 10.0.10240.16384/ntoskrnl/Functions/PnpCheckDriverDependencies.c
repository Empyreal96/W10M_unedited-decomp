// PnpCheckDriverDependencies 
 
int __fastcall PnpCheckDriverDependencies(unsigned __int16 *a1, _BYTE *a2, _BYTE *a3)
{
  int v6; // r10
  int v7; // r4
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r0
  unsigned int v13; // [sp+10h] [bp-30h] BYREF
  int v14; // [sp+14h] [bp-2Ch] BYREF
  int v15; // [sp+18h] [bp-28h] BYREF
  int v16; // [sp+1Ch] [bp-24h] BYREF
  _DWORD v17[8]; // [sp+20h] [bp-20h] BYREF

  v14 = 0;
  v15 = 0;
  v16 = 0;
  *a2 = 0;
  v6 = 0;
  if ( a3 )
    *a3 = 0;
  v7 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v14);
  if ( v7 >= 0 )
  {
    for ( ; *a1; a1 += wcslen(a1) + 1 )
    {
      if ( !wcsicmp((int)a1, L"*") )
      {
        if ( a3 )
          *a3 = 1;
        continue;
      }
      if ( !v6 )
      {
        v8 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v14, (int)L"Control\\FirmwareResources", 0);
        v7 = v8;
        if ( v8 == -1073741772 || v8 == -1073741444 )
        {
          v6 = 1;
LABEL_28:
          v7 = 0;
          continue;
        }
        if ( v8 < 0 )
          return v7;
        v9 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, (int)a1, 0);
        v7 = v9;
        if ( v9 == -1073741772 || v9 == -1073741444 )
          goto LABEL_28;
        if ( v9 < 0 )
          return v7;
        v13 = 4;
        v10 = PnpCtxRegQueryValue(v9, 0, L"Phase", v17, (int)&v15, &v13);
        v7 = v10;
        if ( v10 == -1073741772 )
        {
          v7 = 0;
          goto LABEL_24;
        }
        if ( v10 == -1073741444 )
          goto LABEL_28;
        if ( v10 < 0 )
          return v7;
        if ( v15 != 2 )
          break;
        v13 = 4;
        v11 = PnpCtxRegQueryValue(v10, 0, L"LastAttemptStatus", v17, (int)&v16, &v13);
        v7 = v11;
        if ( v11 == -1073741772 )
        {
          v7 = 0;
          break;
        }
        if ( v11 == -1073741444 )
          goto LABEL_28;
        if ( v11 < 0 )
          return v7;
        if ( v16 )
          break;
      }
    }
    if ( v7 >= 0 )
    {
LABEL_24:
      if ( !*a1 )
        *a2 = 1;
    }
  }
  return v7;
}
