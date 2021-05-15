// PipCommitPendingService 
 
int __fastcall PipCommitPendingService(unsigned __int16 *a1, int a2, int a3)
{
  int v3; // r7
  int v6; // r4
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v11; // [sp+18h] [bp-38h] BYREF
  int v12; // [sp+1Ch] [bp-34h] BYREF
  int v13; // [sp+20h] [bp-30h]
  int v14; // [sp+24h] [bp-2Ch]
  int v15; // [sp+28h] [bp-28h]
  int v16[9]; // [sp+2Ch] [bp-24h] BYREF

  v15 = 0;
  v16[0] = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  v14 = 0;
  v3 = a2;
  if ( !a2 )
  {
    v6 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, v16);
    if ( v6 < 0 )
      goto LABEL_20;
    v6 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v16[0], (int)L"Control\\PendingDriverOperations\\Services", 0);
    if ( v6 < 0 )
      goto LABEL_20;
    v3 = v14;
  }
  if ( !a3 )
  {
    v6 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v3, (int)a1, 0);
    if ( v6 < 0 )
      goto LABEL_20;
    a3 = v15;
  }
  v7 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v3, (int)L"EventLog", 0);
  v6 = v7;
  if ( v7 == -1073741772 || v7 == -1073741444 || v7 >= 0 )
  {
    v8 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, (int)a1, 0);
    v6 = v8;
    if ( v8 == -1073741772 || v8 == -1073741444 || v8 >= 0 )
    {
      v6 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 6, &v11);
      if ( v6 >= 0 )
      {
        v6 = PnpCtxRegCreateKey((int *)PiPnpRtlCtx, v11, a1, 1, 131078, 0, (int)&v12, 0);
        if ( v6 >= 0 )
        {
          v6 = PiDevCfgCopyDeviceKeys(a3, v12, 1, 0);
          if ( v6 >= 0 )
          {
            v9 = PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, v3, a1);
            v6 = v9;
            if ( v9 >= 0 )
            {
              v11 = 0;
              if ( PnpCtxRegEnumKey(v9, v3, 0, 0, (unsigned int *)&v11) == -2147483622 )
                PnpCtxRegDeleteKey((int *)PiPnpRtlCtx, v3, 0);
            }
          }
        }
      }
    }
  }
LABEL_20:
  if ( v12 )
    PnpCtxRegCloseKey();
  if ( v13 )
    PnpCtxRegCloseKey();
  if ( v14 )
    PnpCtxRegCloseKey();
  if ( v15 )
    PnpCtxRegCloseKey();
  return v6;
}
