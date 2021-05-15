// PipProcessPendingOsExtensionResources 
 
int PipProcessPendingOsExtensionResources()
{
  int v0; // r4
  int v2[3]; // [sp+Ch] [bp-Ch] BYREF

  v2[0] = 0;
  v0 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, v2);
  if ( v0 >= 0 )
  {
    if ( PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v2[0], (int)L"Control\\PendingDriverOperations\\OsExtensionDatabase", 0) != -1073741772 )
      return sub_96F5B0();
    v0 = 0;
  }
  return v0;
}
