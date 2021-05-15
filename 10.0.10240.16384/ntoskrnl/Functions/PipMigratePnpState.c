// PipMigratePnpState 
 
int PipMigratePnpState()
{
  int result; // r0

  if ( PnpCtxRegOpenKey((int *)PiPnpRtlCtx, -2147483646, (int)L"System\\Setup\\Upgrade\\Pnp", 0) == -1073741772 )
    result = 0;
  else
    result = sub_96F864();
  return result;
}
