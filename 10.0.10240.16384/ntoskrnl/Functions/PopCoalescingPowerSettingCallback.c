// PopCoalescingPowerSettingCallback 
 
int __fastcall PopCoalescingPowerSettingCallback(unsigned int a1, int *a2, int a3)
{
  int v3; // r5

  v3 = -1073741811;
  PopAcquirePolicyLock();
  if ( !memcmp((unsigned int)&GUID_DISK_COALESCING_POWERDOWN_TIMEOUT, a1, 16) && a3 == 4 && a2 )
  {
    PopDppeCoalescingSpindownTimeout = *a2;
    PopUpdateDiskCoalescingTimeout();
    PopCheckResiliencyScenarios();
    v3 = 0;
  }
  PopReleasePolicyLock();
  return v3;
}
