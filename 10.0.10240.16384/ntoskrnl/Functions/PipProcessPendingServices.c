// PipProcessPendingServices 
 
int PipProcessPendingServices()
{
  int v0; // r4
  int v2[3]; // [sp+Ch] [bp-Ch] BYREF

  v2[0] = 0;
  v0 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, v2);
  if ( v0 >= 0 )
  {
    if ( PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v2[0], (int)L"Control\\PendingDriverOperations\\Services", 0) != -1073741772 )
      return sub_96F5D8();
    v0 = 0;
  }
  return v0;
}
