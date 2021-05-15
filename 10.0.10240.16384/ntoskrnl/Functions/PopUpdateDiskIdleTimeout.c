// PopUpdateDiskIdleTimeout 
 
int __fastcall PopUpdateDiskIdleTimeout(int result)
{
  if ( !result )
    result = -1;
  if ( result != PopDiskIdleTimeout )
  {
    PopDiskIdleTimeout = result;
    result = PopUpdateDiskIdleTimeoutSetting();
  }
  return result;
}
