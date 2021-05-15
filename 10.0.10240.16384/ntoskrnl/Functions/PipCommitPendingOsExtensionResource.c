// PipCommitPendingOsExtensionResource 
 
int __fastcall PipCommitPendingOsExtensionResource(unsigned __int16 *a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r0
  int v9; // [sp+10h] [bp-30h] BYREF
  int v10; // [sp+14h] [bp-2Ch] BYREF
  int v11; // [sp+18h] [bp-28h] BYREF
  int v12; // [sp+1Ch] [bp-24h]
  int v13; // [sp+20h] [bp-20h]

  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v6 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v9);
  if ( v6 >= 0 )
  {
    if ( !a2 )
    {
      v6 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v9, (int)L"Control\\PendingDriverOperations\\OsExtensionDatabase", 0);
      if ( v6 < 0 )
        goto LABEL_14;
      a2 = v12;
    }
    if ( !a3 )
    {
      v6 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, a2, (int)a1, 0);
      if ( v6 < 0 )
        goto LABEL_14;
      a3 = v13;
    }
    v6 = PnpCtxRegCreateKey((int *)PiPnpRtlCtx, v9, L"Control\\OsExtensionDatabase", 1, 131078, 0, (int)&v11, 0);
    if ( v6 >= 0 )
    {
      v6 = PnpCtxRegCreateKey((int *)PiPnpRtlCtx, v11, a1, (int)&v10, 131078, 0, (int)&v10, 0);
      if ( v6 >= 0 )
      {
        v6 = PiDevCfgCopyDeviceKeys(a3, v10, 1, 0);
        if ( v6 >= 0 )
        {
          v7 = PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, a2, a1);
          v6 = v7;
          if ( v7 >= 0 )
          {
            v9 = 0;
            if ( PnpCtxRegEnumKey(v7, a2, 0, 0, (unsigned int *)&v9) == -2147483622 )
              PnpCtxRegDeleteKey((int *)PiPnpRtlCtx, a2, 0);
          }
        }
      }
    }
  }
LABEL_14:
  if ( v10 )
    PnpCtxRegCloseKey();
  if ( v11 )
    PnpCtxRegCloseKey();
  if ( v12 )
    PnpCtxRegCloseKey();
  if ( v13 )
    PnpCtxRegCloseKey();
  return v6;
}
