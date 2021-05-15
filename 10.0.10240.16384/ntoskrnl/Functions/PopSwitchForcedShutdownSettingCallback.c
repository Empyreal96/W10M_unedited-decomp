// PopSwitchForcedShutdownSettingCallback 
 
int __fastcall PopSwitchForcedShutdownSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r5
  int v7; // r0

  v3 = -1073741811;
  PopAcquirePolicyLock(a1, a2);
  v7 = memcmp((unsigned int)&GUID_ENABLE_SWITCH_FORCED_SHUTDOWN, a1, 16);
  if ( !v7 && a3 == 4 && a2 )
  {
    byte_61EC44 = *a2 != 0;
    v3 = 0;
  }
  PopReleasePolicyLock(v7);
  return v3;
}
