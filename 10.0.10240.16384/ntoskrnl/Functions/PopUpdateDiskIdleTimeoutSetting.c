// PopUpdateDiskIdleTimeoutSetting 
 
int PopUpdateDiskIdleTimeoutSetting()
{
  int *v0; // r3
  int result; // r0

  if ( PopCoalescingState )
    v0 = &PopDiskCoalescingTimeout;
  else
    v0 = &PopDiskIdleTimeout;
  if ( *v0 != PopCurrentDiskIdleTimeout )
  {
    PopCurrentDiskIdleTimeout = *v0;
    result = PopSetPowerSettingValueAcDc(&GUID_DISK_IDLE_TIMEOUT, 4, &PopCurrentDiskIdleTimeout);
  }
  return result;
}
