// PopSleepPowerSettingCallback 
 
int __fastcall PopSleepPowerSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r5
  _DWORD v8[22]; // [sp-4h] [bp-108h] BYREF

  v3 = -1073741811;
  PopAcquirePolicyLock();
  memmove((int)v8, PopPolicy, 0xE8u);
  if ( !memcmp((unsigned int)&GUID_STANDBY_TIMEOUT, a1, 16) && a3 == 4 && a2 )
  {
    v8[15] = *a2;
    if ( byte_61EA43 || byte_61EA44 || byte_61EA45 )
      v8[12] = 2;
    v3 = 0;
  }
  if ( !memcmp((unsigned int)&GUID_HIBERNATE_TIMEOUT, a1, 16) && a3 == 4 && a2 )
  {
    if ( *a2 )
      return sub_7F1D1C();
    v3 = 0;
  }
  if ( v3 >= 0 )
    v3 = PopApplyPolicy(1, 0, v8, 232);
  if ( !memcmp((unsigned int)&GUID_HIBERNATE_FASTS4_POLICY, a1, 16) && a3 == 4 && a2 )
  {
    byte_61EC1C = *a2 == 0;
    v3 = 0;
  }
  if ( !memcmp((unsigned int)&GUID_ALLOW_STANDBY_STATES, a1, 16) && a3 == 4 && a2 )
  {
    byte_61EC1D = *a2 == 0;
    v3 = 0;
  }
  if ( !memcmp((unsigned int)&GUID_UNATTEND_SLEEP_TIMEOUT, a1, 16) && a3 == 4 )
  {
    if ( a2 )
    {
      dword_61EC20 = *a2;
      PopInitSIdle(0);
      v3 = 0;
    }
  }
  PopReleasePolicyLock();
  return v3;
}
