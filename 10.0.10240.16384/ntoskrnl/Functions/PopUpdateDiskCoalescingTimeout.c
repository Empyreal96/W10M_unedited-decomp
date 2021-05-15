// PopUpdateDiskCoalescingTimeout 
 
int __fastcall PopUpdateDiskCoalescingTimeout(int result)
{
  if ( !result )
    result = -1;
  if ( result != PopDiskCoalescingTimeout )
  {
    PopDiskCoalescingTimeout = result;
    result = PopUpdateDiskIdleTimeoutSetting();
  }
  return result;
}
