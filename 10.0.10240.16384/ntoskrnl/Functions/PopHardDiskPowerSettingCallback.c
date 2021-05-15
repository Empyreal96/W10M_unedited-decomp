// PopHardDiskPowerSettingCallback 
 
int __fastcall PopHardDiskPowerSettingCallback(unsigned int a1, int *a2, int a3)
{
  int v6; // r4
  _DWORD v8[62]; // [sp-4h] [bp-F8h] BYREF

  if ( memcmp((unsigned int)&GUID_DISK_POWERDOWN_TIMEOUT, a1, 16) )
  {
    if ( !memcmp((unsigned int)&GUID_DISK_BURST_IGNORE_THRESHOLD, a1, 16) && a3 == 4 && a2 )
    {
      dword_61EC24 = *a2;
      return 0;
    }
    return -1073741811;
  }
  if ( a3 != 4 || !a2 )
    return -1073741811;
  PopAcquirePolicyLock();
  memmove((int)v8, PopPolicy, 0xE8u);
  v8[53] = *a2;
  v6 = PopApplyPolicy(1, 0, v8, 232);
  PopUpdateDiskIdleTimeout(1000 * *a2);
  PopReleasePolicyLock();
  if ( v6 >= 0 )
    return 0;
  return v6;
}
