// PopDeepSleepPowerSettingCallback 
 
int __fastcall PopDeepSleepPowerSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v5; // r4

  v5 = -1073741811;
  if ( !memcmp((unsigned int)&GUID_DEEP_SLEEP_ENABLED, a1, 16) && a3 == 4 && a2 )
  {
    PopAcquirePolicyLock();
    PopDeepSleepIsEnabled = *a2 != 0;
    PopCheckResiliencyScenarios();
    PopReleasePolicyLock();
    v5 = 0;
  }
  return v5;
}
