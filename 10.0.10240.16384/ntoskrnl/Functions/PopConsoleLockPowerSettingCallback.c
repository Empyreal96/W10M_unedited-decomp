// PopConsoleLockPowerSettingCallback 
 
int __fastcall PopConsoleLockPowerSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v6; // r4
  _DWORD v8[62]; // [sp-4h] [bp-F8h] BYREF

  PopAcquirePolicyLock();
  memmove((int)v8, PopPolicy, 0xE8u);
  if ( !memcmp((unsigned int)&GUID_LOCK_CONSOLE_ON_WAKE, a1, 16) && a3 == 4 && a2 )
  {
    v8[20] = *a2;
    v6 = PopApplyPolicy(1, 0, v8, 232);
  }
  else
  {
    v6 = -1073741811;
  }
  PopReleasePolicyLock();
  return v6;
}
