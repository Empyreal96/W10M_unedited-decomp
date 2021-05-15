// PopComputeWatchdogTimeout 
 
int __fastcall PopComputeWatchdogTimeout(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 116);
  if ( !v1 )
    return sub_52A628();
  if ( v1 == 1 && *(_DWORD *)(a1 + 120) == 1 )
    return PopWatchdogResumeTimeout;
  return PopWatchdogSleepTimeout;
}
